/**
 * Auto-Jump Script for Chrome Dino Game
 * This script analyzes the canvas to detect obstacles and automatically jumps
 */

class DinoAutoJumper {
    constructor() {
        this.canvas = null;
        this.ctx = null;
        this.runner = null;
        this.isActive = false;
        this.scanRegion = {
            x: 100,        // Start scanning 100px ahead of dino
            y: 110,        // Ground level (adjust based on your game)
            width: 80,     // Scan width
            height: 30     // Scan height
        };
        this.obstacleThreshold = 50; // Minimum dark pixels to consider as obstacle
        this.jumpCooldown = 0;
        this.lastJumpTime = 0;
        this.minJumpInterval = 500; // Minimum time between jumps (ms)
        
        this.init();
    }

    init() {
        // Find the game canvas
        this.canvas = document.querySelector('.runner-canvas');
        if (!this.canvas) {
            console.log('Dino game canvas not found!');
            return;
        }
        
        this.ctx = this.canvas.getContext('2d');
        
        // Find the Runner instance
        this.runner = window.Runner && window.Runner.instance_;
        
        if (!this.runner) {
            console.log('Dino game instance not found!');
            return;
        }

        console.log('Auto-jumper initialized! Press SPACE to toggle auto-jump.');
        this.setupToggle();
    }

    setupToggle() {
        // Toggle auto-jump with 'A' key
        document.addEventListener('keydown', (e) => {
            if (e.key.toLowerCase() === 'a') {
                this.toggle();
            }
        });
    }

    toggle() {
        this.isActive = !this.isActive;
        console.log(`Auto-jump ${this.isActive ? 'ENABLED' : 'DISABLED'}`);
        
        if (this.isActive) {
            this.startAutoJump();
        } else {
            this.stopAutoJump();
        }
    }

    startAutoJump() {
        this.scanInterval = setInterval(() => {
            this.scanForObstacles();
        }, 16); // ~60 FPS scanning
    }

    stopAutoJump() {
        if (this.scanInterval) {
            clearInterval(this.scanInterval);
        }
    }

    scanForObstacles() {
        if (!this.isActive || !this.runner || this.runner.crashed) {
            return;
        }

        // Check cooldown
        const now = Date.now();
        if (now - this.lastJumpTime < this.minJumpInterval) {
            return;
        }

        // Get image data from scanning region
        const imageData = this.ctx.getImageData(
            this.scanRegion.x, 
            this.scanRegion.y, 
            this.scanRegion.width, 
            this.scanRegion.height
        );

        const darkPixels = this.countDarkPixels(imageData);
        
        // Debug visualization (optional)
        if (this.showDebug) {
            this.drawScanRegion(darkPixels);
        }

        // Jump if obstacle detected
        if (darkPixels > this.obstacleThreshold) {
            this.jump();
        }
    }

    countDarkPixels(imageData) {
        let darkPixelCount = 0;
        const data = imageData.data;
        
        // Process every pixel in the image data
        for (let i = 0; i < data.length; i += 4) {
            const r = data[i];
            const g = data[i + 1];
            const b = data[i + 2];
            const alpha = data[i + 3];
            
            // Calculate brightness (0-255)
            const brightness = (r + g + b) / 3;
            
            // Consider pixels darker than threshold as potential obstacles
            // Ground is usually light gray, obstacles are darker
            if (brightness < 200 && alpha > 0) {
                darkPixelCount++;
            }
        }
        
        return darkPixelCount;
    }

    jump() {
        if (!this.runner.tRex.jumping && !this.runner.crashed) {
            // Simulate spacebar press
            const spaceEvent = new KeyboardEvent('keydown', {
                keyCode: 32,
                which: 32,
                key: ' ',
                code: 'Space'
            });
            
            document.dispatchEvent(spaceEvent);
            this.lastJumpTime = Date.now();
            
            console.log('🦘 Auto-jump executed!');
        }
    }

    // Debug visualization
    drawScanRegion(darkPixels) {
        this.ctx.strokeStyle = darkPixels > this.obstacleThreshold ? 'red' : 'green';
        this.ctx.lineWidth = 2;
        this.ctx.strokeRect(
            this.scanRegion.x, 
            this.scanRegion.y, 
            this.scanRegion.width, 
            this.scanRegion.height
        );
        
        // Show dark pixel count
        this.ctx.fillStyle = 'blue';
        this.ctx.font = '12px Arial';
        this.ctx.fillText(
            `Dark: ${darkPixels}`, 
            this.scanRegion.x, 
            this.scanRegion.y - 5
        );
    }

    // Method to enable debug visualization
    enableDebug() {
        this.showDebug = true;
        console.log('Debug visualization enabled');
    }

    disableDebug() {
        this.showDebug = false;
        console.log('Debug visualization disabled');
    }

    // Adjust scanning parameters
    adjustScanRegion(x, y, width, height) {
        this.scanRegion = { x, y, width, height };
        console.log('Scan region adjusted:', this.scanRegion);
    }

    adjustThreshold(threshold) {
        this.obstacleThreshold = threshold;
        console.log('Obstacle threshold adjusted:', threshold);
    }
}

// Alternative simpler approach using pixel detection
class SimpleAutoJumper {
    constructor() {
        this.isActive = false;
        this.canvas = null;
        this.ctx = null;
        this.init();
    }

    init() {
        this.canvas = document.querySelector('.runner-canvas');
        if (!this.canvas) {
            console.log('Canvas not found');
            return;
        }
        this.ctx = this.canvas.getContext('2d');
        
        // Toggle with 'S' key
        document.addEventListener('keydown', (e) => {
            if (e.key.toLowerCase() === 's') {
                this.toggle();
            }
        });
    }

    toggle() {
        this.isActive = !this.isActive;
        console.log(`Simple auto-jump ${this.isActive ? 'ENABLED' : 'DISABLED'}`);
        
        if (this.isActive) {
            this.startScanning();
        } else {
            this.stopScanning();
        }
    }

    startScanning() {
        this.interval = setInterval(() => {
            // Scan specific pixels ahead of the dino
            const pixels = this.ctx.getImageData(150, 125, 50, 25);
            let darkPixels = 0;
            
            for (let i = 0; i < pixels.data.length; i += 4) {
                const brightness = (pixels.data[i] + pixels.data[i + 1] + pixels.data[i + 2]) / 3;
                if (brightness < 150) darkPixels++;
            }
            
            if (darkPixels > 30) {
                this.jump();
            }
        }, 20);
    }

    stopScanning() {
        if (this.interval) {
            clearInterval(this.interval);
        }
    }

    jump() {
        const event = new KeyboardEvent('keydown', { keyCode: 32 });
        document.dispatchEvent(event);
    }
}

// Usage instructions and initialization
console.log(`
🦖 DINO AUTO-JUMPER LOADED! 🦖

Usage:
1. Press 'A' to toggle advanced auto-jumper
2. Press 'S' to toggle simple auto-jumper
3. Only use one at a time!

Advanced features:
- autoJumper.enableDebug()  - Show scan region
- autoJumper.adjustThreshold(50)  - Adjust sensitivity
- autoJumper.adjustScanRegion(x, y, w, h)  - Change scan area

Start the dino game and press A or S to activate!
`);

// Initialize both auto-jumpers
const autoJumper = new DinoAutoJumper();
const simpleAutoJumper = new SimpleAutoJumper();

// Make them globally accessible for debugging
window.autoJumper = autoJumper;
window.simpleAutoJumper = simpleAutoJumper;
