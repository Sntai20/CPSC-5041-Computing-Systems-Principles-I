/* Antonio Santana
* Hw04Project.cpp : This file contains the 'main' function.
* Purpose: C++ program to sort and calculate the average student's score. 
* Input: 
* Output:
* 
* Requirements:
*	Enter name-score pairs, sort the scores in acending order and calculate the average
*	Dynamically allocate an array large enough to hold a user-defined number of the test score
*	Dynamically allocate an array to hold the student names.
*	For each student, the user types the student's name followed by the student's integer test score.
*	To sort the scores in ascending order, pass the names and scores arrays to a sort function.
*	Calculate the average score (format: two digits of precision to the right of the decimal point).
*	Ouput should be aligned
*	Input validation: Do not accept negative numbers or greater than 100.
*	You can use string as the data type 
*/

#include <string>
#include <iostream>
#include <vector>

using namespace std;

//class MyClass
//{
//public:
//	MyClass();
//	~MyClass();
//
//	// Input validation: Do not accept negative numbers or greater than 100.
//	static bool isValid(float number);
//
//	// method to print an array. Accepts a pointer to the array and the size of the array as input parameters.
//	void populateArrays(string* studentNameArray, float* studentScoreArray, int numberOfTestScores);
//
//	// method to print an array. Accepts a pointer to the array and the size of the array as input parameters.
//	void printArrays(string* studentNameArray, float* studentScoreArray, int numberOfTestScores);
//
//	// method to print an array. Accepts a pointer to the array and the size of the array as input parameters.
//	void sortArrays(string* studentNameArray, float* studentScoreArray, int numberOfTestScores);
//
//private:
//
//};
//
//MyClass::MyClass()
//{
//	// Initializing array size and initializing all values to numberOfTestScores.
//	string* studentNameArray = new string[numberOfTestScores];
//	float* studentScoreArray = new float[numberOfTestScores];
//}
//
//MyClass::~MyClass()
//{
//}

/* Function: isValid
	Purpose: Input validation. Do not accept negative numbers or greater than 100.
	Parameters: The test score number as a float.
	Returns: 0 if the exp is false; 1 if exp is true .*/
bool isValid(float number)
{
	if (!(number >= 0) || !(number <= 100))
	{
		cout << "Please enter a valid number, that is between 0 through 100.";
		return false;
	}
	return true;
}

// method to print an array. Accepts a pointer to the array and the size of the array as input parameters.
void populateArrays(string* studentNameArray, float* studentScoreArray, int numberOfTestScores)
{
	std::string studentName;
	float studentTestScore = 0;

	for (size_t i = 0; i < numberOfTestScores; i++)
	{
		cout << "Enter student " << i << "'s last name: ";
		cin >> studentName;

		cout << "Enter that student's test score: ";
		cin >> studentTestScore;

		if (isValid(studentTestScore))
		{
			studentNameArray[i] = studentName;
			studentScoreArray[i] = studentTestScore;
		}
	}
}

// method to print an array. Accepts a pointer to the array and the size of the array as input parameters.
void printArrays(string* studentNameArray, float* studentScoreArray, int numberOfTestScores)
{
	for (size_t i = 0; i < numberOfTestScores; i++)
	{
		// Display results
		cout << "Name: " << studentNameArray[i] << " " << studentScoreArray[i] << endl;
	}
}

// method to print an array. Accepts a pointer to the array and the size of the array as input parameters.
void sortArrays(string* studentNameArray, float* studentScoreArray, int numberOfTestScores)
{
	std::string studentName;
	float studentTestScore = 0;

	for (size_t i = 0; i < numberOfTestScores; i++)
	{

		if (studentScoreArray[i] > studentScoreArray[i + 1])
		{
			studentNameArray[i];
			studentScoreArray[i];
		}
	}
}

// Method to sort array in linear time. Accepts pointer to array data and the size of the array as input parameters.
//void countingSort(int* data, int size)
//{
//	int* output = new int[size + 1];
//
//	int minRange = 1;
//	int maxRange = 1000;
//	// Iterate over the array contents to set minRange and maxRange to the minimum and maximum values
//	for (int i = 0; i < size; i++)
//	{
//		minRange = std::min(minRange, data[i]);
//		maxRange = std::max(maxRange, data[i]);
//	}
//	int range = maxRange - minRange + 1;
//	// Initializing array counts of size range and initializing all values to 0.
//	int* counts = new int[range];
//	for (int i = 0; i < range; i++)
//	{
//		counts[i] = 0;
//	}
//	// Store count of each element in the data array.
//	for (int i = 0; i < size; i++)
//	{
//		counts[data[i] - minRange]++;
//	}
//	// Change count[i] so that count[i] now contains actual position of this integer in the output array.
//	for (int i = 1; i < range; i++)
//	{
//		counts[i] += counts[i - 1];
//	}
//	// Build output integer array
//	for (int i = size - 1; i >= 0; i--)
//	{
//		output[counts[data[i] - minRange] - 1] = data[i];
//		counts[data[i] - minRange]--;
//	}
//	// Copy the output array to array data
//	for (int i = 0; i < size; i++)
//	{
//		data[i] = output[i];
//	}
//	delete[] output;
//	delete[] counts;
//}

//  Program execution begins and ends there.
int main()
{
	int numberOfTestScores = 0;
	cout << "How many test scores will you enter? ";
	cin >> numberOfTestScores;

	// Initializing array size and initializing all values to numberOfTestScores.
	string* studentNameArray = new string[numberOfTestScores];
	float* studentScoreArray = new float[numberOfTestScores];

	populateArrays(studentNameArray, studentScoreArray, numberOfTestScores);

	printArrays(studentNameArray, studentScoreArray, numberOfTestScores);

	sortArrays(studentNameArray, studentScoreArray, numberOfTestScores);

	delete[] studentNameArray;
	delete[] studentScoreArray;

	return 0;
}