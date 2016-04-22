package lists;

	public interface ListInterface<E> {
		
		public boolean isEmpty();
		//This returns true if the List is empty.
		
		public int size();
		//This will return the size of the List.
		
		public boolean add(E element);
		//This should add an element to the List.  It should return false if it failed.

		public boolean add(E element, int index);
		//This should add an element to the List at the given index. It should return false if it failed.
		
		public void clear();
		//This clears the List out and makes it empty.
		
		public boolean contains(Object o);
		//This checks if the object is within the List.
		
		public boolean equals(ListInterface<E> otherList);
		//This checks if this List has all the same elements of another List and ONLY those elements in the same order.
		
		public E get(int index);
		//This returns the element in the specified index.  This should throw an IndexOutOfBoundsException if the index doesn't exist in the List.
		//throw(new IndexOutOfBoundsException(message);
		//The above line of code will throw an exception.
		
		public int indexOf(Object o);
		//This finds the first object in the List equal to o and returns its index.  If no such element exists, it should return -1.
		
		public E remove(int index);
		//This will remove the element in the index specified.  This will also throw an IndexOutOfBoundsException if the index doesn't exist in the List.
		
		public E set(int index, E element);
		//This changes the element at the given index to the given element.  This will also throw an IndexOutOfBoundsException if the index doesn't exist in the List.
		
		public Object[] toArray();
		//This will return an Array representation of the List that has ONLY the objects in the List and no additional elements.
		//The length of the returned Array should be equal to the List's size() method.

	}
