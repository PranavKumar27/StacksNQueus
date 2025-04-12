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
                 Read from End i.e. 2*n-1 till 0 , if n=5 then i = 9 i.e 2*5-1
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

// TC -> O(N^2)
// SC -> O(N) for NGE Array
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

// TC -> O(N^2)
// SC -> O(N) for NGE Array
void find_NGE_Sol2(vector<int> Arr,vector<int>& NGE)
{
    int n = Arr.size();
    for(int i=0;i<n;i++)
    {
        NGE[i]=-1;
        for(int j=i+1;j<=i+n-1;j++)
        {
            int idx = j%n;
            if(Arr[idx]>Arr[i])
            {
                NGE[i]=Arr[idx];
                break;
            }
        }
    }
}

// TC -> O(2N)+O(2N) ~~ O(4N) or O(N)
// TC -> O(N)+O(N) for stack and NGE Array
void find_NGE_Sol3(vector<int> Arr,vector<int>& NGE)
{
    int n = Arr.size();
    stack<int> St;
    for(int i=2*n-1;i>=0;i--)
    {
        int idx = i%n;
        while(!St.empty() && St.top()<=Arr[idx])
        {
            St.pop();
        }

        if(i<n)
        {
            NGE[i]=(!St.empty())?St.top():-1;
        }
        St.push(Arr[idx]);
    }
}

int main()
{
    cout << "Next Greater Element 2" << endl;
    vector<int> Arr ={2,10,12,1,11};
    int n = Arr.size();
    vector<int> NGE_1(n);

    cout << "Arr" << endl;
    print_1D_v(Arr);
    cout << "Using Sol1" << endl;
    find_NGE_Sol1(Arr,NGE_1);
    print_1D_v(NGE_1);

    cout << "Using Sol2" << endl;
    vector<int> NGE_2(n);
    find_NGE_Sol2(Arr,NGE_2);
    print_1D_v(NGE_2);


    cout << "Using Sol3" << endl;
    vector<int> NGE_3(n);
    find_NGE_Sol3(Arr,NGE_3);
    print_1D_v(NGE_3);

    return 0;
}
