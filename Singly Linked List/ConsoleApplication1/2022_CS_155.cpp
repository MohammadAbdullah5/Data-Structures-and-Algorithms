#pragma once
#include<iostream>
#include<stack>
using namespace std;

// Question 1

template <typename T>
class LinkedList
{
public:
	class Node
	{
		T data;
		Node* next;
		friend LinkedList;
		public:
		Node(T value)
		{
			data = value;
			next = nullptr;
		}
	};

	class LLIterator
	{
		Node* current;
		public:
		LLIterator(Node* node)
		{
			current = node;
		}

		LLIterator& operator ++()
		{
			current = current->next;
			return *this;
		}

		LLIterator operator++(int) {
			current = current->next;
			return *this;
		}

		bool operator !=(LLIterator iter)
		{
			return current != iter.current;
		}

		T& operator*()
		{
			return current->data;
		}
	};

	Node* head;
	Node* tail;
	LinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}

	LLIterator begin()
	{
		return LLIterator(head);
	}

	LLIterator end()
	{
		return LLIterator(nullptr);
	}

	bool IsEmpty()
	{
		if (head == nullptr && tail == nullptr)
		{
			return true;
		}
		return false;
	}

	void insertAtFront(T value)
	{
		Node* newNode = new Node(value);
		newNode->next = head;
		head = newNode;
		if (tail == nullptr)
		{
			tail = head;
		}
	}

	void insertAtTail(T value)
	{
		Node* newNode = new Node(value);
		if (IsEmpty())
		{
			head = newNode;
			tail = newNode;
		}

		else
		{
			tail->next = newNode;
			tail = newNode;
		}
	}

	void insertAtMiddle(T value)
	{
		Node* newNode = new Node(value);
		if (!IsEmpty())
		{
			int length = 0;
			Node* temp = head;
			while (temp != nullptr)
			{
				length++;
				temp = temp->next;
			}
			length = length / 2;
			length--;
			temp = head;
			for (int i = 0; i < length; i++)
			{
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}
		else
		{
			insertAtFront(value);
		}
	}

	void insertAfter(T value, T key)
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			if (temp->data == value)
			{
				Node* newNode = new Node(key);
				newNode->next = temp->next;
				temp->next = newNode;
			}
			temp = temp->next;
		}
	}

	void insertBefore(T value, T key)
	{
		Node* current = head;
		Node* previous = nullptr;
		while (current != nullptr)
		{
			if (current->data == value)
			{
				Node* newNode = new Node(key);
				newNode->next = previous->next;
				previous->next = newNode;
			}
			previous = current;
			current = current->next;
		}
	}

	T getFront()
	{
		if (!IsEmpty())
		{
			return head->data;
		}
	}

	T getTail()
	{
		if (!IsEmpty())
		{
			return tail->data;
		}
	}

	Node* Search(T key)
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			if (temp->data == key)
			{
				return temp;
			}
			temp = temp->next;
		}
		return nullptr;
	}

	void removeFront()
	{
		if (!IsEmpty())
		{
			if (head->next != nullptr)
			{
				Node* temp = head;
				head = head->next;
				delete temp;
			}
			else
			{
				delete head;
				head = nullptr;
				tail = nullptr;
			}
		}
	}

	void removeTail()
	{
		if (!IsEmpty())
		{
			if (head->next != nullptr)
			{
				Node* temp = head;
				while (temp->next->next != nullptr)
				{
					temp = temp->next;
				}
				Node* toDelete = temp->next;
				temp->next = nullptr;
				tail = temp;
				delete toDelete;
			}

			else
			{
				delete head;
				head = nullptr;
				tail = nullptr;
			}
		}
	}

	void removeMiddle()
	{
		if (!IsEmpty())
		{
			if (head->next != nullptr)
			{
				int length = 0;
				Node* temp = head;
				while (temp != nullptr)
				{
					length++;
					temp = temp->next;
				}
				int middle = length / 2;
				temp = head;
				if (length % 2 == 1)
				{
					for (int i = 0; i < middle - 1; i++)
					{
						temp = temp->next;
					}
				}

				else
				{
					for (int i = 0; i < middle - 2; i++)
					{
						temp = temp->next;
					}
				}
				Node* toDelete = temp->next;
				temp->next = toDelete->next;
				delete toDelete;
			}

			else
			{
				delete head;
				head = nullptr;
				tail = nullptr;
			}
		}
	}

	void display()
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << " --------- ";
			temp = temp->next;
		}
	}
};


// Question 2

template <typename T>
class Stack
{
	LinkedList<T> stack;

	public:
		Stack()
		{

		}

		void push(T V)
		{
			stack.insertAtTail(V);	
		}

		T pop()
		{
			if (!IsEmpty())
			{
				T returnValue = stack.getTail();
				stack.removeTail();
				return returnValue;
			}
		}

		bool IsEmpty()
		{
			if (stack.IsEmpty())
			{
				return true;
			}
			return false;
		}
};

template <typename T>
class Queue
{
	LinkedList<T> queue;

public:
	Queue()
	{

	}

	void Enqueue(T V)
	{
		
		queue.insertAtTail(V);
		
	}

	T Dequeue()
	{
		if (!IsEmpty())
		{
			T returnValue = queue.getFront();
			queue.removeFront();
			return returnValue;
		}
	}

	bool IsEmpty()
	{
		if (queue.IsEmpty())
		{
			return true;
		}
		return false;
	}
};

