// this code is from file GenericNode.java, CSCI 1933 moodle site, by Dovolis, Chris 

package project2;

public class GenericNode<E> {

	private E data; 
	private GenericNode<E> next; 
	
    public GenericNode (E initData, GenericNode<E> initLink) {
        data = initData;
        next = initLink;
    }

    // selectors and modifiers

    public void setData(E newData) {
        data = newData;
    }

    public void setNext(GenericNode<E> newLink) {
        next = newLink;
    }

    public E getData() {
        return data;
    }

    public GenericNode<E> getNext() {
        return next;
    }
    // standard methods
    @Override
    public String toString(){
    	return data.toString();
    }	
}