//5. Sa se introduca într - o stiva toate numerele naturale pâna la
//50. Din prima stiva se vor elimina numerele prime si se vor
//adauga într - o a doua stiva sub forma binara.
//A) Sa se adauge în stiva toate numerele naturale pâna la 50.
//B) Sa se scoata din prima stiva numerele prime.
//C) Transformarea numerelor prime în baza 2. (sub forma
//finala)
//D) Sa se populeze a doua stiva cu forma binara.
//!Atentie la refacerea primei stive
// Petrusan George - Cristian 5.1 L5 - bonus
#include <stdlib.h>
#include <stdio.h>
#define CAPACITY 50
#pragma warning(disable:4996)
int stack1[CAPACITY], stack2[CAPACITY], top1 = -1, top2 = -1;

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
int isFull1()
{
	if (CAPACITY - 1 == top1)
		return 1;
	else return 0;
}
int isEmpty1()
{
	if (top1 == -1)
		return 1;
	else return 0;
}
void push1(int x)
{
	if (isFull1())
	{
		printf("Stiva e plina!\n\n");
	}
	else
	{
		top1++;
		stack1[top1] = x;
	}
}
int pop1()
{
	if (isEmpty1())
	{
		printf("Stiva este goala!\n\n");
		return -1;
	}
	else return stack1[top1--];
}
int isFull2()
{
	if (CAPACITY - 1 == top2)
		return 1;
	else return 0;
}
int isEmpty2()
{
	if (top2 == -1)
		return 1;
	else return 0;
}
void push2(int x)
{
	if (isFull2())
	{
		printf("Stiva e plina!\n\n");
	}
	else
	{
		top2++;
		stack2[top2] = x;
	}
}
int pop2()
{
	if (isEmpty2())
	{
		printf("Stiva este goala!\n\n");
		return -1;
	}
	else return stack2[top2--];
}
int isPrim(int x)
{
	int i, d = 0;
	for (i = 2; i < x; i++)
		if (x % i == 0)
			d++;
	if (d == 0 && x != 1)
		return 1;
	else return 0;

}
void eliminareprime()
{
	int i, j;
	for (i = 0; i <= top1; i++)
	{
		if (isPrim(stack1[i]) == 1)
		{
			push2(formabinara(stack1[i]));
			for (j = i; j < top1; j++)
				stack1[j] = stack1[j + 1];
			--i;
			--top1;
		}
	}
}
void afisare1()
{
	printf("Stiva 1:\n");
	int i;
	for (i = 0; i <= top1; i++)
		printf("%d ", stack1[i]);
	printf("\n");
}
void afisare2()
{
	printf("Stiva 2:\n");
	int i;
	for (i = 0; i <= top2; i++)
		printf("%d ", stack2[i]);
	printf("\n");
}

int main()
{
	int i;
	for (i = 1; i <= 50; i++)
		push1(i);
	eliminareprime();
	afisare1();
	afisare2();
	system("pause");
	return 0;
}