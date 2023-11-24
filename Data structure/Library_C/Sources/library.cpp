#include "library.h"
////////////////////////////////////////////////////////
void InitQueue(LinkQueue *L)        //��ʼ������ 
{
	L->front=(QueuePtr)malloc(sizeof(QNode));
	if(L->front == NULL)
	{
		printf("\n�����ڴ�ʧ��!!\n");
		system("pause");
		exit(0); 
	}
	L->rear=L->front;
	L->front->next=NULL; 
}

Status InQueue(LinkQueue*L,ElemType *e)   //��� 
{
	QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
	if(p == NULL)
	{
		printf("\n�����ڴ�ʧ��!!\n");
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

Status OutQueue(LinkQueue *L,ElemType &e)  //���� 
{
	if(L->rear==L->front)
	{
		printf("\n����Ϊ��!!\n");
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
	char  command;   //�����ʼ�Ľ��棨ѡ���ɫ��¼���������ָ� 
	while(1)
	{   
	    system("cls");
		character_menu();
		command=getch();
		switch(command)
		{
			case '1' : administrators_menu();break;    //��ת������Աѡ��ҳ�� 
			case '2' : users_menu();break;    //��ת���û�ѡ��ҳ�� 
			case '3' : notice_to_users();break;  //��ת���û���֪ҳ�� 
			case '0' : exit(0);                 //�˳� 
			default  : printf("����������ݷǷ�!������������!!(���������������)\n"); getch();
		}
		
	} 
}



//////////////////////////////////////////////////////////////////////////////////////
void character_menu()      //ѡ���ɫ������Ա���û���ҳ�� �Ĳ˵���ʾ 
{
	printf("\t\t\t----------------------------------\n");
	printf("\t\t\t|       ͼ����Ϣ����ϵͳϵͳ     |\n");
	printf("\t\t\t----------------------------------\n");
	printf("\t\t\t|          1.����Ա��¼          |\n");
	printf("\t\t\t|          2.�û����            |\n");
	printf("\t\t\t|          3.�û���֪            |\n");
	printf("\t\t\t|          0.�˳�ϵͳ            |\n");
	printf("\t\t\t----------------------------------\n");
	printf("������ָ�[\t]\b\b\b");

}

void notice_to_users()      //�û���֪ 
{
system("cls");
printf("\n����һ��ͼ����Ϣ����ϵͳ��Ϊ�˰�����������˽Ⲣʹ������������ϸ�Ķ�һ�����\n");
printf("\t\t\t|                          ע������                            |\n");
printf("\t\t\t|                     1.�밴��ָʾ���в���!!                   |\n");
printf("\t\t\t|   2.����Ա�״�ʹ�ñ����Ƚ��г�ʼ��ͼ����Ϣ!!                 |\n");
printf("\t\t\t|   3.��ͨ�û���������Ϊ60�죬ÿ����һ��ͻᷣ��2Ԫ!!          |\n");
printf("\t\t\t|   4.��ͨ�û�����н�����ڷ����������Ա����!!               |\n");
printf("\t\t\t|   5.ԤԼ����ֻ����ĳ������Ϊ0������½���!                 |\n");
printf("\t\t\t|   6.����������ʱ���ϸ���ָʾ���з���ϵͳ���ܱ���!          |\n");
printf("\t\t\t|   7. ��ʱ3�죬��bug��������!!                                |\n");
printf("\t\t\t|   8.������һ�����֣��������bug�����S����:                 |\n");
printf("\t\t\t|              qq�]�䣺3111297446@qq.com                       |\n");
printf("\t\t\t|                   ���xʹ��ԓϵ�y!!                           |\n");
system("pause");
}





/////////////////////////////////////////////////////////////////////////////////////////////////
void users_menu()      //�û�ѡ��ҳ�� 
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
            	default  :printf("����������ݷǷ�!������������!!(���������������)\n");getch();
	        }
    }
}

void users_menu1()
{
	printf("\n\t\t\t++++++++++++++++++++++++\n\t\t\t+  ��ӭ�����û�ѡ��ҳ��  +\n\t\t\t++++++++++++++++++++++++\n");
    printf("\n		******************�˵���*****************\n");
	printf("\t\t*\t      1.��ʾ����ͼ����Ϣ         *\n");
	printf("\t\t*\t      2.��ѯͼ����Ϣ             *\n");
	printf("\t\t*\t      3.����ͼ��                 *\n");
	printf("\t\t*\t      4.�黹ͼ��                 *\n");
	printf("\t\t*\t      5.������Ա�ķ����뽨��     *\n");
	printf("\t\t*\t      6.������                   *\n");
	printf("\t\t*\t      7.ԤԼϵͳ                 *\n");
	printf("\t\t*\t      8.���ؽ�ɫѡ��ҳ��         *\n");
	printf("		*****************************************\n");
	printf("\n");
	printf("\t\t������ָ�[\t]\b\b\b");
 } 
 
 
 
 
 /////////////////////////////////////////////////////////////////////////////////////////////
 

 void administrators_menu()    //����Աѡ��ҳ�� 
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
        	default  :printf("����������ݷǷ�!������������!!(���������������)\n");getch();
	   }
    }

} 

void administrators_menu1()       //����Աѡ��ҳ��Ĳ˵���ʾ 
{
	printf("\n\t\t\t++++++++++++++++++++++++\n\t\t\t+  ��ӭ��������Աѡ��ҳ��  +\n\t\t\t++++++++++++++++++++++++\n");
    printf("\n		******************�˵���*****************\n");
	printf("\t\t*\t      1.��¼                    *\n");
	printf("\t\t*\t      2.û���˺ţ�ȥע��        *\n");
	printf("\t\t*\t      3.�������룿ȥ�һ�        *\n");
	printf("\t\t*\t      4.���ؽ�ɫѡ��ҳ��        *\n");
	printf("		*****************************************\n");
	printf("\n");
	printf("\t\t������ָ�[\t]\b\b\b");
}



