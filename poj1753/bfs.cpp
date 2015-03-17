#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
struct node{
	int state;
	int step;
} Node;
int visit[65535];
int dir[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

void metrix()
{
	int i, j, k;
	int state = 0;
	for(i=3; i>=0; i--)
		for(j=3; j>=0; j--)
		{
			state = 0;
			for(k=0; k< 4; k++)
			{
				if( j + dir[k][0]>=0 && j+dir[k][0] < 4 &&  i + dir[k][1]>=0 && i+dir[k][1]< 4)
				{
					state ^= (1<<(j+dir[k][0]))<<(i+dir[k][1])*4;
				}
			}
			state ^= (1<<j)<<i*4;
			printf("%d ", state);
		}			
}
int metrixs[16] =
{  
     51200,58368,29184,12544,  
     35968,20032,10016,4880,  
     2248,1252,626,305,  
     140,78,39,19  
};  
int bfs(int s)
{
	int state = s;
	int i;
	struct  node now, next;
	queue<node> q;
	now.state = state;
	now.step = 0;
	visit[state] = 1;
	q.push(now);
	while (!q.empty())
	{
		now = q.front();
		q.pop();
		for(i=0; i<16; i++)
		{
			state = now.state;
			state ^= metrixs[i];
			next.step = now.step + 1;
			next.state = state;
			if(visit[next.state] == 1)//不入队列
			{				
				continue;
			}				
			if(state == 0 || state == 65535)
			{
				return next.step;
			}
			q.push(next);
			visit[next.state] = 1;
		}			

	}
	return -1;
}
int main()
{
	int i, j, k;
	memset(visit, 0, 65535);
	int res;
	int state = 0;
	char c[5][5];
	for(i=0; i<=3; i++)		
	{
		scanf("%s", &c[i]);
		for(j=0; j<=3; j++)
			if(c[i][j] == 'w') 
				state ^= (1<<(3-j))<<(3-i)*4;
	}
	//metrix();
	//system("pause");
	//return 1;
	//printf("%d",state);
	if(state ==0 || state == 65535)
	{
		printf("0\n");
		return 1;
	}
	res = bfs(state);
	if(res == -1)
		printf("Impossible\n");
	else
		printf("%d\n", res);
	//system("pause");
	return 1;
}