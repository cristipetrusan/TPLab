//3. Sa se realizeze un program care interschimba 2 valori folosind
//un pointer ca variabila auxiliara.
// Petrusan George-Cristian 5.1 L4 - tema 

#include <stdlib.h>
#include <stdio.h>
int main()
{
	int a, b, *x, *y, aux;
	scanf("%d %d", &a, &b);
	
	x = &a;
	y = &b;

	aux = *x;
	*x = *y;
	*y = aux;

	printf("x = %d\ny = %d\n", a, b);
	system("pause");
	return 0;
}