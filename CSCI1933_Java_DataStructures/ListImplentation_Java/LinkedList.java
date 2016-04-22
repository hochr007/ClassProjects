//To write and test this code, I worked together with Viswavardhan Challa

package lists;

public class LinkedList<E> implements ListInterface<E>{

	//members
	private GenericNode<E> header; 
	private GenericNode<E> tail;
	private int size;

	//constructor
	public LinkedList (){
		tail = header;
		size = 0;
	}
	//methods
	public boolean isEmpty(){
		if (size ==0){
			return true;
		}
		else return false;
	}
	public int size(){
		return size;
	}

	public boolean add(E element){
		//This should add an element to the List.  It should return false if it failed.
		try{
			GenericNode<E> newNode = new GenericNode<E>(element,null);
			if (header == null){
				header= newNode;
				tail= newNode;
			}
			else{
				tail.setNext(newNode);
				tail = newNode;
			}
			size++;
			return true;
		}
		catch (Exception e){
			return false;
		}
	}
	public boolean add(E element, int index){
		//This should add an element to the List at the given index. It should return false if it failed.
		try{
			GenericNode<E> newNode = new GenericNode<E>(element,null);
			if (index > size || index < 0){
				return false;
			}
			else if (index == size){
				return add(element);
			}
			else{
				if (index == 0){
					newNode.setNext(header);
					header = newNode;
				}
				else{
					GenericNode<E> pointer1 = header;
					int i = 1;
					while (i<index){
						pointer1 = pointer1.getNext();
						i++;
					}
					GenericNode<E> pointer2 = pointer1.getNext();
					pointer1.setNext(newNode);
					newNode.setNext(pointer2);
				}
				size++;
				return true;
			}
		}
		catch (Exception e){
			return false;
		}
	}

	//Does exception handling work correctly? 
	public E remove(int index) throws IndexOutOfBoundsException{
		if (index>=size || index <0){
			throw(new IndexOutOfBoundsException("The index selected lies outside of the list"));
		}
		else{
			if (index ==0){
				if (tail == header)
					tail = header.getNext();
				E temp = header.getData();
				header = header.getNext();
				size--;
				return temp;
			}
			else if (index ==size-1){
				GenericNode<E> pointer1 = header;
				int i = 1;
				while (i<index){
					pointer1 = pointer1.getNext();
					i++;
				}
				E temp = pointer1.getNext().getData();
				pointer1.setNext(null);
				tail = pointer1;
				size--;
				return temp;
			}
			else {
				GenericNode<E> pointer1 = header;
				int i = 1;
				while (i<index){
					pointer1 = pointer1.getNext();
					i++;
				}
				E temp = pointer1.getNext().getData();
				pointer1.setNext(pointer1.getNext().getNext());
				size--;
				return temp;
			}
		}
	}
	//This clears the List out and makes it empty.
	public void clear(){
		//GenericNode<E> pointer = header;
		//GenericNode<E> temp = pointer;
		//int i = 0;
		//while (i<size){
			//temp = pointer;
			//pointer = pointer.getNext();
			//temp.setNext(null);
		//}
		header.setNext(null);
		size = 0;
	}

	//This returns the element in the specified index.  This should throw an IndexOutOfBoundsException if the index doesn't exist in the List.
	//throw(new IndexOutOfBoundsException(message);
	//The above line of code will throw an exception.
	public E get(int index) throws IndexOutOfBoundsException{
		if (index <size && index >=0){
			int i = 0;
			GenericNode<E> pointer = header;
			while (i<index){
				pointer = pointer.getNext();
				i++;
			}
			return pointer.getData();
		}
		else{
			throw(new IndexOutOfBoundsException("The index selected lies outside of the list"));
		}
	}
	//This changes the element at the given index to the given element.  
	//This will also throw an IndexOutOfBoundsException if the index doesn't exist in the List.
	public E set(int index, E element) throws IndexOutOfBoundsException{
		if (index <size && index >=0){
			E temp = get(index);
			int i = 0;
			GenericNode<E> pointer = header;
			while (i<index){
				pointer = pointer.getNext();
				i++;
			}
			pointer.setData(element);
			return temp;
		}
		else{
			throw(new IndexOutOfBoundsException("The index selected lies outside of the list"));
		}
	}

	//This checks if the object is within the List.
	//The exact object?
	//How can I check input and Nodes are of the same class?
	//How can apply the .getData() method on o? 
	public boolean contains(Object o){
		int i = 0;
		GenericNode<E> pointer = header;
		while (i<size){
			if (pointer.getData().equals(o))
				return true;
			pointer = pointer.getNext();
			i++;
		}
		return false;
	}
	//This finds the first object in the List equal to o and returns its index.  If no such element exists, it should return -1.
	public int indexOf(Object o){
		int i = 0;
		GenericNode<E> pointer = header;
		while (i<size){
			if (pointer.getData().equals(o))
				return i;
			pointer = pointer.getNext();
			i++;
		}
		return -1;
	}

	//This checks if this List has all the same elements of another List and ONLY those elements in the same order.
	public boolean equals(ListInterface<E> otherList){
		if (size() != otherList.size()){
			return false;
		}
		int i =0;
		while (i<size()){
			if (!get(i).equals(otherList.get(i))){
				return false;
			}
			i++;
		}
		return true;
	}
	//This will return an Array representation of the List that has ONLY the objects in the List and no additional elements.
	//The length of the returned Array should be equal to the List's size() method.
	public Object[] toArray(){
		Object[] listArray = new Object[size()];
		GenericNode<E> pointer = header;
		int i = 0;
		while (i<size){
			listArray[i]=pointer.getData();
			pointer = pointer.getNext();
			i++;
		}
		return listArray;
	}
	public String toString(){
		String string = "";
		GenericNode<E> pointer = header;
		int i = 0;
		while (i<size){
			string += pointer.getData().toString()+" ";
			pointer.getNext();
			i++;
		}
		return string;
	}

}
