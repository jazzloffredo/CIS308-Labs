//
//  min_unit.c
//  min_unit 
//
//  Attribution: http://www.jera.com/techinfo/jtns/jtn002.html
//  No Copyrite reserved
//

#ifndef min_unit_h
#define min_unit_h

#define mu_assert(message, test) \
    do { \
        if (!(test)) { \
            tests_failed++; \
            return message; \
        } \
    } while (0)

#define mu_run_test(test) do { char *message = test(); tests_run++; \
    if (message) return message; } while (0)

extern int tests_run;
extern int tests_failed;

#endif /* min_unit_h */
