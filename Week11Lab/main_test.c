//
//  main_test.c
//  Week11 
//
//  Created by Ashley Coleman on 7/5/18.
//  Copyright © 2018 Ashley Coleman. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "min_unit.h"

#include "core.h"
#include "triangle.h"
#include "rectangle.h"

static char * test_new_triangle() {
    mu_begin_case("new_triangle", 8);

    {
        Shape * s = new_triangle(3, 4, 5);
        Triangle * t = (Triangle *)s;

        mu_assert_not_null("Verify triangle is not null", t);

        if (t == NULL) {
            mu_assert_f("(SKIPPING) Verify t->a is 3", 3.0, 4.0, 0.001);
            mu_assert_f("(SKIPPING) Verify t->b is 4", 4.0, 5.0, 0.001);
            mu_assert_f("(SKIPPING) Verify t->c is 5", 5.0, 6.0, 0.001);
            mu_assert_not_null("(SKIPPING) Verify s->perimeter is not null", NULL);
            mu_assert_f("(SKIPPING) Verify perimeter is 12", 12.0, 13.0, 0.001);
            mu_assert_not_null("(SKIPPING) Verify s->area is not null", NULL);
            mu_assert_f("(SKIPPING) Verify area is 6", 6.0, 7.0, 0.001);
            return 0;
        }

        mu_assert_f("Verify t->a is 3", 3.0, t->a, 0.001);
        mu_assert_f("Verify t->b is 4", 4.0, t->b, 0.001);
        mu_assert_f("Verify t->c is 5", 5.0, t->c, 0.001);

        mu_assert_not_null("Verify s->perimeter is not null", s->perimeter);

        if (s->perimeter == NULL) {
            mu_assert_f("(SKIPPING) Verify perimeter is 12", 12.0, 13.0, 0.001);
            mu_assert_not_null("(SKIPPING) Verify s->area is not null", NULL);
            mu_assert_f("(SKIPPING) Verify area is 6", 6.0, 7.0, 0.001);
            return 0;
        }

        mu_assert_f("Verify perimeter is 12", 12.0, s->perimeter(s), 0.001);

        mu_assert_not_null("Verify s->area is not null", s->area);

        if (s->area == NULL) {
            mu_assert_f("(SKIPPING) Verify area is 6", 6.0, 7.0, 0.001);
            return 0;
        }

        mu_assert_f("Verify area is 6", 6.0, s->area(s), 0.001);
    }

    mu_end_case("new_triangle");
    return 0;
}

static char * test_new_rectangle() {
    mu_begin_case("new_rectangle", 7);

    {
        Shape * s = new_rectangle(4, 5);
        Rectangle * r = (Rectangle *)s;

        mu_assert_not_null("Verify rectangle is not null", r);

        if (r == NULL) {
            mu_assert_f("(SKIPPING) Verify r->width is 4", 4.0, 5.0, 0.001);
            mu_assert_f("(SKIPPING) Verify r->height is 5", 5.0, 5.0, 0.001);
            mu_assert_not_null("(SKIPPING) Verify s->perimeter is not null", NULL);
            mu_assert_f("(SKIPPING) Verify perimeter is 18", 18.0, 19.0, 0.001);
            mu_assert_not_null("(SKIPPING) Verify s->area is not null", NULL);
            mu_assert_f("(SKIPPING) Verify area is 20", 20.0, 21.0, 0.001);
            return 0;
        }

        mu_assert_f("Verify r->width is 4", 4.0, r->width, 0.001);
        mu_assert_f("Verify r->height is 5", 5.0, r->height, 0.001);

        mu_assert_not_null("Verify s->perimeter is not null", s->perimeter);

        if (s->perimeter == NULL) {
            mu_assert_f("(SKIPPING) Verify perimeter is 18", 18.0, 19.0, 0.001);
            mu_assert_not_null("(SKIPPING) Verify s->area is not null", NULL);
            mu_assert_f("(SKIPPING) Verify area is 20", 20.0, 21.0, 0.001);
            return 0;
        }

        mu_assert_f("Verify perimeter is 18", 18.0, s->perimeter(s), 0.001);

        mu_assert_not_null("Verify s->area is not null", s->area);

        if (s->area == NULL) {
            mu_assert_f("(SKIPPING) Verify area is 20", 20.0, 21.0, 0.001);
            return 0;
        }

        mu_assert_f("Verify area is 20", 20.0, s->area(s), 0.001);
    }

    mu_end_case("new_rectangle");
    return 0;
}
static char * all_tests() {
    test_new_triangle();
    test_new_rectangle();
    return 0;
}

#ifdef TEST
int main(int argc, char **argv) {
    mu_run(all_tests);
    return 0;
}
#endif

