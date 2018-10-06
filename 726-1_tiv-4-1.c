#include <stdlib.h>
#include <stdio.h>

typedef struct node {
	int value;
	struct node *next;
} node;

node *head=NULL;
node *tail=NULL;

int isEmpty()
{
	if ((head==NULL)&&(tail==NULL))
		return 1;
	else
		return 0;
}

void init(int value)
{
	node *t = malloc(sizeof(node));
	t->value = value;
	t->next = NULL;
	head = t;
	tail = t;
}

void add(int val)
{
	if (isEmpty() == 1)
		init(val);
	else
	{
		node *t = malloc(sizeof(node));
		t->value = val;
		t->next = NULL;
		tail->next = t;
		tail = t;
	}
}

void get_first()
{
	if (isEmpty() == 0)
	{
		node *t = head;
		printf("%i", t->value);
		printf("\a");
	}
	else
		printf("Пусто!\a");
}

void destroy()
{
	if (isEmpty() == 0)
	{
		node *t = head;
		node *temp = NULL;
		do {
			temp = t->next;
			free(t);
			t = temp;
		} while (t != NULL);
		head = NULL;
		tail = NULL;
	}
}

void get_full()
{ 
	if (isEmpty()==0)
	{
		node *t=head; 
 
		printf("%i",t->value); 
		while (t->next!=NULL) 
		{ 
			t=t->next; 
			printf(" ");
			printf("%i",t->value); 
		}
		printf("\a");
	}
	else
		printf("Пусто!\a");
} 

void remove_first()
{
	node *t = head;
	int no_op = 0;

	if (isEmpty() == 1)
	{
		no_op = 1;
		printf("Пусто!\a");
	}
	if (head == tail && no_op == 0)
	{
		destroy();
		no_op = 1;
	}

	if (no_op == 0)
	{
		head = t->next;
		free(t);
		no_op = 1;
	}
}




int main()
{
	int a=0;
	int val=0; 

	scanf("%i",&a); 
	
	for (int i=0;i<a;i++) 
	{ 
		scanf ("%i", &val); 
		add(val); 
	} 

	
	get_full();
		
	get_first();
	remove_first();
	
	get_full();
	
	add(6);
	
	get_full();
	
	destroy();
	return 0;
}
