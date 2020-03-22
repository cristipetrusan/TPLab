// A B A&B A|B A^B
// 0 0  0   0   0
// 0 1  0   1   1
// 1 0  0   1   1
// 1 1  0   1   0

// 298 in baza 2        | se ia restul de jos in sus si se scrie numarul
// 298 / 2 = 149 r0     |
// 149 / 2 = 74 r1      ^ 
// 74 / 2 = 37 r0
// 37 / 2 = 18 r1
// 18 / 2 = 9 r0
// 9 / 2 = 4 r1
// 4 / 2 = 2 r0
// 2 / 2 = 1 r0
// 1 / 2 = 0 r1
// 100101010

//2. Fiind necesară setarea / verificarea permisiunilor pentru utilizatorii
//unei aplicații, și presupunând că informațiile legate de permisiune(per
//	utilizator) pot fi salvate doar într - o variabilă de dimeniunea unui octet
//	(limitări de memorie), să se implementeze funcții pentru setarea și
//	verificarea permisiunilor unui anumit utilizator.Există 5 tipuri de
//	permisiuni : Read / Write / Delete / Rename / Copy
 
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int  j, opt, i = 0, opt2;
	unsigned char v[10];
	for (j = 0; j < 10; j++)
		v[j] = 0;
	do {
		printf("0 - IESIRE\n");
		printf("1 - Introducere utilizator\n");
		printf("2 - Actualizare utilizator\n");
		printf("3 - Afisare utilizatori\n");
		printf("Alegeti optiunea: \n");
		scanf("%d", &opt);
		switch (opt)
		{
		case 0:
			exit(0);
			break;
		case 1:
			printf("Adaugati permisiuni pt utilizatorul %d:\n", i + 1);
			printf("Read: "); scanf("%d", &opt2); if (opt2 == 1) v[i] = v[i] + 16;
			printf("Write: "); scanf("%d", &opt2); if (opt2 == 1) v[i] = v[i] + 8;
			printf("Delete: "); scanf("%d", &opt2); if (opt2 == 1) v[i] = v[i] + 4;
			printf("Rename: "); scanf("%d", &opt2); if (opt2 == 1) v[i] = v[i] + 2;
			printf("Copy: "); scanf("%d", &opt2); if (opt2 == 1) v[i] = v[i] + 1;
			i++;
			break;
		case 2:
			printf("Dati numarul utilizatorul: "); scanf("%d", &j);

			break;
		case 3:
			for (j = 0; j < i; j++)
			{
				printf("Utilizatorul %d: \n", j + 1);
				printf("Read: "); if ((v[j] >> 4) % 2 == 1) printf("DA\n"); else printf("NU\n");
				printf("Write: "); if ((v[j] >> 3) % 2 == 1) printf("DA\n"); else printf("NU\n");
				printf("Delete: "); if ((v[j] >> 2) % 2 == 1) printf("DA\n"); else printf("NU\n");
				printf("Rename: "); if ((v[j] >> 1) % 2 == 1) printf("DA\n"); else printf("NU\n");
				printf("Copy: "); if ((v[j] >> 0) % 2 == 1) printf("DA\n"); else printf("NU\n");
			}
			break;
		default:
			break;
		}
	} while (1);

	system("pause");
	return 0;
}
