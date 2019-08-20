## Description
## Table of contents
### [4_1](./4_1)
Route Between Nodes: Given a directed graph, design an algorithm to find out whether there is a
route between two nodes.  

Solution1: (Depth-First Search) Use recursive to loop through all the adjacent nodes. Do this method for both direction (n1 -> n2 and n2-> n1), use tag visited/Notvisited in case of loop in Graph.

Soultion2: (Breadth-First Search) Use queue to store the nodes to be visited.  

Note: Breadth-First Search can find the shortest path, however Depth-First Search is easy to be implemented. This can be discussed with interviewer.

### [4_2](./4_2)
Minimal Tree: Given a sorted (increasing order) array with unique integer elements, write an algorithm
to create a binary search tree with minimal height.  

Solution1: Use recursive method, due to minimum height, create parent node from the middle of array, and recursive to get the left and right node.  

### [4_3](./4_3)
List of Depths: Given a binary tree, design an algorithm which creates a linked list of all the nodes
at each depth (e.g., if you have a tree with depth D, you'll have D linked lists).  

Solution1: Use BFS, and record the amount of next level and deducte the number of current level when pop, so we can know when will shitf to next level.  

### [4_4](./4_4)
Check Balanced: Implement a function to check if a binary tree is balanced. For the purposes of
this question, a balanced tree is defined to be a tree such that the heights of the two subtrees of any
node never differ by more than one.  

Solution1: Use recursive method, get the height of left and right sub tree to see if it is balanced tree.

### [4_5](./4_5)
Validate BST: Implement a function to check if a binary tree is a binary search tree.  

Solution1: Use recursive and In-Order method, to make sure ALL left subtree < root value && and root value < right subtree.  
           This one is more difficult than I expect because it compare the value with all subtree (or compare with "last node value"),  
		   however In-order method can perfectly fullfill this requirement.

### [4_6](./4_6)
Successor: Write an algorithm to find the "next" node (i.e., in-order successor) of a given node in a
binary search tree. You may assume that each node has a link to its parent.  

Solution1:  
There are five situation for the given node:  
(1) leaf node and is parent's left node: parent is the next node  
(2) leaf node and is parent's right node: up to the ancester until the previous ancester is left node. If no such node, the node is the last one.  
(3) no left node and not leaf: left most node in right subtree  
(4) no right node and not leaf: parent is the next node  
(5) left and right node exist: left most node in right subtree  

So three method need to be implemted, findParent, left most node in right subtree, up to the ancester.

### [4_7](./4_7)
Build Order: You are given a list of projects and a list of dependencies (which is a list of pairs of
projects, where the second project is dependent on the first project). All of a project's dependencies
must be built before the project is. Find a build order that will allow the projects to be built. If there
is no valid build order, return an error.  
EXAMPLE  
Input:  
projects: a, b, c, d, e, f  
dependencies: (a, d), (f, b), (b, d), (f, a), (d, c)  
Output: f, e, a, b, d, c  

Solution1: build a class of project, and a graph. Create the graph based on the dependency. Loop through the projects and remove the dependency,  
           if the dependency count down to zero, add the prohect to the "to-do list".  

Solution2: Based in the structure above, loop through the projects and each project use the depth first search to find out the sequence,  
           if during the depth frist search, a node is being process also "be touched" again, it means loop, return NULL.

### [4_8](./4_8)
First Common Ancestor: Design an algorithm and write code to find the first common ancestor
of two nodes in a binary tree. Avoid storing additional nodes in a data structure. NOTE: This is not
necessarily a binary search tree.  

Solution1: (Note: in the code each node has unique value, so the same value means they are the same node to simplify test codes)  
Given the assumption that both target nodes are in the current tree. (Or make sure the target nodes are in the tree)
Use recursive method to find the target nodes in left tree and right tree (and the current node)  
(1) If both left and right tree return a node, the current node is the common ancestor, return the current node.  
(2) If one of the sub tree is null, it means the subtree with value is either returned the common ancestor or one of the target node.  
(3) If both are null, return NULL.  
(4) If current node is one of the target node, return current node. (Based one the assumption, this equation can be judged at first)  

Solution2: (Not implemented)  
Given the assumption that all the nodes have the link to parent.
Get the depth of each target node, move the deeper node up the diff depth so that they are in the same level,  
then loop up to root and see if they have same parent.

### [4_9](./4_9)
BST Sequences: A binary search tree was created by traversing through an array from left to right
and inserting each element. Given a binary search tree with distinct elements, print all possible
arrays that could have led to this tree.  

Solution1:  
The key point is that what kind of array can perform the same BST.
The left subtree has a array, the right subtree has its own, the array if the root is combined the two array and put itselft to the front.  
The combined method is keep each array the same sequence in the combined array.  
The coding will have one recursive containing another recursive.  
Two ways for combining arrays:  
(1) Each recursive returns the possible combined subarray. (Not implemented)  
(2) Each recursive will add one node to the prefix array, at the end is the valid combined array then put it to the result.

### [4_10](./4_10)
Check Subtree: Tl and T2 are two very large binary trees, with Tl much bigger than T2. Create an
algorithm to determine if T2 is a subtree of Tl.  
A tree T2 is a subtree of Tl if there exists a node n in Tl such that the subtree of n is identical to T2.
That is, if you cut off the tree at node n, the two trees would be identical.  

Solution1: Run through all the node in T1, if the current node is the same as root node in T2,  
start the procedure to judge if T1 contains T2.  
  
### [4_11](./4_11)
Random Node: You are implementing a binary tree class from scratch which, in addition to
insert, find, and delete, has a method getRandomNode() which returns a random node
from the tree. All nodes should be equally likely to be chosen. Design and implement an algorithm
for getRandomNode, and explain how you would implement the rest of the methods.  

Solution1:

### [4_12](./4_12)
Paths with Sum: You are given a binary tree in which each node contains an integer value (which
might be positive or negative). Design an algorithm to count the number of paths that sum to a
given value. The path does not need to start or end at the root or a leaf, but it must go downwards
(traveling only from parent nodes to child nodes).  

Solution1:
