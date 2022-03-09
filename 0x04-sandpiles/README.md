# Sandpiles
### **Introduction**
A sandpile is a grid where its elements can only be 0, 1, 2, or 3, else it  subtrackts 4 from itself and gives +1 to the four directions (up :arrow_up: , down :arrow_down: , left :arrow_left: and right :arrow_right:)

```
2 0 3	toppling      3 0 3
4 2 0      ==>	    * 0 3 0
1 2 1                 2 2 1
```
Numberphile youtube video about Sandpiles [Check Video](https://www.youtube.com/watch?v=1MtEUErz7Gg).



### **Problem statement**

Write a function that computes the sum of two sandpiles

* Prototype: `void sandpiles_sum(int grid1[3][3], int grid2[3][3]);`
* You can assume that both `grid1` and `grid2` are individually **stable**
* A sandpile is considered **stable** when none of its cells contains more than 3 grains
* When your function is done, `grid1` must be **stable**
* `grid1` must be printed before each toppling round, only if it is unstable (See example)
* You’re not allowed to allocate memory dynamically

### **Output**
```
$ ./0-sandpiles
3 3 3   1 3 1
3 3 3 + 3 3 3
3 3 3   1 3 1
=
4 6 4
6 6 6
4 6 4
=
2 5 2
5 6 5
2 5 2
=
4 2 4
2 6 2
4 2 4
=
0 5 0
5 2 5
0 5 0
=
2 1 2
1 6 1
2 1 2
=
2 2 2
2 2 2
2 2 2
```

### **Algorithm**

* Calulate the sum of two sandpiles element by element
* Check if the sum result is stable or not
	* If  its stable: copy the result in the grid1 variable and return
	* If it is not stable: start toppling the sum grid
		* starting a while loop (until grid is stable)
		* Create a new 3x3 grid {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
		* Check the sum element by element:
			- if the element is greater than 3:
				- Subtract 4 and save result in the new grid
				- Check the four directions to add 1 for each and save result in the new grid
			- else just save the element into the new grid
		* Check if the new grid is stable or not
			- Stable: copy the result in the grid1 variable and break
			- Not stable: print the result and copy the new result grit to be the new sum!
