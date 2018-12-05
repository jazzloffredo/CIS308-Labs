//
//  shape.h
//  Week 11 
//
//  Created by Ashley Coleman on 7/5/18.
//  Copyright © 2018 Ashley Coleman. All rights reserved.
//

#ifndef shape_h
#define shape_h

typedef struct Shape Shape;

// 1) typedef a function pointer called "perimeter_function" that takes a "Shape *" 
//        and returns a "float"
typedef float (* perimeter_function)(Shape * s);
// 2) typedef a function pointer called "area_function" that takes a "Shape *"
//        and returns a "float"
typedef float (* area_function)(Shape * s);
// 3) Define a struct (no typedef) called "Shape"
//        that has a varible of type "perimeter_function" called "perimeter"
//        and a variable of type "area_function" called "area"
struct Shape{
	perimeter_function perimeter;
	area_function area;
};
#endif /* shape_h */