void administrators_registers()    //����Ա�˺�ע��ҳ�� 
{
	system("cls");
	Create_File();     //�����ļ����������Ա�˺ŵ���Ϣ 
	administrators_users a,b;
	FILE *fp;
	char temp[20];  //temp����ȷ������� 
	printf("\n��ӭ��������Աע�����!\n");
	//Sleep(1000);            
    fp=fopen("administratorsusers.txt","r");
	printf("�������˺ţ�");
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
				printf("���û����Ѵ���!������ע��!\n");
				Sleep(1000);
				fclose(fp);
				return;
		 	 }
	 	} 
	}

	 printf("�������ֻ����룺");
	 scanf("%s",&a.phone);
	 printf("���������룺");
	 scanf("%s",&a.pw);
	 printf("��ȷ�����룺");
	 scanf("%s",&temp);
	 while(1)
	 {
	 	if(!strcmp(a.pw,temp))
	 	{
	 		fp=fopen("administratorsusers.txt","a");
	 		fwrite(&a,sizeof(struct Administrators_users),1,fp);
	 		printf("�˺�ע��ɹ������¼!\n");
	 		system("pause");
	 		fclose(fp);
	 		return;
		 }else
		   {
		 	printf("�������벻ƥ��!�������������룺");
		 	scanf("%s",&a.pw);
		 	printf("��ȷ������:");
		 	scanf("%s",&temp);
		   }
	 }
 } 
 
 void Create_File()     //�����������Ա�û��˺�������ļ� 
{
	 FILE *fp;
     if ((fp = fopen("administratorsusers.txt","r"))==NULL) /*������ļ�������*/
     {
         if ((fp = fopen("administratorsusers.txt","w+"))==NULL)
          {
              printf("�޷������ļ�!\n");
              exit(0);
          }
     }  
     fclose(fp);
}

void administrators_login()     //����Ա�˺ŵ�¼ҳ�� 
{
	system("cls");
	administrators_users a,b;
	FILE *fp; 
	if((fp=fopen("administratorsusers.txt","r"))==NULL) 
	{
		printf("\n�����˺�������Ϣ������ע��!!\n");
		system("pause");
		return;
	}

	printf("��ӭ��������Ա��¼ҳ��\n");
	printf("�������˺�:");
	scanf("%s",&a.id);
	printf("����������:"); 
	scanf("%s",&a.pw);
	fread(&b,sizeof(struct Administrators_users),1,fp);      //ע���㷨���˺��ȼ�飬������ȷ������� 
	while(1)                                          //����ȷ�������룬ֻ���һ�� 
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
				printf("�˺Ż�����������!!\n");
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
		printf("��¼�ɹ�!��ӭʹ��!\n");
		system("pause");
		administrators_side_operation();     //////////////
    }else
      {
      	printf("�˺Ż���������!!\n");
      	system("pause");
      	system("cls");
      	return;
	  }
}

void administrators_reback()        //����Ա�����һ�ҳ�� 
{
	system("cls");
	administrators_users a,b;
	FILE *fp;
	if((fp=fopen("administratorsusers.txt","r"))==NULL) 
	{
		printf("\n�����˺�������Ϣ������ע��!!\n");
		system("pause");
		return;
	}
	printf("��ӭ��������Ա�һ��������!\n");
	fp=fopen("administratorsusers.txt","r");
	fread(&b,sizeof(struct Administrators_users),1,fp);
	printf("�������˺ţ�\n");
	scanf("%s",&a.id);
	while(1)
	{
		if(strcmp(a.id,b.id)==0)
		{
			printf("������˺���ȷ!���ǽ�������֤��!!\n");
			Sleep(2000);
			break;
		}else
		 {
			if(!feof(fp))
			{
				fread(&b,sizeof(struct Administrators_users),1,fp); 
			}else
			  {
			  	printf("��������˺Ų�����!!�����˳�!!\n");
			  	fclose(fp);
			  	Sleep(2000);
			  	system("pause");
			  	system("cls");
			  	return;
			  }
		 }
	 } 
	 char phone_tail[5];                                                 //phone_tail[5]���������ֻ�β�ţ�4������ 
	 strncpy(phone_tail,b.phone+7,4);                                             
	 int system_verification_code=0,manual_verification_code=0,i;       //system_verification_code����ϵͳ���͵���֤�� 
	//                                                                  // manual_verification_code�����˹��������֤�� 
	srand((unsigned)time(0));                                           //srand((unsigned) seed )��������������ĳ�ʼ������(ע��ÿ�����Ӷ�Ӧһ�������������һ��ʹ��ϵͳʱ��time()����!!) 
	 for(i=0;i<10;i++)                                        
	 {
	 	system_verification_code+=( rand () % 500 );                    //rand()%500:�������0-499֮�����;  rand()%500+1:1-500֮��;  rand()%41+80��80-120֮�� 
	 }
	 printf("��������β��Ϊ %s ���ֻ����뷢������֤�� %d ,��ע�����!\n����������֤�룺",phone_tail,system_verification_code);
	scanf("%d",&manual_verification_code);
	for(i=3;i>=00;i--)
	{
		if(system_verification_code==manual_verification_code)
		{
			printf("��֤��������ȷ!!\n�����Ѱ����һ����룺");
			printf("%s",&b.pw);
			printf("\n����������ع���Աѡ��ҳ����е�¼!!\n");
			getch();
			fclose(fp);
		    return;
		}else
		  {
		  	printf("\n��֤�����������ʣ�� %d �λ���!!\n������������֤�룺",i);
		  	scanf("%d",&manual_verification_code);
		  	printf("\n");
		  }
	}
	printf("���Ѷ���������!!��������!!");
	system("pause");
	Sleep(2000);
	fclose(fp);
	return;
}


