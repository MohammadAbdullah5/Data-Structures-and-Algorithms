#pragma once
#include <vector>
template <typename T>
class VectorStack {
private:
	vector<T> stack;
public:
	VectorStack(int capacity) {
		stack(capacity);
	}

	void push(T value) {
		stack.push_back(value);
	}

	void pop() {
		stack.pop_back();
	}

	int top() {
		return stack[stack.size()-1];
	}

	bool IsEmpty() {
		return stack.size() == 0;
	}
};