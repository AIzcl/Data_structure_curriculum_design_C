#include "BTree.h"

int main()
{
	KeyType k;
	BTree t=NULL;
	Result s;        //�趨���ҽ�� 
	char  command;   //�����ʼ�Ľ��棨BTree��������ҳ�������ָ� 
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
				printf("\n����Ҫ���������:\n");
				scanf("%d",&k);
				s=SearchBTree(t,k);
				if(s.tag==0)
				{
					InsertBTree(t,s.i,k,s.pt);
					printf("\n����ɹ�!!.\n");
				}
				else
				{
					printf("\n������󣬲���ʧ��!!\n");
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
					printf("\nB��Ϊ��!!\n");
					system("pause");
					break;
	
				}
				printf("\n����Ҫɾ��������:\n");
				scanf("%d",&k);
				BTreeDelete(t,k);
				if(TAG==1) printf("\n�ɹ�ɾ���ؼ���%d\n",k);
				system("pause");
				break;
			}  
			case '4' :{
				system("cls");
				DestroyBTree(t);
            	printf("\n���ٳɹ�!!\n");
            	system("pause"); 
            	break;
			}  
			case '5' :{
				system("cls");
				PrintBTree(t) ;
				break; 
			}
			case '6' : Test();break;  
			case '0' : exit(0);                 //�˳� 
			default  : printf("����������ݷǷ�!������������!!(���������������)\n"); getch();
		}
		
	} 
} 

void BTree_menu()                  //BTree��������ҳ�� 
{
	printf("\n\t\t\t++++++++++++++++++++++++\n\t\t\t+  B����������ѡ��ҳ��  +\n\t\t\t++++++++++++++++++++++++\n");
    printf("\n		******************�˵���*****************\n");
	printf("\t\t*\t      1.��ʼ��B��               *\n");
	printf("\t\t*\t      2.����                    *\n");
	printf("\t\t*\t      3.ɾ��                    *\n");
	printf("\t\t*\t      4.����B��                 *\n");
	printf("\t\t*\t      5.��ӡB��                 *\n");
	printf("\t\t*\t      6.����1                   *\n");
	printf("\t\t*\t      0.�˳�ϵͳ                *\n");
	printf("		*****************************************\n");
	printf("\n");
	printf("\t\t������ָ�[\t]\b\b\b");	
} 

//////////////////////////////////////////////////////////////
void Test()
{
	system("cls"); 
    BTNode *t=NULL;
    Result s;                                       //�趨���ҽ�� 
    int j,n=10;
    KeyType k;
    KeyType a[]={1,2,3,4,5,6,7,8,9,10};                           
    printf("����һ��%d��B��:\n",m);
    for(j=0;j<n;j++){                               //��һ����Ԫ�� 
        s=SearchBTree(t,a[j]);
        if(s.tag==0)
            InsertBTree(t,s.i,a[j],s.pt);
        printf("   ��%d��,����Ԫ��%d:\n ",j+1,a[j]);
        PrintBTree(t);
    }
    printf("\n");
    system("pause");
    
    printf("\n");
    printf("ɾ������:\n");                          //ɾ������ 
    k=5;                                                        
    BTreeDelete(t,k);
    printf("  ɾ��%d:\n ",k);
    printf("  ɾ�����B��: \n");
    PrintBTree(t);
    printf("\n");

    k=4;
    BTreeDelete(t,k);
    printf("  ɾ��%d:\n ",k);
    printf("  ɾ�����B��: \n");
    PrintBTree(t);
    printf("\n");

    printf("  ����B��\n");                       //�ݹ��ͷ�B��
    DestroyBTree(t);                                 
    PrintBTree(t);
    
} 




//////////////////////////////////////////////////////////////////////////////////////////////
Status InitBTree(BTree &t){
	system("cls");
    t=NULL;
    printf("\n�ɹ���ʼ��!\n");
    system("pause");
    return OK;
}

int SearchBTNode(BTNode *p,KeyType k){
    int i=0;
    for(i=0;i<p->keynum&&p->key[i+1]<=k;i++);
    return i;
}

