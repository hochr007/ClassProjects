from tkinter import *
import random

class SnakeGUI():

    # Constructor: Initialization of UI
    def __init__(self):
        # Scaling to lessen magic number pain
        self.scale = 20

        # Canvas
        self.root = Tk()
        self.canvas = Canvas(self.root, width=30*self.scale, height=30*self.scale, background='grey')
        self.canvas.pack()

        # The button
        self.butt = Button(self.root, text="START NEW GAME", command=self.buttpress)
        self.butt.pack()
        self.butt.bind('<space>', self.buttpress)

        # The Label
        self.label = Label(self.root, text ='')
        self.label.pack()
        self.score = Label(self.root, text = '')
        self.score.pack()
        
        # Bind the keypress
        self.root.bind('<KeyPress>', self.keypress)

        self.reset()
        self.drawsnake()
        self.root.mainloop()


    # Animate the movement of the snake by redrawing it.
    # Placement of snake elements depends on input from keyboard, state, and collisions
    def drawsnake(self):
        
        if self.state == 'pause':
            pass

        elif self.state == 'run':
            self.xy = (self.xy[0]+self.dir[0], self.xy[1]+self.dir[1])
            # Snack Collision
            if self.xy[0] == self.fxy[0] and self.xy[1] == self.fxy[1]:
                self.snake.insert(0, (self.xy[0], self.xy[1],
                                      self.canvas.create_rectangle(self.xy[0]*self.scale,
                                                                   self.xy[1]*self.scale,
                                                                   (self.xy[0]+1)*self.scale,
                                                                   (self.xy[1]+1)*self.scale,
                                                                   fill='green')))
                self.delay -= 10 #Delay Reduction
                # Delete Old Food
                self.canvas.delete(self.food)
                # New Food Placement
                self.fxy = (random.randint(0, 29),random.randint(0, 29))
                k = 0
                while k < len(self.snake):
                    if self.snake[k][0] == self.fxy[0] and self.snake[k][1] == self.fxy[1]:
                        self.fxy = (random.randint(0, 29),random.randint(0, 29))
                    else:
                        k +=1
                self.food = self.canvas.create_oval(self.fxy[0]*self.scale, self.fxy[1]*self.scale,
                                                    (self.fxy[0]+1)*self.scale, (self.fxy[1]+1)*self.scale,
                                                   fill='orange')
            #Wall Collision                
            elif self.xy[0]< 0 or self.xy[1]< 0 or self.xy[0]>= 30 or self.xy[1]>= 30: 
                self.state = 'over'
            else:
                # Remove the tail
                self.canvas.delete(self.snake[-1][2])
                del self.snake[-1]

                # Add the new head
                self.snake.insert(0, (self.xy[0], self.xy[1],
                                      self.canvas.create_rectangle(self.xy[0]*self.scale,
                                                                   self.xy[1]*self.scale,
                                                                   (self.xy[0]+1)*self.scale,
                                                                   (self.xy[1]+1)*self.scale,
                                                                   fill='green')))
            k = 1 #Snake Collision
            while k <len(self.snake):
                if self.xy[0]== self.snake[k][0] and self.xy[1] == self.snake[k][1]:
                    self.state = 'over'
                    k = len(self.snake)
                else:
                    k +=1

        elif self.state == 'over':
             self.label['text'] = "GAME OVER"
             score = 'CONGRATS, Your Score is '+str(len(self.snake))
             self.score['text'] = score
             self.butt['text'] = "ANOTHER TRY?"

        self.root.after(self.delay, self.drawsnake)

    
    # Control Switch button for state. Three possible states: pause, run, over
    def buttpress(self):
        if self.state == 'pause':
            self.butt['text'] = "Pause"
            self.state = 'run'

        elif self.state == 'run':
            self.butt['text'] = "PLAY?"
            self.state = 'pause'

        elif self.state == 'over':
            self.butt['text'] = "START NEW GAME"
            self.reset()


    # Define the keys that allow to move the snake
    def keypress(self, event):
        key = event.keysym
        if key == 'w' or key == 'Up':
            self.dir = (0,-1)
        elif key == 's' or key == 'Down':
            self.dir = (0,1)
        elif key == 'a' or key == 'Left':
            self.dir = (-1,0)
        elif key == 'd' or key == 'Right':
            self.dir = (1,0)
        elif key == 'space':
            self.buttpress()


    # Reset the window, food, snake to the initial state
    def reset(self):
        self.canvas.delete(ALL)
        self.label['text'] = ""
        self.score['text'] = ""
        
        # Create initial food
        self.fxy = (15, 15)
        self.food = self.canvas.create_oval(self.fxy[0]*self.scale, self.fxy[1]*self.scale,
                                            (self.fxy[0]+1)*self.scale, (self.fxy[1]+1)*self.scale,
                                            fill='orange')
        # Create initial snake
        self.xy = (0,15)
        self.snake = []
        self.snake.append((self.xy[0], self.xy[1],
                           self.canvas.create_rectangle(self.xy[0]*self.scale,
                                                        self.xy[1]*self.scale,
                                                        (self.xy[0]+1)*self.scale,
                                                        (self.xy[1]+1)*self.scale,
                                                        fill='green')))
        # Default values
        self.delay = 500
        self.dir = (1,0)
        self.state = 'pause' 

# Driver function

def main():
    snake = SnakeGUI()