void administrators_side_operation_menu()
{
	printf("\n\t\t\t++++++++++++++++++++++++\n\t\t\t+ ��ӭ��������Ա�˲���ҳ�� +\n\t\t\t++++++++++++++++++++++++\n");
    printf("\n		******************�˵���*****************\n");
	printf("\t\t*\t      1.���ع���Աѡ��ҳ��      *\n");
	printf("\t\t*\t      2.��ʼ��ͼ����Ϣ          *\n");
	printf("\t\t*\t      3.��������ͼ����Ϣ        *\n");
	printf("\t\t*\t      4.����ɾ��ͼ����Ϣ        *\n");
    printf("\t\t*\t      5.�����޸�ͼ����Ϣ        *\n");
	printf("\t\t*\t      6.����ͼ����Ϣ            *\n");
	printf("\t\t*\t      7.��ʾȫ��ͼ����Ϣ        *\n");
	printf("\t\t*\t      8.��ѯͼ����Ϣ            *\n");
	printf("\t\t*\t      9.����ͼ����Ϣ            *\n");
	printf("\t\t*\t      a.������     	       *\n"); 
	printf("\t\t*\t      b.�鿴��������Ϣ          *\n");
	printf("\t\t*\t      c.����Ա�˽����뷴��      *\n");
	printf("\t\t*\t      d.����Ա�˹���            *\n");
	printf("		*****************************************\n");
	printf("\n");
	printf("\t\t������ָ�[\t]\b\b\b");
}

void administrators_side_operation()    //����Ա�˲���ҳ�� 
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
				printf("\nϵͳ��ǰ�Ѿ���ʼ��ͼ����Ϣ(���������������)\n");getch(); 
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
			printf("\n����������ݷǷ�!������������!!(���������������)\n");getch(); 
		}
		system("cls");
		administrators_side_operation_menu();
		command2=getch();
		
	}
	
}

bookinformation *creat()            //ָ��bookinformation�ṹ������ָ�뺯�����ڴ���������ʼ������
{
	system("cls");
	printf("��ӭ������ʼ��ͼ����Ϣҳ��!!\n");
	bookinformation *head1;
	bookinformation *p1,*p2;
	head1=NULL;
	int number=1;     
	p1=p2=(struct _bookinformation *)malloc(LEN);
	printf("������ͼ����Ϣ\n(��š����������ߡ������硢��𡢳���ʱ�䡢�۸񡢿��)(������ı��Ϊ 0 ʱ�����,���������������Ч)\n");
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
		  printf("������ͼ����Ϣ\n(��š����������ߡ������硢��𡢳���ʱ�䡢�۸񡢿��)(������ı��Ϊ 0 ʱ�����,���������������Ч)\n");
	      scanf("%ld%s%s%s%s%ld%f%ld",&p1->id,&p1->name,&p1->author,&p1->publisher,&p1->type,&p1->pubtime,&p1->price,&p1->num);
	      p1->bnum=0;
	      
	   	  p1->L.front=NULL;      //////////////////////////////////
		  p1->L.rear=p1->L.front; 
	      
	} 
	p2->next=NULL;
	printf("��ʼ��ͼ����Ϣ�����!!\n");
	system("pause"); 
	Sleep(1000);
	return(head1); 
}

