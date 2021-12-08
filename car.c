#include<stdio.h>
#include"conio2.h"
#include"car.h"
#include<string.h>

void addAdmin()
{
    FILE *fp=fopen("admin.bin","rb");
    if(fp==NULL)
    {
        fp=fopen("admin.bin","wb");
        user u[2]={{"admin","test","Ravi"},{"super","demo","anil"}};
        fwrite(u,sizeof(u),1,fp);
    }
    fclose(fp);


}
user* getinput()//this will return adress of structure.
{
    int i;
    clrscr();
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");

    for(i=1;i<=80;i++)
    {
        printf("%c",247);
    }
    gotoxy(32,5);
    printf("*LOGIN PANNEL*");
    gotoxy(1,7);
    textcolor(LIGHTCYAN);
    for(i=1;i<=80;i++)
    {
        printf("%c",247);
    }
    gotoxy(1,15);
    for(i=0;i<=80;i++)
    {
        printf("%c",247);

    }
    gotoxy(60,8);
    textcolor(WHITE);
    printf("press 0 to exit");
    textcolor(LIGHTCYAN);
    gotoxy(25,10);
    printf("enter user id:");
    textcolor(WHITE);
    static user usr;
    fflush(stdin);
    fgets(usr.userid,20,stdin);
    char*pos=strchr(usr.userid,'\n');//strchr returns address.
    if(pos!=NULL)
     *pos='\0';
     if(strcmp(usr.userid,"0")==0)
     {
       textcolor(LIGHTRED);
       gotoxy(30,17);
       printf("LOGIN CANCELLED");

       textcolor(YELLOW);

       return NULL;


     }
     textcolor(LIGHTCYAN);
     gotoxy(25,11);
     printf("Enter password:");
     fflush(stdin);
     i=0;
      textcolor(WHITE);
      for(;;)
      {
          usr.pwd[i]=getch();
          if(usr.pwd[i]==13)
          {
              break;
          }
          if(usr.pwd[i]==8)
          {
              printf("\b\b");
              i--;
          }
          else{
          printf("*");
          i++;
          }
      }
      usr.pwd[i]='\0';
      if(strcmp(usr.pwd,"0")==0)
     {
       textcolor(LIGHTRED);
       gotoxy(30,17);
       printf("LOGIN CANCELLED");
       getch();
       return NULL;


     }
      return &usr;
      getch();




}

