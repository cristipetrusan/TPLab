//4. Sa se realizeze o implementare de stiva FARA a ne folosii
//variabile globale iar TOATE variabilele trebuiesc sa fie
//pointeri.Stiva este de numere intregi.Se va introduce in
//stiva 7 numere de tip intreg. - Sunt necesare toate metodele
//(de verificat plin / gol / peek / push / pop)
//Petrusan George-Cristian 5.1 L5 - bonus
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define CAPACITY 7
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
	int *st, *top;
	st = (int*)malloc(CAPACITY * sizeof(int));
	top = (int*)malloc(sizeof(int));
	*top = -1;
	push(st, top, 1);
	pop(st, top);
	push(st, top, 1);
	push(st, top, 2);
	push(st, top, 3);
	push(st, top, 4);
	push(st, top, 5);
	push(st, top, 6);
	push(st, top, 7);
	push(st, top, 8);
	printf("%d\n", peek(st, top));

	system("pause");
	return 0;
}