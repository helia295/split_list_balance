
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>


using namespace std;

//This recursive function will calculate base^exp and return the result
unsigned long long pow(long long base, long long exp) {
	
	if (base < 0) {
		cout << "Invalid base! Only take positive integer." << endl;
		exit(1);
	}
	
	if (exp == 0) { 	//base case 1
		return 1;
		
	} else if (exp == 1) { 		//base case 2
		return base;
		
	} else if (exp > 1) { 		//recursion
		return (base * pow(base, exp - 1));
		
	} else { 	//if exp < 0
		cout << "Invalid exponent! Only take positive integer." << endl;
		exit(1);
	}	
}	

//This function will take a single number & create a vector of the digits in that number.
vector<int> vectorize_digits(unsigned long long num) {
	
	vector<int> digitsVector;
	
	while (num != 0) {
		digitsVector.push_back(num % 10);	//modulus 10 will get the last digit of the number
		num /= 10;	//integer division will eliminate everything after the decimal point
	}	
	
	//reverse() will return the reversed vector -- from <algorithm>
	//begin() will return an iterator pointing to the first element -- from <vector>
	//end() will return an iterator pointing to the theoretical element that follows the last element
	reverse(digitsVector.begin(), digitsVector.end());
	
	return digitsVector;
}	

//This function will calculate the sum of all the digits in numVector
unsigned int sum_vector(vector<int> numVector) {
	
	unsigned int result = 0;
	
	for (int i = 0; i < numVector.size(); ++i) {
		result += numVector.at(i);
	}
	
	return result;
}	

//This function will take a vector & return its string representation
string vec_to_string(vector<int> numVector) {
	
	string vecString = "[";
	
	for (int i = 0; i < numVector.size()-1; ++i) {
		//to_string() turns int into string -- from <string>
		vecString += to_string(numVector.at(i)) + ", ";
	}
	
	vecString += to_string(numVector.at(numVector.size()-1)) + "]";
	
	return vecString;
}	

//This function runs fully automated tests (using assertstatements) for all functions
void tests() {
	
	//tests for pow()
	assert(pow(2, 16) == 65536);
	assert(pow(9, 9) == 387420489);
	assert(pow(9, 0) == 1);
	
	//tests for vectorize_digits()
	assert(vectorize_digits(387420489) == vectorize_digits(pow(9, 9)));
	assert(vectorize_digits(65536) == vectorize_digits(pow(2, 16)));
	assert(vectorize_digits(1) == vectorize_digits(pow(9, 0)));
	
	//tests for vec_to_string()
	assert(vec_to_string(vectorize_digits(387420489)) == "[3, 8, 7, 4, 2, 0, 4, 8, 9]");
	assert(vec_to_string(vectorize_digits(35937)) == "[3, 5, 9, 3, 7]");
	assert(vec_to_string(vectorize_digits(1)) == "[1]");
	
	//tests for sum_vector()
	assert(sum_vector(vectorize_digits(pow(0, 9))) == 0);
	assert(sum_vector(vectorize_digits(pow(33, 3))) == 27);
	assert(sum_vector(vectorize_digits(pow(9, 9))) == 45);
	
	cout << "ALL TESTS PASSED" << endl;
}	

int main() {
	
	long long base;
	long long exp;
	vector<int> digitsVector;
	unsigned long long power;
	unsigned int sumDigits;
	
	
	cout << "base: ";
	cin >> base;
	cout << "exponent: ";
	cin >> exp;
	
	power = pow(base, exp);
	digitsVector = vectorize_digits(power);
	sumDigits = sum_vector(digitsVector);
	
	cout << base << "^" << exp << " = " << power << endl;
	cout << vec_to_string(digitsVector) << endl;
	cout << "Sum of Digits: " << sumDigits << endl;
	
	return 0;
}
