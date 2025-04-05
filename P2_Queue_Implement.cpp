#include <iostream>
#define MAXSIZE 4
using namespace std;

// Implement Queue using Arrays
// Queue is FIFO First in First Out
// The number that came first will be removed first
// In Queue we can push,pop,top and size()
// In Queue if index reaches last we wrap around as index = (index+1)%QueueSIZE
// In Queue we have two pointer one for start and one for end
// All the elements between start to end will be size
// If No element in Queue and Pop is done - Return UnderFlow
// If Queue is full as per Queue Max Size, if push is done return Queue Overflow
// At begin start=end=-1
// At some point start<end
// At some other point end>start ( if wrap around of end occurred)
// At some point start == end if only 1 element in queue, After pop set start=end=-1;


class Queue_Impl
{
    int start,ends;
    int Arr[MAXSIZE];
    int Qsize;
public:
    void init()
    {
        start = ends = -1;
        Qsize = 0;
    }
    void push(int num)
    {
        if(Qsize>=MAXSIZE)
        {
            cout << "Q Over Flow in " << __FUNCTION__ << endl;
        }
        else
        {
            if(start==-1 && ends==-1)
            {
                start++;
                ends++;
                Arr[start]=num;
                Qsize++;
            }
            else
            {
                ends=(ends+1)%MAXSIZE;
                Arr[ends]=num;
                Qsize++;
            }
        }
    }
    int pop()
    {
        if(Qsize == 0)
        {
            cout << "Q Under Flow in " << __FUNCTION__ << endl;
            return -1;
        }
        else
        {
            int element = Arr[start];
            start = (start+1)%MAXSIZE;
            Qsize--;
            return element;
        }
    }
    int Front()
    {
        if(Qsize == 0)
        {
            cout << "Q Under Flow in " << __FUNCTION__ << endl;
            return -1;
        }
        else
        {
            int element = Arr[start];
            return element;
        }
    }
    int sizeOfQ()
    {
        if(Qsize == 0)
        {
            cout << "Q Under Flow in " << __FUNCTION__ << endl;
            return -1;
        }
        else
        {
            return Qsize;
        }
    }
};
int main()
{
    Queue_Impl Q;
    Q.init();
    cout << " Q Front=" << Q.Front() << endl;
    cout << " Q Pop=" << Q.pop() << endl;
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);
    cout << " Q Front=" << Q.Front() << endl;
    cout << " Q Pop=" << Q.pop() << endl;
    cout << " Q size=" << Q.sizeOfQ() << endl;
    Q.push(5);
    Q.push(6);
    cout << " Q Pop=" << Q.pop() << endl;
    cout << " Q Pop=" << Q.pop() << endl;
    cout << " Q Front=" << Q.Front() << endl;
    cout << " Q size=" << Q.sizeOfQ() << endl;
    cout << " Q Pop=" << Q.pop() << endl;
    cout << " Q Front=" << Q.Front() << endl;
    cout << " Q size=" << Q.sizeOfQ() << endl;
    cout << " Q Pop=" << Q.pop() << endl;
    cout << " Q size=" << Q.sizeOfQ() << endl;


    cout << "Hello world!" << endl;
    return 0;
}
