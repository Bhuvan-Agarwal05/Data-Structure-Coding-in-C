#include<stdio.h>
#include<stdlib.h>

typedef struct NODE{
	struct NODE *prev;
	int data;
	struct NODE *next;
}node;

node *create_list(node *);
void display(node*);
node *insert_at_beg(node*);
node *insert_at_end(node *);
node *insert_at_pos(node *,int);
node *delete_from_beg(node *);
node *delete_from_end(node *);
node *delete_from_pos(node *,int);
node *reverse_list(node *);
int length_of_list(node *);

int main()
{
	int ch,pos,len;
	node *head;
	head=NULL;  // This value NULL is assigned to HEAD POINTER , because this is our INITIAL LIST !
	
	while(1)  // For INFINITE LOOP:   USER CAN EXIT BY SELECTING THE OPTION !!!
	{
	printf("\n1) CREATE LINKED LIST.\n2) DISPLAY LIST.\n3) INSERT AT BEGINNING.\n4) INSERT_AT_LAST.\n5) INSERT AT ANY POSITION.\n6) DELETE FROM BEGINNING.\n7) DELETE FROM END.\n8) DELETE FROM ANY POSITION.\n9) REVERSE THE LIST.\n10) THE LENGTH OF THE LIST.\n11) EXIT.\n");
    scanf("%d",&ch);
	switch(ch)
      {
    	case 1: head=create_list(head);
    	        break;
    	case 2: display(head);
    	        break;
    	case 3: head=insert_at_beg(head);
    	        break;
        case 4: head=insert_at_end(head);
                break;
        case 5: printf("Enter the Position You Want to Add the New Node:-\n");
        		scanf("%d",&pos);
				head=insert_at_pos(head,pos);
				break;
		case 6: head=delete_from_beg(head);
		        break;
		case 7: head=delete_from_end(head);
		        break;
		case 8: printf("Enter the Position From Where You Want to Delete the Node:-\n");
        		scanf("%d",&pos);
				head=delete_from_pos(head,pos);
		        break;
		case 9: head=reverse_list(head);
		        break;
		case 10:len=length_of_list(head);
				printf("The Length Of The List is:- %d",len);
		        break;
		case 11: exit(0);
		    default:
		    	 printf("\nINVALID CHOICE...");
	  }
	}
}

// Function To Create The Linked List  (Initially)
node * create_list(node *head)
{
	node *new_node,*temp;
	int choice=1;
	while(choice)
	{
	new_node=(node *)malloc(sizeof(node));
	printf("Enter Data:-\n");
	scanf("%d",&new_node->data);
	new_node->prev=NULL;
	new_node->next=NULL;
	
	if(head==NULL)
		{
			head=temp=new_node;
		}
	else
		{
			temp->next=new_node;
			new_node->prev=temp;
			temp=new_node;
		}
	
	printf("Do You Want to insert another data(0/1)?\n");
	scanf("%d",&choice);
	}
return head;
}

// Function The Display The Linked List
void display(node *head)
{
	node *temp;
	temp=head;
	if(head==NULL)
	{
		printf("\nHEAD->null");
	}
	else
	{
		while(temp!=NULL)   // This is how we traverse the list
	 		{
	   			printf("%d<=>",temp->data);
	   			temp=temp->next;
			}
   		printf("NULL");
	}
}

// Function To Insert The NewNode At The First Of The List
node * insert_at_beg(node *head)
{
	node *new_node;
	new_node=(node *)malloc(sizeof(node));
	printf("\nEnter Data:-\n");
	scanf("%d",&new_node->data);
	new_node->prev=NULL;
	new_node->next=NULL;
	if(head==NULL)
	     head=new_node;
	else
	{
		new_node->next=head;
		head->prev=new_node;
		head=new_node;
	}
	return head;
}

