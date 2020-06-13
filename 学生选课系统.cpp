#include"stdio.h"
#include"stdlib.h"//定义内存分配函数
#include"windows.h"
#include"string.h"
#include"student.h"

void sy();//首页
void dljm();
void tcjm();//退出界面
void xsdlcd();//学生登录菜单 
void xk();
void kcll();//课程浏览 
void add();//增加课程
void xscx();//学生查询函数
void xsll();//学生浏览函数


void sy()//首页
{
     char input;
     printf("\n\n\t\t\t****************************\n");
  	printf("\t\t\t     湖南工业大学选课系统        \n");
  	printf("\t\t\t****************************\n\n\n");
    printf("\t\t\t****************************\n\n\n");
    printf("\t\t\t****************************\n\n\n");
  	printf("\t\t\t****************************\n\n\n");
  	printf("\t\t\t******设计者；王功、尚磊****\n\n\n");
      input=getchar();
      system("cls");//清屏 
}
void dljm()//登陆界面 
{
     void xsdlcd(); 
     void tcjm();
     
     int input;
     do
     {
          system("cls");
          printf("\n\n\n\t1.进入本系统\n");
          printf("\t2.退出本系统\n");
          printf("\t请选择服务类别:");
          scanf("%d",&input);
          if (input!=1&&input!=2)  //输入数不等于选项的时候打印画面
          {
              printf("\n\t输入出错!请重新选择~\n");
              printf("\n\t按任意键返回选择页面~\n\t");
              getchar();getchar();
              system("cls");
          }
          if(input==2)//如果输入2退出系统 
          {
             tcjm();
          }
      }while(input!=1&&input!=2);
      
      switch(input)
      {
         case 1:xsdlcd();break;
       
      }
}


void tcjm()//退出界面
{
exit(0);//正常运行程序并退出程序
}



void xsdlcd()//学生登录菜单 
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
         printf("\n\n\n\t--系统功能--");
         printf("\n\n\t1.学生选课\n");
         printf("\t2.课程浏览\n");
         printf("\t3.课程查询\n");
         printf("\t4.增加课程\n");
         printf("\t5.退出\n"); 
         scanf("%d",&input);
         if(input!=1&&input!=2&&input!=3&&input!=4&&input!=5)
         {
             printf("\n\t没有这项服务~\n");
              printf("\t按任意键重新选择");
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
  
  
  
  
 if((fp=fopen("course.dat","rb"))==NULL) //判断是否存在课程 
      {
         
         printf("\n\n\n\t课程不存在\n\n");
         printf("\t<按任意键返回管理菜单>\n\t");
         input=getchar();
         input=getchar();
         xsdlcd();//进入学生登陆菜单                             
      }                                  
           
     else//存在的话循环读取文件中的信息直到文件指针到文件尾部 
     {
       do
        {
          fread(&courses[i],sizeof(struct course),1,fp);//读取课程元素个数 
          i=i+1;
        }
      while(!feof(fp));//文件读取到尾部 
      fclose(fp);//文件读完后关闭
    }
     printf("\n\n\t\t请输入你要选课程的编号：");
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
             printf("\n\n\t\t不存在对应课程\n");
			 printf("\n\n\t\t继续选课请按1，退出请按2:\n");
			 scanf("%d",&in);
			 switch(in)
			 {
			 case 1:xk();break;
             case 2:xsdlcd();break;
             default:
				 printf("输入错误，将返回登录界面！\n");
				 dljm();break;
			}
		   }
            
         else
            {
               fwrite(&courses[j],sizeof(struct course),1,fp1);
               fclose(fp1);
            
         
       
      printf("\n\n\t\t选课成功\t请选择：");
      printf("\n\n\t\t1.继续选课"); 
      printf("\n\n\t\t2.退出，返回登录界面！");
      scanf("%d",&in);
      switch(in)
         {
             case 1:xk();break;
             case 2:xsdlcd();break;
             default:break;
         }
		 }
} 


