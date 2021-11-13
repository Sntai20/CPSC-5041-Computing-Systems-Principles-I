#include "pch.h"
#include "CppUnitTest.h"
#include "..\Hw04Project\Hw04Project.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Hw04ProjectTests
{
	BEGIN_TEST_MODULE_ATTRIBUTE()
		TEST_MODULE_ATTRIBUTE(L"Date", L"2021/11/13")
		END_TEST_MODULE_ATTRIBUTE()

	TEST_CLASS(Hw04ProjectTests)
	{
	public:
		
		TEST_METHOD(TestIsValidUserInputEqualToOne)
		{
			Logger::WriteMessage("In TestIsValidMethod. One is valid");
			float userInput = 1;

			bool valid = isValid(userInput);
			
			Assert::IsTrue(valid);
		}

		TEST_METHOD(TestIsValidUserInputEqualToNegativeOne)
		{
			Logger::WriteMessage("in testisvalidmethod. negative one is not valid");
			float userinput = -1;

			bool notvalid = isValid(userinput);

			Assert::IsFalse(notvalid);
		}

		TEST_METHOD(TestIsValidUserInputEqualToOneHundred)
		{
			Logger::WriteMessage("in testisvalidmethod. one hundred is valid");
		
			float userinput = 100;

			bool valid = isValid(userinput);

			Assert::IsTrue(valid);
		}

		TEST_METHOD(TestIsValidUserInputEqualToOneHundredAndOne)
		{
			Logger::WriteMessage("In TestIsValidMethod. One hundred and one is not valid");
			float userInput = 101;

			bool notValid = isValid(userInput);

			Assert::IsFalse(notValid);
		}/*

		TEST_METHOD(TestAddScoreMethod)
		{
			Logger::WriteMessage("In TestAddScoreMethod");
			vector<int> vectorAssert = { 90 };

			MyClass mc;
			mc.addScore(90);
			vector<int> vectorResults = mc.getStudentScores();
			bool assert = true;
			bool results;

			if (vectorAssert == vectorResults)
			{
				std::cout << "Both vectors are equal";
				results = true;
			}
			else
			{
				std::cout << "Both vectors are not equal";
				results = false;
			}

			Logger::WriteMessage("Add a score to the vector.");
			Assert::AreEqual(assert, results);

			
		}*/
	};
}
