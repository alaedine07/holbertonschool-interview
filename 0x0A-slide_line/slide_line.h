#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stddef.h>

#define SLIDE_LEFT 1
#define SLIDE_RIGHT 2

int slide_line(int *line, size_t size, int direction);
void merge_left(int *line, size_t size);
void move_zeros_to_right(int *line, int size);
void move_zeros_to_left(int *line, int size);

#endif
