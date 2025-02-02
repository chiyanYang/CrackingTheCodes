## Description
## Table of contents
### [1_1](./1_1)
Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you
cannot use additional data structures?  
  
(1) Make assumption for the chars in the string: ASCII (128), extended ASCII (256), Unicode.  
    In my soultion assume character set is extended ASCII.  
(2) Solution1: Use boolean array to store the count of each char.  
(3) Solution2: Use bit vector to store the count of each char.  
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

(1) Make assumption char only a to z.  
(2) Solution1: Count the how many times each character appears, should be at most only one odd times to form Palindrome.  
(3) Optimization1: Count odd times while calculateing each characters.  
(4) Solution2: Use bit vector to store and toggle concept to indicate is odd or even, then use simple bit manipulation to get the result.
### [1_5](./1_5)
One Away: There are three types of edits that can be performed on strings: insert a character,
remove a character, or replace a character. Given two strings, write a function to check if they are
one edit (or zero edits) away.  

(1) Solution: Specialize for each case, and merge simliar case (insert and removal), also use string length to decide which case.  
(2) Optimization: This is refactor. Cases can be merged into one function. (Not implemented in my solution).
### [1_6](./1_6)
String Compression: Implement a method to perform basic string compression using the counts
of repeated characters. For example, the string aabcccccaaa would become a2blc5a3. If the
"compressed" string would not become smaller than the original string, your method should return
the original string. You can assume the string has only uppercase and lowercase letters (a - z).  

(1) Solution: This is easy, one thing to notice is to use effective way to combine string (C++ string).  
(2) Optimization: Check the compressed length first.
### [1_7](./1_7)
Rotate Matrix: Given an image represented by an NxN matrix, where each pixel in the image is 4
bytes, write a method to rotate the image by 90 degrees. Can you do this in place?  

(1) Solution: Layer to layer, use swap concept to reduce memory.
### [1_8](./1_8)
Zero Matrix: Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
column are set to 0.  

(1) Solution1: Extra vector to store zeros.  
(2) Solution2: Extra colum and row to store zeros.  
(3) Solution3: Find a zero, then use this line and column to store zeros
(4) Solution4: Use first column and row to store zeros, and two variable to see if this column and row should be all zero. (Not implemented)  
### [1_9](./1_9)
String Rotation: Assume you have a method i 5Su b 5 tr ing which checks if one word is a substring
of another. Given two strings, 51 and 52, write code to check if 52 is a rotation of 51 using only one
call to i5Sub5tring (e.g., "waterbottle" is a rotation of" erbottlewat").  

(1) Solution1: Concatenate the same string twice, it will include any rotation of the original string.