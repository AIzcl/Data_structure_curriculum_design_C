#ifndef _BTREE_H
#define _BTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


const int m=3;                             //�趨BTREE�Ľ���
const int Max=m-1;                         //ÿһ���������ؼ������� 
const int Min=(m-1)/2;                     //ÿһ��������С�ؼ�������
typedef int KeyType;                       //Keytype�ǹؼ�������
int TAG;    //��־�Ƿ�ɾ�� 






/////////////////////////////////////////////////////////////////////
typedef struct node       //BTREE�Ľ�����ͺ�BTREE 
{
	int keynum;     //���ؼ�������
	KeyType key[m+1];      //�ؼ������飬key[0]��ʹ��
	struct node *parent;         //˫�׽��ָ��
	struct node *ptr[m+1];      //���ӽ��ָ������  
}BTNode,*BTree; 

typedef struct
{
	BTNode *pt;  //ָ����ҵĽ��
	int i;       //�ٽ��Ĺؼ���λ��    0 <= i <= m 
	int tag;     //���ҳɹ���Ϊ 1     ����ʧ����Ϊ0 
}Result;

typedef struct LNode    //����������� 
{
	BTree data;        //������ 
	LNode *next;       //ָ���� 
	
}LNode,*LinkList;

typedef enum status            //ö�����ͣ���0��ʼ���ε�����                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       f enum status     //ö������ ��0��ʼ���ε��� 
{
	TRUE,
	FALSE,
	OK,
	ERROR,
	OVERFLOW,
	EMPTY	
}Status;

////////////////////////////////////////////////////////////////////////
void Test();       //����1 
void BTree_menu();     //BTree���������˵� 

Status InitBTree(BTree &t);     //��ʼ��BTree
int SearchBTNode(BTNode *p,KeyType k);      //�ڽ��p�в��ҹؼ��� k �Ĳ���λ�� i 
Result SearchBTree(BTree t,KeyType k);        //����t�в��ҹؼ���k�����عؼ������� 

void InsertBTNode(BTNode *&p,int i,KeyType k,BTNode *q);   //���ؼ���k�ͽ��q�ֱ���뵽p->key[i+1]��p-ptr[i+1]�� 
void SplitBTNode(BTNode *&p,BTNode *&q);                   //�����p���ѳ�������㣬ǰһ�뱣������һ��������q 
void NewRoot(BTNode *&t,KeyType k,BTNode*p,BTNode *q);          //�����µĸ���㣬ԭp��qΪ����ָ�� 
void InsertBTree(BTree &t,int i,KeyType k,BTNode *p);            //����t�в���ؼ���k

Status PrintBTree(BTree t);                                    //���B�� 
Status InitQueue(LinkList &L);                                  //��ʼ������ 
LNode * CreateNode(BTNode *p);                                  //�½�һ�����
Status Enqueue(LNode *p,BTNode *q);                             //��� 
Status Dequeue(LNode*p,BTNode*&q);                              //���� 
Status IFEmpty(LinkList L);                                     //�����п�
void DestroyQueue(LinkList L);                                  //���ٶ��� 
Status Traverse(BTree t,LinkList L,int newline,int sum);          //�������B��

void DestroyBTree(BTree &t);                                    //����B�� 
 
void BTreeDelete(BTree &t,KeyType k);                     //����ɾ����ܣ�ִ��ɾ������ 
int BTNodeDelete(BTNode *p,KeyType k);                    //�ڽ��p�в��Ҳ�ɾ���ؼ���k
int FindBTNode(BTNode *p,KeyType k,int &i);             //��ӳ�Ƿ��ڽ��p���Ƿ���ҵ��ؼ���k 
void AdjustBTree(BTNode *p,int i);                       //ɾ�����p�еĵ�i���ؼ��ֺ�,����B�� 
void Combine(BTNode *p,int i);                           /*��˫�׽��p���ҽ��q�ϲ�������aq��������˫�׽��p�е�ʣ��ؼ��ֵ�λ��*/  
void MoveLeft(BTNode *p,int i);                         /*��˫�׽��p�еĵ�һ���ؼ���������aq�У������q�еĵ�һ���ؼ�������˫�׽��p��*/
void MoveRight(BTNode *p,int i);						/*��˫�׽��p�е����һ���ؼ��������ҽ��q��,������aq�е����һ���ؼ�������˫�׽��p��*/
void Substitution(BTNode *p,int i);           //���ұ�ɾ�ؼ���p->key[i](�ڷ�Ҷ�ӽ����)�����Ҷ�ӽ��(��������ֵ��С�Ĺؼ���) 
void Remove(BTNode *p,int i);             //��p���ɾ��key[i]�����ĺ���ָ��ptr[i]


#endif



