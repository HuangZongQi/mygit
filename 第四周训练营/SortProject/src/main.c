#include<stdio.h>
#include<stdlib.h>
#include "D:/homework/QG/qg���Ĵ���ҵ/qgsort.h" 

int main(int argc, char *argv[]) {
	menu();	
	
    int i,j,k,max=0;
    printf("����������Ҫ����k������\n");
    while(!scanf("%d",&k) || k < 0){
		printf("����������������ʷ�Χ������\n");
		while(getchar()!='\n');
	} 
    int a[k*1000];
    for(i = 0; i < k*1000 ;i++){
		srand(i);
		a[i]=rand();
	}
	int size = 1000*k;
	int end = size-1,begin = 0;
	while(1){
	printf("\n����˵�\n");
	int x;
	while(!scanf("%d",&x)){
		printf("����������������ʷ�Χ������\n");
		while(getchar()!='\n');
	} 
	switch(x){
		case 1:	{
				insertSort(a,size);
				put(a,size);
				break;
		}  
		
		case 2:{
			int temp[1000*k];
			MergeSort(a,begin,end,temp);
			put(a,size);
			break;
		}  
		
		case 3:	{
			QuickSort_Recursion(a,begin,end);
			put(a,size);  
			break;
		}  
		
		case 4:	{
			QuickSort(a,size);
			put(a,size);
			break;
		}  
		
		case 5:	{
			for(j=0;j<1000*k;j++)
			if(max<a[j]) max=a[j];
			CountSort(a,size ,max);
			put(a,size);
			break;
		}  
		
		case 6:	{
			RadixCountSort(a,size);
			put(a,size);
			break;
		}
		
		case 7:	{
			printf("�������鳤��:\n");
			int csize;
			scanf("%d",&csize);
			printf("����0,1,2�е�����\n");
			int b[csize];
			for(i = 0 ; i < csize ; i++)
			scanf("%d",&b[i]);
			ColorSort(b,csize);
			put(b,csize); 
			break;
		}
		
		case 8:	{
			printf("���������k����\n");
			scanf("%d",&k);
			int t=FindSort(a,size,begin,end,k-1);
			printf("��%d�����ǣ�%d\n",k,a[t]);
			printf("�ź����״̬:\n");
			insertSort(a,size);
			put(a,size);
			break;
		}
		case 9:
		{
			printf("\n�˵�Ϊ:\n");
			menu();
			break;	
		}
		case 10:	
		{
			printf("�˳��˵�\n");
			break;
		}
		case 11:{
			system("cls");
			menu();	
			break;
		}	
		default:
		{
			printf("����Ĳ˵����ڷ�Χ��,����������\n");
			break;	
		}	
	} 
}
	return 0;
}

