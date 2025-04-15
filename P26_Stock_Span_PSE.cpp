#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
    Find Maximum Consective Days for which Stock Price
    was less than or equal to the current day Value

    Eg : 7, 2 , 1 , 3 ,3, 1 ,8
    At              ^
                    3<=3
                1<=3
            2<=3
        7<=3 -False

    Hence Ans  = 3  Stock Prices as {2,1,3}
*/
void print_1D_v(vector<int> v)
{
    for(auto d:v)
        cout << d << ",";
    cout << endl;
}

// TC --> O(N*N)
// Sc --> O(N) for Ans
void findIncPriConsecutiveDays_Sol1(vector<int> Arr,vector<int>& Consecutive_Days)
{
    int n = Arr.size();

    for(int i=0;i<n;i++)
    {
        int cnt = 0;
        for(int j=i;j>=0;j--)
        {
            if(Arr[i] >= Arr[j])
                cnt++;
            else
                break;
        }
        Consecutive_Days.push_back(cnt);
    }
}


// Previous Smaller Element
void findPSE(vector<int> Arr,vector<int>& PSE)
{
    int n = Arr.size();
    stack<int> St;

    for(int i=0;i<n;i++)
    {
        while(!St.empty() && Arr[St.top()]<=Arr[i])
            St.pop();

        PSE[i] = (!St.empty())?St.top():-1;

        St.push(i);
    }
}
// TC -> O(2N)
// SC -> O(N) for Ans + O(N) for PSE + O(N) for stack
void findIncPriConsecutiveDays_Sol2(vector<int> Arr,vector<int>& Consecutive_Days)
{
    int n = Arr.size();
    vector<int> PSE(n);
    findPSE(Arr,PSE); // Previous Smaller Element

    for(int i=0;i<n;i++)
    {
        int days = i-PSE[i];
        Consecutive_Days.push_back(days);
    }
}

int main()
{
    vector<int> Arr = {7,2,1,3,3,1,8};
    vector<int> Consecutive_Days1;
    findIncPriConsecutiveDays_Sol1(Arr,Consecutive_Days1);
    cout << "Using Sol 1" << endl;
    print_1D_v(Consecutive_Days1);

    vector<int> Consecutive_Days2;
    findIncPriConsecutiveDays_Sol2(Arr,Consecutive_Days2);
    cout << "Using Sol 2" << endl;
    print_1D_v(Consecutive_Days2);



    return 0;
}
