#include <stdlib.h>
#include <stdio.h>
int main()
{
	int i = 0, x, search, aux;
	unsigned char v[126];
	scanf("%d", &x);
	for (i = 0; i <= 125; i++)
		v[i] = 0;
	while (x != -1)
	{
		i = x / 8;
		v[i] = v[i] | (1 << (7 - x % 8));
		scanf("%d", &x);
	}
	for (i = 0; i <= 125; i++)
		printf("%d ", v[i]);
	printf("Dati numarul: ");
	scanf("%d", &search);
	
	aux = v[search / 8];
	
	if (aux & (1 << (7 - search % 8)))
	{
		printf("Nr %d exista!\n", search);
	}
	else printf("Nr %d NU exista!\n", search);
	system("pause");
	return 0;
}
