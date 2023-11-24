#include "BTree.h"

int main()
{
	KeyType k;
	BTree t=NULL;
	Result s;        //设定查找结果 
	char  command;   //定义最开始的界面（BTree基本操作页面的输入指令） 
	while(1)
	{   
	    system("cls");
		BTree_menu();
		command=getch();
		switch(command)
		{
			case '1' : InitBTree(t);break;    // 
			case '2' : {
				system("cls");
				printf("\n输入要插入的数字:\n");
				scanf("%d",&k);
				s=SearchBTree(t,k);
				if(s.tag==0)
				{
					InsertBTree(t,s.i,k,s.pt);
					printf("\n插入成功!!.\n");
				}
				else
				{
					printf("\n输入错误，插入失败!!\n");
				}
				system("pause");
				break;
				
			}    
			case '3' :
			{
				system("cls");
				TAG=1; 
				if(t==NULL)
				{
					printf("\nB树为空!!\n");
					system("pause");
					break;
	
				}
				printf("\n输入要删除的数字:\n");
				scanf("%d",&k);
				BTreeDelete(t,k);
				if(TAG==1) printf("\n成功删除关键字%d\n",k);
				system("pause");
				break;
			}  
			case '4' :{
				system("cls");
				DestroyBTree(t);
            	printf("\n销毁成功!!\n");
            	system("pause"); 
            	break;
			}  
			case '5' :{
				system("cls");
				PrintBTree(t) ;
				break; 
			}
			case '6' : Test();break;  
			case '0' : exit(0);                 //退出 
			default  : printf("您输入的数据非法!请您重新输入!!(按任意键返回输入)\n"); getch();
		}
		
	} 
} 

void BTree_menu()                  //BTree基本操作页面 
{
	printf("\n\t\t\t++++++++++++++++++++++++\n\t\t\t+  B树基本操作选择页面  +\n\t\t\t++++++++++++++++++++++++\n");
    printf("\n		******************菜单栏*****************\n");
	printf("\t\t*\t      1.初始化B树               *\n");
	printf("\t\t*\t      2.插入                    *\n");
	printf("\t\t*\t      3.删除                    *\n");
	printf("\t\t*\t      4.销毁B树                 *\n");
	printf("\t\t*\t      5.打印B树                 *\n");
	printf("\t\t*\t      6.测试1                   *\n");
	printf("\t\t*\t      0.退出系统                *\n");
	printf("		*****************************************\n");
	printf("\n");
	printf("\t\t请输入指令：[\t]\b\b\b");	
} 

//////////////////////////////////////////////////////////////
void Test()
{
	system("cls"); 
    BTNode *t=NULL;
    Result s;                                       //设定查找结果 
    int j,n=10;
    KeyType k;
    KeyType a[]={1,2,3,4,5,6,7,8,9,10};                           
    printf("创建一棵%d阶B树:\n",m);
    for(j=0;j<n;j++){                               //逐一插入元素 
        s=SearchBTree(t,a[j]);
        if(s.tag==0)
            InsertBTree(t,s.i,a[j],s.pt);
        printf("   第%d步,插入元素%d:\n ",j+1,a[j]);
        PrintBTree(t);
    }
    printf("\n");
    system("pause");
    
    printf("\n");
    printf("删除操作:\n");                          //删除操作 
    k=5;                                                        
    BTreeDelete(t,k);
    printf("  删除%d:\n ",k);
    printf("  删除后的B树: \n");
    PrintBTree(t);
    printf("\n");

    k=4;
    BTreeDelete(t,k);
    printf("  删除%d:\n ",k);
    printf("  删除后的B树: \n");
    PrintBTree(t);
    printf("\n");

    printf("  销毁B树\n");                       //递归释放B树
    DestroyBTree(t);                                 
    PrintBTree(t);
    
} 




//////////////////////////////////////////////////////////////////////////////////////////////
Status InitBTree(BTree &t){
	system("cls");
    t=NULL;
    printf("\n成功初始化!\n");
    system("pause");
    return OK;
}

int SearchBTNode(BTNode *p,KeyType k){
    int i=0;
    for(i=0;i<p->keynum&&p->key[i+1]<=k;i++);
    return i;
}

