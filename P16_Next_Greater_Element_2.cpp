#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
    In a Arr = [2,10,12,1,11]
    Find the next greater elements in the cyclic order

    eg:
    arr = [ 2, 10, 12,  1, 11]
    NGE = [10, 12, -1, 11, 12]

    Next Greater Element of 2 is 10
    Next Greater Element of 10 is 12
    Next Greater Element of 12 is -1
    Next Greater Element of 1 is 11
    Next Greater Element of 11 is 12  Since No are like [2 10 12 1 11] [2 10 12  1 11]
                                                                   ^         *
                                                                Arr[i]       NGE

    Technique 1: Move in two Direction Forward from i till end and
                then again start from 0 to i-1
                [2 10 12 1 11]
                      i ----->
                ----->

    Technique 2:Imagine hypothetically Arr is present till N More places from i
                [2 10 12 1 11] [2 10 12  1 11]
                      i-----n------>
                            i------n------>
                We can do idx = i*n and obtain back from Arr

     Technique 3: Use Stack to store top() elements
                 Read from last i.e. 2*n-1 if n=5 then i = 9
                 [2 10 12 1 11] [2 10 12  1 11]
                  0 1  2  3  4   5  6  7  8  9

                  while(St.top()<=Arr[i%n]) // Step 1
                    St.pop()

                  if(i<n)                   // Step 2
                    NGE[i] = St.top() or -1

                  St.push(Arr[i])           // Step 3

*/


void print_1D_v(vector<int> v)
{
    for(auto d:v)
        cout << d << ",";
    cout << endl;
}

void find_NGE_Sol1(vector<int> Arr,vector<int>& NGE)
{
    int n = Arr.size();

    for(int i=0;i<n;i++)
    {
        NGE[i]=-1;
        for(int j=i+1;j<n;j++)
        {
            if(Arr[j]>Arr[i])
            {
                NGE[i]=Arr[j];
                break;
            }
        }

        for(int j=0;j<i;j++)
        {
            if(Arr[j]>Arr[i])
            {
                NGE[i]=Arr[j];
                break;
            }
        }
    }
    return;

}

int main()
{
    cout << "Next Greater Element 2" << endl;
    vector<int> Arr ={2,10,12,1,11};
    int n = Arr.size();
    vector<int> NGE_1(n);

    find_NGE_Sol1(Arr,NGE_1);
    print_1D_v(NGE_1);

    return 0;
}
