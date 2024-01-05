// 2022_CS_155.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
using namespace std;

//Question 1 Part I
int sumOf1234N(int n) { 
	if (n == 0)
	{
		return 0;
	}

	return n + sumOf1234N(n - 1);
} // The series for this function will be 1 + 2 + ... + N. 
  // So, This function will be called n times so its time complexity is O(n)

//Question 1 Part II
int sumOf1357N(int n) {
	if (n == 0)
	{
		return 0;
	}

	return n + sumOf1234N(n - 2);
} // The series for this function will be 1 + 3 + 5 +... + N. 
  // So, This function will be called n times so its time complexity is O(n)

//Question 1 Part III
int sumOfSquares1234(int n) {
	if (n == 0)
	{
		return 1;
	}

	return pow(2, n) + sumOfSquares1234(n - 1);
} 
  // This function will be called n times so its time complexity is O(n)

//Question 1 Part IV
int sumOfCubes1234(int n) {
	if (n == 0)
	{
		return 1;
	}

	return pow(3, n) + sumOfCubes1234(n - 1);
}
// This function will be called n times so its time complexity is O(n)

//Question 1 Part V
int gSumOfCubes1234Div3(int n) {
	if (n == 0)
	{
		return 1;
	}

	return pow(3, n) + gSumOfCubes1234Div3(n / 3);
}
// This n will be divided by 3 each time so, its time complexity is O(log base3 n)

//Question 1 Part VI
int gSumOfCubes1234Div2(int n) {
	if (n == 0)
	{
		return 1;
	}

	return pow(2, n) + gSumOfCubes1234Div3(n / 2);
}
// This n will be divided by 2 each time so, its complexity is O(log base2 n)

// Question 2 Part I
int DtoB(int n) {
	if (n == 0)
	{
		return 0;
	}

	return DtoB(n / 2) * 10 + n % 2;
}

// Question 2 Part II
string i2S(int n) {
	if (n / 10 == 0)
	{
		return to_string(n);
	}
	return to_string(n / 10) + to_string(n % 10);
}

// Question 2 Part III
int gCD(int dividend, int divisor) {
	if (dividend % divisor == 0)
	{
		return divisor;
	}
	return gCD(divisor, dividend % divisor);
}

// Question 3 Part I
int SFE(vector<int> arr, int searchKey, int size, int currIn = 0) {
	if (currIn == size) 
	{
		return -1;
	}
	else if (arr[currIn] == searchKey)
	{
		return currIn;
	}
	return SFE(arr, searchKey, size, currIn + 1);
}

// Question 3 Part II
int SLE(vector<int> arr, int searchKey, int size, int currIn) { // currIn will be size - 1 of the vector
	if (currIn == -1)
	{
		return -1;
	}
	else if (arr[currIn] == searchKey)
	{
		return currIn;
	}
	return SLE(arr, searchKey, size, currIn - 1);
}

// Question 3 Part III
int BSA(int arr[], int lowerBound, int upperBound, int searchKey) { 
	int mid = (lowerBound + upperBound) / 2;

	if (arr[mid] == searchKey)
	{
		return arr[mid];
	}

	if (lowerBound >= upperBound) // Not Found
	{
		return -1; 
	}
	else
	{
		if (searchKey > arr[mid])
		{
			return BSA(arr, mid + 1, upperBound, searchKey);
		}

		else
		{
			return BSA(arr, lowerBound, mid - 1, searchKey);
		}
	}
}

//Question 4 Part I X^Y % M O(Y)
int XPowerYOrderOfY(int X, int Y) {
	if (Y == 1)
	{
		return X;
	}

	return X * XPowerYOrderOfY(X, Y - 1);
}

int PowerModYOrderOfY(int X, int Y, int M) {
	return XPowerYOrderOfY(X, Y) % M;
}

//Question 4 Part II X^Y % M O(log Y)
int XPowerYOrderOfLogY(int X, int Y) {
	if (Y == 1)
	{
		return X;
	}

	else if (Y % 2 == 1)
	{
		return X * pow(pow(X, Y / 2), 2);
	}

	else if (Y % 2 == 0)
	{
		return pow(pow(X, Y / 2), 2);
	}
}

int PowerModYOrderOfLogY(int X, int Y, int M) {
	return XPowerYOrderOfLogY(X, Y) % M;
}

// Question 5 Part I
int Add(int X, int Y) {
	return X + Y;
}

int Multiply(int A, int B) {
	if (A == 0 || B == 0) {
		return 0;
	}

	return Add(A, Multiply(A, B - 1));
}

// Question 5 Part II
int multiplyWithLog2(int A, int B) {
	int result = A + A;
	if (A == 0 || B == 0)
	{
		return 0;
	}

	else if (B % 2 == 1)
	{
		return Add(A, multiplyWithLog2(A, B - 1));
	}

	else if (B % 2 == 0)
	{
		return multiplyWithLog2(result, B / 2);
	}
}

// Question 5 Part III
int memoizationForMultiply(int A, int B, vector<vector<int>>& series) {
	if (A == 0 || B == 0)
	{
		return 0;
	}

	else if (series[A][B] != -1) {
		return series[A][B];
	}
	return series[A][B] = A + memoizationForMultiply(A, B - 1, series);
}

int memoMultiplication(int A, int B) {
	vector<vector<int>> series(A + 1, vector<int>(B + 1, -1));
	return memoizationForMultiply(A, B, series);
}

