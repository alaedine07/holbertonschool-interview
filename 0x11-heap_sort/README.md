# Heap sort

Write a function that sorts an array of integers in ascending order using the Heap sort algorithm

* Prototype: void heap_sort(int *array, size_t size);
* You must implement the sift-down heap sort algorithm
* You’re expected to print the array after each time you swap two elements (See example below)

# Heap Data Structure Applications

* Heap is used while implementing a priority queue.
* Dijkstra's Algorithm
* Heap Sort

# Heap Data Structure

Heap data structure is a complete binary tree that satisfies the heap property, where any given node is:

* always greater than its child node/s and the key of the root node is the largest among all other nodes. This property is also called max heap property.
* always smaller than the child node/s and the key of the root node is the smallest among all other nodes. This property is also called min heap property.

# Complete Binary Tree

A complete binary tree is a binary tree in which all the levels are completely filled except possibly the lowest one, which is filled from the left.

A complete binary tree is just like a full binary tree, but with two major differences

* All the leaf elements must lean towards the left.
* The last leaf element might not have a right sibling i.e. a complete binary tree doesn't have to be a full binary tree.

# Relationship between array indexes and tree element

A complete binary tree has an interesting property that we can use to find the children and parents of any node.

If the index of any element in the array is i, the element in the index 2i+1 will become the left child and element in 2i+2 index will become the right child. Also, the parent of any element at index i is given by the lower bound of (i-1)/2.



## Heapify

Heapify is the process of creating a heap data structure from a binary tree. It is used to create a Min-Heap or a Max-Heap.

# resource

https://www.programiz.com/dsa/heap-data-structure