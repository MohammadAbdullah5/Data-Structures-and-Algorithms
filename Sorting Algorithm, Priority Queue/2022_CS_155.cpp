// Sorting Algorithm, Priority Queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <fstream>
#include <ctime>
using namespace std;
// --------- Priority Queue Example --------------
void priorityQueue()
{
	priority_queue<int> pq;
	pq.push(10);
	pq.push(30);
	pq.push(40);
	pq.push(5);
	pq.push(20);

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
}

//  ----------- Heap Sort ------------------
class Compare
{
public:
	bool operator()(int& a, int& b)
	{
		return a > b;
	}
};

template <class T>
void HeapSort(vector<T>& V)
{
	priority_queue<int, vector<int>, Compare> PQ;
	int size = V.size();
	for (int vi = 0; vi < size; vi++)
	{
		PQ.push(V[vi]);
	}
	V.clear();
	while (!PQ.empty())
	{
		V.push_back(PQ.top());
		PQ.pop();
	}
}

void heapSortMain()
{
	vector<int> v;
	v.push_back(20);
	v.push_back(5);
	v.push_back(40);
	v.push_back(10);
	v.push_back(30);
	HeapSort(v);
	cout << "Sorted Vector: ";
	int size = v.size();
	for (int i = 0; i < size; i++)
	{
		cout << v[i] << " ";
	}
}


// ----------------- Task 3 ----------------
template <class T>
bool SwappingAllThrough(vector<T>& vctr) // Task 4
{
	bool isChangeHappen = false;
	int size = vctr.size() - 1;
	for (int i = 0; i < size; i++)
	{
		if (vctr[i] > vctr[i + 1])
		{
			swap(vctr[i], vctr[i + 1]);
			isChangeHappen = true;
		}
	}
	return isChangeHappen;
}

template <class T>
void bubbleSortAlgorithm(vector<T>& vctr)
{
	while (SwappingAllThrough(vctr))
	{
		// All ok
	}
}
//Task4 end

// Task 5
template <class T>
int FindMinimumRange(vector<T>& vctr, int startingIndex, int endingIndex)
{
	int minimum = startingIndex;
	for (int i = startingIndex + 1; i <= endingIndex; i++)
	{
		if (vctr[minimum] > vctr[i])
		{
			minimum = i;
		}
	}
	return minimum;
}

template <class T>
void SelectionSortAlgorithm(vector<T>& vctr)
{
	int size = vctr.size() - 1;
	for (int i = 0; i < size; i++)
	{
		int min = FindMinimumRange(vctr, i, size);
		swap(vctr[i], vctr[min]);
	}
}
// End Task 5

