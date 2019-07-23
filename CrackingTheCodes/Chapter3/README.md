## Description
## Table of contents
### [3_1](./3_1)
Three in One: Describe how you could use a single array to implement three stacks.  

(1) Soultion1: Fix size version. Use given length and stack number. Implement push, pop, peek, isFull, isEmpty.  
(2) Soultion2: Variable size version. Assume the first stack start from beginning, and if next stack add an item, the next one start from previous one.  
			   The stack is full only when the array is completly filled.  
               Insert 1 in Stack 0: [1]  
			   Insert 2 in Stack 0: [1, 2]  
			   Insert 3 in Stack 0: [1, 2, 3]  
			   Insert 4 in Stack 1: [1, 2, 3] [4]  
			   Insert 5 in Stack 2: [1, 2, 3] [4] [5]  
			   Insert 6 in Stack 0: [1, 2, 3, 6] [4] [5]  
			   pop in Stack 0: [1, 2, 3, 0] [4] [5] 
### [3_2](./3_2)
Stack Min: How would you design a stack which, in addition to push and pop, has a function min  
which returns the minimum element? Push, pop and min should all operate in 0(1) time.  

(1) Soultion1: Add one more stack to memorize the current min, if push/pop is called, update this stack accordingly.

### [3_3](./3_3)
Stack of Plates: Imagine a (literal) stack of plates. If the stack gets too high, it might topple.  
Therefore, in real life, we would likely start a new stack when the previous stack exceeds some  
threshold. Implement a data structure SetOfStacks that mimics this. SetO-fStacks should be  
composed of several stacks and should create a new stack once the previous one exceeds capacity.  
SetOfStacks. push() and SetOfStacks. pop() should behave identically to a single stack  
(that is, pop () should return the same values as it would if there were just a single stack).  
FOLLOW UP  
Implement a function popAt (int index) which performs a pop operation on a specific sub-stack.  

(1) Soultion1: Use two dimention vector to implement this. Once current stack full, add to next stack.  
               Push loop through all the vector to see if there is one not full in popAt case.
### [3_4](./3_4)
Queue via Stacks: Implement a MyQueue class which implements a queue using two stacks.  

### [3_5](./3_5)
Sort Stack: Write a program to sort a stack such that the smallest items are on the top. You can use  
an additional temporary stack, but you may not copy the elements into any other data structure  
(such as an array). The stack supports the following operations: push, pop, peek, and is Empty.  

### [3_6](./3_6)
Animal Shelter: An animal shelter, which holds only dogs and cats, operates on a strictly"first in, first  
out" basis. People must adopt either the "oldest" (based on arrival time) of all animals at the shelter,  
or they can select whether they would prefer a dog or a cat (and will receive the oldest animal of  
that type). They cannot select which specific animal they would like. Create the data structures to  
maintain this system and implement operations such as enqueue, dequeueAny, dequeueDog,  
and dequeueCat. You may use the built-in Linked list data structure.  