int checkUserExist(user u,char*usertype)
{
  if(strlen(u.userid)==0||strlen(u.pwd)==0)
{  gotoxy(28,20);
    textcolor(LIGHTRED);
    printf("Both fields are mandatory try again.");
    getch();
    gotoxy(28,20);
    printf("\t\t\t\t\t");
    return 0;
} FILE*fp;
if(strcmp(usertype,"admin")==0)
{
    fp=fopen("admin.bin","rb");


}
else{
    fp=fopen("emp.bin","rb");
    }
      if(fp==NULL)
    {
     gotoxy(28,20);
    textcolor(LIGHTRED);
    printf("sorry cannot open file!");
    getch();
    gotoxy(28,20);
    printf("\t\t\t\t\t");
    return -1;
    }
    int found=0;
     user user;
    while(fread(&user,sizeof(user),1,fp)==1)
    {
        if(strcmp(u.userid,user.userid)==0&&strcmp(u.pwd,user.pwd)==0)
        {
            found=1;
        break;
        }
    }
    if(found==0)
    {
      gotoxy(28,20);
    textcolor(LIGHTRED);
    printf("Invalid userid/password.try again!");
    getch();
    gotoxy(28,20);
    printf("\t\t\t\t\t");


    }
    else{
            gotoxy(28,20);
    textcolor(GREEN);
    printf("Login successfull");
    getch();
    gotoxy(28,20);
    printf("\t\t\t\t\t");
    }

    fclose(fp);
    return found;


}
int adminMenu()
{

    int i,choice;
    textcolor(LIGHTRED);
    gotoxy(32,2);
    printf("CAR RENTAL SYSTEM");
    textcolor(GREEN);
    gotoxy(34,6);
    printf("ADMIN MENU\n");
    for(i=0;i<=80;i++)
    {
        printf("*");
    }
    gotoxy(32,8);
    textcolor(YELLOW);
    printf("1. Add Employee");
    gotoxy(32,9);
    printf("2. Add car detail");
    gotoxy(32,10);
    printf("3. Show employee");
    gotoxy(32,11);
    printf("4. Show car details");
    gotoxy(32,12);
    printf("5. Delete employee");
    gotoxy(32,13);
    printf("6. Delete car details");
    gotoxy(32,14);
    printf("7. Exit");
    gotoxy(32,16);
    printf("Enter your choice:");
    scanf("%d",&choice);
    return choice;

}
void addEmployee()
{  char empid[10]={"EMP-"};
char temp[10];
int i;
char choice;
user U;
char*pos;
FILE*fp=fopen("emp.bin","ab+");
fseek(fp,0,SEEK_END);
long total_rec=ftell(fp)/sizeof(user);
if(total_rec!=0)
{
    fseek(fp,-60,SEEK_END);
    fread(temp,sizeof(temp),1,fp);
    //printf("temp is %s",temp);

    pos=strchr(temp,'-');
    total_rec=atoi(pos+1);
    //printf("\ntotal rec is %d",total_rec);
     getch();
}
total_rec++;
sprintf(temp,"%d",total_rec);//used for converting int to string
strcat(empid,temp);
strcpy(U.userid,empid);
fseek(fp,0,SEEK_END);
do
    {
      clrscr();
       gotoxy(32,2);
       textcolor(RED);
       printf("CAR RENTAL APP");
       gotoxy(1,3);
       textcolor(LIGHTGREEN);
       for(i=1;i<=80;i++)
       printf("~");

       gotoxy(25,5);
       textcolor(WHITE);
       printf("*****ADD EMPLOYEE DETAILS*****");
       gotoxy(1,8);
       textcolor(YELLOW);
       printf("enter employee name:");
       fflush(stdin);
       textcolor(WHITE);
       fgets(U.name,20,stdin);
       char*p=strchr(U.name,'\n');
       if(p!=NULL)
       {
           *p='\0';
       }
       textcolor(YELLOW);
       printf("Enter employee password:");
       fflush(stdin);
        textcolor(WHITE);
       fgets(U.pwd,20,stdin);
       char*pos=strchr(U.pwd,'\n');
       if(pos!=NULL)
       {
           *pos='\0';
       }
       fwrite(&U,sizeof(U),1,fp);
       gotoxy(30,15);
       textcolor(LIGHTGREEN);
       printf("EMPLOYEE ADDED SUCCESSFULLY.");
       printf("EMPLOYEE ID IS:%s",U.userid);
       getch();
       gotoxy(1,19);
       textcolor(LIGHTRED);
       printf("Do you want to add more employees?(Y/N)");
       textcolor(WHITE);
       fflush(stdin);
       scanf("%c",&choice);
       if(choice=='N')
        break;
       total_rec++;
       sprintf(U.userid,"EMP-%d",total_rec);
    }while(choice=='Y');
    fclose(fp);

}
void addCarDetails()
{
char choice;
int x,i;
char temp[20];
FILE*fp=fopen("car.bin","ab+");
fseek(fp,0,SEEK_END);
long total_rec=ftell(fp)/sizeof(car);
total_rec++;
do
    {
      clrscr();
      car C;
      C.car_id=total_rec;
      gotoxy(32,2);
      textcolor(LIGHTRED);
      printf("CAR RENTAL APP");
      gotoxy(1,4);
      textcolor(GREEN);
      for(i=1;i<=80;i++)
      {
          printf("%c",247);

      }
      gotoxy(24,6);
      textcolor(WHITE);
      printf("*****ADD CAR DETAILS*****");
      gotoxy(1,8);
      textcolor(YELLOW);
      printf("Enter car model:\n");
      printf("Enter car capacity:\n");
      printf("Enter car count:\n");
      printf("Enter car price per day:\n");
      gotoxy(17,8);
      textcolor(WHITE);
      fflush(stdin);
      fgets(temp,20,stdin);
      char*pos=strchr(temp,'\n');
      if(pos!=NULL)
      {
          *pos='\0';
      }
      strcpy(C.car_name,temp);
      gotoxy(21,9);
      scanf("%d",&x);
      C.capacity=x;
      gotoxy(17,10);
      scanf("%d",&x);
      C.car_count=x;
      gotoxy(26,11);
      scanf("%d",&x);
      C.price=x;
      fwrite(&C,sizeof(C),1,fp);

      gotoxy(32,13);
      textcolor(LIGHTGREEN);
      printf("CAR ADDED SUCCESSFULLY\n");
      printf("CAR ID IS:%d",C.car_id);
      getch();
      gotoxy(1,15);
      textcolor(LIGHTRED);
      printf("DO YOU WANT TO ADD MORE CAR(Y/N)? ");
      fflush(stdin);
      scanf("%c",&choice);
      if(choice=='N')
      {
         break;
      }
      total_rec++;
    }while(1);
      fclose(fp);

}
void viewEmployee()
{

    FILE*fp=fopen("emp.bin","rb");

    int i;
    textcolor(YELLOW);
    user ur;
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    for(i=1;i<=80;i++)

        printf("%c",247);

    gotoxy(31,5);
    textcolor(YELLOW);
    printf("*EMPLOYEE DETAILS*");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(i=1;i<80;i++)
    {
        printf("%c",247);

    }
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        gotoxy(31,9);
        printf("SORRY! NO EMPLOYEES ADDED YET!");
        getch();
        return;
    }
    gotoxy(1,8);
    printf("EMPLOYEE ID\t\t\tNAME\t\t\tPASSWORD\t\t\t");
    gotoxy(1,9);
    for(i=1;i<=80;i++)
        printf("%c",247);

    int a=10;
    textcolor(YELLOW);
    while(fread(&ur,sizeof(ur),1,fp)==1)
    {
      gotoxy(2,a);
      printf("%s",ur.userid);
      gotoxy(33,a);
      printf("%s",ur.name);
      gotoxy(57,a);
      printf("%s",ur.pwd);
      a++;
    }
    fclose(fp);
    getch();
}
void showCarDetails()
{
    FILE *fp=fopen("car.bin","rb");
    car C;
    int i;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    for(i=1; i<=80; i++)
    printf("%c",247);
    gotoxy(31,5);
    textcolor(YELLOW);
    printf("* ALL CAR DETAILS *");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(i=1; i<80; i++)
        printf("%c",247);
if(fp==NULL)
    {
        gotoxy(31,9);
        textcolor(LIGHTRED);
        printf("Sorry! No cars present");
        getch();
        return;
    }

    gotoxy(1,8);
    printf(" Car ID\t   Model\t\t   Capacity\tAvailable\tPrice/Day");
    gotoxy(1,9);
    textcolor(LIGHTGREEN);
    for(i=1; i<80; i++)
        printf("%c",247);
    int x=10;
    textcolor(YELLOW);

    while(fread(&C,sizeof(C),1,fp)==1)
    {
        gotoxy(2,x);
        printf("%d",C.car_id);
        gotoxy(12,x);
        printf("%s",C.car_name);
        gotoxy(38,x);
        printf("%d",C.capacity);
        gotoxy(50,x);
        printf("%d",C.car_count);
        gotoxy(68,x);
        printf("%d",C.price);
        x++;


    }
    fclose(fp);
    _getch();
}
int deleteEmp()
{
    FILE*fp1=fopen("emp.bin","rb");
    char empid[10];
    int i,result;
    gotoxy(32,1);
    textcolor(YELLOW);
    printf("CAR RENTAL SYSTEM\n");
    for(i=1;i<80;i++)
    {
        printf("%c",247);
    }
    gotoxy(29,5);
    printf("*DELETE EMPLOYEE RECORD*");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
     for(i=1;i<80;i++)
    {
        printf("%c",247);
    }
    gotoxy(1,12);
     for(i=1;i<=80;i++)
    {
        printf("%c",247);
    }
    if(fp1==NULL)
    {
      textcolor(LIGHTRED);
      gotoxy(32,10);
      printf("NO EMPLOYEES ADDED YET");
      return -1;
    }
   FILE*fp2=fopen("temp.bin","wb");
   if(fp2==NULL)
    {
      textcolor(LIGHTRED);
      gotoxy(32,10);
      printf("sorry!cannot open file");
      return -1;
    }
    gotoxy(10,9);
    textcolor(YELLOW);
    printf("Enter employee id to delete the record:");
    textcolor(WHITE);
    scanf("%s",empid);
    user u;
    int found=0;
    while(fread(&u,sizeof(u),1,fp1)==1)
    {
        if(strcmp(empid,u.userid)==0)
            found=1;
        else
            fwrite(&u,sizeof(u),1,fp2);

    }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
    {
        remove("temp.bin");
        return 0;
    }
    else
    {
        result=remove("emp.bin");
    if(result!=0)
        return 2;
   result=rename("temp.bin","emp.bin");
   if(result!=0)
    return 2;
    }
    return found;

}
int deleteCarModel()
{
    FILE*fp1=fopen("car.bin","rb");
    int carid;
    int i,result;
    gotoxy(32,1);
    textcolor(YELLOW);
    printf("CAR RENTAL SYSTEM\n");
    for(i=1;i<80;i++)
    {
        printf("%c",247);
    }
    gotoxy(29,5);
    printf("*DELETE CAR RECORD*");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
     for(i=1;i<80;i++)
    {
        printf("%c",247);
    }
    gotoxy(1,12);
     for(i=1;i<80;i++)
    {
        printf("%c",247);
    }
    if(fp1==NULL)
    {
      textcolor(LIGHTRED);
      gotoxy(32,10);
      printf("NO CARS ADDED YET");
      return -1;
    }
   FILE*fp2=fopen("temp.bin","wb+");
   if(fp2==NULL)
    {
      textcolor(LIGHTRED);
      gotoxy(32,10);
      printf("sorry cannot open file.");
      return -1;
    }
    gotoxy(10,9);
    textcolor(YELLOW);
    printf("Enter car id to delete the record:");
    textcolor(WHITE);
    scanf("%d",&carid);
    car u;
    int found=0;
    while(fread(&u,sizeof(u),1,fp1)==1)
    {
        if(carid==u.car_id)
            found=1;
        else
            fwrite(&u,sizeof(u),1,fp2);

    }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
    {
        remove("temp.bin");
        return 0;
    }
    else
    {
        result=remove("car.bin");
    if(result!=0)
        return 2;
   result=rename("temp.bin","car.bin");
   if(result!=0)
    return 2;
    }
    return found;

}



