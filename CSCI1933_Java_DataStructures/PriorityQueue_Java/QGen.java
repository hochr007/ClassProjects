// this code is from file QGen.java, CSCI 1933 moodle site, by Dovolis, Chris 

package project2;


//QGen.java
//Queue Interface for a generic queue

public interface QGen <T> {


 void add(T o);

 /* adds an object o to a queue placing it in the order of arrival 
    relative to other items added to the queue--first in, first out
    (FIFO) */

 T remove();

 /* removes and returns the object placed in a queue prior
    to any other items presently in the queue */

 int size();

 /* returns the integer quantity of items currently present in the 
    queue */ 

}  // QGen Interface

