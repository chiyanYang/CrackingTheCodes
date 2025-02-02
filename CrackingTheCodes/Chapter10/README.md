## Description
## Table of contents
### [10_1](./10_1)
Sorted Merge: You are given two sorted arrays, A and B, where A has a large enough buffer at the end to hold B.  
Write a method to merge B into A in sorted order.  

Solution1:  
Sorted array is the key point. Merge in two sorted array just need to compare each one by one.
IN this case, we need to put the result in A, so the first thing to do is move the items in A to the last,
to prevent shift remaining items when insert from B.

Optimized:  
Instead of moving element to the back of array, we can compare two arrays from the larger, and put the largest  
the end of array. (not implemented)  

### [10_2](./10_2)
Group Anagrams: Write a method to sort an array of strings so that all the anagrams are next to each other.  

Solution1:  
Use existing sorting function and modify comparision function (sort the string then comapre).  

Solution2:
Use map. Define a key for Anagrams, the string with same key put to value together.  
Loop through the map and combine the value.  

### [10_3](./10_3)
Search in Rotated Array: Given a sorted array of n integers that has been rotated an unknown  
number of times, write code to find an element in the array. You may assume that the array was  
originally sorted in increasing order.  
EXAMPLE  
lnput:find5in{15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14}  
Output: 8 (the index of 5 in the array)  

Solution1:  
Because the target can appear on the both side, so we do the binary search on both sides.  

### [10_4](./10_4)
Sorted Search, No Size: You are given an array-like data structure Listy which lacks a size  
method. It does, however, have an elementAt (i) method that returns the element at index i in  
0(1) time. If i is beyond the bounds of the data structure, it returns -1. (For this reason, the data  
structure only supports positive integers.) Given a Listy which contains sorted, positive integers,  
find the index at which an element x occurs. If x occurs multiple times, you may return any index.  

Solution1:  
(1) Get the size of the array by 2^0, 2^1, 2^2...., until we get -1.
(2) Implement binary search by the lenth we got, note that if we get -1, it means beyond the boundary, search left!  

### [10_5](./10_5)
Sparse Search: Given a sorted array of strings that is interspersed with empty strings,  
write a method to find the location of a given string.  
EXAMPLE  
Input: ball,{"at","", "", "", "ball", "", "", "car", "", "", "dad", "", ""}  
Output: 4  

Solution1:  
Binary search, and if the middle value is empty, keep search the direction (left side search left)  
until find an value, then repeat binary search.  
Note: Need to handle the target is empty string case !!    

### [10_6](./10_6)
Sort Big File: Imagine you have a 20 GB file with one string per line.  
Explain how you would sort the file.  

Solution1:  

### [10_7](./10_7)
Missing Int: Given an input file with four billion non-negative integers, provide an algorithm to  
generate an integer that is not contained in the file. Assume you have 1 GB of memory available for  
this task.  
FOLLOW UP  
What if you have only 10 MB of memory? Assume that all the values are distinct and we now have  
no more than one billion non-negative integers.  

Solution1:  


### [10_8](./10_8)
Find Duplicates: You have an array with all the numbers from 1 to N, where N is at most 32000.  
The array may have duplicate entries and you do not know what N is.  
With only 4 kilobytes of memory available, how would you print all duplicate elements in the array?  

Solution1:  


### [10_9](./10_9)
Sorted Matrix Search: Given an M x N matrix in which each row and each column is sorted in  
ascending order, write a method to find an element.  

Solution1:  
Choose a location, 
(1) If it is smaller than target, we know that we exclude the items of left and top from this location.  
(2) If it is larger than target, we know that we include the items of down and right from this location.  
There are two steps to do binary search:  
(1) Search diagonal, find the two locations near each other which one is larger than target, the other is smaller.
(2) Search both the down left and top right zone, and repeat step (1).  

Advanced thinking:
In a row = 1 square, the above method go through every item.  
Maybe instead of choosing the diagonal item to seperate the square,  
We can choose "middle of the square", the other concept remains the same.  
In the thinking, row = 1 square we do the binary search as well.  

### [10_10](./10_10)
Rank from Stream: Imagine you are reading in a stream of integers. Periodically, you wish to be able  
to look up the rank of a number x (the number of values less than or equal to x). lmplement the data  
structures and algorithms to support these operations. That is, implement the method track(int x),  
which is called when each number is generated, and the method getRankOfNumber(int x),  
which returns the number of values less than or equal to x (not including x itself).  
EXAMPLE  
Stream (in order of appearance): 5, 1, 4, 4, 5, 9, 7, 13, 3  
getRankOfNumber(l) = 0  
getRankOfNumber(3) = 1  
getRankOfNumber(4) = 3  
Note: getRankOfNumber(4) = 3 is because remove a 4, then find the value which is less or equal than 4.

Solution1:  
Binary search tree can be used here. We know that the left tree is less or equal than the middle node.
So we just need to calcuate each node's left tree number of nodes.  
(1) If we search left, do nothing.
(2) If we search right, add the number of left tree and the middle node.
(3) If found nothing, return -1.  

### [10_11](./10_11)
Peaks and Valleys: In an array of integers, a "peak" is an element which is greater than or equal to  
the adjacent integers and a "valley" is an element which is less than or equal to the adjacent integers.  
For example, in the array {5, 8, 6, 2, 3, 4, 6}, {8, 6} are peaks and {5, 2} are valleys. Given an array  
of integers, sort the array into an alternating sequence of peaks and valleys.  
EXAMPLE  
Input: {5, 3, 1, 2, 3}  
Output: {5, 1, 3, 2, 3}  

Solution1:  
We can have 3 numbers as a group, and shift two as next group, which means each group has a common valley.  
If we make sure the middle one is always the peaks, then the left and right are sure to be the valleys.  
Step1: Find the peak in the group, exchange with the middle number.  
Step2: Move to next group, repeat step1.  
In the first group, we can make sure the peak is at the middle after exchange.  
In the next group,  
(1) If the peak at the first number, which is the valley of previous group, exchange with middle surely not affect previous group.  
(2) If the peak at the miidle, no need any action.  
(3) If the peak at the right, exchange with the middle and no affect on the previous group.  
So each step will make the current group [valley, peak, valley] and does not affect previous one.  
After all is done, we will have all that match the rule.  
