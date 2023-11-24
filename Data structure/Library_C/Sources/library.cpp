#include "library.h"
////////////////////////////////////////////////////////
void InitQueue(LinkQueue *L)        //初始化队列 
{
	L->front=(QueuePtr)malloc(sizeof(QNode));
	if(L->front == NULL)
	{
		printf("\n分配内存失败!!\n");
		system("pause");
		exit(0); 
	}
	L->rear=L->front;
	L->front->next=NULL; 
}

Status InQueue(LinkQueue*L,ElemType *e)   //入队 
{
	QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
	if(p == NULL)
	{
		printf("\n分配内存失败!!\n");
		system("pause");
		exit(0); 
	}
	p->data = e;
	
//	printf("%s\t%ld\t\t%s\t\t%d-%d-%d\t%d\t%d\n",p->data->name,p->data->id,p->data->bookname,p->data->year,p->data->month,p->data->day,p->data->time,p->data->money);
//	system("pause");
	
	p->next = NULL;
	L->rear->next = p;
	L->rear = p;
	return 1; 
}

Status OutQueue(LinkQueue *L,ElemType &e)  //出队 
{
	if(L->rear==L->front)
	{
		printf("\n队列为空!!\n");
		system("pause"); 
		return 0;
	 } 
	QueuePtr adjust = L->front->next;
	e = *adjust->data;
	
//	printf("%s\t%ld\t\t%s\t\t%d-%d-%d\t%d\t%d\n",e.name,e.id,e.bookname,e.year,e.month,e.day,e.time,e.money);
//	system("pause");
	
	if(L->rear == L->front->next)
	{
		L->rear=L->front;
	 } 
	 L->front->next=adjust->next;
	 free(adjust);
	 return 1;
	 
} 

///////////////////////////////////////////////////////
int main()
{
	char  command;   //定义最开始的界面（选择角色登录界面的输入指令） 
	while(1)
	{   
	    system("cls");
		character_menu();
		command=getch();
		switch(command)
		{
			case '1' : administrators_menu();break;    //跳转到管理员选择页面 
			case '2' : users_menu();break;    //跳转到用户选择页面 
			case '3' : notice_to_users();break;  //跳转到用户须知页面 
			case '0' : exit(0);                 //退出 
			default  : printf("您输入的数据非法!请您重新输入!!(按任意键返回输入)\n"); getch();
		}
		
	} 
}



//////////////////////////////////////////////////////////////////////////////////////
void character_menu()      //选择角色（管理员和用户）页面 的菜单显示 
{
	printf("\t\t\t----------------------------------\n");
	printf("\t\t\t|       图书信息管理系统系统     |\n");
	printf("\t\t\t----------------------------------\n");
	printf("\t\t\t|          1.管理员登录          |\n");
	printf("\t\t\t|          2.用户入口            |\n");
	printf("\t\t\t|          3.用户须知            |\n");
	printf("\t\t\t|          0.退出系统            |\n");
	printf("\t\t\t----------------------------------\n");
	printf("请输入指令：[\t]\b\b\b");

}

void notice_to_users()      //用户须知 
{
system("cls");
printf("\n这是一个图书信息管理系统，为了帮助您更快的了解并使用它，请先仔细阅读一下事项：\n");
printf("\t\t\t|                          注意事项                            |\n");
printf("\t\t\t|                     1.请按照指示进行操作!!                   |\n");
printf("\t\t\t|   2.管理员首次使用必须先进行初始化图书信息!!                 |\n");
printf("\t\t\t|   3.普通用户借书期限为60天，每超过一天就会罚款2元!!          |\n");
printf("\t\t\t|   4.普通用户如果有建议可在反馈箱向管理员反馈!!               |\n");
printf("\t\t\t|   5.预约功能只能在某种书库存为0的情况下进行!                 |\n");
printf("\t\t\t|   6.在输入数据时请严格按照指示进行否则系统可能奔溃!          |\n");
printf("\t\t\t|   7. 耗时3天，有bug是正常的!!                                |\n");
printf("\t\t\t|   8.作者是一名新手，如果存在bug可以聯係作者:                 |\n");
printf("\t\t\t|              qq郵箱：3111297446@qq.com                       |\n");
printf("\t\t\t|                   感謝使用該系統!!                           |\n");
system("pause");
}





/////////////////////////////////////////////////////////////////////////////////////////////////
void users_menu()      //用户选择页面 
{
   while(1)
    {
	    system("cls");
        char command5;
        users_menu1();
        command5=getch(); 
        switch(command5)
           {
        	    case '1' : print_book(head);break;
        	    case '2' :  find_book(head);break;
        	    case '3' :  borrowing_book();break;
        	    case '4' :  returning_book();break;
        	    case '5' :  administrators_suggestion_and_feedback();break;
        	    case '6' :  users_announcement() ;break;
        	    case '7' :  appointment_system();break;
            	case '8' :  return;
            	default  :printf("您输入的数据非法!请您重新输入!!(按任意键返回输入)\n");getch();
	        }
    }
}

void users_menu1()
{
	printf("\n\t\t\t++++++++++++++++++++++++\n\t\t\t+  欢迎来到用户选择页面  +\n\t\t\t++++++++++++++++++++++++\n");
    printf("\n		******************菜单栏*****************\n");
	printf("\t\t*\t      1.显示所有图书信息         *\n");
	printf("\t\t*\t      2.查询图书信息             *\n");
	printf("\t\t*\t      3.借阅图书                 *\n");
	printf("\t\t*\t      4.归还图书                 *\n");
	printf("\t\t*\t      5.给管理员的反馈与建议     *\n");
	printf("\t\t*\t      6.公告栏                   *\n");
	printf("\t\t*\t      7.预约系统                 *\n");
	printf("\t\t*\t      8.返回角色选择页面         *\n");
	printf("		*****************************************\n");
	printf("\n");
	printf("\t\t请输入指令：[\t]\b\b\b");
 } 
 
 
 
 
 /////////////////////////////////////////////////////////////////////////////////////////////
 

 void administrators_menu()    //管理员选择页面 
{   
    while(1)
	{
       system("cls");
	   char command1; 
       administrators_menu1();
       command1=getch();
       switch(command1)
       {
        	case '1' : administrators_login();break;
        	case '2' : administrators_registers();break;
        	case '3' : administrators_reback();break;
        	case '4' :return;
        	default  :printf("您输入的数据非法!请您重新输入!!(按任意键返回输入)\n");getch();
	   }
    }

} 

void administrators_menu1()       //管理员选择页面的菜单显示 
{
	printf("\n\t\t\t++++++++++++++++++++++++\n\t\t\t+  欢迎来到管理员选择页面  +\n\t\t\t++++++++++++++++++++++++\n");
    printf("\n		******************菜单栏*****************\n");
	printf("\t\t*\t      1.登录                    *\n");
	printf("\t\t*\t      2.没有账号？去注册        *\n");
	printf("\t\t*\t      3.忘记密码？去找回        *\n");
	printf("\t\t*\t      4.返回角色选择页面        *\n");
	printf("		*****************************************\n");
	printf("\n");
	printf("\t\t请输入指令：[\t]\b\b\b");
}



