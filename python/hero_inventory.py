#!/usr/bin/python

#Hero's inventory
#Demonstrates tuple creation

#create an empty tuple

inventory = ()

#treat the tuple as a condition
if not inventory:
    print("You are empty-handed")
   
input("\nPress the enter key to continue")

#create a tuple with some items

inventory = ("swords",
             "armor",
             "shield", 
             "healing potion")

#printing tuple
print("\nThe tuple inventory is:")
print(inventory)

#print each element in tuple

print("\nYour items")
for item in inventory:
    print(item)

input("\n\nPress the enter key to continue")

#get the length of a tuple
print("you have", len(inventory), "items in your possession.")

input("\nPress the enter key to continue")

#test fpr membership with in
if "healing potion" in inventory:
    print("You will live to fight another day")

#display one item through an idex
index = int(input("\nEnter the index number for an item in inventory: "))
print("At index", index, "is", inventory[index])

#display a slice

start = int(input("\nEnter the index number to begin a slice: "))
finish = int(input("\nEnter the index number to end the slice: "))

print("inventory[", start, ":", finish, "] is", end =" ")
print(inventory[start:finish])

#NOTE: tuples are immutable, they cannot be changed after declaration

