//6. Se citeste de la tastatura un numar zecimal pâna în 255. Sa
//se Înscrie într - o stiva reprezentarea sa binara.Sa se
//genereze pe stack cea mai mare valoarea posibila.
//A) Sa se implementeze citirea conditionata pâna la 255.
//B) Sa se realizeze transformarea din zecimal în binar.
//C) Adaugarea fiecarui bit într - o stiva
//D) Sa se genereze valoarea maxima posibila din valorile de
//pe stiva.
//27 - &gt; 0001 1011 (val binara) – Stack initial
//1111 0000 – Valoarea maxima
//5 - &gt; 0000 0101 (val binara) – Stack initial
//1100 0000 – Valoarea maxima
// Petrusan George - Cristian 5.1 L5 - prezenta
#include <stdlib.h>
#include <stdio.h>
#define CAPACITY 8
#pragma warning(disable:4996)
int stack[CAPACITY], top = -1;

int isFull()
{
	if (CAPACITY - 1 == top)
		return 1;
	else return 0;
}
int isEmpty()
{
	if (top == -1)
		return 1;
	else return 0;
}
void push(int x)
{
	if (isFull())
	{
		printf("Stiva e plina!\n\n");
	}
	else
	{
		top++;
		stack[top] = x;
	}
}
int pop()
{
	if (isEmpty())
	{
		printf("Stiva este goala!\n\n");
		return -1;
	}
	else return stack[top--];
}



int main()
{
	int x, i, c = 0, a=8;
	printf("Dati numarul: ");
	scanf("%d", &x);
	if (x <= 255 && x >= 0)
	{ 
		while (a)
		{
			push(x % 2);
			x = x / 2;
			a--;
		}
		//numarul in baza 2
		printf("Numarul in baza 2:\n");
		for (i = top; i >= 0; i--)
			printf("%d ", stack[i]);
		printf("\n");
		//valoare maxima
		for (i = top; i >= 0; i--)
			if (stack[i] == 1)
				c++;
		/*printf("Valoarea maxima:\n");
		x = c;
		for (i = 1; i <= 8; i++)
			if (x)
			{
				printf("1 ");
				x--;
			}
			else printf("0 ");
		printf("\n");*/
		while (isEmpty() != 1)
		{
			pop();
		}
		for (i = 0; i < 8; i++)
			if (i < 8 - c)
				push(0);
			else 
				push(1);
		printf("Valoarea maxima:\n");
		for (i = top; i >= 0; i--)
			printf("%d ", stack[i]);
		printf("\n");

	}
	else printf("Numar invalid!\n\n");
	
	system("pause");
	return 0;
}