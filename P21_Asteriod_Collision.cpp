#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <algorithm>

using namespace std;

void print_1D_v(vector<int> v)
{
    for(auto d:v)
        cout << d << " , ";
    cout << endl;
}

/*

   Arr = {4,7,1,1,2,-3,-7,-17,15,-16};
          ^                                   Stack ={4}
          
   Arr = {4,7,1,1,2,-3,-7,-17,15,-16};
            ^                                 Stack ={4,7}  
            
   Arr = {4,7,1,1,2,-3,-7,-17,15,-16};
              ^                               Stack ={4,7,1}                     

   Arr = {4,7,1,1,2,-3,-7,-17,15,-16};
                ^                              Stack ={4,7,1,1}                     

   Arr = {4,7,1,1,2,-3,-7,-17,15,-16};
                  ^                            Stack ={4,7,1,1,2}                 

   Arr = {4,7,1,1,2,-3,-7,-17,15,-16};
                     ^                         Stack ={4,7,1,1,2}  
                                            abs(-3)>2 So pop top  Stack ={4,7,1,1}  
                                            abs(-3)>1 So pop top  Stack ={4,7,1}  
                                            abs(-3)>1 So pop top  Stack ={4,7} 
                                            abs(-3)>7 False  Stack ={4,7} 

   Arr = {4,7,1,1,2,-3,-7,-17,15,-16};
                        ^                        Stack ={4,7}                                                                                          

   Arr = {4,7,1,1,2,-3,-7,-17,15,-16};
                        ^                        Stack ={4,7} 
                                            abs(-7)==7 So pop top  Stack ={4}  

   Arr = {4,7,1,1,2,-3,-7,-17,15,-16};
                           ^                     Stack ={4} 
                                            abs(-17)>4 So pop top  Stack ={} 
                                            Insert -17 in Stack {-17}

   Arr = {4,7,1,1,2,-3,-7,-17,15,-16};
                              ^                  Stack ={-17} 
                                            abs(15)>-17 False  Stack ={-17} 

   Arr = {4,7,1,1,2,-3,-7,-17,15,-16};
                                   ^             Stack ={-17} 
                                            abs(-16)>-17 False  Stack ={-17}
                                            St.top()<0 So insert  Stack ={-17,-16}  
   
   Non Pop All from Stack and Reverse and send as ANS                                         
                                                                                                                                                                                                                                                                                        
*/

void findAsteriod_that_Survived(vector<int> Arr,vector<int>& Ans)
{
    cout << __FUNCTION__ << endl;
    stack<int> St;
    int n = Arr.size();
    for(int i=0;i<n;i++)
    {

        if(Arr[i]>0)
            St.push(Arr[i]);
        else
        {
            while(!St.empty() && St.top()>0 && St.top()<abs(Arr[i]))
                St.pop();

            if(!St.empty() && abs(Arr[i])==St.top())
                St.pop();

            else if(St.empty()|| (!St.empty() && St.top()<0))
                St.push(Arr[i]);

        }

    }
    while(!St.empty())
    {
        Ans.push_back(St.top());
        St.pop();
    }
    reverse(Ans.begin(),Ans.end());
}

int main()
{
    vector<int> Arr = {4,7,1,1,2,-3,-7,-17,15,-16};

    vector<int> Ans;
    findAsteriod_that_Survived(Arr,Ans);

    cout << "Asteriod Collision Survived Arr " << endl;
    print_1D_v(Ans);
    return 0;
}
