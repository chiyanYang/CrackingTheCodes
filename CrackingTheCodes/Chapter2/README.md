## Description
## Table of contents
### [2_1](./2_1)
Remove Dups: Write code to remove duplicates from an unsorted linked list.  
FOLLOW UP  
How would you solve this problem if a temporary buffer is not allowed?  

(1) Solution1: Use set to store the data and find the duplicate.  
(2) Solution2(FOLLOW UP): Use two pointer to iterate the list. (Not implementd)
### [2_2](./2_2)
2.2 Return Kth to Last: Implement an algorithm to find the kth to last element of a singly linked list.  

(1) Solution1: Use iterative to count the amount of nodes from the end. (Not implemented)  
(2) Solution2: Use two pointer which have k node in between,  
### [2_3](./2_3)
Delete Middle Node: Implement an algorithm to delete a node in the middle (i.e., any node but  
the first and last node, not necessarily the exact middle) of a singly linked list, given only access to  
that node.  
EXAMPLE  
lnput:the node c from the linked list a->b->c->d->e->f  
Result: nothing is returned, but the new linked list looks like a ->b->d- >e- >f  

(1) Solution1: if Given the head node, use two pointer, one is twice faster than another, so get the middle node.  
(2) Solution2: if NOT given the head node, delete the next node by copying the data from next node. (Not implemented)
### [2_4](./2_4)
Partition: Write code to partition a linked list around a value x, such that all nodes less than x come  
before all nodes greater than or equal to x. If x is contained within the list the values of x only need  
to be after the elements less than x (see below). The partition element x can appear anywhere in the  
"right partition"; it does not need to appear between the left and right partitions.  
EXAMPLE  
Input: 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition= 5]  
Output: 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8  

(1) Solution1: Two lists, one for large and one for small, then merge together. (Not implemented)  
(2) Solution2: Begin from a node, then large one go to tail, small one go to head. (Not implemented)  
(3) Solution3: Two pointers, one point to large one, the other to small one, then swap.  
### [2_5](./2_5)
Sum Lists: You have two numbers represented by a linked list, where each node contains a single  
digit. The digits are stored in reverse order, such that the 1 's digit is at the head of the list. Write a  
function that adds the two numbers and returns the sum as a linked list.  
EXAMPLE  
Input: (7-> 1 -> 6) + (5 -> 9 -> 2).That is,617 + 295.  
Output: 2 -> 1 -> 9. That is, 912.  
FOLLOW UP  
Suppose the digits are stored in forward order. Repeat the above problem.  
Input: (6 -> 1 -> 7) + (2 -> 9 -> 5).That is,617 + 295.  
Output: 9 -> 1 -> 2. That is, 912.  

(1) Solution1: recursive mothod, adding two nodes, and get the carry, then recursive call with the carry and next nodes.(not implemented)  
(2) Solution2: iterate mothod (I assume two lists length are the same)  
(3) Solution3(FOLLOW UP): recursive mothod, if two lists length are not the same, padding with zeros. (not implemented)  
### [2_6](./2_6)
Palindrome: Implement a function to check if a linked list is a palindrome.  

(1) Solution1: Reverse and copy the list, and compared the reversed list and original list.  
               (Optimization: only need to compare half of the lists)  
(2) Solution2: (Length of list given) Put half the list to the stack, then compared with the list left. (not implemented)  
(3) Solution3: (Length of list NOT given) Use two pointer, one twice faster then the other,  
               the slow one put the nodes to stack until the fast one reach the end of the list (handle mid node carefully),  
			   then compared. (not implemented)  
### [2_7](./2_7)
Intersection: Given two (singly) linked lists, determine if the two lists intersect. Return the  
intersecting node. Note that the intersection is defined based on reference, not value. That is, if the  
kth node of the first linked list is the exact same node (by reference) as the jth node of the second  
linked list, then they are intersecting.  

(1) Solution1: If tail node of two lists are the same, has intersection. Then the long list move to the same length as the short one.  
               Compared two lists from here.  
### [2_8](./2_8)
Loop Detection: Given a circular linked list, implement an algorithm that returns the node at the beginning of the loop.  
DEFINITION  
Circular linked list: A (corrupt) linked list in which a node's next pointer points to an earlier node,  
so as to make a loop in the linked list.  
EXAMPLE  
Input: A - > B - > C - > D - > E - > C [the same C as earlier]  
Output: C  

(1) Solution1: 
### [2_9](./2_9)