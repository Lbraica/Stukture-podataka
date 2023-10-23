#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_BR_BOD 50


typedef struct
{
	char ime_prezime[80];
	int br_bod;
	float rel_br_bod;
}_student;

int main()
{
	int i,br = 0;
	char tmp[80];
	_student* stud;
	FILE* ulaz;

	ulaz = fopen("studenti.txt", "r");
	if (ulaz == NULL)
	{
		puts("Greska pri otvaranju datoteke!");
		exit(1);
	}
	while (!feof(ulaz))
		if (fgetc(ulaz) == '\n') ++br;
	stud = (_student*)malloc(br * sizeof(_student));
	rewind(ulaz);
	for (i = 0; i < 1; i++)
		while (fgetc(ulaz) != '\n'); //preskakanje prvog reda
	printf("Ime i prezime studenta, broj i relativni broj bodova:\n");
	for (i = 0; i < br; i++)
	{
		fscanf(ulaz,"%s %s %d", stud[i].ime_prezime, tmp, &stud[i].br_bod);
		strcat(stud[i].ime_prezime, " "); //dodavanje razmaka
		strcat(stud[i].ime_prezime, tmp); //dodavanje prezimena
		stud[i].rel_br_bod = (float)stud[i].br_bod / (float)MAX_BR_BOD* 100;
		printf("%s %d %.2f %% \n",stud[i].ime_prezime,stud[i].br_bod,stud[i].rel_br_bod);
	}
	fclose(ulaz);
	return 0;
}