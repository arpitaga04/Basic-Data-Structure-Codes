#include<stdio.h>
#define max 10

int front, rear;

void insert(int *ar, int item)
{
	
	if(front == (rear+1)%max)
	{
		printf("\nQueue Full");
		return;
	}
	
	if(front == rear && front == -1)	
		front++;
	
	rear = (rear+1) % max;
	ar[rear] = item;
		
}

void display(int *ar)
{
	int i;
	
	if(front == -1)
	{
		printf("\nQueue Empty !!");
		return;
		
	}
	printf("\nDisplay Queue elements : ");
	if(front <= rear)
	{
		for(i = front; i <= rear; i++)
			printf("%d ",ar[i]);
	}
	
	else
	{
		for(i = front; i < max; i++)
			printf("%d ",ar[i]);
		
		for(i = 0; i <= rear; i++)
			printf("%d ",ar[i]);	
	}
}


int delete_element(int *ar)
{
	int temp;
	if(front == -1)
	{
		printf("\nQueue Empty !!");
		return -1;
		
	}
	
	else if(front == rear)
	{
		temp = ar[front];
		front = rear = -1;
		return temp;
	}
	
	front = (front + 1) % max;
	return ar[front-1];
	
}



int main()
{
	int ar[max];
	
	int ch = 0, item, n = max-1;
	front = rear = -1;
	printf("\n1. Insert\n2. Delete\n3. Display\nAny other number to exit");
	
	while(ch != 4)
	{
		printf("\nEnter choice : ");
		scanf("%d", &ch);
		item = 0;
		switch(ch)
		{
			case 1:
				printf("\nEnter element : ");
				scanf("%d", &item);
				insert(ar, item);
				
				break;
				
			case 2:
				item = delete_element(ar);
				if(item != -1)
					printf("\nDeleted Element : %d", item);
				break;
				
			case 3:
				display(ar);
				break;
				
			default:
				ch = 4;
		}
	}
	
	return 1;
}
