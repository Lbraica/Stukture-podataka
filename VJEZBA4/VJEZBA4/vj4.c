﻿/*4. Napisati program za zbrajanje i množenje polinoma. Koeficijenti i eksponenti se
čitaju iz datoteke.
Napomena: Eksponenti u datoteci nisu nužno sortirani.*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define FILE_DIDNT_OPEN_ERROR (-1)
#define MAX_LINE (1024)
#define MAX_FILE_NAME (256)
#define MEMORY_NOT_ALLOCATED_CORRECT (-1)

struct _polynomial;
typedef struct _polynomial* position;

typedef struct _polynomial
{
	int coeff;
	int exp;
	position next;
}polynomial;

int readFromFile(position p1, position p2, char* filename);
position createNewPoly(int coeff, int exp);
int insertSort(position p, int coeff, int exp);
int insertAfter(position p, position q);
int printPolyList(position p);
int polyAdd(position add, poistion p1, position p2);
int deleteAfter(position p);
int polyMult(position mult, position p1, position p2);

int main(void)
{
	polynome p1 = { .coeff = 0,.exp = {0},.next = NULL };
	polynome p2 = { .coeff = 0,.exp = {0},.next = NULL };
	polynome resAdd = { .coeff = 0,.exp = {0},.next = NULL };
	polynome resMult = { .coeff = 0,.exp = {0},.next = NULL };

	char fileName[MAX_FILE_NAME] = { 0 };
	printf("Type in the file name:\n");
	scanf(" %s", &fileName);
	readFromFile(&p1,&p2,fileName);

	printf("Polynome 1:");
	printPolyList(p1.next);
	printf("Polynome 2:");
	printPolyList(p2.next);

	polyAdd(&resAdd, &p1, &p2);
	printf("Result of add function:");
	printPolyList(resAdd.next);

	polyMult(&resMult, &p1, &p2);
	printf("Result of multyply function:");
	printPolyList(resMult.next);

	printf("==================================\n");
	if (Delete(p1.next) == 0)
	{
		printf("Successful memory cleaning p1.");
		printf("\n");
	}
	if (Delete(p2.next) == 0)
	{
		printf("Successful memory cleaning p2.");
		printf("\n");
	}
	if (Delete(resAdd.next) == 0)
	{
		printf("Successful memory cleaning resAdd.");
		printf("\n");
	}
	if (Delete(resMult.next) == 0)
	{
		printf("Successful memory cleaning resMult.");
		printf("\n");
	}
	return EXIT_SUCCESS;
}

int readFromFile(position p1, position p2, char* fileName)
{
	FILE* fp = 0;
	fp = fopen(fileName, "r");

	if (fp == NULL)
	{
		printf("Dear customer, the file %s didn´t open! \r\n", fileName);
		return FILE_DIDNT_OPEN_ERROR;
	}

	char buffer[MAX_LINE] = { 0 };
	char* ptr = buffer;
	int coeff = 0;
	int exp = 0;
	int n = 0;
	int counter = 1;

	while (!feof(fp))
	{
		fgets(ptr, MAX_LINE, fp);
		while (strlen(ptr) > 0)
		{
			sscanf(ptr, "%d %d %n", &coeff, &exp, &n);
			if (counter == 1)
			{
				if (coeff != 0)
					insertSort(p1, coeff, exp);
			}
			else if (counter == 2)
			{
				if (coeff != 0)
					insertSort(p2, coeff, exp);
			}
			ptr += n;
		}
		counter++;
	}
	fclose(fp);
	return EXIT_SUCCESS;
}

position createNewPoly(int coeff, int exp)
{
	position new = NULL;
	new = (position)malloc(sizeof(polynomial));
	if (new == NULL)
	{
		printf("Memory not successfully allocated!\n");
		return MEMORY_NOT_ALLOCATED_CORRECT;
	}
	new->coeff = coeff;
	new->exp = exp;
	new->next = NULL;
	return new;
}

int insertSort(position p, int coeff, int exp)
{
	position new = NULL;
	new = createNewPoly(coeff, exp);
	if (new == NULL)
	{
		printf("Memory not successfully allocated!\n");
		return MEMORY_NOT_ALLOCATED_CORRECT;
	}
	if (p == NULL || exp < p->exp)
	{
		new->next = p;
		p = new;
	}
	else
	{
		position temp = p;
		while (temp->next != NULL && temp->next->exp == exp)
		{
			if (temp->next->coeff == 0)
			{
				deleteAfter(temp);
			}
			temp = temp->next;
		}
		if (temp->next != NULL && temp->next->exp == exp)
		{
			if (temp->next->coeff = -coeff)
				deleteAfter(temp);
			else
				temp->next->coeff += coeff;
		}
		else
		{
			insertAfter(temp, new);
		}
	}
	return EXIT_SUCCESS;
}

int insertAfter(position p, position q)
{
	q->next = p->next;
	p->next = q;
	return EXIT_SUCCESS;
}

int printPolyList(position p)
{
	if (p == NULL)
	{
		printf("No polynomials!");
		return FILE_DIDNT_OPEN_ERROR;
	}
	while (p != NULL)
	{
		printf("%dx^%d", p->coeff, p->exp);
		if (p->next != NULL)
		{
			if (p->next->koef >= 0)
				printf("+");
			else
				printf("");
		}
		p = p->next;
	}
	printf("\n");
	return EXIT_SUCCESS;
}

int polyAdd(position add, poistion p1, position p2)
{
	position pt1 = p1->next;
	position pt2 = p2->next;


	while (pt1 != NULL && pt2 != NULL) {

		if (pt1->eksp == pt2->eksp) {
			insertSort(add, pt1->koef + pt2->koef, pt1->eksp);
			pt1 = pt1->next;
			pt2 = pt2->next;
		}

		else if (pt1->eksp > pt2->eksp) {
			insertSort(add, pt1->koef, pt1->eksp);
			pt1 = pt1->next;
		}

		else if (pt1->eksp < pt2->eksp) {
			insertSort(add, pt2->koef, pt2->eksp);
			pt2 = pt2->next;
		}

	}
	while (pt1 != NULL) {
		insertSort(add, pt1->koef, pt1->eksp);
		pt1 = pt1->next;
	}
	while (pt2 != NULL) {
		insertSort(add, pt2->koef, pt2->eksp);
		pt2 = pt2->next;
	}



	return EXIT_SUCCESS;
}

int deleteAfter(position p)
{
	position toDel = NULL;
	toDel = p->next;
	p->next = p->next->next;
	free(toDel);
	return EXIT_SUCCESS;
}

int polyAdd(position add, position p1, position p2)
{
	position pt1 = p1->next;
	position pt2 = p2->next;

	while (pt1 != NULL && pt2 != NULL)
	{
		if (pt1->exp == pt2->exp)
		{
			insertSort(add, pt1->coeff + pt2->coeff, pt1->exp);
			pt1 = pt1->next;
			pt2 = pt2->next;
		}
		else if (pt1->exp > pt2->exp)
		{
			insertSort(add, pt1->coeff, pt1->exp);
			pt1 = pt1->next;
		}
		else if (pt1->exp < pt2->exp)
		{
			insertSort(add, pt2->coeff, pt2->exp);
			pt2 = pt2->next;
		}
	}
	while (pt1 != NULL)
	{
		insertSort(add, pt1->coeff, pt1->exp);
		pt1 = pt1->next;
	}
	while (pt2 != NULL)
	{
		insertSort(add, pt2->coeff, pt2->exp);
		pt2 = pt2->next;
	}
	return EXIT_SUCCESS;
}

int polyMult(position mult, position p1, position p2)
{
	position i = NULL;
	position j = NULL;
	int coefficient = 0;
	int exponent = 0;
	if (p1->next == NULL || p2->next == NULL)
		return EXIT_SUCCESS;
	for (i = p1->next; i != NULL; i = i->next)
	{
		for (j = p2->next; j != NULL; j = j->next)
		{
			coefficient = i->coeff * j->coeff;
			exponent = i->exp + j->exp;

			insertSort(mult, coefficient, exponent);
		}
	}
	return EXIT_SUCCESS;
}

int Delete(position p)
{
	position head = p;
	position temp;
	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
	return EXIT_SUCCESS;
}




