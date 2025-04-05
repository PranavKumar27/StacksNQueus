#include <iostream>

using namespace std;

class Node
{
public:
    int val;
    Node* next;
    Node(int n)
    {
        val = n;
        next = nullptr;
    }
};

class Queue_Impl
{
    Node* start;
    Node* ends;
    int sz;
public:
    void init()
    {
        start=nullptr;
        ends=nullptr;
        sz = 0;
    }
    void push(int n)
    {
        Node* newNode = new Node(n);
        sz++;
        if(start==nullptr)
        {
            ends = nullptr;
            start=newNode;
        }
        else
        {
            ends->next = newNode;
        }
        ends=newNode;
    }
    int pop()
    {
        if(start==nullptr)
        {
            cout << "Q UnderFlow" << endl;
            return -1;
        }
        else
        {
            Node* temp = start;
            int el = temp->val;
            start = start->next;
            delete(temp);
            sz--;
            return el;
        }
    }
    int Front()
    {
        if(start==nullptr)
        {
            cout << "Q UnderFlow" << endl;
            return -1;
        }
        else
        {
            return start->val;
        }
    }
    int sizeOfQ()
    {
        return sz;
    }
};

int main()
{
    cout << "Q Implement Using Linked List" << endl;
    Queue_Impl Q;
    Q.init();
    cout << " Q Front=" << Q.Front() << endl;
    cout << " Q Pop=" << Q.pop() << endl;
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);
    cout << " Q Front=" << Q.Front() << endl;
    cout << " Q Pop=" << Q.pop() << endl;
    cout << " Q size=" << Q.sizeOfQ() << endl;
    Q.push(5);
    Q.push(6);
    cout << " Q Pop=" << Q.pop() << endl;
    cout << " Q Pop=" << Q.pop() << endl;
    cout << " Q Front=" << Q.Front() << endl;
    cout << " Q size=" << Q.sizeOfQ() << endl;
    cout << " Q Pop=" << Q.pop() << endl;
    cout << " Q Front=" << Q.Front() << endl;
    cout << " Q size=" << Q.sizeOfQ() << endl;
    cout << " Q Pop=" << Q.pop() << endl;
    cout << " Q size=" << Q.sizeOfQ() << endl;

    return 0;
}
