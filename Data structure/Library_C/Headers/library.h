#ifndef _LIBRARY_H
#define _LIBRARY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>     //strncpy()��srand()��rand()��strcmp().. 
#include <conio.h>      //getch()
#include <windows.h>    //Sleep()
#include <time.h>       //time��0�� 
#define LEN sizeof(struct _bookinformation) 
#define LEN1 sizeof(struct _borrowers) 

///////////////////////////////////////////////����
typedef struct _borrowers ElemType;
typedef int Status;
typedef struct QNode{
	ElemType *data;
	struct QNode *next; 
}QNode,*QueuePtr;

typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;
/////////////////////////////////////////////////


typedef struct _borrowers
{
	char name[30];           //����������
	long id;                 //���������֤ 
	char bookname[30];       //�����鼮���� 
	int year;                //��        Ĭ��һ��365�� 
	int month;               //��        Ĭ��һ����31�� 
	int day;                 //�� 
	long time;               //�ѽ�����         ����涨60��������������� 
	long money;              //����             ����涨ÿ����1���򷣿� 2 Ԫ 
	struct _borrowers *next;
}borrowers;



typedef struct _bookinformation
{
	long id;                //ͼ���� 
	char name[30];          //����
	char author[30];        //����
	char publisher[50];     //������ 
	char type[30];          //���
	long pubtime;           //����ʱ��
	float price;             //�۸�
	long num;               //���
	long bnum;              //�ѽ�� 
	struct _bookinformation * next;
	LinkQueue L;            //ԤԼ���� 
}bookinformation;


bookinformation *head = NULL;
borrowers *head1 = NULL; 

typedef struct  Administrators_users      //����Ա���˺� 
{
	char id[20];            //id�����˺� 
	char pw[20];            //���� 
	char phone[11];         //�ֻ����� 
}administrators_users;

///////////////////////////////////////////////////
void InitQueue(LinkQueue *L);        //��ʼ������ 
Status OutQueue(LinkQueue *L,ElemType *e);  //���� 
Status InQueue(LinkQueue*L,ElemType &e);   //���
////////////////////////////////////////////////////


void character_menu();                       //ѡ���ɫ������Ա���û���ҳ�� �Ĳ˵���ʾ 
void notice_to_users(); 
 
void users_menu();                         //�û�ѡ��ҳ��
void users_menu1();                        //�û�ѡ��ҳ��˵� 



void administrators_menu();                         //����Աѡ�񣨵�¼��ע�ᡢ�һأ�ҳ�� 
void administrators_menu1();                        //����Աѡ��ҳ��Ĳ˵���ʾ 
void administrators_registers();                    //����Ա�˺�ע��ҳ��
void administrators_login();                        //����Ա�˺ŵ�¼ҳ�� 
void administrators_reback();                       //����Ա�����һ�ҳ�� 
void Create_File();                          //�����������Ա�û��˺�������ļ� administrators.txt


void administrators_side_operation();               //����Ա�˲���ҳ�� 
void administrators_side_operation_menu();          //����Ա�˲���ҳ��Ĳ˵���ʾ 
bookinformation *creat();                    //��ʼ��ͼ����Ϣ 
void add_book(bookinformation *head);                 //��������ͼ����Ϣ
bookinformation *del_book(bookinformation *head);             //����ɾ��ͼ����Ϣ 
void change_book(bookinformation *head);                //�����޸�ͼ����Ϣ 

void reserve_book(bookinformation *head);               //����ͼ����Ϣ�����浽book1.txt�ļ��� 
void reserve_book1(bookinformation *head);            	// ����ͼ����Ϣ�����浽book.txt�ļ��� 
void Create_File1();                         			//��������ͼ����Ϣ���ļ� book.txt���ı��ļ��� 
void Create_File2();                         			//����book1.txt(������) 

void print_book(bookinformation *head);                 //��ʾȫ��ͼ����Ϣ����������
 
void find_book(bookinformation *head);            		//ͨ��ͼ����Ϣҳ��
void find_book_id(bookinformation *head);        	    //ͨ����Ų�ѯͼ����Ϣ 
void find_book_name(bookinformation *head);             //ͨ��������ѯͼ����Ϣ 
void find_book_author(bookinformation *head); 	        //ͨ�����߲�ѯͼ����Ϣ 
void find_book_publisher(bookinformation *head);       //ͨ���������ѯͼ����Ϣ 
void find_book_price(bookinformation *head);		   //ͨ���۸�ķ�Χ��ѯͼ����Ϣ 
void backup_book(bookinformation *head);       	  //����ͼ����Ϣ����book.txt���ݵ�backup.txt��


bookinformation *sort(bookinformation *head);                       //����ѡ��ҳ�� 
int number_of_book(bookinformation *head);         					//����ͼ������
void print(bookinformation *head);    								//��ʾ������ͼ����Ϣ 
bookinformation *sort_book(int number , bookinformation *head , int(*compare)(bookinformation *p));   // ����ð������(���ѵ�!!!) 
void swap(bookinformation *p);     																	 //����p��p->next������ 
int compare_id(bookinformation *p);      															 //�Ƚ�p��p->next�ı�Ŵ�С 
int compare_pubtime(bookinformation *p);    														   //�Ƚ�p��p->next�ĳ���ʱ���С
int compare_price(bookinformation *p);      														 //�Ƚ�p��p->next�ļ۸��С 
int compare_num(bookinformation *p);      															 //�Ƚ�p��p->next�Ŀ���С 

void print_borrowers(borrowers *head1);        //��ʾ��ȫ����������Ϣ 

void borrowing_book();          //����ͼ�� 
borrowers *creat1();            //ָ��borrowers�ṹ������ָ�뺯�����ڴ�������
void returning_book();          //�黹ͼ�� 

void users_suggestion_and_feedback();                       //����Ա�˽����뷴����
void administrators_suggestion_and_feedback();             //�û��˽����뷴����
void Create_File3();                                        //����admSgtFb.txt 


void Create_File4();                                       //����announcement.txt
void administrators_announcement();                        //����Ա�˹���� 
void users_announcement();                                //�û��˹���� 


void appointment_system();                                 //ԤԼϵͳҳ�� 
#endif