// Function To Insert The NewNode At The End Of The List
node *insert_at_end(node *head)
{
	node *temp,*new_node;
	temp=head;
	new_node=(node *)malloc(sizeof(node));
	printf("\nEnter Data:-\n");
	scanf("%d",&new_node->data);
	new_node->prev=NULL;
	new_node->next=NULL;
	if(head==NULL)  // If Our List is Empty then Inserting At Last means Inserting At First Only... This is an Extension which I have given to the user.
	{
	    head=new_node;
	}
	else
	{
		while(temp->next!=NULL)
			{
				temp=temp->next;
			}
		temp->next=new_node;
		new_node->prev=temp;
	}
	return head;
}

// Function To Insert The NewNode At User's Given Position
node * insert_at_pos(node *head,int pos)
{
	int count=1;
	node *new_node,*temp,*prev_node;
	temp=prev_node=head;
	new_node=(node *)malloc(sizeof(node));
	printf("\nEnter Data:-\n");
	scanf("%d",&new_node->data);
	new_node->prev=NULL;
	new_node->next=NULL;
	
	while(pos>count)
	 {
		prev_node=temp;
		temp=temp->next;
		count++;
	 }
	 if(head==NULL)
	     head=new_node;
	else if(pos==1)  // If Already Nodes are inserted and still we want to insert at location 1
	 {
		new_node->next=head;
		head->prev=new_node;
		head=new_node;
	 }
	else
	 {
		new_node->next=temp;
		temp->prev=new_node;
		prev_node->next=new_node;
		new_node->prev=prev_node;
     }
  return head;
}

// Function To Delete The First Node Of The List
node *delete_from_beg(node *head)
{
	node *temp;
	temp=head;
	if(head==NULL)   // If The List Is Already Empty, Then We Can't Delete From First Here
	     printf("\nThe List Is Empty! ");
	else if(head->next==NULL)
		 head=NULL;
	else
	{
		head=head->next;
		head->prev=NULL;
	}
	free(temp);
	return head;
}

// Function To Delete The Last Node Of The List
node * delete_from_end(node *head)
{
	node *temp,*prev_node;
	temp=prev_node=head;
	if(head==NULL)   // If The List Is Already Empty, Then We Can't Delete From Last (i.e First Here)
	    printf("\nThe List Is Empty! ");
	else if(head->next==NULL)
	{
		head=NULL;
		free(temp);
	}
	else
	{
		while(temp->next!=NULL)
			{
				prev_node=temp;
				temp=temp->next;
			}
		prev_node->next=NULL;
		free(temp);
	}
	return head;
}

// Function To Delete From Any Position
node * delete_from_pos(node *head,int pos)
{
	int count=1;
	node *temp,*prev_node;
	temp=prev_node=head;
	if(pos<1) // If USER Enters Any Invalid Positions like 0 , -1 , etc.
	   printf("\nINVALID POSITION...\nThe Position Must Be A Natural Number!");
	else
	{
		while(pos>count)
			{
				prev_node=temp;
				temp=temp->next;
				count++;
			}
		if(head->next==NULL)
			   head=NULL; 
		else if(pos==1)
	  		{
				head=head->next;
				head->prev=NULL;
	  		}
		else
	  		{
	    		prev_node->next=temp->next;
	    		temp->next->prev=prev_node;
      		}
		free(temp);
	}
	return head;
}

// Function To Reverse The List
node *reverse_list(node *head)
{
	node *current_node,*prev_node,*next_node;
	prev_node=NULL;
	current_node=next_node=head;
	
	while(next_node!=NULL)
	{
		next_node=next_node->next;
		current_node->next=prev_node;
		current_node->prev=next_node;
		prev_node=current_node;
		current_node=next_node;
	}
	head=prev_node;
	return head;
}

// Function To Find The Length Of The Linked List
int length_of_list(node *head)
{
	int len=1;
	node *temp;
	temp=head;
	if(head==NULL)  // If The Linked List Is Empty.
	     return 0;
	else
	{
		while(temp->next!=NULL)
			{
				temp=temp->next;
				len++;
			}
		return len;
	}
}
