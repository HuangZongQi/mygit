#include<stdio.h>
#include<stdlib.h>
#include "D:/homework/QG/qg���Ĵ���ҵ/qgsort.h" 
#include<time.h>
int main(int argc, char *argv[]) {
	menu();	
	clock_t start ,stop;
    int i,j,k,max=0;
    printf("����������Ҫ����k������\n");
    while(!scanf("%d",&k) || k < 0){
		printf("����������������ʷ�Χ������\n");
		while(getchar()!='\n');
	} 
	int a[k*1000];
	FILE *fpWrite=fopen("SuperBig.txt","w");
    if(fpWrite==NULL)
    {
        return 0;
    }
    for(i=0;i<1000*k;i++){
    		srand(i);
			a[i]=rand();
        fprintf(fpWrite,"%d ",rand());
    }
    fclose(fpWrite);
    printf("������ϣ�����SuperBig.txt�в鿴\n");
	
  /*  int a[k*1000];
    for(i = 0; i < k*1000 ;i++){
		srand(i);
		a[i]=rand();
	}  */
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
				start = clock();
				insertSort(a,size);
				stop = clock();
				double duration = (double)(stop-start)/CLK_TCK;
				printf("������ʱ��%lf\n",duration);
				put(a,size);
				break;
		}  
		
		case 2:{
				int temp[1000*k];
				start = clock();
				MergeSort(a,begin,end,temp);
				stop = clock();
				double duration = (double)(stop-start)/CLK_TCK;
				printf("������ʱ��%lf\n",duration);
				put(a,size);
				break;
		}  
		
		case 3:	{
				start = clock();
				QuickSort_Recursion(a,begin,end);
				stop = clock();
				double duration = (double)(stop-start)/CLK_TCK;
				printf("������ʱ��%lf\n",duration);
				put(a,size);  
				break;
		}  
		
		case 4:	{
				start = clock();
				QuickSort(a,size);
				stop = clock();
				double duration = (double)(stop-start)/CLK_TCK;
				printf("������ʱ��%lf\n",duration);
				put(a,size);
				break;
		}  
		
		case 5:	{
				for(j=0;j<1000*k;j++)
				if(max<a[j]) max=a[j];
				start = clock();
				CountSort(a,size ,max);
				stop = clock();
				double duration = (double)(stop-start)/CLK_TCK;
				printf("\n������ʱ��%lf\n",duration);
				break;
		}  
		
		case 6:	{
				start = clock();
				RadixCountSort(a,size);
				stop = clock();
				double duration = (double)(stop-start)/CLK_TCK;
				printf("������ʱ��%lf\n",duration);
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
			start = clock();
			ColorSort(b,csize);
			stop = clock();
			double duration = (double)(stop-start)/CLK_TCK;
			printf("\n������ʱ��%lf\n",duration);
			put(b,csize); 
			break;
		}
		
		case 8:	{
			printf("���������k����\n");
			scanf("%d",&k);
			start = clock();
			int t=FindSort(a,size,begin,end,k-1);
			stop = clock();
			double duration = (double)(stop-start)/CLK_TCK;
			printf("������ʱ��%lf\n",duration);
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


