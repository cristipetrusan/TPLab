//Petrusan George-Cristian 5.1
#include <stdlib.h>
#include <stdio.h>
#pragma warning(disable : 4996)
int manna(int x)
{
	if (x >= 12)
		return x - 1;
	else return manna(manna(x + 2));
}

int main()
{
	int x;
	printf("Functia manna pnueli\n Dati x:\n");
	scanf("%d", &x);
	printf("Rezultatul functiei manna pnueli: %d\n", manna(x));
	system("pause");
	return 0;
}
