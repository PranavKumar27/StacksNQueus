#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/*
    in Arr = 4 12 5 3 1 2 5 3 1 2 4 6
    NGE    =12 -1 6 5 2 5 6 4 2 4 6 -1

    Using For Loop = Sol1
    Using Stack = Sol 2: Monotonic Stack
    A stack where elements are stored in a specific order.
    Here element are stored in decreasing order only

    When Using stack
    Start from end
    in Arr = 4 12 5 3 1 2 5 3 1 2 4 6
                                    ^
            Next to 6 is -1,
            Push 6 in Stack {6}

     in Arr = 4 12 5 3 1 2 5 3 1 2 4 6
                                   ^
               Next to 4 is 6 top of stack,
               Push 4 in Stack  {6,4}

     in Arr = 4 12 5 3 1 2 5 3 1 2 4 6
                                 ^
               Next to 2 is 6 top of stack,
               Push 2 in Stack  {6,4,2}

      in Arr = 4 12 5 3 1 2 5 3 1 2 4 6
                                ^
               Next to 1 is 2 top of stack,
               Push 2 in Stack  {6,4,2,1}

      in Arr = 4 12 5 3 1 2 5 3 1 2 4 6
                              ^
               Next to 3 is 1 top of stack hwich is <3, So pop it , same way 2 pop
               So NGE of 3 is 4 top of stack
               Push 3 in Stack  {6,4,3}

      in Arr = 4 12 5 3 1 2 5 3 1 2 4 6
                            ^
               Next to 5 is 3 top of stack which is <5, So pop it , same way 5<4 pop
               So NGE of 5 is 6 top of stack
               Push 5 in Stack  {6,5}

       in Arr = 4 12 5 3 1 2 5 3 1 2 4 6
                           ^
               Next to 2 is 5 top of stack, which is > 2
               So NGE of 2 is 5 top of stack
               Push 2 in Stack  {6,5,2}

       in Arr = 4 12 5 3 1 2 5 3 1 2 4 6
                         ^
               Next to 1 is 2 top of stack, which is > 1
               So NGE of 1 is 2 top of stack
               Push 1 in Stack  {6,5,2,1}

       in Arr = 4 12 5 3 1 2 5 3 1 2 4 6
                       ^
               Next to 3 is 1 top of stack which is <3, So pop it , same way 2 pop
               So NGE of 3 is 5 top of stack
               Push 3 in Stack  {6,5,3}

        in Arr = 4 12 5 3 1 2 5 3 1 2 4 6
                      ^
               Next to 5 is 3 top of stack which is <5, So pop it , same way 5 pop
               So NGE of 3 is 6 top of stack
               Push 5 in Stack  {6,5}

        in Arr = 4 12 5 3 1 2 5 3 1 2 4 6
                    ^
               Next to 12 is 5 top of stack which is <12, So pop it , same way 6 pop
               So NGE of 12 is -1
               Push 12 in Stack  {12}

         in Arr = 4 12 5 3 1 2 5 3 1 2 4 6
                  ^
               Next to 4 is 12 top of stack, which is > 1
               So NGE of 4 is 12
               Push 4 in Stack  {12,4}
*/

// TC --> O(N*N)
void find_Next_Greater_Elmnt_SOl1(vector<int>& Arr,vector<int>& NGE)
{
    cout << __FUNCTION__ << endl;
    int n = Arr.size();
    for(int i=0;i<n;i++)
    {
        NGE[i]=-1;
        cout << "Arr[i]=" << Arr[i] << endl;
        for(int j=i+1;j<n;j++)
        {
            if(Arr[j]>Arr[i])
            {
                NGE[i]=Arr[j];
                break;
            }
        }
    }
}

// TC --> O(2N) for using loop for and while, while loop at max runs N times in the entire For loop
// SC --> O(N)+O(N) for Ans and Stack
void find_Next_Greater_Elmnt_SOl2(vector<int>& Arr,vector<int>& NGE)
{
    cout << __FUNCTION__ << endl;
    stack<int> St; // Store Numbers in Decresing order

    int n = Arr.size();
    for(int i=n-1;i>=0;i--)
    {
        int val = Arr[i];
        NGE[i]=-1;
        while(!St.empty())
        {
            int top = St.top();
            if(top>val)
            {
                NGE[i] = top;
                break;
            }
            else
            {
                St.pop();
            }
        }
        St.push(val);
    }
}

void print_1D_v(vector<int> v)
{
    for(auto d:v)
        cout << d << ",";
    cout << endl;
}
int main()
{
    cout << "Next Greater Element" << endl;
    vector<int> Arr ={4, 12, 5, 3, 1, 2, 5, 3, 1, 2, 4, 6};
    int n = Arr.size();
    vector<int> NGE(n);// Next Greater Element

    find_Next_Greater_Elmnt_SOl1(Arr,NGE);



    print_1D_v(Arr);
    print_1D_v(NGE);


    vector<int> NGE2(n);// Next Greater Element

    find_Next_Greater_Elmnt_SOl2(Arr,NGE2);



    //print_1D_v(Arr);
    print_1D_v(NGE2);


    return 0;
}