Result SearchBTree(BTree t,KeyType k){
    BTNode *p=t,*q=NULL;                            //初始化结点p和结点q,p指向待查结点,q指向p的双亲
    int found_tag=0;                                //设定查找成功与否标志 
    int i=0;                 
    Result r;                                       //设定返回的查找结果 

    while(p!=NULL&&found_tag==0){
        i=SearchBTNode(p,k);                        //在结点p中查找关键字k                   
		if(i>0&&p->key[i]==k)                       //找到待查关键字
			found_tag=1;                            //查找成功 
        else{                                       //查找失败 
            q=p;                            
            p=p->ptr[i];
        }
    }

    if(found_tag==1){                               //查找成功
        r.pt=p;
        r.i=i;
        r.tag=1;
    }
    else{                                           //查找失败
        r.pt=q;
        r.i=i;
        r.tag=0;
    }
    return r;                                       //返回关键字k的位置(或插入位置)
}

 
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void InsertBTNode(BTNode *&p,int i,KeyType k,BTNode *q){
    int j;
    for(j=p->keynum;j>i;j--){                       //整体后移空出一个位置
        p->key[j+1]=p->key[j];
        p->ptr[j+1]=p->ptr[j];
    }
    p->key[i+1]=k;
    p->ptr[i+1]=q;
    if(q!=NULL) 
        q->parent=p;
    p->keynum++;
}

void SplitBTNode(BTNode *&p,BTNode *&q){
    int i;
    int s=(m+1)/2;
    q=(BTNode *)malloc(sizeof(BTNode));             //给结点q分配空间

    q->ptr[0]=p->ptr[s];                            //后一半移入结点q
    for(i=s+1;i<=m;i++){
        q->key[i-s]=p->key[i];
        q->ptr[i-s]=p->ptr[i];
    }
    q->keynum=p->keynum-s;                
    q->parent=p->parent;
    for(i=0;i<=p->keynum-s;i++)                         //修改双亲指针 
        if(q->ptr[i]!=NULL) 
            q->ptr[i]->parent=q;
    p->keynum=s-1;                              //结点p的前一半保留,修改结点p的keynum
}

void NewRoot(BTNode *&t,KeyType k,BTNode *p,BTNode *q){
    t=(BTNode *)malloc(sizeof(BTNode));             //分配空间 
    t->keynum=1;
    t->ptr[0]=p;
    t->ptr[1]=q;
    t->key[1]=k;
    if(p!=NULL)                                     //调整结点p和q的双亲指针 
        p->parent=t;
    if(q!=NULL) 
        q->parent=t;
    t->parent=NULL;
}

 void InsertBTree(BTree &t,int i,KeyType k,BTNode *p){
    BTNode *q;
    int finish_tag,newroot_tag,s;                   //设定需要新结点标志和插入完成标志 
    KeyType x;
    if(p==NULL)                                     //t是空树
        NewRoot(t,k,NULL,NULL);                     //生成仅含关键字k的根结点t
    else{
        x=k;
        q=NULL;
        finish_tag=0;       
        newroot_tag=0;
        while(finish_tag==0&&newroot_tag==0){
            InsertBTNode(p,i,x,q);                  //将关键字x和结点q分别插入到p->key[i+1]和p->ptr[i+1]
            if (p->keynum<=Max) 
                finish_tag=1;                       //插入完成
            else{         
                s=(m+1)/2;
                SplitBTNode(p,q);                 //分裂结点 
                x=p->key[s];
                if(p->parent){                      //查找x的插入位置
                    p=p->parent;
                    i=SearchBTNode(p, x);
                }
                else                            //没找到x，需要新结点 
                    newroot_tag=1;
            }
        }
        if(newroot_tag==1)                      //根结点已分裂为结点p和q 
            NewRoot(t,x,p,q);                   //生成新根结点t,p和q为子树指针
    }
}

 
 
 ///////////////////////////////////////////////////////////
 Status InitQueue(LinkList &L)                           //初始化队列 
 {
 	L=(LNode*)malloc(sizeof(LNode));              //分配结点空间
	if(L==NULL)
	{
		return OVERFLOW;
	} 
	 L->next=NULL;
	 return OK;
 }
 
LNode * CreateNode(BTNode *p)                   //新建一个结点 
{
	LNode *q;
	q=(LNode*)malloc(sizeof(LNode));            //分配结点空间
	if(q!=NULL)
	{
		q->data=p;
		q->next=NULL;	
	}
	return q; 
}

Status Enqueue(LNode *p,BTNode *q)                             //入队 
{
	if(p==NULL)
	{
		return ERROR;
	}
	while(p->next!=NULL)
	{
		p=p->next;                                   //调到队尾 
	} 
	p->next=CreateNode(q);
	return OK; 
}


