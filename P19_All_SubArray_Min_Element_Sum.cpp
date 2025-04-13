#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;


// Find All the possible subArrays
// In each SubArray Find min val
// Sum all the min vals


void print_1D_v(vector<int> v)
{
    for(auto d:v)
        cout << d << " , ";
    cout << endl;
}

void findAllSubArray(vector<int> Arr,vector<vector<int>>& AllSubArray)
{
    int n = Arr.size();

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            vector<int> temp;
            for(int k=i;k<=j;k++)
            {
                temp.push_back(Arr[k]);
            }
            print_1D_v(temp);
            AllSubArray.push_back(temp);
        }

    }
    cout << "Size=" << AllSubArray.size() << endl;
}

int findAllSubArray_Min_Sum_Sol1(vector<int> Arr)
{
    vector<vector<int>> AllSubArray;
    findAllSubArray(Arr,AllSubArray);

    int n = AllSubArray.size();
    cout << "n=" << endl;
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        if(AllSubArray[i].size()>0)
        {
            print_1D_v(AllSubArray[i]);
            auto itr = min_element(AllSubArray[i].begin(),AllSubArray[i].end());
            cout << "min=" << *itr << endl;
            sum+=*itr;
        }

    }
    return sum;
}

void findNextSmallerEqualElement(vector<int> Arr,vector<int>& NSE)
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

void findPreviousSmallerElement(vector<int> Arr,vector<int>& PSEE)
{
    int n = Arr.size();

    stack<int> St;

    for(int i=n-1;i>=0;--i)
    {
        while(!St.empty() && Arr[St.top()]>Arr[i])
            St.pop();

        PSEE[i] = (!St.empty())?St.top():n;

        St.push(i);
    }
}

int findAllSubArray_Min_Sum_Sol2(vector<int> Arr)
{
    int n = Arr.size();
    int total = 0;
    vector<int> NSE(n,-1),PSE(n,n);
    findNextSmallerEqualElement(Arr,NSE);
    findPreviousSmallerElement(Arr,PSE);
    print_1D_v(NSE);
    print_1D_v(PSE);
    for(int i=0;i<n;i++)
    {
        int left = i-NSE[i];
        int right = PSE[i]-i;
        cout << "left=" << left << " right=" << right << endl;
        total = total + (left*right)*Arr[i];
    }
    return total;
}
int main()
{
    vector<int> Arr ={3,2,1,4};



    int res_1 = findAllSubArray_Min_Sum_Sol1(Arr);
    cout << "findAllSubArray_Min_Sum_Sol1 = " << res_1 << endl;

    int res_2 = findAllSubArray_Min_Sum_Sol2(Arr);
    cout << "findAllSubArray_Min_Sum_Sol2 = " << res_2 << endl;

    return 0;
}
