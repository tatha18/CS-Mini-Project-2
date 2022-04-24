#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <Windows.h>

typedef struct days_of_months
{
	unsigned int d;
}Months;

void menu(char [], FILE*, Months**);

int get_1st_weekday(int year);

int isholiday(int date);

int get_date(int date);

void read_dates(Months **months, FILE *fp, int *monthDay_read);