void add_book(bookinformation *head)           //��������ͼ����Ϣ 
{
	system("cls");
	if(head==NULL)
	{
		printf("��δ���г�ʼ��ͼ����Ϣ!!\n��������������ع���Ա�˲���ҳ��!!\n");
		system("pause"); 
		return;
	}
	printf("��ӭ��������ͼ����Ϣҳ��!!\n");
	bookinformation *p1,*p2;
	p2=head;
	while(1)
	{
		if(p2->next==NULL)
		{
			p1=(struct _bookinformation *)malloc(LEN);
			printf("������ͼ����Ϣ\n(��š����������ߡ������硢��𡢳���ʱ�䡢�۸񡢿��)(������ı��Ϊ 0 ʱ�����,���������������Ч)\n");
			scanf("%ld%s%s%s%s%ld%f%ld",&p1->id,&p1->name,&p1->author,&p1->publisher,&p1->type,&p1->pubtime,&p1->price,&p1->num);
			p1->bnum=0;
			
			p1->L.front=NULL;      //////////////////////////////////
			p1->L.rear=p1->L.front; 
			
	        while(p1->id!=0)
	        {
	        	p2->next=p1;
	        	p2=p1;
	        	p1=(struct _bookinformation *)malloc(LEN);
				printf("������ͼ����Ϣ\n(��š����������ߡ������硢��𡢳���ʱ�䡢�۸񡢿��)(������ı��Ϊ 0 ʱ�����,���������������Ч)\n");
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
	printf("����ͼ����Ϣ�ɹ�!!\n�������ع���Ա�˲���ҳ��!!\n");
	system("pause");
	Sleep(2000);
	return;
}



bookinformation *del_book(bookinformation *head)     //����ɾ��ͼ����Ϣ 
{
	system("cls");
	if(head==NULL)
	{
		printf("��δ���г�ʼ��ͼ����Ϣ!!\n��������������ع���Ա�˲���ҳ��!!\n");
		system("pause"); 
		return head;
	}
	char isAgain; 
	bookinformation *p,*p1;
	long id;
	printf("��ӭ����ɾ��ͼ����Ϣҳ��!!\n������Ҫɾ��ͼ��ı�ţ�");
	scanf("%ld",&id);
again://ע��!!

    p=head;
	while(1)
	{

		if(head->id==id)
		{
			head=head->next;
			free(p);     //�ͷŶ�̬�ڴ� 
			if(head == NULL)    
			{
				break;
			} 
			printf("����ɾ��ͼ����Ϣ�� 1 �����ع���Ա�˲���ҳ�水 2 \n");
			isAgain=getch();
			if(isAgain=='1')
			{
				printf("������Ҫɾ��ͼ��ı�ţ�");
				scanf("%ld",&id);
				goto again;                                    //ע��!!! 
			}
			else if(isAgain=='2')
			{
				break;
		    }
			else
			{
				printf("�������!!\n");
				Sleep(2000);
				break;
			}
		}else
		{
			p1=p;
			p1=p->next;   //p1ָ����һ��̬�ڴ�洢�� 
			
			if(p1==NULL)
			{
				printf("������ı������!!!\n�������ع���Ա�˲���ҳ��!!\n");
		   		system("pause");
		   		Sleep(2000);
		   		return head;
			}
			 	
			if(p1->id==id)
			{
				p->next=p1->next;   //������̬�洢�����Ӵ������м��p1 
				p=p1;
				free(p1);
				printf("����ɾ��ͼ����Ϣ�� 1 �����ع���Ա�˲���ҳ�水 2 \n");
				isAgain=getch();
				if(isAgain=='1')
				{
					printf("������Ҫɾ��ͼ��ı�ţ�");
					scanf("%ld",&id);
					goto again;
				} 
				else if(isAgain=='2')
				{
					break;
				}
				else
			    {
				printf("�������!!\n");
				Sleep(2000);
				break;
			    }
			}
			
			
			p=p->next;  
		   if(p->next==NULL)
		   {
		   	printf("������ı������!!!\n�������ع���Ա�˲���ҳ��!!\n");
		   	system("pause");
		   	Sleep(2000);
		   	return head;
		   }
		}
	}
	
	
	printf("�ɹ�ɾ��ָ��ͼ����Ϣ!!\n�������ع���Ա�˲���ҳ��!!\n");
	Sleep(2000);
	system("pause");
	return head; 
 } 
 
void change_book(bookinformation *head)             //�����޸�ͼ����Ϣ 
 {
 	system("cls");
 	if(head==NULL)
	{
		printf("��δ���г�ʼ��ͼ����Ϣ!!\n��������������ع���Ա�˲���ҳ��!!\n");
		system("pause"); 
		return;
	}
	printf("��ӭ�������޸�ͼ����Ϣҳ��!!\n");
	bookinformation *p;
	long id,pubtime,num;
	char publisher[50];
	char name[30];
	char author[30];
	char type[30];
	char isAgain; 
	float price;
	printf("��������Ҫ�޸�ͼ��ı��:");
	scanf("%ld",&id);
	
again:                        //ע��!!!	
	
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
		    printf("δ�ҵ���ͼ�����Ϣ!!!\n�������ع���Ա�˲���ҳ��!!\n");
		    system("pause");
		    return;
	    }
	}
	
	printf("������ͼ����Ϣ\n(��š����������ߡ������硢��𡢳���ʱ�䡢�۸񡢿��)\n");
	scanf("%ld%s%s%s%s%ld%f%ld",&id,&name,&author,&publisher,&type,&pubtime,&price,&num);
    p->id=id;
    strcpy(p->type,type);
    strcpy(p->name,name);
    strcpy(p->author,author);
    strcpy(p->publisher,publisher);
    p->price=price;
    p->num=num;
    printf("�����޸�ͼ����Ϣ�� 1 �����ع���Ա�˲���ҳ�水 2 \n");
	isAgain=getch();
	if(isAgain=='1')
	{
		printf("������Ҫ�޸�ͼ��ı�ţ�");
		scanf("%ld",&id);
		goto again;                                    //ע��!!! 
	}
	else if(isAgain=='2')
	{
		return;
	}
	else
	{
		printf("�������!!\n");
		system("pause");
		Sleep(2000);
		return;
	}
 }
 
 void reserve_book(bookinformation *head)       //����ͼ����Ϣ�� book1.txt(�������ļ�) 
{
	system("cls");
	Create_File2();  //����book1.txt 
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
	printf("ͼ����Ϣ�ѱ��浽�ļ�book1.txt!!");
	system("pause");
	Sleep(2000);
	return;
	 
} 
void reserve_book1(bookinformation *head)        //����ͼ����Ϣ��book.txt(�ı��ļ��� 
{
	system("cls");
	Create_File1();       //����book.txt 
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
	printf("ͼ����Ϣ�ѱ��浽�ļ�book.txt!!");
	system("pause");
	Sleep(2000);
	return;
}

void Create_File1()             //��������ͼ����Ϣ���ļ� book.txt
{
	system("cls"); 
	FILE *fp;
    if ((fp = fopen("book.txt","r"))==NULL) /*������ļ�������*/
    {
        if ((fp = fopen("book.txt","w+"))==NULL)
        {
            printf("�޷������ļ�!\n");
            Sleep(1000);
            exit(0);
        }
    }  
    fclose(fp);
}

void Create_File2()             //��������ͼ����Ϣ���ļ� book1.txt
{
	FILE *fp;
    if ((fp = fopen("book1.txt","rb"))==NULL) /*������ļ�������*/
    {
        if ((fp = fopen("book1.txt","wb+"))==NULL)
        {
            printf("�޷������ļ�!\n");
            Sleep(1000);
            exit(0);
        }
    }  
    fclose(fp);
}


void print_book(bookinformation *head)        //��ʾ�ѱ���ȫ��ͼ����Ϣ 
{
    system("cls");
 	//FILE *fp;
 	if(head==NULL)      //�ж����޳�ʼ�� 
	{
		printf("δ���г�ʼ��ͼ����Ϣ!!\n�밴���������!!\n");
		system("pause"); 
		return;
	}
	bookinformation *p;
	p=head;
	int count =1;
	printf("------------------------------------------------ͼ����Ϣ--------------------------------------------------------\n");
	printf("���\t���\t����\t����\t������\t���\t����ʱ��\t�۸�\t���\t�ѽ��\n");
	while(p!=NULL)
	{
		printf("%d\t%ld\t%s\t%s\t%s\t%s\t%ld\t%.1f\t%ld\t%ld\n",count,p->id,p->name,p->author,p->publisher,p->type,p->pubtime,p->price,p->num,p->bnum);
		p=p->next; 
		count++;
	 } 
	printf("\n����Ϊȫ��ͼ�����Ϣ\n");
	printf("\n");
	system("pause");
	return;
	/*
	if ((fp = fopen("book1.txt","rb"))==NULL) //������ļ�������
    {
        printf("��δ�����ļ�!!!\n�������ع���Ա�˲���ҳ��!!!\n");
        system("pause");
		return; 
    }
 	printf("------------------------------------------------ͼ����Ϣ--------------------------------------------------------\n");
 	printf("���\t����\t����\t������\t���\t����ʱ��\t�۸�\t���\n");
    fp=fopen("book1.txt","rb"); 
    
    bookinformation *p;
    
    while(1)
    {
        if(fread(p,sizeof(struct _bookinformation),1,fp)==1) //��һ�в�֪��Ϊʲô����ʧ�󣿴��ļ���ȡ��Ϣ����ӡ 
        {
            printf("%ld\t%s\t%s\t%s\t%s\t%ld\t%.1f\t%ld\n",p->id,p->name,p->author,p->publisher,p->type,p->pubtime,p->price,p->num);
		
		}
		else
		{
			printf("\n����Ϊ�ѱ����ȫ��ͼ�����Ϣ\n");
			fclose(fp);
			system("pause");
			return;
		}
	} 
	*/
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void find_book(bookinformation *head)         //��ѯͼ����Ϣҳ�� 
{
	system("cls");
	if(head==NULL)      //�ж����޳�ʼ�� 
	{
		printf("δ���г�ʼ��ͼ����Ϣ!!\n�밴���������!!\n");
		system("pause"); 
		return;
	}
	printf("��ӭ������ѯͼ����Ϣҳ��!!!\n��ʾ��\n1.����'1'����Ų�ѯ;\n2.����'2'��������ѯ;\n3.����'3'�����߲�ѯ;\n4.����'4'���������ѯ;\n5.����'5'���۸�Χ��ѯ;\n6.����'6'���ع���Ա�˲���ҳ��;\n");
	char command3;
	printf("������ָ��:"); 
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
			printf("\n��������!!");
			Sleep(2000);
			return;
		}else
		{
		  printf("\n��������!!!\n");
		  Sleep(2000);
		}
		system("cls");
		printf("��ӭ������ѯͼ����Ϣҳ��!!!\n��ʾ��\n1.����'1'����Ų�ѯ;\n2.����'2'��������ѯ;\n3.����'3'�����߲�ѯ;\n4.����'4'���������ѯ;\n5.����'5'���۸�Χ��ѯ;\n6.����'6'���ع���Ա�˲���ҳ��;\n");
		printf("������ָ�"); 
		command3=getch();
	}
	 
	
 } 

 void find_book_id(bookinformation *head)         //ͨ����Ų�ѯͼ����Ϣ 
 {
 	system("cls");
 	bookinformation *p;
 	p=head;
 	long id;
 	printf("������ͼ��ı��:");
 	scanf("%ld",&id);
 	while(p!=NULL)                        //���ñ����ķ��� 
 	{
 		if(p->id==id)
 		{
 			printf("------------------------------------------------ͼ����Ϣ--------------------------------------------------------\n");
 	        printf("���\t����\t����\t������\t���\t����ʱ��\t�۸�\t���\t�ѽ��\n");
 	        printf("%ld\t%s\t%s\t%s\t%s\t%ld\t%.1f\t%ld\t%ld\n",p->id,p->name,p->author,p->publisher,p->type,p->pubtime,p->price,p->num,p->bnum);
 	        printf("\n����Ϊ��ͼ����Ϣ!!�����������!!\n");
 	        system("pause");
 	        break;
		}else if(p->next==NULL)
		{
			printf("δ�ҵ���ͼ��!!�밴���������!");
			system("pause");
			break;
		}
		p=p->next;
		
	}
 }
 
