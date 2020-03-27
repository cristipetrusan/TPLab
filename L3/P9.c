//9.Sa se inverseze doua numere naturale fara a se folosii de o variabila auxiliara, ci doar operatii bit wise.
//Petrusan George-Cristian 5.1 S3
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("a = %d\nb = %d\n", a, b);
	system("pause");
	return 0;
}