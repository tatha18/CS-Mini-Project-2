#include<stdio.h>
#include<string.h>

typedef struct days_of_months
{
	unsigned int d : 10;
}Months;

int monthDay[] = {31,29,31,30,31,30,31,31,30,31,30,31};


Months jan[32] = {{.d = 0}}, feb[29] = {{.d = 1}}, mar[32] = {{.d = 2}}, apr[31] = {{.d = 3}}, may[32] = {{.d = 4}}, jun[31] = {{.d = 5}}, jul[32] = {{.d = 6}}, aug[32] = {{.d = 7}}, sep[31] = {{.d = 8}}, oct[32] = {{.d = 9}}, nov[31] = {{.d = 10}}, dec[32] = {{.d = 11}};

Months *months[12] = {jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};

int add_dates(Months **months, FILE *fp)
{
	int holiday;
	

	for (int i = 0; i < 12; i++)
	{
		printf("\n\n\nMonth %d\n", i + 1);

		int m_num = (*(months + i))[0].d;

		for(int j = 1; j <= monthDay[m_num]; j++)
		{
			int date = j - 1;
			printf("Is it a holiday on date %d? Enter - ", j);
			scanf("%d", &holiday);

			(*(months + i))[j].d = (((m_num << 1) + holiday) << 5) + date;	

			fprintf(fp, "%d ", (*(months + i))[j].d);

		}
	}
}



int main()
{
	FILE *fp = fopen("holidays.txt", "a+");
	if(fp == (FILE *) NULL)
	{
		printf("Can't open file...");
		return 0;
	}

	add_dates(months, fp);
	return 0;
}
