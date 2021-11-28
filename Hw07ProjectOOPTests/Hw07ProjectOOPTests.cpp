#include "pch.h"
#include "CppUnitTest.h"
#include "..\Hw07ProjectOOP\List.h"
#include "..\Hw07ProjectOOP\Hw07ProjectOOP.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Hw07ProjectOOPTests
{
	BEGIN_TEST_MODULE_ATTRIBUTE()
		TEST_MODULE_ATTRIBUTE(L"Date", L"2021/11/28")
		END_TEST_MODULE_ATTRIBUTE()

	TEST_CLASS(Hw07ProjectOOPTests)
	{
	public:
		
		TEST_METHOD(TestAddMethodUsingIntegers)
		{
			Logger::WriteMessage("In TestAddMethod.");
			const int SIZE = 10;

			// create list of integers and doubles
			List<int> integerListResult(SIZE);

			// populate lists
			for (int i = 0; i < SIZE; i++)
			{
				integerListResult.add(i * 2);
			}

			// Test List
			List<int> integerListAssert(SIZE);
			int testArr[SIZE] = { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18 };
			
			for each (int testValue in testArr)
			{
				integerListAssert.add(testValue);
			}

			bool assert = true;
			bool results;
			int assertTotal = 0;
			int resultTotal = 0;

			for (int j = 0; j < SIZE; j++)
			{
				assertTotal += integerListAssert.get(j);
				resultTotal += integerListResult.get(j);
			}

			if (assertTotal == resultTotal)
			{
				std::cout << "Both values are equal";
				results = true;
			}
			else
			{
				std::cout << "Both values are not equal";
				results = false;
			}
			Assert::AreEqual(assert, results);
		}

		TEST_METHOD(TestAddMethodUsingDoubles)
		{
			Logger::WriteMessage("In TestAddMethodUsingDoubles.");
			const int SIZE = 10;

			// create list of integers and doubles
			List<double> doubleListResult(SIZE);

			// populate lists
			for (int i = 0; i < SIZE; i++)
			{
				doubleListResult.add(i * 2.14);
			}

			// Test List
			List<double> doubleListAssert(SIZE);
			double testArr[SIZE] = { 0, 2, 4, 6, 8, 10, 12, 14, 17, 19 };

			for each (int testValue in testArr)
			{
				doubleListAssert.add(testValue);
			}

			bool assert = true;
			bool results;
			double assertTotal = 0;
			double resultTotal = 0;

			for (int j = 0; j < SIZE; j++)
			{
				assertTotal += doubleListAssert.get(j);
				resultTotal += doubleListResult.get(j);
			}

			if (assertTotal == resultTotal)
			{
				std::cout << "Both values are equal";
				results = true;
			}
			else
			{
				std::cout << "Both values are not equal";
				results = false;
			}
			Assert::AreEqual(assert, results);
		}

		/*TEST_METHOD(TestOverloadMethod)
		{
			Logger::WriteMessage("In TestEncryptMethod. The clear text word shold match the decrypted word.");
			int countNumber = 2;

			CaesarCipher cc;
			cc.operator++(countNumber);
			int caesarCipherCount = cc.getCount();

			Assert::AreEqual(3, caesarCipherCount);
		}*/
	};
}
