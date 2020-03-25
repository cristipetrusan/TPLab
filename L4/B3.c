//3. Sa se realizeze un program care interschimba 2 valori folosind
//un pointer ca variabila auxiliara.
// Petrusan George-Cristian 5.1 L4 - tema 

#include <stdlib.h>
#include <stdio.h>
int main()
{
	int a, b, *aux;
	scanf("%d %d", &a, &b);
	aux = (int*)malloc(sizeof(int));
	*aux = a;
	a = b;
	b = *aux;
	printf("x = %d\ny = %d\n", a, b);
	system("pause");
	return 0;
}
