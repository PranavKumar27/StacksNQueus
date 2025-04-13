#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Find sum of difference of Max - Min of all the sub Arrays Possible

// TC --> O(N*N)
// SC --> O(1)
int findSubArray_RangeSum_Sol1(vector<int> Arr)
{
    int n = Arr.size();
    int total = 0;
    for(int i=0;i<n;i++)
    {
        cout << "-------------------------" << endl;
        int maxi = Arr[i],mini=Arr[i];
        cout << "Before maxi=" << maxi << " mini=" << mini << endl;
        for(int j=i+1;j<n;j++)
        {
            if(maxi<Arr[j])
                maxi=Arr[j];
            if(mini>Arr[j])
                mini = Arr[j];

            total = total + maxi - mini;
            cout << "After maxi=" << maxi << " mini=" << mini << endl;
        }
        cout << "-------------------------" << endl;

    }
    return total;
}

void Obtain_NSE(vector<int> Arr,vector<int>& NSE)
{
    int n = Arr.size();
    stack<int> St;
    for(int i=0;i<n;i++)
    {
        while(!St.empty() && Arr[St.top()]>=Arr[i])
            St.pop();

        NSE[i] = (!St.empty())?St.top():-1;

        St.push(i);
    }
}

void Obtain_NGE(vector<int> Arr,vector<int>& NGE)
{
    int n = Arr.size();
    stack<int> St;
    for(int i=0;i<n;i++)
    {
        while(!St.empty() && Arr[St.top()]<=Arr[i])
            St.pop();

        NGE[i] = (!St.empty())?St.top():-1;

        St.push(i);
    }
}

void Obtain_PSE(vector<int> Arr,vector<int>& PSE)
{
    int n = Arr.size();
    stack<int> St;
    for(int i=n-1;i>=0;i--)
    {
        while(!St.empty() && Arr[St.top()]>Arr[i])
            St.pop();

        PSE[i] = (!St.empty())?St.top():n;

        St.push(i);
    }
}

void Obtain_PGE(vector<int> Arr,vector<int>& PGE)
{
    int n = Arr.size();
    stack<int> St;
    for(int i=n-1;i>=0;i--)
    {
        while(!St.empty() && Arr[St.top()]<Arr[i])
            St.pop();

        PGE[i] = (!St.empty())?St.top():n;

        St.push(i);
    }
}
int findSubArray_RangeSum_Sol2(vector<int> Arr)
{
    // We have already done change to find Sum of Min Elements in All SubArrays Using stack
    // We used NSE and PSE
    // Similarly Now we need NGE and PGE
    // Sum All Mins in Sub Array and Sum All Max in Sub Array and then Subtract Max-Min

    int n = Arr.size();
    int total = 0;
    vector<int> NSE(n,-1),PSE(n,n),NGE(n,-1),PGE(n,n);
    Obtain_NGE(Arr,NGE);
    Obtain_PGE(Arr,PGE);
    Obtain_NSE(Arr,NSE);
    Obtain_PSE(Arr,PSE);

    for(int i=0;i<n;i++)
    {
        int Sleft = i-NSE[i];
        int Sright = PSE[i]-i;

        int Gleft = i-NGE[i];
        int Gright = PGE[i]-i;

        total = total + ( (Gleft*Gright)*Arr[i] - (Sleft*Sright)*Arr[i]);

    }
    return total;

}


int main()
{
    vector<int> Arr = {1,4,3,2};

    int SubArray_RangeSum = findSubArray_RangeSum_Sol1(Arr);
    cout << "SubArray_RangeSum Using Sol 1=" << SubArray_RangeSum << endl;


    int SubArray_RangeSum_2 = findSubArray_RangeSum_Sol2(Arr);
    cout << "SubArray_RangeSum Using Sol 2=" << SubArray_RangeSum_2 << endl;
    return 0;
}
