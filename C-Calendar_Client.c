
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <Windows.h>
#include "C-Calendar_header.h"

Months jan[31], feb[29], mar[31], apr[30], may[31], jun[30], jul[31], aug[31], sep[30], oct[31], nov[30], dec[31];

Months *months[12] = {jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};

int main()
{
    int year;
    char ans[2];
    char ch;
    FILE *fp = fopen("holidays.txt", "r");
    do
    {
        menu(ans,fp,months);
        fflush(stdin);
        printf("\n");
        printf("\nEnter any key to continue or Q to quit\n");
        scanf("%c", &ch);
        ch = tolower(ch);
    }while(ch != 'q');

    printf("Thank you for using the C-Calendar!");
    return 0;
}