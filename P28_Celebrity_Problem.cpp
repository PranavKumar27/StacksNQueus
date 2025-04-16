#include <iostream>
#include <vector>

using namespace std;

/*
    Celebrity Problem
        ARR = {0,1,1,0}
              {0,0,0,0}
              {0,1,0,0}
              {1,1,0,0}
    A celeb is a person who knows NoOne and Everybody Knows him/her
    In above Arr
    0 don't know 0 - Invalid
    0 knows 1
    0 knows 2
    0 don't know 3

    1 don't know 0
    1 don't know 1  - Invalid
    1 don't know 2
    1 don't know 3

    2 don't know 0
    2 knows 1
    2 don't know 2 - Invalid
    2 don't know 3

    3 knowns 0
    3 knows 1
    3 don't know 2
    3 don't know 3   - Invalid

    Hence 1 is the celebrity

    At end we see two Arayas

    KnownMe[] = {1,3,1,0}
    I_Know[]= {2,0,1,2}

    KnowMe[i]= 3 and I_Know[i] = 0 for i=1 Hence 1 is Celebrity

    Technique 1:
    This Can be solved using Array Traversal
    where we build two Arrays KnowMe & I_Know

    Once Made Check the value in Array as
    KnowMe[i]= 3 and I_Know[i] = 0
    The particular i will be the ans

    Technique 2:
    Traverse with two indexes top_row and bottom_row
    Find the row such if Arr[3][0]=1 and Arr[0][3]=0
    3 know 0
    but
    0 don't know 3
    Hence update bottom_row (decr)

    Here if Arr[2][0]=0 and Arr[0][2]=1
    2 don't know 0
    but
    0 know 2
    Hence update top_row (incr)

    Arr[2][1]=1 and Arr[1][2]=0
    2 know 1
    but
    1 Don't know 2
    Hence update bottom_row (decr)

    Now both top_row & bottom_row are at same row.
    Here Check all value of this row = 1 is 0
    &
    Check the vertical Sum of Arr[idx][1] = N-1 (All Knowns Celeb execpt themselves)

*/

// TC -> O(N*N)
// SC -> O(2N)
int findCeleberity_Sol1(vector<vector<int>>& Arr)
{
    int n=Arr.size();
    vector<int> I_Know(n);
    vector<int> Knows_Me(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(Arr[i][j]==1)
            {
                I_Know[i]++;
                Knows_Me[j]++;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        if(I_Know[i]==0 && Knows_Me[i]==n-1)
            return i;
    }

    return -1;
}
// TC -> O(2*N)
// SC -> O(1)
int findCeleberity_Sol2(vector<vector<int>>& Arr)
{
    int n = Arr.size();
    int top = 0 , bottom = n-1;
    while(top<bottom)
    {
        if(Arr[top][bottom]==1)
            top++;
        else if(Arr[bottom][top]==1)
            bottom--;
        else
        {
            top++;
            bottom--;
        }
    }
    if(top==bottom)
    {
        // Verify Row All Elements should be ), Celeb Knows NO-ONE
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(i==top)
                continue;
            if(Arr[top][i]==0 || Arr[i][top]==1)
                continue;
            else
                return -1;
        }
        return top;
    }

    return -1;
}

int main()
{
    vector<vector<int>> Arr =  {{0,1,1,0},
                                {0,0,0,0},
                                {0,1,0,0},
                                {1,1,0,0}};

    int ans = findCeleberity_Sol1(Arr);

    cout << "findCeleberity_Sol1 at row=" << ans << endl;

    int ans_2 = findCeleberity_Sol2(Arr);

    cout << "findCeleberity_Sol2 at row=" << ans_2 << endl;
    return 0;
}