void find_book_name(bookinformation *head)       //ͨ��������ѯͼ����Ϣ 
 {
 	system("cls");
 	bookinformation *p;
 	p=head;
 	char name[30];
 	printf("������ͼ������:");
 	scanf("%s",name);
 	while(p!=NULL)                        //���ñ����ķ��� 
 	{
 		if(strcmp(name,p->name)==0)
 		{
			printf("------------------------------------------------ͼ����Ϣ--------------------------------------------------------\n");
 	        printf("���\t����\t����\t������\t���\t����ʱ��\t�۸�\t���\t�ѽ��\n");
 	        printf("%ld\t%s\t%s\t%s\t%s\t%ld\t%.1f\t%ld\t%ld\n",p->id,p->name,p->author,p->publisher,p->type,p->pubtime,p->price,p->num,p->bnum);
 	        printf("\n����Ϊ��ͼ����Ϣ!!�����������!!\n");
 	        system("pause");
 	        break;
		}else if(p->next==NULL)
		{
			printf("δ�ҵ���ͼ��!!�밴���������!");
			system("pause");
			break;
		}
		p=p->next;	
	}
 }
 
 void find_book_author(bookinformation *head)       //ͨ�����߲�ѯͼ����Ϣ 
 {
 	system("cls");
 	bookinformation *p;
 	p=head;
 	char author[30];
 	printf("������������:");
 	scanf("%s",author);
 	while(p!=NULL)                        //���ñ����ķ��� 
 	{
 		if(strcmp(author,p->author)==0)
 		{
			printf("------------------------------------------------ͼ����Ϣ--------------------------------------------------------\n");
 	        printf("���\t����\t����\t������\t���\t����ʱ��\t�۸�\t���\t�ѽ��\n");
 	        printf("%ld\t%s\t%s\t%s\t%s\t%ld\t%.1f\t%ld\t%ld\n",p->id,p->name,p->author,p->publisher,p->type,p->pubtime,p->price,p->num,p->bnum);
 	        printf("\n����Ϊ��ͼ����Ϣ!!�����������!!\n");
 	        system("pause");
 	        break;
		}else if(p->next==NULL)
		{
			printf("δ�ҵ���ͼ��!!�밴���������!");
			system("pause");
			break;
		}
		p=p->next;	
	}
 }
 
