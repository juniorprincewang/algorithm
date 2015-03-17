#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<queue>
using namespace std;
struct  path
{
	int pre;
	int r, c;
	int visit;
} path[65535];
struct node
{
	int state;
	int step;
};
void metrixs()
{
	int i, j, k;
	int state;
	for(i=0; i<=3; i++)
		for(j=0; j<=3; j++)
		{
			state = 0;			
			state ^= (1<<j)<<(i*4);
			for(k=0; k <= 3; k++)
				if( k != i)
					state ^= 1<<(j+ 4*k);
			for(k=0; k<=3; k++)
				if(k!= j)
					state ^= 1<<(4*i+k);
			printf("%d ", state);
		}
}
//metrixs结果
int result[16] ={
4383, 8751, 17487, 34959, 
4593, 8946, 17652, 35064,
7953, 12066, 20292, 36744, 
61713, 61986, 62532, 63624
};

int bfs(int s)
{
	queue<node> q;
	int i;
	struct node next, now;
	int state = s;
	
	now.state = state;
	now.step = 0;
	q.push(now);
	path[state].pre= -1;
	path[state].visit = 1;

	while(!q.empty())
	{
		now = q.front();
		q.pop();		
		for(i=0; i<16; i++)
		{
			state = now.state;
			state ^= result[i];
			if(path[state].visit)
				continue;			
			path[state].pre = now.state;
			path[state].r =4 -i /4;
			path[state].c = 4-i%4;
			if(state == 0)
			{
				return now.step +1;
			}
			
			path[state].visit = 1;
			next.state = state;
			next.step = now.step +1;
			q.push(next);
		}
	}
	return -1;
}
int main()
{
	//metrixs();
	char s[5][5];
	int state=0, stat=0;
	int i,j;
	int res;
	memset(path, 0, sizeof(path));
	for(i=0; i<4; i++)
	{
		scanf("%s",s[i]);
		for(j=0; j<4; j++)
		{
			//'+' means closed, '-' means open
			// '+' equals 1, '-' equals 0;
			if(s[i][j] == '+')
				state ^= 1<< ((3-i)*4+3-j);
		}
	}
	res = bfs(state);
	if(res != -1)
	{
		stat = 0;
		printf("%d\n",res);
		while(stat != state){
			printf("%d %d\n", path[stat].r, path[stat].c);
			stat = path[stat].pre;
		}

	}
	//printf("state = %d", state);
	system("pause");
	return 1;
}