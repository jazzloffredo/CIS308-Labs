//
//  main_test.c
//  Week 7 
//
//  Created by Ashley Coleman on 7/5/18.
//  Copyright © 2018 Ashley Coleman. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#include "min_unit.h"
#include "core.h"

static char * test_create_integer_node() {
    mu_begin_case("create_integer_node");

    {
        bool result = create_integer_node(NULL, 0);
        mu_assert_i("create_integer_node(NULL) should return FALSE", FALSE, result);
    }

    {
        LinkedList l1;
        l1.next = NULL;

        bool result = create_integer_node(&l1, 5);

        mu_assert_i("create_integer_node(&l1, 5) should return TRUE", TRUE, result);
        mu_assert_i("create_integer_node(&l1, 5) should set type to Integer", Integer, l1.type);
        mu_assert_i("create_integer_node(&l1, 5) should set value.i to 5", 5, l1.value.i);
    }

    mu_end_case("create_integer_node");
    return 0;
}

static char * test_create_character_node() {
    mu_begin_case("create_character_node");

    {
        bool result = create_character_node(NULL, 'A');
        mu_assert_i("create_character_node(NULL) should return FALSE", FALSE, result);
    }

    {
        LinkedList l1;
        l1.next = NULL;

        bool result = create_character_node(&l1, 'A');

        mu_assert_i("create_character_node(&l1, 'A') should return TRUE", TRUE, result);
        mu_assert_i("create_character_node(&l1, 'A') should set type to Character", Character, l1.type);
        mu_assert_c("create_character_node(&l1, 'A') should set value.c to A", 'A', l1.value.c);
    }

    mu_end_case("create_character_node");
    return 0;
}

static char * test_create_float_node() {
    mu_begin_case("create_float_node");

    {
        bool result = create_float_node(NULL, 0.0);
        mu_assert_i("create_float_node(NULL) should return FALSE", FALSE, result);
    }

    {
        LinkedList l1;
        l1.next = NULL;

        bool result = create_float_node(&l1, 5.2);

        mu_assert_i("create_float_node(&l1, 5.2) should return TRUE", TRUE, result);
        mu_assert_i("create_float_node(&l1, 5.2) should set type to Float", Float, l1.type);
        mu_assert_f("create_float_node(&l1, 5.2) should set value.f to 5.2", 5.2, l1.value.f, 0.001);
    }

    mu_end_case("create_float_node");
    return 0;
}

static char * test_sum_integer_nodes() {
    mu_begin_case("sum_integer_nodes");

    {
        int result = sum_integer_nodes(NULL);
        mu_assert_i("sum_integer_nodes(NULL) should return 0", 0, result);
    }

    {
        LinkedList h, a, b, c, d, e, f;
        create_character_node(&h, 'A');
        create_integer_node(&a, 1);
        create_float_node(&b, 1.1);
        create_integer_node(&c, 2);
        create_float_node(&d, 2.2);
        create_integer_node(&e, 3);
        create_float_node(&f, 3.3);
    
        h.next = &a;
        a.next = &b;
        b.next = &c;
        c.next = &d;
        d.next = &e;
        e.next = &f;
        f.next = NULL;

        int result = sum_integer_nodes(&h);
        mu_assert_i("sum_integer_nodes(&h) should return 6", 6, result);
    }

    mu_end_case("sum_integer_nodes");
    return 0;
}

static char * test_sum_float_nodes() {
    mu_begin_case("sum_float_nodes");

    {
        float result = sum_float_nodes(NULL);
        mu_assert_f("sum_float_nodes(NULL) should return 0.0", 0.0, result, 0.000001);
    }

    {
        LinkedList h, a, b, c, d, e, f;
        create_character_node(&h, 'A');
        create_integer_node(&a, 1);
        create_float_node(&b, 1.1);
        create_integer_node(&c, 2);
        create_float_node(&d, 2.2);
        create_integer_node(&e, 3);
        create_float_node(&f, 3.3);
    
        h.next = &a;
        a.next = &b;
        b.next = &c;
        c.next = &d;
        d.next = &e;
        e.next = &f;
        f.next = NULL;

        float result = sum_float_nodes(&h);
        mu_assert_f("sum_float_nodes(&h) should return 6.6", 6.6, result, 0.000001);
    }

    mu_end_case("sum_float_nodes");
    return 0;
}

static char * all_tests() {
    test_create_integer_node();
    test_create_character_node();
    test_create_float_node();
    test_sum_integer_nodes();
    test_sum_float_nodes();
    return 0;
}

#ifdef TEST
int main(int argc, char **argv) {
    mu_run(all_tests);
    return 0;
}
#endif

