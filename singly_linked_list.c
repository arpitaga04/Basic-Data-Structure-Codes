#include<stdio.h>
#include<stdlib.h>

struct node
{
	int val;
	struct node *next;
};
	
struct node *create_end();
struct node *create_beg();
void traverse(struct node *start);
struct node *insert_beg(struct node *start);
struct node *insert_end(struct node *start);
void search_elem(struct node *start); 
void count_elem(struct node *start);
struct node *insert_position(struct node *start);
void insert_after_element(struct node *start);
struct node *insert_before_element(struct node *start);
struct node *insert_in_order(struct node *start);
struct node *delete_position(struct node *start);
void delete_after_element(struct node *start);
struct node *delete_before_element(struct node *start);
struct node *delete_all_element_occurence(struct node *start);
void del_middle_node(struct node *start);
struct node *reverse_list(struct node *start);
struct node *arrange_even_odd(struct node *start);

// A function that creates a linked list by adding each node at the end of previous node
struct node *create_end()
{
	struct node *p, *last, *start=NULL;
	int x;
	
	printf("\nEnter the values to create linked list\nEnter -999 to stop\n");
	scanf("%d",&x);
	
	while(x!=-999)
	{
		p = (struct node *)malloc(sizeof(struct node));
		p->val = x;
		p->next = NULL;
		if(start == NULL)
			start = p;
		else
			last->next = p;
			
		last = p;
		scanf("%d",&x);
	}
	return start;
}

// A function that creates a linked list by adding the pervious list at the end of the new node

struct node *create_beg()
{
	struct node *p, *start = NULL;
	int x;
	printf("\nEnter the values to create linked list\nEnter -999 to end ");
	scanf("%d",&x);
	
	while(x!=-999)
	{
		p = (struct node *)malloc(sizeof(struct node));
		p->next = start;
		p->val = x;
		start = p;
		scanf("%d",&x);
	}
	return start;
} 

//Traverse through a linked list
void traverse(struct node *start)
{
	struct node *p = start;
	while(p!= NULL)
	{
		printf("\n%d",p->val);
		p = p->next;
	}
}


//A function that takes the input of the value to be inserted in the node,
// and insert the node at the beginning of the list
struct node *insert_beg(struct node *start)
{
	struct node *p;
	p = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter the value to be inserted at beginning ");
	scanf("%d",&p->val);
	p->next = start;
	return p;
}

//A function that takes the input of the value to be inserted in the node,
// and insert the node at the end of the list

struct node *insert_end(struct node *start)
{
	struct node *p,*t;
	p = start;
	t = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter the value to be inserted at end ");
	scanf("%d",&t->val);
	
	t->next = NULL;
	if(start == NULL)
	{
		start = t;
		return start;	
	}
	while(p->next != NULL)
		p = p->next;
	p->next = t;
	return start;
}

//A function that takes an input and displays whether the element
// is there in the list or not
void search_elem(struct node *start)
{
	struct node *p=start;
	int elem;
	
	printf("\nEnter the element to be searched : ");
	scanf("%d",&elem);
	
	while(p	!= NULL)
	{
		if(elem == p->val) 
		{
			printf("%d exist in the linked list", p->val);
			return;
		}
		p = p->next;
	}
	printf("%d does not exist in the linked list", elem);
}

//A function that takes an input and counts the occurences of 
// the element in the linked list
void count_elem(struct node *start)
{
	struct node *p=start;
	int count = 0,elem;
	
	printf("\nEnter the element to be counted : ");
	scanf("%d",&elem);
	
	while(p	!= NULL)
	{
		if(elem == p->val) 
			count++;
		p = p->next;
	}
	if(count == 0)
		printf("\n%d does not exist in the linked list", elem);
	else
		printf("\n%d occurs %d times",elem,count);
	
}
//A function that inputs a position and the data to to be inserted in the
// the linked list, thus inserts the node at a given position.
struct node *insert_position(struct node *start)
{
	struct node *p = start, *t;
	int pos, i, count = 1;
	if(start != NULL)
	{
		t = (struct node *)malloc(sizeof(struct node));
	
		printf("\nEnter the position at which element is to be inserted : ");
		scanf("%d",&pos);
		printf("\nEnter the value to be inserted : ");
		scanf("%d",&t->val);
		if(pos == 1)
		{
			t->next = start;
			start = t;
			return start;
		}
		
		while(p->next != NULL)
		{
			p = p->next;
			count++;	
		}
	
		if(pos>count+1)
		{
			printf("\nIndex Out of Bound Error\nPosition not Inserted");
			return start;
		}
		p = start;
		for(i=1;i<(pos-1);i++)
			p = p->next;
		
		t->next = p->next;
		p->next = t;
	}
	else
		printf("\nList is Empty\nElement is not inserted ");
		
	return start;	
}


