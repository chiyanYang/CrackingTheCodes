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

### [1_4](./1_4)
### [1_5](./1_5)
### [1_6](./1_6)
### [1_7](./1_7)
### [1_8](./1_8)
### [1_9](./1_9)