Status Dequeue(LNode*p,BTNode*&q)                              //出队 
{
	LNode *aq;
	if(p==NULL||p->next==NULL)                                 //删除位置不合理 
	{
		return ERROR;
	} 
	aq=p->next;
	p->next=aq->next;
	q=aq->data;
	free(aq);
	return OK;
}


Status IFEmpty(LinkList L)                                    //队列判空
{
	if(L==NULL)                           //队列未初始化 
	{
		return ERROR;
	}
	if(L->next==NULL)
	{
		return TRUE;
	}
	return FALSE;
}


void DestroyQueue(LinkList L)                                  //销毁队列
{
	LinkList p;
	if(L!=NULL)
	{
		p=L;
		L=L->next;
		free(p);                                           
		DestroyQueue(L);
	 } 
}

Status Traverse(BTree t,LinkList L,int newline,int sum){ 
    int i;
    BTree p;
    if(t!=NULL){
        printf("  [ ");
        Enqueue(L,t->ptr[0]);                       //入队         
        for(i=1;i<=t->keynum;i++){
            printf(" %d ",t->key[i]);
            Enqueue(L,t->ptr[i]);                   //子结点入队 
        }
        sum+=t->keynum+1;
        printf("]");
        if(newline==0){                             //需要另起一行 
            printf("\n");
            newline=sum-1;
            sum=0;
        }
        else
            newline--;
     }

     if(IFEmpty(L)==FALSE){                         //l不为空 
         Dequeue(L,p);                              //出队，以p返回 
         Traverse(p,L,newline,sum);                 //遍历出队结点 
     }
     return OK;
 }

Status PrintBTree(BTree t)                                   //输出B树 
{
	
	LinkList L;
	if(t==NULL)
	{
		printf("\nB树为空!!\n");
		system("pause");
		return OK;
	} 
	InitQueue(L);
	Traverse(t,L,0,0);
	DestroyQueue(L);
	system("pause");
	return OK;
}

 void DestroyBTree(BTree &t){
//递归释放B树 
    int i;  
    BTNode* p=t;  
    if(p!=NULL){                                    //B树不为空  
        for(i=0;i<=p->keynum;i++){                  //递归释放每一个结点 
            DestroyBTree(*&p->ptr[i]);  
        }  
        free(p);  
    }  
    t=NULL;  
} 

 
 ///////////////////////////////////////////////////////////////////////////
 void BTreeDelete(BTree &t,KeyType k)
 {
//构建删除框架，执行删除操作  
    BTNode *p;
    int a=BTNodeDelete(t,k);                        //删除关键字k 
    if(a==0)
	{
	    printf("   关键字%d不在B树中\n",k); //查找失败 
    	TAG=0;	
	}                                       
    else if(t->keynum==0){                          //调整 
        p=t;
        
        ////////////////
        if(t->ptr[0]==NULL) 
        {
        	t =NULL;
        	free(p);
        	return;
		}
		////////////////
		t=t->ptr[0];
        t->parent=NULL; 
        free(p);
    }
}


int BTNodeDelete(BTNode *p,KeyType k)
{
//在结点p中查找并删除关键字k
    int i;
    int found_tag;                                  //查找标志 
    if(p==NULL)                                     
        return 0;
    else{
        found_tag=FindBTNode(p,k,i);                //返回查找结果 
        if(found_tag==1){                           //查找成功 
            if(p->ptr[i-1]!=NULL){                  //删除的是非叶子结点
                Substitution(p,i);                  //寻找相邻关键字(右子树中最小的关键字) 
                BTNodeDelete(p->ptr[i],p->key[i]);  //执行删除操作 
            }
            else
                Remove(p,i);                        //从结点p中位置i处删除关键字
        }
        else
            found_tag=BTNodeDelete(p->ptr[i],k);    //沿孩子结点递归查找并删除关键字k
        if(p->ptr[i]!=NULL)
            if(p->ptr[i]->keynum<Min)               //删除后关键字个数小于MIN
                AdjustBTree(p,i);                   //调整B树 
        return found_tag;
    }
}

int FindBTNode(BTNode *p,KeyType k,int &i)
{
//反映是否在结点p中是否查找到关键字k 
    if(k<p->key[1]){                                //结点p中查找关键字k失败 
        i=0;
        return 0;
    }
    else{                                           //在p结点中查找
        i=p->keynum;
        while(k<p->key[i]&&i>1)
            i--;
        if(k==p->key[i])                            //结点p中查找关键字k成功 
            return 1;
    }
}

