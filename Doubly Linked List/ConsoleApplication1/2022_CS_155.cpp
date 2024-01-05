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
		Node* previous;
		Node* next;
		friend LinkedList;
	public:
		Node(T value)
		{
			data = value;
			previous = nullptr;
			next = nullptr;
		}
	};

	class ForwardIterator
	{
	public:
		Node* current;
		ForwardIterator(Node* node)
		{
			current = node;
		}

		ForwardIterator& operator ++()
		{
			current = current->next;
			return *this;
		}

		ForwardIterator operator++(int) {
			current = current->next;
			return *this;
		}

		bool operator !=(ForwardIterator iter)
		{
			return current != iter.current;
		}

		bool operator ==(ForwardIterator iter)
		{
			return current == iter.current;
		}

		T& operator*()
		{
			return current->data;
		}
	};

	class ReverseIterator
	{
	public:
		Node* current;
		ReverseIterator(Node* node)
		{
			current = node;
		}

		ReverseIterator& operator ++()
		{
			current = current->previous;
			return *this;
		}

		ReverseIterator operator++(int) {
			current = current->previous;
			return *this;
		}

		bool operator !=(ReverseIterator iter)
		{
			return current != iter.current;
		}

		bool operator ==(ReverseIterator iter)
		{
			return current == iter.current;
		}

		T& operator*()
		{
			return current->data;
		}
	};

	class GeneralIterator
	{
	public:
		Node* current;
		GeneralIterator(Node* node)
		{
			current = node;
		}

		GeneralIterator& operator ++()
		{
			current = current->next;
			return *this;
		}

		GeneralIterator operator++(int) {
			current = current->next;
			return *this;
		}

		GeneralIterator& operator --()
		{
			current = current->previous;
			return *this;
		}

		GeneralIterator operator--(int) {
			current = current->previous;
			return *this;
		}

		bool operator !=(GeneralIterator iter)
		{
			return current != iter.current;
		}

		bool operator ==(GeneralIterator iter)
		{
			return current == iter.current;
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

	ForwardIterator fbegin()
	{
		return GeneralIterator(head);
	}

	ForwardIterator fend()
	{
		return GeneralIterator(nullptr);
	}

	ReverseIterator rbegin()
	{
		return GeneralIterator(head);
	}

	ReverseIterator rend()
	{
		return GeneralIterator(nullptr);
	}

	GeneralIterator begin()
	{
		return GeneralIterator(head);
	}

	GeneralIterator end()
	{
		return GeneralIterator(nullptr);
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
		head->previous = newNode;
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
			newNode->previous = tail;
			tail->next = newNode;
			tail = newNode;
		}
	}

	void insertAtAfter(GeneralIterator iter, T value)
	{
		Node* newNode = new Node(value);
		if (iter.current == tail)
		{
			newNode->previous = iter.current;
			iter.current->next = newNode;
			iter.current = newNode;
			tail = newNode;
		}

		else
		{
			newNode->previous = iter.current;
			newNode->next = iter.current->next;
			iter.current->next->previous = newNode;
			iter.current->next = newNode;
		}
	}

	void insertAtBefore(GeneralIterator iter, T value)
	{
		Node* newNode = new Node(value);
		if (iter.current == head)
		{
			newNode->next = iter.current;
			newNode->previous = nullptr;
			iter.current->previous = newNode;
			iter.current = newNode;
			head = newNode;
		}

		else
		{
			newNode->next = iter.current;
			newNode->previous = iter.current->previous;
			iter.current->previous->next = newNode;
			iter.current->previous = newNode;
		}		 
	}

	void removeAt(GeneralIterator iter)
	{
		Node* temp = iter.current;
		if (iter.current != head || iter.current != tail)
		{
			iter.current->previous->next = iter.current->next;
			iter.current->next->previous = iter.current->previous;
		}

		else if (iter.current == head)
		{
			iter.current = iter.current->next;
			iter.current->previous = nullptr;
			head = iter.current;
		}

		else if(iter.current == tail)
		{
			iter.current = iter.current->previous;
			iter.current->next = nullptr;
			tail = iter.current;
		}
		delete temp;
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

	void splice(GeneralIterator iter, LinkedList<T>& ll)
	{
		ll.head = iter.current;
	}
};

// Part B
// Reverse Linked List II (Prob. 4)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> vctr;

        if(head == nullptr || head->next == nullptr || left == right)
        {
            return head;
        }   
        
        ListNode* temp = head;

        while(temp != nullptr)
        {
            vctr.push_back(temp->val);
            temp = temp->next;
        }
        int l = left - 1;
        int r = right - 1;
        while(l <= r)
        {
            swap(vctr[l], vctr[r]);
            l++;
            r--;
        }

        ListNode* newHead = new ListNode(vctr[0]);
        head = newHead;
        ListNode* headToMov = head;
        for(int i = 1; i < vctr.size(); i++)
        {
            ListNode* curr = new ListNode(vctr[i]);
            headToMov->next = curr;
            headToMov = curr;
        }
        return head;
    }
};

