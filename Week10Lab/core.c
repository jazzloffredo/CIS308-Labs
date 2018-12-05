//
//  core.c
//  Week10 
//
//  Created by Ashley Coleman on 7/5/18.
//  Copyright © 2018 Ashley Coleman. All rights reserved.
//

#include <stdlib.h>
#include <string.h>

#include "core.h"

// This function takes a value and a function pointer 
// and applies the function to the value twice
//
// i.e. if func adds 2 to value. Then four should be returned
// because 2 would be added twice
//
// Hint:
//     Because func is a pointer, it *can* be NULL
//         In this case just return the value you are given
int apply_twice(int value, int_application_function func) {
	// Null check
	if(!func) return value;
	
	return func(func(value));
}

// This function takes a string and a function pointer.
// The function pointer converts a given character to a new character
// 
// i.e. if s is "HELLO" and func is to_lower then after the call s will be "hello"
// The function pointer should be applied to each individual character
// 
// Hint:
//     As always, check for NULL when working with pointers
//     Remember that the last character of a string is always '\0'
void change_string(char * str, change_string_function func) {
	// Null check
	if(!func) return;
	
	while(*str != '\0'){
		*str = func(*str);
		str++;
	}
}

char unsave_to_upper(char c) {
    if(c == ' ') { return c; }
    return c - 32;
}

// For core main, we are just going to test calling a function
// that accepts a function pointer.
//
// For this method you need to 
// 1) Create a string with only lowercase letters and spaces
// 2) Call change_string with the string from 1) and the function unsave_to_upper
// 3) Print out the result
int core_main(int argc, const char * argv[]) {
	char lower[] = "helloworldmynameisjazz";
	change_string(lower, unsave_to_upper);
	printf("%s\n", lower);
    return 0;
}

