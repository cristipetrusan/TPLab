//3. Se citesc de la tastatura tastatura &quot; N&quot; numere intregi.Sa
//se verifice folosind DOAR stive daca numerele respective
//sunt palindroame, iar numere care sunt palindroame vor fi
//introduce intr - o stiva.La sfarsit se va afisa continutul stivei
//respective.Cerinta de implementare : Se va implementa o
//singura metoda de &quot; Push&quot; / &quot; Pop&quot; / &quot; Peek&quot; , se va stii pe care
//stiva se lucreaza transmitand parametrii prin referinta.
//Petrusan George-Cristian 5.1 L5 - bonus
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define CAPACITY 50
#pragma warning(disable:4996)


int isFull(int top)
{
	if (CAPACITY - 1 == top)
		return 1;
	else return 0;
}
int isEmpty(int top)
{
	if (top == -1)
		return 1;
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
int pop(int *stack, int top)
{
	if (isEmpty(top))
	{
		printf("Stiva este goala!\n\n");
		return -1;
	}
	else return stack[top--];
}
void afisare(int stack[], int *top)
{
	printf("Stiva:\n");
	int i;
	for (i = 0; i <= *top; i++)
		printf("%d ", stack[i]);
	printf("\n");
}
int main()
{
	int n, i, x, c, aux, k, *st1, *st2, *top1, *top2;
	printf("Cate numere doriti sa cititi? ");
	scanf("%d", &n);
	st1 = (int*)malloc(CAPACITY * sizeof(int));
	st2 = (int*)malloc(CAPACITY * sizeof(int));

	top1 = (int*)malloc(sizeof(int));
	top2 = (int*)malloc(sizeof(int));
	*top1 = -1;
	*top2 = -1;

	for (i = 0; i < n; i++)
	{
		c = 1;
		scanf("%d", &x);
		aux = x;
		while (x)
		{
			push(st1, top1, x % 10);
			x /= 10;
		}
		for (k = 0; k <= *top1; k++)
			if (*(st1 + k) != *(st1 + *top1 - k))
				c = 0;
		if (c == 1)
			push(st2, top2, aux);
		*top1 = -1;
	}
	afisare(st2, top2);
	system("pause");
	return 0;
}