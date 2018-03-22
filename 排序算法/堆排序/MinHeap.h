#ifndef MINHEAP_H_INCLUDED
#define MINHEAP_H_INCLUDED
#define  DefaultSize 20                 //默认堆大小
class MinHeap
{
private:
    int  *heap;                         //指向存放最小堆元素的数组
    int currentSize;                    //最小堆中当前元素个数
    int MaxHeapSize;                    //最小堆最多允许元素
    void siftDown(int start,int over);           //下浮函数，从start到数组中最后一个元素 下滑调整成为最小堆
    void siftUp(int start);             //上浮函数，从start到0逐步调整成为最小堆
public:
    MinHeap(int A[],int n); //构造函数，通过一个数组建堆
    ~MinHeap(){delete []heap;}          //析构函数
    // new 分配的单个对象的内存空间的时候用 delete，回收用 new[] 分配的一组对象的内存空间的时候用 delete[]
    bool Insert(const int &x);          //将x插入到堆的合适位置
    bool RemoveMin(int &x);             //删除堆顶最小的元素,并保存到x值
    bool IsEmpty()const                 //判断堆是否为空
    {return (currentSize==0)?true:false;}
    bool IsFull()const                  //判断堆是否已满
    {return (currentSize==MaxHeapSize)?true:false;}
    void MakeEmpty(){currentSize=0;}    //置空堆
    void Traverse();                    //遍历堆
    void HeapSort(int A[],int &n);                    //最小堆排序，按照从小到大的顺序排序
};



#endif // MINHEAP_H_INCLUDED