Result SearchBTree(BTree t,KeyType k){
    BTNode *p=t,*q=NULL;                            //��ʼ�����p�ͽ��q,pָ�������,qָ��p��˫��
    int found_tag=0;                                //�趨���ҳɹ�����־ 
    int i=0;                 
    Result r;                                       //�趨���صĲ��ҽ�� 

    while(p!=NULL&&found_tag==0){
        i=SearchBTNode(p,k);                        //�ڽ��p�в��ҹؼ���k                   
		if(i>0&&p->key[i]==k)                       //�ҵ�����ؼ���
			found_tag=1;                            //���ҳɹ� 
        else{                                       //����ʧ�� 
            q=p;                            
            p=p->ptr[i];
        }
    }

    if(found_tag==1){                               //���ҳɹ�
        r.pt=p;
        r.i=i;
        r.tag=1;
    }
    else{                                           //����ʧ��
        r.pt=q;
        r.i=i;
        r.tag=0;
    }
    return r;                                       //���عؼ���k��λ��(�����λ��)
}

 
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void InsertBTNode(BTNode *&p,int i,KeyType k,BTNode *q){
    int j;
    for(j=p->keynum;j>i;j--){                       //������ƿճ�һ��λ��
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
    q=(BTNode *)malloc(sizeof(BTNode));             //�����q����ռ�

    q->ptr[0]=p->ptr[s];                            //��һ��������q
    for(i=s+1;i<=m;i++){
        q->key[i-s]=p->key[i];
        q->ptr[i-s]=p->ptr[i];
    }
    q->keynum=p->keynum-s;                
    q->parent=p->parent;
    for(i=0;i<=p->keynum-s;i++)                         //�޸�˫��ָ�� 
        if(q->ptr[i]!=NULL) 
            q->ptr[i]->parent=q;
    p->keynum=s-1;                              //���p��ǰһ�뱣��,�޸Ľ��p��keynum
}

void NewRoot(BTNode *&t,KeyType k,BTNode *p,BTNode *q){
    t=(BTNode *)malloc(sizeof(BTNode));             //����ռ� 
    t->keynum=1;
    t->ptr[0]=p;
    t->ptr[1]=q;
    t->key[1]=k;
    if(p!=NULL)                                     //�������p��q��˫��ָ�� 
        p->parent=t;
    if(q!=NULL) 
        q->parent=t;
    t->parent=NULL;
}

 void InsertBTree(BTree &t,int i,KeyType k,BTNode *p){
    BTNode *q;
    int finish_tag,newroot_tag,s;                   //�趨��Ҫ�½���־�Ͳ�����ɱ�־ 
    KeyType x;
    if(p==NULL)                                     //t�ǿ���
        NewRoot(t,k,NULL,NULL);                     //���ɽ����ؼ���k�ĸ����t
    else{
        x=k;
        q=NULL;
        finish_tag=0;       
        newroot_tag=0;
        while(finish_tag==0&&newroot_tag==0){
            InsertBTNode(p,i,x,q);                  //���ؼ���x�ͽ��q�ֱ���뵽p->key[i+1]��p->ptr[i+1]
            if (p->keynum<=Max) 
                finish_tag=1;                       //�������
            else{         
                s=(m+1)/2;
                SplitBTNode(p,q);                 //���ѽ�� 
                x=p->key[s];
                if(p->parent){                      //����x�Ĳ���λ��
                    p=p->parent;
                    i=SearchBTNode(p, x);
                }
                else                            //û�ҵ�x����Ҫ�½�� 
                    newroot_tag=1;
            }
        }
        if(newroot_tag==1)                      //������ѷ���Ϊ���p��q 
            NewRoot(t,x,p,q);                   //�����¸����t,p��qΪ����ָ��
    }
}

 
 
 ///////////////////////////////////////////////////////////
 Status InitQueue(LinkList &L)                           //��ʼ������ 
 {
 	L=(LNode*)malloc(sizeof(LNode));              //������ռ�
	if(L==NULL)
	{
		return OVERFLOW;
	} 
	 L->next=NULL;
	 return OK;
 }
 
LNode * CreateNode(BTNode *p)                   //�½�һ����� 
{
	LNode *q;
	q=(LNode*)malloc(sizeof(LNode));            //������ռ�
	if(q!=NULL)
	{
		q->data=p;
		q->next=NULL;	
	}
	return q; 
}

Status Enqueue(LNode *p,BTNode *q)                             //��� 
{
	if(p==NULL)
	{
		return ERROR;
	}
	while(p->next!=NULL)
	{
		p=p->next;                                   //������β 
	} 
	p->next=CreateNode(q);
	return OK; 
}


Status Dequeue(LNode*p,BTNode*&q)                              //���� 
{
	LNode *aq;
	if(p==NULL||p->next==NULL)                                 //ɾ��λ�ò����� 
	{
		return ERROR;
	} 
	aq=p->next;
	p->next=aq->next;
	q=aq->data;
	free(aq);
	return OK;
}


Status IFEmpty(LinkList L)                                    //�����п�
{
	if(L==NULL)                           //����δ��ʼ�� 
	{
		return ERROR;
	}
	if(L->next==NULL)
	{
		return TRUE;
	}
	return FALSE;
}


void DestroyQueue(LinkList L)                                  //���ٶ���
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
        Enqueue(L,t->ptr[0]);                       //���         
        for(i=1;i<=t->keynum;i++){
            printf(" %d ",t->key[i]);
            Enqueue(L,t->ptr[i]);                   //�ӽ����� 
        }
        sum+=t->keynum+1;
        printf("]");
        if(newline==0){                             //��Ҫ����һ�� 
            printf("\n");
            newline=sum-1;
            sum=0;
        }
        else
            newline--;
     }

     if(IFEmpty(L)==FALSE){                         //l��Ϊ�� 
         Dequeue(L,p);                              //���ӣ���p���� 
         Traverse(p,L,newline,sum);                 //�������ӽ�� 
     }
     return OK;
 }

