## Description
## Table of contents
### [5_1](./5_1)
Insertion: You are given two 32-bit numbers, N and M, and two bit positions, i and j. Write a method  
to insert M into N such that M starts at bit j and ends at bit i. You can assume that the bits j through  
i have enough space to fit all of M. That is, if M = 10011, you can assume that there are at least 5  
bits between j and i. You would not, for example, have j = 3 and i = 2, because M could not fully  
fit between bit 3 and bit 2.  
EXAMPLE:  
Input: N->10000000000, M->10011, i = 2, j = 6  
Output: 10001001100

Solution1:  
This is quite straight forward, follow the steps below:
(1) Do a zero mask from ith~jth in N, e.g. 2th~6th -> 111111110000011  
(2) Create the mask of M.  
(3) Combined.  

### [5_2](./5_2)
Binary to String: Given a real number between 0 and 1 (e.g., 0.72) that is passed in as a double,  
print the binary representation. If the number cannot be represented accurately in binary with at  
most 32 characters, print"ERROR."  

Solution1:  
Come to examples to think through it:  
0.101 -> 0 * (1/1) + 1 * (1/2) + 0 * (1/4) + 1 * (1/8)  
So here we can multiplt the target and the binary by 2 (shilt left by 1), so the result point to the next.  
0.101 (shift 1) -> 1.01 (shift 1) -> 10.1

### [5_3](./5_3)
Flip Bit to Win: You have an integer and you can flip exactly one bit from a O to a 1. Write code to  
find the length of the longest sequence of 1 s you could create.  
EXAMPLE:  
Input: 1775 (or: 11011101111)  
Output: 8  

Solution1:  
The only way to combine two string(1s) is only one zero between them,  
So we can track the pre string(1s) and see if there is only one 0 to combine the current string(1s)  
Remember to add result one more because if the flip except special case (like the string are all 1s)   

### [5_4](./5_4)
Next Number: Given a positive integer, print the next smallest and the next largest number that  
have the same number of 1 bits in their binary representation.  

Solution1:  
Next smallest:  
(1) Search from the least digit, find the first zero following 1(s).  
(2) Use mask to set the zero to 1 and other least digits to zero.  
(3) Use mask to set rest 1(s) from the least digit.  


### [5_5](./5_5)
Debugger: Explain what the following code does: ((n & (n-1 )) == 0).  

Solution1: 

### [5_6](./5_6)
Conversion: Write a function to determine the number of bits you would need to flip to convert  
integer A to integer B.  
EXAMPLE:  
Input: 29 (or: 11101), 15 (or: 01111)  
Output: 2  

Solution1:  

### [5_7](./5_7)
Pairwise Swap: Write a program to swap odd and even bits in an integer with as few instructions as  
possible (e.g., bit O and bit 1 are swapped, bit 2 and bit 3 are swapped, and so on).  

Solution1: 

### [5_8](./5_8)
Draw Line: A monochrome screen is stored as a single array of bytes, allowing eight consecutive  
pixels to be stored in one byte. The screen has width w, where w is divisible by 8 (that is, no byte will  
be split across rows). The height of the screen, of course, can be derived from the length of the array  
and the width. Implement a function that draws a horizontal line from (xl, y) to (x2, y).  
The method signature should look something like:  
drawLine(byte[] screen, int width, int xl, int x2, int y)  

Solution1: 