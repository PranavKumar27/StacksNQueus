#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void print_1D_v(vector<int> v)
{
    for(auto d:v)
        cout << d << " , ";
    cout << endl;
}


int find_trapped_Rain_Water_Sol1(vector<int>Arr)
{
    int n = Arr.size();
    vector<int> leftMax(n,-1),RightMax(n,-1);

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(Arr[j]>Arr[i]&& Arr[j]>RightMax[i])
            {
                RightMax[i] = Arr[j];
            }
        }
    }

    for(int i=n-1;i>=0;i--)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(Arr[j]>Arr[i] && Arr[j]>leftMax[i])
            {
                leftMax[i]=Arr[j];
            }
        }
    }

    cout << "Arr=" << endl;
    print_1D_v(Arr);
    cout << "LeftMax=" << endl;
    print_1D_v(leftMax);
    cout << "RightMax=" << endl;
    print_1D_v(RightMax);
    int sum=0;
    for(int i=0;i<n-1;i++)
    {
        if(Arr[i]<leftMax[i] && Arr[i]<RightMax[i])
        {
            //cout << "Inside i=" << i << " Arr[i]=" << Arr[i] << endl;
            //cout << "leftMax[i]=" << leftMax[i] << " RightMax[i]=" << RightMax[i] << endl;
            int mini = min(leftMax[i],RightMax[i]);
            cout << "mini=" << mini << endl;
            cout << "Arr[i]=" << Arr[i] << endl;
            sum+= mini - Arr[i]; // subtract Height of building
        }
    }
    return sum;
}




void LeftPrefixSum(vector<int> Arr,vector<int>& LeftMax)
{
    int n = Arr.size();

    LeftMax.resize(n);
    LeftMax[0]=Arr[0];

    for(int i=1;i<n;i++)
    {
        if(LeftMax[i-1]<Arr[i])
            LeftMax[i]=Arr[i];
        else
            LeftMax[i]=LeftMax[i-1];
    }
    print_1D_v(LeftMax);
}

void RightPrefixSum(vector<int> Arr,vector<int>& RightMax)
{
    int n = Arr.size();

    RightMax.resize(n);
    RightMax[n-1]=Arr[n-1];

    for(int i=n-2;i>=0;i--)
    {
        if(RightMax[i+1]<Arr[i])
            RightMax[i]=Arr[i];
        else
            RightMax[i] = RightMax[i+1];
    }
    print_1D_v(RightMax);
}

// TC --> O(2N) for Left and Right + O(N) for loop
// SC --> O(2N) for two array LeftMax and RightMax
int find_trapped_Rain_Water_Sol2(vector<int>Arr)
{
    int n = Arr.size();
    vector<int> LeftMax,RightMax;
    LeftPrefixSum(Arr,LeftMax);
    RightPrefixSum(Arr,RightMax);

    int total = 0;
    for(int i=0;i<n;i++)
    {
        if(Arr[i]<LeftMax[i] && Arr[i]<RightMax[i])
            total = total + min(LeftMax[i],RightMax[i]) - Arr[i];
    }
    return total;
}

// TC --> O(2N) for Left and Right + O(N) for loop
// SC --> O(N) for RightMax array
int find_trapped_Rain_Water_Sol3(vector<int>Arr)
{
    int n = Arr.size();
    vector<int> RightMax;
    RightPrefixSum(Arr,RightMax);

    int total = 0;
    int LeftMax_So_Far = -1e9;
    for(int i=0;i<n;i++)
    {
        if(Arr[i]>LeftMax_So_Far)
            LeftMax_So_Far = Arr[i];

        if(Arr[i]<LeftMax_So_Far && Arr[i]<RightMax[i])
            total = total + min(LeftMax_So_Far,RightMax[i]) - Arr[i];
    }
    return total;
}

// TC --> O(N)
// SC--> O(1)
int find_trapped_Rain_Water_Sol4(vector<int>Arr)
{
    int n = Arr.size();
    int l=0,r=n-1;
    int leftMax=Arr[l],RightMax=Arr[r];
    int total = 0;
    while(l<r)
    {
        if(Arr[l]<=Arr[r])
        {
            l++;
            if(Arr[l]<leftMax )
                total+=leftMax-Arr[l];
            else
                leftMax = Arr[l];
        }
        else
        {
            r--;
            if(Arr[r]<RightMax)
                total+=RightMax-Arr[r];
            else
                RightMax = Arr[r];
        }
    }
    return total;
}

int main()
{
    vector<int> Hghts = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
    int rain_water_1 = find_trapped_Rain_Water_Sol1(Hghts);
    cout << "Total trapped_Rain_Water Using Sol 1=" << rain_water_1 << endl;

    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
    int rain_water_2 = find_trapped_Rain_Water_Sol2(Hghts);
    cout << "Total trapped_Rain_Water Using Sol2=" << rain_water_2 << endl;
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;


    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
    int rain_water_3 = find_trapped_Rain_Water_Sol3(Hghts);
    cout << "Total trapped_Rain_Water Using Sol3=" << rain_water_3 << endl;
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;

    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
    int rain_water_4 = find_trapped_Rain_Water_Sol4(Hghts);
    cout << "Total trapped_Rain_Water Using Sol4=" << rain_water_4 << endl;
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;



    return 0;
}