void administrators_registers()    //管理员账号注册页面 
{
	system("cls");
	Create_File();     //创建文件来储存管理员账号的信息 
	administrators_users a,b;
	FILE *fp;
	char temp[20];  //temp用来确认密码的 
	printf("\n欢迎来到管理员注册界面!\n");
	//Sleep(1000);            
    fp=fopen("administratorsusers.txt","r");
	printf("请输入账号：");
	scanf("%s",&a.id);
	if(fread(&b,sizeof(struct Administrators_users),1,fp)==1)
	{
		while(1)
		{
			if(strcmp(a.id,b.id))  
			{
				if(!feof(fp))
				{
					fread(&b,sizeof(struct Administrators_users),1,fp);
				}else
				  {
				     break;	
		   	   }
			}else
	     	 {
				printf("此用户名已存在!请重新注册!\n");
				Sleep(1000);
				fclose(fp);
				return;
		 	 }
	 	} 
	}

	 printf("请输入手机号码：");
	 scanf("%s",&a.phone);
	 printf("请输入密码：");
	 scanf("%s",&a.pw);
	 printf("请确认密码：");
	 scanf("%s",&temp);
	 while(1)
	 {
	 	if(!strcmp(a.pw,temp))
	 	{
	 		fp=fopen("administratorsusers.txt","a");
	 		fwrite(&a,sizeof(struct Administrators_users),1,fp);
	 		printf("账号注册成功，请登录!\n");
	 		system("pause");
	 		fclose(fp);
	 		return;
		 }else
		   {
		 	printf("两次密码不匹配!请重新输入密码：");
		 	scanf("%s",&a.pw);
		 	printf("请确认密码:");
		 	scanf("%s",&temp);
		   }
	 }
 } 
 
 void Create_File()     //创建储存管理员用户账号密码的文件 
{
	 FILE *fp;
     if ((fp = fopen("administratorsusers.txt","r"))==NULL) /*如果此文件不存在*/
     {
         if ((fp = fopen("administratorsusers.txt","w+"))==NULL)
          {
              printf("无法建立文件!\n");
              exit(0);
          }
     }  
     fclose(fp);
}

void administrators_login()     //管理员账号登录页面 
{
	system("cls");
	administrators_users a,b;
	FILE *fp; 
	if((fp=fopen("administratorsusers.txt","r"))==NULL) 
	{
		printf("\n暂无账号密码信息，请先注册!!\n");
		system("pause");
		return;
	}

	printf("欢迎来到管理员登录页面\n");
	printf("请输入账号:");
	scanf("%s",&a.id);
	printf("请输入密码:"); 
	scanf("%s",&a.pw);
	fread(&b,sizeof(struct Administrators_users),1,fp);      //注意算法：账号先检查，若不正确则结束； 
	while(1)                                          //若正确则检查密码，只检查一次 
	{
		if(strcmp(a.id,b.id)==0)
		{
			break;
		}else
		  {
			if(!feof(fp))
			{
				fread(&b,sizeof(struct Administrators_users),1,fp);
			}else
			  {
				printf("账号或者密码有误!!\n");
				fclose(fp);
				Sleep(1000);
				system("pause");
				return;
			  }
		  }
	}
	fclose(fp);
	if(strcmp(a.pw,b.pw)==0)
	{
		printf("登录成功!欢迎使用!\n");
		system("pause");
		administrators_side_operation();     //////////////
    }else
      {
      	printf("账号或密码有误!!\n");
      	system("pause");
      	system("cls");
      	return;
	  }
}

void administrators_reback()        //管理员密码找回页面 
{
	system("cls");
	administrators_users a,b;
	FILE *fp;
	if((fp=fopen("administratorsusers.txt","r"))==NULL) 
	{
		printf("\n暂无账号密码信息，请先注册!!\n");
		system("pause");
		return;
	}
	printf("欢迎来到管理员找回密码界面!\n");
	fp=fopen("administratorsusers.txt","r");
	fread(&b,sizeof(struct Administrators_users),1,fp);
	printf("请输入账号：\n");
	scanf("%s",&a.id);
	while(1)
	{
		if(strcmp(a.id,b.id)==0)
		{
			printf("输入的账号正确!我们将发送验证码!!\n");
			Sleep(2000);
			break;
		}else
		 {
			if(!feof(fp))
			{
				fread(&b,sizeof(struct Administrators_users),1,fp); 
			}else
			  {
			  	printf("您输入的账号不存在!!即将退出!!\n");
			  	fclose(fp);
			  	Sleep(2000);
			  	system("pause");
			  	system("cls");
			  	return;
			  }
		 }
	 } 
	 char phone_tail[5];                                                 //phone_tail[5]用来储存手机尾号（4个数） 
	 strncpy(phone_tail,b.phone+7,4);                                             
	 int system_verification_code=0,manual_verification_code=0,i;       //system_verification_code代表系统发送的验证码 
	//                                                                  // manual_verification_code代表人工输入的验证码 
	srand((unsigned)time(0));                                           //srand((unsigned) seed )是随机数发生器的初始化函数(注意每个种子对应一种随机数，我们一般使用系统时间time()函数!!) 
	 for(i=0;i<10;i++)                                        
	 {
	 	system_verification_code+=( rand () % 500 );                    //rand()%500:随机产生0-499之间的数;  rand()%500+1:1-500之间;  rand()%41+80：80-120之间 
	 }
	 printf("我们已向尾号为 %s 的手机号码发送了验证码 %d ,请注意查收!\n请您输入验证码：",phone_tail,system_verification_code);
	scanf("%d",&manual_verification_code);
	for(i=3;i>=00;i--)
	{
		if(system_verification_code==manual_verification_code)
		{
			printf("验证码输入正确!!\n我们已帮您找回密码：");
			printf("%s",&b.pw);
			printf("\n按任意键返回管理员选择页面进行登录!!\n");
			getch();
			fclose(fp);
		    return;
		}else
		  {
		  	printf("\n验证码输入错误，您剩下 %d 次机会!!\n请重新输入验证码：",i);
		  	scanf("%d",&manual_verification_code);
		  	printf("\n");
		  }
	}
	printf("您已多次输入错误!!即将返回!!");
	system("pause");
	Sleep(2000);
	fclose(fp);
	return;
}


void administrators_side_operation_menu()
{
	printf("\n\t\t\t++++++++++++++++++++++++\n\t\t\t+ 欢迎来到管理员端操作页面 +\n\t\t\t++++++++++++++++++++++++\n");
    printf("\n		******************菜单栏*****************\n");
	printf("\t\t*\t      1.返回管理员选择页面      *\n");
	printf("\t\t*\t      2.初始化图书信息          *\n");
	printf("\t\t*\t      3.批量增加图书信息        *\n");
	printf("\t\t*\t      4.批量删除图书信息        *\n");
    printf("\t\t*\t      5.批量修改图书信息        *\n");
	printf("\t\t*\t      6.保存图书信息            *\n");
	printf("\t\t*\t      7.显示全部图书信息        *\n");
	printf("\t\t*\t      8.查询图书信息            *\n");
	printf("\t\t*\t      9.备份图书信息            *\n");
	printf("\t\t*\t      a.排序功能     	       *\n"); 
	printf("\t\t*\t      b.查看借阅人信息          *\n");
	printf("\t\t*\t      c.管理员端建议与反馈      *\n");
	printf("\t\t*\t      d.管理员端公告            *\n");
	printf("		*****************************************\n");
	printf("\n");
	printf("\t\t请输入指令：[\t]\b\b\b");
}