void xsll()//课程浏览 
{
    void xsdlcd();
    void kcll() ; 
    int   inp,i=0,n=0;
    FILE *fp;
    char input;
    struct course courseview[10];
    
    if((fp=fopen("course.dat","rb"))==NULL) //判断是否存在课程 
      {
         system("cls");
         printf("\n\n\n\t课程不存在\n\n");
         printf("\t<按任意键返回管理菜单>\n\t");
         getchar();getchar();
         xsdlcd();//进入学生登陆菜单                             
      }                                  
           
     else//存在的话循环读取文件中的信息直到文件指针到文件尾部 
     {
       do
        {
          fread(&courseview[i],sizeof(struct course),1,fp);
          i=i+1;
        }
      while(!feof(fp));
      fclose(fp);//文件读完后关闭
      
      do
      {
         system("cls");
		 if(i==1)
		 {
			 printf("\n\n\n\t\t\t没有记录！\n");
			 getchar();getchar();
			 xsdlcd();
         }
		 else
		 {
			 printf("\n\t------共有%d条记录-------",i-1);
			 printf("\n\n\t课程编号： %d\n",courseview[n].bh);
			 printf("\n\n\t课程名字： %s\n",courseview[n].mc);
		     printf("\n\n\t课程学分： %d\n",courseview[n].xf);
		     printf("\n\n\t课程已选人数： %d\n",courseview[n].alreadypp);
		     printf("\n\n\t课程人数上限： %d\n",courseview[n].maxpp);
		     
	         printf("\n\n\t1.上一页\t2.下一页\t3.回目录");
             printf("\n请选择：");
    	     scanf ("%d",&inp);
	         switch(inp)
			 {
               case 1:
                    {
                      if(n==0)
                         {
                          printf("\n\t已到达首页 \t按任意键返回");
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
                              printf("\n\t已到达尾页\t按任意键返回");
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
                           printf("\n\t操作错误\t按任意键返回");
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

    if ((fp=fopen("course.dat","rb"))==NULL)   //判断课程信息是否存在
      {
         system("cls");
         printf("\n\n\t课程不存在\t按任意键返回");
         getchar();getchar();
         xsdlcd();
        }
    else//存在的话循环读取文件中的信息直到文件指针到文件尾部 
       {
           do
             {
                 fread(&coursesear[i],sizeof(struct course),1,fp);
                  i=i+1;
              }while(!feof(fp));
            fclose(fp);
         }
    system("cls");
    printf("\n\n\t\t\t请输入你要查询的课程编号：");
    scanf("%d",&id);
    
    do//检查输入是否符合要求 
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
                  printf("\n\n\t课程编号:%d\n",coursesear[k].bh);
                  printf("\n\n\t课程名字:%s\n",coursesear[k].mc);
                  printf("\n\n\t课程学分:%d\n",coursesear[k].xf);
                  printf("\n\n\t课程已选人数:%d\n",coursesear[k].alreadypp);
                  printf("\n\n\t课程人数上限:%d\n",coursesear[k].maxpp);
				  getchar();getchar();
				  printf("\n\n\t1.回目录继续查询\t2.退出查询系统\n");
                  printf("请选择：");
                  scanf("%d",&inp);
                  switch(inp)
                     {
                        case 1:xscx();
                        case 2:xsdlcd();
                        default:
                            {
                                printf("\n\t没有这项服务\t请按任意键重新输入");
                                getchar();getchar(); 
                             }
                        }
				} 
                else 
                  {
                      system("cls");
                      printf("\n\n\t不存在对应记录\n");
                      printf("\n\n\t1.回目录继续查询\t2.退出查询系统\n");
                      printf("请选择：");
                      scanf("%d",&inp);
                      switch(inp)
                     {
                        case 1:xscx();
                        case 2:xsdlcd();
                        default:
                            {
                                printf("\n\t没有这项服务\t请按任意键重新输入");
                                getchar();getchar(); 
                             }
                        }
				}
           }while(inp!=1);
} 


void add()//增加课程
{
     void add();
     int i=0,j,inp;
       
     FILE *fp;
     struct course course_new;
     struct course courses[10];
     
     system("cls");
     printf("\n\n\t\t请输入课程信息");
     printf("\n\n\t\t1.课程编号:");
     scanf("%d",&course_new.bh); 
     printf("\n\n\t\t2.课程名字:");
     scanf("%s",course_new.mc);
     printf("\n\n\t\t3.课程学分:");
     scanf("%d",&course_new.xf);
     printf("\n\n\t\t4.课程已选人数:");
     scanf("%d",&course_new.alreadypp);
     printf("\n\n\t\t5.课程人数上限:");
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
            printf("\n\n\t\t\t对不起，这个编号已经使用过\n\n\t\t按任意键返回管理菜单");
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
    
    printf("\n\n\t\t信息输入完毕\t按任意键继续");
    getchar();getchar();
    
    do
     {
       system("cls");
       printf("\n\n\t\t1.继续输入");
       printf("\n\n\t\t2.返回管理菜单");
       printf("\n\n\t\t请选择");
       scanf("%d",&inp);
       if(inp!=1&&inp!=2)
         {
           printf("输入不符合要求\t按任意键重新选择");
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

