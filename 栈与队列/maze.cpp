/*
�������������������������������������������������������
�������������������������������������������������������
 �� Date  :2011-11-16    
 �� Author :renlimin
 �� Description  : 

 �� subscribe:    
 
 �� Introduction�� 
 ��                             

�������������������������������������������������������
�������������������������������������������������������
*/
//----------------����ͷ�ļ�---------------------------------
#include"stdio.h" 
#include"stdlib.h"
#include"time.h"

//=--------------���峣��-------------------------------------
#define  max 126 
#define MaxSize 10000
//---------------�Զ�����������-------------------------------
typedef struct
{
	int x; // �� ���� 
	int y; // �� ���� 
	int k; // �� ��
}datatype; //����ջԪ������

typedef struct 
{
	datatype data[MaxSize];
	int top;
}STACK;//����ջ����

typedef  struct            
{ 
	int x;
	int y;
} item ;//���巽�����ݵ���  
 
//---------------��������-------------------------------------
int hang,lie;
int Maze[max+2][max+2];
int Mark[max+2][max+2];
STACK road;
item move[8];
//---------------������������---------------------------------
int Rand_01(int s_hang,int s_lie);
void InitStack(STACK *S);
//---------------��������-------------------------------------
void Init_value(void);
int Go(int *maze,int HANG,int LIE);
void Random_Maze(void);//��������Թ�
int Push(STACK *S,datatype x);
int Pop(STACK *S,datatype *x);     
int Empty(STACK *S);
int GetTop(STACK *S, datatype *x);   
void road_line(int hang,int lie);
//###################################################### main #
int main(void)