//A function that creates a node just after a inputed particular node,
// and writes the val into it.
void insert_after_element(struct node *start)
{
	struct node *p=start, *t;
	int testElem;
	
	if(start != NULL)
	{
		printf("\nEnter the element after which node is to be inserted ");
		scanf("%d", &testElem);
		while(p->val != testElem)
		{
			if(p->next == NULL)
			{
				printf("\nThe element %d does not exist in the list", testElem);
				return ;
			}
			p = p->next;
		}
		
		t = (struct node *)malloc(sizeof(struct node));
		printf("\nEnter the element to be inserted ");
		scanf("%d",&(t->val));
		t->next = p->next;
		p->next = t;
	}
	else
		printf("\nThe list is empty");
}

//A function that creates a node just before a inputed particular node,
// and writes the val into it.
struct node *insert_before_element(struct node *start)
{
	struct node *p=start, *t;
	int testElem;
	
	if(start != NULL)
	{
		printf("\nEnter the element before which node is to be inserted ");
		scanf("%d", &testElem);
		t = (struct node *)malloc(sizeof(struct node));
		if(p->val == testElem)
		{
			printf("\nEnter the element to be inserted ");
			scanf("%d",&(t->val));
			
			t->next = p;
			start = t;
			return start;
		}
		while(p->next->val != testElem)
		{
			if(p->next == NULL)
			{
				printf("\nThe element %d does not exist in the list", testElem);
				return start;
			}
			p = p->next;
		}
		
		printf("\nEnter the element to be inserted ");
		scanf("%d",&(t->val));
		t->next = p->next;
		p->next = t;
	}
	else
		printf("\nThe list is empty");
	return start;	
}

//A function that is constrained to accept an ascending ordered linked list,
// and insert a node in it in the order. 
struct node *insert_in_order(struct node *start)//Ascending order
{
	struct node *p=start, *t;
	int x;
	t = (struct node *)malloc(sizeof(struct node));
	
	printf("\nEnter the element to be inserted in an ordered linked list\nThe linked list is in ascending order : ");
	scanf("%d",&x);
	t->val = x;
	if(start == NULL)
	{
		printf("\nLinked List empty!!\nYou are inserting the first element : ");
		t->next = NULL;
		start = t;
		return start;
	}
	if(p->val >= x)
	{
		t->next = p;
		start = t;
		return start;
	}
	
	while(p->next->val < x)
	{
		if(p->next->next == NULL)
		{
			p = p->next;
			p->next = t;
			t->next = NULL;
			return start;
		}
		p = p->next;
	}
	
	t->next = p->next;
	p->next = t;
	return start;
}

//A function that inputs the position of the element to be deleted
// and takes in the start of the node as parameter
struct node *delete_position(struct node *start)
{
	struct node *p=start,*t;
	int pos,i,count = 1;
	
	if(start == NULL)
	{
		printf("\nDeletion not possible, List is empty ");
		return start;
	}
	
	printf("\nEnter the position to be deleted ");
	scanf("%d",&pos);
	
	if(pos == 1)
	{
		start = start->next;
		printf("\nValue at the deleted element %d",p->val);
		free(p);
		return start;
	}

	while(p->next != NULL)
	{
		p = p->next;
		count++;	
	}
	
	if(pos>count)
	{
		printf("\nIndex Out of Bound Error\nPosition not deleted");
		return start;
	}
	p = start;	
	for(i=1;i<(pos-1);i++)
		p = p->next;
	
	t = p->next;
	p->next = t->next;
	printf("\nValue at the deleted element %d",t->val);
	free(t);
	
	return start;
}

//A function that takes a test element as input and deletes a node after the occurence 
// of that element in the linked list
void delete_after_element(struct node *start)
{
	struct node *p = start, *t;
	int testElem;
	if(start == NULL)
	{
		printf("\nLinked List is empty, element cannot be deleted ");
		return;
	}
	
	printf("\nEnter the element after which a node is to be deleted : ");
	scanf("%d",&testElem);
	
	while(p->val != testElem)
	{
		if(p->next == NULL)
		{
			printf("\nTest element does not exist in the linked list ");
			return;
		}
		p = p->next;
	}
	if(p->next == NULL)
	{
		printf("\nNo element after that node");
		return;	
	}
	t = p->next;
	p->next = t->next;
	printf("\nElement of the deleted node : %d", t->val);
	free(t);
	
}

//A function that takes a test element as input and deletes a node before the occurence 
// of that element in the linked list
struct node *delete_before_element(struct node *start)
{
	struct node *p = start, *t;
	int testElem;
	if(start == NULL)
	{
		printf("\nLinked List is empty, element cannot be deleted ");
		return start;
	}
	printf("\nEnter the element before which a node is to be deleted : ");
	scanf("%d",&testElem);
	
	if(p->val == testElem)
	{
		printf("\nNode before the first element does not exist\nDeletion not possible");
		return start;
	}
	else if(p->next->val == testElem)
	{
		t = p;
		p = p->next;
		start = p;
		free(t);
		return start;
	}
	
