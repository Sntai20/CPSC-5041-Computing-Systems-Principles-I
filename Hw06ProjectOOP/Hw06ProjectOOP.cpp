/* Antonio Santana
* Hw06ProjectOOP.cpp : This file contains the 'main' function.
* Purpose: C++ program to demonstrate the Big 4 operations and 
*   overloaded operators in the CaesarCipher class.
* Input:
* Output:
*
* Requirements:
* This assignment exercises your understanding of operator overloading in C++. 
* You must overload all appropriate operators. As with other design details, 
* type definition is concerned with consistency. Focus on the expectations of 
* the application programmer.
* 
* We will be revisiting the CaesarCipher class we created for HW 2, with a few 
* modifications. For one, we will not be including the Encryptor interface (since 
* there are no Java-style interfaces in C++).  For another, it's C++, not Java, 
* so you'll get the chance to translate your code to C++.
* 
*/

#include <string>
#include <iostream>
#include "CaesarCipher.h"
using namespace std;

int main() 
{
	string clearTextWord = "Hello, world!";
	string encryptedWord;
	string decryptedWord;
	string message;
	
	try
	{
		CaesarCipher cc;
		encryptedWord = cc.encrypt( clearTextWord );
		decryptedWord = cc.decrypt( encryptedWord );
	}
	catch ( const std::invalid_argument ) 
	{
		message = "Exception: std::invalid_argument";
		cout << message << endl;
	}
	catch ( const std::exception& )
	{
		message = "Exception: Something went wrong.";
		cout << message << endl;
	}

	cout << "Encrypted: " << encryptedWord << endl;
	cout << "Decrypted: " << decryptedWord << endl;

    return 0;
}
