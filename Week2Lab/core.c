//
//  core.c
//  Week2 
//
//  Created by Ashley Coleman on 7/5/18.
//  Copyright © 2018 Ashley Coleman. All rights reserved.
//

#include <stdio.h>

#include "core.h"

// This function should calculate the letter
// grade for the given percentage
// i.e. 
//     100-90: A
//      89-80: B
//      79-70: C
//      69-60: D
//      59-00: F
//         <0: 0
//
// using only if/else/else if conditionals
//
char calculate_grade(int percent) {
	if(percent >= 90){
		return 'A';
	}
	else if(percent >= 80){
		return 'B';
	}
	else if(percent >= 70){
		return 'C';
	}
	else if(percent >= 60){
		return 'D';	
	}
	else if(percent >= 0){
		return 'F';
	}
	else{
		return 0;
	}
}


// This function should return the department name
// from the given department code. The map is listed below.
// If a unknown code is recieved "Unknown" should be returned.
// Switch should be the only control structure used here
//
// code | department name
//   01 | Computer Science
//   02 | Computer Science
//   05 | Computer Engineering
//   10 | Physics
//   20 | Chemistry
//  100 | Math
char * department_name(int department_code) {
	switch (department_code){
		case 1:
			return "Computer Science";
			break;
		case 2:
			return "Computer Science";
			break;
		case 5:
			return "Computer Engineering";
			break;
		case 10:
			return "Physics";
			break;
		case 20:
			return "Chemistry";
			break;
		case 100:
			return "Math";
			break;
		default:
			return "Unknown";
			break;
	}
    return "";
}

// This function should calculate the factorial of n
// where factorial is defined as n * n - 1 * n - 2 * ... * 1
// i.e 4 factorial = 4 * 3 * 2 * 1 = 24
// There is one special case. 0 factorial is defined to be 1
// Negative factorials are not defined, and thus should return -1
int factorial(int n) {
	if(n < 0){
		return -1;
	}
	
	if(n > 0){
		return n * factorial(n - 1);
	}
	
    return 1;
}


// This function should print out a diamond to the screen.
// The diamond has a different height based on the provided
// height value. Examples of expected output are listed below
//
// if height == 1 then
//
// *
// *
//
// if height == 2 then
//
// *
// **
// **
// *
//
// if height == 5 then
//
// *
// **
// ***
// ****
// *****
// *****
// ****
// ***
// **
// *
//
// This pattern should continue for any given height
// 
// The provided code currently prints out out a rectangle and needs to be updated
// to print out the correct shape.
//
// Use 
//     make main
//     ./main
// to test what the function is currently printing out
//
void print_diamond(int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < i + 1; j++) {
            printf("*");
        }
        printf("\n");
    }

    for (int i = 0; i < height; i++) {
        for (int j = height - i; j > 0; j--) {
            printf("*");
        }
		if(i < height - 1){
        printf("\n");
		}
    }
	
	printf("\n");
}