	while(p->next->val != testElem)
	{
		if(p->next == NULL)
		{
			printf("\nTest element does not exist in the linked list ");
			return start;
		}
		t = p;
		p = p->next;
	}

	t->next = p->next;
	printf("\nElement of the deleted node : %d", p->val);
	free(p);
	return start;
}

//A function that delete all the occurences of an element 
// in a given list.
struct node *delete_all_element_occurence(struct node *start)
{
	struct node *p = start, *t;
	int testElem;
	
	if(start == NULL)
	{
		printf("\nThe list is empty\nNo elements can be deleted");
		return start;
		
	}
	printf("\nEnter the element which is to be deleted : ");
	scanf("%d",&testElem);
	while(p->val == testElem)
	{
		t = start;
		start = start->next;
		printf("\nElement %d deleted",t->val);
		free(t);
	}
	p = start;
	
	while(p->next != NULL)
	{
		if(p->next->val == testElem)
		{
			t = p->next;
			p->next = t->next;
			printf("\nElement %d deleted",t->val);
			free(t);
		} 
		else
			p = p->next;
	}
	return start;
}


//This function is written assuming that list has minimum of 2 elements
//Delete the middle element of the list
void del_middle_node(struct node *start)
{
	struct node *p = start, *t;
	int n = 1, i;
	
	while(p->next != NULL)
	{
		n++;
		p = p->next;
	}
	
	if(n%2 != 0)
	{
		p = start;
		for(i = 1; i < n/2; i++)
			p = p->next;
		t = p->next;
		p->next = t->next;
		printf("\nValue of element deleted : %d\n",t->val);
		free(t);
	}
	else
		printf("\nList has even no. of elements\n");
}

// Reverse the list
struct node *reverse_list(struct node *start)
{
	struct node *p,*t,*q;
	if(start == NULL)
	{
		printf("\nLinked List Empty\n");
		return start;
	}
	p = start;
	t = p->next;
	p->next = NULL;
	while(t->next != NULL)
	{
		q = t->next;
		t->next = p;
		p = t;
		t = q;
	}
	t->next = p;
	start = t;
	return start;
}

// Arrange the list as such that all even numbers occur first and all odds at the end
struct node *arrange_even_odd(struct node *start)
{
	struct node *p = start, *t, *last;
	last = p;
	if(start == NULL)
	{
		printf("\nLinked List Empty\n");
		return start;
	}
	
	while(p->next != NULL)
	{
		if(p->val%2 == 0 && p != start)
		{
			t = p->next;
			last->next = t;
			p->next = start;
			start = p;
			p = last;
		}
		last = p;
		p = p->next;
	}
	if(p->val%2 == 0)
	{
		last->next = NULL;
		p->next = start;
		start = p;
	}
	
	return start;
}

void printchoices()
{
	printf("\n");
		printf("Choices : "
			"1. Create a linked list by adding each node at the end of previous node"
			"2. Create a linked list by adding the pervious list at the end of the new node"
			"3. Traverse through a linked list"
			"4. Insert the node at the beginning of the list"
			"5. Insert the node at the end of the list"
			"6. Check whether the element is there in the list or not"
			"7. Count the occurences of element in the list"
			"8. Insert an element in the list by specifying the position"
			"9. Insert a node after a given element"
			"10. Insert a node before a given element"
			"11. Constrain to put the linked list in ascending order"
			"12. Delete an element by specifying the position"
			"13. Delete a node that occurs after the input element in the linked list"
			"14. Delete a node that occurs before the input element in the linked list"
			"15. Delete all the occurences of an element"
			"16. Delete the middle element of the list"
			"17. Reverse the list"
			"18. Arrange the list as such that all even numbers occur first and all odds at the end"
			"999. Exit the program");
}
int main()
{
	struct node *start = NULL;
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
			start = create_end();
			break;
			
			case 2:
			start = create_beg();
			break;
			
			case 3:
			traverse(start);
			break;
			
			case 4:
			start = insert_beg(start);
			break;
			
			case 5:
			start = insert_end(start);
			break;
			
			case 6:
			search_elem(start); 
			break;
			
			case 7:
			count_elem(start);
			break;
			
			case 8:
			start = insert_position(start);
			break;
			
			case 9:
			insert_after_element(start);
			break;
			
			case 10:
			start = insert_before_element(start);
			break;
			
			case 11:
			start = insert_in_order(start);
			break;
			
			case 12:
			start = delete_position(start);
			break;
			
			case 13:
			delete_after_element(start);
			break;
			
			case 14:
			start = delete_before_element(start);
			break;
			
			case 15:
			start = delete_all_element_occurence(start);
			break;
			
			case 16:
			del_middle_node(start);
			break;
			
			case 17:
			start = reverse_list(start);
			break;
			
			case 18:
			start = arrange_even_odd(start);
			break;
			
			case 999:
			exit(0);
			
		}
		
		printf("\n");
	}

	return 1;
}
