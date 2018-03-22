#ifndef MAXHEAP_H_INCLUDED
#define MAXHEAP_H_INCLUDED
#define DefaultSize 100
class MaxHeap
{
private:
    int currentSize;
    int *heap;
    int MaxSize;
    void SiftUp(int start);
    void SiftDown(int start,int over);
public:
    MaxHeap(int A[],int );
    ~MaxHeap(){delete []heap;}
    void Traverse();
    void HeapSort();
    int RemoveMax();
    void Insert(const int x);
};


#endif // MAXHEAP_H_INCLUDED
