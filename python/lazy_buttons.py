#Lazy buttons
#Demonstrates creating buttons

from Tkinter import *

#create a root window
root = Tk()
root.title("Lazy Buttons")
root.geometry("200x85")

#create a frame in the window to hold other widgets
app = Frame(root)
app.grid()

#create a button in the Frame
bttn1 = Button(app, text = "I do nothing!")
bttn1.grid()

#create a second button in the Frame
bttn2 = Button(app)
bttn2.grid()
bttn2.configure(text = "Me too!")
#Can also use configure to change the button

#create a third button in the frame 
bttn3 = Button(app)
bttn3.grid()
bttn3["text"] = "Same here!"
#The text can also be accessed like a dictionary

#Kick off the window's even loop
root.mainloop()