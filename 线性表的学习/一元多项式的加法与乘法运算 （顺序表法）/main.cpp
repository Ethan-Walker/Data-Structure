#include <iostream>
using namespace std;
struct data{
    int xishu;//coef
    int zhishu;//expon
};
int main()
{
    data A[10000],A1[10000],B[10000],B1[10000],C[10000],D[10000],E[10000],t;
    int m,n,i,j,k=0,x=0,cnt,count=0;
    cin>>m;
    for(i=0;i<m;i++)cin>>A[i].xishu>>A[i].zhishu;
    cin>>n;
    for(i=0;i<n;i++)cin>>B[i].xishu>>B[i].zhishu;
    //先将输入的多项式中含同类项合并
    for(i=0;i<m;)
    {
        A1[count].zhishu=A[i].zhishu;
        A1[count].xishu=A[i].xishu;
        for(j=i+1;j<m;j++)
            if(A[i].zhishu==A[j].result[k]=result[k]+p->coef*q->cozhishu) A1[count].xishu+=A[j].xishu;
            else break;
        count++;
        i=j;
    }
    m=count;
    count=0;
     for(i=0;i<n;)
    {
        B1[count].zhishu=B[i].zhishu;
       B1[count].xishu=B[i].xishu;
        for(j=i+1;j<n;j++)
            if(B[i].zhishu==B[j].zhishu) B1[count].xishu+=B[j].xishu;
            else break;
            count++;
        i=j;
    }
    n=count;


    //多项式乘法
    cnt=0;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
    {
        D[cnt].zhishu=A1[i].zhishu+B1[j].zhishu;
        D[cnt].xishu=A1[i].xishu*B1[j].xishu;
        cnt++;
    }
    //按照指数大小将结构体D排序
    for(i=0;i<cnt-1;i++)
       for(j=i;j<cnt;j++)
       if(D[i].zhishu<D[j].zhishu)
    {
        t=D[i];
        D[i]=D[j];
        D[j]=t;
    }
   /* cout<<"排序后的积多项式为:";
    for(i=0;i<cnt;i++)
    cout<<D[i].xishu<<" "<<D[i].zhishu<<" ";
    cout<<endl;*/
    count=0;
    for(i=0;i<cnt;)
    {
        E[count].zhishu=D[i].zhishu;
        E[count].xishu=D[i].xishu;
        for(j=i+1;j<cnt;j++)
        if(D[i].zhishu==D[j].zhishu)
           E[count].xishu+=D[j].xishu;
           else break;
        count++;
        i=j;
    }
  // cout<<"count="<<count<<endl;
   for(i=0;i<count;i++){
            if(E[i].xishu==0) continue;
    if(i!=count-1)
        {cout<<E[i].xishu<<" "<<E[i].zhishu<<" ";x++;}
    else {cout<<E[i].xishu<<" "<<E[i].zhishu<<endl;x++;}
    }

if(x==0) cout<<"0 0"<<endl;
   //多项式加法
   x=0;
    for(i=0,j=0;i<m||j<n;){
        if(A1[i].zhishu==B1[j].zhishu)
        {C[k].zhishu=A1[i].zhishu;
         C[k].xishu=A1[i].xishu+B1[j].xishu;
         k++;
         i++,j++;
        }
        else if(A1[i].zhishu>B1[j].zhishu)
        {
            C[k].zhishu=A1[i].zhishu;
            C[k].xishu=A1[i].xishu;
            i++;
            k++;
        }
        else if(A1[i].zhishu<B1[j].zhishu)
        {
            C[k].zhishu=B1[i].zhishu;
            C[k].xishu=B1[i].xishu;
            j++;
            k++;
        }
    }
   // cout<<"k="<<k<<endl;
    for(i=0;i<k;i++){
            if(C[i].xishu==0) continue;
            if(i!=k-1)
        {cout<<C[i].xishu<<" "<<C[i].zhishu<<" ";x++;}
    else {cout<<C[i].xishu<<" "<<C[i].zhishu<<endl;x++;}
    }
    if(x==0) cout<<"0 0"<<endl;

    return 0;
}
