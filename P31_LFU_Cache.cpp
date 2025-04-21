#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Node
{
public:
    int key,val;
    Node* left;
    Node* right;

    Node(int k,int v)
    {
        key=k;
        val=v;
        left=nullptr;
        right=nullptr;
    }
};

class NodeList
{
public:
    Node* head;
    Node* tail;
    NodeList()
    {
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->right = tail;
        tail->left = head;
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

    }

    void deleteNode(Node* node)
    {
        Node* Next = node->right;
        Node* Prev = node->left;

        Prev->right = Next;
        Next->left = Prev;
    }
};

class LFU
{
    int cap;
    NodeList* lst;
    unordered_map<int,Node*> Cache_Map;
    map<int,NodeList*> Freq;
public:
    LFU(int capacity)
    {
        cap=capacity;
    }
    int get(int key)
    {
        if(Cache_Map.find(key)!=Cache_Map.end())
        {
           Node* node = Cache_Map[key];
           UpdateFreq(node);
           return node->val;
        }
        else
            return -1;
    }

    void put(int key,int val)
    {
        if(Cache_Map.find(key)!=Cache_Map.end())
        {
            Node* node = Cache_Map[key];
            node->val = val;
            UpdateFreq(node);
        }

        int minFreq = 1; // Min Freq when element is to be inserted first time
        Node* newNode = new Node(key,val);
        UpdateFreq(newNode);
        Cache_Map[key] = newNode;
        if(Freq.find(minFreq)==Freq.end())
        {
            NodeList* All = new NodeList();
            All->addNode(newNode);
            Freq[minFreq] = All;
        }
        else
        {
            NodeList* All = Freq[minFreq];
            All->addNode(newNode);
            print_NodeList();
            cout << "Added in lst" << endl;
        }
        NodeList* All = Freq[minFreq];
        cout << "All->head=" << All->head << endl;
        cout << "All->head->right=" << All->head->right << endl;
        cout << "All->tail=" << All->tail << endl;
        cout << "All->tail->left=" << All->tail->left << endl;
        cout << "All->tail->right=" << All->tail->right << endl;


        if(Cache_Map.size()>cap)
        {
            // Remove before to tail
            minFreq = findMinFreqInLst(lst);
            if(minFreq!=-1)
            {
                NodeList* newLst = Freq[minFreq]; // Remove From Min Freq
                Node* node = newLst->tail->left; // Removing the LRU
                Cache_Map.erase(node->key);
                newLst->deleteNode(node);
            }
            else
            {
                // No data here
            }

        }
    }
    int findMinFreqInLst(NodeList* Lst)
    {
        int minfreq=-1;
        for(auto f:Freq)
        {
            minfreq = f.first;
            break;
        }
        return minfreq;
    }
    void UpdateFreq(Node* node)
    {
        bool IsFound = false;
        for(auto f:Freq)
        {
            NodeList* newList = f.second;
            Node* tailNode = newList->tail;
            Node* temp = newList->head;
            if(temp!=tailNode)
            {
                if(temp->key == node->key)
                {
                    IsFound = true;
                    break;
                }
                temp=temp->right;
            }
            if(IsFound) // For Updates
            {
                newList->deleteNode(temp);
                int nfreq = f.first+1;

                if(Freq.find(nfreq)!=Freq.end())
                {
                    NodeList* NewFreqList = Freq[nfreq];
                    NewFreqList->addNode(temp);
                }
                else
                {
                    NodeList* NewFreqList = new NodeList();
                    NewFreqList->addNode(temp);
                    Freq[nfreq] = NewFreqList;
                }

                break;
            }
            else  // For Insert of Nodes at MinFreq
            {
                int minfreq = findMinFreqInLst(lst);
                if(minfreq!=-1)
                {
                    NodeList* NewFreqList = Freq[minfreq];
                    NewFreqList->addNode(node);
                }
                else
                {
                    NodeList* NewFreqList = new NodeList();
                    NewFreqList->addNode(temp);
                    Freq[1] = NewFreqList;
                }

            }
        }
    }
    void print_NodeList()
    {
        cout << __FUNCTION__ << endl;
        for(auto f:Freq)
        {
            int freq = f.first;
            cout << "freq=" << freq << endl;
            NodeList* All = f.second;
            Node* start = All->head;
            if(start!=All->tail)
            {
                cout << "key=" << start->key << " val=" << start->val << endl;
                cout << "IN start=" << start << endl;
                cout << "IN start->right=" << start->right << endl;
                start = start->right;
            }
            cout << "start=" << start << endl;
            cout << "start->right=" << start->right << endl;

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
