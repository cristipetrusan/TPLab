#include <stdio.h>
#include <stdlib.h>

void cautare_liniara(int v[], int n, int nr)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (v[i] == nr)
			printf("Al %d-lea numar e %d\n", i + 1, v[i]);
	}

}
void ordonare(int v[], int n)
{
	int ok, i;
	do {
		ok = 0;
		for (i = 0; i < n; i++)
			if (v[i] > v[i + 1])
			{
				int aux = v[i];
				v[i] = v[i + 1];
				v[i + 1] = aux;
				ok = 1;
			}

	} while (ok);
}
void cautare_binara(int v[], int n, int nr)
{
	int left = 0, right = n - 1, middle = (left + right) / 2, ok = 0;
	while (left <= right)
	{
		if (v[middle] < nr)
		{
			if (left == middle)
			{
				left++; 
				middle = left;
			}
			else left = middle;
		}
		else if (v[middle] > nr)
			if (right == middle)
			{
				right--;
				middle = right;
			}
			else right = middle;
		if (v[middle] == nr)
		{
			ok = 1;
			break;
		}
	
		middle = (left + right) / 2;
	}
	if (ok == 0)
		printf("Nope!\n");
	else printf("Yep!\n");
	
}

int main()
{
	int i, nr, n, v[100];
	printf("n="); scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &v[i]);
	printf("Numarul cautat: ");
	scanf("%d", &nr);
	ordonare(v, n);
	//cautare_liniara(v, n, nr);
	cautare_binara(v, n, nr);
	system("pause");
	return 0;
}