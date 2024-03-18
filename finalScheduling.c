#include "header.h"

extern int count;
extern StartBatch prev_startBatch[10];
void finalSchedule()
{
    read_Batch_Schedule();
    for (int i = 0; i < count; i++)
    {
        printf("Start date: %d %d %d\n", prev_startBatch[i].startDate.dd, prev_startBatch[i].startDate.mm, prev_startBatch[i].startDate.yy);
        printf("End date: %d %d %d\n", prev_startBatch[i].endDate.dd, prev_startBatch[i].endDate.mm, prev_startBatch[i].endDate.yy);
        printf("*******************\n");
    }
}

//------------------------------------------------
void print_weekly_report()
{
    Date start_date;
    Date end_date;
    read_Batch_Schedule();
    char name[10];
    printf("\n");
    printf("Which Batch Report Have : ");
    scanf("%s", name);
    if (validate_name(name))
    {
        printf("Batch Present : %s \n", name);
        for (int i = 0; i < count; i++)
        {
            //printf("%s %s %d  \n",name,prev_startBatch[i].newBatch.batch_name,strcmp(name, prev_startBatch[i].newBatch.batch_name) == 0);
            if (strcmp(name, prev_startBatch[i].newBatch.batch_name) == 0)
            {
                start_date = prev_startBatch[i].startDate;
                end_date = prev_startBatch[i].endDate;
                printf("Batch Start Date : %d-%d-%d\n",start_date.dd,start_date.mm,start_date.yy);
                printf("Batch End Date : %d-%d-%d\n",end_date.dd,end_date.mm,end_date.yy);
                {
                    int k = date(start_date, end_date);
                    printf("No of Working Days Of %s : %d \n", name, k);
                    final arr[k];
                    int c_prog = 10, ds = 20, cpp = 30, apti = 40,d = k,x;
                    {
                    Here:
                        printf("Allot Days to C proraming : ");
                        scanf("%d",&c_prog);
                        d = c_prog;
                        x = k - d;
                        printf("Days remaing : %d \n",x);
                        printf("Allot Days to Data Structure : ");
                        scanf("%d",&ds);
                        ds = ds+ c_prog;
                        d =  ds;
                        x = k - d;
                        printf("Days remaing : %d \n",x);
                        printf("Allot Days to CPP : ");
                        scanf("%d",&cpp);
                        cpp = cpp + ds;
                        d =  cpp;
                        x = k - d;
                        printf("Days remaing : %d \n",x);
                        printf("Allot Days to Apptitude : ");
                        scanf("%d",&apti);
                        apti = apti+ cpp;
                        d =  apti;
                        x = k - d;
                        printf("Days remaing : %d \n",x);
                        if(x < 0)
                        {
                            printf("Someting Wrong Calculation..\n");
                            goto Here;
                        }
                    }
                    for (int j = 0; j < k; j++)
                    {
                        // start_date.dd += j;
                        if (j == 0)
                        {
                            arr[j].date = start_date;
                        }
                        else
                        {
                            arr[j].date = next_date(&start_date); //     start_date;
                        }
                        strcpy(arr[j].lec_venue, prev_startBatch[i].venue.lec_hall_name);
                        arr[j].lec_time = prev_startBatch[i].batchTime.batch_Start_Time;

                        if (j < c_prog)
                        {
                            strcpy(arr[j].fac_name, prev_startBatch[i].faculaty[0].faculaty_name);
                            strcpy(arr[j].module, "C_prog");
                            arr[j].lab_time = prev_startBatch[i].batchTime.batch_End_Time - 2;
                            //printf("%s \n", arr[j].fac_name);
                        }
                        else if (j < ds)
                        {
                            strcpy(arr[j].fac_name, prev_startBatch[i].faculaty[1].faculaty_name);
                            // c_prog--;
                            strcpy(arr[j].module, "Data_Struc");
                            arr[j].lab_time = prev_startBatch[i].batchTime.batch_End_Time - 2;
                            // printf("%s \n",arr[j].fac_name);
                        }
                        else if (j < cpp)
                        {
                            strcpy(arr[j].fac_name, prev_startBatch[i].faculaty[2].faculaty_name);
                            // c_prog--;
                            strcpy(arr[j].module, "CPP");
                            arr[j].lab_time = prev_startBatch[i].batchTime.batch_End_Time - 2;
                            // printf("%s \n",arr[j].fac_name);
                        }
                        else if (j < apti)
                        {
                            strcpy(arr[j].fac_name, prev_startBatch[i].faculaty[3].faculaty_name);
                            strcpy(arr[j].module, "Apptitude");
                            arr[j].lab_time = prev_startBatch[i].batchTime.batch_End_Time - 2;
                            strcpy(arr[j].lec_venue,"NA");
                            // printf("%s \n",arr[j].fac_name);
                        }
                        else 
                        {
                            printf("Here\n");
                            strcpy(arr[j].fac_name,"NA");
                            strcpy(arr[j].module, "NA");
                            strcpy(arr[j].lec_venue,"NA");
                            arr[j].lab_time = 00;
                            strcpy(arr[j].lec_venue,"NA");
                            // printf("%s \n",arr[j].fac_name);
                        }
                        //printf("");
                    }
                    printf("---------------------------------------------------------\n");
                    printf("Date     Lec_Time    Module       Faculty     Lec_Venue  \n");
                    printf("---------------------------------------------------------\n");
                    for (int p = 0; p < k; p++)
                    {
                        printf("%02d/%d/%d  %d:00     %-10s    %-9s   %-10s \n", arr[p].date.dd, arr[p].date.mm, arr[p].date.yy, arr[p].lec_time, arr[p].module, arr[p].fac_name, arr[p].lec_venue);
                    }
                    //----------------------------------------------
                    write_schdule(arr,k);

                    //----------------------------------------------

                    read_schdule(k);
                }
                printf("Here \n");
                break;
            }
        }
    }
    else
    {
        printf("Batch Not Present : %s \n", name);
    }
}

