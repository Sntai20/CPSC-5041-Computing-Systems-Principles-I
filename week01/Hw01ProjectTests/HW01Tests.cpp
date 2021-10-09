#include "pch.h"
#include "CppUnitTest.h"
#include "../Hw01Project/HW1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MyClassTest
{
	BEGIN_TEST_MODULE_ATTRIBUTE()
		TEST_MODULE_ATTRIBUTE(L"Date", L"2021/10/03")
		END_TEST_MODULE_ATTRIBUTE()

	TEST_CLASS(MyClassTest)
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

		TEST_METHOD(TestPowerMethod)
		{
			Logger::WriteMessage("In TestPowerMethod\n");
			int results = MyClass::power(2, 3);
			Assert::AreEqual(8, results);
			Logger::WriteMessage("Enter a base : 2\nEnter an exponent : 3\n2 to the 3 is 8\n");
		}

		TEST_METHOD(TestNegativePowerMethod)
		{
			Logger::WriteMessage("In TestNegativePowerMethod\n");
			int results = MyClass::power(2, -3);
			Assert::AreEqual(0, results);
			Logger::WriteMessage("Enter a base : 2\nEnter an exponent : 10\n2 to the -3 is 0\n");
		}

		TEST_METHOD(TestZeroPowerMethod)
		{
			Logger::WriteMessage("In TestZeroPowerMethod\n");
			int results = MyClass::power(2, 0);
			Assert::AreEqual(1, results);
			Logger::WriteMessage("Enter a base : 2\nEnter an exponent : 0\n2 to the 0 is 1\n");
		}

		TEST_METHOD(TestMyLogMethod)
		{
			Logger::WriteMessage("In TestMyLogMethod\n");
			int results = MyClass::myLog(5, 777);
			Assert::AreEqual(4, results);
			Logger::WriteMessage("Enter a base : 5\nEnter an exponent : 777\n2 to the 10 is 1024\n");
		}
	};
}