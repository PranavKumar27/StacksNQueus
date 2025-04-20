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
class Node;
map<int,Node*> Mp;


class Node
{
    public:
    int key,val;
    Node* left;
    Node* right;


    Node()
    {

    }
    Node(int k,int v,Node* prev,Node* next)
    {
        key=k;
        val =v;
        left = prev;
        right = next;
    }
    Node(int k,int v)
    {
        key = k;
        val = v;
        left = right = nullptr;
    }
    Node* put(Node* head,int key,int val) // Insert front
    {

        cout << "head addr=" << head << endl;
        auto itr = Mp.find(key);
        if(itr==Mp.end())
        {
            cout << "Key Not Found in MAP and Hence Insert New Key,Val Pair" << endl;
            Node* newNode = new Node(key,val,nullptr,head);
            cout << "newNode addr=" << newNode << endl;
            if(head!=nullptr)
                head->left = newNode;
            head = newNode;
            cout << "head addr=" << head << endl;
            Mp[key] = newNode;
            cout << "Insert in Map key = " << key << " Size of Map=" << Mp.size() << endl;
            cout << "Insert at Front Done" << endl;

        }
        else
        {
            cout << "Key Found in MAP and Hence Just Update Old Key with New Value" << endl;
            Node* it= Mp[key];
            it->val = val;
            cout << "Val Updated as val=" << it->val << endl;
        }

        return head;
    }

    Node* get(Node* head,int key)
    {

        auto itr = Mp.find(key);
        int val=-1;
        if(itr==Mp.end())
        {
           cout << "Key Not Found in MAP" << endl;
           return nullptr;
        }
        else
        {
            Node* it= Mp[key];
            val = it->val;
            Node*temp = head;
            while(temp!=nullptr)
            {
                if(temp==it)
                {
                    break;
                }

                else
                    temp = temp->right;
            }
            if(temp!=nullptr)
            {
                Node* next = temp->right;
                Node* prev = temp->left;

                if(prev!=nullptr)
                    prev->right = next;
                if(next!=nullptr)
                    next->left = prev;

                temp->right=head;
                temp->left = nullptr;

                head = temp;
            }
        }
        return head;
    }
    Node* del(Node* head)
    {
        cout << __FUNCTION__ << endl;
        Node* temp = head;
        while(temp!=nullptr && temp->right!=nullptr)
        {
            temp = temp->right;
        }
        if(temp!=nullptr)
        {
            Node* prev = temp->left;
            prev->right = nullptr;
            delete(temp);
            return head;
        }
        else
        {
            return nullptr;
        }


    }
    void print_DeQue(Node* head)
    {
        cout << "head in Node Class =" << __FUNCTION__ << "  " <<  head << endl;

        cout << __FUNCTION__ << endl;
        Node* temp = head;
        while(temp!=nullptr)
        {
            cout << "key=" << temp->key << " val=" << temp->val << endl;
            temp = temp->right;
        }
    }


};

class LRU
{
public:
    Node*head;
    int sz;
    LRU()
    {
        Node* head=nullptr;
        cout << "head in LRU =" << __FUNCTION__ << "  " <<  head << endl;
        sz=0;

    }
    void put(int key,int val)
    {
        cout << "head in LRU =" << __FUNCTION__ << "  " <<  head << endl;

        if(sz<MAX_SIZE-1 && head!=nullptr)
        {
            cout << "head in LRU =" << head << endl;
            // Check if already existing in the Map then update the key with diff val
            head = head->put(head,key,val);
            sz++;
        }
        else if(head!=nullptr)
        {
            cout << "else called" << endl;
            head = head->del(head);
            head = head->put(head,key,val);
        }
    }
    int get(int key)
    {
        cout << "head in LRU =" << __FUNCTION__ << "  " <<  head << endl;

        if(head!=nullptr)
        {
            head = head->get(head,key);
            return head->val;
        }
        else
        {
            cout << "Key Not Found and head is NULL" << endl;
            return -1;
        }

    }
    void printLRU()
    {
        cout << "head in LRU =" << __FUNCTION__ << "  " <<  head << endl;
        if(head!=nullptr)
            head->print_DeQue(head);
    }
};

int main()
{
    cout << "LRU Cache Least Recently Used at last" << endl;
    LRU Cache;
    //Cache.printLRU();
    //Cache.get(1);
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
                    Cache.printLRU();
                    break;
            case 2:
                    cout << "Enter key " << endl;
                    cin >> key;
                    val = Cache.get(key);
                    cout << "val=" << val << endl;
                    Cache.printLRU();
                    break;
            case 3:return 0;
            default:break;

        }


    }while(input!=0);

    return 0;
}
