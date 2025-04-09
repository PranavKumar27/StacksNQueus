#include <iostream>
#include <string>
#include <stack>

using namespace std;

/*
    S = AB - DE + F * /

    char                                stack (top-->)
    A                                   A,
    B                                   A,B
    -    pop Last 2 from stack
         put operator in between
         and wrap with () and push      (A-B)
    D                                   (A-B),D
    E                                   (A-B),D,E
    +    pop Last 2 from stack
         put operator in between
         and wrap with () and push      (A-B),(D+E)
    F                                   (A-B),(D+E),F
    *                                   (A-B),((D+E)*F)
    /                                   ((A-B)/((D+E)*F))

    Hence Ans = ((A-B)/((D+E)*F))
*/

string Convert_PostFix_to_Infix(string PostFix)
{
    stack<string> St;
    int n = PostFix.size();
    for(int i=0;i<n;i++)
    {
        char ch = PostFix[i];
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
            string Merge_str = "("+str2+str+str1+")";
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
    string PostFix = "AB-DE+F*/";

    string Infix = Convert_PostFix_to_Infix(PostFix);

    cout << "Infix=" << Infix << endl;
    return 0;
}