void find_book_publisher(bookinformation *head)       //ͨ���������ѯͼ����Ϣ 
{
 	system("cls");
 	bookinformation *p;
 	p=head;
 	char publisher[50];
 	printf("�����������:");
 	scanf("%s",publisher);
 	while(p!=NULL)                        //���ñ����ķ��� 
 	{
 		if(strcmp(publisher,p->publisher)==0)
 		{
			printf("------------------------------------------------ͼ����Ϣ--------------------------------------------------------\n");
 	        printf("���\t����\t����\t������\t���\t����ʱ��\t�۸�\t���\t�ѽ��\n");
 	        printf("%ld\t%s\t%s\t%s\t%s\t%ld\t%.1f\t%ld\t%ld\n",p->id,p->name,p->author,p->publisher,p->type,p->pubtime,p->price,p->num,p->bnum);
 	        printf("\n����Ϊ��ͼ����Ϣ!!�����������!!\n");
 	        system("pause");
 	        break;
		}else if(p->next==NULL)
		{
			printf("δ�ҵ���ͼ��!!�밴���������!");
			system("pause");
			break;
		}
		p=p->next;	
	}
}

void find_book_price(bookinformation *head)    //ͨ���۸�ķ�Χ��ѯͼ����Ϣ 
 {
 	system("cls");
 	bookinformation *p;
 	p=head;
 	int n=0;
 	float priceMax,priceMin;
 	printf("������۸����ֵ:");
	scanf("%f",&priceMax);
	printf("������۸���Сֵ:");
	scanf("%f",&priceMin);
	system("cls");
	printf("------------------------------------------------ͼ����Ϣ--------------------------------------------------------\n");
	printf("���\t����\t����\t������\t���\t����ʱ��\t�۸�\t���\t�ѽ��\n");
 	while(p!=NULL)                                    //ͬ����� 
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
	  	printf("δ�ҵ�����������ͼ��!!�밴���������!");
		system("pause");
		return;
	  }else if(n==1)
	  {
	  		printf("\n����Ϊ��ͼ����Ϣ!!�����������!!\n");
 	        system("pause");
 	        return;
	  }
 }
 
 
 //////////////////////////////////////////////////////////////////////////////////////////////
 
 
 void backup_book(bookinformation *head)        //����ͼ����Ϣ����book.txt���ݵ�backup.txt�� 
{
	system("cls");
	if(head==NULL)      //�ж����޳�ʼ�� 
	{
		printf("��δ���г�ʼ��ͼ����Ϣ!!\n��������������ع���Ա�˲���ҳ��!!\n");
		system("pause"); 
		return;
	}
	FILE *in,*out;
	char ch;
	if((in=fopen("book.txt","r"))==NULL)
	{
		printf("��book.txt�ļ�ʧ��!!!");
		Sleep(2000);
		fclose(in);
		fclose(out);
		exit(0);
	}
	if((out=fopen("backup.txt","w"))==NULL)
	{
		printf("�򿪱����ļ�ʧ��!!!");
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
	printf("�ɹ�����!!!\n");
	system("pause");
	Sleep(2000);
	return;
}


/////////////////////////////////////////////////////////////////////////////////////////////

bookinformation *sort(bookinformation *head)                       //����ѡ��ҳ�� 
{
	system("cls");
	if(head==NULL)      //�ж����޳�ʼ�� 
	{
		printf("��δ���г�ʼ��ͼ����Ϣ!!\n��������������ع���Ա�˲���ҳ��!!\n");
		system("pause"); 
		return head;
	}
	int number;
	number=number_of_book(head);
	printf("��ӭ����������ҳ��!!\n��ʾ:\n1.'1'�����������;\n2.'2'�����۸�����;\n3.'3'�����������;\n4.'4'��������ʱ������;\n5.'5'�����ع���Ա�˲���ϵͳ;\n");
	printf("������ָ��:");
	char command4;
	command4=getch();
	while(1)
	{
		if(command4=='1')
		{
			head=sort_book(number , head , compare_id);
			printf("\n���������\n");
			print(head);
			system("pause");
		}else if(command4=='2')
		{
		  head=sort_book(number , head , compare_price);
		  printf("\n���۸�����\n");
		  print(head);
		  system("pause"); 
		  
		}else if(command4=='3')
		{
		   head=sort_book(number , head , compare_num);
		   printf("\n���������\n");
		   print(head);
		   system("pause");
		}else if(command4=='4')
		{
		   head=sort_book(number , head , compare_pubtime);
		   printf("\n������ʱ������\n");
		   print(head);
		   system("pause"); 
		}else if(command4=='5')
		{
			printf("\n�������ع���Ա�˲���ҳ��!!");
			Sleep(2000);
			return head;
		}else
		{
		  printf("\n��������!!!\n");
		  Sleep(2000);
		}
		system("cls");
		printf("��ӭ����������ҳ��!!\n��ʾ:\n1.'1'�����������;\n2.'2'�����۸�����;\n3.'3'�����������;\n4.'4'��������ʱ������;\n5.'5'�����ع���Ա�˲���ϵͳ;\n");
		printf("������ָ�"); 
		command4=getch();
    }
}

int number_of_book(bookinformation *head)         //����ͼ������ 
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

void print(bookinformation *head)    //��ʾ������ͼ����Ϣ 
{
	bookinformation *p;
	p=head;
	int count =1;
	printf("------------------------------------------------ͼ����Ϣ--------------------------------------------------------\n");
	printf("���\t���\t����\t����\t������\t���\t����ʱ��\t�۸�\t���\t�ѽ��\n");
	while(p!=NULL)
	{
		printf("%d\t%ld\t%s\t%s\t%s\t%s\t%ld\t%.1f\t%ld\t%ld\n",count,p->id,p->name,p->author,p->publisher,p->type,p->pubtime,p->price,p->num,p->bnum);
		p=p->next; 
		count++;
	 } 
	 printf("\n");
}

bookinformation *sort_book(int number , bookinformation *head , int(*compare)(bookinformation *p))   // ����ð������(���ѵ�!!!) 
{
	system("cls");
	int t;
	printf("��ʾ��\n1.����'0'����С->��;\n2.����'2'�����->С;\n");
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
    	printf("��������!!!\n�԰�ԭ��������!!");
    	system("pause");
    	return head;
	}
	return head;
}


