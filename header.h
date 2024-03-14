#ifndef _HEADER_H
#define _HEADER_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h>
typedef struct Date
{
    int dd;
    int mm;
    int yy;
}Date;
typedef struct Time{
    int batch_Start_Time;
    int batch_End_Time;
}Time; 
typedef struct Module{
    char module_name[10];
    char Faculaty_name[10];
    int duration;
    Date startDate;
    Date endDate;
} Module;


#endif