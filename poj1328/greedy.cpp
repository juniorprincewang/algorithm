#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;  
struct corrd
{
	int x;
	int y;
} Corrd[1050];

struct interval
{
	double left;
	double right;
} Interval[1050];

void printResult(int c, int num)
{
	printf("Case %d: %d\n", c, num);
}
int cmp(interval a, interval b)
{
	return a.left < b.left;
}
int main()
{
	int n, d;
	int i, j;
	int stop=0;
	int caseth=0;
	double len=0;
	double mini;
	int number;
	while(scanf("%d %d", &n, &d) && n && d)
	{
		caseth++;
		stop = 0;
		for(i=0; i< n; i++)
		{
			scanf("%d %d", &Corrd[i].x, &Corrd[i].y);
			if(Corrd[i].y > d)
				stop=1;
		}
		if(stop)
		{
			printResult(caseth, -1);
			continue;
		}
		for(i=0; i<n; i++)
		{
			len = sqrt(d*d - Corrd[i].y*Corrd[i].y);
			Interval[i].left =(double) Corrd[i].x - len;
			Interval[i].right = (double)Corrd[i].x + len;
		}
		sort(Interval, Interval + n, cmp);
		mini = -0xffffff;
		number = 0;
		for(i=0; i< n; i++)
		{
			if( mini < Interval[i].left)
			{
				mini = Interval[i].right;
				number++;
			}
			else if(mini > Interval[i].right)
			{
				mini = Interval[i].right;				
			}
		}
		printResult(caseth, number);
	}
	//system("pause");
	return 1;
}