void swap(bookinformation *p)      //����p��p->next������ 
{
	bookinformation *temp;
	temp=(struct _bookinformation *)malloc(LEN);
	      	//��p->next�����ݷŵ�temp 
				temp->id=p->next->id;
				temp->pubtime=p->next->pubtime;
				temp->num=p->next->num;
				temp->price=p->next->price;
				strcpy(temp->name,p->next->name);
				strcpy(temp->publisher,p->next->publisher);
				strcpy(temp->author,p->next->author);
				strcpy(temp->type,p->next->type);
				//��p�����ݷŵ�p->next
				p->next->id=p->id;
				p->next->pubtime=p->pubtime;
				p->next->num=p->num;
				p->next->price=p->price;
				strcpy(p->next->publisher,p->publisher);
				strcpy(p->next->name,p->name);
				strcpy(p->next->author,p->author);
				strcpy(temp->type,p->next->type);
				//��temp�����ݷŵ�p
				p->id=temp->id;
				p->pubtime=temp->pubtime;
				p->num=temp->num;
				p->price=temp->price;
				strcpy(p->publisher,temp->publisher);
				strcpy(p->name,temp->name);
				strcpy(p->author,temp->author);
				strcpy(temp->type,p->next->type); 
}


int compare_id(bookinformation *p)       //�Ƚ�p��p->next�ı�Ŵ�С 
{
	return (p->id - p->next->id);
}

int compare_pubtime(bookinformation *p)       //�Ƚ�p��p->next�ĳ���ʱ���С 
{
	return (p->pubtime - p->next->pubtime);
}

int compare_price(bookinformation *p)       //�Ƚ�p��p->next�ļ۸��С 
{
	return (p->price - p->next->price);
}

int compare_num(bookinformation *p)       //�Ƚ�p��p->next�Ŀ���С 
{
	return (p->num - p->next->num);
}



void print_borrowers(borrowers *head1)        //��ʾ��ȫ����������Ϣ 
{
    system("cls");
 	//FILE *fp;
 	if(head1==NULL)      //�ж����޳�ʼ�� 
	{
		printf("���޽�����Ϣ!!\n��������������ع���Ա�˲���ҳ��!!\n");
		system("pause"); 
		return;
	}
	borrowers *p;
	p=head1;
	int count =1;
	printf("------------------------------------------------��������Ϣ--------------------------------------------------------\n");
	printf("���\t����\t���֤\t\t�����鼮\t�� -��-��\t��������\t�������\n");
	while(p!=NULL)
	{
		printf("%d\t%s\t%ld\t\t%s\t\t%d-%d-%d\t%d\t%d\n",count,p->name,p->id,p->bookname,p->year,p->month,p->day,p->time,p->money);
		p=p->next; 
		count++;
	 } 
	printf("\n����Ϊȫ�������˵���Ϣ\n");
	printf("\n");
	system("pause");
	return;
}


void borrowing_book()       //�����鼮 
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
		printf("\n����ͼ��ɽ�!!����ϵ����Ա!!\n");
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
		printf("��ӭ��������ͼ��ҳ��!!\n");
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
		printf("�����������Ϣ��Ϣ\n(���������֤���������ꡢ�¡���)\n");
		scanf("%s%ld%s%d%d%d",&p1->name,&p1->id,&p1->bookname,&p1->year,&p1->month,&p1->day);
		
		if((p1->month==(1+p4->tm_mon))&&((p1->day)>(p4->tm_mday)))
		{
			printf("\n�ǳ���Ǹ!!���������!!!\n");
			system("pause");
			Sleep(1000);
			return ;
		}
		
		while(p3!=NULL)
		{
			if((p1->id==p3->id)&&(strcmp(p1->name,p3->name)!=0))
			{
				printf("\n�ǳ���Ǹ!!���������Ϣ�Ǵ����!!!\n");
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
						printf("\n���ĳɹ�!!\n");
						system("pause"); 
						Sleep(1000);
						return;
					}else if(p2->num==0)
					{
						printf("\n�ǳ���Ǹ!!������ĵ��鼮���Ϊ0!!\n");
						system("pause"); 
						Sleep(1000); 
						return ;
					}
				}
				p2=p2->next;
			}
		}
		
		printf("\n�ǳ���Ǹ!!�������ͼ�����Ǵ����!!!\n");
		system("pause");
		Sleep(1000);
		return ;
		

	}
} 


borrowers *creat1()            //ָ��borrowers�ṹ������ָ�뺯�����ڴ����������� 
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
	printf("��ӭ��������ͼ��ҳ��!!\n");
	borrowers *p1;
	bookinformation *p2;
	p2=head;
	p1=(struct _borrowers*)malloc(LEN1);
	printf("�����������Ϣ��Ϣ\n(���������֤���������ꡢ�¡���)\n");
	scanf("%s%ld%s%d%d%d",&p1->name,&p1->id,&p1->bookname,&p1->year,&p1->month,&p1->day);

	if((p1->month==(1+p3->tm_mon))&&((p1->day)>(p3->tm_mday)))
	{
		printf("\n�ǳ���Ǹ!!���������!!!\n");
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
					printf("\n���ĳɹ�!!\n");
					system("pause"); 
					Sleep(1000);
					return(p1);
				}else if(p2->num==0)
				{
					printf("\n�ǳ���Ǹ!!������ĵ��鼮���Ϊ0!!\n");
					system("pause"); 
					Sleep(1000); 
					return NULL;
				}
			}
			p2=p2->next;
		}
	}
	
	printf("\n�ǳ���Ǹ!!���������!!!\n");
	system("pause");
	Sleep(1000);
	return NULL;
	



}

