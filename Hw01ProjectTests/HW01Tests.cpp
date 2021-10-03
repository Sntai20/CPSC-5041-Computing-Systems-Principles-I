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
			Logger::WriteMessage("In TestPowerMethod");
			MyClass::power(2, 3);
			Assert::AreEqual("2","2");
		}

		TEST_METHOD(TestMyLogMethod)
		{
			Logger::WriteMessage("In TestMyLogMethod");
			MyClass::myLog(2, 3);
			Assert::AreEqual("2", "2");
		}
	};
}
