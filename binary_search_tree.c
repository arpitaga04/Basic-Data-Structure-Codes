#include<stdio.h>
#include<stdlib.h>
#define MAX 100

//Test iterative inorder
struct node
{
	int val;
	struct node *left, *right;
};

struct node *stack[MAX];
int top = -1;

void push(struct node *p);
struct node *pop();
int empty();
struct node *newnode(int val);
struct node *insert(struct node *root, int val);
void inorder_iterative(struct node *root);
void inorder(struct node *root);
void preorder(struct node *root);
void postorder(struct node *root);
int search(struct node *root, int testElem);
void delete_child(struct node *p, struct node *prev);
struct node *delete_node(struct node *root, int elem);
int find_max(struct node *root);
int find_min(struct node *root);
int tot_nodes(struct node *root, int count);
int count_leaf(struct node *root, int count);
int count_one_child(struct node *root, int count);
int max_depth(struct node *root);



void push(struct node *p)
{
	top++;
	stack[top] = p;
}

struct node *pop()
{
	top--;
	return stack[top+1];
}

int empty()
{
	return (top == -1)?1:0;
}

struct node *newnode(int val)
{
	struct node *p = (struct node *)malloc(sizeof(struct node));
	p->val = val;
	p->left = p->right = NULL;
	
	return p;
}


struct node *insert(struct node *root, int val)
{
	if(root == NULL)
		return newnode(val);
	
	if(root->val > val)
		root->left = insert(root->left, val);
		
	else if(root->val < val)
		root->right = insert(root->right, val);
	
	else
		printf("\nDuplicate element cannot be inserted");
		
	return root;
}	

void inorder_iterative(struct node *root)
{	
	struct node *p = root;
	
	do
	{
		while(p != NULL)
		{
			push(p);
			p = p->left;
		}
		
		if(!empty())
		{
			p = pop();
			
			printf("%d\n", p->val);
			p = p->right;
		}
	} while(!empty() || p != NULL);
}

void inorder(struct node *root)
{
	if(root != NULL)
	{
		inorder(root->left);
		printf(" %d ", root->val);
		inorder(root->right);
	}
}

