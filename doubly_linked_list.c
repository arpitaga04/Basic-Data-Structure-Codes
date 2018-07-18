#include<stdio.h>
#include<stdlib.h>

struct node
{
	int val;
	struct node *prev;
	struct node *next;
};

struct node *create_beg();
struct node *create_end();
struct node *insert_beg(struct node *start);
struct node *insert_end(struct node *start);
void reverseLL_by_content(struct node *start);
struct node *reverse_modify_link(struct node *start);
void traverse(struct node *start);


//Create a linked list by adding the pervious list at the end of the new node
struct node *create_beg()
{
	struct node *start = NULL, *p;
	int val;
	
	printf("\nEnter the values to create the linked list \nBy adding nodes at the beginning(-999 to end)\n");
	scanf("%d", &val);
	
	while(val != -999)
	{
		p = (struct node *)malloc(sizeof(struct node));
		p->val = val;
		if(start == NULL)
			p->next = NULL;
		else
		{
			p->next = start;
			start->prev = p;
		}
		p->prev = NULL;
		start = p;
		
		scanf("%d", &val);	
	}
	return start;
}

//Create a linked list by adding each node at the end of previous node
struct node *create_end()
{
	struct node *start, *p, *last;
	int val;
	
	printf("\nEnter the values to create the linked list \nBy adding nodes at the end(-999 to end)\n");
	scanf("%d", &val);
	
	while(val != -999)
	{
		p = (struct node *)malloc(sizeof(struct node));
		p->val = val;
		if(start == NULL)
		{
			p->prev = NULL;
			start = p;
		}
		
		else
		{
			p->prev = last;
			last->next = p;

		}
		p->next = NULL;
		last = p;
		
		scanf("%d",&val);
	}
	
	return start;
}

//Insert the node at the beginning of the list
struct node *insert_beg(struct node *start)
{
	struct node *p;
	printf("\nEnter the value to be inserted at the beginning : ");
	
	p = (struct node *)malloc(sizeof(struct node));
	scanf("%d",&p->val);
	
	p->next = start;
	if(start != NULL)
		start->prev = p;
	p->prev = NULL;
	start = p;
	
	return start;
}

//Insert the node at the end of the list
struct node *insert_end(struct node *start)
{
	struct node *p = start, *t;
	t = (struct node *)malloc(sizeof(struct node));
	t->next = NULL;
	printf("\nEnter the value to be inserted at the end : ");
	
	if(start == NULL)
	{
		t->prev = NULL;
		start = t;
		return start;
	}
	
	while(p->next != NULL)
		p = p->next;
	
	t->prev = p;
	p->next = t;
	return start;
}

//Reverse a list by swapping its contents
void reverseLL_by_content(struct node *start)
{
	struct node *p, *end;
	int n = 1, i, temp = 0;
	p = end = start;
	while(end->next != NULL)
	{
		n++;
		end = end->next;
	}
	
	for(i=1; i<=(n/2); i++)
	{
		temp = p->val;
		p->val = end->val;
		end->val = temp;
		p = p->next;
		end = end->prev;
	}
	
}

//Reverse a list by swapping the links of doubly linked list
struct node *reverse_modify_link(struct node *start)
{
	struct node *p = start, *t;
	while(p->next != NULL)
	{
		t = p->next;
		p->next = p->prev;
		p->prev = t;
		
		p = p->prev;
	}
	p->next = p->prev;
	p->prev = NULL;
	start = p;
	return start;
}

//Traverse through a linked list
void traverse(struct node *start)
{
	struct node *p = start;
	if(p == NULL)
		printf("\nLinked List Empty");
	
	while(p != NULL)
	{
		printf("\n%d",p->val);
		p = p->next;
	}
	printf("\n");
}
void printchoices()
{
	printf("\n");
		printf("Choices : "
			"1. Create a linked list by adding the pervious list at the end of the new node"
			"2. Create a linked list by adding each node at the end of previous node"
			"3. Insert the node at the beginning of the list"
			"4. Insert the node at the end of the list"
			"5. Reverse a list by swapping its contents"
			"6. Reverse a list by swapping the links of doubly linked list"
			"7. Traverse through a linked list"
			"999. Exit the program");
}

int main()
{
	struct node *start;
	
	int ch;
	
	printf("\nOperations on a Doubly Linked List");
	printchoices();
	
	while(1)
	{
		printf("\nEnter your choice : "
			"Enter choice as 0 if you want to print all choices");
			
		scanf("%d", &ch);
		
		switch(ch)
		{
		
			case 0:
			printchoices();
			break;
			
			case 1:
			start = create_beg();
			break;
			
			case 2:
			start = create_end();
			break;
			
			case 3:
			start = insert_beg(struct node *start);
			break;
			
			case 4:
			start = insert_end(struct node *start);
			break;
			
			case 5:
			reverseLL_by_content(start);
			break;
			
			case 6:
			start = reverse_modify_link(start);
			break;
			
			case 7:
			traverse(start);
			break;
				
			case 999:
			exit(0);
			
		}
		
		printf("\n");

	}
	return 1;
}
