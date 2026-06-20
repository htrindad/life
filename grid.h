#ifndef GRID_H
#define GRID_H
#include <cstddef>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	grid_s
{
	size_t	w;
	size_t	h;
	size_t	iter;
	size_t	**map;
}		grid_t;
#endif
