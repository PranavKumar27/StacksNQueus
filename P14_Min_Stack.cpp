#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef pair<int,int> pi;

/*
    Min Stack: A stack which has stack methods like push,pop,top,size and min()

    min() finds the minimum element in the stack so far

    To implement this store Stack as stack<pair<int,int>> St;
    where pair<element,min so far>

    At any point at top we can find Min in stack so far

    eg:
    Push(10)              {10,10}
    Push(12)              {10,10},{12,10}
    Push(5)               {10,10},{12,10},{5,5}
    top()              5  {10,10},{12,10},{5,5}
    min()              5  {10,10},{12,10},{5,5}
    pop()              5  {10,10},{12,10}
    min()             10  {10,10},{12,10}
    POP               12  {10,10}
    MIN               10  {10,10}



*/

class Min_Stack1
{
    stack<pi> St;
public:
    void push(int val)
    {
        if(St.empty())
        {
            St.push({val,val});
        }
        else
        {
            pi top = St.top();
            if(top.second<val)
            {
                St.push({val,top.second});
            }
            else
                St.push({val,val});
        }
    }
    void pop()
    {
       St.pop();
    }
    int top()
    {
        if(!St.empty())
            return St.top().first;
        else
            return -1;
    }
    int minInStack()
    {
        if(!St.empty())
            return St.top().second;
        else
            return -1;
    }
};

/*
   Min Stack: A stack which has stack methods like push,pop,top,size and min()

    min() finds the minimum element in the stack so far

    To implement this store Stack as stack<int> St;
    Maintain a mini val

    eg: Case 1:
        if mini =12 and we ecnounter New Val as 10

                10 < 12
              val  < mini
        val - mini < 0
  val - mini + val < 0 + val           Add val both sides
      2*val - mini < val
           new_val < val

    In stack we will push new_val


        Case 2:
        if mini =10 and we ecnounter New Val as 15

                15 < 10       Here mini is already minimum
                              so no need to modify and hence Just push


    When pop() is called
        We check if
            top < mini  If yes then we have stored Modified val
                        After pop we modify the mini to old_mini val
                        like from mini as 10 to 12

            top > mini - Directly pop

    Any time if a val which is going to replace the mini,
    we are going to store modified val < current val

    While popping take care of the same and revert to old_mini val

    At any point at top we can find Min in stack so far

    eg:
    Push(12)       mini = 12        12
    Push(10)       Mini = 10        12,8  .   Insert Modified val = 8     2*10-mini  = 20-12 = 8
    Push(15)       Mini = 10        12,8,15
    top()          15               12,8,15
    min()          10
    pop()          15               12,8
    min()          10
    POP            12               12
    MIN            12               12
*/
class Min_Stack2
{
    stack<int> St;
    int mini;
public:
    Min_Stack2()
    {
        mini=1e9;
    }
    void push(int val)
    {
        if(St.empty())
        {
            mini = val;
            St.push(val);
        }
        else
        {
            if(val>mini)
            {
                St.push(val);
            }
            else
            {
                // Obtain Modified val
                // Since mini is to be updated Here, store modified val in Stack
                int new_val = 2*val-mini; // new_val < val
                mini = val;
                St.push(new_val);
            }
        }
    }
    void pop()
    {

        if(St.empty())
            return;
        else
        {
            int val = St.top();
            St.pop();
            if(val<mini)  // Modified Vale was stored in Stack St
            {
                int old_mini = 2*mini - val;
                mini = old_mini;
            }
            else
            {
                // St.top > mini No need to update Mini
            }

        }
    }
    int top()
    {
        if(St.empty())
            return -1;
        else
        {
            int val = St.top();
            if(val<mini)  // Modified Vale was stored in Stack St
            {
                return mini; // Since val is modified and Store in Stack St
            }
            else
            {
                return val;
                // St.top > mini No need to update Mini
            }

        }
    }
    int minInStack()
    {
        return mini;
    }
};

int main()
{

    cout << "Min STACK 1" << endl;
    vector<int> Arr = {10,12,5,13,19};
    int n = Arr.size();
    Min_Stack1 S1;
    for(int i=0;i<n;i++)
    {
        S1.push(Arr[i]);
    }

    for(int i=0;i<n;i++)
    {
        int Element_top = S1.top();
        int Element_min = S1.minInStack();
        cout << "Element popped =" << Element_top << " Min So far =" << Element_min << endl;
        S1.pop();
    }


    cout << "Min STACK 2" << endl;
    vector<int> Arr2 = {10,12,5,13,19};
    int n2 = Arr2.size();
    Min_Stack2 S2;
    for(int i=0;i<n2;i++)
    {
        S2.push(Arr[i]);
    }

    for(int i=0;i<n2;i++)
    {
        int Element_top = S2.top();
        int Element_min = S2.minInStack();
        cout << "Element popped =" << Element_top << " Min So far =" << Element_min << endl;
        S2.pop();
    }


    return 0;
}
