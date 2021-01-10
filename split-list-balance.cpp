
#include <iostream>
#include <vector>

using namespace std;


//This function will check if testNum is the sum of the max-sum sublist of numVector
bool is_max_sum_sublist(int testNum, vector<int> numVector, int numSublists) {
	
	int count = 1; 
	//count increments into total numbers of possible sublists
	//count = 1 because we start counting at the first sublist
	int sum = 0;
	
	for (unsigned int i = 0; i < numVector.size(); i++) {
		
		/* For testNum to be the max sum of the sublist, testNum has to be >=
		 * than each of the elements in the list because we always have some 
		 * sublists that consist of only 1 element */
		if (numVector.at(i) > testNum) {
			return false;		
		}
		
		sum += numVector.at(i);	//sum of all elements from index 0 to index i
		
		/* Assume testNum is the max sum of a sublist, each time the sum of a 
		 * sublist is < or = the value of testNum, it means the current element
		 * will belong to the next sublist so add 1 to count - which stores the 
		 * total number of sublists - and assign sum = current element to start 
		 * increment the sum of the next sublist. */
		if (sum > testNum) {
			count++; 	
			sum = numVector.at(i);
		}
	}
	
	//Now, check if count is valid by comparing it with numSublists
	if (count <= numSublists) {
		return true; 		//testNum is the sum of the maximum sublist
	} else {
		return false;		//testNum is NOT the sum of the maximum sublist
	}
} 


//Copied from my own product-digit-sum.cpp
//This function will calculate the sum of all the digits in numVector
unsigned int sum_vector(vector<int> numVector) {
	
	unsigned int result = 0;
	
	for (unsigned int i = 0; i < numVector.size(); ++i) {
		result += numVector.at(i);
	}
	
	return result;
}	


//This function will find the maximum element in numVector
int max_value(vector<int> numVector) {
	
	int maxVal = 0;
	
	for (unsigned int i = 0; i < numVector.size(); ++i) {
		if (maxVal < numVector.at(i)) {
			maxVal = numVector.at(i);
		}
	}
	
	return maxVal;
}	

//This function will return the maximum sublist sum that is minimal
int split_vec(vector<int> numVector, int numSublists) {
	
	//Notice: we choose the value of ONE largest element in vector as the floor for MAX sum
	int lowSum = max_value(numVector);
	//Notice: we choose the value of total all elements in vector as the ceiling for MAX sum
	int highSum = sum_vector(numVector);
	
	int result = 0;
	
	//Loop until the floor value touches the ceiling which means Max sum is then minimal
	while (lowSum <= highSum) {
		
		//An educational guess at the value for minMaxSum since lowSum < minMaxSum < highSum
		int minMaxSum = lowSum + (highSum - lowSum) / 2;
		
		//Call the is_max_sum_sublist() to test if current minMaxSum is valid
		if (is_max_sum_sublist(minMaxSum, numVector, numSublists)) {
			//this function is true showing that minMaxSum can be the result
			result = minMaxSum;
			
			highSum = minMaxSum - 1; 	//we try lowering the ceiling --> minimize minMaxSum 
			
		} else {
			//this function is not true showing that minMaxSum may be too small
			lowSum = minMaxSum + 1; 	//we try increasing the floor --> increase minMaxSum
			
		}
	}
	return result;
	
}


//Copied from my own product-digit-sum.cpp
//This function will take a vector & return its string representation
string vec_to_string(vector<int> numVector) {
	
	string vecString = "[";
	
	for (unsigned int i = 0; i < numVector.size()-1; ++i) {
		//to_string() turns int into string -- from <string>
		vecString += to_string(numVector.at(i)) + ", ";
	}
	
	vecString += to_string(numVector.at(numVector.size()-1)) + "]";
	
	return vecString;
}	


int main() {
	
	vector<int> digitsVector;
	digitsVector.push_back(7);
	//digitsVector.push_back(13);
	digitsVector.push_back(2);
	digitsVector.push_back(5);
	digitsVector.push_back(10);
	digitsVector.push_back(8);
	//digitsVector.push_back(3);
	
	int numSublists = 2;
	
	int result = split_vec(digitsVector, numSublists);
	
	cout << "Input vector: " << vec_to_string(digitsVector) << "      m = " << numSublists << endl;
	cout << "Result: " << result << endl;
}
