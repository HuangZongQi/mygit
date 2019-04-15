#include<stdio.h>
#include<stdlib.h>
#include "D:/homework/QG/qg���Ĵ���ҵ/qgsort.h" 
#include"D:/homework/QG/zhan/LinkStack/LinkStack.h"

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : ��������
 *  @param       : ����ָ�� a, ���鳤�� n
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
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
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
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
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
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
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
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
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
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
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
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
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
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
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
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
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
 *  @name        : ����
 *  @description : ��һ�������������ҵ���K��/С����
 *  @param       : ����ָ��a�����鳤��size
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
	printf("************************************�ƿ�3������********************************************\n");
	printf("***************************************ջ**************************************************\n");
	printf("                                   1.���뷨                                          	   \n");
	printf("                                   2.�鲢��                                            	   \n");
	printf("                                   3.��������ݹ�ʵ��                                      \n");
	printf("                                   4.��������ǵݹ�ʵ��                                    \n");
	printf("                                   5.��������                                     		   \n");
	printf("                                   6.��������                                         	   \n");
	printf("                                   7.��ɫ����                                          	   \n");
	printf("                                   8.���ҵ�k����                                           \n");
	printf("                                   9.�˵�                                                  \n");
	printf("                                   10.�˳�                                                 \n");
	printf("                                   11.����                                                 \n");	
	printf("*******************************************************************************************\n");
	printf("*******************************************************************************************\n\n");
	}



