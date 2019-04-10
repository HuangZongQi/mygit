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
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q){
	Q->front=0;
   	Q->rear=0;
    Q->length=0;
    printf("��ʼ�����\n"); 
}


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q){
	if(Q->length < 0)
    {
    	printf("����ʧ��,�������ǿյ�\n"); 
	}
	else
	{
       Q->length=-1;
       printf("���ٳɹ�\n");
       t = 1;
    }
}

/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : �������Ƿ�����
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q){
		if(Q->length < 0){
			printf("���ȳ�ʼ��\n");
			t = 1;
			return FALSE;
	}else{
		if(Q->length < MAXQUEUE-1){
			printf("����δ��\n");
			return FALSE;
		}else{
			printf("��������\n"); 
			return TRUE;
		}
	}
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q){
	if(Q->length < 0 )
    {
    	printf("���ȳ�ʼ��\n");
    	t = 1;
    	return FALSE;
	}else{
		if(Q->length == 0)
		printf("����Ϊ��\n");
		else printf("���в�Ϊ��\n");
		return TRUE;
	}
}



/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q ����ָ��Q�����Ԫ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadAQueue(AQueue *Q, void *e){
		if( Q->length <= 0 || t == 1){
		printf("�㻹û�г�ʼ�������\n");
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
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : ���г���count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q){
	if(Q->length < 0 )
    {
    	printf("���ȳ�ʼ��\n");
    	t = 1;
	}
	else{	
	if(Q->length == 0)
		printf("��û������\n");
	else
		return Q->length;
	}
}



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ����˻�Ϊ��
 */
Status EnAQueue(AQueue *Q, void *data){
	if(Q->length == MAXQUEUE)
   {
   	    printf("��������,���ʧ��\n");
		return FALSE;
   }
   if(Q->length < 0){
   	printf("���ʧ��,����δ��ʼ��\n"); 
   	return FALSE;
   }
   Q->data[i-1] = data;
   Q->rear++;
   Q->length++;
   printf("��ӳɹ�\n");
   return TRUE;	
}

/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q){
	if(Q->length <= 0){
		printf("����ʧ�ܣ���û�г�ʼ�������\n");
		return FALSE;
	}
	Q->front--;
	Q->length--;
	printf("���ӳɹ�\n");
	ss++;
	return TRUE;
}



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q){
	if(Q->length <= 0)
	{
		printf("����Ϊ��,�������\n");
	}else{
		Q->front = Q->front;
		Q->length = 0;
		i = 0;
		ss = 0;
		printf("��ճɹ�\n");
	}
}



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*APrint)(void *q)){
	if(Q->length <= 0){
		printf("��û�г�ʼ������������\n"); 
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
 *    @description : ��������
 *    @param         q ָ��q
 *  @notice      : None
 */
void APrint(void *q){
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
	printf("                                   3.�������Ƿ�����                                      \n");
	printf("                                   4.�������Ƿ�Ϊ��                                      \n");
	printf("                                   5.�鿴��ͷԪ��                                          \n");
	printf("                                   6.ȷ�����г���                                          \n");
	printf("                                   7.��Ӳ���                                              \n");
	printf("                                   8.���Ӳ���                                              \n");
	printf("                                   9.��ն���                                              \n");
	printf("                                   10.������������                                         \n");
	printf("                                   11.�˵�                                                 \n");
	printf("                                   12.�˳�                                                 \n");
	printf("                                   13.����                                                 \n");	
	printf("*******************************************************************************************\n");
	printf("*******************************************************************************************\n\n");
	}




