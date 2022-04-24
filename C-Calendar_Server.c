#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "C-Calendar_header.h"
#include <windows.h>


int get_1st_weekday(int year)
{
  int d;
  d = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
  return d;
}

int isholiday(int date)
{
	return (date & 32);
}

int get_date(int date)
{
	return (date & 31) + 1;
}

void menu(char ans[20],FILE* fp, Months** months)
{
    int year,month,day,daysInMonth,weekDay=0,startingDay;    
    char *months_name[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    int monthDay_read[]={31,28,31,30,31,30,31,31,30,31,30,31};
    printf("---------------------------Welcome to the C-Calendar!---------------------------------------\n");
    printf("-------------------------------------Menu---------------------------------------------------\n");
    printf("                             Year-Wise Calendar(y)                                             \n");
    printf("                             Month-Wise Calendar(m)                                             \n");
    printf("                                     Timer(t)                                                   \n");
    printf("                                     Quit(q)                                                     \n");
    printf(">");
    scanf("%s", ans);
    fflush(stdin);
    if(!(strcmp(ans,"y")) || !(strcmp(ans,"Y")))
    {
        printf("\nEnter your desired year:");
        scanf("%d",&year);
        
        if(year>1584) 
        {
            if((year%4==0&&year%100!=0)||year%400==0)
                monthDay_read[1]=29;

            read_dates(months, fp, monthDay_read);	

            startingDay=get_1st_weekday(year);

            for(month=0;month<12;month++)
            {

                daysInMonth=monthDay_read[month];
                printf("\n\n---------------%s-------------------\n",months_name[month]);
                HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(h, FOREGROUND_GREEN);
                printf("\n  Sun  "); 
                HANDLE a = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(a, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
                printf("Mon  Tue  Wed  Thurs  Fri  Sat\n");

                for(weekDay=0;weekDay<startingDay;weekDay++)
                    printf("     ");

                for(day=0;day<daysInMonth;day++)
                {
                    if(isholiday((*(months + month))[day].d))       //  Case for holiday
                    {
                        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(h,FOREGROUND_RED);
                        printf("%5d",get_date((*(months + month))[day].d));
                    }
                    else if(weekDay == 0)
                    {
                        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);     // Case for Sunday
                        SetConsoleTextAttribute(h, FOREGROUND_GREEN);
                        printf("%5d",get_date((*(months + month))[day].d));
                    }
                    
                    
                    else        // Case for any other day
                    {
                        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
                        printf("%5d",get_date((*(months + month))[day].d));
                    }

                    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);


                    if(++weekDay>6)
                    {
                        printf("\n");
                        weekDay=0;
                    }
                    startingDay=weekDay;
                }
            }
        }
        else
        {
            printf("The year you have inputed is before the implementation of the Gregorian Calendar.\n");
            printf("\n");
            menu(ans,fp,months);
        }
    }
    if(!(strcmp(ans,"m")) || !(strcmp(ans,"M")))
    {
        int month1;
        printf("\nEnter your desired year:");
        scanf("%d",&year);

        if((year%4==0&&year%100!=0)||year%400==0)
            monthDay_read[1]=29;
        
        read_dates(months, fp, monthDay_read);

        startingDay=get_1st_weekday(year);

        printf("\nEnter the desired month's index: ");
        scanf("%d", &month1);
       
        if(month1 <= 12 && month1 >= 1)
        {
            month1--;
            for(month=0;month<12;month++){

                daysInMonth=monthDay_read[month];
                if(month == month1)
                {
                    printf("\n\n---------------%s-------------------\n",months_name[month]);
                    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(h, FOREGROUND_GREEN);
                    printf("\n  Sun  ");
                    HANDLE a = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(a, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
                    printf("Mon  Tue  Wed  Thurs  Fri  Sat\n");
                }
                for(weekDay=0;weekDay<startingDay;weekDay++)
                    if(month == month1)
                        printf("     ");

                for(day=0;day<daysInMonth;day++){
                    if(month == month1)
                        if(isholiday((*(months + month))[day].d))
                        {
                            HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                            SetConsoleTextAttribute(h,FOREGROUND_RED);
                            printf("%5d",get_date((*(months + month))[day].d));
                        }
                        else if(weekDay == 0)
                        {
                            HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                            SetConsoleTextAttribute(h, FOREGROUND_GREEN);
                            printf("%5d",get_date((*(months + month))[day].d));
                        }
                        else
                        {
                            HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                            SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
                            printf("%5d",get_date((*(months + month))[day].d));
                        }

                        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
                    
                    if(++weekDay>6){
                        if(month == month1)
                            printf("\n");
                            weekDay=0;
                    }
                    startingDay=weekDay;
                }

            }
        }
        else
        {
            printf("Invalid month. Please try again!\n");
            printf("\n");
        }
    }
    if((!(strcmp(ans,"t"))) || (!(strcmp(ans,"T"))))
    {
        time_t t1 = time(NULL);
        printf("Please press a key to stop the timer.");
	    getch();
	    time_t t2 = time(NULL);
        int hour = (t2-t1)/3600;
        int minutes = ((t2-t1)%3600)/60;
        int seconds = ((t2-t1)%60);
        printf("\nTime Elapsed:   %02d:%02d:%02d", hour, minutes, seconds);
    }
    if(!(strcmp(ans,"q")) || !(strcmp(ans,"Q")))
    {
        printf("Thank you for using the C-Calendar!");
        exit(0);
    }
}

void read_dates(Months **months, FILE *fp, int *monthDay_read)
{
    int skip = 1;
    if(monthDay_read[1] == 29)
    {
        (*(months + 1))[28].d = 92;
    }
	for(int i = 0; i < 12; i++)
	{

		for(int j = 0; j < monthDay_read[i]; j++)
		{
			if(monthDay_read[1] == 28 && i == 2 && j == 0 && skip)
			{
				int waste_date;
				fscanf(fp, "%d", &waste_date);
				j--;
                skip = 0;
			}
			else
			{
                //if(i == 1 && j == 28)
                {
                  //  (*(months + i))[j].d = 92;
                }
               // elseA
                {
				    fscanf(fp, "%d", &((*(months + i))[j].d));
                }
			}
		}
	}
}