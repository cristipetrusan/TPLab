//2. Se citeste de la tastatura un numar C cu valori posibile
//intre 0 - 7. Dupa citirea numarului &quot; C&quot; se vor citi de la tastatura
//&quot; N&quot; numere iar acele numere care au reprezentarea lor
//binara, bitul de pe pozitia &quot; C&quot; cu valoare 1, vor fi introduse
//intr - o stiva.Sa se afiseze in final tot continutul stivei
//(indiferent de ordine)
//Ex:
//C = 2
//N = 5
//- Acum se citesc 5 numere :
//	1 2 3 4 5
//	- Se afiseaza la sfarsit
//	4 5
//	Deoarece 4 = 100 si 5 = 101, bitul de pe pozitia &quot; 2 & quot; este &quot; 1 & quot;
//Petrusan George-Cristian 5.1 L5 - bonus
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
	int c, i, n, x, aux;
	printf("Dati pozitia bitului: ");
	scanf("%d", &c);
	printf("Cate numere doriti sa cititi? ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &x);
		aux = formabinara(x);
		if ((int) (aux / pow(10, c)) % 2 == 1)
			push(x);
	}
	afisare();
	system("pause");
	return 0;
}