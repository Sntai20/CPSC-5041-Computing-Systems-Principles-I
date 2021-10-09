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
	static std::vector<int> decimalToBinaryVector(int n)
	{
		// vector to store a binary number
		std::vector<int> binaryVector;

		while (n > 0)
		{
			// storing remainder in binary vector
			binaryVector.push_back(n % 2);
			n = n / 2;
		}
		return binaryVector;
	}

	static void printVector(std::vector<int> binaryVector)
	{	
		vector <int>::reverse_iterator rvIter;
		for (rvIter = binaryVector.rbegin(); rvIter != binaryVector.rend(); rvIter++)
			cout << *rvIter << " ";
	}
};


//  Program execution begins and ends there.
int main()
{
	int number = 2048;
	MyClass mc;
	cout << "Please enter a decimal number to convert to binary: ";
	vector<int> binary = mc.decimalToBinaryVector(number);
	
	// Display the results.
	cout << "The binary number is: ( ";
	mc.printVector(binary);
	cout << ")." << endl;

	return 0;
}