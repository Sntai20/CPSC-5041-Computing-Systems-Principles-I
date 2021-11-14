// Remembering to define _CRT_RAND_S prior
// to inclusion statement.
//#define _CRT_RAND_S

#include <stdlib.h>
#include "pch.h"
#include "CppUnitTest.h"
#include "..\Hw06ProjectOOP\CaesarCipher.h"
#include "..\Hw06ProjectOOP\CaesarCipher.cpp"
#include "..\Hw06ProjectOOP\Hw06ProjectOOP.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Hw06ProjectOOPTests
{
	BEGIN_TEST_MODULE_ATTRIBUTE()
		TEST_MODULE_ATTRIBUTE(L"Date", L"2021/11/13")
		END_TEST_MODULE_ATTRIBUTE()

	TEST_CLASS(Hw06ProjectOOPTests)
	{
	public:
		
		TEST_METHOD(TestEncryptMethod)
		{
			CaesarCipher cc;
			string clearTextWord = "Hello, world!";
			string encryptedWord;
			string decryptedWord;

			encryptedWord = cc.encrypt(clearTextWord);
			decryptedWord = cc.decrypt(encryptedWord);

			Assert::AreEqual(clearTextWord, decryptedWord);		
		}

		TEST_METHOD(TestIsPositionInRangeMethod)
		{
			Logger::WriteMessage("In TestIsPositionInRangeMethod. The clearTextWord is not valid. The backslash n is read as a new line.");
			string clearTextWord = "Hello, world!\n\\";
			string encryptedWord;
			string decryptedWord;
			string message = "Microsoft C++ exception: std::invalid_argument";
			string message2;

			try
			{
				CaesarCipher cc;
				encryptedWord = cc.encrypt(clearTextWord);
				decryptedWord = cc.decrypt(encryptedWord);
			}
			catch (const std::exception&)
			{
				message2 = "Microsoft C++ exception: std::invalid_argument";
			}

			Assert::AreEqual(message2, message);			
		}

	};
}
