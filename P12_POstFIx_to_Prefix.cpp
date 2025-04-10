#include <iostream>
#include <string>
#include <stack>

using namespace std;
/*
    //PostFix = AB-DE+F*/
/*
    ch                        stack
    A                         A
    B                         A,B
    -                         -AB   (op t2 t1)
    D                         -AB,D
    E                         -AB,DE
    +                         -AB,+DE (op top2 top1)
    F                         -AB,+DE,F
    *                         -AB,*+DEF ( op top2 top1)
    /                         /-AB*+DEF

*/

string PostFix_to_Prefix(string PostFix)
{
    string Prefix = "";

    int n = PostFix.size();
    stack<string> St;
    for(int i=0;i<n;i++)
    {
        char ch = PostFix[i];
        cout << "ch=" << ch << endl;
        string str{ch};
        // Operands
        if( (ch>='A' && ch<='Z')||
           (ch>='a' && ch<='z')||
           (ch>='0' && ch<='9'))
        {

            St.push(str);
            cout << "str=" << str << endl;
        }
        else
        {
            string t1,t2;
            if(!St.empty())
            {
                t1 = St.top();
                St.pop();
            }
            if(!St.empty())
            {
                t2 = St.top();
                St.pop();
            }
            cout << "t1=" << t1 << "  t2=" << t2 <<  endl;
            string Merged_Str = str+t2+t1;
             cout << "Merged_Str=" << Merged_Str  <<  endl;
            St.push(Merged_Str);
        }
    }
    while(!St.empty())
    {
        Prefix = St.top();
    }
    return Prefix;

}

int main()
{
    string PostFix = "AB-DE+F*/";

    string Prefix = PostFix_to_Prefix(PostFix);

    cout << "Prefix=" << Prefix << endl;
    return 0;
}
