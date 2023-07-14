import random
from tkinter import *
from tkinter import ttk
#help(random.random)
#class MyFirstClass(object):
 ##      self.__attr = attr
   # def affichage(self):
    #    print(self.attr)
#firstObject = MyFirstClass(5)
#firstObject.affichage()
#i = firstObject._MyFirstClass__attr
#print(i)
root = None
def buttonPushed():
    global root
    root.destroy()

def main():
    global root
    root = Tk()
    lab = Label(root,text="riririri")
    lab.pack()
    exitbutton = Button(root, text= "start",command=buttonPushed)
    exitbutton.pack()
    ef = Entry(root)


     = ef.get()

    ef.pack()
    root.mainloop()
    print("Le texte est:",txt)
main()



