// C program for the above approach
#include"header.h"
// Driver Code
Venue v1[5];
Module m[5]; 
Faculaty f1[7];

void read_moduleData()
{
	FILE* fp = fopen("module.csv", "r");
    if (!fp) {
		// Error in file opening
		printf("Can't open file\n");
		exit(0);
	}
    char buffer[50];
    while (fgets(buffer,50,fp)!=NULL)
    {
        char *p= NULL;
        p = strtok(buffer,",");

        for (int i = 0; i < 5; i++)
        {
            if(i != 0)
                p=strtok(NULL,",");
            m[i].duration=atoi(p);
            p=strtok(NULL,",");
            strcpy(m[i].module_name,p);
            printf("%s ",m[i].module_name);
            printf("%d\n",m[i].duration);

        }
    }   
		fclose(fp);
}

void read_venue_Data()
{

	FILE* fp = fopen("venu.csv", "r");
    if (!fp) 
    {
		// Error in file opening
		printf("Can't open file\n");
		exit(0);
	}
    char buffer[29];
        for (int i = 0; i < 5; i++)
        {
           fgets(buffer,29,fp);
           char *p = strtok(buffer,",");
           if(strcmp(p,"l") == 0)
           {
                strcpy(v1[i].name_type,p);
                p = strtok(NULL,",");
                strcpy(v1[i].lab_name,p);

                p = strtok(NULL,",");
                v1[i].lab_capacity = atoi(p);

                strcpy(v1[i].lec_hall_name,"NA");
                v1[i].lec_hall_capacity = 0;
           }
           if(strcmp(p,"h") == 0)
           {
                strcpy(v1[i].name_type,p);
                p = strtok(NULL,",");
                strcpy(v1[i].lec_hall_name,p);

                p = strtok(NULL,",");
                v1[i].lec_hall_capacity = atoi(p);

                strcpy(v1[i].lab_name,"NA");
                v1[i].lab_capacity = 0;
           }
            p = strtok(NULL,",");
            strcpy(v1[i].location_name,p);
   
        }
	fclose(fp);
    //  print_venue();
 }

 void print_venue()
 {
    printf("Name         Type   Capacity Location     \n");
    for (int i = 0; i < 5; i++)
    {
        if(strcmp(v1[i].name_type,"l") == 0)
            printf("%s %s %d %s",v1[i].lab_name,v1[i].name_type,v1[i].lab_capacity,v1[i].location_name);
        if(strcmp(v1[i].name_type,"h") == 0)
            printf("%s %s %d %s",v1[i].lec_hall_name,v1[i].name_type,v1[i].lec_hall_capacity,v1[i].location_name);
    }
 }











