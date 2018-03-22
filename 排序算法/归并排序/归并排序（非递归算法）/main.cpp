//归并排序  稳定 复杂度O(n*log2 n)  没有最差、好、平均复杂度，始终是O(n*log2 n)
#include <iostream>

using namespace std;
//非递归算法

//核心：两个有序子列的归并
/*L=左边起始位置 R=右边起始位置 RightEnd=右边终点位置*/
void Merge1(int A[],int temp[],int L,int R,int RightEnd)
{
    int LeftEnd = R - 1; //左边终点位置
    int t = L;           //t为结果数组temp的初始位置
    while(L<=LeftEnd&&R<=RightEnd)
    {
        if(A[L]<=A[R]) temp[t++]=A[L++];
        else           temp[t++]=A[R++];
    }
    while (L <= LeftEnd) //复制左边剩下的数据
        temp[t++]=A[L++];
    while (R <= RightEnd) //复制右边剩下的数据
        temp[t++]=A[R++];
}

//归并算法（分而治之）
void Merge_pass(int A[],int temp[],int n,int length)    //length=??????????械????
{
     int i;
     for(i=0;i<n-2*length;i+=2*length)
        Merge1(A,temp,i,i+length,i+2*length-1);
     if(i+length<n)              //??????????校??椴�???????????
        Merge1(A,temp,i,i+length,n-1);
     else                        //?????1??????,??????
        for(int j=i;j<n;j++)
                      temp[j]=A[j];
}
void Merge_Sort1(int A[],int n)
{
    int *temp,length=1;
    temp=new int[n];
    if(temp!=NULL)
    {
        while(length<n)
        {
            Merge_pass(A,temp,n,length);               //??A?椴�??胃???temp
            length*=2;
            Merge_pass(temp,A,n,length);               //??temp?椴�????A
            length*=2;
        }
        delete []temp;
    }
    else cout<<"空间不足"<<endl;
}
int main()
{

    int A[600],i,n;
    cout << "请输入数组中数据个数:";
    cin>>n;
    cout << "请输入数组中数据个数:";
    for(i=0;i<n;i++)
        cin>>A[i];
    Merge_Sort1(A,n);
    cout<<endl<<"排序后的数组: ";
    for(i=0;i<n;i++)
        cout<<A[i]<<"  ";
    return 0;
}
