# 0x14. Heap Extract

Write a function that extracts the root node of a Max Binary Heap:

* Prototype: int heap_extract(heap_t **root);
* root is a double pointer to the root node of the heap
* Your function must return the value stored in the root node
* The root node must be freed and replace with the last level-order node of the heap
* Once replaced, the heap must be rebuilt if necessary
* If your function fails, return 0
