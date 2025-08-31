# ASCII Art from Text - Trinket.io Compatible
# No external libraries needed!

def char_to_ascii(char):
    """Convert a single character to ASCII art"""
    art_dict = {
        'A': [
            "  █████  ",
            " ██   ██ ",
            " ███████ ",
            " ██   ██ ",
            " ██   ██ "
        ],
        'B': [
            " ██████  ",
            " ██   ██ ",
            " ██████  ",
            " ██   ██ ",
            " ██████  "
        ],
        'C': [
            "  ██████ ",
            " ██      ",
            " ██      ",
            " ██      ",
            "  ██████ "
        ],
        'D': [
            " ██████  ",
            " ██   ██ ",
            " ██   ██ ",
            " ██   ██ ",
            " ██████  "
        ],
        'E': [
            " ███████ ",
            " ██      ",
            " █████   ",
            " ██      ",
            " ███████ "
        ],
        'F': [
            " ███████ ",
            " ██      ",
            " █████   ",
            " ██      ",
            " ██      "
        ],
        'G': [
            "  ██████ ",
            " ██      ",
            " ██  ███ ",
            " ██   ██ ",
            "  ██████ "
        ],
        'H': [
            " ██   ██ ",
            " ██   ██ ",
            " ███████ ",
            " ██   ██ ",
            " ██   ██ "
        ],
        'I': [
            " ███████ ",
            "    ██   ",
            "    ██   ",
            "    ██   ",
            " ███████ "
        ],
        'L': [
            " ██      ",
            " ██      ",
            " ██      ",
            " ██      ",
            " ███████ "
        ],
        'O': [
            "  ██████ ",
            " ██   ██ ",
            " ██   ██ ",
            " ██   ██ ",
            "  ██████ "
        ],
        'R': [
            " ██████  ",
            " ██   ██ ",
            " ██████  ",
            " ██  ██  ",
            " ██   ██ "
        ],
        'S': [
            "  ██████ ",
            " ██      ",
            "  █████  ",
            "      ██ ",
            " ██████  "
        ],
        'T': [
            " ███████ ",
            "    ██   ",
            "    ██   ",
            "    ██   ",
            "    ██   "
        ],
        'U': [
            " ██   ██ ",
            " ██   ██ ",
            " ██   ██ ",
            " ██   ██ ",
            "  ██████ "
        ],
        'W': [
            " ██   ██ ",
            " ██   ██ ",
            " ██ █ ██ ",
            " ███████ ",
            " ██   ██ "
        ],
        ' ': [
            "         ",
            "         ",
            "         ",
            "         ",
            "         "
        ]
    }
    
    return art_dict.get(char.upper(), [
        " ███████ ",
        " ██   ██ ",
        " ██   ██ ",
        " ██   ██ ",
        " ███████ "
    ])

def text_to_ascii_banner(text):
    """Convert text to ASCII art banner"""
    if len(text) > 10:
        return "Text too long! Please use 10 characters or less."
    
    # Get ASCII art for each character
    char_arts = [char_to_ascii(char) for char in text]
    
    # Combine horizontally
    result = []
    for row in range(5):
        line = ""
        for char_art in char_arts:
            line += char_art[row]
        result.append(line)
    
    return "\n".join(result)

def create_border(text, char="*"):
    """Create a decorative border around text"""
    width = len(text) + 4
    border = char * width
    return f"""
{border}
{char} {text} {char}
{border}
"""

def draw_patterns():
    """Draw some fun ASCII patterns"""
    patterns = {
        "Heart": [
            " ██   ██ ",
            "███ ███ ",
            "███████ ",
            " █████  ",
            "  ███   ",
            "   █    "
        ],
        "Star": [
            "    ★    ",
            "   ★★★   ",
            "  ★★★★★  ",
            "   ★★★   ",
            "    ★    "
        ],
        "Diamond": [
            "    ◆    ",
            "   ◆◆◆   ",
            "  ◆◆◆◆◆  ",
            "   ◆◆◆   ",
            "    ◆    "
        ]
    }
    
    for name, pattern in patterns.items():
        print(f"\n{name}:")
        for line in pattern:
            print(line)

# Main program
print("🎨 ASCII Art Generator")
print("=" * 50)

# Get user input
user_text = input("Enter text for ASCII art (max 10 chars): ")

# Generate ASCII art
print("\n🎯 Your ASCII Art:")
print(text_to_ascii_banner(user_text))

# Add decorative border
print("\n🎁 With Border:")
print(create_border(user_text))

# Show some patterns
print("\n🌟 Bonus Patterns:")
draw_patterns()

print("\n✨ Try different words and see the magic!")
