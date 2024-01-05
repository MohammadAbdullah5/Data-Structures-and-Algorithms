#pragma once
template <typename T>
class StaticStack {

private:
	int size;
	int capacity;
	T* stack;

public:
	StaticStack(int capacity) {
		stack = new T[capacity];
	}

	void push(T value) {
		stack[size] = value;
		size++;
	}

	void pop(){
		size--;
	}

	int top() {
		return stack[size - 1];
	}

	bool IsEmpty() {
		return size == 0;
	}

	bool IsFull() {
		return size == capacity;
	}

	int size() {
		return size;
	}
};