void administrators_side_operation()    //管理员端操作页面 
{
//	bookinformation *head;
//	head=NULL; 
	system("cls");
	char command2;   
	administrators_side_operation_menu();
	command2=getch();
	getch(); 
    while(command2)
	{
		if(command2=='1')
		{
			return;
		}else if(command2=='2')
		{
			if(head == NULL)
			{
					head =creat();
			}else
			{
				printf("\n系统先前已经初始化图书信息(按任意键返回输入)\n");getch(); 
			}
		}else if(command2=='3')
		{
			add_book( head );
		}else if(command2=='4')
		{
			head=del_book( head );
		}else if(command2=='5')
		{
			change_book( head );
		}else if(command2=='6')
		{
			reserve_book1( head );
			reserve_book( head );
		}else if(command2=='7')
		{
			print_book(head);
		}else if(command2=='8')
		{
			find_book(head);
		}else if(command2=='9')
		{
			backup_book(head);
		}else if(command2=='a')
		{
			head=sort( head );
		}else if(command2=='b')
		{
			print_borrowers(head1); 
		}else if(command2=='c')
		{
			users_suggestion_and_feedback();
		}else if(command2=='d') 
		{
			administrators_announcement();
		}else
		{
			printf("\n您输入的数据非法!请您重新输入!!(按任意键返回输入)\n");getch(); 
		}
		system("cls");
		administrators_side_operation_menu();
		command2=getch();
		
	}
	
}

bookinformation *creat()            //指向bookinformation结构体类型指针函数用于创建链表并初始化数据
{
	system("cls");
	printf("欢迎来到初始化图书信息页面!!\n");
	bookinformation *head1;
	bookinformation *p1,*p2;
	head1=NULL;
	int number=1;     
	p1=p2=(struct _bookinformation *)malloc(LEN);
	printf("请输入图书信息\n(编号、书名、作者、出版社、类别、出版时间、价格、库存)(当输入的编号为 0 时则结束,后面输入的数据无效)\n");
	scanf("%ld%s%s%s%s%ld%f%ld",&p1->id,&p1->name,&p1->author,&p1->publisher,&p1->type,&p1->pubtime,&p1->price,&p1->num);
	p1->bnum=0;
	
	p1->L.front=NULL;      //////////////////////////////////
	p1->L.rear=p1->L.front; 
	
	while(p1->id !=0)
	{
		if(number==1)
		{
			head1=p1;
			number++;
		}else
		  {
		  	p2->next=p1;
		  }
		  p2=p1;
		  p1=(struct _bookinformation *)malloc(LEN);
		  printf("请输入图书信息\n(编号、书名、作者、出版社、类别、出版时间、价格、库存)(当输入的编号为 0 时则结束,后面输入的数据无效)\n");
	      scanf("%ld%s%s%s%s%ld%f%ld",&p1->id,&p1->name,&p1->author,&p1->publisher,&p1->type,&p1->pubtime,&p1->price,&p1->num);
	      p1->bnum=0;
	      
	   	  p1->L.front=NULL;      //////////////////////////////////
		  p1->L.rear=p1->L.front; 
	      
	} 
	p2->next=NULL;
	printf("初始化图书信息已完成!!\n");
	system("pause"); 
	Sleep(1000);
	return(head1); 
}

void add_book(bookinformation *head)           //批量增加图书信息 
{
	system("cls");
	if(head==NULL)
	{
		printf("您未进行初始化图书信息!!\n请您按任意键返回管理员端操作页面!!\n");
		system("pause"); 
		return;
	}
	printf("欢迎来到增加图书信息页面!!\n");
	bookinformation *p1,*p2;
	p2=head;
	while(1)
	{
		if(p2->next==NULL)
		{
			p1=(struct _bookinformation *)malloc(LEN);
			printf("请输入图书信息\n(编号、书名、作者、出版社、类别、出版时间、价格、库存)(当输入的编号为 0 时则结束,后面输入的数据无效)\n");
			scanf("%ld%s%s%s%s%ld%f%ld",&p1->id,&p1->name,&p1->author,&p1->publisher,&p1->type,&p1->pubtime,&p1->price,&p1->num);
			p1->bnum=0;
			
			p1->L.front=NULL;      //////////////////////////////////
			p1->L.rear=p1->L.front; 
			
	        while(p1->id!=0)
	        {
	        	p2->next=p1;
	        	p2=p1;
	        	p1=(struct _bookinformation *)malloc(LEN);
				printf("请输入图书信息\n(编号、书名、作者、出版社、类别、出版时间、价格、库存)(当输入的编号为 0 时则结束,后面输入的数据无效)\n");
				scanf("%ld%s%s%s%s%ld%f%ld",&p1->id,&p1->name,&p1->author,&p1->publisher,&p1->type,&p1->pubtime,&p1->price,&p1->num);
				p1->bnum=0;
				
				p1->L.front=NULL;      //////////////////////////////////
				p1->L.rear=p1->L.front; 
				
			}
	        p2->next=NULL;
	        break;
		}
		p2=p2->next;
	}
	printf("增加图书信息成功!!\n即将返回管理员端操作页面!!\n");
	system("pause");
	Sleep(2000);
	return;
}



bookinformation *del_book(bookinformation *head)     //批量删除图书信息 
{
	system("cls");
	if(head==NULL)
	{
		printf("您未进行初始化图书信息!!\n请您按任意键返回管理员端操作页面!!\n");
		system("pause"); 
		return head;
	}
	char isAgain; 
	bookinformation *p,*p1;
	long id;
	printf("欢迎来到删除图书信息页面!!\n请输入要删除图书的编号：");
	scanf("%ld",&id);
again://注意!!

    p=head;
	while(1)
	{

		if(head->id==id)
		{
			head=head->next;
			free(p);     //释放动态内存 
			if(head == NULL)    
			{
				break;
			} 
			printf("继续删除图书信息按 1 ，返回管理员端操作页面按 2 \n");
			isAgain=getch();
			if(isAgain=='1')
			{
				printf("请输入要删除图书的编号：");
				scanf("%ld",&id);
				goto again;                                    //注意!!! 
			}
			else if(isAgain=='2')
			{
				break;
		    }
			else
			{
				printf("输入错误!!\n");
				Sleep(2000);
				break;
			}
		}else
		{
			p1=p;
			p1=p->next;   //p1指向下一动态内存存储区 
			
			if(p1==NULL)
			{
				printf("您输入的编号有误!!!\n即将返回管理员端操作页面!!\n");
		   		system("pause");
		   		Sleep(2000);
		   		return head;
			}
			 	
			if(p1->id==id)
			{
				p->next=p1->next;   //两个动态存储区连接处跳开中间的p1 
				p=p1;
				free(p1);
				printf("继续删除图书信息按 1 ，返回管理员端操作页面按 2 \n");
				isAgain=getch();
				if(isAgain=='1')
				{
					printf("请输入要删除图书的编号：");
					scanf("%ld",&id);
					goto again;
				} 
				else if(isAgain=='2')
				{
					break;
				}
				else
			    {
				printf("输入错误!!\n");
				Sleep(2000);
				break;
			    }
			}
			
			
			p=p->next;  
		   if(p->next==NULL)
		   {
		   	printf("您输入的编号有误!!!\n即将返回管理员端操作页面!!\n");
		   	system("pause");
		   	Sleep(2000);
		   	return head;
		   }
		}
	}
	
	
	printf("成功删除指定图书信息!!\n即将返回管理员端操作页面!!\n");
	Sleep(2000);
	system("pause");
	return head; 
 } 
 
