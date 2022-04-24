#include<stdio.h>
#include<string.h>

typedef struct days_of_months
{
	unsigned int d;
}Months;

int monthDay[] = {31,28,31,30,31,30,31,31,30,31,30,31};

Months jan[31], feb[29], mar[31], apr[30], may[31], jun[30], jul[31], aug[31], sep[30], oct[31], nov[30], dec[31];

Months *months[12] = {jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};


void read_dates(Months **months, FILE *fp)
{
	int skip = 1;
	for(int i = 0; i < 12; i++)
	{

		for(int j = 0; j < monthDay[i]; j++)
		{
			if(monthDay[1] == 28 && i == 2 && j == 0 && skip)
			{
				int waste_date;
				//printf("Enter whether the 29th of Feb is a holiday or not -> ");
				fscanf(fp, "%d", &waste_date);
				j--;
				skip = 0;
			}
			else
			{
				fscanf(fp, "%d", &((*(months + i))[j].d));
			}
		}
	}
}

int isholiday(int date)
{
	return (date & 32);
}

int get_date(int date)
{
	return (date & 31) + 1;
}

int main()
{
	FILE *fp = fopen("holidays.txt", "r");
	read_dates(months, fp);		
	printf("Example date - %d and actual date %d and holiday value - %d", (*(months + 9))[3].d, get_date((*(months + 9))[3].d), isholiday((*(months + 9))[3].d));
	return 0;

}