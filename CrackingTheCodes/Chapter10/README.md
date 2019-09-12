## Description
## Table of contents
### [10_1](./10_1)
Sorted Merge: You are given two sorted arrays, A and B, where A has a large enough buffer at the end to hold B.  
Write a method to merge B into A in sorted order.  

Solution1:  
Sorted array is the key point. Merge in two sorted array just need to compare each one by one.
IN this case, we need to put the result in A, so the first thing to do is move the items in A to the last,
to prevent shift remaining items when insert from B.

### [10_2](./10_2)
Group Anagrams: Write a method to sort an array of strings so that all the anagrams are next to each other.  

Solution1:  
Use existing sorting function and modify comparision function.



### [10_3](./10_3)
Search in Rotated Array: Given a sorted array of n integers that has been rotated an unknown  
number of times, write code to find an element in the array. You may assume that the array was  
originally sorted in increasing order.  
EXAMPLE  
lnput:findSin{lS, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14}  
Output: 8 (the index of 5 in the array)  

Solution1:  

### [10_4](./10_4)
Sorted Search, No Size: You are given an array-like data structure Listy which lacks a size  
method. It does, however, have an elementAt ( i) method that returns the element at index i in  
0( 1) time. If i is beyond the bounds of the data structure, it returns -1. (For this reason, the data  
structure only supports positive integers.) Given a Li sty which contains sorted, positive integers,  
find the index at which an element x occurs. If x occurs multiple times, you may return any index.  

Solution1:  


### [10_5](./10_5)
Sparse Search: Given a sorted array of strings that is interspersed with empty strings,  
write a method to find the location of a given string.  
EXAMPLE  
Input: ball,{"at",""}  
Output: 4  

Solution1:  


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
Find Duplicates: You have an array with all the numbers from 1 to N, where N is at most 32,000.  
The array may have duplicate entries and you do not know what N is.  
With only 4 kilobytes of memory available, how would you print all duplicate elements in the array?  

Solution1:  


### [10_9](./10_9)
Sorted Matrix Search: Given an M x N matrix in which each row and each column is sorted in  
ascending order, write a method to find an element.  

Solution1:  


### [10_10](./10_10)
Rank from Stream: Imagine you are reading in a stream of integers. Periodically, you wish to be able  
to look up the rank of a numberx (the number of values less than or equal to x). lmplement the data  
structures and algorithms to support these operations. That is, implement the method track ( int  
x), which is called when each number is generated, and the method getRankOfNumber(int  
x), which returns the number of values less than or equal to x (not including x itself).  
EXAMPLE  
Stream (in order of appearance): 5, 1, 4, 4, 5, 9, 7, 13, 3  
getRankOfNumber(l) 0  
getRankOfNumber(3) = 1  
getRankOfNumber(4) 3  

Solution1:  

### [10_11](./10_11)
Peaks and Valleys: In an array of integers, a "peak" is an element which is greater than or equal to  
the adjacent integers and a "valley" is an element which is less than or equal to the adjacent integers.  
For example, in the array {5, 8, 6, 2, 3, 4, 6}, {8, 6} are peaks and {5, 2} are valleys. Given an array  
of integers, sort the array into an alternating sequence of peaks and valleys.  
EXAMPLE  
Input: {5, 3, 1, 2, 3}  
Output: {5, 1, 3, 2, 3}  

Solution1:  