// Merge Sort
template <class T>
void merge(vector<T>& vctr, int left, int mid, int right)
{
	int subArrayOne = mid - left + 1;
	int subArrayTwo = right - mid;

	vector<T> leftVector(vctr.begin() + left, vctr.begin() + left + subArrayOne);
	vector<T> rightVector(vctr.begin() + mid + 1, vctr.begin() + mid + 1 + subArrayTwo);

	int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
	int indexOfMergedArray = left;

	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
		if (leftVector[indexOfSubArrayOne] <= rightVector[indexOfSubArrayTwo]) {
			vctr[indexOfMergedArray] = leftVector[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			vctr[indexOfMergedArray] = rightVector[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}

	while (indexOfSubArrayOne < subArrayOne) {
		vctr[indexOfMergedArray] = leftVector[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}

	while (indexOfSubArrayTwo < subArrayTwo) {
		vctr[indexOfMergedArray] = rightVector[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
}

template <class T>
void mergeSort(vector<T>& vctr, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}

	int mid = begin + (end - begin) / 2;
	mergeSort(vctr, begin, mid);
	mergeSort(vctr, mid + 1, end);
	merge(vctr, begin, mid, end);
}

template <class T>
void mergeSortAlgorithm(vector<T>& vctr)
{
	if (vctr.size() == 1 || vctr.size() == 0)
	{
		return;
	}
	mergeSort(vctr, 0, vctr.size() - 1);
}

// Task 6 A
template <class T>
int partition(vector<T>& vctr, int left, int right, int partitionIndex)
{
	int pivot = vctr[partitionIndex];
	swap(vctr[partitionIndex], vctr[right]);
	int i = left - 1;

	for (int j = left; j < right; ++j)
	{
		if (vctr[j] <= pivot)
		{
			i++;
			swap(vctr[i], vctr[j]);
		}
	}

	swap(vctr[i + 1], vctr[right]);
	return i + 1;
}

template <class T>
void QuicksortRecursive(vector<T>& vctr, int startingIndex, int endingIndex)
{
	if (startingIndex >= endingIndex)
	{
		return;
	}

	int partitionI = (rand() % (endingIndex - startingIndex + 1)) + startingIndex;
	partitionI = partition(vctr, startingIndex, endingIndex, partitionI);
	QuicksortRecursive(vctr, startingIndex, partitionI - 1);
	QuicksortRecursive(vctr, partitionI + 1, endingIndex);
}

template <class T>
void quicksort(vector<T>& vctr)
{
	int size = vctr.size();
	QuicksortRecursive(vctr, 0, size - 1);
}
// End Task 6 A

void RandomizwedINit(vector<int>& Vctr)
{
	for (int i = 0; i < Vctr.size(); i++)
	{
		Vctr[i] = rand() % 100;
	}
}

void printVctr(vector<int>& Vctr)
{
	for (int i = 0; i < Vctr.size(); i++)
	{
		cout << Vctr[i] << " ";
	}
	cout << endl << endl << endl;
}

void testHeapSortMain()
{
	vector<int> valuez(20);
	RandomizwedINit(valuez);
	cout << "Before Sorting: " << endl;
	printVctr(valuez);

	//mergeSortAlgorithm(valuez);
	//HeapSort(valuez);
	//quicksort(valuez);
	cout << "After Sorting: " << endl;
	printVctr(valuez);

}

void printMenu()
{
	system("cls");
	cout << "1. Insert an element" << endl;
	cout << "2. Bubble Sort" << endl;
	cout << "3. Selection Sort" << endl;
	cout << "4. Merge Sort" << endl;
	cout << "5. Heap Sort" << endl;
	cout << "6. Quick Sort" << endl;
	cout << "7. Print Array" << endl;
}

void print(vector<int> arr)
{
	int size = arr.size();
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void createRandomFile(string fn, int Size, int RN = 100) 
{
	ofstream Writer(fn);

	for (int i = 0; i < Size * 1024; i++) {
		Writer << rand() % RN << " ";
	}

}

void LoadData(string filename, vector<int>& vctr)
{
	ifstream file(filename);
	int value;

	while (file >> value) {
		vctr.push_back(value);
	}
	file.close();
}

int main()
{
	//Task1
	/*priority_queue<int> pq;
	pq.push(20);
	pq.push(30);
	pq.push(40);
	pq.push(5);
	pq.push(10);

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}*/

	//Task2
	/*heapSortMain();*/

	/*vector<int> v;
	v.push_back(30);
	v.push_back(10);
	v.push_back(40);
	v.push_back(50);
	mergeSortAlgorithm(v);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}*/

	//testHeapSortMain();

	/*vector<int> vctr;
	string option;
	while (true)
	{
		system("cls");
		printMenu();
		cin >> option;

		if (option == "1")
		{
			int value;
			cin >> value;
			vctr.push_back(value);
		}

		else if (option == "2")
		{
			bubbleSortAlgorithm(vctr);
		}

		else if (option == "3")
		{
			SelectionSortAlgorithm(vctr);
		}

		else if (option == "4")
		{
			mergeSortAlgorithm(vctr);
		}

		else if (option == "5")
		{
			HeapSort(vctr);
		}

		else if (option == "6")
		{
			quicksort(vctr);
		}

		else if (option == "7")
		{
			print(vctr);
		}

		else if (option == "8")
		{
			break;
		}
	}*/

	vector<int> vctr;
	createRandomFile("file.txt", 100);
	cout << "Before Loading: " << time(0) << endl;
	LoadData("file.txt", vctr);
	cout << "After Loading: " << time(0) << endl;
	HeapSort(vctr);
	cout << "After applying Heap Sort: " << time(0) << endl;
 }

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
