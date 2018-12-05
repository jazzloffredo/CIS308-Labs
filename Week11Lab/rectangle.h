//
//  rectangle_h 
//  Week 11 
//
//  Created by Ashley Coleman on 7/5/18.
//  Copyright © 2018 Ashley Coleman. All rights reserved.
//

#ifndef rectangle_h
#define rectangle_h 

#include "shape.h"

Shape * new_rectangle(float, float);

// Add to Rectangle the following members
// 1) a float called "width"
// 2) a float called "height"
typedef struct Rectangle {
    Shape base;
    float width;
    float height;
} Rectangle;

#endif /* rectangle_h */
