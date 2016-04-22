//To write and test this code, I worked together with Viswavardhan Challa

package lists;

public class ArrayList<E> implements ListInterface<E> {

	//members
	private E[] array;
	private int listSize;
	
	//constructor
	public ArrayList(){
		listSize = 0;
		@SuppressWarnings("unchecked")
		E[] tempArray = (E[]) new Object[1];
		array = tempArray;
	}

	//helper methods to resize the internal array
	private void expandArray(){
		@SuppressWarnings("unchecked")
		E[] tempArray = (E[]) new Object[2*array.length];
		int i = 0;
		while (i<array.length){
			tempArray[i] = array[i];
			i++;
		}
		array = tempArray;
	}
	private void reduceArray(){
		@SuppressWarnings("unchecked")
		E[] tempArray = (E[]) new Object[size()];
		int i = 0;
		while (i<size()){
			tempArray[i] = array[i];
			i++;
		}
		array = tempArray;
	}
	//Interface methods
	
	@Override
	public boolean isEmpty() {
		if (size() ==0)
			return true;
		else return false;
	}

	public int size() {
		return listSize;
	}

	public boolean add(E element) {
		try{
			if (size()<array.length)
				array[size()] = element;
			else{
				expandArray();
				array[size()] = element;
			}
			listSize++;
			return true;
		}
		catch (Exception e){
			return false;
		}
	}

	public boolean add(E element, int index) {
		try{
			if (index > size() || index < 0)
				return false;
			if (index == size())
				return add(element);
			else{
				if (size()==array.length)
					expandArray();
				int i =size()-1;
				while (i>=index){
					array[i+1]=array[i];
					i--;
				}
				array[i+1] = element;
				listSize++;
				return true;
			}
		}
		catch (Exception e){
			return false;
		}
	}

	public void clear() {
		int i = 0;
		while(i<size()){
			array[i] = null;
			i++;
		}
		listSize=0;
		reduceArray();
	}

	public boolean contains(Object o) {
		int i = 0;
		while (i <size()){
			if (array[i].equals(o))
				return true;
			i++;
		}
		return false;
	}

	public boolean equals(ListInterface<E> otherList) {
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

	public E get(int index) {
		if (index <size() && index >=0)
			return array[index];
		else
			throw(new IndexOutOfBoundsException("The index selected lies outside of the list"));
	}

	public int indexOf(Object o) {
		int i = 0;
		while (i <size()){
			if (array[i].equals(o))
				return i;
			i++;
		}
		return -1;
	}
	//When to reduce size of array? 
	//Temporary Solution: if list is half the size of the internal array, halve the array
	public E remove(int index)throws IndexOutOfBoundsException{
		if (index>=size() || index <0){
			throw(new IndexOutOfBoundsException("The index selected lies outside of the list"));
		}
		E temp = array[index];
		int i = index+1;
		while (i<size()){
			array[i-1] = array[i];
			i++;
		}
		array[size()-1] = null;
		listSize--;
		if (size() <=(array.length/2)){
			reduceArray();
		}
		return temp;
	}

	public E set(int index, E element)throws IndexOutOfBoundsException {
		if (index <size() && index >=0){
			E temp = array[index];
			array[index] = element;
			return temp;
		}
		else
			throw(new IndexOutOfBoundsException("The index selected lies outside of the list"));
	}

	public Object[] toArray() {
		Object[] arrayOfList = new Object[size()];
		int i = 0;
		while (i<size()){
			arrayOfList[i]=array[i];
			i++;
		}
		return arrayOfList;
	}
	public String toString(){
		String string = "";
		int i = 0;
		while (i<size()){
			string += array[i].toString()+" ";
			i++;
		}
		return string;
	}
}
