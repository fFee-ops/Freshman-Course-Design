#include"stdio.h"
#include"stdlib.h"//�����ڴ���亯��
#include"windows.h"
#include"string.h"
#include"student.h"

void sy();//��ҳ
void dljm();
void tcjm();//�˳�����
void xsdlcd();//ѧ����¼�˵� 
void xk();
void kcll();//�γ���� 
void add();//���ӿγ�
void xscx();//ѧ����ѯ����
void xsll();//ѧ���������


void sy()//��ҳ
{
     char input;
     printf("\n\n\t\t\t****************************\n");
  	printf("\t\t\t     ���Ϲ�ҵ��ѧѡ��ϵͳ        \n");
  	printf("\t\t\t****************************\n\n\n");
    printf("\t\t\t****************************\n\n\n");
    printf("\t\t\t****************************\n\n\n");
  	printf("\t\t\t****************************\n\n\n");
  	printf("\t\t\t******����ߣ�����������****\n\n\n");
      input=getchar();
      system("cls");//���� 
}
void dljm()//��½���� 
{
     void xsdlcd(); 
     void tcjm();
     
     int input;
     do
     {
          system("cls");
          printf("\n\n\n\t1.���뱾ϵͳ\n");
          printf("\t2.�˳���ϵͳ\n");
          printf("\t��ѡ��������:");
          scanf("%d",&input);
          if (input!=1&&input!=2)  //������������ѡ���ʱ���ӡ����
          {
              printf("\n\t�������!������ѡ��~\n");
              printf("\n\t�����������ѡ��ҳ��~\n\t");
              getchar();getchar();
              system("cls");
          }
          if(input==2)//�������2�˳�ϵͳ 
          {
             tcjm();
          }
      }while(input!=1&&input!=2);
      
      switch(input)
      {
         case 1:xsdlcd();break;
       
      }
}


void tcjm()//�˳�����
{
exit(0);//�������г����˳�����
}



void xsdlcd()//ѧ����¼�˵� 
{
     void xk();
     void kcll();
     void xscs();
     void dljm();
     void  add();
     
    int input;
    do
    {
         system("cls");
         printf("\n\n\n\t--ϵͳ����--");
         printf("\n\n\t1.ѧ��ѡ��\n");
         printf("\t2.�γ����\n");
         printf("\t3.�γ̲�ѯ\n");
         printf("\t4.���ӿγ�\n");
         printf("\t5.�˳�\n"); 
         scanf("%d",&input);
         if(input!=1&&input!=2&&input!=3&&input!=4&&input!=5)
         {
             printf("\n\tû���������~\n");
              printf("\t�����������ѡ��");
              getchar();
              getchar();
          }
       }while(input!=1&&input!=2&&input!=3&&input!=4&&input!=5);
       
       switch(input)
       {
           case 1:xk();break;
           case 2:xsll();break;
           case 3:xscx();break;
           case 4:add();break;
           case 5:dljm();break;
       }
}

void xk()
{
  int n,in,i=0,j;int flag=0;
  FILE *fp;
  FILE *fp1;
  char input;
  
  struct course courses[10];
  
  
  
  
 if((fp=fopen("course.dat","rb"))==NULL) //�ж��Ƿ���ڿγ� 
      {
         
         printf("\n\n\n\t�γ̲�����\n\n");
         printf("\t<����������ع���˵�>\n\t");
         input=getchar();
         input=getchar();
         xsdlcd();//����ѧ����½�˵�                             
      }                                  
           
     else//���ڵĻ�ѭ����ȡ�ļ��е���Ϣֱ���ļ�ָ�뵽�ļ�β�� 
     {
       do
        {
          fread(&courses[i],sizeof(struct course),1,fp);//��ȡ�γ�Ԫ�ظ��� 
          i=i+1;
        }
      while(!feof(fp));//�ļ���ȡ��β�� 
      fclose(fp);//�ļ������ر�
    }
     printf("\n\n\t\t��������Ҫѡ�γ̵ı�ţ�");
     scanf("%d",&n);
     
     if((fp1=fopen("courseselect.dat","rb"))==NULL)
       {
          fp1=fopen("courseselect.dat","wb");
       }
     else
       {
         fclose(fp1);
         fp1=fopen("courseselect.dat","ab");
       }
     
     for(j=0;j<i;j++)
       if(courses[j].bh==n)
          flag++;
           if(flag==0)
		   {
             printf("\n\n\t\t�����ڶ�Ӧ�γ�\n");
			 printf("\n\n\t\t����ѡ���밴1���˳��밴2:\n");
			 scanf("%d",&in);
			 switch(in)
			 {
			 case 1:xk();break;
             case 2:xsdlcd();break;
             default:
				 printf("������󣬽����ص�¼���棡\n");
				 dljm();break;
			}
		   }
            
         else
            {
               fwrite(&courses[j],sizeof(struct course),1,fp1);
               fclose(fp1);
            
         
       
      printf("\n\n\t\tѡ�γɹ�\t��ѡ��");
      printf("\n\n\t\t1.����ѡ��"); 
      printf("\n\n\t\t2.�˳������ص�¼���棡");
      scanf("%d",&in);
      switch(in)
         {
             case 1:xk();break;
             case 2:xsdlcd();break;
             default:break;
         }
		 }
} 


