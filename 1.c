#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning (disable:4996)
main()
{
	double** p,**q,**t;
	int m,n,l, i, j,k;
	printf("please input n and m and l:");
	scanf("%d%d%d", &n,&m,&l);
	p = (double**)malloc(sizeof(double*) * n);
	for (i = 0; i < n; i++)
	{
		p[i] = (double*)malloc(sizeof(double) * m);	
		if (p[i] == NULL)
		{
			printf("Can't get memory!\n");
			exit(0);
		}
	}
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
		{
			printf("请输入第一个矩阵的第%d行%d个数：",i+1,j+1);
			scanf("%lf", &p[i][j]);
		}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			printf("%10.3f", p[i][j]);
		printf("\n");
	}
	printf("\n");
	q = (double**)malloc(sizeof(double*) * m);
	for (i = 0; i < m; i++)
	{
		q[i] = (double*)malloc(sizeof(double) * l);
		if (q[i] == NULL)
		{
			printf("Can't get memory!\n");
			exit(0);
		}
	}
	for (i = 0; i < m; i++)
		for (j = 0; j < l; j++)
		{
			printf("请输入第二个矩阵的第%d行%d个数：", i + 1, j + 1);
			scanf("%lf", &q[i][j]);
		}
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < l; j++)
			printf("%10.3f", q[i][j]);
		printf("\n");
	}
	printf("\n");
	t = (double **)malloc(sizeof(double*) * n);
	for (k = 0; k < n; k++)
		t[k] = (double*)malloc(sizeof(double)*l);
	for (i = 0; i < n; i++)
		for (j = 0; j < l; j++)
			t[i][j] = 0.0;
	for (i = 0; i < n; i++)
		for (j = 0; j < l; j++)
			for (k = 0; k < m; k++)
			{
				t[i][j] = t[i][j] + p[i][k] * q[k][j];
			}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < l; j++)
			printf("%10.3lf", t[i][j]);
		printf("\n");
	}
	for (k = n - 1; k >= 0; k--)
		free(p[k]);
	free(p);
	for (k = m - 1; k >= 0; k--)
		free(q[k]);
	free(q);
	for (k = l-1; k >= 0; k--)
		free(t[k]);
	free(t);
}