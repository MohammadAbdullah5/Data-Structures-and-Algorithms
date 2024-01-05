#include <iostream>
#include <fstream>
#include <ctime>  
using namespace std;

template <typename T>
class AutoGrowingArray {
private:
    T* data;        
    int size;        
    int capacity;     

public:
    AutoGrowingArray() {
        size = 0;
        capacity = 1;
        data = new T[capacity];
    }


    ~AutoGrowingArray() {
        delete[] data;
    }

 
    T operator[](int index) const {
        if (index < 0 || index >= size) {
            cout << "Index out of bounds";
        }
        return data[index];
    }


    T& operator[](int index) {
        if (index < 0 || index >= size) {         
		   cout << "Index out of bounds";
        }
        return data[index];
    }

    friend std::ostream& operator<<(std::ostream& out, const AutoGrowingArray& other) {
        for (int i = 0; i < other.size; i++) {
            out << other.data[i] << ' ';
        }
        return out;
    }

    void Pushback(T value) {
        if (size == capacity) {
            capacity += 1;
            T* newData = new T[capacity];
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        data[size++] = value;
    }
    
    int Size(){
    	return size;
	}
	
	void createRandomFile(string fn, int Size, int RN = 100) {
    ofstream Writer(fn);

    for (int i = 0; i < Size * 1024 * 1024; i++) {
        Writer << rand() % RN << " ";
    }
}

void LoadData(string filename){
	ifstream file(filename);
	int value;
	
	while(file>>value){
		Pushback(value);
	}
	file.close();
}
};

template <typename T>
class Vector {
private:
    T* data;         
    int size;        
    int capacity;     

public:
    Vector() {
        size = 0;
        capacity = 1;
        data = new T[capacity];
    }


    ~Vector() {
        delete[] data;
    }

 
    T operator[](int index) const {
        if (index < 0 || index >= size) {
            cout << "Index out of bounds";
        }
        return data[index];
    }


    T& operator[](int index) {
        if (index < 0 || index >= size) {         
		   cout << "Index out of bounds";
        }
        return data[index];
    }

    friend std::ostream& operator<<(std::ostream& out, const Vector& other) {
        for (int i = 0; i < other.size; i++) {
            out << other.data[i] << ' ';
        }
        return out;
    }

    void Pushback(T value) {
        if (size == capacity) {
            capacity *= 2;
            T* newData = new T[capacity];
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        data[size++] = value;
    }
    
    int Size(){
    	return size;
	}
	
	void createRandomFile(string fn, int Size, int RN = 100) {
    ofstream Writer(fn);

    for (int i = 0; i < Size * 1024 * 1024; i++) {
        Writer << rand() % RN << " ";
    }
}

void LoadData(string filename){
	ifstream file(filename);
	int value;
	
	while(file>>value){
		Pushback(value);
	}
	file.close();
}
};

template <typename T>
class ArrayList {
private:
    T* data;         
    int size;        
    int capacity;     

public:
    ArrayList() {
        size = 0;
        capacity = 1;
        data = new T[capacity];
    }


    ~ArrayList() {
        delete[] data;
    }

 
    T operator[](int index) const {
        if (index < 0 || index >= size) {
            cout << "Index out of bounds";
        }
        return data[index];
    }


    T& operator[](int index) {
        if (index < 0 || index >= size) {         
		   cout << "Index out of bounds";
        }
        return data[index];
    }

    friend std::ostream& operator<<(std::ostream& out, const ArrayList& other) {
        for (int i = 0; i < other.size; i++) {
            out << other.data[i] << ' ';
        }
        return out;
    }

    void Pushback(T value) {
        if (size == capacity) {
            capacity = (int) capacity * 1.5;
            T* newData = new T[capacity];
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        data[size++] = value;
    }
    
    int Size(){
    	return size;
	}
	
	void createRandomFile(string fn, int Size, int RN = 100) {
    ofstream Writer(fn);

    for (int i = 0; i < Size * 1024 * 1024; i++) {
        Writer << rand() % RN << " ";
    }
    
}

void LoadData(string filename){
	ifstream file(filename);
	int value;
	
	while(file>>value){
		Pushback(value);
	}
	file.close();
}
};




int main() {
	AutoGrowingArray<int> AGA;
	AGA.createRandomFile("OutputGA.txt", 2);
	cout << "Before Loading: " << time(0) << endl;
	AGA.LoadData("OutputGA.txt");
	cout << "After Loading: " << time(0) << endl;
	
	Vector<int> v;
	v.createRandomFile("OutputVector.txt", 2);
	cout << "Before Loading: " << time(0) << endl;
	v.LoadData("OutputVector.txt");
	cout << "After Loading: " << time(0) << endl;
	
	ArrayList<int> AL;
	AL.createRandomFile("OutputArrayList.txt", 2);
	cout << "Before Loading: " << time(0) << endl;
	AL.LoadData("OutputArrayList.txt");
	cout << "After Loading: " << time(0) << endl;
	return 0;
}