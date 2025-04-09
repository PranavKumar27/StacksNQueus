#include <iostream>
#include <string>
#include <stack>

using namespace std;

/*
    S = *+PQ-MN

    char                                stack (top-->)
    N                                   N,
    M                                   N,M
    -    pop Last 2 from stack
         put operator in between
         and wrap with () and push      (M-N)
    Q                                   (M-N),Q
    P                                   (M-N),Q,P
    +    pop Last 2 from stack
         put operator in between
         and wrap with () and push      (A-B),(P+Q)
    *                                   ((A-B)*(P+Q))

    Hence Ans = ((A-B)*(P+Q))
*/

string Convert_Prefix_to_Infix(string Prefix)
{
    stack<string> St;
    int n = Prefix.size();
    for(int i=n-1;i>=0;i--)
    {
        char ch = Prefix[i];
        //cout << "ch=" << ch << endl;
        string str{ch};
        //cout << "str=" << str << endl;
        // Operands
        if((ch>='A' && ch<='Z')||
           (ch>='a' && ch<='z')||
           (ch>='0' && ch<='9'))
        {
            St.push(str);
        }
        else // Operator
        {
            string str1,str2;
            if(!St.empty())
            {
               str1 = St.top();
               St.pop();
            }
            if(!St.empty())
            {
               str2 = St.top();
               St.pop();
            }
            //cout << "str1=" << str1 << " str2=" << str2 << endl;
            string Merge_str = "("+str1+str+str2+")";
            //cout << "Merge_str=" << Merge_str << endl;
            St.push(Merge_str);
        }
    }
/*
    string infix;
    if(!St.empty())
    {
        infix = St.top();
        St.pop();
    }

    Or
*/
    string infix = St.top();
    return infix;
}

int main()
{
    string Prefix = "*+PQ-MN";

    string Infix = Convert_Prefix_to_Infix(Prefix);

    cout << "Infix=" << Infix << endl;
    return 0;
}
