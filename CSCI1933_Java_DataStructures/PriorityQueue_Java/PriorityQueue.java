package project2;

public class PriorityQueue<E> {
	
	//members
	private GenericNodePrio<Queue<E>> header; 
	private GenericNodePrio<Queue<E>> tail;
	private int size;
	
	//constructor
	public PriorityQueue(){
		header = null;
		tail = header;
		size = 0;
	}
		
	//Core methods
	public void addWithPriority(E element, int priority) {
		try{
			//Does the priority level exist already?
			int i = 0;
			GenericNodePrio<Queue<E>> pointer = header;
			while (i <size){
				if (pointer.getPriority()==priority){
					pointer.getData().add(element);
					return;
				}
				pointer = pointer.getNext();
				i++;
			}
			//The priority level is new:
			GenericNodePrio<Queue<E>> newNode = new GenericNodePrio<Queue<E>>(null,null, priority);
			Queue<E> newQueue = new Queue<E>();
			newQueue.add(element);
			newNode.setData(newQueue);
			//Empty List
			if (header == null){
				header= newNode;
				tail= newNode;
			}
			//new PrioLevel < header or > tail
			else if (header.getPriority()<priority){
				newNode.setNext(header);
				header = newNode;
			}
			else if (tail.getPriority()>priority){
				tail.setNext(newNode);
				tail = newNode;
			}
			//header < new PrioLevel < tail 
			else{
				GenericNodePrio<Queue<E>> pointer1 = header;
				GenericNodePrio<Queue<E>> pointer2 = header.getNext();
				while (pointer2.getPriority()>priority){
					pointer1 = pointer1.getNext();
					pointer2 = pointer2.getNext();
				}
				newNode.setNext(pointer2);
				pointer1.setNext(newNode);
			}
			size++;
		}
		catch (Exception e){
			System.out.println(e.getMessage());
		}
	}
	
	public E remove() throws NullPointerException{
		if (size>0){
			E temp = header.getData().remove();
			if (header.getData().size()==0){
				if (size==1){
					header = null;
					tail = null;
				}
				else{
					header = header.getNext();
				}
				size--;
			}
			return temp;
		}
		else{
			throw (new NullPointerException("There is no element in this list"));
		}
	}
	
	// Other methods
	
	public String toString(){
		String string = "";
		int i = 0;
		GenericNodePrio<Queue<E>> pointer = header; 
		while (i<size){
			string += pointer.getData().toString()+" ";
			pointer = pointer.getNext();
			i++;
		}
		return string;
	}	
}
