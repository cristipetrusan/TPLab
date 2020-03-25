//Petrusan George-Cristian 5.1
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#pragma warning(disable: 4996)
int  i1 = 0, i2 = 0, i3 = 0;
char fp[100], st[100], aux[100];
void pushfp(char a)
{
	fp[i1] = a;
	i1++;
}
void popfp() {
	fp[i1 - 1] = 0;
	i1--;
}
void pushst(char x)
{
	st[i2] = x;
	i2++;
}
char checkst()
{
	return st[i2 - 1];
}
char popst() {
	char x = st[i2 - 1];
	i2--;
	return x;
}
void pushaux(char x)
{
	aux[i3] = x;
	i3++;
}
char popaux() {
	char x = aux[i3 - 1];
	i3--;
	return x;
}
int prioritate(char x)
{
	if (x == '(' || x == ')')
		return 0;
	else if (x == '*' || x == '/')
		return 1;
	else if (x == '+'|| x == '-')
		return 2;
	else return -1;
}

void formapoloneza(char sir[])
{
	int k = 0, lung = strlen(sir);
	char x, op, ultimst;
	pushst(sir[0]);
	for (k = 1; k < lung; k++)
	{
		op = sir[k];
		if (prioritate(op) == -1)
		{
			pushfp(op);
		}
		else {
			pushst(op);
			if (checkst() == ')')
			{
				x = popst();
				while (checkst() != '(')
				{
					x = popst();
					if (x != ')')
						pushfp(x);
				}
				x = popst();
			}
			else {
				if (prioritate(checkst()) == 2)
				{
					while (checkst() != '(')
					{
						x = popst();
						if (prioritate(x) == 1)
							pushfp(x);
						else pushaux(x);
					}
					while (i3 != 0)
					{
						x = popaux();
						pushst(x);
					}
				}
			}
			
		}
	}
	for (k = 0; k < lung; k++)
	{
		if (fp[k] == '+')
			printf("+");
		else if (fp[k] == '-')
			printf("-");
		else if (fp[k] == '*')
			printf("*");
		else if (fp[k] == '/')
			printf("/");
		else
		printf("%c", fp[k]);
	}
	printf("\n");
	for (k = 0; k < lung; k++)
	{
			printf("%c", st[k]);
	}
	printf("\n");
}
void afisare(char sir[])
{
	printf("%s\n", sir);
}

int main()
{
	char sir[100], x;
	printf("Dati expresia: ");
	scanf("%s", sir);
	afisare(sir);
	printf("Forma poloneza: "); formapoloneza(sir);
	printf("\n");
	system("pause");
	return 0;
}