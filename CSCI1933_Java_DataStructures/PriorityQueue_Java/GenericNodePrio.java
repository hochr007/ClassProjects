// this code is based on file GenericNode.java, CSCI 1933 moodle site, by Dovolis, Chris

package project2;

public class GenericNodePrio<E> {
	private E data; 
	private GenericNodePrio<E> next; 
	private int priority;
	
    public GenericNodePrio (E initData, GenericNodePrio<E> initLink, int priority) {
        this.data = initData;
        this.next = initLink;
        this.priority = priority;
    }
    public GenericNodePrio () {}
 
    // selectors and modifiers

    public void setData(E newData) {
        data = newData;
    }
    public void setNext(GenericNodePrio<E> newLink) {
        next = newLink;
    }
    public void setPriority(int newPriority){
    	priority = newPriority;
    }
    

    public E getData() {
        return data;
    }
    public GenericNodePrio<E> getNext() {
        return next;
    }
    public int getPriority(){
    	return priority;
    }
    
    // standard methods
    @Override
    public String toString(){
    	return data.toString();
    }	
}
