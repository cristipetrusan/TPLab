//7. Sa se scrie un program care verifica daca un numar citit de
//la tastatura pâna în valoarea de 65535 este palindrom atât în
//baza 2 cât si în baza 10. Verificarea ca numarul ar fi
//palindrom sa se implementeze cu ajutorul unui stack.
//A) Sa se implementeze citirea conditionata pâna la 65535.
//B) Sa se realizeze transformarea din zecimal în binar.
//C) Adaugarea fiecarui bit într - un stack
//D) Adaugarea fiecarei cifre într - un alt stack.
//E) Verificarea ca cele doua variante sunt palindrom sau nu.
//585 = 1001 0 0 1001 (binary)– PALINDROM
//Palindrom – O secventa de caractere care se citeste exact la
//fel indiferent de directia de citire(stânga dreapta sau dreapta
//	– stânga)
//Petrusan George-Cristian 5.1 L5 - bonus
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define CAPACITY 64
#pragma warning(disable:4996)

int isFull(int top)
{
	if (CAPACITY - 1 == top)
	{
		return 1;
	}
	else return 0;
}
int isEmpty(int top)
{
	if (-1 == top)
	{
		return 1;
	}
	else return 0;
}
void push(int *stack, int *top, int d)
{
	if (isFull(*top))
	{
		printf("Stiva e plina!\n\n");
	}
	else
	{
		(*top)++;
		*(stack + *top) = d;
	}
}
void pop(int *stack, int *top)
{
	(*top)--;
}
int peek(int *stack, int *top)
{
	return *(stack + *top);
}
int main()
{
	int x, aux, *st1, *st2, *top1, *top2, c1, c2;
	st1 = (int*)malloc(CAPACITY * sizeof(int));
	st2 = (int*)malloc(CAPACITY * sizeof(int));
	top1 = (int*)malloc(sizeof(int));
	top2 = (int*)malloc(sizeof(int));
	*top1 = -1;
	*top2 = -1;
	printf("Dati numarul: ");
	scanf("%d", &x);
	aux = x;
	if (x >= 0 && x <= 65535)
	{
		while (x)
		{
			push(st1, top1, x % 2);
			x /= 2;
		}
		while (aux)
		{
			push(st2, top2, aux % 10);
			aux /= 10;
		}
		c1 = c2 = 1;
		for (x = 0; x <= *top1; x++)
			if (*(st1 + x) != *(st1 + *top1 - x))
				c1 = 0;
		for (x = 0; x <= *top2; x++)
			if (*(st2 + x) != *(st2 + *top2 - x))
				c2 = 0;
		for (x = 0; x <= *top1; x++)
			printf("%d", *(st1 + x));
		printf("\n");
		for (x = 0; x <= *top2; x++)
			printf("%d", *(st2 + x));
		printf("\n");

		if (c1 == 1 && c2 == 1)
			printf("ESTE PALINDROM!\n");
		else printf("NU ESTE PALINDROM!\n");
	}
	else printf("NUMARUL NU ESTE IN PARAMETRII CERUTI! \n");


	system("pause");
	return 0;
}