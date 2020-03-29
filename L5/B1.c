//1. Sa se scrie un program care citeste de la tastura &quot; N&quot;
//numere naturale.Pentru fiecare numar se va determina forma
//lui binara, se va calcula inversul binar, iar mai apoi se
//introduce intr - o stiva forma binara inversata.
//Ex:
//Input: 27
//	Forma binara : 0001 1011
//	Forma binara stiva output : 1110 0100
//Petrusan George-Cristian L5 - bonus
#include <stdlib.h>
#include <stdio.h>
#define CAPACITY 50
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
int formabinara(int x)
{
	int aux = 0, p = 1;
	while (x)
	{
		aux = p * (x % 2) + aux;
		p *= 10;
		x /= 2;
	}
	return aux;
}
int invers_binar(int x)
{
	int aux = 0, p = 1, i;
	for (i = 0; i <= 7; i++)
	{
		aux = aux + p * ((x + 1) % 2);
		p *= 10;
		x /= 10;
	}
	return aux;
}
void afisare()
{
	printf("Stiva:\n");
	int i;
	for (i = 0; i <= top; i++)
		printf("%d ", stack[i]);
	printf("\n");
}

int main()
{
	int n, x, i;
	printf("Cate numere doriti sa cititi? \n");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &x);
		x = invers_binar(formabinara(x));
		push(x);
	}
	afisare();
	system("pause");
	return 0;
}