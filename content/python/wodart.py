# Importing required modules
from PIL import Image
import pywhatkit

# Store path of image in input_path
input_path = 'E:\\C programs\\Remove BackGround\\gfgoriginal.png'

# Processing image
input = Image.open(input_path)

# Convert image to text form
pywhatkit.image_to_ascii_art(input_path,'GFGART')

# read word art text file
read_file = open("GFGART.txt","r")

# Print word art generated file
print(read_file.read())