{
	int sel,hang,lie,i,j;
//	int Maze[hang][lie];
	Init_value();
	//�����Թ�1�������2����
do{
	printf("\n##########################################");
	printf("\n#                  ���Թ�                #\n#");
	printf("                                        #");
	printf("\n#    ������ʾѡ��������ֶ�����һ�Թ�    #\n#");
	printf("                                        #");
	printf("\n#    1 ��������Թ� 2 �ֶ������Թ� 0 OUT #\n");
	printf(" >>");
	scanf("%d",&sel);
	getchar();
	while(sel<0||sel>2)
	{
		printf("\n!��ű�����0,1��2������������>> ");
		scanf("%d",&sel);
		getchar();
	}
	if(sel==1)
	{
		printf("\n�����Թ�������>>");
		scanf("%d",&hang);

		printf("�����Թ�������>>");
		scanf("%d",&lie);	
		srand((unsigned int)time(NULL));//�õ�ǰ����ʱ���ʼ����������� 
		
		for(i=0 ; i<hang ; i++)
		{
			for(j=0 ; j<lie ;j++)
			{
				Maze[i+1][j+1]=rand()%2;//���Ҫȡ��[a,b)֮���"int"������ num = rand()%(b-a) + a;
				printf("%d  ", Maze[i+1][j+1]);	//printf("Ten random numbers from 0 to 1\n\n");	
			}                               
			printf("\n");
		}
	}
	else
	{
		printf("\n     �ֶ������Թ�\n");
	}

	
	//���Թ�
	if(Go(&Maze[0][0],hang,lie)==1)
	{
		printf("\n��ͨ\n");
		for(i=0;i<=road.top;i++)
			printf("%d,%d  ",road.data[i].x,road.data[i].y);
		printf("%d,%d  ",hang,lie);
		//�����켣·��
		road_line(hang,lie);
        
		Init_value();
	}
	else
	{
		printf("\nû��ͨ\n");
		Init_value();
	}
}while(sel!=0);//do{};

	return 0;
}
/*--------------------------------------------/
*Function   =  
*Description=��ʼ����������
*input      =
*output     =
*example    =
*---------------------------------------------*/
void Init_value(void)
{
	int i,j;
	//��ʼ��ջInitStack(S) 
	InitStack(&road);
	//��ʼ��move
	move[0].x=0;move[0].y=1;
	move[1].x=1;move[1].y=1;
	move[2].x=1;move[2].y=0;
	move[3].x=1;move[3].y=-1;
	move[4].x=0;move[4].y=-1;
	move[5].x=-1;move[5].y=-1;
	move[6].x=-1;move[6].y=0;
	move[7].x=-1;move[7].y=1;
    //��ʼ����־����
	for(i=0;i<max;i++)
		for(j=0;j<max;j++)
			Mark[i][j]=0;
	//��ʼ������
}
/*--------------------------------------------/
*Function   =  
*Description=���Թ�
*input      =
*output     =
*example    =
*---------------------------------------------*/
int Go(int *maze,int Hang,int Lie)
{
	int i,j,dp_x,dp_y,success=0;
	datatype p;
	for(i=0;i<Lie+2;i++)
	{
		Maze[0][i]=1;
		Maze[Hang+1][i]=1;
	}
	for(i=0;i<Hang+2;i++)
	{
		Maze[i][0]=1;
		Maze[i][Lie+1]=1;
	}
	Maze[1][1]=0;Maze[Hang][Lie]=0;
	for(i=0;i<Hang+2;i++)
	{
		for(j=0;j<Lie+2;j++)
			printf("%d  ",Maze[i][j]);
		printf("\n");
	}	
	//�����Թ�  ��ǰλ�����꣨p_x��P_y��
	p.x=1;
	p.y=1;
	p.k=0;
	Mark[1][1]=1;
	while(success==0)
	{
		//����һ����(direction)��λ������(dp_x,dp_y)
		dp_x=p.x+move[p.k].x;
		dp_y=p.y+move[p.k].y;
		if(Maze[dp_x][dp_y]==0&&Mark[dp_x][dp_y]==0)//�÷���ͨ 
		{
			//�÷���ͨ��ѹջ��ָ��ֵλ
			Push(&road, p);
			Mark[p.x][p.y]=1;
			p.x=dp_x;
			p.y=dp_y;
			p.k=0;
			
			if(dp_x==Hang&&dp_y==Lie)
			{
				Mark[p.x][p.y]=1;
				success=1;
				return 1;
			}
		}
		else//�÷���ͨ 
		{
			Mark[p.x][p.y]=1;
			if(p.k==7)//��·
			{
				//��ջ��Ԫ�ص���������ȡ����Ԫ��ֵ
				if(Pop(&road,&p)==0)
				{
					printf("\nջ����·����\n");
					return 0;
				}
			}
			else
			{
				//������·
				p.k++;
			}
		}
	}
	return 1;
}
/*--------------------------------------------/
*Function   =  
*Description=��ʼ��ջ
*input      =
*output     =
*example    =
*---------------------------------------------*/
void InitStack(STACK *S) 
{
	S->top=-1; 
} 
/*--------------------------------------------/
*Function   =  
*Description=ѹջPush(S,x)
*input      =
*output     =
*example    =
*---------------------------------------------*/
int Push(STACK *S,datatype x)
{
	if(S->top==MaxSize-1)
	{
		printf("\n Stack is full!"); 
		return 0;
	}
	S->top++;
	S->data[S->top]=x;
	return 1; 
}
/*--------------------------------------------/
*Function   =  
*Description=��ջPop(S,x) 
*input      =
*output     =
*example    =
*---------------------------------------------*/
int Pop(STACK *S,datatype *x)     
{ 
	if(Empty(S))
	{
		printf("\n Stack is free!"); 
		return 0;
	}
	*x=S->data[S->top];
	S->top--;
	return 1;
}
/*--------------------------------------------/
*Function   =  
*Description=ȡջ��Ԫ��GetTop(S,x)
*input      =
*output     =
*example    =
*---------------------------------------------*/
int GetTop(STACK *S, datatype *x)   
{
  if(Empty(S))
  {   
      printf("\n Stack is free!"); 
      return 0;
  }
   *x=S->data[S->top];
   return 1;
}
/*--------------------------------------------/
*Function   =  
*Description= ��ջ��Empty(S) 
*input      =
*output     =
*example    =
*---------------------------------------------*/
 int Empty(STACK *S)
 { 
	 return (S->top==-1?1:0);
 }
/*--------------------------------------------/
*Function   =  
*Description=
*input      =
*output     =
*example    =
*---------------------------------------------*/
 void road_line(int hang,int lie)
 {
	 int i,j;
	 for(i=0 ; i<hang+2 ; i++)
	 {
		for(j=0 ; j<lie+2 ;j++)
		{
				  
			Maze[i][j]=0; 
		}                               
	 }
	 for(i=0;i<=road.top;i++)
		Maze[road.data[i].x][road.data[i].y]=1;
	 printf("\n�����켣·��\n");
        for(i=0 ; i<hang+2 ; i++)
		{
			for(j=0 ; j<lie+2 ;j++)
			{
				  
				printf("%d ", Maze[i][j]); 
			}                               
			printf("\n");
		}
	printf("\n�������߹��Ĺ켣·��\n");
        for(i=0 ; i<hang+2 ; i++)
		{
			for(j=0 ; j<lie+2 ;j++)
			{
				  
				printf("%d ", Mark[i][j]); 
			}                               
			printf("\n");
		}
 }
/*--------------------------------------------/
*Function   =  
*Description=
*input      =
*output     =
*example    =
*---------------------------------------------*/
/*--------------------------------------------/
*Function   =  
*Description=
*input      =
*output     =
*example    =
*---------------------------------------------*/
/*--------------------------------------------/
*Function   =  
*Description=
*input      =
*output     =
*example    =
*---------------------------------------------*/


