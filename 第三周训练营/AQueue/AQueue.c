#include "D:/homework/QG/AQueue/AQueue.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern i; 
extern t;
extern ss;
extern array[30];


/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q){
	Q->front=0;
   	Q->rear=0;
    Q->length=0;
    printf("初始化完成\n"); 
}


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q){
	if(Q->length < 0)
    {
    	printf("销毁失败,本来就是空的\n"); 
	}
	else
	{
       Q->length=-1;
       printf("销毁成功\n");
       t = 1;
    }
}

/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : 检查队列是否已满
 *    @param         Q 队列指针Q
 *    @return         : 满-TRUE; 未满-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q){
		if(Q->length < 0){
			printf("请先初始化\n");
			t = 1;
			return FALSE;
	}else{
		if(Q->length < MAXQUEUE-1){
			printf("队列未满\n");
			return FALSE;
		}else{
			printf("队列已满\n"); 
			return TRUE;
		}
	}
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q){
	if(Q->length < 0 )
    {
    	printf("请先初始化\n");
    	t = 1;
    	return FALSE;
	}else{
		if(Q->length == 0)
		printf("队列为空\n");
		else printf("队列不为空\n");
		return TRUE;
	}
}



/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q 队列指针Q，存放元素e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue(AQueue *Q, void *e){
		if( Q->length <= 0 || t == 1){
		printf("你还没有初始化或入队\n");
		t = 1;
		return FALSE;
	}else{
		
		e = Q->data[ss];
		APrint(Q->data[ss]);
		ss = 0;
		return TRUE;
	}
}

/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q){
	if(Q->length < 0 )
    {
    	printf("请先初始化\n");
    	t = 1;
	}
	else{	
	if(Q->length == 0)
		printf("还没有入列\n");
	else
		return Q->length;
	}
}



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue(AQueue *Q, void *data){
	if(Q->length == MAXQUEUE)
   {
   	    printf("队列已满,入队失败\n");
		return FALSE;
   }
   if(Q->length < 0){
   	printf("入队失败,队列未初始化\n"); 
   	return FALSE;
   }
   Q->data[i-1] = data;
   Q->rear++;
   Q->length++;
   printf("入队成功\n");
   return TRUE;	
}

/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q){
	if(Q->length <= 0){
		printf("出队失败，还没有初始化或入队\n");
		return FALSE;
	}
	Q->front--;
	Q->length--;
	printf("出队成功\n");
	ss++;
	return TRUE;
}



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q){
	if(Q->length <= 0)
	{
		printf("队列为空,不用清空\n");
	}else{
		Q->front = Q->front;
		Q->length = 0;
		i = 0;
		ss = 0;
		printf("清空成功\n");
	}
}



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*APrint)(void *q)){
	if(Q->length <= 0){
		printf("还没有初始化，或者入列\n"); 
		return FALSE;
	}else{
		int len = 0;
		while(len < Q->length){
			APrint(Q->data[len++]);
		}
	}
	return TRUE;
}

/**
 *  @name        : void APrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 *  @notice      : None
 */
void APrint(void *q){
	switch(array[ss++])
			{
				case 4:{
					printf("数据为：%d\n",*(int *)q);
					break;
				}
				case 8:{
					printf("数据为：%f\n",*(double *)q);
					break;
				}
				case 1:{
					printf("数据为：%c\n",*(char *)q);
					break;
				}
			}
}
	void menu()
	{
	printf("*******************************************************************************************\n");
	printf("*******************************************************************************************\n\n");
	printf("************************************计科3黄宗琪********************************************\n");
	printf("***************************************栈**************************************************\n");
	printf("                                   1.初始化队列                                            \n");
	printf("                                   2.销毁队列                                              \n");
	printf("                                   3.检查队列是否满了                                      \n");
	printf("                                   4.检查队列是否为空                                      \n");
	printf("                                   5.查看队头元素                                          \n");
	printf("                                   6.确定队列长度                                          \n");
	printf("                                   7.入队操作                                              \n");
	printf("                                   8.出队操作                                              \n");
	printf("                                   9.清空队列                                              \n");
	printf("                                   10.遍历函数操作                                         \n");
	printf("                                   11.菜单                                                 \n");
	printf("                                   12.退出                                                 \n");
	printf("                                   13.清屏                                                 \n");	
	printf("*******************************************************************************************\n");
	printf("*******************************************************************************************\n\n");
	}




