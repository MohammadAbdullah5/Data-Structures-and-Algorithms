#include <iostream>
#include "2022_CS_155.cpp"

int main()
{
    LinkedListForQ3<int> l;
    l.insertAtTail(1);
    l.insertAtTail(2);
    l.insertAtTail(3);
    l.insertAtTail(4);
    l.insertAtTail(5);
    l.insertAtTail(6);
    l.reverseLinkedList();

    l.display();
    cout << endl;

    LinkedListForQ3<int> ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.reverseLinkedList();

    ll.display();

    /*Stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout << st.pop();
    cout << st.pop();
    cout << st.pop();
    cout << st.pop();
    cout << st.pop();

    Queue<int> q;
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    cout << q.Dequeue();
    cout << q.Dequeue();
    cout << q.Dequeue();
    cout << q.Dequeue();
    cout << q.Dequeue();*/
}
