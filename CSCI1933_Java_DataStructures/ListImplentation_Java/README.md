Project: List Interface implementation in Java

Name: Andreas Hochrein

What was the context and nature of this project?

This project was part of an Algorithm and Data Structures course.

This project was individual.

What was the purpose of this project?

The purpose of this project was to implement the API for a list in java as a LinkedList and an ArrayList. The implementations had to include all the methods provided in a java list interface that was given. The ArrayList had the additional challenge of making a reasonable and justifiable decision as to when and by how much to expand and reduce the array structure that underlies this class. 

ArrayList - Justifications for Expanding/Reduction Decision

1. Expanding the array

When and by how much:

I decided to expand the array that my ArrayList class is based on when the size of the arraylist equals the length of the array.
Each time the array expands, its length doubles. Since I initialized the member variable array to length 1, its length increases to 2, 4, 8, 16,… until no space is left in memory.

Justification:

I decided to initialize the array that underlies my arraylist to length 1 and to expand the array only when it is completely full in order to avoid to use unnecessary memory space, particularly for small arraylists.  
I double the size of the array each time I expand it to keep the number of costly operations of copying the array over to another array lower than required with the approach of increasing the array each time the user adds an element(let's call this "approach 0"). For instance, if the array is full with 16 elements and the user wants to add 24 more elements, this will only require my program to expand the array by copying twice while the approach 0 would require this operation 20 times. My array will take away more space since it will be of length 64 instead of 44, but this will probably be worth the lower number of copying operations. The difference in required array-copying operations between my approach and approach 0, increase with the number of elements n. More accurately, for k copying operations with my approach, approach 0 requires (2^k) such operations. The main drawback of my approach is that, particularly with large numbers of elements, there is potential for a large amount of unused space in the array. I think this trade-off is worth the much lower number of copying operations required though.

2. Reducing the array size

When and by how much:

I decided to reduce the array in two cases: if the user uses the clear() method and if the length of the array is twice the size of the arraylist after the user removes an element.
In both cases, I reduce the length of the array to the size of the arraylist.

Justification:

I decided to decrease the size of the array in the above situations to avoid an array that takes away memory space with more than half of its space unused after the user clears an arraylist or removes a large number of elements. The justification for decreasing the length of the array how I did it is the same as the justification for my array expanding approach. I also decided to reduce the size of the array to stay consistent in the resizing of my array with respect to my expanding approach. 



  
  