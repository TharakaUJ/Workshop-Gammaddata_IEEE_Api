print("✨ Welcome to the Python Magic Show! ✨")
name = input("What's your name? ")

stars = "*" * (len(name) + 10)
print(stars)
print("*** {0} ***".format(name.upper()))
print(stars)

print(f"\nHello, {name}! Did you know your name has {len(name)} letters?")
print(f"Your name backwards is: {name[::-1]}")
print(f"Your name in title case: {name.title()}")

print("\nHere are the Unicode code points for each letter in your name:")
for char in name:
    print(f"{char}: {ord(char)}")

print("\nPython can do amazing things with just a few lines of code!")
print(r"""
      .-.
     (o o) boo!
      |O| 
     _|_|_
""")