void returning_book()           //�黹ͼ��      ///////////////
{
	system("cls");
	printf("��ӭ�����黹ͼ��ҳ��!!\n");
	if(head1==NULL)      //�ж����޽�����Ϣ 
	{
		printf("���޽�����Ϣ!!\n���������������!!\n");
		system("pause"); 
		return;
	}
	char name[30];
	char bookname[30]; 
	int id;
	printf("\n����������������ͼ���������֤!!\n");
	scanf("%s%s%ld",name,bookname,&id);
	borrowers *p1,*p;
	borrowers *t; 
	bookinformation *p2;
	p2=head;
	p1=head1;
	p=p1;
	int time;
	int money; 
	int tag=0;           //��־ 
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
						if(p2->L.front!=NULL)  //ԤԼϵͳ��� 
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
				printf("\n����60���ڳɹ��黹ͼ��!!\n");
			}else
			{
				time = time-60;
				printf("\n��������%d��,�����ѿ۳���%dԪ!!!\n",time,money);
			}
			printf("\n�黹�ɹ�!!!\n");
			//////////////////////
			if(tag==1)         //��⵽�����п�沢�������Ŷ� 
			{
				OutQueue(&p2->L,*e);  //����
				
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
				printf("\nԤԼϵͳ��Ϣ�� %s �ɹ�ԤԼ %s \n",e->name,e->bookname);
			}
			//////////////////////
			system("pause");
			Sleep(1000);
			return;
		}
		p=p1;
		p1=p1->next; 
	}
	printf("\n���������Ϣ����!!!\n");
	system("pause");
	Sleep(1000);
	return;
}


void administrators_suggestion_and_feedback()               //�û��˽����뷴����
{
	system("cls");
	printf("��ӭ�����û��˽����뷴����!!!\n");
	FILE *fp;
	Create_File3();        //����admSgtFb.txt
	fp=fopen("admSgtFb.txt","w");
	printf("���������Ľ����뷴��:(��ʾ��Ϊ����ϵͳ�����������100���֣�����������!!)\n");
	char str[200];
	gets(str);
	fputs(str,fp);
	fclose(fp);
	putchar(10);
	system("pause");
	return;
	 
}

void Create_File3()     //����admSgtFb.txt 
{ 
	FILE *fp;
    if ((fp = fopen("admSgtFb.txt","r"))==NULL) /*������ļ�������*/
    {
        if ((fp = fopen("admSgtFb.txt","w+"))==NULL)
        {
            printf("�޷������ļ�!\n");
            Sleep(1000);
            exit(0);
        }
    }  
    fclose(fp);
}

void users_suggestion_and_feedback()     //����Ա�˽����뷴���� 
{
	system("cls");
	FILE *fp;
	char ch;
	printf("��ӭ��������Ա�˽����뷴����!!\n");
	Create_File3();            //����admSgtFb.txt 
	fp=fopen("admSgtFb.txt","r");
	ch=getc(fp);
	while(!feof(fp))
	{
		putchar(ch);
		ch=getc(fp);
	}
	putchar('\n');
	fclose(fp);
	printf("����������ع���Ա�˲���ϵͳ!!\n");
	system("pause");
	return;
}

void administrators_announcement()               //����Ա�˹���� 
{
	system("cls");
	printf("��ӭ��������Ա�˹����!!!\n");
	FILE *fp;
	Create_File4();        //����announcement.txt
	fp=fopen("announcement.txt","w");
	printf("�����빫��:(��ʾ��Ϊ����ϵͳ�����������100���֣�����������!!)\n");
	char str[200];
	gets(str);
	fputs(str,fp);
	fclose(fp);
	putchar(10);
	system("pause");
	return;
	 
}

void Create_File4()     //����announcement.txt 
{ 
	FILE *fp;
    if ((fp = fopen("announcement.txt","r"))==NULL) /*������ļ�������*/
    {
        if ((fp = fopen("announcement.txt","w+"))==NULL)
        {
            printf("�޷������ļ�!\n");
            Sleep(1000);
            exit(0);
        }
    }  
    fclose(fp);
}




void users_announcement()     //�û��˹���� 
{
	system("cls");
	FILE *fp;
	char ch;
	printf("��ӭ���������!!\n");
	Create_File4();            //����announcement.txt 
	fp=fopen("announcement.txt","r");
	ch=getc(fp);
	while(!feof(fp))
	{
		putchar(ch);
		ch=getc(fp);
	}
	putchar('\n');
	fclose(fp);
	printf("�����������!!\n");
	system("pause");
	return;
}



///////////////////////////////////////////////// 
void appointment_system()                              //ԤԼϵͳҳ�� 
{
	////////////////
	time_t timep;
    struct tm *p3;
    time (&timep);
    p3=gmtime(&timep);
	///////////////
	system("cls");
	printf("\n��ӭ����ԤԼϵͳҳ��!!\n");
	if(head==NULL)      //�ж����޳�ʼ�� 
	{
		printf("δ���г�ʼ��ͼ����Ϣ!!\n�밴���������!!\n");
		system("pause"); 
		return;
	}
	bookinformation *p;
	p=head;
	int count =1;
	printf("------------------------------------------------ͼ����Ϣ--------------------------------------------------------\n");
	printf("���\t���\t����\t����\t������\t���\t����ʱ��\t�۸�\t���\t�ѽ��\n");
	while(p!=NULL)
	{
		if(p->num==0)
		{
			printf("%d\t%ld\t%s\t%s\t%s\t%s\t%ld\t%.1f\t%ld\t%ld\n",count,p->id,p->name,p->author,p->publisher,p->type,p->pubtime,p->price,p->num,p->bnum); 
			count++;
		}
		p=p->next; 

	 } 
	printf("\n����Ϊȫ����ԤԼ��ͼ����Ϣ\n");
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
	printf("������ԤԼ������Ϣ��Ϣ\n(���������֤���������ꡢ�¡���)\n");
	scanf("%s%ld%s%d%d%d",&e->name,&e->id,&e->bookname,&e->year,&e->month,&e->day);
	/////////////////////
	while(p5!=NULL)
	{
		if((e->id==p5->id)&&(strcmp(e->name,p5->name)!=0))
		{
			printf("\n�ǳ���Ǹ!!���������Ϣ�Ǵ����!!!\n");
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
		printf("\n������Ϣ����!!\n");
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
				printf("\n�Ŷ�ԤԼ�ɹ�!!\n");
			system("pause");
			break;
		}
		p=p->next;
	} 
	if(tag==0)
	{
		printf("\n������Ϣ����!!\n");
		system("pause");
	}
}
