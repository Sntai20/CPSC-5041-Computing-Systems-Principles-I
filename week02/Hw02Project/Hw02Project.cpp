// Hw02Project.cpp : This file contains the 'main' function.
// C++ program to convert a decimal
// number to binary number

#include <iostream>
#include <vector>

using namespace std;

// Class used to test functions.
class MyClass
{
public:
	static std::vector<int> decimalToBinaryVector(int number)
	{
		// vector to store a binary number
		std::vector<int> binaryVector;

		while (number > 0)
		{
			// storing remainder in binary vector
			binaryVector.push_back(number % 2);
			number = number / 2;
		}
		return binaryVector;
	}

	static void printVector(std::vector<int> binaryVector)
	{	
		vector <int>::reverse_iterator rvIter;
		for (rvIter = binaryVector.rbegin(); rvIter != binaryVector.rend(); rvIter++)
			cout << *rvIter << " ";
	}

	static bool isValid(int number)
	{
		if (!(number >= 0) )
		{
			cout << "Please enter a valid number, that is greater than or equal to zero.";
			return false;
		}
		return true;
	}
};


//  Program execution begins and ends there.
int main()
{
	MyClass mc;
	cout << "Please enter a decimal number to convert to binary: ";
	int userInput; 
	cin >> userInput;

	if (mc.isValid(userInput))
	{
		int number = userInput;
		vector<int> binary = mc.decimalToBinaryVector(number);

		// Display the results.
		cout << "The binary number is: ( ";
		mc.printVector(binary);
		cout << ")." << endl;
	}

	return 0;
}