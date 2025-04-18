#include <iostream>
#include <vector>
#include <deque>
#include <map>

using namespace std;

typedef pair<int,int> Pi;
#define MAX_SIZE 4

/*
    Using a Deque Form a LRU Cache
    Least Recently Used - Elements stay last
    Size is fixed
    The last access/inserted Node is at the front of deque
*/
class LRU
{
    deque<Pi> DQ;
    map<int,deque<Pi>::iterator> Mp;
    int sz;
public:
    LRU()
    {
        sz = MAX_SIZE;
    }
    void put(int key,int val)
    {
        if(DQ.size()<sz)
        {
            DQ.push_front({key,val});
            deque<Pi>::iterator addr = DQ.begin();
            Mp.insert({key,addr});
        }
        else
        {
            DQ.pop_back();
            DQ.push_front({key,val});
        }
    }
    int get(int key)
    {
        auto itr = Mp.find(key);
        if(itr==Mp.end())
        {
            cout << "Key Not Found=" << key << endl;
            return -1;
        }
        else
        {
            deque<Pi>::iterator addr = Mp[key];
            int val = addr->second;
            DQ.erase(addr);
            cout << "Key Asked=" << key << endl;
            cout << "Val Found=" << (addr->second) << endl;
            // Move to front via insert
            put(key,val);
            return val;
        }


    }
    void print_DeQue()
    {
        for (const auto element : DQ) {
            cout << "(" << element.first << ", " << (element.second) << ") ";
        }
    }
};
int main()
{
    cout << "LRU Cache Least Recently Used at last" << endl;
    LRU Cache;
    int input;
    do
    {
        cout << "\nInput 1 to push Data, 2 to get Data 3 to Stop," << endl;
        cin >> input;

        switch(input)
        {
            case 1: int key,val;
                    cout << "Enter key " << endl;
                    cin >> key;
                    cout << "Enter value " << endl;
                    cin >> val;
                    Cache.put(key,val);
                    Cache.print_DeQue();
                    break;
            case 2:
                    cout << "Enter key " << endl;
                    cin >> key;
                    val = Cache.get(key);
                    cout << "val=" << val << endl;
                    Cache.print_DeQue();
                    break;
            case 3:return 0;
            default:break;

        }


    }while(input!=0);

    return 0;
}
