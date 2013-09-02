#Hero's inventory 3.0
#Demonstrate lists
#Create a list with some items and dislplay with a for loop
inventory = ["sword", "armor", "shield", "healing potion"]
print("Your items:")
for item in inventory:
    print(item)

input("\nPress the enter key to continue")

#get the length of a list
print("you have ", len(inventory), "items in your possession")

input("\nPRess the enter key to continue.")

#test for membership within
if "healing potion" in inventory:
    print("You will live to fight another day.")

#display one item through an index
index = int(input("\nEnter the index number for an itme in inventory: "))
print ("At index", index, "is", inventory[index])

#display a slice
start = int(input("\nEnter the index number to begin a slice: "))
finish = int(input("\nEnter the index number to begin a slice: "))

print("inventory[", start, ":", finish, "] is", end= " ")
print(inventory[start:finish])

input("\nPress the enter key to continue")

#concatenate two lists

chest = ["gold", 'gems']
print("You find a chest which contains:")
print(chest)
print("you add the contents of the chest to your inventory.")
inventory += chest
print("Your inventory is now:")
print(inventory)

input("\nPress the enter key to continue")

#Showing list mutability
#Assign by index
print("You trade your sword for a crossbow.")
inventory[0] = "crossbow"
print("your inventory is now:")
print(inventory)

input("\nPress the enter key to continue")

#Assign by slice
print("You used your gold and gems to buy an orb of future telling.")
inventory[4:6] = ["orb of future telling"]
print("your inventory is now:")
print(inventory)
#NOTE:The list is shrunken by 1 because the slice of 2 element is replaced by 1 element

input("\nPress the enter key to continue")


#Delete an element
print("In a great battle, your shiueld is destroyed.")
del inventory[2]
print("your inventory is now:")
print(inventory)

input("\nPress the enter key to continue")

#Delete a slice

print("your crossbow and armor are stolen by thieves.")
del inventory[:2]
print("your inventory is now:")
print(inventory)

input("\nPress the enter key to continue")

#delete a slice
print("Your crossbow and armor are stolen by thieves.")
del inventory[:2]
print("Your inventory is now: ")
print(inventory)

input("\nPress the enter key to continue")

