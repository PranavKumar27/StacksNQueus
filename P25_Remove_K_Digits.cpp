#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

void print_1D_int_array(vector<int> v)
{
    for(auto d:v)
    {
        cout << d << " ";
    }
    cout << endl;
}
// TC --> O(3N) + O(K)
// SC -> O(N) for stack + O(N) for Res

string removeKElements(vector<int> Arr,int K)
{
    stack<int> St;
    string res="";
    int n = Arr.size();
    for(int i=0;i<n;i++) //O(N)
    {

        while(K>0 && !St.empty()&& St.top()>Arr[i])  // O(k)
        {
            St.pop();
            K--;
        }
        St.push(Arr[i]); // SC -O(N)
    }
    while(K>0 && !St.empty())
    {
        St.pop();
        K--;
    }
    if(St.empty())
        return "0";
    while(!St.empty()) // O(N)
    {
        res+=to_string(St.top());
        St.pop();
    }
    cout << "res=" << res << endl;
    while(res.size()>0 && res.back()=='0')  // TC O(N)
        res.pop_back();
    reverse(res.begin(),res.end());
    return res;
}
int main()
{
    string str = "01432219";

    int sz = str.size();
    long n = stoi(str);
    cout << "n=" << n << endl;
    vector<int> Arr;
    while(n>0)
    {
        int val = n%10;
        Arr.push_back(val);
        n=n/10;
    }


    reverse(Arr.begin(),Arr.end());
    print_1D_int_array(Arr);

    int K = 3;
    string Ans = removeKElements(Arr,K);

    cout << "After removeKElements =" << Ans << endl;
    return 0;
}
