#ifndef POINT_H 
#define POINT_H// this helps from stopping the program from importing this module multiple times
// even if #include is used multiple times

typedef struct point
{
        double x;
        double y;
} point;
/*
 * Iniialize and return a point struct value
 * */
 point point_value(double x, double y);
 //print a representation of a point to stdout

 void point_print(point *self);

extern int var;
#endif
