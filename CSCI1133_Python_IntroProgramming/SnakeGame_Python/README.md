# README

Project: PriorityQueue implementation in Java

Name: Andreas Hochrein

What was the context and nature of this project?

This project was the final project in a Introduction to Programming  class.

This project was individual.

What does this program do?

The SnakeGUI class implements a simple snake game. It utilizes the python library tkinter to create the UI.

The UI includes a button that switches between the different stages of the game: run, pause, over.

On the canvas, the snake (chain of square objects) moves constantly in the direction the user gives with the arrow or awsd keys. The objective of the game is to collide the snake with the food pallets (i.e. to eat them) and to grow the snake. Each time the snake eats a pallet, it's length increases by one element. Food pallets are randomly placed on the canvas. As soon as the snake collides with a wall or itself, the game is over.

The program keeps track of the score in each game. 

How to run this program?

To run this program in the interpreter IDLE, just choose 'Run Module' in the Dropdown menu 'Run' and invoke the driver function by entering 'main()' into the command line. 

How is the program built?

The program is contained in the class SnakeGUI. The constructor sets up the UI and the game.
The member function drawsnake() takes care of the animation in the game. It redraws the snake elements when the snake is moving and the program is in the running state. It defines what happens during collisions. It also places the food pallets and decreases the delay in redrawing the snae elements (i.e. increases the speed of the snake) after each food pallet is consumed. 
Buttenpress() defines the functionality of the switch button at the bottom of the window and allows to switch between states.
Keypress() defines how to steer the snake.
Reset() resets the game to it's initial state after the game ends due to collision.