void xsll()//�γ���� 
{
    void xsdlcd();
    void kcll() ; 
    int   inp,i=0,n=0;
    FILE *fp;
    char input;
    struct course courseview[10];
    
    if((fp=fopen("course.dat","rb"))==NULL) //�ж��Ƿ���ڿγ� 
      {
         system("cls");
         printf("\n\n\n\t�γ̲�����\n\n");
         printf("\t<����������ع���˵�>\n\t");
         getchar();getchar();
         xsdlcd();//����ѧ����½�˵�                             
      }                                  
           
     else//���ڵĻ�ѭ����ȡ�ļ��е���Ϣֱ���ļ�ָ�뵽�ļ�β�� 
     {
       do
        {
          fread(&courseview[i],sizeof(struct course),1,fp);
          i=i+1;
        }
      while(!feof(fp));
      fclose(fp);//�ļ������ر�
      
      do
      {
         system("cls");
		 if(i==1)
		 {
			 printf("\n\n\n\t\t\tû�м�¼��\n");
			 getchar();getchar();
			 xsdlcd();
         }
		 else
		 {
			 printf("\n\t------����%d����¼-------",i-1);
			 printf("\n\n\t�γ̱�ţ� %d\n",courseview[n].bh);
			 printf("\n\n\t�γ����֣� %s\n",courseview[n].mc);
		     printf("\n\n\t�γ�ѧ�֣� %d\n",courseview[n].xf);
		     printf("\n\n\t�γ���ѡ������ %d\n",courseview[n].alreadypp);
		     printf("\n\n\t�γ��������ޣ� %d\n",courseview[n].maxpp);
		     
	         printf("\n\n\t1.��һҳ\t2.��һҳ\t3.��Ŀ¼");
             printf("\n��ѡ��");
    	     scanf ("%d",&inp);
	         switch(inp)
			 {
               case 1:
                    {
                      if(n==0)
                         {
                          printf("\n\t�ѵ�����ҳ \t�����������");
                          input=getchar();
                          input=getchar();
                          }
                       else
                          {
                            n=n-1;
                           }
                       break;
                      }
                 case 2:
                      {
                        if(n==i-2)
                           {
                              printf("\n\t�ѵ���βҳ\t�����������");
                              input=getchar();
                              input=getchar();
                            }
                         else
                            {  
                              n=n+1;
                            }
                         break;
                        }
                   case 3:{xsdlcd();break;}
                   default:
                        {
                           printf("\n\t��������\t�����������");
                           getchar();getchar();
                           break;
                         }
             }
		 }
      }while(inp!=3);
   }
}


