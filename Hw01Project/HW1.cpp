/*  Antonio Santana
  HW1.cpp : This file contains the 'main' function. 
  Purpose: Computes the num to the exp power and the logarithm of a number with a given base.
  Input: The number – num, and the exponent – exp
  Output: "Enter a base : 2"
          "Enter an exponent : 10"
           "2 to the 10 is 1024"*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MyClass
{
public:
    /* Function: power
    Purpose: computes num to the exp power
    Parameters: The number - num, and the exponent -exp
    Returns: 0 if the exp is negative; 1 if exp is 0; raise num to the exp power otherwise.*/
    static int power(int num, int exp);

    /* Function: myLog
    Purpose: computes num to the exp power
    Parameters: The number - num, and the exponent -exp
    Returns: 0 if the exp is negative; 1 if exp is 0; raise num to the exp power otherwise.*/
    static int myLog(int num, int exp);
};

/* Implementation starts here.
* 
* The power function should compute numexp and return the answer as an int. If exp is negative, 
* power should return 0. If it is 0 then power should return 1. You should use a loop to compute 
* this (and not pow (x, y) or anything else in the Math library <cmath>). You can use the following 
* comment to describe your power function.
* 
*  Function:      power
*  Purpose:       computes num to the exp power
*  Parameters:    The number – num, and the exponent – exp
*  Returns:       0 if exp is negative; 1 if exp is 0; raise num to the exp power otherwise.*/
int MyClass::power(int num, int exp)
{
    int results = 1;
    if (!(exp < 0))
    {
        for (int i = 0; i < exp; i++)
        {
            results *= num;
        }
    }
    else
    {
        results = 0;
    }

    return results;
}

/* This function should return the answer as an int, rounded down. It must utilize the function 
* from Task 1 (and not any functions from <cmath>). (Recall that if a^b = c, then logac = b). 
* Revise your main function to prompt the user for one power call and one myLog call. The myLog 
* function should compute numexp and return the answer as an int. 
*
*  Function:      myLog
*  Purpose:       computes the logarithm of a number with a given base.
*  Parameters:    The number – num, and the exponent – exp
*  Returns:       0 if exp is negative; 1 if exp is 0; raise num to the exp power otherwise.*/
int MyClass::myLog(int num, int exp)
{
    int standard = 1;
    int results = power(num, standard);

    while (results != exp)
    {
        if (results >= exp)
        {
            return standard - 1;
        }
        else
        {
            standard += 1;
            results = power(num, standard);
        }
    }
    return standard;

}

/* Program execution begins and ends there. */
int main()
{
    MyClass mc;

    int base, exp, number, powResult, logResult;

    cout << "Enter a base: ";
    cin >> base;
    cout << "Enter an exponent: ";
    cin >> exp;
    powResult = mc.power(base, exp);
    cout << base << " to the " << exp << " is " << powResult;

    cout << endl;
    cout << endl;

    cout << "Enter a base: ";
    cin >> base;
    cout << "Enter an number: ";
    cin >> number;
    logResult = mc.myLog(base, number);
    cout << "Log of " << number << " in base " << base << " is " << logResult;

}
