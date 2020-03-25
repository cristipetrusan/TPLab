#include <stdlib.h>
#include <stdio.h>
//5. Sa se realizeze un program care sa prezinte diferenta dintre
//urmatoarele, incrementarea / decrementarea valorii pointerului,
//precum si incrementarea / decrementarea pointerului care ia
//adresa index - ului “0” a unui vector oarecare.
//Petrusan George-Cristian L4 - prezenta
int main()
{
	int v[10], *x;
	v[0] = 0;
	v[1] = 12354;
	printf("v[0] = 0\nv[1] = 12354\nx = &v[0]\n");
	x = &v[0];
	printf("Valoarea pointerului x este %d\n", *x);
	x = &v[0];
	printf("Valoarea incrementata pointerului x este %d\n", (*x) + 1);
	x = &v[0];
	printf("Valoarea decrementata pointerului x este %d\n", (*x) - 1);
	x = &v[0];
	printf("Valoarea pointerului ++x este %d\n", *(++x));
	x = &v[0];
	printf("Valoarea pointerului --x este %d\n", *(--x));
	x = &v[0];
	system("pause");
	return 0;
}
