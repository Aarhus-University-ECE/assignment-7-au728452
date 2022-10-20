#include <math.h>
#include "taylor_sine.h"
#include <stdio.h>
// Add your test cases for Exercise 1b,c) here
int main(int argc, char **argv)
{

printf("%lf\n", taylor_sine(3.1415, 7));
printf("%lf\n", sin(3.1415));
    return 0;
}