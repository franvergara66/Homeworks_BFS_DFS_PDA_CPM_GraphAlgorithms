#include <stdio.h>

int main()
{
	freopen("tarea3.in","r",stdin);
	freopen("tarea3_separadores.in","w",stdout);
	int t, n, k, vi, vj, vc, cont = 0;
	scanf("%d",&t);
	printf("%d\n",t);
	while(t--)
	{
		scanf("%d %d",&n,&k);
		printf("\n // Caso #%d con N = %d y K = %d\n\n",++cont,n,k);
		printf("%d %d\n",n,k);
		while(k--)
		{
			scanf("%d %d %d",&vi,&vj,&vc);
			printf("%d %d %d\n",vi,vj,vc);
		}
	}
	return 0;
}
