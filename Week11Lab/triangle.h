//
//  triangle_h 
//  Week 11 
//
//  Created by Ashley Coleman on 7/5/18.
//  Copyright © 2018 Ashley Coleman. All rights reserved.
//

#ifndef triangle_h
#define triangle_h 

#include "shape.h"

Shape * new_triangle(float, float, float);

// Add to Triangle the following members
// 1) a float called "a"
// 2) a float called "b"
// 3) a float called "c"
typedef struct Triangle {
    Shape base;
    float a;
    float b;
    float c;
} Triangle;

#endif /* rectangle_h */
