#include <iostream>
#define MAXSIZE 10
using namespace std;

// Stack is a LIFO Design
// Last In  First Out
// Whoever enters last , exists first
// Stack will be of Size N i.e. Max Size
// Push more than N will send Error as Stack OverFlow
// Pop when 0 elements are in Stack we throw Error as Stack UnderFlow
// Top returns topMost or the last inserted element
// size() Returns the size of the stack

class Stack_Impl
{
    int top;
    int Arr[MAXSIZE];
public:
    void init()
    {
        top=-1;
        Arr[MAXSIZE]=0;
    }
    void push(int n)
    {
        if(top+1==MAXSIZE)
        {
            cout << "Over Flow in " << __FUNCTION__ << endl;
            return;
        }
        else
        {
            Arr[++top] = n;
        }
    }
    int pop()
    {
        if(top<0)
        {
            cout << "Under Flow in " << __FUNCTION__ << endl;
            return -1;
        }
        else
        {
            int element = Arr[top];
            top--;
            return element;
        }
    }
    int Size()
    {
        return (top+1);
    }
    int Top()
    {
        if(top<0)
        {
            cout << "Under Flow in " << __FUNCTION__ << endl;
            return -1;
        }
        else
            return Arr[top];
    }

};
int main()
{
    Stack_Impl Stck;
    Stck.init();
    int element = Stck.pop();
    cout << "element Popped = " << element << endl;
    Stck.push(10);
    Stck.push(50);
    Stck.push(40);
    int top = Stck.Top();
    cout << "top=" << top << endl;
    element = Stck.pop();
    cout << "element Popped = " << element << endl;
    Stck.push(30);
    int sz = Stck.Size();
    cout << "Stack Size=" << sz << endl;

    Stck.push(60);
    Stck.push(100);
    Stck.push(-20);
    Stck.push(90);

    top = Stck.Top();
    cout << "top=" << top << endl;
    element = Stck.pop();
    cout << "element Popped = " << element << endl;
    Stck.push(30);
    sz = Stck.Size();
    cout << "Stack Size=" << sz << endl;

    cout << "Hello world!" << endl;
    return 0;
}
