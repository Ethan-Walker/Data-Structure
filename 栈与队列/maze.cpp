/*
♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀
♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂
 ● Date  :2011-11-16    
 ● Author :renlimin
 ● Description  : 

 ● subscribe:    
 
 ● Introduction： 
 ●                             

♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀
♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂
*/
//----------------包含头文件---------------------------------
#include"stdio.h" 
#include"stdlib.h"
#include"time.h"

//=--------------定义常量-------------------------------------
#define  max 126 
#define MaxSize 10000
//---------------自定义数据类型-------------------------------
typedef struct
{
	int x; // 横 坐标 
	int y; // 纵 坐标 
	int k; // 方 向
}datatype; //定义栈元素类型

typedef struct 
{
	datatype data[MaxSize];
	int top;
}STACK;//定义栈类型

typedef  struct            
{ 
	int x;
	int y;
} item ;//定义方向数据的型  
 
//---------------变量定义-------------------------------------
int hang,lie;
int Maze[max+2][max+2];
int Mark[max+2][max+2];
STACK road;
item move[8];
//---------------基本函数声明---------------------------------
int Rand_01(int s_hang,int s_lie);
void InitStack(STACK *S);
//---------------函数声明-------------------------------------
void Init_value(void);
int Go(int *maze,int HANG,int LIE);
void Random_Maze(void);//随机生成迷宫
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
	//生成迷宫1随机生成2输入
do{
	printf("\n##########################################");
	printf("\n#                  走迷宫                #\n#");
	printf("                                        #");
	printf("\n#    根据提示选择随机或手动输入一迷宫    #\n#");
	printf("                                        #");
	printf("\n#    1 随机生成迷宫 2 手动输入迷宫 0 OUT #\n");
	printf(" >>");
	scanf("%d",&sel);
	getchar();
	while(sel<0||sel>2)
	{
		printf("\n!序号必须是0,1或2，请重新输入>> ");
		scanf("%d",&sel);
		getchar();
	}
	if(sel==1)
	{
		printf("\n输入迷宫的行数>>");
		scanf("%d",&hang);

		printf("输入迷宫的行数>>");
		scanf("%d",&lie);	
		srand((unsigned int)time(NULL));//用当前日历时间初始化随机数种子 
		
		for(i=0 ; i<hang ; i++)
		{
			for(j=0 ; j<lie ;j++)
			{
				Maze[i+1][j+1]=rand()%2;//如果要取得[a,b)之间的"int"数，则 num = rand()%(b-a) + a;
				printf("%d  ", Maze[i+1][j+1]);	//printf("Ten random numbers from 0 to 1\n\n");	
			}                               
			printf("\n");
		}
	}
	else
	{
		printf("\n     手动输入迷宫\n");
	}

	
	//走迷宫
	if(Go(&Maze[0][0],hang,lie)==1)
	{
		printf("\n走通\n");
		for(i=0;i<=road.top;i++)
			printf("%d,%d  ",road.data[i].x,road.data[i].y);
		printf("%d,%d  ",hang,lie);
		//画出轨迹路线
		road_line(hang,lie);
        
		Init_value();
	}
	else
	{
		printf("\n没走通\n");
		Init_value();
	}
}while(sel!=0);//do{};

	return 0;
}
/*--------------------------------------------/
*Function   =  
*Description=初始化各个变量
*input      =
*output     =
*example    =
*---------------------------------------------*/
void Init_value(void)
{
	int i,j;
	//初始化栈InitStack(S) 
	InitStack(&road);
	//初始化move
	move[0].x=0;move[0].y=1;
	move[1].x=1;move[1].y=1;
	move[2].x=1;move[2].y=0;
	move[3].x=1;move[3].y=-1;
	move[4].x=0;move[4].y=-1;
	move[5].x=-1;move[5].y=-1;
	move[6].x=-1;move[6].y=0;
	move[7].x=-1;move[7].y=1;
    //初始化标志矩阵
	for(i=0;i<max;i++)
		for(j=0;j<max;j++)
			Mark[i][j]=0;
	//初始化结束
}
/*--------------------------------------------/
*Function   =  
*Description=走迷宫
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
	//进入迷宫  当前位置坐标（p_x，P_y）
	p.x=1;
	p.y=1;
	p.k=0;
	Mark[1][1]=1;
	while(success==0)
	{
		//求下一方向(direction)点位置坐标(dp_x,dp_y)
		dp_x=p.x+move[p.k].x;
		dp_y=p.y+move[p.k].y;
		if(Maze[dp_x][dp_y]==0&&Mark[dp_x][dp_y]==0)//该方向通 
		{
			//该方向通，压栈，指标值位
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
		else//该方向不通 
		{
			Mark[p.x][p.y]=1;
			if(p.k==7)//死路
			{
				//将栈顶元素弹出，并获取弹出元素值
				if(Pop(&road,&p)==0)
				{
					printf("\n栈空无路可走\n");
					return 0;
				}
			}
			else
			{
				//不是死路
				p.k++;
			}
		}
	}
	return 1;
}
/*--------------------------------------------/
*Function   =  
*Description=初始化栈
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
*Description=压栈Push(S,x)
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
*Description=出栈Pop(S,x) 
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
*Description=取栈顶元素GetTop(S,x)
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
*Description= 判栈空Empty(S) 
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
	 printf("\n画出轨迹路线\n");
        for(i=0 ; i<hang+2 ; i++)
		{
			for(j=0 ; j<lie+2 ;j++)
			{
				  
				printf("%d ", Maze[i][j]); 
			}                               
			printf("\n");
		}
	printf("\n画出行走过的轨迹路线\n");
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


