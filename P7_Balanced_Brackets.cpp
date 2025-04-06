#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

bool IsBalanced(string s)
{
    stack<char> St;
    bool IsBal = true;
    int n = s.size();
    for(int i=0;i<n;i++)
    {
        char ch = s[i];
        //cout << "ch=" << ch << endl;
        if(ch == '(' || ch =='{' || ch == '[')
            St.push(ch);

        else if(ch == ')' || ch =='}' || ch == ']')
        {
            if(St.empty())
               return false;
            
            char ch_top = St.top();
            if( ( ch == ')' && ch_top == '(' ) ||
                ( ch == '}' && ch_top == '{' ) ||
                ( ch == ']' && ch_top == '[' ) )
            {
                St.pop();
            }
            else
            {

                IsBal = false;   // Brackets Not Matching  ( with }
                break;
            }
        }
        else
        {
                IsBal = false;   // Case for Random Characters
                break;
        }
    }

    if(!St.empty())
        return false;
    else
        return IsBal;
}
int main()
{
    cout << "BALANCED BRACKETS" << endl;
    vector<string> lists = {"()[{}]","([{}])","))","(()","((()k))"};
    //int n =
    for(int i=0;i<lists.size();i++)
    {
        cout << "String S=" << lists[i] << " Is Balanced = " << IsBalanced(lists[i]) << endl;
    }

    return 0;
}
