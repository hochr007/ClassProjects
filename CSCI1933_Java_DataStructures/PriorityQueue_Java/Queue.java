package project2;

public class Queue<T> implements QGen <T> {

	//members
	private GenericNode<T> header; 
	private GenericNode<T> tail;
	private int size;

	//constructor
	public Queue (){
		header = null;
		tail = header;
		size = 0;
	}
	//methods
	
	public int size(){
		return size;
	}

	public void add(T element){
		//This should add an element to the List.  It should return false if it failed.
		try{
			GenericNode<T> newNode = new GenericNode<T>(element,null);
			if (header == null){
				header= newNode;
				tail= newNode;
			}
			else{
				tail.setNext(newNode);
				tail = newNode;
			}
			size++;
		}
		catch (Exception e){
			System.out.println(e.getMessage());
		}
	}
	
 
	public T remove(){
		//Empty Queue
		if (size()==0){
			System.out.println("Queue is empty so nothing can be removed");
			return null;
		}
		//Nonempty Queue
		T temp = header.getData();
		if (size()==1){
			header = null;
			tail = null;
		}
		else{
			header = header.getNext();
		}
		size--;
		return temp;
	}
	public String toString(){
		String string = "";
		GenericNode<T> pointer = header;
		int i = 0;
		while (i<size){
			string += pointer.getData().toString()+" ";
			pointer = pointer.getNext();
			i++;
		}
		return string;
	}
}
