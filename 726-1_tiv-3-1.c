#include <stdlib.h>
#include <stdio.h>

typedef struct node {
	int value;
	struct node *next;
	struct node *prev;
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

node *find_node_num(int k)
{

	node *tmp = head;
	
	for (int i=1;i<k;i++)
	{
		tmp=tmp->next;
		if (tmp==NULL)
			break;
	}

	return tmp;
}

node *find_node_val(int k)
{

	node *tmp = head;
	
	while (tmp != NULL && tmp->value != k)
	{
		tmp=tmp->next;
	}
	
	return tmp;
}

void init (int value)
{
	node *tmp = malloc(sizeof(node));
	tmp->value = value;
	tmp->next = NULL;
	tmp->prev = NULL;
	head = tmp;
	tail = tmp;
}

void add (int val)
{
	if (isEmpty()==1)
		init (val);
	else
	{
		node *tmp = malloc(sizeof(node)); 
		tmp->value=val; 
		tmp->prev=tail; 
		tmp->next=NULL; 
		tail=tmp; 
		tmp->prev->next=tmp; 
	}
}

void add_pend(int num, int data)
{
	node *tmp = find_node_num(num);
	if (tmp == NULL || tmp == head)
	{
		node *temp = malloc(sizeof(node));
		temp->value = data;
		temp->prev = NULL;
		temp->next = head;
		head = temp;
		temp->next->prev = temp;
	}
	else
	{
		node *temp = malloc(sizeof(node));
		temp->value = data;
		temp->prev = tmp->prev;
		temp->next = tmp;
		tmp->prev = temp;
		temp->prev->next = temp;
	}
}

void add_end(int num, int data)
{
	node *tmp = find_node_num(num);
	if (tmp==NULL||tmp==tail)
	{
		node *temp = malloc(sizeof(node));
		temp->value=data;
		temp->next=NULL;
		temp->prev=tail;
		temp->prev->next=temp;
		tail=temp;
	}
	else
	{
		node *temp = malloc(sizeof(node));
		temp->value=data;
		temp->next=tmp->next;
		temp->prev=tmp;
		tmp->next->prev=temp;
		tmp->next=temp;	
	}	
}

void destroy()
{
	if (isEmpty() == 0)
	{
		node *tmp = head;
		node *temp = NULL;
		do {
			temp = tmp->next;
			free(tmp);
			tmp = temp;
		} while (tmp != NULL);
		head = NULL;
		tail = NULL;
	}
}
 
void print() 
{ 
	node *tmp=head; 
 
	printf("%i",tmp->value); 
	while (tmp->next!=NULL) 
	{ 
		tmp=tmp->next; 
		printf(" ");
		printf("%i",tmp->value); 
	}
	printf("\n");
} 

void remove_node(node *tmp) 
{
	int no_op=0;
	
	if (tmp==NULL)
		no_op = 1;
	
	if (tmp==head && tmp==tail && no_op==0)
	{
		destroy();
		no_op=1;
	}
		
	if (tmp==head && no_op==0)
	{
		head=tmp->next;
		tmp->next->prev=NULL;
		free(tmp);
		no_op=1;
	}
	
	if(tmp==tail && no_op==0)
	{
		tail=tmp->prev;
		tmp->prev->next=NULL;
		free(tmp);
		no_op=1;
	}
	
	if (tmp!=head && tmp!=head && no_op==0)
	{
		tmp->next->prev=tmp->prev;
		tmp->prev->next=tmp->next;
		free(tmp);
		no_op=1;
	}

	
}

int main()
{
	int n=0;
	int val=0;
	int a=0; 

	scanf("%i",&n); 
	
	for (int i=0;i<n;i++) 
	{ 
		scanf ("%i", &val); 
		add(val); 
	} 

	if (isEmpty()==0)
		print();
		
	scanf("%i",&a);
	remove_node(find_node_num(a));

	if (isEmpty()==0)
		print();
	
	scanf("%i",&a);
	
	remove_node(find_node_val(a));
	
	if (isEmpty()==0)
		print();
		
	scanf ("%i",&a);
	scanf ("%i", &val);
	
	add_end(a,val);
	
	if (isEmpty()==0)
		print();
		
	scanf ("%i",&a);
	scanf ("%i", &val);
	
	add_pend(a,val);	
	
	if (isEmpty()==0)
		print();
		
	destroy();
	
	return 0; 
}

