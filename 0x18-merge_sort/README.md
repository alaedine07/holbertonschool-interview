# Merge sort

Write a function that sorts an array of integers in ascending order using the Merge Sort algorithm:

* Prototype: void merge_sort(int *array, size_t size);
* You must implement the top-down merge sort algorithm
* When you divide an array into two sub-arrays, the size of the left array should always be <= the size of the right array. i.e. {1, 2, 3, 4, 5} -> {1, 2}, {3, 4, 5}
* Sort the left array before the right array
* You are allowed to use printf
* You are allowed to use malloc and free only once (only one call)
* Output: see example