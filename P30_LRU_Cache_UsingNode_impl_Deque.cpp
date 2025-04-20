#include <iostream>
#include <vector>
#include <unordered_map>

// From GFG : https://www.geeksforgeeks.org/lru-cache-implementation-using-double-linked-lists/

using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>

// From GFG : https://www.geeksforgeeks.org/lru-cache-implementation-using-double-linked-lists/

using namespace std;

class Node
{
public:
    int key,val;
    Node* left;
    Node* right;

    Node()
    {
        left=right=nullptr;
    }
    Node(int k,int v)
    {
        key=k;
        val=v;
        left=right=nullptr;
    }
};

class LRUCache
{
    Node* head;
    Node* tail;
    int capacity;
    unordered_map<int,Node*> Cache_Map;
public:
    LRUCache(int cap)
    {
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->right = tail;
        tail->left = head;
        capacity = cap;
    }
    void add(Node* node)
    {
        Node* nextNode = head->right;
        head->right = node;
        node->left = head;
        node->right = nextNode;
        nextNode->left = node;
    }
    void removeNode(Node* node)
    {
        Node* prev = node->left;
        Node* next = node->right;

        prev->right = next;
        next->left = prev;
    }

    int get(int key)
    {
        if(Cache_Map.find(key)==Cache_Map.end()) // Element Not Found
        {
            return -1;
        }
        Node* node = Cache_Map[key]; 
        removeNode(node);
        add(node);
        return node->val;
    }
    void put(int key,int val)
    {
        if(Cache_Map.find(key)!=Cache_Map.end())
        {
            Node* Oldnode = Cache_Map[key];
            removeNode(Oldnode);
            delete Oldnode;
        }

        Node* newNode = new Node(key,val);
        add(newNode);
        Cache_Map[key] = newNode;

        if(Cache_Map.size()>capacity)
        {
            Node* DeleteNode = tail->left;
            int oldkey = DeleteNode->key;
            //cout << "Before Map size=" << Cache_Map.size() << endl;
            removeNode(DeleteNode);
            Cache_Map.erase(oldkey);
            //cout << "After Map size=" << Cache_Map.size() << endl;
            delete DeleteNode;
        }

    }
void print_DeQue()
    {
        cout << __FUNCTION__ << endl;
        Node* temp = head->right;
        while(temp!=nullptr)
        {
            cout << "key=" << temp->key << " val=" << temp->val << endl;
            temp = temp->right;
        }
    }

};
    



int main()
{
    LRUCache Cache(2);
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
    cout << "Hello world!" << endl;
    return 0;
}