// Question 6 Part I
int recursiveDivision(int A, int B) {
	if (A - B <= 0)
	{
		return 0;
	}
	return 1 + recursiveDivision(A - B, B);
}

int recursiveModulo(int A, int B) {
	if (B == 0)
	{
		return 0;
	}

	else if (A - B == 0) {
		return 1;
	}
	else if (A < B)
	{
		return A;
	}
	return recursiveModulo(A - B, B);
}

// Question 6 Part II
int recursiveDivisionLog2Y(int A, int B) {
	if (B > A)
	{
		return 0;
	}
	return 1 + recursiveDivisionLog2Y(A - B, B);
}

int recursiveModuloLog2Y(int A, int B) {
	if (B == 0)
	{
		return 0;
	}

	else if (A < B)
	{
		return A;
	}
	return recursiveModulo(A - B, B);
}

// Question 6 Part III
int recursiveDivisionMemo(int A, int B, vector<int>& memoVector) {
	if (A - B < 0) {
		return 0;
	}

	else if (A - B == 0) 
	{
		return 1;
	}

	if (memoVector[A] != -1) {
		return memoVector[A];
	}

	return memoVector[A] = 1 + recursiveDivisionMemo(A - B, B, memoVector);
}

int divisionUsingMemoization(int A, int B) {
	vector<int> memoVector(A + 1, -1);
	return recursiveDivisionMemo(A, B, memoVector);
}

// Question 7 Part I
int fibonacciByLoop(int n) {
	int result = 1;
	int first = 0, second = 1;
	for (int i = 2; i <= n; i++) 
	{
		result = first + second;
		first = second;
		second = result;
	}
	return result;
}

int fibonacciByRecursion(int n) {
	if (n == 0 || n == 1)
	{
		return n;
	}
	return fibonacciByRecursion(n -1) + fibonacciByRecursion(n - 2);
}

// Question 7 Part II
int fibonacci(int n, vector<int>& series) {
	if (n == 0 || n == 1) {
		return n;
	}

	else if (series[n] != -1) {
		return series[n];
	}
	return series[n] = fibonacci(n - 1, series) + fibonacci(n - 2, series);
}

int fibonacciWithMemoization(int n) {
	vector<int> series(n + 1, -1);
	series[0] = 0;
	series[1] = 1;
	return fibonacci(n, series);
}

// Question 7 Part III
int bottomUpFibonacci(int n) {
	if (n == 1 || n == 0) {
		return n;
	}
	vector<int> series(n + 1, - 1);
	series[0] = 0;
	series[1] = 1;

	for (int i = 2; i <= n; i++) {
		series[i] = series[i - 1] + series[i - 2];
	}
	return series[n];
}

// Question 8 Part I
/*
	Formula : if n = 0 , 1 , 2 or 3 return n
	otherwise return the sum of n - 1 n - 2 n n - 3
*/

// Question 8 Part II
int triSum(int n) {
	if (n == 0 || n == 1 || n == 2 || n == 3) 
	{
		return n;
	}

	return triSum(n - 1) + triSum(n - 2) + triSum(n - 3);
}

// Question 8 Part III
/*
	Its time complexity will be O(3^N) because after every call there are three functions 
	called at each of them
*/

// Question 8 Part IV
int triSumMemoizaton(int n, vector<int>& series) {
	if (n == 0 || n == 1 || n == 2 || n == 3)
	{
		return n;
	}

	else if (series[n] != -1) 
	{
		return series[n];
	}

	return series[n] = triSumMemoizaton(n - 1, series) + triSumMemoizaton(n - 2, series) + triSumMemoizaton(n - 3, series);
}

int trisumByMemoization(int n) {
	vector<int> series(n + 1, -1);
	return triSumMemoizaton(n, series);
}

// Question 8 Part V
int triSumBottomUp(int n) {
	if (n < 4)
	{
		return n;
	}

	vector<int> series(n + 1);
	series[0] = 0;
	series[1] = 1;
	series[2] = 2;
	series[3] = 3;

	for (int i = 4; i <= n; i++) {
		series[i] = series[i - 1] + series[i - 2] + series[i - 3];
	}
	return series[n];
}

// Challenge 1
void generateSubArr(vector<int> arr, vector<int>& current, vector<vector<int>>& result, int idx) {
	if (idx == arr.size())
	{
		result.push_back(current);
		return;
	}

	current.push_back(arr[idx]);
	generateSubArr(arr, current, result, idx + 1);

	current.pop_back();
	generateSubArr(arr, current, result, idx + 1);
}

vector<vector<int>> AllSubarrays(vector<int> arr) {
	vector<vector<int>> result;
	vector<int> current;
	generateSubArr(arr, current, result, 0);
	return result;
}

// Challenge 2
void insertElement(stack<int>& stackToSort, int insertionElement) {
	if (stackToSort.empty() || stackToSort.top() < insertionElement)
	{
		stackToSort.push(insertionElement);
		return;
	}

	int newElement = stackToSort.top();
	stackToSort.pop();
	insertElement(stackToSort, insertionElement);

	stackToSort.push(newElement);
}

void sortStack(stack<int>& inputStack) {
	if (!inputStack.empty()) {
		int element = inputStack.top();
		inputStack.pop();

		sortStack(inputStack);

		insertElement(inputStack, element);
	}
}



int main()
{
	stack<int> st;
	st.push(12);
	st.push(40);
	st.push(3);
	st.push(20);
	sortStack(st);
	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}

	return 0;
}
