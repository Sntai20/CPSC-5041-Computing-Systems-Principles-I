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
			Logger::WriteMessage("In TestEncryptMethod. The clear text word shold match the decrypted word.");
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

		TEST_METHOD(TestOverloadMethod)
		{
			Logger::WriteMessage("In TestEncryptMethod. The clear text word shold match the decrypted word.");
			int countNumber = 2;

			CaesarCipher cc;
			cc.operator++(countNumber);
			int caesarCipherCount = cc.getCount();

			Assert::AreEqual(3, caesarCipherCount);
		}

		//TEST_METHOD(TestOverloadMethod)
		//{
		//	Logger::WriteMessage("In TestEncryptMethod. The clear text word shold match the decrypted word.");
		//	//CaesarCipher::operator=();
		//	int countNumber = 2;
		//	CaesarCipher cc;
		//	cc.operator++(countNumber);
		//	int caesarCipherCount = cc.getCount();
		//	string clearTextWord = "Hello, world!";
		//	string encryptedWord;
		//	string decryptedWord;

		//	encryptedWord = cc.encrypt(clearTextWord);
		//	decryptedWord = cc.decrypt(encryptedWord);

		//	Assert::AreEqual(3, caesarCipherCount);
		//}

//		*****RUN 1: *****
//
//			test constructor : cc
//			Encrypted : , IPPSnb[SVPHc
//			Decrypted : Hello, world!
//
//			test constructor : cc2
//			Encrypted : Dahhk(zsknh`{
//				Decrypted: Hello, world!
//
//				***testing copy constructor and overloaded assignment * **
//
//				test copy constructor : cc3(cc2)
//				Encrypted : Dahhk(zsknh`{
//					Decrypted: Hello, world!
//
//					test overloaded assignment operator : cc2 = cc
//					Encrypted : , IPPSnb[SVPHc
//					Decrypted : Hello, world!
//
//					***printing cc, cc2, and cc3 * **
//
//					test constructor : cc
//					Encrypted : , IPPSnb[SVPHc
//					Decrypted : Hello, world!
//
//					test constructor : cc2
//					Encrypted : , IPPSnb[SVPHc
//					Decrypted : Hello, world!
//
//					test constructor : cc3
//					Encrypted : Dahhk(zsknh`{
//						Decrypted: Hello, world!
//
//						***testing comparators * **
//
//						test comparators
//						cc == c3 is false
//						cc < c3 is true
//						cc > c3 is false
//
//						* **testing add * **
//
//						test add : cc2 = cc + cc3
//						Encrypted : (ELLOj ^ WORLD_
//							Decrypted : Hello, world!
//
//							***testing increment * **
//
//							test increment(postfix) : cc4 = cc++
//							Encrypted : -JQQToc\TWQId
//							Decrypted : Hello, world!
//
//							result of cc4 after postfix :
//	Encrypted:, IPPSnb[SVPHc
//		Decrypted : Hello, world!
//
//		test increment(prefix) : cc4 = ++cc
//		Encrypted : .KRRUpd]UXRJe
//		Decrypted : Hello, world!
//
//		result of cc4 after prefix :
//Encrypted:.KRRUpd]UXRJe
//Decrypted : Hello, world!
//
//test increment(postfix) : cc4 = cc2++
//Encrypted : )FMMPk_XPSME`
//Decrypted: Hello, world!
//
//result of cc4 after postfix :
//Encrypted: (ELLOj ^ WORLD_
//	Decrypted : Hello, world!
//
//	test increment(prefix) : cc4 = ++cc2
//	Encrypted : *GNNQl`YQTNFa
//	Decrypted : Hello, world!
//
//	result of cc4 after prefix :
//Encrypted: *GNNQl`YQTNFa
//Decrypted : Hello, world!
//
//test increment(postfix) : cc4 = cc3++
//Encrypted : Ebiil) {
//	tloia |
//		Decrypted: Hello, world!
//
//		result of cc4 after postfix :
//Encrypted: Dahhk(zsknh`{
//	Decrypted: Hello, world!
//
//	test increment(prefix) : cc4 = ++cc3
//	Encrypted : Fcjjm * | umpjb
//}
//Decrypted: Hello, world!
//
//result of cc4 after prefix :
//Encrypted: Fcjjm* | umpjb
//	}
//Decrypted: Hello, world!
//
//----------------------------
//
//*** testing list***
//
//test list : add cc, cc2, cc3
//
//test print list[0] :
//	Encrypted : .KRRUpd]UXRJe
//	Decrypted : Hello, world!
//
//	test print list[1] :
//	Encrypted : *GNNQl`YQTNFa
//	Decrypted : Hello, world!
//
//	test print list[2] :
//	Encrypted : Fcjjm * | umpjb
//}
//Decrypted: Hello, world!
//
//
//*****RUN 2 : *****
//
//test constructor : cc
//Encrypted : Lipps0${ svph %
//Decrypted: Hello, world!
//
//test constructor : cc2
//Encrypted : i(//2MA:25/'B
//Decrypted : Hello, world!
//
//***testing copy constructor and overloaded assignment * **
//
//test copy constructor : cc3(cc2)
//Encrypted : i(//2MA:25/'B
//Decrypted : Hello, world!
//
//test overloaded assignment operator : cc2 = cc
//Encrypted : Lipps0${svph %
//Decrypted: Hello, world!
//
//***printing cc, cc2,and cc3 * **
//
//test constructor : cc
//Encrypted : Lipps0${svph %
//Decrypted: Hello, world!
//
//test constructor : cc2
//Encrypted : Lipps0${svph %
//Decrypted: Hello, world!
//
//test constructor : cc3
//Encrypted : i(//2MA:25/'B
//Decrypted : Hello, world!
//
//***testing comparators * **
//
//test comparators
//cc == c3 is false
//cc < c3 is true
//cc > c3 is false
//
//* **testing add * **
//
//test add : cc2 = cc + cc3
//Encrypted : m,336QE > 693 + F
//Decrypted : Hello, world!
//
//***testing increment * **
//
//test increment(postfix) : cc4 = cc++
//Encrypted : Mjqqt1 % | twqi &
//Decrypted : Hello, world!
//
//result of cc4 after postfix :
//Encrypted: Lipps0${svph %
//Decrypted: Hello, world!
//
//test increment(prefix) : cc4 = ++cc
//Encrypted : Nkrru2&}uxrj'
//Decrypted : Hello, world!
//
//result of cc4 after prefix :
//Encrypted: Nkrru2&}uxrj'
//Decrypted: Hello, world!
//
//test increment(postfix) : cc4 = cc2++
//Encrypted : n - 447RF ? 7 : 4,G
//Decrypted : Hello, world!
//
//result of cc4 after postfix :
//Encrypted: m,336QE > 693 + F
//Decrypted : Hello, world!
//
//test increment(prefix) : cc4 = ++cc2
//Encrypted : o.558SG@8; 5 - H
//Decrypted : Hello, world!
//
//result of cc4 after prefix :
//Encrypted: o.558SG@8; 5 - H
//Decrypted : Hello, world!
//
//test increment(postfix) : cc4 = cc3++
//Encrypted : j)003NB; 360(C
//Decrypted : Hello, world!
//
//result of cc4 after postfix :
//Encrypted: i(//2MA:25/'B
//Decrypted : Hello, world!
//
//test increment(prefix) : cc4 = ++cc3
//Encrypted : k * 114OC < 471)D
//Decrypted : Hello, world!
//
//result of cc4 after prefix :
//Encrypted: k * 114OC < 471)D
//Decrypted : Hello, world!
//
//----------------------------
//
//* **testing list * **
//
//test list : add cc, cc2, cc3
//
//test print list[0] :
//Encrypted : Nkrru2&}uxrj'
//Decrypted: Hello, world!
//
//test print list[1] :
//Encrypted : o.558SG@8; 5 - H
//Decrypted : Hello, world!
//
//test print list[2] :
//Encrypted : k * 114OC < 471)D
//Decrypted : Hello, world!
//


	};
}
