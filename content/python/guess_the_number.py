import random

number = random.randint(1, 10)
print("Guess a number between 1 and 10!")

while True:
    guess = input("Your guess: ")
    if guess == str(number):
        print("You got it!")
        break
    else:
        print("Try again!")
        print(r"""
      .-.
     (o o) boo!
      |O| 
     _|_|_
""")
