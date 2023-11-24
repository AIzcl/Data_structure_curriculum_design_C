#ifndef _LIBRARY_H
#define _LIBRARY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>     //strncpy()、srand()、rand()、strcmp().. 
#include <conio.h>      //getch()
#include <windows.h>    //Sleep()
#include <time.h>       //time（0） 
#define LEN sizeof(struct _bookinformation) 
#define LEN1 sizeof(struct _borrowers) 

///////////////////////////////////////////////队列
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
	char name[30];           //借阅人名字
	long id;                 //借阅人身份证 
	char bookname[30];       //借阅书籍名字 
	int year;                //年        默认一年365天 
	int month;               //月        默认一个月31天 
	int day;                 //日 
	long time;               //已借天数         这里规定60天是最大期限天数 
	long money;              //罚款             这里规定每超过1天则罚款 2 元 
	struct _borrowers *next;
}borrowers;



typedef struct _bookinformation
{
	long id;                //图书编号 
	char name[30];          //书名
	char author[30];        //作者
	char publisher[50];     //出版社 
	char type[30];          //类别
	long pubtime;           //出版时间
	float price;             //价格
	long num;               //库存
	long bnum;              //已借出 
	struct _bookinformation * next;
	LinkQueue L;            //预约队列 
}bookinformation;


bookinformation *head = NULL;
borrowers *head1 = NULL; 

typedef struct  Administrators_users      //管理员的账号 
{
	char id[20];            //id代表账号 
	char pw[20];            //密码 
	char phone[11];         //手机号码 
}administrators_users;

///////////////////////////////////////////////////
void InitQueue(LinkQueue *L);        //初始化队列 
Status OutQueue(LinkQueue *L,ElemType *e);  //出队 
Status InQueue(LinkQueue*L,ElemType &e);   //入队
////////////////////////////////////////////////////


void character_menu();                       //选择角色（管理员和用户）页面 的菜单显示 
void notice_to_users(); 
 
void users_menu();                         //用户选择页面
void users_menu1();                        //用户选择页面菜单 



void administrators_menu();                         //管理员选择（登录、注册、找回）页面 
void administrators_menu1();                        //管理员选择页面的菜单显示 
void administrators_registers();                    //管理员账号注册页面
void administrators_login();                        //管理员账号登录页面 
void administrators_reback();                       //管理员密码找回页面 
void Create_File();                          //创建储存管理员用户账号密码的文件 administrators.txt


void administrators_side_operation();               //管理员端操作页面 
void administrators_side_operation_menu();          //管理员端操作页面的菜单显示 
bookinformation *creat();                    //初始化图书信息 
void add_book(bookinformation *head);                 //批量增加图书信息
bookinformation *del_book(bookinformation *head);             //批量删除图书信息 
void change_book(bookinformation *head);                //批量修改图书信息 

void reserve_book(bookinformation *head);               //保存图书信息（保存到book1.txt文件） 
void reserve_book1(bookinformation *head);            	// 保存图书信息（保存到book.txt文件） 
void Create_File1();                         			//创建储存图书信息的文件 book.txt（文本文件） 
void Create_File2();                         			//创建book1.txt(二进制) 

void print_book(bookinformation *head);                 //显示全部图书信息（遍历链表）
 
void find_book(bookinformation *head);            		//通过图书信息页面
void find_book_id(bookinformation *head);        	    //通过编号查询图书信息 
void find_book_name(bookinformation *head);             //通过书名查询图书信息 
void find_book_author(bookinformation *head); 	        //通过作者查询图书信息 
void find_book_publisher(bookinformation *head);       //通过出版社查询图书信息 
void find_book_price(bookinformation *head);		   //通过价格的范围查询图书信息 
void backup_book(bookinformation *head);       	  //备份图书信息（将book.txt备份到backup.txt）


bookinformation *sort(bookinformation *head);                       //排序选择页面 
int number_of_book(bookinformation *head);         					//计算图书数量
void print(bookinformation *head);    								//显示排序后的图书信息 
bookinformation *sort_book(int number , bookinformation *head , int(*compare)(bookinformation *p));   // 链表冒泡排序(最难的!!!) 
void swap(bookinformation *p);     																	 //交换p和p->next的内容 
int compare_id(bookinformation *p);      															 //比较p和p->next的编号大小 
int compare_pubtime(bookinformation *p);    														   //比较p和p->next的出版时间大小
int compare_price(bookinformation *p);      														 //比较p和p->next的价格大小 
int compare_num(bookinformation *p);      															 //比较p和p->next的库存大小 

void print_borrowers(borrowers *head1);        //显示已全部借阅人信息 

void borrowing_book();          //借阅图书 
borrowers *creat1();            //指向borrowers结构体类型指针函数用于创建链表
void returning_book();          //归还图书 

void users_suggestion_and_feedback();                       //管理员端建议与反馈箱
void administrators_suggestion_and_feedback();             //用户端建议与反馈箱
void Create_File3();                                        //建立admSgtFb.txt 


void Create_File4();                                       //建立announcement.txt
void administrators_announcement();                        //管理员端公告板 
void users_announcement();                                //用户端公告板 


void appointment_system();                                 //预约系统页面 
#endif
