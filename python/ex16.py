from sys import argv

script, filename =  argv

print("We're going to erase %r." % filename)

input("?")

print("opening the file...")
target = open(filename, 'w')

print("truncating the file. goodbye!")
target.truncate()

print("now I am going to ask you for three lines.")

line1 = input("line 1: ") + "\n"
line2 = input("line 2: ") + "\n"
line3 = input("line 3: ") + "\n"

print("I'm going to write these to the file")

target.write(line1)
#target.write("\n")
target.write(line2)
#target.write("\n")
target.write(line3)
#target.write("\n")

print("and finally we close it.")
target.close()