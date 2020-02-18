#include <stdio.h>
int main()
{
	int b[11], n, i;
	while (~scanf("%d", &n))
	{
		i = 0;
		while(n)
		{
			b[i++] = n % 2;
			n /= 2;
		}
		i--;
		while(i >= 0)
			printf("%d", b[i--]);
		printf("\n");
	}
	return 0;
}
