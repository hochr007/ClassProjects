// README PhotoApp project

Assignment info:

CSci3081 S2016 Iteration 2 

What I worked on in this project:

This assignment was a group project that the team worked on in three iterations throughout the semester. The current version is version 2.0 .

The entire team worked on the design of the overall project. 

I have written the classes:
- Eraser
- Highlighter
- JPEGApp
- Stamp
- Tool

I have also downloaded and installed the JPEG library and modified the Makefile accordingly. 

In FlashPhotoApp, I have worked on the functions:
-loadImageToCanvas()
-loadImageToStamp()
-saveImageToFile()

I have also worked extensively on debugging and testing the team's code.


1) Program Purpose:
The Purpose of this program is twofold. It provides the user with a drawing board that is similar to Microsoft Paint. The user can make use of eight different interactive drawing tools that can be controlled by dragging the mouse. Each tool can take different colors. The tools provided are Pen, Calligraphy Pen, Eraser, Highlighter, Spray Can, Box Brush, Stamp, and Blur Tool. 
The second purpose of the app is to get users a way to process images. Images that are in JPEG format can be loaded and saved. There are nine different filters that can be applied on a image as well as the interactive tools. This allows for instance for sharpening, blurring and edge detection in an image. 


2) Compiling:
To compile the program, open the directory containing the main Makefile in the terminal and use the following command:

$ make

This will create the executables necessary to successfully run the program.

Please note: This application was written for UNIX and might not compile or run correctly on other platforms.


3) Running: 
After compilation, in the same terminal window, enter the command below to run the main server administrator:

$ ./FlashPhotoApp

Two windows will open. One of them contains the canvas (where the drawing happens), the other one a control UI in which the user can choose from different tools and image filters that she wants to apply to the canvas. It is possible to load JPEG images into the canvas, manipulate them and to save them. 
The App also includes a Undo/Redo function. 


