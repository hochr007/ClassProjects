// README ChatServer project

Assignment info:

CSci4061 S2016 Assignment 2
section: 5
date: 03/21/16
name: Hui Huang, Zach Foster, Andreas Hochrein

What I worked on in this project:

This assignment was a group project.

As part of the team, I have written the methods:
- list_users()
- add_users()
- send_p2p_msg()

I have also worked on parts of the main method and participated in the merging of the team's code and debugging.


1) Program Purpose:
Purpose of this program is to simulate an interactive chatting application locally using interprocess communication(IPC) to manipulate the interactions. The program plays the roles of both the chat/server administrator and the chatting users. With the command-line interface, the administrator and the users can feed instructions and commands into the terminal and the terminal window(s) will respond accordingly.


2) Compiling:
To compile the program, open the directory containing all of the program files in the terminal and use the following command:

$ make

This will create the executables necessary to successfully run the program.


3) Running: 
After compilation, in the same terminal window, enter the command below to run the main server administrator:

$ ./server

This allows the main server terminal to begin taking in commands and instructions from the program user, as well as broadcast any messages typed in this main terminal to all of the potential chatting users' windows. Other public(non-peer-to-peer) messages from any chat users will also go through the main server and will be broadcasted to all chat windows.


4) Instruction Options in the User Chat window:
After the main server initialization above, program user has the following instruction options to execute:

$ \add user_name
Only available in the server terminal, the "\add" command takes a username user_name and create a chat user and a corresponding chat window. Any messages that are not peer-to-peer(p2p) or instructions from this user will be displayed on all users' chat windows. Closing this chat window removes its user from the list of users.

$ \list
"\list" will list the names of all existing users. It is available to both server terminal and chat user shell window.

$ \kick user_name
Only available in the server terminal, the "\kick" command takes a username user_name and removes a user with that username from the users list and closes its corresponding chat window.

$ \p2p user_name message
Only available in the chat window shell, the "\p2p" command takes a username user_name and any message, and sends that message to the receiving user. On the receiving user's chat window and only there, the name of the sender and the message will be displayed.

$ \exit
It is available on both server terminal and the user chat window shell. If called by any user, that particular user's window will close and be removed from the list of users. If used by server, all of the user windows, if any, will be closed, and the entire program terminates and exits.

$ \seg
Available to both server and users. If used by user, the respective chat window will generate a segmentation fault and close. If called by server, the program stops.


5) Broadcasting:
Any non-instructional texts that are not part of the above commands will be treated as a normal message. It will be displayed to all chat windows along with its sender name; this could be either a user or the server.


6) Error Handling:
Upon incorrect input types for the commands, error messages will be displayed informing the program user what the causing problem was. If the error interferes with the functionalities of the program and causes it to crash, the program will be exited after error has been printed out.
