#include <stdlib.h>
#include <stdio.h> 
#include <time.h>

int month; 
int year; 
int day; 
int realDay; 
int dayNumber; 
int flag; 

int fineDay (int month, int year) {
	int day;
	int a, b, c;
	a=(14-month)/12;
	b=year-a;
	c=month+12*a-2;
	day=(7000+(1+b+(b/4)-(b/100)+(b/400)+(31*c)/12))%7;
	day++;
	return day;
}

int dayNmbrSearching (int month, int year) {
		int visYear=0;
		int dayNmbr;
		if (year%4==0) {
			visYear=1;
			if (year%100==0) {
				visYear=0;
			} 
			if (year%400==0) {
				visYear=1;
			}
		}

		switch (month) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12: dayNmbr=31; break;
		case 2:  if (visYear) dayNmbr=29; else dayNmbr=28; break;
		case 4: case 6: case 9: case 11: dayNmbr=30;
		}
		return dayNmbr;
}

void print (int day, int dayNmbr, int realDay, int flag) {

	int i=1;
	int sunday=1;
	
	printf ("Su\tMo\tTu\tWe\tTh\tFr\tSa\n");
	
	while (day!=i) {
		printf ("\t");
		sunday++;
		i++;
	}

	if (sunday%7==0) {
		if (flag==1 && realDay==1) {
			printf ("[1]\n");
		} else {
			printf ("1\n");
		}
	} else {
		printf ("1\t");
	}
	sunday++;
	
	for (i=2; i<=dayNmbr;i++) {
		if (sunday%7==0) {
			if (flag==1 && realDay==i) {
				printf ("[%d]\n",i);
			} else {
				printf ("%d\n",i);
			}
		} else {
			if (flag==1 && realDay==i) {
				printf ("[%d]\t",i);
			} else {
				printf ("%d\t",i);
			}
		}
		sunday++;
	}
	
	printf ("\n");

}
/*
Grigorian calendar
*/

int main () {

	struct tm *tim;
	time_t tt = time(NULL);
	tim = localtime(&tt);
	realDay=tim->tm_mday;

	scanf("%d.%d", &month, &year);

	if ( tim->tm_mon+1==month && tim->tm_year+1900==year ) {
		flag=1;
	}

	day=fineDay(month, year);
	dayNumber=dayNmbrSearching(month, year);

	print(day, dayNumber, realDay, flag);
	
//	system("pause"); //for Windows
	return 0;

}
