#include "taylor_sine.h"
double taylor_sine(double x, int n)
{
    /* implement your function here */
    double answer = 0;
    double holding = 0;
    double sum_of_holding = x;
    double m = x*x*x;
    double f = 6;
    double c_1 = 2;
    double c_2 = 3;
    for (int i = 1; i < n; i++)
    {
        holding = (m/f); // Calculates each element n individually
        m = m*x*x;
        c_1 += 2;
        c_2 += 2;
        f = f*c_1*c_2;

        if (i == 1)
        {
            sum_of_holding -= holding;
        }
        
    if (i>=2)
    {
        if (i%2 == 1) // if odd
        {
            sum_of_holding -= holding;
        }
        if (i%2 == 0) // if even
        {
            sum_of_holding += holding;
        }
    }
    
        
        
    }
    answer = sum_of_holding; // Transfers the value held in holding to answer
    
    return answer;
}
