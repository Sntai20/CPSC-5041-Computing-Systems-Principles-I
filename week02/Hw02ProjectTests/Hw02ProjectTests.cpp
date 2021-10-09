#include "pch.h"
#include "CppUnitTest.h"
#include "..\Hw02Project\Hw02Project.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Hw02ProjectTests
{
	BEGIN_TEST_MODULE_ATTRIBUTE()
		TEST_MODULE_ATTRIBUTE(L"Date", L"2021/10/09")
		END_TEST_MODULE_ATTRIBUTE()

	TEST_CLASS(Hw02ProjectTests)
	{
	public:

		TEST_CLASS_INITIALIZE(ClassInitialize)
		{
			Logger::WriteMessage("In Class Initialize");
		}

		TEST_CLASS_CLEANUP(ClassCleanup)
		{
			Logger::WriteMessage("In Class Cleanup");
		}

		TEST_METHOD(TestdecimalToBinaryVectorMethod)
		{
			Logger::WriteMessage("In TestdecimalToBinaryVectorMethod\n");
			MyClass mc;
			vector<int> binaryVectorAssert = { 0, 0, 0, 0, 0, 1 };
			vector<int> binaryVectorResults = mc.decimalToBinaryVector(32);
			bool assert = true;
			bool results;

			if (binaryVectorAssert == binaryVectorResults) 
			{
				std::cout << "Both vectors are equal";
				results = true;
			}
			else 
			{
				std::cout << "Both vectors are not equal";
				results = false;
			}

			Logger::WriteMessage("Enter a decimal number : 32\n32 converted to binary is 1 0 0 0 0 0 \n");
			Assert::AreEqual(assert, results);
		}

		TEST_METHOD(TestdecimalToBinaryVectorWithZeroValueMethod)
		{
			Logger::WriteMessage("In TestdecimalToBinaryVectorWithZeroValueMethod\n");
			MyClass mc;
			vector<int> binaryVectorAssert;
			vector<int> binaryVectorResults = mc.decimalToBinaryVector(0);
			bool assert = true;
			bool results;

			if (binaryVectorAssert == binaryVectorResults)
			{
				std::cout << "Both vectors are equal";
				results = true;
			}
			else
			{
				std::cout << "Both vectors are not equal";
				results = false;
			}

			Logger::WriteMessage("Enter a decimal number : 0\n0 converted to binary is 0 \n");
			Assert::AreEqual(assert, results);
		}

		TEST_METHOD(TestdecimalToBinaryVectorWithANegativeValueMethod)
		{
			Logger::WriteMessage("In TestdecimalToBinaryVectorWithZeroValueMethod\n");
			MyClass mc;
			vector<int> binaryVectorAssert;
			vector<int> binaryVectorResults = mc.decimalToBinaryVector(-1);
			bool assert = true;
			bool results;

			if (binaryVectorAssert == binaryVectorResults)
			{
				std::cout << "Both vectors are equal";
				results = true;
			}
			else
			{
				std::cout << "Both vectors are not equal";
				results = false;
			}

			Logger::WriteMessage("Enter a decimal number : -1\n0 converted to binary is 0 \n");
			Assert::AreEqual(assert, results);
		}
	};
}