Status PrintBTree(BTree t)                                   //���B�� 
{
	
	LinkList L;
	if(t==NULL)
	{
		printf("\nB��Ϊ��!!\n");
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
//�ݹ��ͷ�B�� 
    int i;  
    BTNode* p=t;  
    if(p!=NULL){                                    //B����Ϊ��  
        for(i=0;i<=p->keynum;i++){                  //�ݹ��ͷ�ÿһ����� 
            DestroyBTree(*&p->ptr[i]);  
        }  
        free(p);  
    }  
    t=NULL;  
} 

 
 ///////////////////////////////////////////////////////////////////////////
 void BTreeDelete(BTree &t,KeyType k)
 {
//����ɾ����ܣ�ִ��ɾ������  
    BTNode *p;
    int a=BTNodeDelete(t,k);                        //ɾ���ؼ���k 
    if(a==0)
	{
	    printf("   �ؼ���%d����B����\n",k); //����ʧ�� 
    	TAG=0;	
	}                                       
    else if(t->keynum==0){                          //���� 
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
//�ڽ��p�в��Ҳ�ɾ���ؼ���k
    int i;
    int found_tag;                                  //���ұ�־ 
    if(p==NULL)                                     
        return 0;
    else{
        found_tag=FindBTNode(p,k,i);                //���ز��ҽ�� 
        if(found_tag==1){                           //���ҳɹ� 
            if(p->ptr[i-1]!=NULL){                  //ɾ�����Ƿ�Ҷ�ӽ��
                Substitution(p,i);                  //Ѱ�����ڹؼ���(����������С�Ĺؼ���) 
                BTNodeDelete(p->ptr[i],p->key[i]);  //ִ��ɾ������ 
            }
            else
                Remove(p,i);                        //�ӽ��p��λ��i��ɾ���ؼ���
        }
        else
            found_tag=BTNodeDelete(p->ptr[i],k);    //�غ��ӽ��ݹ���Ҳ�ɾ���ؼ���k
        if(p->ptr[i]!=NULL)
            if(p->ptr[i]->keynum<Min)               //ɾ����ؼ��ָ���С��MIN
                AdjustBTree(p,i);                   //����B�� 
        return found_tag;
    }
}

int FindBTNode(BTNode *p,KeyType k,int &i)
{
//��ӳ�Ƿ��ڽ��p���Ƿ���ҵ��ؼ���k 
    if(k<p->key[1]){                                //���p�в��ҹؼ���kʧ�� 
        i=0;
        return 0;
    }
    else{                                           //��p����в���
        i=p->keynum;
        while(k<p->key[i]&&i>1)
            i--;
        if(k==p->key[i])                            //���p�в��ҹؼ���k�ɹ� 
            return 1;
    }
}

void AdjustBTree(BTNode *p,int i)
{
//ɾ�����p�еĵ�i���ؼ��ֺ�,����B��
    if(i==0)                                        //ɾ����������߹ؼ���
        if(p->ptr[1]->keynum>Min)                   //�ҽ����Խ�
            MoveLeft(p,1);
        else                                        //���ֵܲ����� 
            Combine(p,1);
    else if(i==p->keynum)                           //ɾ���������ұ߹ؼ���
        if(p->ptr[i-1]->keynum>Min)                 //������Խ� 
            MoveRight(p,i);
        else                                        //���㲻���� 
            Combine(p,i);
    else if(p->ptr[i-1]->keynum>Min)                //ɾ���ؼ������в������㹻�� 
        MoveRight(p,i);
    else if(p->ptr[i+1]->keynum>Min)                //ɾ���ؼ������в����ҽ�㹻�� 
        MoveLeft(p,i+1);
    else                                            //ɾ���ؼ������в������ҽ�㶼������
        Combine(p,i);
}

void Combine(BTNode *p,int i)
{
/*��˫�׽��p���ҽ��q�ϲ�������aq��
������˫�׽��p�е�ʣ��ؼ��ֵ�λ��*/ 
    int j;
    BTNode *q=p->ptr[i];                            
    BTNode *aq=p->ptr[i-1];

    aq->keynum++;                                  //��˫�׽��Ĺؼ���p->key[i]���뵽����aq     
    aq->key[aq->keynum]=p->key[i];
    aq->ptr[aq->keynum]=q->ptr[0];

    for(j=1;j<=q->keynum;j++){                      //���ҽ��q�е����йؼ��ֲ��뵽����aq 
        aq->keynum++;
        aq->key[aq->keynum]=q->key[j];
        aq->ptr[aq->keynum]=q->ptr[j];
    }

    for(j=i;j<p->keynum;j++){                       //��˫�׽��p�е�p->key[i]������йؼ�����ǰ�ƶ�һλ 
        p->key[j]=p->key[j+1];
        p->ptr[j]=p->ptr[j+1];
    }
    p->keynum--;                                    //�޸�˫�׽��p��keynumֵ 
    free(q);                                        //�ͷſ��ҽ��q�Ŀռ�
}

void MoveLeft(BTNode *p,int i)
{
/*��˫�׽��p�еĵ�һ���ؼ�����������aq�У�
���ҽ��q�еĵ�һ���ؼ�������˫�׽��p��*/ 
    int j;
    BTNode *aq=p->ptr[i-1];
    BTNode *q=p->ptr[i];

    aq->keynum++;                                   //��˫�׽��p�еĹؼ����ƶ������ֵ�aq��
    aq->key[aq->keynum]=p->key[i]; 
    aq->ptr[aq->keynum]=p->ptr[i]->ptr[0];

    p->key[i]=q->key[1];                            //�����ֵ�q�еĹؼ����ƶ���˫�׽ڵ�p��
    q->ptr[0]=q->ptr[1];
    q->keynum--;

    for(j=1;j<=q->keynum;j++){                     //�����ֵ�q�����йؼ�����ǰ�ƶ�һλ
        q->key[j]=q->key[j+1];
        q->ptr[j]=q->ptr[j+1];
    }
}


void MoveRight(BTNode *p,int i)
{
/*��˫�׽��p�е����һ���ؼ��������ҽ��q��
������aq�е����һ���ؼ�������˫�׽��p��*/ 
    int j;
    BTNode *q=p->ptr[i];
    BTNode *aq=p->ptr[i-1];

    for(j=q->keynum;j>0;j--){                       //�����ֵ�q�����йؼ�������ƶ�һλ
        q->key[j+1]=q->key[j];
        q->ptr[j+1]=q->ptr[j];
    }

    q->ptr[1]=q->ptr[0];                            //��˫�׽��p�ƶ��ؼ��ֵ����ֵ�q��
    q->key[1]=p->key[i];
    q->keynum++;

    p->key[i]=aq->key[aq->keynum];                  //�����ֵ�aq�����һ���ؼ����ƶ���˫�׽��p��
    p->ptr[i]->ptr[0]=aq->ptr[aq->keynum];
    aq->keynum--;
}

 
void Substitution(BTNode *p,int i)
{
//���ұ�ɾ�ؼ���p->key[i](�ڷ�Ҷ�ӽ����)�����Ҷ�ӽ��(��������ֵ��С�Ĺؼ���) 
    BTNode *q;
    for(q=p->ptr[i];q->ptr[0]!=NULL;q=q->ptr[0]);
    p->key[i]=q->key[1];                            //���ƹؼ���ֵ
}

void Remove(BTNode *p,int i)
{
//��p���ɾ��key[i]�����ĺ���ָ��ptr[i]
    int j;
    for(j=i+1;j<=p->keynum;j++){                    //ǰ��ɾ��key[i]��ptr[i]
        p->key[j-1]=p->key[j];
        p->ptr[j-1]=p->ptr[j];
    }
    p->keynum--;
}

 
 
