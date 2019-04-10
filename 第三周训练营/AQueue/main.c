#include <stdio.h>
#include "D:/homework/QG/AQueue/AQueue.h"
#include <string.h>
#include <stdlib.h>

//全局变量 
 int array[30]={-1};//用于记录每次存储的类型是多少 
 int i = 0; 
 int t = 0;
 int ss = 0;
 Date tmp;

int main(int argc, char** argv) {
	AQueue Q;
	void *data = NULL;
	menu();
	int flag = 0;    //在创好节点好，允许其他数字输入 
	int fflag = 0; //退出菜单得控制 
	while(1)
	{
		int x,y;//y用来接收返回值，x是菜单选项 
		printf("请输入你要开始的菜单选项\n");
		int w = 0; 
		while(1 != w)
		{
			w = scanf("%d",&x);
			if(w == 0) printf("error,重新输入\n");
 			while(getchar()!='\n');
		}  
		if(x == 1 || flag == 1)
	{
		flag = 1;
		switch(x)
	{
	case 1:
	{
		if(t == 2)
		{
			printf("节点已创建或已经初始化，不用再次创建或初始化\n");
			break; 
		}
		InitAQueue(&Q);
		if(Q.length >= 0)
		{
			t = 2;
		}
		else
			printf("创建失败\n"); 
		break;
	}
	
	case 2:
	{
		DestoryAQueue(&Q);
		break;
	}
	
	case 3:{
		IsFullAQueue(&Q);
		break;
	}
	case 4:
	{
		IsEmptyAQueue(&Q);
		break;
	}
	
	case 5:
	{
		if(array[0] > 0)
		{
			void *e = malloc(sizeof(array[0]));
			GetHeadAQueue(&Q,e);
		}else{
			printf("还没初始化或者还没入队\n");
		}
		break;
	}
	
	case 6:
	{
		y = LengthAQueue(&Q);
		if(!y) printf("长度为:%d\n",y);
		break;
	}
	
	case 7:
	{
	if(t == 1){
		printf("你还没有初始化，选择1初始化\n");
		break;
	}
	printf("*******************************************************************************************\n");
	printf("*******************************************************************************************\n\n");
	printf("**********************************选择输入的数据类型***************************************\n");
	printf("                                   1.int类型                                               \n");
	printf("                                   2.double类型                                            \n");
	printf("                                   3.char类型                                              \n");
	printf("*******************************************************************************************\n");
	printf("*******************************************************************************************\n\n");
	printf("请选择你要输入的数据类型\n");
	int temp; 
	while(!scanf("%d",&temp) || temp <= 0 || temp >= 5){
			printf("输入有误或者不在菜单范围内,请重新输入\n");
 			while(getchar()!='\n');  //清屏 
		}
	printf("请输入你的数据\n");
	switch(temp){
		case 1 :{
			while(!scanf("%d",&tmp.i)){
			printf("输入有误或数据超出范围,请重新输入\n");
 			while(getchar()!='\n');  //清屏 
		}
			data = malloc(sizeof(int));
		 	memcpy(data,&tmp.i,sizeof(int));
		 	array[i++] = sizeof(int); 
			break;
		}
		case 2 :{
			while(!scanf("%lf",&tmp.d)){
			printf("输入有误或数据超出范围,请重新输入\n");
 			while(getchar()!='\n');  //清屏 
		}
			data = malloc(sizeof(double));
		 	memcpy(data,&tmp.d,sizeof(double));
		 	array[i++] = sizeof(double); 
			break;
		}
		case 3 :{
			getchar();  //吃掉空格键 
			while(1){
				printf("输入一个字符，回一次车后，再输入#号结束,输入字符串无效，字符字符要回车多一次换行才能输入#号结束\n");
					tmp.c = getchar();
						getchar();    //清除缓存区 
					if('#' == getchar())
					break;
			printf("输入有误或数据超出范围,请重新输入\n");
 			while(getchar()!='\n');  //清屏 
		}
			data = malloc(sizeof(char));
		 	memcpy(data,&tmp.c,sizeof(char));
		 	array[i++] = 1; 
			break;
		}
	}
		y = EnAQueue(&Q,data);
		break;
	}
	
	case 8:
	{
		DeAQueue(&Q);
		break;
	}
	
	case 9:
	{	
		ClearAQueue(&Q);
		break;
	}
	case 10:{
		 TraverseAQueue(&Q,&APrint);
		 ss = 0;
		break;
	}
	case 11:
	{
		printf("菜单为:\n");
		menu();
		break;	
	}
	
	case 12:
	{
		printf("退出菜单\n");
		fflag = 1;
		break;
	}
	
	case 13:
	{
		system("cls");
		menu();	
		break;
	}
	default:
	{
		printf("输入的菜单不在范围内\n");
		break;	
	}	
	}
    }
	else
    {
    	printf("节点还没有创建，请先选菜单那1来创建\n");
	}
		if(fflag)
		break;
	}
	return 0;
}
 

