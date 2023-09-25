/*Q1. Write a menu driven program for Date in a C. Declare a structure Date having data members
day, month, year. Implement the following functions.
void initDate(struct Date* ptrDate);
void printDateOnConsole(struct Date* ptrDate);
void acceptDateFromConsole(struct Date* ptrDate);*/

#include <stdio.h>

struct Date
{
    int day;
    int month;
    int year;
};

void initDate(struct Date *ptrd)
{
    ptrd->day = 01;
    ptrd->month = 01;
    ptrd->year = 1900;
}

void printDateOnConsole(struct Date *ptrd)
{
    printf("DATE = %d / %d / %d  \n", ptrd->day, ptrd->month, ptrd->year);
}

void acceptDateFromConsole(struct Date *ptrd)
{
    printf("Enter DATE : ");
    scanf("%d", &ptrd->day);

    printf("Enter MONTH : ");
    scanf("%d", &ptrd->month);

    printf("Enter YEAR : ");
    scanf("%d", &ptrd->year);
}

int main()
{
    int opt;

    struct Date d;

    do
    {
        printf("************************************************************ \n");
        printf("1. Initial Date \n 2.Enter Date \n 3.Print Date \n 0.Exit \n");
        printf("************************************************************");

        printf("\n Enter Option : ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:

            initDate(&d);

            break;

        case 2:

            acceptDateFromConsole(&d);

            break;

        case 3:

            printDateOnConsole(&d);

            break;

        default:

            printf("Invalid Input /n");
            break;
        };
    } while (opt != 0);

    return 0;
}