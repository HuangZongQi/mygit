#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "D:/homework/QG/LQuenue/LQuenue.h"


 extern array[100];//用于记录每次存储的类型是多少 
 extern tmp; 
 extern i; 
 extern t;
 extern ss;
/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q){
	  if(Q->length < 0){
	  	Q->front = (Node*)malloc(sizeof(Node));
		Q->rear = Q->front;
	  	Q->front->next = NULL;
	  	Q->length = 0; 
	  	printf("初始化成功\n");
	}else{
	  	printf("已经初始化了\n");
	  }
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){
	if(Q->length >0){
		while(Q->front != NULL){
		 	Node *temp = Q->front;
		 	if(Q->length == 1){   //特殊处理一个节点 
		 		Q->front = NULL;
		 		free(temp);
		 		break;
			 }
		 	Q->front = Q->front->next;
				free(temp);
		}
		i = 0;
		array[i] = 0;
		Q->rear = NULL;
		Q->length = 0;
		printf("销毁队列成功\n"); 
		t = 1;
	}else{
		printf("销毁失败，队列本身是空的\n");
	}
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
	if(Q->front == NULL){
		return TRUE;
		t = 1;
	}else{
		printf("队列不为空\n");
		if(Q->length == 0)
		printf("但是队列还没有入队元素\n");
		return FALSE;
	}
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void *e){
	if(Q->front == NULL || Q->length == 0){
		printf("你还没有初始化");
		t = 1;
		return FALSE;
	}else{
		memcpy(e,Q->front->data,sizeof(*e));
		LPrint(Q->front->data);
		ss = 0;
		return TRUE;
	}
} 

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
	if(Q->length < 0){
		printf("你还没初始化\n");
		t = 1;
		return FALSE;
	}else{
		if(Q->length == 0){
			printf("你还没有入队\n");
			return FALSE;
		}else{
			printf("队列长度：%d\n",Q->length);
			return TRUE;
		}
	}
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data){
		if(Q->length < 0){
		printf("你还没初始化\n");
		t = 1;
		return FALSE;
	}else{
		if(Q->length == 0){
			Q->front->data = data;
			Q->front->next = Q->rear;
			Q->length++;
		}else{
			Node *t = (Node*)malloc(sizeof(Node));
			t->data = data;
			t->next = NULL;
			Q->rear->next = t;
			Q->rear = t;
			Q->length++;
			return TRUE;
		}
	}
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
	if(Q->length < 0){
		printf("你还没初始化\n");
		t = 1;
		return FALSE;
	}else{
		if(Q->length == 0){
			printf("你还没有入队\n");
			return FALSE;
		}else{
			if(Q->length == 1){
				free(Q->front);
				Q->front = (Node*)malloc(sizeof(Node));
				Q->rear = Q->front;
	  			Q->front->next = NULL;
	  			Q->length = 0; 
				printf("出列成功\n");
				ss++; 
				return TRUE;
			}
			Node *t = Q->front;
			Q->front = Q->front->next;
			free(t);
			ss++;
			printf("出列成功\n"); 
			return TRUE;
		}
	}
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
	if(Q->front != NULL){
		while(Q->front != NULL){
			if(Q->length == 0){
				printf("还没有入队\n");
				break;
			} 
			if(Q->length == 1){
				free(Q->front);
				Q->front = (Node*)malloc(sizeof(Node));
				Q->rear = Q->front;
	  			Q->front->next = NULL;
	  			Q->length = 0; 
				printf("清空成功\n"); 
				ss = 0;
				break;
		}else{
		 	Node *temp = Q->front;
		 	Q->front = Q->front->next;
			free(temp);
			Q->length--; 
			}
		}
	}else{
		printf("队列本身是空的\n");
	}
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*LPrint)(void *q)){
		if(Q->length <= 0){
		printf("你还没初始化\n");
		t = 1;
		return FALSE;
	}else{
		Node *t = Q->front;
		while(t != NULL){
			LPrint(t->data);
			if(Q->front == Q->rear){
				break;  //特殊处理只有一个节点，它的next不是空 
			}
			t = t->next;
		}
		return TRUE;
	}
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 
 *  @notice      : None
 */
void LPrint(void *q){
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
	printf("                                   3.检查队列是否为空                                      \n");
	printf("                                   4.查看队头元素                                          \n");
	printf("                                   5.确定队列长度                                          \n");
	printf("                                   6.入队操作                                              \n");
	printf("                                   7.出队操作                                              \n");
	printf("                                   8.清空队列                                              \n");
	printf("                                   9.遍历函数操作                                          \n");
	printf("                                   10.菜单                                                 \n");
	printf("                                   11.退出                                                 \n");
	printf("                                   12.清屏                                                 \n");	
	printf("*******************************************************************************************\n");
	printf("*******************************************************************************************\n\n");
	}


