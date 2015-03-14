/*
#include <stdio.h>
#include <cmath>
#include <stdlib.h>
using namespace std;
int main()
{
	double n, p;
	while(scanf("%lf%lf", &n, &p)!=EOF)
	{
		double t= pow(p, 1/n);
		printf("%.0lf\n", t);
	}
	//system("pause");
	return 1;
}
*/

#include <stdio.h>
#include <cmath>
#include <stdlib.h>
using namespace std;
int main()
{
	double n, p;
	long long mid, left, right;
	while(scanf("%lf%lf", &n, &p)!=EOF)
	{
		left = 0;
		right = pow(10, 9)+1;
		
		while(1)
		{
			mid = (left + right) / 2;
			if(pow(mid, n) > p)
				right = mid;
			else if(pow(mid, n) < p)
				left = mid;
			else break;
		}
		printf("%.0lld\n", mid);
	}
	return 1;
}