// Question 3
// LinkedList Implementation is used and at the end there are 
// functions for this question
template <typename T>
class LinkedListForQ3
{
public:
	class Node
	{
		T data;
		Node* next;
		friend LinkedListForQ3;
	public:
		Node(T value)
		{
			data = value;
			next = nullptr;
		}
	};

	class LLIterator
	{
		Node* current;
	public:
		LLIterator(Node* node)
		{
			current = node;
		}

		LLIterator& operator ++()
		{
			current = current->next;
			return *this;
		}

		LLIterator operator++(int) {
			current = current->next;
			return *this;
		}

		bool operator !=(LLIterator iter)
		{
			return current != iter.current;
		}

		T& operator*()
		{
			return current->data;
		}
	};

	Node* head;
	Node* tail;
	LinkedListForQ3()
	{
		head = nullptr;
		tail = nullptr;
	}

	LLIterator begin()
	{
		return LLIterator(head);
	}

	LLIterator end()
	{
		return LLIterator(nullptr);
	}

	bool IsEmpty()
	{
		if (head == nullptr && tail == nullptr)
		{
			return true;
		}
		return false;
	}

	void insertAtFront(T value)
	{
		Node* newNode = new Node(value);
		newNode->next = head;
		head = newNode;
		if (tail == nullptr)
		{
			tail = head;
		}
	}

	void insertAtTail(T value)
	{
		Node* newNode = new Node(value);
		if (IsEmpty())
		{
			head = newNode;
			tail = newNode;
		}

		else
		{
			tail->next = newNode;
			tail = newNode;
		}
	}

	void insertAtMiddle(T value)
	{
		Node* newNode = new Node(value);
		if (!IsEmpty())
		{
			int length = 0;
			Node* temp = head;
			while (temp != nullptr)
			{
				length++;
				temp = temp->next;
			}
			length = length / 2;
			length--;
			temp = head;
			for (int i = 0; i < length; i++)
			{
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}
		else
		{
			insertAtFront(value);
		}
	}

	void insertAfter(T value, T key)
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			if (temp->data == value)
			{
				Node* newNode = new Node(key);
				newNode->next = temp->next;
				temp->next = newNode;
			}
			temp = temp->next;
		}
	}

	void insertBefore(T value, T key)
	{
		Node* current = head;
		Node* previous = nullptr;
		while (current != nullptr)
		{
			if (current->data == value)
			{
				Node* newNode = new Node(key);
				newNode->next = previous->next;
				previous->next = newNode;
			}
			previous = current;
			current = current->next;
		}
	}

	T getFront()
	{
		if (!IsEmpty())
		{
			return head->data;
		}
	}

	T getTail()
	{
		if (!IsEmpty())
		{
			return tail->data;
		}
	}

	Node* Search(T key)
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			if (temp->data == key)
			{
				return temp;
			}
			temp = temp->next;
		}
		return nullptr;
	}

	void removeFront()
	{
		if (!IsEmpty())
		{
			if (head->next != nullptr)
			{
				Node* temp = head;
				head = head->next;
				delete temp;
			}
			else
			{
				delete head;
				head = nullptr;
				tail = nullptr;
			}
		}
	}

	void removeTail()
	{
		if (!IsEmpty())
		{
			if (head->next != nullptr)
			{
				Node* temp = head;
				while (temp->next->next != nullptr)
				{
					temp = temp->next;
				}
				Node* toDelete = temp->next;
				temp->next = nullptr;
				tail = temp;
				delete toDelete;
			}

			else
			{
				delete head;
				head = nullptr;
				tail = nullptr;
			}
		}
	}

	void removeMiddle()
	{
		if (!IsEmpty())
		{
			if (head->next != nullptr)
			{
				int length = 0;
				Node* temp = head;
				while (temp != nullptr)
				{
					length++;
					temp = temp->next;
				}
				int middle = length / 2;
				temp = head;
				if (length % 2 == 1)
				{
					for (int i = 0; i < middle - 1; i++)
					{
						temp = temp->next;
					}
				}

				else
				{
					for (int i = 0; i < middle - 2; i++)
					{
						temp = temp->next;
					}
				}
				Node* toDelete = temp->next;
				temp->next = toDelete->next;
				delete toDelete;
			}

			else
			{
				delete head;
				head = nullptr;
				tail = nullptr;
			}
		}
	}

	void display()
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << " --------- ";
			temp = temp->next;
		}
	}

	// Part 1
	void recursivePrint(Node* curr = head)
	{
		if (curr == nullptr)
		{
			return;
		}

		cout << curr->data;
		recursivePrint(curr->next);
		cout << curr->data;
	}

	// Part 2
	T middleElement()
	{
		if (!IsEmpty())
		{
			int length = 0;
			Node* temp = head;
			while (temp != nullptr)
			{
				length++;
				temp = temp->next;
			}
			if (length % 2 == 0)
			{
				length = length / 2;
				length--;
			}
			else
			{
				length = length / 2;
			}

			temp = head;
			for (int i = 0; i < length; i++)
			{
				temp = temp->next;
			}
			return temp->data;
		}
	}

	// Part 3
	bool isCircular()
	{
		if (tail->next == head)
		{
			return true;
		}
		return false;
	}

	// Part 4
	void reverseLinkedList()
	{
		stack<Node*> St;
		Node* temp = head;
		while (temp->next != nullptr)
		{
			St.push(temp);
			temp = temp->next;
		}
		head = temp;
		while (!St.empty())
		{
			temp->next = St.top();
			St.pop();
			temp = temp->next;
		}
		tail = temp;
		tail->next = nullptr;
	}
};

