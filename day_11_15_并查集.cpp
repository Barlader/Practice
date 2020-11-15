#include <stdio.h>

int f[1000]={0],n,m,k,sum=0;

void init(void)
{
	int i;
	for (i=1;i<=n;i++)
	{
		f[i] = i;
	}
}

int getAncestor(int v)
{
	if (f[v] == v)
	{
		return v;
	}
	else
	{
		f[v] = getAncestor(v);
		return f[v];
	}
}

void merge(int v, int u)
{
	int t1, t2;
	t1 = getAncestor(v);
	t2 = getAncestor(u);
	if (t1 != t2)
	{
		//靠左原则，v和u是同伙，但是它们的祖先节点是不一致的，
		//所以应该将右边的右边的节点的祖先节点归顺给左边的节点。
		f[t2] = t1;
	}
}

int main(void)
{
	int i, x,y;
	//有多少个强盗，有多少条线索
	scanf("%d %d", &n, &m);
	
	init();
	for (i = 1;i <= m;i++)
	{
		scanf("%d %d", &x, &y);
		merge(x,y);
	}
	
	for (i=1; i<=n; i++)
	{
		if (f[i] == i)
		{
			if (f[i] == i)
			{
				sum++;
			}
		}
	}
	//扫描有多少个犯罪团伙
	for (i=0; i<= n; i++)
	{
		if (f[i] == i)
		{
			sum++;
		}
	}
}

/**
1 2 3 4 5 6 7 8 9 10
2->1 4->3
1 1 3 3 5 6 7 8 9 10
2->5 ? 
找到2的祖先是1，
1,2-> 5
5 5 3 3 5 6 7 8 9 10
4号强盗与6号强盗是同伙
5 5 5 3 5 3 
2号强盗与6号强盗是同伙
5 5 
8号强盗与7号强盗是同伙
5 5 5 3 5 3 8 8 9 10
9号与7号是同伙
5 5 5 3 5 3 8 9 9 10
**/