void change_book(bookinformation *head)             //批量修改图书信息 
 {
 	system("cls");
 	if(head==NULL)
	{
		printf("您未进行初始化图书信息!!\n请您按任意键返回管理员端操作页面!!\n");
		system("pause"); 
		return;
	}
	printf("欢迎您来到修改图书信息页面!!\n");
	bookinformation *p;
	long id,pubtime,num;
	char publisher[50];
	char name[30];
	char author[30];
	char type[30];
	char isAgain; 
	float price;
	printf("请您输入要修改图书的编号:");
	scanf("%ld",&id);
	
again:                        //注意!!!	
	
	p=head;
	while(1)
	{
		if(p->id==id)
		{
			break;
		}
		p=p->next;
		if(p==NULL)
	    {
		    printf("未找到该图书的信息!!!\n即将返回管理员端操作页面!!\n");
		    system("pause");
		    return;
	    }
	}
	
	printf("请输入图书信息\n(编号、书名、作者、出版社、类别、出版时间、价格、库存)\n");
	scanf("%ld%s%s%s%s%ld%f%ld",&id,&name,&author,&publisher,&type,&pubtime,&price,&num);
    p->id=id;
    strcpy(p->type,type);
    strcpy(p->name,name);
    strcpy(p->author,author);
    strcpy(p->publisher,publisher);
    p->price=price;
    p->num=num;
    printf("继续修改图书信息按 1 ，返回管理员端操作页面按 2 \n");
	isAgain=getch();
	if(isAgain=='1')
	{
		printf("请输入要修改图书的编号：");
		scanf("%ld",&id);
		goto again;                                    //注意!!! 
	}
	else if(isAgain=='2')
	{
		return;
	}
	else
	{
		printf("输入错误!!\n");
		system("pause");
		Sleep(2000);
		return;
	}
 }
 
 void reserve_book(bookinformation *head)       //保存图书信息到 book1.txt(二进制文件) 
{
	system("cls");
	Create_File2();  //创建book1.txt 
	FILE *fp;
	bookinformation *p ;
	p=head;
	fp=fopen("book1.txt","wb");
	while(p!=NULL)
	{
		fwrite(p,sizeof(struct _bookinformation),1,fp);
		p=p->next;
	}
	fclose(fp);
	printf("图书信息已保存到文件book1.txt!!");
	system("pause");
	Sleep(2000);
	return;
	 
} 
void reserve_book1(bookinformation *head)        //保存图书信息到book.txt(文本文件） 
{
	system("cls");
	Create_File1();       //创建book.txt 
	FILE *fp;
	bookinformation *p ;
	p=head;
	fp=fopen("book.txt","w");
	while(p!=NULL)
	{
	    fprintf(fp,"%ld %s %s %s %s %ld %.1f %ld %ld ",p->id,p->name,p->author,p->publisher,p->type,p->pubtime,p->price,p->num,p->bnum);
		p=p->next;
	}
	fclose(fp);
	printf("图书信息已保存到文件book.txt!!");
	system("pause");
	Sleep(2000);
	return;
}

void Create_File1()             //创建储存图书信息的文件 book.txt
{
	system("cls"); 
	FILE *fp;
    if ((fp = fopen("book.txt","r"))==NULL) /*如果此文件不存在*/
    {
        if ((fp = fopen("book.txt","w+"))==NULL)
        {
            printf("无法建立文件!\n");
            Sleep(1000);
            exit(0);
        }
    }  
    fclose(fp);
}

void Create_File2()             //创建储存图书信息的文件 book1.txt
{
	FILE *fp;
    if ((fp = fopen("book1.txt","rb"))==NULL) /*如果此文件不存在*/
    {
        if ((fp = fopen("book1.txt","wb+"))==NULL)
        {
            printf("无法建立文件!\n");
            Sleep(1000);
            exit(0);
        }
    }  
    fclose(fp);
}