void preorder(struct node *root)
{
	if(root != NULL)
	{
		
		printf(" %d ", root->val);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(struct node *root)
{
	if(root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf(" %d ", root->val);
	}
}

int search(struct node *root, int testElem)
{
	if(root != NULL)
	{
		if(testElem == root->val)
			return 1;
		
		else if(testElem > root->val)
			return search(root->right, testElem);
			
		else 
			return search(root->left, testElem);
	}
	
	else
		return -1;
}

void delete_child(struct node *p, struct node *prev)
{
	if(p->right == NULL && p->left == NULL)
	{
		if(prev->right == p)
			prev->right = NULL;
		
		else if(prev->left == p)
			prev->left = NULL;
		
	}
	
	else if(p->left == NULL && p->right != NULL)
	{
		if(prev->left == p)
			prev->left = p->right;
		
		else if(prev->right == p)
			prev->right = p->right;
	}
	
	else if(p->left != NULL && p->right == NULL)
	{
		if(prev->left == p)
			prev->left = p->left;
		
		else if(prev->right == p)
			prev->right = p->left;
	}
	
	free(p);
}
struct node *delete_node(struct node *root, int elem)
{
	struct node *p, *prev, *q, *prev2;
	if(root == NULL)
	{
		printf("\nBST is empty");
		return NULL;
	}
	p = prev = root;
	
	if(root->val == elem)
	{
		if(root->left == NULL && root->right != NULL)
			root = root->right;
			
		else if(root->left != NULL && root->right == NULL)
			root = root->left;
		
		return root;
	}
	while(p != NULL)
	{
		if(p->val == elem)
			break;
		
		else if(p->val > elem)
		{
			prev = p;
			p = p->left;
		}
		
		else if(p->val < elem)
		{
			prev = p;
			p = p->right;
		}
	}
	
	if(p == NULL)
	{
		printf("\n%d not Found", elem);
		return root;
	}
	
	if(p->right != NULL && p->left != NULL)
	{
		q = p->right;
		prev2 = p;
		while(q->left != NULL)
		{
			prev2 = q;
			q = q->left;
		}
		p->val = q->val;
		delete_child(q, prev2);
		
	}
	
	else
		delete_child(p, prev);
	
	return root;
}

int find_max(struct node *root)
{
	struct node *p = root;
	if(root == NULL)
		return -1;

	while(p->right != NULL)
		p = p->right;
	
	return p->val;
		
}

int find_min(struct node *root)
{
	struct node *p = root;
	if(root == NULL)
		return -1;

	while(p->left != NULL)
		p = p->left;
	
	return p->val;
		
}

int tot_nodes(struct node *root, int count)
{
	if(root != NULL)
	{
		count = tot_nodes(root->left, count);
		count = count + 1;
		count = tot_nodes(root->right, count);
		
	}
	return count;
}

int count_leaf(struct node *root, int count)
{
	if(root != NULL)
	{
		count = count_leaf(root->left, count);
		
		if(root->left == NULL && root->right == NULL)
			count++;
		
		count = count_leaf(root->right, count);
		
	}
	return count;
}

int count_one_child(struct node *root, int count)
{
	if(root != NULL)
	{
		count = count_one_child(root->left, count);
		
		if((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL))
			count++;
		
		count = count_one_child(root->right, count);
		
	}
	return count;
	
}

//Also called maximum height of BST
int max_depth(struct node *root)
{
	int d1, d2;
	if(root != NULL)
	{
		d1 = max_depth(root->left);
		d2 = max_depth(root->right);
		
		return(1 + ((d1>d2)? d1:d2));
	}
	
	else 
		return 0;
}

void printchoices()
{
	printf("\n");
		printf("Choices : "
			"1. Insert"
			"2. Inorder traversal"
			"3. Preorder traversal"
			"4. Postorder traversal"
			"5. Iterative Inorder traversal"
			"6. Search an element"
			"7. Delete Element"
			"8. Find Maximum Element"
			"9. Find Minimum Element"
			"10. Count Nodes"
			"11. Count Leafs"
			"12. Count Nodes with one child"
			"13. Find the Max Depth"
			"999. Exit the program");
}

int main()
{
	struct node *root = NULL;
	
	int ch = 0, val, count = 0;
	
	printf("\nOperations on Binary Search Tree");
	printchoices();	
	while(1)
	{
		printf("\nEnter your choice : "
			"Enter choice as 0 if you want to print all choices");
		scanf("%d", &ch);
		count = 0;
		switch(ch)
		{
			case 0:
				printchoices();
				break;
			case 1:
				printf("\nEnter element : ");
				scanf("%d", &val);
				root = insert(root, val);
				break;
			
			case 2:
				printf("\nInorder Traversal : ");
				inorder(root);
				break;
			
			case 3:
				printf("\nPreorder Traversal : ");
				preorder(root);
				break;
			
			case 4:
				printf("\nPostorder Traversal : ");
				postorder(root);
				break;
				
			
			case 5:
				printf("\nIterative Inorder Traversal : ");
				inorder_iterative(root);
				break;
							
			
			case 6:
				printf("\nEnter element to be Searched : ");
				scanf("%d", &val);
				
				if(search(root, val) == -1)
					printf("\n%d not Found", val);
				else
					printf("\n%d Found", val);
				
				break;
				
			case 7:
				printf("\nEnter element to be Deleted : ");
				scanf("%d", &val);
				
				root = delete_node(root, val);
				break;
				
			case 8:
				val = find_max(root);
				if(val == -1)
					printf("\nBST is Empty");
				else
					printf("\nMax Element : %d", val);
				break;
				
			case 9:
				val = find_min(root);
				if(val == -1)
					printf("\nBST is Empty");
				else
					printf("\nMin Element : %d", val);
				break;
			
			case 10:
				count = tot_nodes(root, 0);
				if(count == 0)
					printf("\nNo nodes");
				
				else printf("\nNumber of nodes : %d", count);
				break;
			
			case 11:
				count = count_leaf(root, 0);
				if(count == 0)
					printf("\nNo leaf");
				
				else printf("\nNumber of leafs : %d", count);
				break;
			
			case 12:
				count = count_one_child(root, 0);
				if(count == 0)
					printf("\nNo nodes with one child");
				
				else printf("\nNumber of nodes with one child : %d", count);
				break;
				
			
			case 13:
				printf("\nMaximum Depth of BST : %d", max_depth(root));
				break;
				
			case 999:
				exit(0);
			
			
			default:
				printf("\nWrong Choice");
		
		}
		printf("\n");
	}
	
	return 1;
	
}
