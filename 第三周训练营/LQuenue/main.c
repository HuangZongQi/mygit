#include <stdio.h>
#include "D:/homework/QG/LQuenue/LQuenue.h"
#include <string.h>
#include <stdlib.h>

//ȫ�ֱ��� 
 int array[100]={-1};//���ڼ�¼ÿ�δ洢�������Ƕ��� 
 int i = 0; 
 int t = 0;
 int ss = 0;
 Date tmp;

int main(int argc, char** argv) {
	LQueue Q;
	Q.length = -1;
	Q.front = NULL;
	Q.rear = NULL;
	void *data = NULL;
	menu();
	int flag = 0;    //�ڴ��ýڵ�ã����������������� 
	int fflag = 0; //�˳��˵��ÿ��� 
	while(1)
	{
		int x,y;//y�������շ���ֵ��x�ǲ˵�ѡ�� 
		printf("��������Ҫ��ʼ�Ĳ˵�ѡ��\n");
		int w = 0; 
		while(1 != w)
		{
			w = scanf("%d",&x);
			if(w == 0) printf("error,��������\n");
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
			printf("�ڵ��Ѵ������Ѿ���ʼ���������ٴδ������ʼ��\n");
			break; 
		}
		InitLQueue(&Q);
		if(Q.length >= 0)
		{
			t = 2;
		}
		else
			printf("����ʧ��\n"); 
		break;
	}
	
	case 2:
	{
		DestoryLQueue(&Q);
		break;
	}
	
	case 3:
	{
		y = IsEmptyLQueue(&Q);
		if(y)
		{
			printf("����Ϊ��\n");
		}
		break;
	}
	
	case 4:
	{
		if(array[0] > 0)
		{
			void *e = malloc(sizeof(array[0]));
			GetHeadLQueue(&Q,e);
		}else{
			printf("��û��ʼ��\n");
		}
		break;
	}
	
	case 5:
	{
		LengthLQueue(&Q);
		break;
	}
	
	case 6:
	{
	if(t == 1){
		printf("�㻹û�г�ʼ����ѡ��1��ʼ��\n");
		break;
	}
	printf("*******************************************************************************************\n");
	printf("*******************************************************************************************\n\n");
	printf("**********************************ѡ���������������***************************************\n");
	printf("                                   1.int����                                               \n");
	printf("                                   2.double����                                            \n");
	printf("                                   3.char����                                              \n");
	printf("*******************************************************************************************\n");
	printf("*******************************************************************************************\n\n");
	printf("��ѡ����Ҫ�������������\n");
	int temp; 
	while(!scanf("%d",&temp) || temp <= 0 || temp >= 5){
			printf("����������߲��ڲ˵���Χ��,����������\n");
 			while(getchar()!='\n');  //���� 
		}
	printf("�������������\n");
	switch(temp){
		case 1 :{
			while(!scanf("%d",&tmp.i)){
			printf("������������ݳ�����Χ,����������\n");
 			while(getchar()!='\n');  //���� 
		}
			data = malloc(sizeof(int));
		 	memcpy(data,&tmp.i,sizeof(int));
		 	array[i++] = sizeof(int); 
			break;
		}
		case 2 :{
			while(!scanf("%lf",&tmp.d)){
			printf("������������ݳ�����Χ,����������\n");
 			while(getchar()!='\n');  //���� 
		}
			data = malloc(sizeof(double));
		 	memcpy(data,&tmp.d,sizeof(double));
		 	array[i++] = sizeof(double); 
			break;
		}
		case 3 :{
			getchar();  //�Ե��ո�� 
			while(1){
				printf("����һ���ַ�����һ�γ���������#�Ž���,�����ַ�����Ч���ַ��ַ�Ҫ�س���һ�λ��в�������#�Ž���\n");
					tmp.c = getchar();
					getchar();    //�Ե��ո�� 
					if('#' == getchar())
					break;
			printf("������������ݳ�����Χ,����������\n");
 			while(getchar()!='\n');  //���� 
		}
			data = malloc(sizeof(char));
		 	memcpy(data,&tmp.c,sizeof(char));
		 	array[i++] = 1; 
			break;
		}
	}
		y = EnLQueue(&Q,data);
		if(y)
		{
			printf("��ӳɹ�\n");
		}
		else
		{
				printf("���ʧ��\n");
		}
		break;
	}
	
	case 7:
	{
		DeLQueue(&Q);
		break;
	}
	
	case 8:
	{	
		ClearLQueue(&Q);
		break;
	}
	case 9:{
		 TraverseLQueue(&Q,&LPrint);
		 ss = 0;
		break;
	}
	case 10:
	{
		printf("�˵�Ϊ:\n");
		menu();
		break;	
	}
	
	case 11:
	{
		printf("�˳��˵�\n");
		fflag = 1;
		break;
	}
	
	case 12:
	{
		system("cls");
		menu();	
		break;
	}
	default:
	{
		printf("����Ĳ˵����ڷ�Χ��\n");
		break;	
	}	
	}
    }
	else
    {
    	printf("�ڵ㻹û�д���������ѡ�˵���1������\n");
	}
		if(fflag)
		break;
	}
	return 0;
}
 