void print_book(bookinformation *head)        //显示已保存全部图书信息 
{
    system("cls");
 	//FILE *fp;
 	if(head==NULL)      //判断有无初始化 
	{
		printf("未进行初始化图书信息!!\n请按任意键返回!!\n");
		system("pause"); 
		return;
	}
	bookinformation *p;
	p=head;
	int count =1;
	printf("------------------------------------------------图书信息--------------------------------------------------------\n");
	printf("序号\t编号\t书名\t作者\t出版社\t类别\t出版时间\t价格\t库存\t已借出\n");
	while(p!=NULL)
	{
		printf("%d\t%ld\t%s\t%s\t%s\t%s\t%ld\t%.1f\t%ld\t%ld\n",count,p->id,p->name,p->author,p->publisher,p->type,p->pubtime,p->price,p->num,p->bnum);
		p=p->next; 
		count++;
	 } 
	printf("\n以上为全部图书的信息\n");
	printf("\n");
	system("pause");
	return;
	/*
	if ((fp = fopen("book1.txt","rb"))==NULL) //如果此文件不存在
    {
        printf("您未保存文件!!!\n即将返回管理员端操作页面!!!\n");
        system("pause");
		return; 
    }
 	printf("------------------------------------------------图书信息--------------------------------------------------------\n");
 	printf("编号\t书名\t作者\t出版社\t类别\t出版时间\t价格\t库存\n");
    fp=fopen("book1.txt","rb"); 
    
    bookinformation *p;
    
    while(1)
    {
        if(fread(p,sizeof(struct _bookinformation),1,fp)==1) //这一行不知道为什么运行失误？从文件读取信息并打印 
        {
            printf("%ld\t%s\t%s\t%s\t%s\t%ld\t%.1f\t%ld\n",p->id,p->name,p->author,p->publisher,p->type,p->pubtime,p->price,p->num);
		
		}
		else
		{
			printf("\n以上为已保存的全部图书的信息\n");
			fclose(fp);
			system("pause");
			return;
		}
	} 
	*/
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void find_book(bookinformation *head)         //查询图书信息页面 
{
	system("cls");
	if(head==NULL)      //判断有无初始化 
	{
		printf("未进行初始化图书信息!!\n请按任意键返回!!\n");
		system("pause"); 
		return;
	}
	printf("欢迎来到查询图书信息页面!!!\n提示：\n1.输入'1'按编号查询;\n2.输入'2'按书名查询;\n3.输入'3'按作者查询;\n4.输入'4'按出版社查询;\n5.输入'5'按价格范围查询;\n6.输入'6'返回管理员端操作页面;\n");
	char command3;
	printf("请输入指令:"); 
	command3=getch();
	while(1)
	{
		if(command3=='1')
		{
			find_book_id(head);
		}else if(command3=='2')
		{
			find_book_name(head); 
		}else if(command3=='3')
		{
		   find_book_author(head);
		}else if(command3=='4')
		{
			find_book_publisher(head);
		}else if(command3=='5')
		{
			find_book_price(head); 
		}else if(command3=='6')
		{
			printf("\n即将返回!!");
			Sleep(2000);
			return;
		}else
		{
		  printf("\n输入有误!!!\n");
		  Sleep(2000);
		}
		system("cls");
		printf("欢迎来到查询图书信息页面!!!\n提示：\n1.输入'1'按编号查询;\n2.输入'2'按书名查询;\n3.输入'3'按作者查询;\n4.输入'4'按出版社查询;\n5.输入'5'按价格范围查询;\n6.输入'6'返回管理员端操作页面;\n");
		printf("请输入指令："); 
		command3=getch();
	}
	 
	
 } 

 void find_book_id(bookinformation *head)         //通过编号查询图书信息 
 {
 	system("cls");
 	bookinformation *p;
 	p=head;
 	long id;
 	printf("请输入图书的编号:");
 	scanf("%ld",&id);
 	while(p!=NULL)                        //采用遍历的方法 
 	{
 		if(p->id==id)
 		{
 			printf("------------------------------------------------图书信息--------------------------------------------------------\n");
 	        printf("编号\t书名\t作者\t出版社\t类别\t出版时间\t价格\t库存\t已借出\n");
 	        printf("%ld\t%s\t%s\t%s\t%s\t%ld\t%.1f\t%ld\t%ld\n",p->id,p->name,p->author,p->publisher,p->type,p->pubtime,p->price,p->num,p->bnum);
 	        printf("\n以上为该图书信息!!按任意键返回!!\n");
 	        system("pause");
 	        break;
		}else if(p->next==NULL)
		{
			printf("未找到该图书!!请按任意键返回!");
			system("pause");
			break;
		}
		p=p->next;
		
	}
 }
 
void find_book_name(bookinformation *head)       //通过书名查询图书信息 
 {
 	system("cls");
 	bookinformation *p;
 	p=head;
 	char name[30];
 	printf("请输入图书书名:");
 	scanf("%s",name);
 	while(p!=NULL)                        //采用遍历的方法 
 	{
 		if(strcmp(name,p->name)==0)
 		{
			printf("------------------------------------------------图书信息--------------------------------------------------------\n");
 	        printf("编号\t书名\t作者\t出版社\t类别\t出版时间\t价格\t库存\t已借出\n");
 	        printf("%ld\t%s\t%s\t%s\t%s\t%ld\t%.1f\t%ld\t%ld\n",p->id,p->name,p->author,p->publisher,p->type,p->pubtime,p->price,p->num,p->bnum);
 	        printf("\n以上为该图书信息!!按任意键返回!!\n");
 	        system("pause");
 	        break;
		}else if(p->next==NULL)
		{
			printf("未找到该图书!!请按任意键返回!");
			system("pause");
			break;
		}
		p=p->next;	
	}
 }
 
 void find_book_author(bookinformation *head)       //通过作者查询图书信息 
 {
 	system("cls");
 	bookinformation *p;
 	p=head;
 	char author[30];
 	printf("请输入作者名:");
 	scanf("%s",author);
 	while(p!=NULL)                        //采用遍历的方法 
 	{
 		if(strcmp(author,p->author)==0)
 		{
			printf("------------------------------------------------图书信息--------------------------------------------------------\n");
 	        printf("编号\t书名\t作者\t出版社\t类别\t出版时间\t价格\t库存\t已借出\n");
 	        printf("%ld\t%s\t%s\t%s\t%s\t%ld\t%.1f\t%ld\t%ld\n",p->id,p->name,p->author,p->publisher,p->type,p->pubtime,p->price,p->num,p->bnum);
 	        printf("\n以上为该图书信息!!按任意键返回!!\n");
 	        system("pause");
 	        break;
		}else if(p->next==NULL)
		{
			printf("未找到该图书!!请按任意键返回!");
			system("pause");
			break;
		}
		p=p->next;	
	}
 }
 
void find_book_publisher(bookinformation *head)       //通过出版社查询图书信息 
{
 	system("cls");
 	bookinformation *p;
 	p=head;
 	char publisher[50];
 	printf("请输入出版社:");
 	scanf("%s",publisher);
 	while(p!=NULL)                        //采用遍历的方法 
 	{
 		if(strcmp(publisher,p->publisher)==0)
 		{
			printf("------------------------------------------------图书信息--------------------------------------------------------\n");
 	        printf("编号\t书名\t作者\t出版社\t类别\t出版时间\t价格\t库存\t已借出\n");
 	        printf("%ld\t%s\t%s\t%s\t%s\t%ld\t%.1f\t%ld\t%ld\n",p->id,p->name,p->author,p->publisher,p->type,p->pubtime,p->price,p->num,p->bnum);
 	        printf("\n以上为该图书信息!!按任意键返回!!\n");
 	        system("pause");
 	        break;
		}else if(p->next==NULL)
		{
			printf("未找到该图书!!请按任意键返回!");
			system("pause");
			break;
		}
		p=p->next;	
	}
}

void find_book_price(bookinformation *head)    //通过价格的范围查询图书信息 
 {
 	system("cls");
 	bookinformation *p;
 	p=head;
 	int n=0;
 	float priceMax,priceMin;
 	printf("请输入价格最大值:");
	scanf("%f",&priceMax);
	printf("请输入价格最小值:");
	scanf("%f",&priceMin);
	system("cls");
	printf("------------------------------------------------图书信息--------------------------------------------------------\n");
	printf("编号\t书名\t作者\t出版社\t类别\t出版时间\t价格\t库存\t已借出\n");
 	while(p!=NULL)                                    //同理遍历 
	 {
	 	if((p->price)<=priceMax&&(p->price)>=priceMin)
		 {
		 	n=1;
		 	printf("%ld\t%s\t%s\t%s\t%s\t%ld\t%.1f\t%ld\t%ld\n",p->id,p->name,p->author,p->publisher,p->type,p->pubtime,p->price,p->num,p->bnum);
	     }
		 p=p->next;
	  } 
	  if(n==0)
	  {
	  	printf("未找到符合条件的图书!!请按任意键返回!");
		system("pause");
		return;
	  }else if(n==1)
	  {
	  		printf("\n以上为该图书信息!!按任意键返回!!\n");
 	        system("pause");
 	        return;
	  }
 }
 
 
 //////////////////////////////////////////////////////////////////////////////////////////////
 
 
 void backup_book(bookinformation *head)        //备份图书信息（将book.txt备份到backup.txt） 
{
	system("cls");
	if(head==NULL)      //判断有无初始化 
	{
		printf("您未进行初始化图书信息!!\n请您按任意键返回管理员端操作页面!!\n");
		system("pause"); 
		return;
	}
	FILE *in,*out;
	char ch;
	if((in=fopen("book.txt","r"))==NULL)
	{
		printf("打开book.txt文件失败!!!");
		Sleep(2000);
		fclose(in);
		fclose(out);
		exit(0);
	}
	if((out=fopen("backup.txt","w"))==NULL)
	{
		printf("打开备份文件失败!!!");
		Sleep(2000);
		fclose(in);
		fclose(out);
		exit(0);
	}
	ch=fgetc(in);
	while(!feof(in))
	{
		fputc(ch,out);
		ch=fgetc(in);
	}
	fclose(in);
	fclose(out);
	printf("成功备份!!!\n");
	system("pause");
	Sleep(2000);
	return;
}


/////////////////////////////////////////////////////////////////////////////////////////////

bookinformation *sort(bookinformation *head)                       //排序选择页面 
{
	system("cls");
	if(head==NULL)      //判断有无初始化 
	{
		printf("您未进行初始化图书信息!!\n请您按任意键返回管理员端操作页面!!\n");
		system("pause"); 
		return head;
	}
	int number;
	number=number_of_book(head);
	printf("欢迎来到排序功能页面!!\n提示:\n1.'1'代表按编号排序;\n2.'2'代表按价格排序;\n3.'3'代表按库存排序;\n4.'4'代表按出版时间排序;\n5.'5'代表返回管理员端操作系统;\n");
	printf("请输入指令:");
	char command4;
	command4=getch();
	while(1)
	{
		if(command4=='1')
		{
			head=sort_book(number , head , compare_id);
			printf("\n按编号排序\n");
			print(head);
			system("pause");
		}else if(command4=='2')
		{
		  head=sort_book(number , head , compare_price);
		  printf("\n按价格排序\n");
		  print(head);
		  system("pause"); 
		  
		}else if(command4=='3')
		{
		   head=sort_book(number , head , compare_num);
		   printf("\n按库存排序\n");
		   print(head);
		   system("pause");
		}else if(command4=='4')
		{
		   head=sort_book(number , head , compare_pubtime);
		   printf("\n按出版时间排序\n");
		   print(head);
		   system("pause"); 
		}else if(command4=='5')
		{
			printf("\n即将返回管理员端操作页面!!");
			Sleep(2000);
			return head;
		}else
		{
		  printf("\n输入有误!!!\n");
		  Sleep(2000);
		}
		system("cls");
		printf("欢迎来到排序功能页面!!\n提示:\n1.'1'代表按编号排序;\n2.'2'代表按价格排序;\n3.'3'代表按库存排序;\n4.'4'代表按出版时间排序;\n5.'5'代表返回管理员端操作系统;\n");
		printf("请输入指令："); 
		command4=getch();
    }
}

int number_of_book(bookinformation *head)         //计算图书数量 
{
	bookinformation *p;
	p=head;
	int n=1;
	while(p->next!=NULL)
	{
		n++; 
		p=p->next; 
	}
	return n;
}

void print(bookinformation *head)    //显示排序后的图书信息 
{
	bookinformation *p;
	p=head;
	int count =1;
	printf("------------------------------------------------图书信息--------------------------------------------------------\n");
	printf("序号\t编号\t书名\t作者\t出版社\t类别\t出版时间\t价格\t库存\t已借出\n");
	while(p!=NULL)
	{
		printf("%d\t%ld\t%s\t%s\t%s\t%s\t%ld\t%.1f\t%ld\t%ld\n",count,p->id,p->name,p->author,p->publisher,p->type,p->pubtime,p->price,p->num,p->bnum);
		p=p->next; 
		count++;
	 } 
	 printf("\n");
}

bookinformation *sort_book(int number , bookinformation *head , int(*compare)(bookinformation *p))   // 链表冒泡排序(最难的!!!) 
{
	system("cls");
	int t;
	printf("提示；\n1.输入'0'代表小->大;\n2.输入'2'代表大->小;\n");
	scanf("%d",&t);
	
	int i,j;
	bookinformation *p;
	p=head;
	if(t==0||t==2)
	{
	for(i=0;i<number-1;i++)
	{
		p=head;
		for(j=0;j<number-1-i;j++)
		{
			if(compare(p)>0 && t==0)
			{
			    swap(p); 
			    
			}else if(compare(p)<0 && t==2 )
			{
				 swap(p); 
			}
			p=p->next; 
		}
	}
    }else
    {
    	printf("输入有误!!!\n仍按原序列排序!!");
    	system("pause");
    	return head;
	}
	return head;
}


void swap(bookinformation *p)      //交换p和p->next的内容 
{
	bookinformation *temp;
	temp=(struct _bookinformation *)malloc(LEN);
	      	//把p->next的内容放到temp 
				temp->id=p->next->id;
				temp->pubtime=p->next->pubtime;
				temp->num=p->next->num;
				temp->price=p->next->price;
				strcpy(temp->name,p->next->name);
				strcpy(temp->publisher,p->next->publisher);
				strcpy(temp->author,p->next->author);
				strcpy(temp->type,p->next->type);
				//把p的内容放到p->next
				p->next->id=p->id;
				p->next->pubtime=p->pubtime;
				p->next->num=p->num;
				p->next->price=p->price;
				strcpy(p->next->publisher,p->publisher);
				strcpy(p->next->name,p->name);
				strcpy(p->next->author,p->author);
				strcpy(temp->type,p->next->type);
				//把temp的内容放到p
				p->id=temp->id;
				p->pubtime=temp->pubtime;
				p->num=temp->num;
				p->price=temp->price;
				strcpy(p->publisher,temp->publisher);
				strcpy(p->name,temp->name);
				strcpy(p->author,temp->author);
				strcpy(temp->type,p->next->type); 
}


int compare_id(bookinformation *p)       //比较p和p->next的编号大小 
{
	return (p->id - p->next->id);
}

int compare_pubtime(bookinformation *p)       //比较p和p->next的出版时间大小 
{
	return (p->pubtime - p->next->pubtime);
}

int compare_price(bookinformation *p)       //比较p和p->next的价格大小 
{
	return (p->price - p->next->price);
}

int compare_num(bookinformation *p)       //比较p和p->next的库存大小 
{
	return (p->num - p->next->num);
}



void print_borrowers(borrowers *head1)        //显示已全部借阅人信息 
{
    system("cls");
 	//FILE *fp;
 	if(head1==NULL)      //判断有无初始化 
	{
		printf("暂无借阅信息!!\n请您按任意键返回管理员端操作页面!!\n");
		system("pause"); 
		return;
	}
	borrowers *p;
	p=head1;
	int count =1;
	printf("------------------------------------------------借阅人信息--------------------------------------------------------\n");
	printf("序号\t姓名\t身份证\t\t借阅书籍\t年 -月-日\t借书天数\t罚款余额\n");
	while(p!=NULL)
	{
		printf("%d\t%s\t%ld\t\t%s\t\t%d-%d-%d\t%d\t%d\n",count,p->name,p->id,p->bookname,p->year,p->month,p->day,p->time,p->money);
		p=p->next; 
		count++;
	 } 
	printf("\n以上为全部借阅人的信息\n");
	printf("\n");
	system("pause");
	return;
}


void borrowing_book()       //借阅书籍 
{
///////////////////////
	time_t timep;
    struct tm *p4;
    time (&timep);
    p4=gmtime(&timep);
    int time;
    int money; 
////////////////////
	system("cls");
	if(head == NULL)
	{
		printf("\n暂无图书可借!!请联系管理员!!\n");
		Sleep(1000);
		system("pause");
		return ; 
	}
	if(head1 == NULL)
	{
		head1 = creat1();
		return;
	}else
	{
		system("cls");
		printf("欢迎来到借阅图书页面!!\n");
		Sleep(1000);
		borrowers *p,*p1,*p3;
		bookinformation *p2;
		p2=head;
		p=head1;
		p3=head1;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p1=(struct _borrowers*)malloc(LEN1);
		printf("请输入借阅信息信息\n(姓名、身份证、书名、年、月、日)\n");
		scanf("%s%ld%s%d%d%d",&p1->name,&p1->id,&p1->bookname,&p1->year,&p1->month,&p1->day);
		
		if((p1->month==(1+p4->tm_mon))&&((p1->day)>(p4->tm_mday)))
		{
			printf("\n非常抱歉!!您输入错误!!!\n");
			system("pause");
			Sleep(1000);
			return ;
		}
		
		while(p3!=NULL)
		{
			if((p1->id==p3->id)&&(strcmp(p1->name,p3->name)!=0))
			{
				printf("\n非常抱歉!!您输入的信息是错误的!!!\n");
				system("pause");
				Sleep(1000);
				return ;
			}
			p3=p3->next; 
		}
		
		if((p1->year>0&&p1->year<=2023)&&(p1->month>=1&&p1->month<=12)&&(p1->day>=0&&p1->day<=30))
		{
			p1->time = ((1900+p4->tm_year)*365+(1+p4->tm_mon)*31+p4->tm_mday)-(p1->year*365+p1->month*31+p1->day);
			if(p1->time>60)
			{
				p1->money=(p1->time-60)*2;
			}else
			{
				p1->money=0;
			}
			
			while(p2!=NULL)
			{
				if(strcmp(p2->name,p1->bookname)==0)
				{
					if(p2->num>0)
					{
						p2->num--;
						p2->bnum++;
						p1->next=NULL; 
						p->next=p1;
						printf("\n借阅成功!!\n");
						system("pause"); 
						Sleep(1000);
						return;
					}else if(p2->num==0)
					{
						printf("\n非常抱歉!!您想借阅的书籍库存为0!!\n");
						system("pause"); 
						Sleep(1000); 
						return ;
					}
				}
				p2=p2->next;
			}
		}
		
		printf("\n非常抱歉!!您输入的图书名是错误的!!!\n");
		system("pause");
		Sleep(1000);
		return ;
		

	}
} 


borrowers *creat1()            //指向borrowers结构体类型指针函数用于创建链表数据 
{
	///////////////////////
	time_t timep;
    struct tm *p3;
    time (&timep);
    p3=gmtime(&timep);
    int time;
    int money; 
	////////////
	system("cls");
	printf("欢迎来到借阅图书页面!!\n");
	borrowers *p1;
	bookinformation *p2;
	p2=head;
	p1=(struct _borrowers*)malloc(LEN1);
	printf("请输入借阅信息信息\n(姓名、身份证、书名、年、月、日)\n");
	scanf("%s%ld%s%d%d%d",&p1->name,&p1->id,&p1->bookname,&p1->year,&p1->month,&p1->day);

	if((p1->month==(1+p3->tm_mon))&&((p1->day)>(p3->tm_mday)))
	{
		printf("\n非常抱歉!!您输入错误!!!\n");
		system("pause");
		Sleep(1000);
		return NULL;
	}
	if((p1->year>0&&p1->year<=2023)&&(p1->month>=1&&p1->month<=(1+p3->tm_mon))&&(p1->day>=1&&p1->day<=30))
	{
		p1->time = ((1900+p3->tm_year)*365+(1+p3->tm_mon)*31+p3->tm_mday)-(p1->year*365+p1->month*31+p1->day);
		if(p1->time>60)
		{
			p1->money=(p1->time-60)*2;
		}else
		{
			p1->money=0;
		}
		while(p2!=NULL)
		{
			if(strcmp(p2->name,p1->bookname)==0)
			{
				if(p2->num>0)
				{
					p2->num--;
					p2->bnum++;
					p1->next=NULL; 
					printf("\n借阅成功!!\n");
					system("pause"); 
					Sleep(1000);
					return(p1);
				}else if(p2->num==0)
				{
					printf("\n非常抱歉!!您想借阅的书籍库存为0!!\n");
					system("pause"); 
					Sleep(1000); 
					return NULL;
				}
			}
			p2=p2->next;
		}
	}
	
	printf("\n非常抱歉!!您输入错误!!!\n");
	system("pause");
	Sleep(1000);
	return NULL;
	



}

void returning_book()           //归还图书      ///////////////
{
	system("cls");
	printf("欢迎来到归还图书页面!!\n");
	if(head1==NULL)      //判断有无借阅信息 
	{
		printf("暂无借阅信息!!\n请您按任意键返回!!\n");
		system("pause"); 
		return;
	}
	char name[30];
	char bookname[30]; 
	int id;
	printf("\n请输入您的姓名、图书名、身份证!!\n");
	scanf("%s%s%ld",name,bookname,&id);
	borrowers *p1,*p;
	borrowers *t; 
	bookinformation *p2;
	p2=head;
	p1=head1;
	p=p1;
	int time;
	int money; 
	int tag=0;           //标志 
	ElemType *e;
	e=(borrowers*)malloc(sizeof(borrowers));       //??
	while(p1!=NULL)
	{
	
		if((strcmp(p1->bookname,bookname)==0)&&(strcmp(p1->name,name)==0)&&(id==p1->id))
		{
			time=p1->time;
			money=p1->money;
			while(p2!=NULL)
			{
				if(strcmp(p2->name,p1->bookname)==0)
				{
				
						p2->num++;
						p2->bnum--; 
						if(p2->L.front!=NULL)  //预约系统检测 
						{
							if((p2->num==1)&&(p2->L.front->next!=NULL))
							{
								p2->num--;
								p2->bnum++;
								tag=1;
							///////////////////////////////////
							}
						} 
						break;		
				}
				p2=p2->next;
			}
			if(p1==head1)
			{
				head1=p1->next;
				free(p1);
			}else if(p1->next==NULL)
			{
				free(p1);
				p->next=NULL; 
			}else
			{
				p->next=p1->next;
				free(p1);
			}
			if(money==0)
			{
				printf("\n您在60天内成功归还图书!!\n");
			}else
			{
				time = time-60;
				printf("\n您已逾期%d天,我们已扣除您%d元!!!\n",time,money);
			}
			printf("\n归还成功!!!\n");
			//////////////////////
			if(tag==1)         //检测到该书有库存并且有人排队 
			{
				OutQueue(&p2->L,*e);  //出队
				
			//	printf("%s\t%ld\t\t%s\t\t%d-%d-%d\t%d\t%d\n",e->name,e->id,e->bookname,e->year,e->month,e->day,e->time,e->money);//////
				
				t=head1;
				if(t==NULL)
				{
					head1=e;
					head1->next=NULL; 
				}else
				{
					while(t->next!=NULL)
					{
						t=t->next;
					}
					t->next=e;
					e->next=NULL;
				}
				printf("\n预约系统消息： %s 成功预约 %s \n",e->name,e->bookname);
			}
			//////////////////////
			system("pause");
			Sleep(1000);
			return;
		}
		p=p1;
		p1=p1->next; 
	}
	printf("\n您输入的信息有误!!!\n");
	system("pause");
	Sleep(1000);
	return;
}


void administrators_suggestion_and_feedback()               //用户端建议与反馈箱
{
	system("cls");
	printf("欢迎来到用户端建议与反馈箱!!!\n");
	FILE *fp;
	Create_File3();        //建立admSgtFb.txt
	fp=fopen("admSgtFb.txt","w");
	printf("请输入您的建议与反馈:(提示：为避免系统错误最多输入100个字，包括标点符号!!)\n");
	char str[200];
	gets(str);
	fputs(str,fp);
	fclose(fp);
	putchar(10);
	system("pause");
	return;
	 
}

void Create_File3()     //建立admSgtFb.txt 
{ 
	FILE *fp;
    if ((fp = fopen("admSgtFb.txt","r"))==NULL) /*如果此文件不存在*/
    {
        if ((fp = fopen("admSgtFb.txt","w+"))==NULL)
        {
            printf("无法建立文件!\n");
            Sleep(1000);
            exit(0);
        }
    }  
    fclose(fp);
}

void users_suggestion_and_feedback()     //管理员端建议与反馈箱 
{
	system("cls");
	FILE *fp;
	char ch;
	printf("欢迎来到管理员端建议与反馈箱!!\n");
	Create_File3();            //建立admSgtFb.txt 
	fp=fopen("admSgtFb.txt","r");
	ch=getc(fp);
	while(!feof(fp))
	{
		putchar(ch);
		ch=getc(fp);
	}
	putchar('\n');
	fclose(fp);
	printf("按任意键返回管理员端操作系统!!\n");
	system("pause");
	return;
}

void administrators_announcement()               //管理员端公告板 
{
	system("cls");
	printf("欢迎来到管理员端公告板!!!\n");
	FILE *fp;
	Create_File4();        //建立announcement.txt
	fp=fopen("announcement.txt","w");
	printf("请输入公告:(提示：为避免系统错误最多输入100个字，包括标点符号!!)\n");
	char str[200];
	gets(str);
	fputs(str,fp);
	fclose(fp);
	putchar(10);
	system("pause");
	return;
	 
}

void Create_File4()     //建立announcement.txt 
{ 
	FILE *fp;
    if ((fp = fopen("announcement.txt","r"))==NULL) /*如果此文件不存在*/
    {
        if ((fp = fopen("announcement.txt","w+"))==NULL)
        {
            printf("无法建立文件!\n");
            Sleep(1000);
            exit(0);
        }
    }  
    fclose(fp);
}




void users_announcement()     //用户端公告板 
{
	system("cls");
	FILE *fp;
	char ch;
	printf("欢迎来到公告板!!\n");
	Create_File4();            //建立announcement.txt 
	fp=fopen("announcement.txt","r");
	ch=getc(fp);
	while(!feof(fp))
	{
		putchar(ch);
		ch=getc(fp);
	}
	putchar('\n');
	fclose(fp);
	printf("按任意键返回!!\n");
	system("pause");
	return;
}



///////////////////////////////////////////////// 
void appointment_system()                              //预约系统页面 
{
	////////////////
	time_t timep;
    struct tm *p3;
    time (&timep);
    p3=gmtime(&timep);
	///////////////
	system("cls");
	printf("\n欢迎来到预约系统页面!!\n");
	if(head==NULL)      //判断有无初始化 
	{
		printf("未进行初始化图书信息!!\n请按任意键返回!!\n");
		system("pause"); 
		return;
	}
	bookinformation *p;
	p=head;
	int count =1;
	printf("------------------------------------------------图书信息--------------------------------------------------------\n");
	printf("序号\t编号\t书名\t作者\t出版社\t类别\t出版时间\t价格\t库存\t已借出\n");
	while(p!=NULL)
	{
		if(p->num==0)
		{
			printf("%d\t%ld\t%s\t%s\t%s\t%s\t%ld\t%.1f\t%ld\t%ld\n",count,p->id,p->name,p->author,p->publisher,p->type,p->pubtime,p->price,p->num,p->bnum); 
			count++;
		}
		p=p->next; 

	 } 
	printf("\n以上为全部可预约的图书信息\n");
	printf("\n");
	system("pause");
	if(count == 1)
		return;
	p=head;
	ElemType *e;
	//////////////////
	borrowers *p5;
	p5=head1; 
	/////////////////
	e = (borrowers*)malloc(sizeof(borrowers));
	int tag =0;
	printf("请输入预约借阅信息信息\n(姓名、身份证、书名、年、月、日)\n");
	scanf("%s%ld%s%d%d%d",&e->name,&e->id,&e->bookname,&e->year,&e->month,&e->day);
	/////////////////////
	while(p5!=NULL)
	{
		if((e->id==p5->id)&&(strcmp(e->name,p5->name)!=0))
		{
			printf("\n非常抱歉!!您输入的信息是错误的!!!\n");
			system("pause");
			Sleep(1000);
			return ;
			}
			p5=p5->next; 
		}
	///////////////////
	
	
	if((e->year>0&&e->year<=2023)&&(e->month>=1&&e->month<=(1+p3->tm_mon))&&(e->day>=1&&e->day<=30))
	{
		e->time = ((1900+p3->tm_year)*365+(1+p3->tm_mon)*31+p3->tm_mday)-(e->year*365+e->month*31+e->day);
		if(e->time>60)
		{
			e->money=(e->time-60)*2;
		}else
		{
			e->money=0;
		}
	}else
	{
		printf("\n输入信息有误!!\n");
		system("pause");
		return;
	}
	while(p!=NULL)
	{
		if((strcmp(p->name,e->bookname)==0)&&p->num==0)
		{
			tag=1;
			if(p->L.front==NULL)
			{
				InitQueue(&p->L);
			}
			
			if(InQueue(&p->L,e)==1)
				printf("\n排队预约成功!!\n");
			system("pause");
			break;
		}
		p=p->next;
	} 
	if(tag==0)
	{
		printf("\n输入信息有误!!\n");
		system("pause");
	}
}
