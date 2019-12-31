#include<stdio.h>
#include<stdlib.h>

typedef struct STACK{
	int data;
	struct STACK *next;
}stack_node;

stack_node *top=NULL;

stack_node *push(stack_node *,int);
stack_node *pop(stack_node *);
void peek(stack_node *);
void display(stack_node *);

int main()
{
	int ch,data;
	while(1)
	{
		printf("\n1) PUSH INTO STACK.\n2) POP FROM STACK.\n3) PEEK IN THE STACK.\n4) DISPLAY THE STACK.\n5) EXIT.\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nEnter The Data To Be Pushed:- ");
					scanf("%d",&data);
					top=push(top,data);
					break;
			case 2: top=pop(top);
					break;
			case 3: peek(top);
		      	    break;
			case 4: display(top);
		    	    break;
		    case 5: exit(0);
		    	default:
		    		printf("\n...INVALID CHOICE...");
		}
	}
}

// Function push() to insert data on the top of the Stack... Time Complexity for "PUSH OPERATION" is O(1)
stack_node * push(stack_node *top,int data)
{
		stack_node *new_node;
		new_node=(stack_node *)malloc(sizeof(stack_node));
		new_node->data=data;
		
        /* Here in Linked List we don't need to check for the "OVERFLOW CONDITION" 
		  , because Linked List is created Dynamically & not Statically as Array! */
		
		new_node->next=top;
		top=new_node;
		return top;
}

// Function pop() to delete data from the top of the Stack... Time Complexity for "POP OPERATION" is O(1)
stack_node * pop(stack_node *top)
{
	if(top==NULL)
	   printf("\nUNDERFLOW");
	else
	{
		stack_node *temp=top;
		top=top->next;
		printf("\nThe Popped Out Data is %d",temp->data);
		free(temp);
	}
	return top;
}

// Function peek() to Display The Topmost Data On The Stack... Time Complexity for "PEEK OPERATION" is O(1)
void peek(stack_node *top)
{
	if(top==NULL)
	    printf("\nUNDERFLOW");
	else
	{
		printf("\nThe Top Most Data in The Stack is %d.",top->data);
	}
}

// Function display() to Print All The Data In The Stack... Time Complexity for "DISPLAY OPERATION" is O(n), where n= Number Of Data In The Stack
void display(stack_node *top)
{
	if(top==NULL)
	   printf("\nUNDERFLOW");
	else
	{
		stack_node *temp=top;
		while(temp!=NULL)
			{
				printf("[%d]\n",temp->data);
				temp=temp->next;
			}
	}
}
