#Labeler
#Demonstrates a label

from Tkinter import *

#create the root window
root = Tk()
root.title("Labeler")
root.geometry("200x50")

#create a frame in the window to hold other widgets
app = Frame(root)
"""
Any time you create a new widget, you must pass its mater (the thing that will contain the widget) to hte constructor of the new object.
Here root is passed to the Frame constructor. As of a result, the new frame is placed inside the new window.
"""

app.grid()

#create a label in the Frame
lbl = Label(app, text = "I'm a label!")
lbl.grid()

#kick off the window's event loop
root.mainloop()