/*6.
Ispiši 20 random vrijednosti u opsegu od 0 do 30, ali da se vrijednosti ne ponavljaju
//
For (i=0; i<20; i++)
{
X=rand()%31;
If (Trazi(x, head.next)==NULL
UnosP(x, &head);
Else
i--;
}
Ako je rijeè o èitanju rijeèi, onda nije for petlja vec citanje iz datoteke
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct _brojevi;
typedef struct _brojevi brojevi;
typedef brojevi* position;

struct _brojevi {

	int broj;

	position next;
};
int GeneriranjeBroja(position head);
int SpremanjeBroja(position head, int broj);
int TraziBroj(position head, int broj);
int IspisBroja(position head);



int main()
{
	srand((unsigned int)(time));

	brojevi head;
	head.next = NULL;

	int result;
	result = GeneriranjeBroja(&head);
	if (result == -1)
	{
		printf("error");
		return -1;
	}
	result = IspisBroja(&head);

	return 0;
}

int GeneriranjeBroja(position head)
{
	int x;
	int i;
	for (i = 0; i < 21; i++)
	{
		x = (rand()) % 31;

		if (TraziBroj(head, x) == x)
		{
			SpremanjeBroja(head, x);
		}
		else
		{
			i--;
		}

	}

	return 0;
}

int SpremanjeBroja (position head, int broj)
{
	position temp;
	temp = (position)malloc(sizeof(brojevi));

	if (temp == NULL)
	{
		printf("nije se alociralo");
		return -1;
	}
	temp->broj = broj;

	while (head->next != NULL)
	{
		head = head->next;
	}

	temp->next = NULL;
	head->next = temp;

	return 0;
}



int TraziBroj(position head, int broj)
{
	position temp;
	temp = head;

	while (temp->next != NULL)
	{
		temp = head->next;
		if (broj == temp->broj)
		{
			broj = 0;
		}
		else
		{
			head = head->next;
		}
	}


	return broj;
}

int IspisBroja(position head)
{
	head = head->next;

	while (head != NULL)
	{
		printf("%d\n", head->broj);
		head = head->next;

	}


	return 0;
}