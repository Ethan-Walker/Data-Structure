//�ռ任ʱ��  �ȶ�  ƽ��ʱ�临�Ӷ�O(n)
#include <iostream>

using namespace std;

//����Ԫ��ȫΪ0~1000֮������
void Bucket_Sort1(int A[],int n)
{
    int i,k,j;
    int Bucket[1001]={0};
    for(i=0;i<n;i++)
    {
        Bucket[A[i]]++;
    }
    //������õ�Ԫ�ظ��Ƹ�A
    for(k=0,i=0;i<1001;i++)
    {
        for(j=0;j<Bucket[i];j++)
            A[k++]=i;
    }
    return ;

}

//����Ԫ��Ϊ0~1֮��С��
 /*  ��������  0.12 0.32 0.78 0.79 0.09    0.98 0.987  0.125   0.65    0.9
               0.39 0.10 0.89 0.35 0.29    0.67 0.89   0.1000  0.10001 0.32001
*/

struct Node
{
    double data;
    Node *next;
    Node(double da=0):data(da),next(NULL){}
};
void Bucket_Sort2(double A[],int n)
{
    int i,num;
    Node *head[10];//����10��Ͱ��ÿ��Ͱ���δ��ʮ��λΪ0,1,2,,,9������
    for(i=0;i<10;i++)
        head[i]=new Node;
    int Count[10]={0};
    for(i=0;i<n;i++)
    {
        num=int(A[i]*10);            //��ʮ��λ��������λ
        if(Count[num]==0)
           {
               head[num]->data=A[i];
               Count[num]++;
           }
  else
        {
            Count[num]++;
            Node *s=new Node(A[i]);
            Node *p=head[num];
            if(A[i]<p->data)
            {

                s->next=p;
                head[num]=s;
            }
            else
            {
                Node *q=p->next;

                do
                {
                    if(q==NULL)
                    {
                        p->next=s;
                        break;
                    }
                    if(A[i]<q->data)
                    {
                        s->next=q;
                        p->next=s;
                        break;
                    }
                    p=q;
                    q=q->next;
                }while(1);

            }
        }

    }
    //�����������õ�Ԫ��
    for(i=0;i<10;i++)
    {
        if(Count[i]>0)
        {
            Node *p=head[i];
            while(p!=NULL)
            {
                cout<<p->data<<" ";
                p=p->next;
            }

        }

    }


}

int main()
{
    int A1[1000];
    double A2[1000];
    int n,m,i;
    cout<<"�������0~1000�ڵ�������������������Ԫ��������";
    cin>>n;
    cout<<"�����������Ԫ��"<<endl;
    for(i=0;i<n;i++)
        cin>>A1[i];
    Bucket_Sort1(A1,n);
    cout<<"�����Ľ��:"<<endl;
    for(i=0;i<n;i++)
        cout<<A1[i]<<" ";
    cout<<endl;


    cout<<endl<<"�������0~1�ڵ�С��������������Ԫ��������";
    cin>>m;
    cout<<"�����������Ԫ��:"<<endl;
    for(i=0;i<m;i++)
        cin>>A2[i];

    cout<<"�����Ľ��:"<<endl;
    Bucket_Sort2(A2,m);


    return 0;
}
