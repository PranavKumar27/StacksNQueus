#include <iostream>
#include <string>
#include <stack>

using namespace std;

int priority(char ch)
{
    if(ch == '^')
        return 3;
    else if(ch=='*' || ch=='/')
        return 2;
    else if(ch=='+' || ch=='-')
        return 1;
    else
        return -1;
}

string findPostFix(string s)
{
    int n = s.size();
    stack<char> St;
    string ans = "";
    for(int i=0;i<n;i++)
    {
        char ch = s[i];
        cout << "ch=" << ch << endl;
        // Operands
        if((ch>='A' && ch <='Z')||
           (ch>='a' && ch <='z')||
           (ch>='0' && ch <='9'))
        {
            ans=ans+ch;
        }
        else if(ch == '(')
            St.push(ch);
        else if(ch == ')')
        {
            while(St.top() != '(' )
            {
                char val = St.top();
                ans = ans+val;
                St.pop();
            }
            St.pop();
        }
        // Operator
        else if(!St.empty() && priority(ch)<=priority(St.top()))
        {
            char val = St.top();
            St.pop();
            ans = ans+val;
            St.push(ch);
        }
        else
        {
            St.push(ch);
        }
    }

    while(!St.empty())
    {
        char val = St.top();
        St.pop();
        ans = ans+val;
    }
    return ans;
}

int main()
{
    string s = "a+b*(c^d-e)";

    string PostFix = findPostFix(s);
    cout << "PostFix Expression =" << PostFix << endl;
    return 0;
}
