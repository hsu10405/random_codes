#Handle it
#Demonstrates handling exceptions

#try/except
try:
    num = float(input("Enter a number: "))
except ValueError:
    print("That was not a number!")
    
#You can also specify what kind of exceptions after except

#handle multiple exception types
print()
for value iin (None, "Hi!"):
    try:
        print("Attempting to convert," value, "-->", end=" ")
        print(float(value))
    except (TypeError, ValueError):
        print("Something went wrong!")
        
#Another way to write it
print()
for value iin (None, "Hi!"):
    try:
        print("Attempting to convert," value, "-->", end=" ")
        print(float(value))
    except TypeError:
        print("I can only convert a string or a number!")
    except ValueError:
        print("I can only convery a string of digits!")
        
#get an exception's argument
e = "what are you doing?"
try:
    num = float(input("\nEnter a number: "))
except ValueError as e:
    print("That was not a number! Or as Python would say...")
    print(e)