int empMenu()
{
    int i,choice;
    textcolor(LIGHTRED);
    gotoxy(32,2);
    printf("CAR RENTAL SYSTEM");
    textcolor(LIGHTGREEN);
    gotoxy(35,6);
    printf("EMPLOYEE MENU\n");
    for(i=0;i<=80;i++)
    {
        printf("*");
    }

    textcolor(YELLOW);
    gotoxy(32,8);
    printf("1. Rent A Car");
    gotoxy(32,9);
    printf("2.Booking Details");
    gotoxy(32,10);
    printf("3.Available car Details");
    gotoxy(32,11);
    printf("4.Show all car details");
    gotoxy(32,12);
    printf("5.Exit");
    gotoxy(32,13);
    printf("Enter a choice:");
    scanf("%d",&choice);
    return choice;
}
int selectCarModel()
{
  FILE*fp=fopen("car.bin","rb");
  int choice,flag;
  int rowno=9;
  car c;
  int carcount=0;
  gotoxy(34,rowno);
  while(fread(&c,sizeof(c),1,fp)==1)
  {
      if(c.car_count>0)
      {
          printf("%d,%s",c.car_id,c.car_name);
          gotoxy(34,++rowno);
          ++carcount;

      }
  }
  if(carcount==0)
  {
      fclose(fp);
      return -2;
  }

  gotoxy(34,rowno+2);

      printf("Enter your choice(enter 0 to quit):");
      while(1)
      {
          flag=0;
          scanf("%d",&choice);
          if(choice==0)
          {
              fclose(fp);
              return 0;
          }
          rewind(fp);
           while(fread(&c,sizeof(c),1,fp)==1)
         {
             if(c.car_id==choice&& c.car_count>0)
               {
                   flag=1;
                   break;
               }
         }
         if(flag==1)
         {
             fclose(fp);
             return choice;
         }
         gotoxy(37,rowno+4);
         textcolor(LIGHTRED);
         printf("Wrong input!");
         getch();
         gotoxy(35,rowno+4);
         printf("\t\t\t");
         gotoxy(52,rowno+2);
         printf("\t\t");
         gotoxy(52,rowno+2);
         textcolor(WHITE);

      }

}
int isValidDate(struct tm dt)
{
 if(dt.tm_year>=2021&&dt.tm_year<=2022)
    {
      if(dt.tm_mon>=1&&dt.tm_mon<=12)
      {
          if((dt.tm_mday>=1&&dt.tm_mday<=31)&&(dt.tm_mon==1||dt.tm_mon==3||dt.tm_mon==5||dt.tm_mon==7||dt.tm_mon==8||dt.tm_mon==10||dt.tm_mon==12))
          return 1;
          else if((dt.tm_mday>=1&&dt.tm_mday<=30)&&(dt.tm_mon==4||dt.tm_mon==4||dt.tm_mon==9||dt.tm_mon==11))
          return 1;
          else if((dt.tm_mday>=1&&dt.tm_mday<=28)&&(dt.tm_mon==2))
          return 1;
          else if((dt.tm_mday>=1&&dt.tm_mday<=29)&&dt.tm_mon==2&&(dt.tm_year%400==0||(dt.tm_year%4==0&&dt.tm_year%100!=0)))
          return 1;

      }

    }
    return 0;
}

