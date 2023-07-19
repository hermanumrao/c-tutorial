#include <stdio.h>
#include <stdlib.h>

typedef enum week { mon, tue, wed=0, thu, fri=7, sat, sun}week;

int main()
{	enum week day;
	day =wed;
	printf("%d", day);
	for (enum week i;i!=sun;i++)printf("%d ",i);
	printf("\n%d %d %d %d %d %d %d\n ",mon, tue, wed, thu, fri, sat, sun);
	printf("%ld %ld", sizeof(enum week), sizeof(day));
}
