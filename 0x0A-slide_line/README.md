The goal of this task is to reproduce the 2048 game mechanics on a single horizontal line.
Given an array of integers, we want to be able to slide & merge it to the left or to the right. 
Identical numbers, if they are contiguous or separated by zeros, should be merged (See example)

# objective
Write a function that slides and merges an array of integers

* Prototype: int slide_line(int *line, size_t size, int direction);
* Where line points to an array of integers containing size elements, that must be slided & merged to the direction represented by direction. direction can be either:
* SLIDE_LEFT
* SLIDE_RIGHT
* If it is something else, the function must fail
* Both macros SLIDE_LEFT and SLIDE_RIGHT must be defined in slide_line.h
* Your function must return 1 upon success, or 0 upon failure
* You are not allowed to allocate memory dynamically (malloc, calloc, …)