//-----------------------------------------------

void read_schdule(int k)
{
    // Open a binary file in write mode
    FILE *f1 ;
    final arr[k];
    Date sd;
    Date ed;
    f1 = fopen("final.db", "rb");
    if (f1 == NULL)
    {
        fprintf(stderr, "Error- File can't Open \n");
        exit(1);
    }
    for (size_t i = 0; i < k; i++)
    {
        fread(&arr[i], sizeof(final), 1, f1);
    }
    printf("User Record Added into File .\n");
    fclose(f1);

    int choice;
    int p,i,diff,x= 0;
    do
    {
      printf("0.Exit\n1.Weekly Report\n2.Monthly Report\n3.All Report \n");
      printf("Your Choice : ");
      scanf("%d",&choice);
      switch (choice)
      {
        case 0:printf("Exit Menu..\n");
               break;
        case 1:printf("Weekly report \n");
               printf("Enter Start Date : ");
               scanf("%d%d%d",&sd.dd,&sd.mm,&sd.yy);
               printf("Enter End Date : ");
               scanf("%d%d%d",&ed.dd,&ed.mm,&ed.yy); 
               printf("---------------------------------------------------------\n");
               printf("Date     Lec_Time    Module       Faculty     Lec_Venue  \n");
               printf("---------------------------------------------------------\n");
               i = 0;
               while(i < k)
               {
                   if(arr[i].date.dd == sd.dd)
                   {
                        if(arr[i].date.mm== sd.mm)
                        {
                            if(arr[i].date.yy== sd.yy)
                            {
                                break;
                            }
                        }
                   }
                   i++;
               }
               diff = date(sd,ed);
               p=0;
               while(p <= diff)
               {  
                    printf("%02d/%d/%d  %d:00     %-10s    %-9s   %-10s \n", arr[i].date.dd, arr[i].date.mm, arr[i].date.yy, arr[i].lec_time, arr[i].module, arr[i].fac_name, arr[i].lec_venue);
                    p++;
                    i++;
               }
               printf("---------------------------------------------------------\n");                
               break;
        case 2:printf("Monthly report \n");
               printf("Enter Month To Get Report : ");
               scanf("%d",&p);
               printf("---------------------------------------------------------\n");
               printf("Date     Lec_Time    Module       Faculty     Lec_Venue  \n");
               printf("---------------------------------------------------------\n");
               i = 0;
               x = 0;
               while(i <= 31)
               {
                    if(arr[i].date.mm == p)
                    {
                        x++;
                        printf("%02d/%d/%d  %d:00     %-10s    %-9s   %-10s \n", arr[i].date.dd, arr[i].date.mm, arr[i].date.yy, arr[i].lec_time, arr[i].module, arr[i].fac_name, arr[i].lec_venue);
                    }
                    
                    if(arr[i].date.dd > 31)
                        break;
                    i++;
               }
               if(x == 0)
                    printf("Sorry No Record Found...\n");
                printf("---------------------------------------------------------\n");                
                            
               break;
        case 3:printf("All report \n");
               printf("---------------------------------------------------------\n");
               printf("Date     Lec_Time    Module       Faculty     Lec_Venue  \n");
               printf("---------------------------------------------------------\n");
               for( p = 0 ; p < k ; p++)
               {
                    printf("%02d/%d/%d  %d:00     %-10s    %-9s   %-10s \n", arr[p].date.dd, arr[p].date.mm, arr[p].date.yy, arr[p].lec_time, arr[p].module, arr[p].fac_name, arr[p].lec_venue);
               }
               break;
        
        default:printf("Invalid Choice...\n");
            break;
      } 
    } while (choice != 0);
    
}

//---------------------------------------------
void write_schdule(final arr[], int k)
{
    // Open a binary file in write mode
    FILE *f1 ;
    f1 = fopen("final.db", "ab");
    if (f1 == NULL)
    {
        fprintf(stderr, "Error- File can't Open \n");
        exit(1);
    }
    for (size_t i = 0; i < k; i++)
    {
        fwrite(&arr[i], sizeof(final), 1, f1);
    }
    printf("User Record Added into File .\n");
    fclose(f1);
}

//------------------------------------------------
int validate_name(char *batch)
{
    FILE *fp = fopen("scheduleBatch.csv", "r");
    if (!fp)
    {
        // Error in file opening
        printf("Can't open file\n");
        exit(0);
    }
    char buffer[100];
    char *p = NULL;
    while (fgets(buffer, 100, fp) != NULL)
    {
        p = strtok(buffer, ",");
        if (strcmp(p, batch) == 0)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
