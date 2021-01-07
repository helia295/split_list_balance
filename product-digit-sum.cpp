
#include <iostream>

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

//This function will calculate the sum of all the digits in num
unsigned long long sum(unsigned long long num) {
	
	unsigned long long result = 0;
	
	while (num != 0) {
		result += num % 10;	//modulus 10 will get the last digit of the number
		num /= 10;	//integer division will eliminate everything after the decimal point
	}	
	
	return result;
}	

int main() {
	
	long long base;
	long long exp;
	unsigned long long power;
	unsigned long long sumDigits;
	
	cout << "base: ";
	cin >> base;
	cout << "exponent: ";
	cin >> exp;
	
	power = pow(base, exp);
	sumDigits = sum(power);
	
	cout << base << "^" << exp << " = " << power << endl;
	cout << "Sum of Digits: " << sumDigits << endl;
	
	return 0;
}
