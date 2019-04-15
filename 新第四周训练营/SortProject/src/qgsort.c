#include<stdio.h>
#include<stdlib.h>
#include "D:/homework/QG/qg第四次作业/qgsort.h" 
#include"D:/homework/QG/zhan/LinkStack/LinkStack.h"

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int *a,int size){
	 int i,ii,temp = 0;
    for(i = 1;i < size ;i++){
        temp = a[i]; 
        ii = i-1;
        while(ii >= 0 && a[ii] < temp)
        a[ii+1] = a[ii--];
         a[ii+1] = temp; 
     }
 }


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp){
	int i = begin;
	int j = mid + 1;
	int t = 0;
	while(i <= mid && j <= end){
		if(a[i] >= a[j])
		temp[t++] = a[i++];
		else
		temp[t++] = a[j++];
	}
	while(i <= mid)
	temp[t++] = a[i++];
	while(j <= end)
	temp[t++] = a[j++];
	t = 0;
	while(begin <= end)
	a[begin++] = temp[t++];
}


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int *a,int begin,int end,int *temp){
	if(begin >= end)
	return ;
		int mid = (begin + end)/2;
		MergeSort(a,begin,mid,temp);
		MergeSort(a,mid+1,end,temp);
		MergeArray(a,begin,mid,end,temp);
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
 
void QuickSort_Recursion(int *a, int begin, int end){
	if(begin >= end )
	return ;
    int i = begin,j = end;
    int key = a[i];
    while(i < j){
        while(i < j && key >= a[j])
         j--;
        a[i] = a[j];
        while(i < j && key <= a[i])
         i++;
        a[j] = a[i];
    } 
    a[i] = key;
    QuickSort_Recursion(a,begin,i-1);
    QuickSort_Recursion(a,i+1,end); 
}

/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
 void QuickSort(int *a,int size){
 	int b[size];
 	int c[size];
	int end = size-1;
	int begin = 0;	
    int i,j,t = 0;
    i = begin,j = end;
    while(t > 0){	
				int k = Partition(a,i,j);
	            if(k > i) b[t] = i-1,c[t++] = begin; 
	            if(k < j) b[t] = end,c[t++] = i+1;
	            i = c[--t],j = b[t];
	   }
}

/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int *a, int begin, int end){
	if(begin < end ){
    int i = begin,j = end;
    int key = a[i];
    while(i < j){
        while(i < j && key >= a[j])
         j--;
        a[i] = a[j];
        while(i < j && key <= a[i])
         i++;
        a[j] = a[i];
    } 
    a[i] = key;
    return i;
}
}


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int *a, int size , int max){
		int j,i = 0,k = 0;    
		int *p = (int*)malloc(max*sizeof(int));
		for(i = 0;i < max;i++)
			p[i] = 0;                     
        for(i = 0;i < size;i++)
            p[a[i]]++;
        for(i = 0;i < size;i++){
            for(j = 0;j < p[i];j++)
            	printf("%d ",i);
        }
        free(p);
        p = NULL;
}


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */ 
void RadixCountSort(int *a,int size){
	int maxLength = 0;
	int currentLength = 0;
	int base = 1;
	int i,j;
	int count[size];
        for (i = 0; i < size; i++) {
        	j = i;
        	while(a[j] / base){
            currentLength++;
            if (maxLength < currentLength)
                maxLength = currentLength;
            if(i < 10)
            count[i] = 0;
            base *= 10;
        }
    }
	int bucket[size];
	base = 1;
	j = 0;
	while(j < maxLength){
	for(i = 0;i < size; i++)
	count[i] = 0;
	for(i = 0;i< size;i++)
		count[a[i]/base%10]++;
	for(i = 1;i < 10;i++)
	count[i] += count[i-1]; 
	for(i = size-1;i >= 0;i--){
		int d = a[i]/base%10;
		bucket[count[d]-1] = a[i];
		count[d]--;	
		}
		base *= 10; 
	for(i = 0; i < size;i++)
	a[i] = bucket[i];
	j++;
	}
}


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int *a,int size){
	int *p,*p0,*p2;
	p0 = a;
	p = a + 1;
	p2 = a + size - 1;
	int i = 0;
	while(p != p2){
		if(*p == 0){
			int temp = *p;
			*p = *p0;
			*p0 = temp;
			p0++;
		}
		if(*p == 2){
			int temp = *p;
			*p = *p2;
			*p2 = temp;
			p2--;
		}
		if(*p == 1)
		p++;
  }
    if(*p == 0){
			int temp = *p;
			*p = *p0;
			*p0 = temp;
			p0++;
		}
		if(*p == 2){
			int temp = *p;
			*p = *p2;
			*p2 = temp;
			p2--;
		}
}


/**
 *  @name        : 自拟
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : 数组指针a，数组长度size
 */
int  FindSort(int *a,int size,int begin,int end,int k){
	if(k > size || k < 0)
		return 0;
	else{
		int i = begin,j = end;
    	int key = a[i];
    while(i < j){
        while(i < j && key <= a[j])
         j--;
        a[i] = a[j];
        while(i < j && key >= a[i])
         i++;
        a[j] = a[i];
    } 
    a[i] = key;
    if(i == k)
    	return k;
    else{
    	if(i < k)
    		FindSort(a,size,i+1,size,k);
		else
			FindSort(a,size,0,i-1,k);
		
		}
	}
}
void put(int *a,int size){
	int i;
	for(i = 0;i < size;i++)
	printf("%d ",a[i]);
}
	void menu()
	{
	printf("*******************************************************************************************\n");
	printf("*******************************************************************************************\n\n");
	printf("************************************计科3黄宗琪********************************************\n");
	printf("***************************************栈**************************************************\n");
	printf("                                   1.插入法                                          	   \n");
	printf("                                   2.归并法                                            	   \n");
	printf("                                   3.快速排序递归实现                                      \n");
	printf("                                   4.快速排序非递归实现                                    \n");
	printf("                                   5.计数排序                                     		   \n");
	printf("                                   6.基数排序                                         	   \n");
	printf("                                   7.颜色排序                                          	   \n");
	printf("                                   8.查找第k个数                                           \n");
	printf("                                   9.菜单                                                  \n");
	printf("                                   10.退出                                                 \n");
	printf("                                   11.清屏                                                 \n");	
	printf("*******************************************************************************************\n");
	printf("*******************************************************************************************\n\n");
	}



