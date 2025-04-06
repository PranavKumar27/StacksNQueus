#include <iostream>
#include <stack>

using namespace std;

/* Implement Queue Using stacks

Insert in Queue    1, 2, 3 ,4 ,5
              <-------Queue ------->
              front  1 2 3 4 5
Pop       1          2 3 4 5
top       2
Push 6               2 3 4 5 6
pop       2          3 4 5 6

Using Stack to implement Queue
Three Steps
S1--> S2
Push in S1
S2->S1

Push 1
S1  1                S2  ___

Push 2  Before Insert Move all values of S1 to S2
S1                   S2 1
S1 2                 S2 1
Move all back from S2 to s1
S1 top-> 1 2          S2 __


Push 3  Before Insert Move all values of S1 to S2
S1 top->  1 2        S2 __
S1  2                S2 1
S1                   S2 2 1
S1  3                S2 2 1
Move all back from S2 to s1
S1 3              S2 2 1
S1 2 3             S2 1
S1 (top) 1 2 3      S2


Push 4  Before Insert Move all values of S1 to S2
S1(top)-> 1 2 3       S2 __
S1          2 3       S2 1
S1            3       S2 2 1
S1         4          S2 3 2 1
Move all back from S2 to s1
S1 4               S2 3 2 1
S1 3 4             S2 2 1
S1 2 3 4            S2 1
S1 1 2 3 4          S2 na

Same way push 5 and 6,
S1 top = 1 2 3 4 5 6  S1 __

Find Top() = Top of S1 = 1

Pop = Pop top = 1
S1 = 1 2 3 4 5    S2___

*/

///<-----------------  SOLUTION 1 --------------> Push is O(N)
class Queue_Impl_Sol1
{
    public:
    stack<int> S1,S2;
    void push(int n)
    {
        // Step 1: Move All S1 to S2
        while(!S1.empty())
        {
            S2.push(S1.top());
            S1.pop();
        }

        // Step 2: Insert into S1
        S1.push(n);

        // Step 3: Move back S2 to S1
        while(!S2.empty())
        {
            S1.push(S2.top());
            S2.pop();
        }
    }
    int pop()
    {
        int val = -1;
        if(S1.size()>0)
        {
            val = S1.top();
            S1.pop();
        }
        return val;
    }
    int top()
    {
        int val = -1;
        if(S1.size()>0)
        {
            val = S1.top();
        }
        return val;
    }
    void print_Stack(stack<int> st)
    {
        while(!st.empty())
        {
            cout << "val=" << st.top() << endl;
            st.pop();
        }
    }
};



///<-----------------  SOLUTION 2 --------------> Pop and top is O(N)


class Queue_Impl_Sol2
{
    public:
    stack<int> S1,S2;
    void push(int n)
    {

        S1.push(n);
    }
    int pop()
    {
        int val = -1;
        if(S1.size()>0)
        {
            // Step 1: Move All S1 to S2
            while(!S1.empty())
            {
                S2.push(S1.top());
                S1.pop();
            }

            // Step 2: Pop Element from S1
            val = S2.top();
            S2.pop();

            // Step 3: Move back S2 to S1
            while(!S2.empty())
            {
                S1.push(S2.top());
                S2.pop();
            }
        }
        return val;
    }
    int top()
    {
        int val = -1;
        if(S1.size()>0)
        {
            // Step 1: Move All S1 to S2
            while(!S1.empty())
            {
                S2.push(S1.top());
                S1.pop();
            }

            // Step 2: Pop Element from S1
            val = S2.top();

            // Step 3: Move back S2 to S1
            while(!S2.empty())
            {
                S1.push(S2.top());
                S2.pop();
            }
        }
        return val;
    }
    void print_Stack(stack<int> st)
    {
        while(!st.empty())
        {
            cout << "val=" << st.top() << endl;
            st.pop();
        }
    }
};



int main()
{
    cout << "Queue Implement Using Stack Using Sol-1" << endl;
    Queue_Impl_Sol1 Q1;
    Q1.push(1);
    Q1.push(2);
    Q1.push(3);
    Q1.push(4);
    Q1.push(5);
    cout << "Q front =" << Q1.top() << endl;
    cout << "Q pop=" << Q1.pop() << endl;

    cout << "Q front =" << Q1.top() << endl;
    cout << "Q pop=" << Q1.pop() << endl;
    Q1.push(6);
    cout << "Q front =" << Q1.top() << endl;
    cout << "Q pop=" << Q1.pop() << endl;

    cout << "Queue Implement Using Stack Using Sol-2" << endl;
    Queue_Impl_Sol2 Q2;
    Q2.push(1);
    Q2.push(2);
    Q2.push(3);
    Q2.push(4);
    Q2.push(5);

    Q2.print_Stack(Q2.S1);
    cout << "Q front =" << Q2.top() << endl;
    cout << "Q pop=" << Q2.pop() << endl;

    cout << "Q front =" << Q2.top() << endl;
    cout << "Q pop=" << Q2.pop() << endl;
    Q2.push(6);
    cout << "Q front =" << Q2.top() << endl;
    cout << "Q pop=" << Q2.pop() << endl;
    return 0;
}


