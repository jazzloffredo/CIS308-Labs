//
//  rectangle.c
//  Week11 
//
//  Created by Ashley Coleman on 7/5/18.
//  Copyright © 2018 Ashley Coleman. All rights reserved.
//

#include "rectangle.h"

#include <stdlib.h>

float rectangle_perimeter(Shape * s) {
    Rectangle * r = (Rectangle *)s;
    return 2 * r->width + 2 * r->height;
}

float rectangle_area(Shape * s) {
    Rectangle * r = (Rectangle *)s;
    return r->width * r->height;
}

// This function creates and returns a new Rectangle
// but returns it as a shape so it can be used as such.
//
// Tasks
// 1) dynamically create an instance of Rectangle (malloc)
// 2) Set the width and height of the Rectangle
// 3) Set the perimeter and area function pointers to the functions 
//        provided above
// 4) Return the rectangle as a shape
//        Hint: To convert a pointer from one type to another we can cast like in c#
//        i.e. Person * p = (Person *)new_employee(...);
Shape * new_rectangle(float width, float height) {
    Rectangle * rec = malloc(sizeof(Rectangle));
    rec->width = width;
    rec->height = height;
    rec->base.perimeter = rectangle_perimeter;
    rec->base.area = rectangle_area;
    return (Shape *)rec;
}

