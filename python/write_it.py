#Write it
#Demonstrates writing to a text file

print("Creating a text file with the write() method.")
text_file = open("write_it.txt", "w")
text_file.write("Line 1\n")
text_file.write("This is line 2\n")
text_file.write("That makes this line 3\n")

#Note: The write() method doesn't automatically insert a newline character at the end of a string it writes. Need to put new lines where you want them.

text_file.close()

print("\nReading the newly created file.")
text_file = open("write_it.txt", "r")
print(text_file.read())
text_file.close()

print("\nCreating a text file with the writlines() method.")
text_file = open("write_it.txt", "w")
lines = ["Line 1\n",
        "This is line 2\n",
        "That makes this line 3\n"]
text_file.writelines(lines)
text_file.close

print("\nReading the newly created file.")
text_file = open("write_it.txt", "r")
print(text_file.read())
text_file.close()

input("\n\nPRess the enter key to exit.")