void xscx()
{ 
    void xsdlcd();
    void xscx();
    
    int  id,i=0,j,inp,k;
    int flag=0;
    FILE *fp;
    struct course coursesear[10];

    if ((fp=fopen("course.dat","rb"))==NULL)   //�жϿγ���Ϣ�Ƿ����
      {
         system("cls");
         printf("\n\n\t�γ̲�����\t�����������");
         getchar();getchar();
         xsdlcd();
        }
    else//���ڵĻ�ѭ����ȡ�ļ��е���Ϣֱ���ļ�ָ�뵽�ļ�β�� 
       {
           do
             {
                 fread(&coursesear[i],sizeof(struct course),1,fp);
                  i=i+1;
              }while(!feof(fp));
            fclose(fp);
         }
    system("cls");
    printf("\n\n\t\t\t��������Ҫ��ѯ�Ŀγ̱�ţ�");
    scanf("%d",&id);
    
    do//��������Ƿ����Ҫ�� 
       {
           for(j=0;j<i-1;j++)
		   {
			   if(id==coursesear[j].bh)
               {
				   flag++;
				   k=j;
			   }
		   }
                if(flag==1) 
                {
                  system("cls");
                  printf("\n\n\t�γ̱��:%d\n",coursesear[k].bh);
                  printf("\n\n\t�γ�����:%s\n",coursesear[k].mc);
                  printf("\n\n\t�γ�ѧ��:%d\n",coursesear[k].xf);
                  printf("\n\n\t�γ���ѡ����:%d\n",coursesear[k].alreadypp);
                  printf("\n\n\t�γ���������:%d\n",coursesear[k].maxpp);
				  getchar();getchar();
				  printf("\n\n\t1.��Ŀ¼������ѯ\t2.�˳���ѯϵͳ\n");
                  printf("��ѡ��");
                  scanf("%d",&inp);
                  switch(inp)
                     {
                        case 1:xscx();
                        case 2:xsdlcd();
                        default:
                            {
                                printf("\n\tû���������\t�밴�������������");
                                getchar();getchar(); 
                             }
                        }
				} 
                else 
                  {
                      system("cls");
                      printf("\n\n\t�����ڶ�Ӧ��¼\n");
                      printf("\n\n\t1.��Ŀ¼������ѯ\t2.�˳���ѯϵͳ\n");
                      printf("��ѡ��");
                      scanf("%d",&inp);
                      switch(inp)
                     {
                        case 1:xscx();
                        case 2:xsdlcd();
                        default:
                            {
                                printf("\n\tû���������\t�밴�������������");
                                getchar();getchar(); 
                             }
                        }
				}
           }while(inp!=1);
} 


void add()//���ӿγ�
{
     void add();
     int i=0,j,inp;
       
     FILE *fp;
     struct course course_new;
     struct course courses[10];
     
     system("cls");
     printf("\n\n\t\t������γ���Ϣ");
     printf("\n\n\t\t1.�γ̱��:");
     scanf("%d",&course_new.bh); 
     printf("\n\n\t\t2.�γ�����:");
     scanf("%s",course_new.mc);
     printf("\n\n\t\t3.�γ�ѧ��:");
     scanf("%d",&course_new.xf);
     printf("\n\n\t\t4.�γ���ѡ����:");
     scanf("%d",&course_new.alreadypp);
     printf("\n\n\t\t5.�γ���������:");
     scanf("%d",&course_new.maxpp);
     
     if((fp=fopen("course.dat","rb"))!=NULL)
       {
         do
           {
             fread(&courses[i],sizeof(struct course),1,fp);
             i=i+1;
            }while(!feof(fp));
            
     fclose(fp);
     
     for(j=0;j<=i-1;j++)
       if(course_new.bh==courses[j].bh)
         {
            system("cls");
            printf("\n\n\t\t\t�Բ����������Ѿ�ʹ�ù�\n\n\t\t����������ع���˵�");
            getchar();getchar();
            break;
         }
     }
     
     if((fp=fopen("course.dat","rb"))==NULL)
       {
          fp=fopen("course.dat","wb");
       }
     else
       {
         fclose(fp);
         fp=fopen("course.dat","ab");
       }
       
    fwrite(&course_new,sizeof(struct course),1,fp);
    fclose(fp);
    
    printf("\n\n\t\t��Ϣ�������\t�����������");
    getchar();getchar();
    
    do
     {
       system("cls");
       printf("\n\n\t\t1.��������");
       printf("\n\n\t\t2.���ع���˵�");
       printf("\n\n\t\t��ѡ��");
       scanf("%d",&inp);
       if(inp!=1&&inp!=2)
         {
           printf("���벻����Ҫ��\t�����������ѡ��");
           getchar();getchar();
         }
     }while(inp!=1&&inp!=2);
     
     switch(inp)
        { 
           case 1:add();break;
        }
}


int main()
{
    sy();
	dljm();
	return 0;
}  

