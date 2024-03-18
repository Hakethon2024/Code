#include"header.h"

int count = 0;
void read_line_count()
{
    FILE* fp = fopen("scheduleBatch.csv", "r");
    if (!fp) {
		// Error in file opening
		printf("Can't open file\n");
		exit(0);
	}
    char buffer[100];
    while (fgets(buffer,100,fp)!=NULL)
    {
        count++;
    }   
	fclose(fp);
    printf("Total Scheduled Batches count :: %d\n",count);
}