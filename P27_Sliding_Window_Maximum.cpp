#include <iostream>
#include <vector>
#include <deque>

using namespace std;

/*
    A window of Size K
    Find Maximum Value in Each windows
*/

void print_1D_v(vector<int> v)
{
    for(auto d:v)
        cout << d << ",";
    cout << endl;
}

// TC --> O(N*N)
// SC ->O(N)
void findMaxSlidingWindow_Sol1(vector<int>& Arr,vector<int>& Ans,int K)
{
    cout << __FUNCTION__ << endl;
    int n = Arr.size();
    for(int i=0;i<=n-K;i++)
    {
        int maxi = -1e9;
        for(int j=i;j<i+K;j++)
        {
            maxi = max(maxi,Arr[j]);
        }
        Ans.push_back(maxi);
    }
}

// TC --> O(2N)
// SC ->O(K) + O(N-k) for stack
void findMaxSlidingWindow_Sol2(vector<int>& Arr,vector<int>& Ans,int K)
{
    int n = Arr.size();
    deque<int> dq;
    for(int i=0;i<n;i++)
    {
        while(!dq.empty() && Arr[dq.back()]<=Arr[i])
            dq.pop_back();

        if(!dq.empty() && dq.front()<=i-K)
            dq.pop_front();


        dq.push_back(i);

        if(i>=K-1)
        {
            int val = Arr[dq.front()];
            Ans.push_back(val);
        }
    }
}

int main()
{
    cout << "Maximum Siding Window" << endl;
    vector<int> Arr = {1,3,-1,-3,5,3,2,1,6};
    int n = Arr.size();
    int K=3;
    vector<int> Ans1,Ans2;
    findMaxSlidingWindow_Sol1(Arr,Ans1,K);
    findMaxSlidingWindow_Sol2(Arr,Ans2,K);
    print_1D_v(Ans1);
    print_1D_v(Ans2);

    return 0;
}
