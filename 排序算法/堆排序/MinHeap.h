#ifndef MINHEAP_H_INCLUDED
#define MINHEAP_H_INCLUDED
#define  DefaultSize 20                 //Ĭ�϶Ѵ�С
class MinHeap
{
private:
    int  *heap;                         //ָ������С��Ԫ�ص�����
    int currentSize;                    //��С���е�ǰԪ�ظ���
    int MaxHeapSize;                    //��С���������Ԫ��
    void siftDown(int start,int over);           //�¸���������start�����������һ��Ԫ�� �»�������Ϊ��С��
    void siftUp(int start);             //�ϸ���������start��0�𲽵�����Ϊ��С��
public:
    MinHeap(int A[],int n); //���캯����ͨ��һ�����齨��
    ~MinHeap(){delete []heap;}          //��������
    // new ����ĵ���������ڴ�ռ��ʱ���� delete�������� new[] �����һ�������ڴ�ռ��ʱ���� delete[]
    bool Insert(const int &x);          //��x���뵽�ѵĺ���λ��
    bool RemoveMin(int &x);             //ɾ���Ѷ���С��Ԫ��,�����浽xֵ
    bool IsEmpty()const                 //�ж϶��Ƿ�Ϊ��
    {return (currentSize==0)?true:false;}
    bool IsFull()const                  //�ж϶��Ƿ�����
    {return (currentSize==MaxHeapSize)?true:false;}
    void MakeEmpty(){currentSize=0;}    //�ÿն�
    void Traverse();                    //������
    void HeapSort(int A[],int &n);                    //��С�����򣬰��մ�С�����˳������
};



#endif // MINHEAP_H_INCLUDED
