/* Antonio Santana
* CaesarCipher.cpp : This file contains the 'main' function.
* Purpose: C++ program to sort and calculate the average student's score.
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
* rand_s Reference:
* https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/rand-s?view=msvc-170
*
* strcpy_s Reference:
* https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/strcpy-s-wcscpy-s-mbscpy-s?view=msvc-170
*/

// Remembering to define _CRT_RAND_S prior
// to inclusion statement.
#define _CRT_RAND_S

#include <stdlib.h> // Required for rand_s
#include "CaesarCipher.h"
#include <cstring>
#include <stdexcept>
#include <iostream>

CaesarCipher::CaesarCipher()
{
	shift = getShift();
}

CaesarCipher::CaesarCipher( const CaesarCipher &cc )
{
	shift = cc.shift;
}

string CaesarCipher::encrypt( string s )
{
	return encryptDecrypt( s, true );
}

string CaesarCipher::decrypt( string s )
{
	return encryptDecrypt( s, false );
}

//CaesarCipher& CaesarCipher::operator=(const CaesarCipher&)
//{
//	// TODO: insert return statement here
//}
//
//CaesarCipher CaesarCipher::operator+(const CaesarCipher&)
//{
//	return CaesarCipher();
//}
//
//bool CaesarCipher::operator==(const CaesarCipher&)
//{
//	return false;
//}
//
//bool CaesarCipher::operator<(const CaesarCipher&)
//{
//	return false;
//}
//
//bool CaesarCipher::operator>(const CaesarCipher&)
//{
//	return false;
//}
//
//CaesarCipher& CaesarCipher::operator++()
//{
//	// TODO: insert return statement here
//}
//
//CaesarCipher CaesarCipher::operator++(int)
//{
//	return CaesarCipher();
//}

int CaesarCipher::getShift()
{
    unsigned int number;
    errno_t err;
	bool isSeeded = false;
    int low = 1;
    int high = OFFSET_MAX - OFFSET_MIN;

	if ( !isSeeded )
	{
        err = rand_s( &number );
        if (err != 0)
        {
            printf_s( "The rand_s function failed!\n" );
        }

        isSeeded = true;
	}

	return ( rand_s( &number ) % ( high - low )) + low;
}

string CaesarCipher::encryptDecrypt( string s, bool encrypt )
{
    // string to be returned after being built by for-each loop below.
    string processed = "";
    size_t n = s.length();
    rsize_t dest_size = n + 1;

    // Declaring character array and initializing array size.
    char* charArray = new char[n + 1];

    // copying contents of input string to character array
    strcpy_s(
        charArray, // Destination
        dest_size,
        s.c_str() // Source
    );

    for ( int i = 0; i < n; i++ ) 
    {
        int indx = charArray[i], cpos;

        if ( !isPositionInRange(indx) ) 
        {
            string message = "Index out of range. Characters are not supported. " + indx;
            message.push_back( charArray[i] );
            throw invalid_argument( message );
        }

        if ( encrypt ) 
        {
            cpos = indx + shift;
            if ( cpos > OFFSET_MAX )
            {
                cpos = OFFSET_MIN + (cpos - OFFSET_MAX);
            }
        }
        else 
        {
            cpos = indx - shift;
            if (cpos < OFFSET_MIN )
            {
                cpos = OFFSET_MAX - (OFFSET_MIN - cpos);
            }
        }

        processed.push_back( (char)cpos );
    }

    return processed;
}

bool CaesarCipher::isPositionInRange( int indx )
{
    return indx >= OFFSET_MIN && indx <= OFFSET_MAX;
}