//
//  core.c
//  Project 1 
//
//  Created by Ashley Coleman on 7/5/18.
//  Copyright © 2018 Ashley Coleman. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "core.h"

#define CHARACTER_COUNT (LAST_CHARACTER - FIRST_CHARACTER + 1) 
#define FIRST_CHARACTER 'A'
#define LAST_CHARACTER 'Z'
#define MAX_MSG_LENGTH 101

#define TRUE 1;
#define FALSE 0;

int is_number_convertable(const char * string) {
    int len = strlen(string);
    const char * s = string;
    
    for (int i = 0; i < len; i++) {
        if (!isdigit(*s)) {
            return FALSE;
        }
        s++;
    }
    
    return TRUE;
}

char encrypt_character(char source, int key) {
	if(key < 0) return source;
	
	if(source != ' '){
		return (((source - FIRST_CHARACTER) + key) % CHARACTER_COUNT) + FIRST_CHARACTER;
	}
	else{
    	return source;
	}
}

void encrypt_string(char * message, int key, int step) {
	int len = strlen(message);
	
	for(int i = 0; i < len; i++){
		message[i] = encrypt_character(message[i], key);
		key += step;
	}
}

char decrypt_character(char source, int key) {
	if(key < 0) return source;
	
    if(source != ' '){
		return (((((source - FIRST_CHARACTER) - key) % CHARACTER_COUNT) + CHARACTER_COUNT) % CHARACTER_COUNT) + FIRST_CHARACTER;
	}
	else{
		return source;
	}
}

void decrypt_string(char * message, int key, int step) {
	int len = strlen(message);
	
	for(int i = 0; i < len; i++){
		message[i] = decrypt_character(message[i], key);
		key += step;
	}
	
}

void print_usage() {
    printf("Usage:\n");
    printf("\t./main encrypt message key key_offset\n");
    printf("\t./main decrypt message key key_offset\n");
}

int strcomp_ignore_case(const char* a, const char* b){
	if(strlen(a) != strlen(b)) return FALSE;
	
	for(int i = 0; i < strlen(a); i++){
		if(tolower(a[i]) != tolower(b[i])) return FALSE;
	}
	
	return TRUE;
}

int check_valid_args(int argc, const char* argv[]){
	
	//Too few arguments supplied
	if(argc < 5){
		printf("Missing arguments\n");
		print_usage();
		return FALSE;
	}
	//Too many arguments supplied
	else if(argc > 5){
		printf("Too many arguments\n");
		print_usage();
		return FALSE;
	}
	
	//--------------------------------------------------
	//Number of arguments is correct, check other params
	//--------------------------------------------------
	
	//First argument is neither decrypt nor encrypt
	if(!strcomp_ignore_case("encrypt", argv[1]) && !strcomp_ignore_case("decrypt", argv[1])){
		printf("Unknown command: %s\n", argv[1]);
		print_usage();
		return FALSE;
	}
	
	//Key does not consist of all digits
	if(!is_number_convertable(argv[3])){
		printf("Key must be an integer\n");
		print_usage();
		return FALSE;
	}
	//Key offset does not consist of all digits
	else if(!is_number_convertable(argv[4])){
		printf("Key offset must be an integer\n");
		print_usage();
		return FALSE;
	}
	
	//Message is longer than 100 char (must account for null byte)
	if(strlen(argv[2]) > 101){
		printf("Max message length is 100 characters\n");
		print_usage();
		return FALSE;
	}
	   
	//All params test passed
	return TRUE;
}

int core_main(int argc, const char * argv[]) {
	//If check_valid_args returns false, exit program
	if(!check_valid_args(argc, argv)){
		return 0;
	}
	
	//All valid params
	char original_msg[MAX_MSG_LENGTH];
	strcpy(original_msg, argv[2]);
	int key = atoi(argv[3]);
	int key_offset = atoi(argv[4]);
	
	if(strcomp_ignore_case("encrypt", argv[1])){
		encrypt_string(original_msg, key, key_offset);
		printf("%s\n", original_msg);
		return 0;
	}
	else if(strcomp_ignore_case("decrypt", argv[1])){
		decrypt_string(original_msg, key, key_offset);
		printf("%s\n", original_msg);
		return 0;
	}
	   
	return 0;
	
}
