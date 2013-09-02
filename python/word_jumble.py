#Word jumble
#
#The computer picks a random work and then "jumbles" it
#The player has to guess the original word

import random

#create a sequence of words to choose from
WORDS = ("Python", "jumble", "easy", "difficult", "answer", "xylophone")

#pick one word randomly from the sequence

word = random.choice(WORDS)

#create a variable to use later to see if the guess is correct

correct = word

#create a jumbled version of the word

jumble = ""

while word:
    position = random.randrange(len(word))
    jumble += word[position]
    word = word[:position] + word[(position + 1):]

#start the game
print(
"""
            Welcome to word jumble!
    Unscramble the leters to make a word.
    (press the enter at the prompt to quit.)
"""
)
print("The jumble is: ", jumble)

guess = input("\nYour guess ")
while guess != correct and guess != "":
    print("Sorry, that's not it.'")
    guess = input("Your guess: ")

if guess == correct:
    print("that's it! You guessed it!\n")

print("thanks for playing!")

print("\nPress the enter key to exit.")
