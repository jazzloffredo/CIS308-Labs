//
//  triangle.c
//  Week11 
//
//  Created by Ashley Coleman on 7/5/18.
//  Copyright © 2018 Ashley Coleman. All rights reserved.
//

#include "triangle.h"

#include <stdlib.h>
#include <math.h>

float triangle_perimeter(Shape * s) {
    Triangle * t = (Triangle *)s;
    return t->a + t->b + t->c;
}

float triangle_area(Shape * s) {
    Triangle * t = (Triangle *)s;

    float p = triangle_perimeter(s) / 2;
    float base = p * (p - t->a) * (p - t->b) * (p - t->c);

    return sqrt(base);
}

// This function creates and returns a new Triangle 
// but returns it as a shape so it can be used as such.
//
// Tasks
// 1) dynamically create an instance of Triangle (malloc)
// 2) Set the a, b, and c of the triangle 
// 3) Set the perimeter and area function pointers to the functions 
//        provided above
// 4) Return the triangle as a shape
//        Hint: To convert a pointer from one type to another we can cast like in c#
//        i.e. Person * p = (Person *)new_employee(...);
Shape * new_triangle(float a, float b, float c) {
    Triangle * tri = malloc(sizeof(Triangle));
    tri->a = a;
    tri->b = b;
    tri->c = c;
    tri->base.perimeter = triangle_perimeter;
    tri->base.area = triangle_area;
    return (Shape *)tri;
}

