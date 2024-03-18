#include"header.h"


bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(Date d) {
    if (d.yy < 1) {  // Check if the year is valid
        return false;
    }
    if (d.mm < 1 || d.mm > 12) { // Check if the month is valid
        return false;
    }
    // Check if the day is valid
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (d.mm == 2 && isLeapYear(d.yy)) { // Adjust for leap year
        daysInMonth[2] = 29;
    }
    if (d.dd < 1 || d.dd > daysInMonth[d.mm]) {
        return false;
    }
    return true;
}
int datecmp(Date d1,Date d2) {
    // Compare the dates and return the result
    // printf("%d  %d\n",isValidDate(d1),isValidDate(d1));
    if (isValidDate(d1) && isValidDate(d2)) {
        if (d1.dd == d2.dd && d1.mm == d2.mm && d1.yy ==d2.yy)
            return 0;
        else if (d1.yy > d2.yy || (d1.yy == d2.yy && (d1.mm > d2.mm || (d1.mm == d2.mm && d1.dd > d2.dd))))
            return 1;
        else
            return -1;
    }else{
        printf("The entered date is not valid\n");
        return 0;
    }
}

//------------------------------------------------
// Function to calculate the day of the week using Zeller's Congruence algorithm
// Returns 0 for Sunday, 1 for Monday, and so on up to 6 for Saturday
int calculateDayOfWeek(int day, int month, int year) 
{
    if (month < 3) 
    {
        month += 12;
        year -= 1;
    }

    int q = day;
    int m = month;
    int K = year % 100;
    int J = year / 100;

    int h = (q + ((13 * (m + 1)) / 5) + K + (K / 4) + (J / 4) - (2 * J)) % 7;

    // Adjust the result to start from Sunday (0)
    return (h + 6) % 7;
}

int date( Date sd , Date ed) 
{
    
    int count = 0;

    // // Input start date from the user
    // printf("Enter start date (DD MM YYYY): ");
    // scanf("%d %d %d", &sd.dd, &sd., &start_year);

    // // Input end date from the user
    // printf("Enter end date (DD MM YYYY): ");
    // scanf("%d %d %d", &end_day, &end_month, &end_year);

    // Check for valid input
    if (sd.dd <= 0 || sd.mm <= 0 || sd.mm > 12 || sd.yy <= 0 ||
        ed.dd <= 0 || ed.mm <= 0 || ed.mm > 12 || ed.yy <= 0) {
        printf("Invalid date!\n");
        return 1;
    }

    // Open the CSV file for reading
    // FILE *file = fopen("scheduleBatch.csv", "r");
    // if (file == NULL) {
    //     printf("Error opening file!\n");
    //     return 1;
    // }

    // Loop through the dates from start date to end date
    while (sd.dd != ed.dd || sd.mm != ed.mm || sd.yy != ed.yy) {
        // Calculate the day of the week
        int dayOfWeek = calculateDayOfWeek(sd.dd, sd.mm, sd.yy);

        // Print the date and day with an asterisk (*) if it's Saturday (6) or Sunday (0)
        printf("%02d-%02d-%d: ", sd.dd, sd.mm, sd.yy);
        switch (dayOfWeek) {
            case 0:
                printf("***\n");
                break;
            case 1:
                printf("Monday\n");
                break;
            case 2:
                printf("Tuesday\n");
                break;
            case 3:
                printf("Wednesday\n");
                break;
            case 4:
                printf("Thursday\n");
                break;
            case 5:
                printf("Friday\n");
                break;
            case 6:
                printf("***\n");
                break;
        }

        // Increment the count of valid days if it's not Saturday or Sunday
        if (dayOfWeek != 0 && dayOfWeek != 6) {
            count++;
        }

        // Move to the next day
        sd.dd++;

        // Adjust the day, month, and year if needed
        if (sd.dd > 31 || (sd.dd > 30 && (sd.mm == 4 || sd.mm == 6 || sd.mm == 9 || sd.mm == 11)) || (sd.dd > 29 && sd.mm == 2) || (sd.dd > 28 && sd.mm == 2 && !(sd.yy % 4 == 0 && (sd.yy % 100 != 0 || sd.yy % 400 == 0)))) {
            sd.dd = 1; // Reset day to 1
            sd.mm++; // Move to the next month

            if (sd.mm > 12) {
                sd.mm = 1; // Reset month to January
                sd.yy++; // Move to the next year
            }
        }
    }

    // Print the count of days excluding Saturdays and Sundays
    printf("Count of days excluding Saturdays and Sundays: %d\n", count);

    // Close the file
    //fclose(file);
    return count;

}


Date next_date(Date *sd)
{
    int count = 0;
    // while (sd.dd != ed.dd || sd.mm != ed.mm || sd.yy != ed.yy) {
    //     // Calculate the day of the week
         int dayOfWeek = calculateDayOfWeek(sd->dd, sd->mm, sd->yy);

        //Print the date and day with an asterisk (*) if it's Saturday (6) or Sunday (0)
        //printf("%02d-%02d-%d: ", sd->dd, sd->mm, sd->yy);
        switch (dayOfWeek) {
            case 0:
                //printf("***\n");
                break;
            case 1:
                //printf("Monday\n");
                break;
            case 2:
                //printf("Tuesday\n");
                break;
            case 3:
                //printf("Wednesday\n");
                break;
            case 4:
                //printf("Thursday\n");
                break;
            case 5:
                //printf("Friday\n");
                sd->dd += 3;
                 if (sd->dd > 31 || (sd->dd > 30 && (sd->mm == 4 || sd->mm == 6 || sd->mm == 9 || sd->mm == 11)) || (sd->dd > 29 && sd->mm == 2) || (sd->dd > 28 && sd->mm == 2 && !(sd->yy % 4 == 0 && (sd->yy % 100 != 0 || sd->yy % 400 == 0)))) 
                {
                    sd->dd = 1; // Reset day to 1
                    sd->mm++; // Move to the next month

                    if (sd->mm > 12) {
                        sd->mm = 1; // Reset month to January
                        sd->yy++; // Move to the next year
                    }
                }
                    return *sd;
                break;
            case 6:
                //printf("***\n");
                break;
        }

        // // Increment the count of valid days if it's not Saturday or Sunday
        if (dayOfWeek != 0 && dayOfWeek != 6) {
            count++;
        }

        // Move to the next day
        sd->dd++;

        // Adjust the day, month, and year if needed
        if (sd->dd > 31 || (sd->dd > 30 && (sd->mm == 4 || sd->mm == 6 || sd->mm == 9 || sd->mm == 11)) || (sd->dd > 29 && sd->mm == 2) || (sd->dd > 28 && sd->mm == 2 && !(sd->yy % 4 == 0 && (sd->yy % 100 != 0 || sd->yy % 400 == 0)))) 
        {
            sd->dd = 1; // Reset day to 1
            sd->mm++; // Move to the next month

            if (sd->mm > 12) {
                sd->mm = 1; // Reset month to January
                sd->yy++; // Move to the next year
            }
        }
        return *sd;
}


//------------------------------------------------