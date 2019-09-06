## Description
## Table of contents
### [8_1](./8_1)
Triple Step: A child is running up a staircase with n steps and can hop either 1 step, 2 steps,  
or 3 steps at a time. Implement a method to count how many possible ways the child can run up the stairs.  

Solution1:  
Use recursive method, e.g. tripleStep(remainSteps), which get the all possible ways for the remaining steps,  
In current steps, you can call this method three times with currentSteps - 1, currentSteps - 2, currentSteps - 3.  
These are three ways to get to current steps, so add them up as total steps for current steps.

Solution2(optimized):  
Lots of same function are called repeatedly, it will be good if we keep the result and no need to calculate the result again.  
This optimization is memoization.


### [8_2](./8_2)
Robot in a Grid: Imagine a robot sitting on the upper left corner of grid with r rows and c columns.  
The robot can only move in two directions, right and down, but certain cells are "off limits" such that  
the robot cannot step on them. Design an algorithm to find a path for the robot from the top left to  
the bottom right.  

Solution1:  
Can be done by depth first search.  
In my codes, mark 1 as obstacle, 5 as correct path, 9 as the route never works.  


### [8_3](./8_3)
Magic Index: A magic index in an array A [0 ••• n -1] is defined to be an index such that A[i] = i.  
Given a sorted array of distinct integers, write a method to find a magic index, if one exists, in array A.    
FOLLOW UP  
What if the values are not distinct?  

Solution1 and follow up:  
Brute force way works for the question and follow up,  
but walk through brute force, we can tell that some steps can be skip because of "A[i] = i". (Not implemented)  

Solution2:
Binary search. Sorted array hint us Binary search, and also distinct integers can perform a easy Binary search.  

Follow up:  
Although the array is not distinct, it is still sorted array,  
so Binary search works better in this case compared to Brute force.  
This case we need to consider both left and right search because mid idx greater or smaller than the mid value  
does not mean we can skip search for one part, but we can skip a few number because of the diff between value and idx.  

### [8_4](./8_4)
Power Set: Write a method to return all subsets of a set.  

Solution1:  
All subsets mean that each element we can decide choose or not choose to the current subset.  
Collecting all the cases for choosing or not choosing, all subsets get.  

### [8_5](./8_5)
Recursive Multiply: Write a recursive function to multiply two positive integers without using the  
*operator.You can use addition, subtraction, and bit shifting, but you should minimize the number  
of those operations.  

Solution1:  
Bit shifting is the same as multiply by 2. Use minimum operations, we can shift the larger number.  
(1) The smaller number will seperate into multiple of 2 (e.g. 2^5 + 2^4 + ....).  
(2) The larger number will be shifted according to the "multiple of 2", and add it up to the result.   
Step (1) can be achieved by shift and get the remaining (e.g. 65 -> 32 ....1).  


### [8_6](./8_6)
Towers of Hanoi: In the classic problem of the Towers of Hanoi, you have 3 towers and N disks of  
different sizes which can slide onto any tower. The puzzle starts with disks sorted in ascending order  
of size from top to bottom (i.e., each disk sits on top of an even larger one). You have the following  
constraints:  
(1) Only one disk can be moved at a time.  
(2) A disk is slid off the top of one tower onto another tower.  
(3) A disk cannot be placed on top of a smaller disk.  
Write a program to move the disks from the first tower to the last using stacks.  

Solution1:  
(1) The purpose of the recursive function is important.  
(2) The actor and exit condition is important.  
In the case, to move the source to destination, we keep repeat this process:  
(a) Leave the largest one, move the others to another stack.  
(b) Move the largest one to the destination.  
(c) Move the rest upon the largest one.  

### [8_7](./8_7)
Permutations without Dups: Write a method to compute all permutations of a string of unique characters.  

Solution1:  
In each recursive call, choose one char from the string (and loop through the string) then call the recursive.

### [8_8](./8_8)
Permutations with Dups: Write a method to compute all permutations of a string whose characters  
are not necessarily unique. The list of permutations should not have duplicates.  

Solution1:  


### [8_9](./8_9)
Parens: Implement an algorithm to print all valid (e.g., properly opened and closed) combinations  
of n pairs of parentheses.  
EXAMPLE  
Input: 3  
Output: ( ( () ) ) , ( () () ) , ( () ) () , () ( () ) , () () ()  

Solution1:  
One left parenthese then we can put a right parenthese.
So at each iteration we know we can put a left parenthese and if we can put a right one by counting the existing left.  

### [8_10](./8_10)
Paint Fill: Implement the "paint fill" function that one might see on many image editing programs.  
That is, given a screen (represented by a two-dimensional array of colors), a point, and a new color,  
fill in the surrounding area until the color changes from the original color.  

Solution1:  

### [8_11](./8_11)
Coins: Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents), and  
pennies (1 cent), write code to calculate the number of ways of representing n cents.  

Solution1:  
We can go through all possibilities, start from all posibilities in 25 cents, then count down to 10 cents, then 5 cents.
If the result match the target, add one to the number of ways.  


### [8_12](./8_12)
Eight Queens: Write an algorithm to print all ways of arranging eight queens on an 8x8 chess board  
so that none of them share the same row, column, or diagonal. In this case, "diagonal" means all  
diagonals, not just the two that bisect the board.  

Solution1:  


### [8_13](./8_13)
Stack of Boxes: You have a stack of n boxes, with widths wi , heights hi, and depths di. The boxes  
cannot be rotated and can only be stacked on top of one another if each box in the stack is strictly  
larger than the box above it in width, height, and depth. Implement a method to compute the  
height of the tallest possible stack. The height of a stack is the sum of the heights of each box.  

Solution1:  

### [8_14](./8_14)
Boolean Evaluation: Given a boolean expression consisting of the symbols  
0 (false), 1 (true), &(AND), I (OR), and /\ (XOR), and a desired boolean result value result,  
implement a function to count the number of ways of parenthesizing the expression such that it evaluates to result.  
EXAMPLE  
countEval("l /\01011", false) -> 2  
countEval("0&0&0&1/\ ll0", true) -> 10  
Hints: #748, #168, #197, #305, #327  

Solution1:  
