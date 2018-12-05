//
//  core.h
//  Week 7 
//
//  Created by Ashley Coleman on 7/5/18.
//  Copyright © 2018 Ashley Coleman. All rights reserved.
//

#ifndef core_h
#define core_h

#include <stdio.h>

#include "types.h"

bool create_integer_node(LinkedList * list, int value);
bool create_character_node(LinkedList * list, char value);
bool create_float_node(LinkedList * list, float value);
int sum_integer_nodes(LinkedList * list);
float sum_float_nodes(LinkedList * list);

int core_main(int argc, const char * argv[]);

#endif /* core_h */
