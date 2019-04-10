#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "D:/homework/QG/LQuenue/LQuenue.h"


 extern array[100];//���ڼ�¼ÿ�δ洢�������Ƕ��� 
 extern tmp; 
 extern i; 
 extern t;
 extern ss;
/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q){
	  if(Q->length < 0){
	  	Q->front = (Node*)malloc(sizeof(Node));
		Q->rear = Q->front;
	  	Q->front->next = NULL;
	  	Q->length = 0; 
	  	printf("��ʼ���ɹ�\n");
	}else{
	  	printf("�Ѿ���ʼ����\n");
	  }
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){
	if(Q->length >0){
		while(Q->front != NULL){
		 	Node *temp = Q->front;
		 	if(Q->length == 1){   //���⴦��һ���ڵ� 
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
		printf("���ٶ��гɹ�\n"); 
		t = 1;
	}else{
		printf("����ʧ�ܣ����б����ǿյ�\n");
	}
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
	if(Q->front == NULL){
		return TRUE;
		t = 1;
	}else{
		printf("���в�Ϊ��\n");
		if(Q->length == 0)
		printf("���Ƕ��л�û�����Ԫ��\n");
		return FALSE;
	}
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q, void *e){
	if(Q->front == NULL || Q->length == 0){
		printf("�㻹û�г�ʼ��");
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
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
	if(Q->length < 0){
		printf("�㻹û��ʼ��\n");
		t = 1;
		return FALSE;
	}else{
		if(Q->length == 0){
			printf("�㻹û�����\n");
			return FALSE;
		}else{
			printf("���г��ȣ�%d\n",Q->length);
			return TRUE;
		}
	}
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data){
		if(Q->length < 0){
		printf("�㻹û��ʼ��\n");
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
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
	if(Q->length < 0){
		printf("�㻹û��ʼ��\n");
		t = 1;
		return FALSE;
	}else{
		if(Q->length == 0){
			printf("�㻹û�����\n");
			return FALSE;
		}else{
			if(Q->length == 1){
				free(Q->front);
				Q->front = (Node*)malloc(sizeof(Node));
				Q->rear = Q->front;
	  			Q->front->next = NULL;
	  			Q->length = 0; 
				printf("���гɹ�\n");
				ss++; 
				return TRUE;
			}
			Node *t = Q->front;
			Q->front = Q->front->next;
			free(t);
			ss++;
			printf("���гɹ�\n"); 
			return TRUE;
		}
	}
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
	if(Q->front != NULL){
		while(Q->front != NULL){
			if(Q->length == 0){
				printf("��û�����\n");
				break;
			} 
			if(Q->length == 1){
				free(Q->front);
				Q->front = (Node*)malloc(sizeof(Node));
				Q->rear = Q->front;
	  			Q->front->next = NULL;
	  			Q->length = 0; 
				printf("��ճɹ�\n"); 
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
		printf("���б����ǿյ�\n");
	}
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*LPrint)(void *q)){
		if(Q->length <= 0){
		printf("�㻹û��ʼ��\n");
		t = 1;
		return FALSE;
	}else{
		Node *t = Q->front;
		while(t != NULL){
			LPrint(t->data);
			if(Q->front == Q->rear){
				break;  //���⴦��ֻ��һ���ڵ㣬����next���ǿ� 
			}
			t = t->next;
		}
		return TRUE;
	}
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
 
 *  @notice      : None
 */
void LPrint(void *q){
		switch(array[ss++])
			{
				case 4:{
					printf("����Ϊ��%d\n",*(int *)q);
					break;
				}
				case 8:{
					printf("����Ϊ��%f\n",*(double *)q);
					break;
				}
				case 1:{
					printf("����Ϊ��%c\n",*(char *)q);
					break;
				}
			}
}

	void menu()
	{
	printf("*******************************************************************************************\n");
	printf("*******************************************************************************************\n\n");
	printf("************************************�ƿ�3������********************************************\n");
	printf("***************************************ջ**************************************************\n");
	printf("                                   1.��ʼ������                                            \n");
	printf("                                   2.���ٶ���                                              \n");
	printf("                                   3.�������Ƿ�Ϊ��                                      \n");
	printf("                                   4.�鿴��ͷԪ��                                          \n");
	printf("                                   5.ȷ�����г���                                          \n");
	printf("                                   6.��Ӳ���                                              \n");
	printf("                                   7.���Ӳ���                                              \n");
	printf("                                   8.��ն���                                              \n");
	printf("                                   9.������������                                          \n");
	printf("                                   10.�˵�                                                 \n");
	printf("                                   11.�˳�                                                 \n");
	printf("                                   12.����                                                 \n");	
	printf("*******************************************************************************************\n");
	printf("*******************************************************************************************\n\n");
	}


