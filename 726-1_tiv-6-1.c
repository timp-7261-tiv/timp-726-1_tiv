#include <stdlib.h>
#include <stdio.h>

typedef struct node {
	int value;
	int key;
	struct node *left;
	struct node *right;
	struct node *parent;
} node;

typedef struct queue {
	struct queue *next;
	struct queue *prev;
	struct node *point;
} queue;

queue *head=NULL;
queue *tail=NULL;

int q_isEmpty()
{
	if ((head==NULL)&&(tail==NULL))
		return 1;
	else
		return 0;
}

void q_init (node *point)
{
	queue *tmp = malloc(sizeof(queue));
	tmp->point = point;
	tmp->next = NULL;
	head = tmp;
	tail = tmp;
}

node *q_get_first()
{
	if (q_isEmpty() == 0)
	{
		queue *tmp = head;
		return tmp->point;
	}
	else
	{
		printf("Очередь пуста!\a");
		return NULL;
	}
}

void q_add(node *point)
{
	if (q_isEmpty()==1)
		q_init (point);
	else
	{
		queue *tmp = malloc(sizeof(queue)); 
		tmp->point=point;  
		tmp->next=NULL;
		tail->next=tmp;
		tail=tmp;  
	}
}

void q_destroy()
{
	if (q_isEmpty()==0)
	{
		queue *tmp=head;
		queue *temp=NULL;
		do{
			temp=tmp->next;
			free(tmp);
			tmp=temp;
		}while (tmp!=NULL);
		head=NULL;
		tail=NULL;
	}
}

void q_remove_first()
{
	queue *tmp=head;
	int no_op=0;
	
	if (q_isEmpty()==1)
	{
		no_op = 1;
		printf("Очередь пуста!\a");
	}
	if (head==tail && no_op==0)
	{
		q_destroy();
		no_op=1;
	}
		
	if (no_op==0)
	{
		head=tmp->next;
		free(tmp);
		no_op=1;
	}	
}

node *init()
{
	node *root = malloc(sizeof(node));
	root->value=-1;
	root->key=-1;
	root->left=NULL;
	root->right=NULL;
	root->parent=NULL;
	return root;
}

int isEmpty(node *root)
{
	if (root->key==-1)
		return 1;
	else
		return 0;
}

void add (node *root, int key, int value)
{

	for(;;)
	{
		if (root->key==-1)
		{
			root->key=key;
			root->value=value;
			break;
		}
		
		if (root->key==key)
		{
			root->value=value;
			break;
		}	
	
	
		if (key>root->key)
		{
			if (root->right==NULL)
			{
				node *tmp = init();
				root->right = tmp;
				tmp->key=key;
				tmp->value=value;
				tmp->parent=root;
				break;
			}
			else
			{
				root=root->right;
				continue;
			}
		}
	
	
		if (key<root->key)
		{
			if (root->left==NULL)
			{
				node *tmp = init();
				root->left = tmp;
				tmp->key=key;
				tmp->value=value;
				tmp->parent=root;
				break;
			}
			else
			{
				root=root->left;
				continue;
			}
		}
	}
	
}


void key_get_out(node *root, int key)
{
	int i = 0;
	 
	for(;;)
	{	
		if (key==root->key)
		{
			printf ("%d ", i);
			printf ("%d", root->value);
			break;
		}
		
		if (key>root->key)
		{
			if (root->right==NULL)
			{
				printf ("-1");
				break;
			}
			else
			{
				root=root->right;
				i++;
				continue;
			}
		}
		
		if (key<root->key)
		{
			if (root->left==NULL)
			{
				printf ("-1");
				break;
			}
			else
			{
				root=root->left;
				i++;
				continue;
			}
		}	
	}		
	printf ("\a");
}

void destroy(node *root)
{
	node *tmp=NULL;
	for(;;)
	{
		if (root->left!=NULL)
		{
			root=root->left;
			continue;
		}
		if (root->right!=NULL)
		{
			root=root->right;
			continue;
		}
		
		tmp=root->parent;
		if (tmp!=NULL)
		{
			if (tmp->key>root->key)
				tmp->left=NULL;
			else
				tmp->right=NULL;
				
			free(root);
			root=tmp;
		}
		else
		{
			free(root);
			break;
		}
	}
} 

void wide(node *root)
{
q_add(root);

	for(;;)
	{
		if (root->left!=NULL)
			q_add(root->left);
			
		if (root->right!=NULL)
			q_add(root->right);
			
		printf ("%d ", root->value);
		q_remove_first();
		if (q_isEmpty()==1)
			break;
		root=q_get_first();
	}
}

int main()
{
	int a=0,key=0,value=0;
	
	node *root=init();
	
	scanf("%d",&a);
	
	for (int i=0;i<a;i++) 
	{ 
		scanf ("%d", &key);
		scanf ("%d", &value);
		add(root, key, value); 
	}
	
	wide(root);
	
	
	destroy(root);
	
	printf("\a");
	return 0;
}

