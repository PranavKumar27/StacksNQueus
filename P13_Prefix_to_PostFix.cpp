#include <iostream>
#include <string>
#include <stack>

using namespace std;

/*
    str = /-AB*+DEF

    Read ch in reverse order

    ch                      stack
    F                       F
    E                       F,E
    D                       F,E,D  ( t1 t2 operator)
    +                       F,DE+
    *                       DE+F*
    B                       DE+F*,B
    A                       DE+F*,B,A
    -                       DE+F*,AB-
    /                       AB-DE+F*/


// */

string Convert_PreFix_to_PostFix(string Prefix)
{
    int n = Prefix.size();
    stack<string> St;
    for(int i=n-1;i>=0;i--)
    {
        char ch = Prefix[i];
        string str{ch};
        if((ch>='A' && ch<='Z')||
           (ch>='a' && ch<='z')||
           (ch>='0' && ch<='9'))
        {
            St.push(str);
        }
        else
        {
            string t1,t2;
            if(!St.empty())
            {
                t1=St.top();
                St.pop();
            }
            if(!St.empty())
            {
                t2=St.top();
                St.pop();
            }
            string MergedStr = t1+t2+str;
            St.push(MergedStr);
        }
    }

    string Postfix  ="";
    if(!St.empty())
        Postfix = St.top();
    return Postfix;
}

int main()
{
    string Prefix = "/-AB*+DEF";

    string PostFix = Convert_PreFix_to_PostFix(Prefix);



    cout << "PostFix=" << PostFix << endl;
    return 0;
}