void AdjustBTree(BTNode *p,int i)
{
//删除结点p中的第i个关键字后,调整B树
    if(i==0)                                        //删除的是最左边关键字
        if(p->ptr[1]->keynum>Min)                   //右结点可以借
            MoveLeft(p,1);
        else                                        //右兄弟不够借 
            Combine(p,1);
    else if(i==p->keynum)                           //删除的是最右边关键字
        if(p->ptr[i-1]->keynum>Min)                 //左结点可以借 
            MoveRight(p,i);
        else                                        //左结点不够借 
            Combine(p,i);
    else if(p->ptr[i-1]->keynum>Min)                //删除关键字在中部且左结点够借 
        MoveRight(p,i);
    else if(p->ptr[i+1]->keynum>Min)                //删除关键字在中部且右结点够借 
        MoveLeft(p,i+1);
    else                                            //删除关键字在中部且左右结点都不够借
        Combine(p,i);
}

void Combine(BTNode *p,int i)
{
/*将双亲结点p、右结点q合并入左结点aq，
并调整双亲结点p中的剩余关键字的位置*/ 
    int j;
    BTNode *q=p->ptr[i];                            
    BTNode *aq=p->ptr[i-1];

    aq->keynum++;                                  //将双亲结点的关键字p->key[i]插入到左结点aq     
    aq->key[aq->keynum]=p->key[i];
    aq->ptr[aq->keynum]=q->ptr[0];

    for(j=1;j<=q->keynum;j++){                      //将右结点q中的所有关键字插入到左结点aq 
        aq->keynum++;
        aq->key[aq->keynum]=q->key[j];
        aq->ptr[aq->keynum]=q->ptr[j];
    }

    for(j=i;j<p->keynum;j++){                       //将双亲结点p中的p->key[i]后的所有关键字向前移动一位 
        p->key[j]=p->key[j+1];
        p->ptr[j]=p->ptr[j+1];
    }
    p->keynum--;                                    //修改双亲结点p的keynum值 
    free(q);                                        //释放空右结点q的空间
}

void MoveLeft(BTNode *p,int i)
{
/*将双亲结点p中的第一个关键字移入左结点aq中，
将右结点q中的第一个关键字移入双亲结点p中*/ 
    int j;
    BTNode *aq=p->ptr[i-1];
    BTNode *q=p->ptr[i];

    aq->keynum++;                                   //把双亲结点p中的关键字移动到左兄弟aq中
    aq->key[aq->keynum]=p->key[i]; 
    aq->ptr[aq->keynum]=p->ptr[i]->ptr[0];

    p->key[i]=q->key[1];                            //把右兄弟q中的关键字移动到双亲节点p中
    q->ptr[0]=q->ptr[1];
    q->keynum--;

    for(j=1;j<=q->keynum;j++){                     //将右兄弟q中所有关键字向前移动一位
        q->key[j]=q->key[j+1];
        q->ptr[j]=q->ptr[j+1];
    }
}


void MoveRight(BTNode *p,int i)
{
/*将双亲结点p中的最后一个关键字移入右结点q中
将左结点aq中的最后一个关键字移入双亲结点p中*/ 
    int j;
    BTNode *q=p->ptr[i];
    BTNode *aq=p->ptr[i-1];

    for(j=q->keynum;j>0;j--){                       //将右兄弟q中所有关键字向后移动一位
        q->key[j+1]=q->key[j];
        q->ptr[j+1]=q->ptr[j];
    }

    q->ptr[1]=q->ptr[0];                            //从双亲结点p移动关键字到右兄弟q中
    q->key[1]=p->key[i];
    q->keynum++;

    p->key[i]=aq->key[aq->keynum];                  //将左兄弟aq中最后一个关键字移动到双亲结点p中
    p->ptr[i]->ptr[0]=aq->ptr[aq->keynum];
    aq->keynum--;
}

 
void Substitution(BTNode *p,int i)
{
//查找被删关键字p->key[i](在非叶子结点中)的替代叶子结点(右子树中值最小的关键字) 
    BTNode *q;
    for(q=p->ptr[i];q->ptr[0]!=NULL;q=q->ptr[0]);
    p->key[i]=q->key[1];                            //复制关键字值
}

void Remove(BTNode *p,int i)
{
//从p结点删除key[i]和它的孩子指针ptr[i]
    int j;
    for(j=i+1;j<=p->keynum;j++){                    //前移删除key[i]和ptr[i]
        p->key[j-1]=p->key[j];
        p->ptr[j-1]=p->ptr[j];
    }
    p->keynum--;
}

 
 
