#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void print_1D_v(vector<int> v)
{
    for(auto d:v)
        cout << d << ",";
    cout << endl;
}

int findMax_Area_Rect_Sol1(vector<int>& Arr)
{
   int n = Arr.size();

   int maxArea=-1e9;
   for(int i=0;i<n;i++)
   {
       int l=Arr[i],b=1;
       for(int j=i+1;j<n+i+1;j++)
       {
           int idx = j%n;
           if(l>=Arr[idx]||j==n+i)
           {
               int new_Area = l*b;
               if(new_Area>maxArea)
                    maxArea = new_Area;
           }
           else
            b++;
       }
   }
   return maxArea;
}

vector<int> findNSE(vector<int>& Arr)
{
    int n = Arr.size();
    vector<int> NSE(n);
    stack<int> St;

    for(int i=n-1;i>=0;i--) // Defaulted to n
    {
        while(!St.empty() && Arr[St.top()]>Arr[i])
            St.pop();
        NSE[i] = (!St.empty())?St.top():n;
        St.push(i);
    }
    return NSE;
}

vector<int> findPSE(vector<int>& Arr)
{
    int n = Arr.size();
    vector<int> PSE(n);
    stack<int> St;

    for(int i=0;i<n;i++) // Default to -1
    {
        while(!St.empty() && Arr[St.top()]>Arr[i])
            St.pop();
        PSE[i]=(!St.empty())?St.top():-1;
        St.push(i);
    }
    return PSE;
}


int findMax_Area_Rect_Sol2(vector<int>& Arr)
{
    int n = Arr.size();
    vector<int> NSE = findNSE(Arr);
    vector<int> PSE = findPSE(Arr);

    print_1D_v(NSE);
    print_1D_v(PSE);
    int maxi = -1e9;
    for(int i=0;i<n;i++)
    {
        int length = Arr[i];
        int breadth = NSE[i]-PSE[i]-1;
        cout << "length=" << length << " breadth=" << breadth << endl;
        maxi = max(maxi,length*breadth);
    }
    return maxi;
}

int findMax_Area_Rect_Sol3(vector<int>& Arr)
{
    int n = Arr.size();
    stack<int> St;
    int maxArea = -1e9;
    for(int i=0;i<n;i++)
    {
        while(!St.empty() && Arr[St.top()]>Arr[i])
        {
            // Arr[i] is the nse of Arr[St.top()]
            // Arr[St.top()-1] is the pse of Arr[St.top()]
            int nse = i;
            int element = Arr[St.top()];
            St.pop();
            int pse = (!St.empty())?St.top():-1;
            int Area = (nse - pse -1)*element;
            cout << "Area in For " << Area << endl;
            maxArea = max(Area,maxArea);
        }
        St.push(i);
    }

    while(!St.empty())
    {
        int nse = n;
        int element = Arr[St.top()];
        St.pop();
        int pse = (!St.empty())?St.top():-1;
        int Area = (nse - pse -1)*element;
        cout << "Area in While " << Area << endl;
        maxArea = max(Area,maxArea);
    }
    return maxArea;
}
int main()
{
    vector<int> Arr = {3,2,10,11,5,10,6,3};

    int ans_1 = findMax_Area_Rect_Sol1(Arr);
    cout << "Max_Area_Rect Sol1=" << ans_1 << endl;

    int ans_2 = findMax_Area_Rect_Sol2(Arr);
    cout << "Max_Area_Rect Sol2=" << ans_2 << endl;

    int ans_3 = findMax_Area_Rect_Sol3(Arr);
    cout << "Max_Area_Rect Sol3=" << ans_3 << endl;
    return 0;
}