void updateCarCount(int c_id)
{
    FILE*fp=fopen("car.bin","rb+");
    if(fp==NULL)
        {
          printf("sorry!file cannot be opened");
          getch();
          return;
        }
        car C;
        while(fread(&C,sizeof(car),1,fp)==1)
        {
            if(C.car_id==c_id)
                {

                    int x=C.car_count;
                    x--;
                    fseek(fp,-8,SEEK_CUR);
                    fwrite(&x,sizeof(x),1,fp);

                    break;


                }
        }

    fclose(fp);
}
void bookedCarDetails()
{
    clrscr();
    FILE*fp=fopen("customer.bin","rb");

        customer_car_details CC;
        int i;
        textcolor(YELLOW);
        gotoxy(32,1);
        printf("CAR RENTAL SYSYTEM\n");
        for(i=1;i<=80;i++)
        printf("%c",247);
        gotoxy(31,5);
        printf("BOOKED CAR DETAILS\n");
        gotoxy(1,7);
        textcolor(LIGHTGREEN);
        for(i=1;i<=80;i++)
        printf("%c",247);
       gotoxy(1,8);
       printf("Model\t    Cust name\t   Pick Up\t  Drop\t\t  S_Date\t E_Date");
       gotoxy(1,9);
       textcolor(LIGHTGREEN);
        for(i=1;i<=80;i++)
         printf("%c",247);
        int row=10;
        textcolor(YELLOW);
        while(fread(&CC,sizeof(customer_car_details),1,fp)==1);
        {
            gotoxy(1,row);
            printf("%s",getCarName(CC.car_id));
            gotoxy(13,row);
            printf("%s",CC.cust_name);
            gotoxy(27,row);
            printf("%s",CC.pick);
            gotoxy(44,row);
            printf("%s",CC.drop);
            gotoxy(58,row);
            printf("%d-%d-%d",CC.sd.tm_mday,CC.sd.tm_mon,CC.sd.tm_year);
            gotoxy(70,row);
            printf("%d-%d-%d",CC.ed.tm_mday,CC.ed.tm_mon,CC.ed.tm_year);

            row++;


        }
        fclose(fp);
        getch();

}
char* getCarName(int c_id)
{
    FILE*fp=fopen("car.bin","rb");
    if(fp==NULL)
    {
        printf("sorry! file cannot be opened.");
        return NULL;
    }
    static car c;
    while(fread(&c,sizeof(c),1,fp)==1)
    {
       if(c.car_id==c_id)
       {
           break;
       }
    }
    fclose(fp);
    return c.car_name;
}
int rentCar()
{
    customer_car_details CC;
    int i,c;
    textcolor(LIGHTRED);
    gotoxy(32,2);
    printf("CAR RENTAL SYSTEM");
    textcolor(LIGHTGREEN);
    gotoxy(35,6);
    printf("EMPLOYEE MENU\n");
    for(i=1;i<=80;i++)
         printf("*");
    textcolor(YELLOW);
    gotoxy(32,8);
    c=selectCarModel();
    if(c==0||c==-2)
        return c;
    CC.car_id=c;
    clrscr();
     textcolor(LIGHTRED);
    gotoxy(32,2);
    printf("CAR RENTAL SYSTEM");
    textcolor(LIGHTGREEN);
    gotoxy(35,6);
    printf("EMPLOYEE MENU\n");
    for(i=1;i<=80;i++)
         printf("*");
    gotoxy(1,17);
    for(i=1;i<=80;i++)
         printf("*");
    textcolor(YELLOW);
    gotoxy(27,9);
    printf("Enter customer name:");
    fflush(stdin);
    textcolor(WHITE);
    fgets(CC.cust_name,30,stdin);
    char*pos=strchr(CC.cust_name,'\n');
    if(pos!=NULL)
    *pos='\0';
    gotoxy(27,10);
    textcolor(YELLOW);
    printf("Enter pickup point:");
    textcolor(WHITE);
    fflush(stdin);
    fgets(CC.pick,30,stdin);
    pos=strchr(CC.pick,'\n');
    if(pos!=NULL)
    *pos='\0';
    gotoxy(27,11);
    textcolor(YELLOW);
    printf("Enter drop point:");
    textcolor(WHITE);
    fflush(stdin);
    fgets(CC.drop,30,stdin);
    pos=strchr(CC.drop,'\n');
    if(pos!=NULL)
    *pos='\0';
    gotoxy(27,12);
    textcolor(YELLOW);
    printf("Enter start date(dd/mm/yyyy):");
    textcolor(WHITE);
    do
    {
        scanf("%d/%d/%d",&CC.sd.tm_mday,&CC.sd.tm_mon,&CC.sd.tm_year);
        int datevalid=isValidDate(CC.sd);
        if(datevalid==1)
        break;
        gotoxy(27,18);
        textcolor(LIGHTRED);
        printf("wrong date");
        getch();
        gotoxy(56,12);
        printf("\t\t\t");
        gotoxy(56,12);
        textcolor(WHITE);
    }while(1);
    gotoxy(27,13);
    textcolor(YELLOW);
    printf("Enter end date(dd/mm/yyyy):");
    textcolor(WHITE);
    do
    {
        scanf("%d/%d/%d",&CC.ed.tm_mday,&CC.ed.tm_mon,&CC.ed.tm_year);
        int datevalid=isValidDate(CC.ed);
        if(datevalid==1)
        break;
        gotoxy(27,18);
        textcolor(LIGHTRED);
        printf("wrong date");
        getch();
        gotoxy(54,13);
        printf("\t\t\t");
        gotoxy(54,13);
        textcolor(WHITE);
    }while(1);
    //now validate the dates against current date as well as against each other
    FILE*fp=fopen("customer.bin","ab");
    if(fp==NULL)
    {
        gotoxy(27,18);
        textcolor(LIGHTRED);
        printf("sorry file cannot be opened!");
        return -1;
    }
    fwrite(&CC,sizeof(customer_car_details),1,fp);
    gotoxy(27,18);
    textcolor(WHITE);
    printf("Booking details");
    printf("Booking done for car %d",CC.car_id);
    printf("\npress any key to continue");
    getch();
    fclose(fp);
    updateCarCount(CC.car_id);
    bookedCarDetails();
    return 1;

}
void availCarDetails()
{
    FILE*fp=fopen("car.bin","rb");
    car C;
    int i;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    textcolor(LIGHTGREEN);
    for(i=1;i<80;i++)
        printf("%c",247);
    gotoxy(32,5);
    textcolor(YELLOW);
    printf("*AVAILABLE CAR DETAILS*");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(i=1;i<80;i++)
        printf("%c",247);
    if(fp==NULL)
    {
        gotoxy(32,8);
        textcolor(LIGHTRED);
        printf("sorry file cannot be opened.");
        getch();
        return;
    }
    gotoxy(1,8);
    printf("CAR ID\t   MODEL\t\tCAPACITY \tAVAIALABLE\tPRICE/DAY");
    gotoxy(1,9);
    for(i=1;i<80;i++)
        printf("%c",247);
    int row=10;
    textcolor(YELLOW);
    while(fread(&C,sizeof(C),1,fp)==1)
    {
        if(C.car_count>0)
        {
            gotoxy(2,row);
            printf("%d",C.car_id);
            gotoxy(13,row);
            printf("%s",C.car_name);
            gotoxy(35,row);
            printf("%d",C.capacity);
            gotoxy(50,row);
            printf("%d",C.car_count);
            gotoxy(68,row);
            printf("%d",C.price);
            row++;
        }
    }

    fclose(fp);
    getch();
}

