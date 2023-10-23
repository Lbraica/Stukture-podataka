#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

struct osoba
{
	char ime[15];
	char prezime[15];
	int god_rod;
};

int unos_na_poc();
int unos_na_kraj();


int main()
{
	int n=0;
	char izbor=0;
	int br;
	struct osoba *lista;
	do
	{
		printf("Koliko ce clanova imati niz osoba?\n");
		scanf("%d", &n);
	} while (n != 0);
	lista = (struct osoba*)malloc(n * sizeof(struct osoba));
	while (izbor != 'k' && izbor != 'K')
	{
		printf("Koju izmjenu zelite napraviti?\n");
		printf("Unos elementa na pocetak niza- 1\nIspis liste - 2\n");
		printf("Unos elementa na kraj niza- 3\nPronalazak elementa po prezimenu - 4\nBrisanje odredenog elementa iz liste - 5\n");
		printf("Kraj rada - k\n");
		scanf(" %c", &izbor);

		switch (izbor)
		{
		case '1':
			br = unos_na_poc(n, lista);
			break;
		case '2':
			br = ispis(n, lista);
			break;
		case '3':
			br = unos_na_kraj(n, lista);
			break;
		case '4':
			br = nadi_el(n, lista);
			break;
		case '5':
			br = brisi_el(n, lista);
			break;
		case 'k':
		case 'K':
			printf("Kraj programa.\n");
			break;
		default:
			printf("Krivi unos!\n");
		}
	}
	


}


