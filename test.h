//
// Created by pedro on 05/11/22.
//

#ifndef VIRTUAL_MACHINE_TEST_H
#define VIRTUAL_MACHINE_TEST_H

//
// Created by pedro on 04/11/22.
//
#include <stdio.h>
#include <stdbool.h>


typedef bool (*test_fn)();
struct test {
    const char* name;
    const test_fn fn;
};

#define TEST(name) {#name, name ##  _test}

int run_tests(const struct test *tests) {
    size_t failed = 0, succeeded = 0;
    for (const struct  test *test = &tests[0]; test->fn != NULL; test++) {
        bool did_succeed = test->fn();
        if (did_succeed) {
            succeeded++;
            printf("\x1b[32m[SUCCESS]\x1b[0m: %s\n", test->name);
        } else {
            failed++;
            printf("\x1b[31m[FAILED]\x1b[0m: %s\n", test->name);
        }
    }
    if (failed) {
        printf("\x1b[31m");
    } else {
        printf("\x1b[32m");
    }
    printf("Failed: %lu, Succeeded: %lu\n", failed, succeeded);
    printf("\x1b[0m");
}

#endif //VIRTUAL_MACHINE_TEST_H
