#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
    Find Next Smaller Element (i.e. Smaller element on the left)
    Arr = [ 4  5  2  10  8 ]
            ^
            -1

    Arr = [ 4  5  2  10  8 ]
               ^
               4 (4<5)

    Arr = [ 4  5  2  10  8 ]
                  ^
                  -1

    Arr = [ 4  5  2  10  8 ]
                     ^
                     2 (2<10)

    Arr = [ 4  5  2  10  8 ]
                      ^
                        (10<8)
                  ^     (2<8)

     Arr = [ 4  5  2  10  8 ]
     NSE = [-1  4  -1  2  2 ]

     Technique 1: Using for loop
                [ 4  5  2  10  8 ]
                            ^
                  <---------   Go from j to i to 0 and
                               check if Arr[j]<Arr[i]
                               and then update NSE and break

     Technique 2: Using Monotonic Stack to store elements in decreasing order
                [ 4  5  2  10  8 ]
                  ^
        NSE[i] = -1                          St = {4}

                [ 4  5  2  10  8 ]
                     ^
                    St.top()<5
        NSE[i] = 4                         St = {4,5}

                [ 4  5  2  10  8 ]
                        ^
                    St.top()<2 -> False     St = {4,5} Pop Top
                    St.top()<2 -> False     St = {4} Pop Top
                                            St = {}  Pop Top

        NSE[i] = -1                         St = {2}

                       [ 4  5  2  10  8 ]
                                  ^
                    St.top()<10 -> True     St = {2}


        NSE[i] = 2                         St = {2,10}

                        [ 4  5  2  10  8 ]
                                       ^
                    St.top()<8 -> False     St = {2,10}  Pop Top
                    St.top()<8 -> True     St = {2}

        NSE[i] = 2                         St = {2,8}

        NSE[i] = [-1 4 -1 2 2]

*/

void print_1D_v(vector<int> v)
{
    for(auto d:v)
        cout << d << ",";
    cout << endl;
}

// TC --> O(N^2)
// SC -> O(N)
void findNextSmallerElement_Sol1(vector<int> Arr,vector<int>& NSE)
{
    int n = Arr.size();

    for(int i=0;i<n;i++)
    {
        NSE[i]=-1;
        for(int j=i-1;j>=0;j--)
        {
            if(Arr[j]<Arr[i])
            {
                NSE[i]=Arr[j];
                break;
            }
        }
    }
}

// TC --> O(2N) for pop N Max Element and N for loop
// SC -> O(N)+O(N) for stack and NSE Array
void findNextSmallerElement_Sol2(vector<int> Arr,vector<int>& NSE)
{
    int n = Arr.size();
    stack<int> St;
    for(int i=0;i<n;i++)
    {
        while(!St.empty() && St.top()>Arr[i])
            St.pop();

        NSE[i] = (!St.empty())?St.top():-1;

        St.push(Arr[i]);
    }
}
int main()
{
    cout << "Next Smaller Element " << endl;
    vector<int> Arr ={4 , 5, 2, 10, 8};
    int n = Arr.size();
    vector<int> NSE_1(n);

    cout << "Arr" << endl;
    print_1D_v(Arr);
    cout << "Using Sol1" << endl;
    findNextSmallerElement_Sol1(Arr,NSE_1);
    print_1D_v(NSE_1);

    cout << "Using Sol2" << endl;
    vector<int> NSE_2(n);
    findNextSmallerElement_Sol2(Arr,NSE_2);
    print_1D_v(NSE_2);
    return 0;
}
