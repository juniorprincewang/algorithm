#include<stdio.h>
using namespace std;
int judge(int s, int d)
{
	if (4*s < d)
		return 10*s-2*d;
	else if(3*s <2*d)
		return 8*s-4*d;
	else if(2*s < 3*d)
		return 6*s - 6*d;
	else if(s <4*d)
		return 3*s - 9*d;
	else return -1;
}
int main()
{
	int s, d;
	int r;
	while(scanf("%d%d", &s, &d)!=EOF)
	{
		r = judge(s, d);
		if(r> 0)
			printf("%d\n", r);
		else
			printf("Deficit\n");
	}
	return 1;
}