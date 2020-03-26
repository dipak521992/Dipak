#include <stdio.h>
int max_cost(int book[], int day , int beg, int end);
static int ic1=0,ic2=0;
int main() 
{
	int book[10];/* = {2,4,6,2,5};*/
	int beg = 0, end = 4, day = 1, num = 0 ,j=0;
	scanf("%d",&num);
	end = num - 1;
	for ( j = 0; j < num; j++)
         	scanf("%d", &book[j]);
	printf("%d \n", max_cost(book, day, beg, end));
	return 0;
}
int max_cost(int book[], int day , int beg, int end)
{
	int cost1 = 0, cost2 = 0, profit = 0;
	if (beg > end)
	return profit;
	else if (beg == end) 
	{
		profit += day * book[beg];
		return profit;
	}
	else 
	{
		printf("beg %d\n",++ic1);
		cost1 = day * book[beg] + max_cost(book, day + 1, beg + 1, end);
                printf("end %d\n",++ic2);
		cost2 = day * book[end] + max_cost(book, day + 1, beg, end - 1);
		profit += cost1 > cost2 ? cost1 : cost2;
		return profit;
	}
}