// Remove nth node from tail (Prob. 2)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev;
        ListNode* curr = head;
        int size = 0;
        while(curr != nullptr)
        {
            size++;
            curr = curr->next;
        }
        int idx = size - n - 1;
        curr = head;
        int index = 0;
        while(index < idx)
        {
            index++;
            curr = curr->next;
            prev = curr;
        }
        if(size - n == 0)
        {
            return head->next;
        }
        if(index + 1 < size)
        {
            curr->next = curr->next->next;
        }

        else if(size == 1)
        {
            head = nullptr;
        }


        else
        {
            curr->next = nullptr;
        }
        return head;
    }
};


// Swap Nodes in pairs (Prob. 3)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr)
        {
            return head;
        }
        vector<ListNode*> vctr;
        ListNode* temp = head;
        while(temp != nullptr)
        {
            vctr.push_back(temp);
            temp = temp->next;
        }
        int size = vctr.size();
        for(int i = 0; i + 1< size; i+= 2)
        {
            swap(vctr[i],vctr[i+1]);
        }

        ListNode* header = nullptr;
        ListNode* h = header;
        
        for(int i = 0; i + 1 < size; i++)
        {

            vctr[i]->next = vctr[i+1];
        }
        vctr[size-1]->next = nullptr;
        return vctr[0];
    }
};

// Design Linked List (Prob. 5)
class Node{
    public:
        int value;
        Node* next;
        Node* prev;
        Node(int val)
        {
            value = val;
            next = nullptr;
            prev = nullptr;
        }
};
class MyLinkedList {
    Node* head;
    Node* tail;
    int size;
public:
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    int get(int index) {
        if(index < size)
        {
            int count = 0;
            Node* temp = head;
            while(temp != nullptr && count < index)
            {
                count++;
                temp = temp->next;
            }
            return temp->value;
        }

        else
        {
            return -1;
        }
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        if(head == nullptr && tail == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }   
        size++;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if(head == nullptr && tail == nullptr)
        {
            head = newNode;
            tail = newNode;
        }

        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > size)
        {
            return;
        }
        
        else if(index == 0)
        {
            addAtHead(val);
        }
        
        else if(index == size)
        {
            addAtTail(val);
        }

        else
        {
            int count = 0;
            Node* temp = head;
            Node* newNode = new Node(val);
            while(temp != nullptr && count < index)
            {
                temp = temp->next;
                count++;
            }
            newNode->next = temp;
            newNode->prev = temp->prev;
            temp->prev->next = newNode;
            temp->prev = newNode;
            size++;
        }
        
    }
    
   void deleteAtIndex(int index) {
        if(index < 0 || index >= size)
        {
            return;
        }

        else if(index == 0)
        {
            Node* temp = head;
            head = head->next;
            if(head != nullptr)
            {
                head->prev = nullptr;
            }
            delete temp;
        }

        else if (index == size - 1)
        {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }

        else
        {
            int count = 0;
            Node* temp = head;
            while(temp != nullptr && count < index)
            {
                temp = temp->next;
                count++;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
        size--;
    }

};

/**
 * Your MyLinked object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

// Merge Two Sorted List (Prob. 1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* result = new ListNode(-1);
        ListNode* dummy = result;
        if(list1 == nullptr)
        {
            return list2;
        }

        else if(list2 == nullptr)
        {
            return list1;
        }

        else
        {
            while(list1 != nullptr && list2 != nullptr)
            {
                if(list1->val <= list2->val)
                {
                    result->next = list1;
                    list1 = list1->next;
                }

                else
                {
                    result->next = list2;
                    list2 = list2->next;
                }
                result = result->next;
            }
            
            if (list1 != nullptr)
            {
                result->next = list1;
            }

            else 
            {
                result->next = list2;
            }
        }
        return dummy->next;
    }
};