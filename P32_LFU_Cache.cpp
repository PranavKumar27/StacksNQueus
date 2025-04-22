#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Node
{
public:
    int key,val,cnt; // cnt will be freq
    Node* left;
    Node* right;

    Node(int k,int v)
    {
        key=k;
        val=v;
        cnt = 1;
        left=nullptr;
        right=nullptr;
    }
};

class NodeList
{
public:
    Node* head;
    Node* tail;
    int sz;
    NodeList()
    {
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->right = tail;
        tail->left = head;
        sz=0;
    }
    void addNode(Node* node)
    {
        cout << "Node=" << node << endl;
        // Insert At Front
        Node* nextNode = head->right;
        cout << "nextNode=" << nextNode << endl;
        head->right = node;
        cout << "head->right=" << head->right << endl;
        node->left = head;
        cout << "node->left=" << node->left << endl;

        node->right = nextNode;
        cout << "node->right=" << node->right << endl;

        nextNode->left = node;
        cout << "nextNode->left =" << nextNode->left  << endl;
        sz++;

    }

    void deleteNode(Node* node)
    {
        Node* Next = node->right;
        Node* Prev = node->left;

        Prev->right = Next;
        Next->left = Prev;
        sz--;
    }
};

class LFU
{
    int cap;
    NodeList* lst;
    unordered_map<int,Node*> Cache_Map;
    map<int,NodeList*> FreqListMap;
    int Min_freq;
    int Cur_size;
public:
    LFU(int capacity)
    {
        cap=capacity;
        Min_freq = 0;
        Cur_size=0;
    }
    int get(int key)
    {
        if(Cache_Map.find(key)!=Cache_Map.end())
        {
           Node* node = Cache_Map[key];
           int val = node->val;
           UpdateFreq(node);
           return val;
        }
        else
            return -1;
    }

    void put(int key,int val)
    {
        if(cap==0)
        {
            cout << "No capacity" << endl;
            return;
        }

        if(Cache_Map.find(key)!=Cache_Map.end())
        {
            Node* node = Cache_Map[key];
            node->val = val;
            UpdateFreq(node);
        }
        else
        {
            if(Cur_size == cap)
            {
                NodeList* New_Node_List = FreqListMap[Min_freq];
                Cache_Map.erase(New_Node_List->tail->left->key);
                FreqListMap[Min_freq]->deleteNode(New_Node_List->tail->left);
                Cur_size--;
            }
            Cur_size++;
            /// Add new value at Min Freq
            Min_freq = 1;
            NodeList* NodeLst = new NodeList();
            if(FreqListMap.find(Min_freq)!=FreqListMap.end())
            {
                NodeLst = FreqListMap[Min_freq];
            }
            Node* newNode = new Node(key,val);
            //newNode->cnt = Min_freq;
            NodeLst->addNode(newNode);
            Cache_Map[key] = newNode;
            FreqListMap[Min_freq] = NodeLst;

        }
    }
    int UpdateFreq(Node* node)
    {
        Cache_Map.erase(node->key);
        FreqListMap[node->cnt]->deleteNode(node);

        if(node->cnt == Min_freq && FreqListMap[node->cnt]->sz==0)
            Min_freq++; // Remove old Freq Possible

        NodeList* NextHigherList = new NodeList();
        if(FreqListMap.find(node->cnt+1)!=FreqListMap.end())
        {
            NextHigherList = FreqListMap[node->cnt+1];
        }

        (node->cnt)++;
        NextHigherList->addNode(node);
        FreqListMap[node->cnt] = NextHigherList;
        Cache_Map[node->key] = node;

    }
    void print_NodeList()
    {
        cout << __FUNCTION__ << endl;
        for(auto f:FreqListMap)
        {
            int freq = f.first;
            cout << "freq=" << freq << " -->";
            NodeList* All = f.second;
            Node* start = All->head->right;
            while(start!=All->tail)
            {
                cout << "key=" << start->key << " val=" << start->val << " , ";
                //cout << "IN start=" << start << endl;
                //cout << "IN start->right=" << start->right << endl;
                start = start->right;
            }
            cout << endl;
            //cout << "start=" << start << endl;
            //cout << "start->right=" << start->right << endl;

        }
    }
};

int main()
{
    LFU Cache(3);
    int input;

    do
    {
        cout << "\nInput 1 to push Data, 2 to get Data 3 to Stop," << endl;
        cin >> input;
        int key,val;
        switch(input)
        {
            case 1:
                    cout << "Enter key " << endl;
                    cin >> key;
                    cout << "Enter value " << endl;
                    cin >> val;
                    Cache.put(key,val);
                    Cache.print_NodeList();
                    break;
            case 2:
                    cout << "Enter key " << endl;
                    cin >> key;
                    val = Cache.get(key);
                    cout << "val=" << val << endl;
                    Cache.print_NodeList();
                    break;
            case 3:return 0;
            default:break;

        }


    }while(input!=0);
    return 0;
}
