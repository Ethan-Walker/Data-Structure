//归并排序  稳定 复杂度O(n*log2 n)  没有最差、好、平均复杂度，始终是O(n*log2 n)
#include <iostream>

using namespace std;
//递归算法

//核心：两个有序子列的归并
/*L=左边起始位置 R=右边起始位置 RightEnd=右边终点位置*/

void Merge(int A[],int temp[],int L,int R,int RightEnd)
{
    int LeftEnd=R-1;          //左边终点位置
    int t=L;                  //t为结果数组temp的初始位置
    int num=RightEnd-L+1;     //处理数据的总数
    while(L<=LeftEnd&&R<=RightEnd)
    {
        if(A[L]<=A[R]) temp[t++]=A[L++];
        else           temp[t++]=A[R++];
    }
    while(L<=LeftEnd)         //复制左边剩下的数据
        temp[t++]=A[L++];
    while(R<=RightEnd)        //复制右边剩下的数据
        temp[t++]=A[R++];

    //***将归并后得到的临时数组重新复制到原先数组
    for(int i=0;i<num;i++,RightEnd--)
        A[RightEnd]=temp[RightEnd];
}



//归并算法（分而治之）
void MSort(int A[],int temp[],int L,int RightEnd)
{
    int mid;
    if(L<RightEnd)
    {
        mid=(L+RightEnd)/2;
        MSort(A,temp,L,mid);            //递归拆分排序左边
        MSort(A,temp,mid+1,RightEnd);   //递归拆分排序右边
        Merge(A,temp,L,mid+1,RightEnd); //归并排序
    }
}

//MSort函数接口
void Merge_Sort(int A[],int n)
{
    int *temp;
    temp=new int[n];                   //动态分配长度为n的数组空间，并返回首地址temp
    if(temp!=NULL)
    {
        MSort(A,temp,0,n-1);
        delete []temp;                  //释放临时数组空间
    }
    else cout<<"空间不足"<<endl;
}

int main()
{
    int A[600],i,n;
    cout<<"请输入数组中数据个数:";
    cin>>n;
    cout<<"请输入数组中数据:";
    for(i=0;i<n;i++)
        cin>>A[i];
    Merge_Sort(A,n);
    cout<<endl<<"排序后的数组：";
    for(i=0;i<n;i++)
        cout<<A[i]<<"  ";
    return 0;
}
