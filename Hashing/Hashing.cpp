#include <iostream>
#include <cassert>
#include <list>
using namespace std;
//  -------------------- Task 1 ( Seperate Chaining ) --------------
class SeperateChaining
{
public:
    int tableSize;
    list<int>* hashTable;
    SeperateChaining(int size = 10)
    {
        tableSize = size;
        hashTable = new list<int>[size];
    }

    int hashFunction(int key)
    {
        return key % tableSize;
    }

    void insert(int value)
    {
        int hashValue = hashFunction(value);
        hashTable[hashValue].push_back(value);
    }

    void remove(int value)
    {
        int hashValue = hashFunction(value);
        hashTable[hashValue].remove(value);
    }

    int search(int value)
    {
        int hashValue = hashFunction(value);
        list<int>::iterator start = hashTable[hashValue].begin();
         list<int>::iterator end = hashTable[hashValue].end();
        for (typename list<int>::iterator it = start; it != end; it++)
        {
            if (*it == value)
            {
                return value;
            }
        }
        
        return INT_MIN;
    }
};

//  -------------------- Task 2 ( Linear Probing ) --------------
class LinearProbing
{
public:
    int tableSize;
    int* hashTable;
    LinearProbing(int size = 10)
    {
        tableSize = size;
        hashTable = new int[size];
        for (int i = 0; i < size; i++)
        {
            hashTable[i] = -1;
        }
    }

    int hashFunction(int key)
    {
        return key % tableSize;
    }

    void insert(int value)
    {
        int hashValue = hashFunction(value);
        while (hashTable[hashValue] != -1)
        {
            ++hashValue;
            hashValue %= tableSize;
        }
        hashTable[hashValue] = value;
    }

    void remove(int value)
    {
        int hashValue = hashFunction(value);
        while (hashTable[hashValue] != NULL)
        {
            if (hashTable[hashValue] == value)
            {
                hashTable[hashValue] = -1;
                return;
            }
            hashValue++;
            hashValue %= tableSize;
        }
    }

    int search(int value)
    {
        int hashValue = hashFunction(value);
        while (hashTable[hashValue] != -1)
        {
            if (hashTable[hashValue] == value)
            {
                return value;
            }
            hashValue++;
            hashValue %= tableSize;
        }
        return -1;
    }
};

//  -------------------- Task 3 ( Quadratic Probing ) --------------
class QuadraticProbing
{
public:
    int tableSize;
    int* hashTable;
    QuadraticProbing(int size = 10)
    {
        tableSize = size;
        hashTable = new int[size];
        for (int i = 0; i < size; i++)
        {
            hashTable[i] = -1;
        }
    }

    int hashFunction(int key)
    {
        return key % tableSize;
    }

    void insert(int value)
    {
        int hashValue = hashFunction(value);
        int originalHashValue = hashValue;
        int i = 1;
        while (hashTable[hashValue] != -1)
        {
            hashValue = (originalHashValue + (i*i)) % tableSize;
            ++i;
        }
        hashTable[hashValue] = value;
    }

    void remove(int value)
    {
        int hashValue = hashFunction(value);
        int originalHashValue = hashValue;
        int i = 1;
        while (hashTable[hashValue] != NULL)
        {
            if (hashTable[hashValue] == value)
            {
                hashTable[hashValue] = -1;
                return;
            }
            hashValue = (originalHashValue + (i * i)) % tableSize;
            ++i;
        }
    }

    int search(int value)
    {
        int hashValue = hashFunction(value);
        while (hashTable[hashValue] != -1)
        {
            if (hashTable[hashValue] == value)
            {
                return value;
            }
            hashValue++;
            hashValue %= tableSize;
        }
        return -1;
    }
};

int main() 
{
 
    return 0;
}