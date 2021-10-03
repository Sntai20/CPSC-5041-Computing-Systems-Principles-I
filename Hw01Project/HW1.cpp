/*

  Antonio Santana
  HW1.cpp : This file contains the 'main' function. 
  Purpose:
  Input:
  Process:
  Output:
  Example:

  Run program: Ctrl + F5 or Debug > Start Without Debugging menu
   Debug program: F5 or Debug > Start Debugging menu

   Tips for Getting Started:
     1. Use the Solution Explorer window to add/manage files
     2. Use the Team Explorer window to connect to source control
     3. Use the Output window to see build output and other messages
     4. Use the Error List window to view errors
     5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
     6. In the future, to open this project again, go to File > Open > Project and select the .sln file

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MyClass
{
public:
    /*

    Function: power
    Purpose: computes num to the exp power
    Parameters: The number - num, and the exponent -exp
    Returns: 0 if the exp is negative; 1 if exp is 0; raise num to the exp power otherwise.

     */
    static int power(int num, int exp);

    /*

    Function: myLog
    Purpose: computes num to the exp power
    Parameters: The number - num, and the exponent -exp
    Returns: 0 if the exp is negative; 1 if exp is 0; raise num to the exp power otherwise.

     */
    static int myLog(int num, int exp);
};

/*
* Implementation starts here.
*/
int MyClass::power(int num, int exp)
{
    cout << num << "power function" << exp << endl;
    return num;
}

int MyClass::myLog(int num, int exp)
{
    vector<string> msg{ "Hello", "C++", "World", "from", "VS Code", "and the C++ extension!" };

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
    cout << num << " myLog function " << exp << endl;
    return num;
}

/*
*  Program execution begins and ends there.
*/
int main()
{
    MyClass mc;
    mc.power(3, 2);
    mc.myLog(5, 2);

}



