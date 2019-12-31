#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int stack[MAX];
int top=-1;

void push(int);
void pop();
void peek();
void display();

int main()
{
	int ch,data,popped_data,top_data;
	while(1)
	{
		printf("\n1) PUSH INTO STACK.\n2) POP FROM STACK.\n3) PEEK IN THE STACK.\n4) DISPLAY THE STACK.\n5) EXIT.\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nEnter The Data To Be Pushed:- ");
					scanf("%d",&data);
					push(data);
					break;
			case 2: pop();
					
					break;
			case 3: peek();
		      	    break;
			case 4: display();
		    	    break;
		    case 5: exit(0);
		    	default:
		    		printf("\n...INVALID CHOICE...");
		}
	}
}

// Function push() to insert data on the top of the Stack... Time Complexity for "PUSH OPERATION" is O(1)
void push(int data)
{
	if(top==MAX-1)
	   printf("\nOVERFLOW");
	else
	{
		top++;
		stack[top]=data;
	}
}

// Function pop() to delete data from the top of the Stack... Time Complexity for "POP OPERATION" is O(1)
void pop()
{
	if(top==-1)
	   printf("\nUNDERFLOW");
	else
	{
		int popped_data=stack[top];
		top--;
		printf("\nThe Data Popped From The Stack is %d.",popped_data);
	}
}

// Function peek() to Display The Topmost Data On The Stack... Time Complexity for "PEEK OPERATION" is O(1)
void peek()
{
	if(top==-1)
	   printf("\nUNDERFLOW");
	else
	{
		int top_data=stack[top];
		printf("\nThe Data On The Top Of Stack is %d.\n",top_data);
	}
}

// Function display() to Print All The Data In The Stack... Time Complexity for "DISPLAY OPERATION" is O(n), where n= Number Of Data In The Stack
void display()
{
	if(top==-1)
	   printf("\nUNDERFLOW");
	for(int i=top;i>=0;i--)
	    {
	    	printf("[%d]\n",stack[i]);
		}
}

