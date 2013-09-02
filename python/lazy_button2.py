#Lazy buttons 2
#Demonstrates using a class wiht tkinter

from tkinter import *

class Application(Frame):
	""" A GUI application with three buttons"""
	def __init__(self, master):
		"""Initialize the Frame."""
		super().__init__()
		self.grid()
		self.create_widgets()
		
	#Called the super class constructor. Passed Application object's master into superclass constructor. Then invoke Application's create_widgets method
	
	def create_widgets(self):
		"""Create three buttons that do nothing."""
		#create first Button
		self.bttn1 = Button(self, text = "I do nothing!")
		self.bttn1.grid()
		
		#create second button
		self.bttn2 = Button(self)
		self.bttn2.grid()
		self.bttn2.configure(text = "Me too!")
		
		#create third Button
		self.bttn3 = Button(self)
		self.bttn3.grid()
		self.bttn3["text"] = "Same here!"
		
#main
root = Tk()
root.title("Lazy Buttons 2")
root.geometry("200x85")

app = Application(root)

root.mainloop()
