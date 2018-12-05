//
//  core.c
//  Project 3
//
//  Created by Ashley Coleman on 7/5/18.
//  Copyright © 2018 Ashley Coleman. All rights reserved.
//

#include <stdlib.h>
#include <string.h>

#include "core.h"
#include "types.h"

LinkedList * lex(char * input) {
    LinkedList * head = NULL;
    
    int read = 0;
    Token * t = tokenize(input, &read);
    
    while (t != NULL) {
        input += read;
        
        head = append(head, t);
        
        read = 0;
        t = tokenize(input, &read);
    }
    
    return head;
}

// This is the "parse" function. It takes the list of tokens
// and converts them into an "Abstract Syntax Tree". Whenever
// a operator (ADD, SUBTRACT, MULTIPLY) is seen we need to 
// parse 2 more tree values which themselves can either be a number
// or another operator.
//
// This function is recursive and you will need to recursively 
// call the function for your changes.
//
//  Hints:
//      - call malloc
//      - recursively call parse
//      - Only edit the function where you see "TODO"
//      - Each TODO can be done in only 2 lines of code
//         - Both TODO's are very similar
//
int parse(AST * tree, LinkedList * tokens) {
    if(tree == NULL || tokens == NULL || tokens->value == NULL) {
        return 0;
    }

    int count = 0;

    switch (tokens->value->type) {
        case ADD:
        case SUBTRACT:
        case MULTIPLY:
            tree->value = copy_token(tokens->value);
            count++;
            
            // TODO: Process the left tree, to do so:
            //   1. malloc the left tree pointer
            //   2. recursively call parse with the left tree, and the *advanced* token list (see the advance_list function in linked_list.h) 
            //   3. update count with the results from the recursive call
            tree -> left = malloc(sizeof(AST));
			count += parse(tree -> left, advance_list(tokens, 1));
            // TODO: Process the right tree, to do so:
            //   1. malloc the right tree pointer
            //   2. recursively call parse with the right tree, and the *advanced* token list (see the advance_list function in linked_list.h) 
            //   3. update count with the results from the recursive call
			tree -> right = malloc(sizeof(AST));
			count += parse(tree -> right, advance_list(tokens, count));

            break;
        case INTEGER:
            tree->value = copy_token(tokens->value);
            tree->left = NULL;
            tree->right = NULL;
            count++;
            break;
    }
    return count;
}

// The evaulate function "walks" an Abstract Syntax Tree and produces the result of the program
//
// This function will awlays return the result of the calculation or 0 if an error occurred.
//
// Your job is to implement the recursive call and application of the operator
//
// Hints:
//     - Use recursion
//     - Each TODO is exactly the same except for one small change
//     - Each TODO is only one line
int evaluate(AST * tree) {
    if (tree == NULL) {
        return 0;
    }
    
    switch (tree->value->type) {
        case ADD:
            // TODO: Evaluate the left and right tree and then add and return the results
			return evaluate(tree -> left) + evaluate(tree -> right);
        case SUBTRACT:
            // TODO: Evaluate the left and right tree and then subract and return the results
            return evaluate(tree -> left) - evaluate(tree -> right);
        case MULTIPLY:
            // TODO: Evaluate the left and right tree and then multiply and return the results
            return evaluate(tree -> left) * evaluate(tree -> right);
        case INTEGER:
            return tree->value->value;
    }
}

int execute(char * input) {
    if (input == NULL) {
        return 0;
    }
    
    LinkedList * tokens = lex(input);

    if (tokens == NULL) {
        printf("Syntax error\n");
        return 0;
    }
    
    AST * tree = malloc(sizeof(AST));
    parse(tree, tokens);
    
    int result = evaluate(tree);
    
    free_tree(tree);
    free_list(tokens);
    
    return result;
}

int core_main(int argc, const char * argv[]) {
    char input[100];
    
    printf(":> ");
    fgets(input, 100, stdin);
    while(strcmp(input, "q\n") && strcmp(input, "quit\n") && strcmp(input, "exit\n")) {
        printf("   = %d\n", execute(input));
        printf(":> ");
        fgets(input, 100, stdin);
    } 

    return 0;
}

