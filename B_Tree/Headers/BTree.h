#ifndef _BTREE_H
#define _BTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


const int m=3;                             //设定BTREE的阶数
const int Max=m-1;                         //每一个结点的最大关键字数量 
const int Min=(m-1)/2;                     //每一个结点的最小关键字数量
typedef int KeyType;                       //Keytype是关键字类型
int TAG;    //标志是否删除 






/////////////////////////////////////////////////////////////////////
typedef struct node       //BTREE的结点类型和BTREE 
{
	int keynum;     //结点关键字数量
	KeyType key[m+1];      //关键字数组，key[0]不使用
	struct node *parent;         //双亲结点指针
	struct node *ptr[m+1];      //孩子结点指针数组  
}BTNode,*BTree; 

typedef struct
{
	BTNode *pt;  //指向查找的结点
	int i;       //再借点的关键字位序    0 <= i <= m 
	int tag;     //查找成功则为 1     查找失败则为0 
}Result;

typedef struct LNode    //链表和链表结点 
{
	BTree data;        //数据域 
	LNode *next;       //指针域 
	
}LNode,*LinkList;

typedef enum status            //枚举类型（从0开始依次递增）                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       f enum status     //枚举类型 从0开始依次递增 
{
	TRUE,
	FALSE,
	OK,
	ERROR,
	OVERFLOW,
	EMPTY	
}Status;

////////////////////////////////////////////////////////////////////////
void Test();       //测试1 
void BTree_menu();     //BTree基本操作菜单 

Status InitBTree(BTree &t);     //初始化BTree
int SearchBTNode(BTNode *p,KeyType k);      //在结点p中查找关键字 k 的插入位置 i 
Result SearchBTree(BTree t,KeyType k);        //在树t中查找关键字k，返回关键字类型 

void InsertBTNode(BTNode *&p,int i,KeyType k,BTNode *q);   //将关键字k和结点q分别插入到p->key[i+1]和p-ptr[i+1]中 
void SplitBTNode(BTNode *&p,BTNode *&q);                   //将结点p分裂成两个结点，前一半保留，后一半移入结点q 
void NewRoot(BTNode *&t,KeyType k,BTNode*p,BTNode *q);          //生产新的根结点，原p和q为字数指针 
void InsertBTree(BTree &t,int i,KeyType k,BTNode *p);            //在树t中插入关键字k

Status PrintBTree(BTree t);                                    //输出B树 
Status InitQueue(LinkList &L);                                  //初始化队列 
LNode * CreateNode(BTNode *p);                                  //新建一个结点
Status Enqueue(LNode *p,BTNode *q);                             //入队 
Status Dequeue(LNode*p,BTNode*&q);                              //出队 
Status IFEmpty(LinkList L);                                     //队列判空
void DestroyQueue(LinkList L);                                  //销毁队列 
Status Traverse(BTree t,LinkList L,int newline,int sum);          //遍历输出B树

void DestroyBTree(BTree &t);                                    //销毁B树 
 
void BTreeDelete(BTree &t,KeyType k);                     //构建删除框架，执行删除操作 
int BTNodeDelete(BTNode *p,KeyType k);                    //在结点p中查找并删除关键字k
int FindBTNode(BTNode *p,KeyType k,int &i);             //反映是否在结点p中是否查找到关键字k 
void AdjustBTree(BTNode *p,int i);                       //删除结点p中的第i个关键字后,调整B树 
void Combine(BTNode *p,int i);                           /*将双亲结点p、右结点q合并入左结点aq，并调整双亲结点p中的剩余关键字的位置*/  
void MoveLeft(BTNode *p,int i);                         /*将双亲结点p中的第一个关键字移入结点aq中，将结点q中的第一个关键字移入双亲结点p中*/
void MoveRight(BTNode *p,int i);						/*将双亲结点p中的最后一个关键字移入右结点q中,将左结点aq中的最后一个关键字移入双亲结点p中*/
void Substitution(BTNode *p,int i);           //查找被删关键字p->key[i](在非叶子结点中)的替代叶子结点(右子树中值最小的关键字) 
void Remove(BTNode *p,int i);             //从p结点删除key[i]和它的孩子指针ptr[i]


#endif



