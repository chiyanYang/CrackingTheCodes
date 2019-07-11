## Description
## Table of contents
### [1_1](./1_1)
Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you
cannot use additional data structures?  
  
(1) Make assumption for the chars in the string: ASCII (128), extended ASCII (256), Unicode.  
    In my soultion assume character set is extended ASCII.  
(2) Solution1: Use boolean array to store the count of each char.  
(3) Solution2: Use bit vector to store the count of each char -- to be done  
(4) Solution3: Without additional data structures, use merge sort with inplace.  
(5) Optimization: early break when the string length greater than the char set.
### [1_2](./1_2)
Check Permutation: Given two strings, write a method to decide if one is a permutation of the
other.  
  
(1) Make assumption for the case sensitive and whitespace, also for the char set.  
    In my soultion assume character set is ASCII, so it is case sensitive and take whitespace into account.   
(2) Solution: Count how many times each character appears for each string. They should be the same.  
### [1_3](./1_3)
URLify: Write a method to replace all spaces in a string with '%20'. You may assume that the string
has sufficient space at the end to hold the additional characters, and that you are given the "true"
length of the string. (Note: if implementing in Java, please use a character array so that you can
perform this operation in place.)  

(1) Solution: Walk from the end of the string, copy the real string to the end. This way will make sure there is enough space for replacement.
### [1_4](./1_4)
Palindrome Permutation: Given a string, write a function to check if it is a permutation of
a palindrome. A palindrome is a word or phrase that is the same forwards and backwards. A
permutation is a rearrangement of letters. The palindrome does not need to be limited to just
dictionary words.  
### [1_5](./1_5)
### [1_6](./1_6)
### [1_7](./1_7)
### [1_8](./1_8)
### [1_9](./1_9)