import random

print("you are ...")

mood = random.randint(1,3)

if mood == 1:
	print("happy")
elif mood == 2:
	print("neutral")
elif mood == 3:
	print("sad")
else:
	print("invalid mood value")

