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











