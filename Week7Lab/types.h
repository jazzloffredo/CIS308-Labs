//
//  types.h
//  Week 7 
//
//  Created by Ashley Coleman on 7/5/18.
//  Copyright © 2018 Ashley Coleman. All rights reserved.
//

#ifndef types_h
#define types_h

typedef enum { FALSE, TRUE } bool;

// Define a typedef'd struct called "LinkedList" with the following variables 
// An enum variable called "type" with the values "Integer", "Character", "Float"
// A union variable called "value" with the following variables
//     an int called "i"
//     a char called "c"
//     a float called "f"
// A struct LinkedList pointer called next

typedef struct LinkedList{
	enum {Integer, Character, Float} type;
	union {
		int i;
		char c;
		float f;
	} value;
	
	struct LinkedList *next;
	
} LinkedList;


#endif /* types_h */
