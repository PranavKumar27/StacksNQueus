#include <iostream>
#include <queue>

using namespace std;

/*
    Implement Stack LIFO Using Queue FIFO

    In stack
    1 2 3 4
    push (insert after 5) 1 2 3 4 5
    pop() will return 5
    top() will return 4


    Using Queue
    Insert in Queue
    Push(1) in Queue, Push 1 in Queue               1
                      Pop all element before 1
                      Push back in queue

    Push(2) in Queue, Push 2 in Queue               1 2
                      Pop all element before 2        2
                      Push back in queue            2 1

    Push(3) in Queue, Push 3 in Queue               2 1 3
                      Pop all element before 3        1 3             3
                      Push back in queue            1 3 2         3 2 1

    Push(4) in Queue, Push 4 in Queue               3 2 1 4
                      Pop all element before 4        2 1 4           1 4            4
                      Push back in queue              2 1 4 3         1 4 3 2        4 3 2 1

    Push(5) in Queue, Push 5 in Queue               4 3 2 1 5
                      Pop all element before 5        3 2 1 5          2 1 5             1 5                  5
                      Push back in queue              3 2 1 5 4        2 1 5 4 3         1 5 4 3 2            5 4 3 2 1


    pop()  Return Front of queue as 5            5 4 3 2 1    After pop 4 3 2 1
    top()  top is front = 4


*/
 // Stack using Queue
class Stack_Impl
{
    queue<int> Q;
public:
    void push(int n)
    {
        int sz = Q.size();
        Q.push(n);

        // Reverse the queue till n;

        for(int i=0;i<sz;i++)
        {
            int el = Q.front();
            Q.pop();
            Q.push(el);
        }
    }

    int pop()
    {
        int val = -1000;
        if(Q.size()!=0)
        {
            val = Q.front();
            Q.pop();
        }
        return val;
    }
    int top()
    {
        int val = -1000;
        if(Q.size()!=0)
        {
            val = Q.front();
        }
        return val;
    }
};

int main()
{

    cout << "Stack Using Queue" << endl;
    // Insert 1, 2 , 3 , 4 ,5 in Stack

    Stack_Impl S;

    cout << "Stack Top=" << S.top() << endl;
    cout << "Stack Popped Element =" << S.pop() << endl;
    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    S.push(5);

    cout << "Stack Top=" << S.top() << endl;
    cout << "Stack Popped Element =" << S.pop() << endl;
    cout << "Stack Top=" << S.top() << endl;

    S.push(6);
    cout << "Stack Top=" << S.top() << endl;
    cout << "Stack Popped Element =" << S.pop() << endl;
    cout << "Stack Top=" << S.top() << endl;

    return 0;
}
