#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED
#include<time.h>
#include"conio.h"

typedef struct user
{
    char userid[20];
    char pwd[20];
    char name[20];
}user;


typedef struct car
{
    int car_id;
    char car_name[50];
    int capacity;
    int car_count;
    int price;
}car;
typedef struct customer_car_details
{
    int car_id;
    char cust_name[30];
    char pick[30];
    char drop[30];
    struct tm sd;
    struct tm ed;
}customer_car_details;
void addAdmin();
user* getinput();
int checkUserExist(user,char*);
int adminMenu();
void addEmployee();
void viewEmployee();
void addCarDetails();
void showCarDetails();
int deleteEmp();
int deleteCarModel();
int empMenu();
int selectCarModel();
int isValidDate(struct tm);
void updateCarCount(int);
void bookedCarDetails();
char* getCarName(int);
int rentCar();
void availCarDetails();



#endif // CAR_H_INCLUDED



