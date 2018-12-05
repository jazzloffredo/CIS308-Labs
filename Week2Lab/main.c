//
//  main.c 
//  Week2
//
//  Created by Ashley Coleman on 7/5/18.
//  Copyright © 2018 Ashley Coleman. All rights reserved.
//

#include <stdio.h>
#include "core.h"

#ifndef TEST
int main(int argc, const char * argv[]) {
    print_diamond(1);
    printf("\n");
    printf("\n");
    print_diamond(2);
    printf("\n");
    printf("\n");
    print_diamond(5); 
    printf("\n");
    printf("\n");
    print_diamond(10);
}
#endif
