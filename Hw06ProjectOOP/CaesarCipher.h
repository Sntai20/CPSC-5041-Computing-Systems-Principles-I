/* Antonio Santana
* CaesarCipher.h : This file contains the CaesarCipher class.
* Purpose: Specification file for the CaesarCipher class.
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
#pragma once

#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H

#include <string>
using namespace std;

class CaesarCipher {
public:
    CaesarCipher();
    CaesarCipher(const CaesarCipher&);
    string encrypt(string);
    string decrypt(string);
    CaesarCipher& operator = (const CaesarCipher&);
    CaesarCipher operator + (const CaesarCipher&);
    bool operator == (const CaesarCipher&);
    bool operator < (const CaesarCipher&);
    bool operator > (const CaesarCipher&);
    CaesarCipher& operator ++ ();
    CaesarCipher operator ++ (int);
    
private:
    int shift;
    const int OFFSET_MIN = 32;
    const int OFFSET_MAX = 126;
    int getShift();
    string encryptDecrypt(string, bool);
    bool isPositionInRange(int);
    static bool isSeeded;
    const int MAX_SHIFT = OFFSET_MAX - OFFSET_MIN;
};

#endif