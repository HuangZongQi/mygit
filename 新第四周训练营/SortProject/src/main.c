#include<stdio.h>
#include<stdlib.h>
#include "D:/homework/QG/qg第四次作业/qgsort.h" 
#include<time.h>
int main(int argc, char *argv[]) {
	menu();	
	clock_t start ,stop;
    int i,j,k,max=0;
    printf("请输入你想要多少k的数据\n");
    while(!scanf("%d",&k) || k < 0){
		printf("输入有误，请输入合适范围的整数\n");
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
    printf("生成完毕，请在SuperBig.txt中查看\n");
	
  /*  int a[k*1000];
    for(i = 0; i < k*1000 ;i++){
		srand(i);
		a[i]=rand();
	}  */
	int size = 1000*k;
	int end = size-1,begin = 0;
	while(1){
	printf("\n输入菜单\n");
	int x;
	while(!scanf("%d",&x)){
		printf("输入有误，请输入合适范围的整数\n");
		while(getchar()!='\n');
	} 
	switch(x){
		case 1:	{
				start = clock();
				insertSort(a,size);
				stop = clock();
				double duration = (double)(stop-start)/CLK_TCK;
				printf("程序用时：%lf\n",duration);
				put(a,size);
				break;
		}  
		
		case 2:{
				int temp[1000*k];
				start = clock();
				MergeSort(a,begin,end,temp);
				stop = clock();
				double duration = (double)(stop-start)/CLK_TCK;
				printf("程序用时：%lf\n",duration);
				put(a,size);
				break;
		}  
		
		case 3:	{
				start = clock();
				QuickSort_Recursion(a,begin,end);
				stop = clock();
				double duration = (double)(stop-start)/CLK_TCK;
				printf("程序用时：%lf\n",duration);
				put(a,size);  
				break;
		}  
		
		case 4:	{
				start = clock();
				QuickSort(a,size);
				stop = clock();
				double duration = (double)(stop-start)/CLK_TCK;
				printf("程序用时：%lf\n",duration);
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
				printf("\n程序用时：%lf\n",duration);
				break;
		}  
		
		case 6:	{
				start = clock();
				RadixCountSort(a,size);
				stop = clock();
				double duration = (double)(stop-start)/CLK_TCK;
				printf("程序用时：%lf\n",duration);
				put(a,size);
				break;
		}
		
		case 7:	{
			printf("输入数组长度:\n");
			int csize;
			scanf("%d",&csize);
			printf("输入0,1,2中的数据\n");
			int b[csize];
			for(i = 0 ; i < csize ; i++)
			scanf("%d",&b[i]);
			start = clock();
			ColorSort(b,csize);
			stop = clock();
			double duration = (double)(stop-start)/CLK_TCK;
			printf("\n程序用时：%lf\n",duration);
			put(b,csize); 
			break;
		}
		
		case 8:	{
			printf("输入你求第k个数\n");
			scanf("%d",&k);
			start = clock();
			int t=FindSort(a,size,begin,end,k-1);
			stop = clock();
			double duration = (double)(stop-start)/CLK_TCK;
			printf("程序用时：%lf\n",duration);
			printf("第%d个数是：%d\n",k,a[t]);
			printf("排好序的状态:\n");
			insertSort(a,size);
			put(a,size);
			break;
		}
		case 9:
		{
			printf("\n菜单为:\n");
			menu();
			break;	
		}
		case 10:	
		{
			printf("退出菜单\n");
			break;
		}
		case 11:{
			system("cls");
			menu();	
			break;
		}	
		default:
		{
			printf("输入的菜单不在范围内,请重新输入\n");
			break;	
		}	
	} 
}
	return 0;
}


