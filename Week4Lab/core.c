//
//  core.c
//  Week 4 
//
//  Created by Ashley Coleman on 7/5/18.
//  Copyright © 2018 Ashley Coleman. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#include "core.h"

#define MAX_NAME_LENGTH 20

// This function should write the name of the 
// "highest scorer" into buffer. If a value is
// written into the buffer then TRUE should be return.
// If an error occurs or a value isn't written into 
// butter then FALSE should be returned
//
// i.e. if the file has the following contents
// Pam 10
// Jim 50
// Dwight 100
// Then "Dwight" should be written into buffer
//
// Hint:
//     Remember to check for NULL
//     Use the MAX_NAME_LENGTH constant defined above
//     You will need to call fscanf to read from the file
//
int highest_scorer(char * buffer, FILE * stream) {
	if(stream == NULL || buffer == NULL) return FALSE;
	
	char string[MAX_NAME_LENGTH + 1];
	int max;
	int temp;
	int adjusted = FALSE;
	
	while(fscanf(stream, "%s %d \n", string, &temp) != EOF){
		if(max == 0) {
			max = temp;
			strcpy(buffer, string);
			adjusted = TRUE;
		}
		else if(temp > max){
			max = temp;
			strcpy(buffer, string);
			adjusted = TRUE;
		}
	}
	
    return adjusted;
}

// This function should write name and score into
// the file. The function should return TRUE if the
// score was written. It should return false if there
// was ana error.
//
// i.e. if the file has the contents
// Pam 10
// Dwight 50
//
// and add_score("Jim", 100, fp) is called then the file
// will become
//
// Pam 10
// Dwight 50
// Jim 100
//
// Hint:
//     Remeber to check for NULL
//     You need to match the format exactly or the reading from the file will break
//     You will need to call fprintf to write to the file.
int add_score(char * name, int score, FILE * stream) {
	if(stream == NULL){ 
		return FALSE;
	}
	else{
		fprintf(stream, "%s %d \n", name, score);
		return TRUE;
	}
	
    return FALSE;
}


// This function is the user interaction function. It should handle a few things.
// The last slide in lecture 4 gives more details on what should be done here
//
// Overview: 
//     1. Take as a cli argument the name of the file
//         1.1 Error if no name is provided
//     2. Ask the user if they want the highest score or to add a score
//         2.1 if highest score then open the file for reading and print the result of highest_scorer()
//         2.2 if add score then open the file for appending and and add the score using add_score()
//         2.3 if anything else is entered print and error and exit
//     3. Make sure to close the file when you are done with it 
int core_main(int argc, const char * argv[]) {
	
	if(argc < 2){
		printf("No filename provided.]n");
		return 0;
	}
	
	FILE * fp = fopen(argv[1], "a+");
	
	printf("(H)ighest Score or (A)dd New Score: ");
	
	char answer = getchar();
	getchar(); //newline char
	
	if(answer != 'H' &&  answer != 'h' && answer != 'A' && answer != 'a'){
		printf("Invalid command\n");
		return 0;
	}
	
	if(answer == 'H' || answer == 'h'){
		char buffer[250];
		highest_scorer(buffer, fp);
		printf("%s \n", buffer);
	}
	else{
		char name[MAX_NAME_LENGTH + 1];
		int score;
		printf("Enter name (20 character max): ");
		scanf("%s", name);
		printf("Enter score: ");
		scanf("%d", &score);
		add_score(name, score, fp);
	}
	
	fclose(fp);
    return 1;
}

