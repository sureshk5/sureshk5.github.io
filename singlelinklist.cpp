#include<iostream>
#include <cstdlib>
using namespace std;
void CreateNode();
void DisplayElement();
void InsertAtBegining();
void InsertAtEnd();
void InsertAtSpecificPos();
void DeleteAtBe();
void DeleteAtEnd();
void DeleteAtSpec();
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL,*newnode, *temp, *prevnode;
int main()
{
	int choice;
	do
	{
	cout<<"Enter Your choice"<<endl;
	cout<<"1 Create Node"<<endl;
	cout<<"2 Display Node"<<endl;
	cout<<"3 Insert Node  At Begining"<<endl;
	cout<<"4 Insert Node At End"<<endl;
	cout<<"5 Insert Node at after specific Element"<<endl;
	cout<<"6 DELETE Node at Beginnig"<<endl;
	cout<<"7 DELETE Node at end"<<endl;
	cout<<"8 DELETE Specific Node "<<endl;
	cout<<"0 Exit"<<endl;
	cin>>choice;
	switch(choice)
	{
		case 1:
			   CreateNode();
			   break;
		case 2:
				DisplayElement();
				break;
		case 3:
				InsertAtBegining();
				break;
		case 4:
				InsertAtEnd();
				break;
		case 5:
				InsertAtSpecificPos();
				break;
		case 6:
				DeleteAtBe();
				break;
		case 7:
				DeleteAtEnd();
				break;
		case 8:
				DeleteAtSpec();
				break;										
		default :
				cout<<"wrong Choice"<<endl;							   
	}
}while(choice!=0);
}
void CreateNode()
{
	int a;
     	do{
		newnode =(struct node*) malloc(sizeof(struct node));
		cout<<"Enter New Node data"<<endl;
		cin>>newnode->data;
		newnode->next=NULL;		
	if(head==NULL)
	{
		head=temp=newnode;	
	}
	else 
	{
		temp->next=newnode;
		temp=newnode;
	}
	cout<<"press 1 for ADD more Element"<<endl;
	cin>>a;	
} while(a==1);
}
void DisplayElement()
{
	temp=head;
	cout<<"Node Elements"<<endl;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl<<endl;
}
void InsertAtBegining()
{
	newnode =(struct node*) malloc(sizeof(struct node));
		cout<<"Enter data "<<endl;
		cin>>newnode->data;
		
		newnode->next=head;
		head=newnode;	
}
void InsertAtEnd()
{
	   newnode =(struct node*) malloc(sizeof(struct node));
		cout<<"Enter data "<<endl;
		cin>>newnode->data;
		newnode->next=NULL;	
	if(head==NULL)
	{
		head=temp=newnode;	
	}
	else 
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
    } 
}
void InsertAtSpecificPos()
{
	int data;
	cout<<"Enter element to add new element after"<<endl;
	cin>>data;
	temp=head;
	while(temp->data!=data)
	{
	   temp=temp->next;		
	}
		newnode =(struct node*) malloc(sizeof(struct node));
		cout<<"Enter data "<<endl;
		cin>>newnode->data;	
		newnode->next=temp->next;
		temp->next=newnode;
}
void DeleteAtBe()
{
	if(head==NULL)
	{
		cout<<"list is empty";	
	}
	else
	{
		temp=head;
		head=head->next;
		free(temp);	
		
		cout<<"First NODE DELETED"<<endl<<endl<<endl;
	}	
}
void DeleteAtEnd()
{
	if(head==NULL)
	{
		cout<<"list is empty";	
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			prevnode=temp;
			temp=temp->next;
		}
		if(temp==head)
		{
			head=NULL;
		}
		else{
		
		  prevnode->next=NULL;
	   }
		free(temp);
		cout<<"End NODE DELETED"<<endl<<endl<<endl;
	}	
}
void DeleteAtSpec()
{
	int data;
	cout<<"Enter data to want delete";
	cin>>data;
	
	if(head==NULL)
	{
		cout<<"list is empty"<<endl;	
	}
	else
	{
		temp=head;
		while(temp->data!=data)
		{
			prevnode=temp;
			temp=temp->next;
		}
		prevnode->next=temp->next;
		free(temp);	
		
		cout<<"NODE DELETED"<<endl<<endl<<endl;
	}	
	
}
