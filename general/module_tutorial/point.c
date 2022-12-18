#include <stdio.h>

#include "point.h"
point point_value(double x, double y)
{
	point initialized = {x,y};
	return initialized;
}

void point_print(point *self)
{
	printf("(%f,%f)\n", self->x,self->y);
}

extern int var=10;