#Property Critter
#Demonstrates properties

class Critter(object):
    """A virtual pet"""
    def __init__(self, name):
        print("A new critter has been born!")
        self.__name = name
        
    @property
    def name(self):
        return self.__name
        
#By creating a property, you can provide read access to a private attribute. 
#However, a property can also probide write access, and even impose some limits on that access.

    @name.setter
    def name(self, new_name):
        if new_name == "":
            print("A critter's name can't be the empty string.")
        else:
            self.__name = new_name
            print("Name change successful.")
            
    def talk(self):
        print("\nHi, I'am", self.name)
        
#main
crit = Critter("Poochie")
crit.talk()

print("\nMy critter's name is:", end=" ")
print(crit.name)

print("\nAttempting to change my critter's name to Rnadolph")
crit.name = "Randolph"

print("\nMy critter's name is:", end=" ")
print(crit.name)

print("\nAttempting to change my critter's name to the empty string...")
crit.name = ""

print("\nMy critter's name is:", end=" ")
print(crit.name)
