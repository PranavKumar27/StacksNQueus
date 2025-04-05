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

class Stack_Impl
{
    Node* top;
    int St_size;
public:
    void init()
    {
        top = nullptr;
        St_size = 0;
    }
    void push(int n)
    {
        Node* newNode = new Node(n);
        if(top==nullptr)
            top = newNode;
        else
        {
            Node* temp = top;
            newNode->next = temp;
            top = newNode;
        }
        St_size++;
    }
    int pop()
    {
        if(top==nullptr)
        {
            cout << "Stack underFlow " << endl;
            return -1;
        }
        else
        {
            Node* temp = top;
            int val = temp->val;
            top = top->next;
            delete(temp);
            St_size--;
            return val;
        }
    }
    int top_val()
    {
        if(top==nullptr)
        {
            cout << "Stack underFlow " << endl;
            return -1;
        }
        else
            return top->val;
    }
    int size_val()
    {
        return St_size;
    }
};
int main()
{
    cout << "Stack Implementation Using Linked List" << endl;
    Stack_Impl Stck;
    Stck.init();
    int element = Stck.pop();
    cout << "element Popped = " << element << endl;
    Stck.push(10);
    Stck.push(50);
    Stck.push(40);
    int top = Stck.top_val();
    cout << "top=" << top << endl;
    element = Stck.pop();
    cout << "element Popped = " << element << endl;
    Stck.push(30);
    int sz = Stck.size_val();
    cout << "Stack Size=" << sz << endl;

    Stck.push(60);
    Stck.push(100);
    Stck.push(-20);
    Stck.push(90);

    top = Stck.top_val();
    cout << "top=" << top << endl;
    element = Stck.pop();
    cout << "element Popped = " << element << endl;
    Stck.push(30);
    sz = Stck.size_val();
    cout << "Stack Size=" << sz << endl;

    return 0;
}
