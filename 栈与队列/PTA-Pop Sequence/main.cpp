#include <iostream>
#include <stack>
#define Max 1000
using namespace std;
//����һ���������֣��ж��ܷ��ջ�е����õ���Ӧ��˳��
int main()
{
    stack<int> s;
    int i,j,f,x,cnt;
    int M,N,K;
    int A[Max];
    cin>>M>>N>>K;
    while(K--)
    {
        cnt=0;j=1;                                             //cntΪ�ܷ�ɹ��ı�ǣ�ÿ��ѭ��j���Ǵ�1��ʼѹջ
        for(i=0;i<N;i++) cin>>A[i];
        for(i=0;i<N;i++)                                       //�ӵ�һ�����ֱ���
        {
            if(s.empty())                                      //�ж�ջ���Ƿ�Ϊ��
             {
                    for(;j<=A[i];j++)                          //�ӵ�ǰjԪ��һֱѹջj��j+1,..ֱ��ѹ��A��i��Ԫ��
                    s.push(j);
                    if(s.size()>M) {cnt++;break;}              //�жϴ�ʱջ���Ƿ񳬹����ƣ�������˵����ʱ�õ�A��i��Ԫ�ز�����������

                   x=s.top();                                  //x���漴��������ջ��Ԫ��
                   s.pop();                                    //ջ��Ԫ�غ�A��i����Ӧ������
                   continue;

             }
              if(x>A[i])                                       // ���֮ǰջ��Ԫ��x��A��i-1���ȴ�ʱ��A��i��Ԫ�ش���Ӧ��
             {
                x=s.top();                                     //�Ƚϵ�ǰջ��Ԫ����A��i���Ƿ���ȣ��������ȷ������ջ��Ԫ��x
                if(x==A[i]) s.pop();
                else {cnt++;break;}                            //����������

             }
             else if(x<A[i])                                   //���A��i-1���ȴ�ʱ��A��i��Ԫ��С����Ӧ�ôӵ�ǰ��j��ʼѹջ��j+1��j+2..ֱ��ѹ��A��i��
             {
                 for(;j<=A[i];j++)
                    s.push(j);
                if(s.size()>M) {cnt++;break;}                   //�������ջ�Ĵ�С���ƣ���˵�����ܵõ�A��i��Ԫ�أ����˳�
                 x=s.top();
                 s.pop();
                 continue;
             }


        }
        if(cnt==1)
            cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        while(!s.empty())                                      //ÿ��ѭ����Ҫ���ջ����ֹջ��Ԫ�ض��´�ѭ����Ӱ��
                s.pop();

    }
    return 0;
}
