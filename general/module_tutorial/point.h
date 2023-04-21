#ifndef POINT_H 
#define POINT_H// this helps from stopping the program from importing this module multiple times
// even if #include is used multiple times
/*Once the header is included, it checks if a unique value (in this case HEADERFILE_H) is defined. Then if it's not defined, it defines it and continues to the rest of the page.

When the code is included again, the first ifndef fails, resulting in a blank file.

That prevents double declaration of any identifiers such as types, enums and static variables.*/
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
