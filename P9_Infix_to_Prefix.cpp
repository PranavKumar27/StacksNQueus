#include <iostream>
#include <stack>

using namespace std;


/*
    Infix to Prefix
    Step 1: Reverse the Infix
    Step 2: Perform Infix (str of step 1) to PostFix
            Note: Cannot have two '^' together
    Step 3: Reverse str of step 2

    Infix => str = (A + B)*C-D+F

    Step 1: Reverse str
            F+D-C*( B+A )  Note Parenthesis is reversed

    Step 2: Perform Infix to PostFix
            char             stack             ans
            F                                  F
            +                +                 F
            D                +                 FD
            -                - +               FD
            C                - +               FDC
            *                * - +             FDC
            (                ( * - +           FDC
            B                ( * - +           FDCB
            +                + ( * - +         FDCB
            A                + ( * - +         FDCBA
            )                    * - +         FDCBA+
                                   - +         FDCBA+*
                                     +         FDCBA+*-
                                               FDCBA+*-+

    Step 3: Reverse Str in step 2
            +-*+ABCDF

 Infix => str = A+B^(C-D)*F

    Step 1: Reverse str

            F*(D-C)^B+A  Note Parenthesis is reversed

    Step 2: Perform Infix to PostFix
            char             stack             ans
            F                                  F
            *                *                 F
            (                ( *               F
            D                ( *               FD
            -                - ( *             FD
            C                - ( *             FDC
            )                    *             FDC-
            ^                ^ *               FDC-
            B                ^ *               FDC-B
            +                + *               FDC-B^
                             +                 FDC-B^*
            A                +                 FDC-B^*A
                                               FDC-B^*A+



    Step 3: Reverse Str in step 2
            +A*^B-CDF


*/

int priority(char ch)
{
    if(ch=='^')
        return 3;
    else if(ch=='*' || ch=='/')
        return 2;
    else if(ch=='+' || ch=='-')
        return -1;
    else
        return -1;
}

string reverse_str(string str)
{
    int n = str.size();

    //if(n%2==1)// Odd
    {
        for(int i=0;i<=n/2;i++)
        {
            char ch = str[i];
            char ch2 = str[n-i-1];
            //cout << "ch1=" << ch << " ch2=" << ch2 << endl;

            if(ch=='(')
            {
               swap(str[i],str[n-i-1]);

               str[n-i-1] = ')';

            }
            else if(ch2=='(')
            {
                swap(str[i],str[n-i-1]);

                str[i] = ')';
            }
            else if(ch==')')
            {
                swap(str[i],str[n-i-1]);

                str[n-i-1] = '(';

            }
            else if(ch2==')')
            {
                swap(str[i],str[n-i-1]);

                str[i] = '(';
            }
            else
            {
                swap(str[i],str[n-i-1]);

            }

        }
    }
    return str;

}
string findPostFix(string infix)
{
   string PostFix="";
   int n = infix.size();
   stack<char> St;

   for(int i=0;i<n;i++)
   {
       char ch = infix[i];
       cout << " ch=" << ch << endl;

       if( (ch>='A' && ch<='Z') ||  // For Operands
          (ch>='a' && ch<='z') ||
          (ch>='0' && ch<='9') )
       {
            PostFix=PostFix+ch;
       }
       else if(ch=='(')  // For Open Parenthesis
       {
           St.push(ch);
       }
       else if(ch==')')  // For Closed Parenthesis
       {
           while(!St.empty() && St.top()!='(')
           {
               PostFix = PostFix + St.top();
               St.pop();
           }
          St.pop();
       }
       else // For Operators
       {
           // Element at top of stack > New Element
           if( ch=='^')
           {
               while(!St.empty() && priority(ch)<=priority(St.top()))
               {
                  PostFix = PostFix + St.top();
                  St.pop();
               }
           }
           else
           {
               while(!St.empty() && priority(ch)<priority(St.top()))
               {
                  PostFix = PostFix + St.top();
                  St.pop();
               }

           }
           St.push(ch);
       }

   }

   while(!St.empty())
   {
        PostFix = PostFix + St.top();
        St.pop();
   }

   return PostFix;
   //cout <<
}

void infixToPrefix(string& Infix,string& Prefix)
{
    // Step 1 : Reverse Infix
    string RevInfix = reverse_str(Infix);
    cout << "Rev Str =" << RevInfix << endl;

    string PostFix = findPostFix(RevInfix);
    cout << "PostFix Str =" << PostFix << endl;

    Prefix = reverse_str(PostFix);

    cout << "Prefix Str =" << Prefix << endl;

}

int main()
{
    string s1 = "A+B^(C-D)*F";
    string s2 = "";
    infixToPrefix(s1,s2);

    cout << "Prefix =" << s2 << endl;
    return 0;
}
