#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
    Given Array as  {1,0,1,0,1}
                    {1,0,1,1,1}
                    {1,1,1,1,1}
                    {1,0,0,1,0}

    In this Max Rectangle Area is length {1,2} to {1,4}  {1,1,1}
                                Breadth {2,2} to {2,4}   {1,1,1}


                                Area = 3*2 = 6
    This Problem can be imagined as Histogram Rectangle
    eg consider at row 2
                    {1,0,1,0,1}              1   1    1
                    {1,0,1,1,1}              1   1 1  1
                    {1,1,1,1,1}     Height   1 1 1 1  1
                    ------------- Base Line  ----------
                    {1,0,0,1,0}             {3,1,3,2,3}

      Heights as    {3,1,3,2,3}

      Find NSE and PSE and Can solve to find min Area
                {3, 1, 3, 2, 3}
        NSE      1  5  3  5  5
        PSE     -1 -1  1  1  3
diff NSE-PSE-1 = 1  5  1  3  1
 arr[i]*diff   = 3  5  3  6  5

 Hence Max Area = 6

 This needs to be done for all the Rows

*/

void print_1D_int_array(vector<int> v)
{
    for(auto d:v)
    {
        cout << d << " ";
    }
    cout << endl;
}

void print_2D_int_array(vector<vector<int>> v)
{
    cout << endl;
    for(auto d:v)
    {
        print_1D_int_array(d);
    }
    cout << "\n" << endl;
}

void convert1sToHeight(vector<vector<int>> Arr_2D,vector<vector<int>>& Height_2D)
{
    int n = Arr_2D.size(); // rows
    int m = Arr_2D[0].size(); // Cols

    for(int j=0;j<m;j++)
    {
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            //cout << "i=" << i << endl;
            sum+=Arr_2D[i][j];
            if(Arr_2D[i][j]==0)
                sum = 0;
            //cout << "sum=" << sum << endl;
            Height_2D[i][j] = sum;
        }

    }
    print_2D_int_array(Height_2D);

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
        maxArea = max(Area,maxArea);
    }
    return maxArea;
}

int main()
{
    vector<vector<int>> Arr_2D = {  {1,0,1,0,1},
                                    {1,0,1,1,1},
                                    {1,1,1,1,1},
                                    {1,0,0,1,0}
                                };
    int n = Arr_2D.size(); // rows
    int m = Arr_2D[0].size(); // Cols
    vector<vector<int>> Height_2D(n,vector<int>(m,0));
    convert1sToHeight(Arr_2D,Height_2D);

    int maxArea=-1e9;
    for(int i=0;i<n;i++)
    {
        maxArea = max(maxArea,findMax_Area_Rect_Sol3(Height_2D[i]));
    }

    cout << "Maximal Area =" << maxArea << endl;
    return 0;
}
