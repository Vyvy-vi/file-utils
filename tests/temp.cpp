#include <criterion/criterion.h>
#include "../src/factorial.cpp"

Test(factorials, passing) {
    cr_assert(factorial(1) == 1 );
    cr_assert(factorial(2) == 2 );
    cr_assert(factorial(3) == 6 );
    cr_assert(factorial(10) == 3628800 );
}

Test(factorials, failing) {
    cr_assert(factorial(0) == 1);
    cr_assert(factorial(1) == 1);
    cr_assert(factorial(2) == 2);
    cr_assert(factorial(3) == 6);
    cr_assert(factorial(10) == 3628800);
}

Test(misc, failing) {
    cr_assert(0);
}

Test(misc, passing) {
    cr_assert(1);
}