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

typedef struct Batch{
    char batch_name[10];
    int admission;
} Batch;

typedef struct Venue{
    char name_type[5];
    char lec_hall_name[15];
    char lab_name[15];
    char location_name[15];
    int lab_capacity;
    int lec_hall_capacity;
} Venue;




#endif