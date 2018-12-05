//
//  main_test.c
//  Week 5 
//
//  Created by Ashley Coleman on 7/5/18.
//  Copyright © 2018 Ashley Coleman. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#include "min_unit.h"
#include "core.h"

static char * test_swap() {
    mu_begin_case("swap");

    {
        int result = swap(NULL, NULL);
        mu_assert_i("swap(NULL, NULL) should return FALSE", 0, result);
    }

    {
        int a = 3;
        int result = swap(&a, NULL);
        mu_assert_i("swap(a, NULL) should return FALSE", 0, result);
    }

    {
        int b = 5;
        int result = swap(NULL, &b);
        mu_assert_i("swap(NULL, b) should return FALSE", 0, result);
    }

    {
        int a = 3;
        int b = 5;
        int result = swap(&a, &b);
        mu_assert_i("swap(a, b) should return TRUE", 1, result);
        mu_assert_i("swap(a, b) a should be 5", 5, a);
        mu_assert_i("swap(a, b) b should be 3", 3, b);
    }

    mu_end_case("swap");
    return 0;
}

static char * test_to_lower() {
    mu_begin_case("to_lower");

    {
        int result = to_lower(NULL);
        mu_assert_i("to_lower(NULL) should return FALSE", 0, result);
    }

    {
        char s[] = "X";
        int result = to_lower(s);
        mu_assert_i("to_lower(s) should return TRUE", 1, result);
        mu_assert_s("s should be 'x'", "x", s);
    }

    {
        char s[] = "HELLO";
        int result = to_lower(s);
        mu_assert_i("to_lower(s) should return TRUE", 1, result);
        mu_assert_s("s should be 'hello'", "hello", s);
    }

    mu_end_case("to_lower");
    return 0;
}

static char * test_inc_int_list() {
    mu_begin_case("inc_int_list");

    {
        mu_assert_i("inc_int_list(NULL, 0) should return FALSE", 0, inc_int_list(NULL, 0));
    }

    {
        int list[3] = {0, 1, 2};
        int result = inc_int_list(list, 3);
        mu_assert_i("inc_int_list(list, 3) should return TRUE", 1, result);

        mu_assert_i("Assert inc_int_list(list, 3) assigned correct value", 1, list[0]);
        mu_assert_i("Assert inc_int_list(list, 3) assigned correct value", 2, list[1]);
        mu_assert_i("Assert inc_int_list(list, 3) assigned correct value", 3, list[2]);
    }

    mu_end_case("inc_int_list");
    return 0;
}

static char * all_tests() {
    test_swap();
    test_to_lower();
    test_inc_int_list();
    return 0;
}

#ifdef TEST
int main(int argc, char **argv) {
    mu_run(all_tests);
    return 0;
}
#endif

