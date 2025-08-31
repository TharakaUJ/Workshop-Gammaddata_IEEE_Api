# Simple & Pretty ASCII Patterns Demo
height = int(input("Enter triangle height (e.g., 5): "))
print("Pretty ASCII Triangle:")
for i in range(1, height + 1):
    print(" " * (height - i) + "*" * (2 * i - 1))