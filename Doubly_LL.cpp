#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *prev;
	struct node *next;
	
};
struct node *head=NULL,*tail,*temp,*newnode;

void insertAtEnd()
{
	newnode=new node();
cout<<"Enter data element \n";
cin>>newnode->data;
newnode->next=NULL;
newnode->prev=NULL;

	if(head==NULL)
	{
		head=newnode;
		temp=newnode;
	}
	else
	{
		newnode->prev=temp;
		temp->next=newnode;
		temp=temp->next;
		
		
	}
}
void display()
{
	struct node *p=head;
	if(p==NULL)
	{
		cout<<"list empty \n";
		
	}
	else{
		while(p->next!=NULL)
		{
			cout<<p->data<<"\n";
			p=p->next;
		}
		cout<<p->data<<"\n";
	}
}
void insertAtPos()
{
	struct node *p1=head,*p2=head,*p=head;
	cout<<"Enter position you want to enter\n";
	int a;
	cin>>a;
	int count=0;
	if(p==NULL)
	{
		cout<<"list empty \n";
	}
	else
	{
		while(p->next!=NULL)
		{
			count++;
			p=p->next;
		}
		count++;
		cout<<"number of nodes = "<<count<<endl;
		int i=0;
		if(a<=count+1)
		{
			cout<<"inside a<=count+1 ";
			while(i<a-2)
			{
				
			cout<<"inside i<a-2 ";
				p1=p1->next;
				p2=p2->next;
				i++;		
			}
			p2=p2->next;
			
			
			newnode=new node();
			cout<<"Enter data element \n";
			cin>>newnode->data;
			newnode->next=NULL;
			newnode->prev=NULL;
			
			
			newnode->next=p2;
			p2->prev=newnode;
			newnode->prev=p1;
			p1->next=newnode;
			
		}
		else
		{
			cout<<"FUCK OFF";
				
		}
		
	}
	
	
}
void insertAtBegin()
{
newnode=new node();
cout<<"Enter data element \n";
cin>>newnode->data;
newnode->next=NULL;
newnode->prev=NULL;
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		newnode->next=head;
		head->prev=newnode;
		head=newnode;	
	}
	
}
void deleteAtEnd()
{
	if(head==NULL)
	{
		cout<<"list is empty\n";
			
	}
	else
	{
		struct node *p=head;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->prev->next=NULL;
		p->prev=NULL;
		delete(p);
		
				
	}	
}
void deleteAtPos()
{
	if(head==NULL)
	{
		cout<<"empty list\n";
			
	}	
	else
	{
		int a;
		cout<<"enter the position to delete element\n";	
		cin>>a;
		struct node *p;
		p = head;
		int count = 0;
		while(p->next!=NULL)
		{
			p = p->next;
			count++;	
		}
		count++;
		if(a<=count)
		{
			struct node *p1 = head,*p2 = head;
			int i=0;
			while(i<a-2)
			{
				i++;
				p1=p1->next;
				p2=p2->next;
			}
			
			struct node *d=p1->next;
			p2=p2->next->next;
			p2->prev=p1;
			p1->next=p2;
	
	
			
			delete(d);
				
		}
	}	
}
void deleteAtBegin()
{
	if(head==NULL)
	{
		cout<<"list is empty\n";
			
	}
	else
	{
		struct node *p;
		p=head;
		head=head->next;
		head->prev=NULL;
		delete(p);
	}
}	


int main()
{
	cout<<"--DOUBLY LINKED LIST OPERATIONS-- \n-----------------------------------------\n";	

	
	int choice,con=0;

	do
	{
	cout<<"1. Insert at begin \n";
	cout<<"2. Insert at specific position \n";	
	cout<<"3. Insert at end \n";
	cout<<"4. Delete at begin \n";
	cout<<"5. Delete at specific position \n";
	cout<<"6. Delete at end \n";
	cout<<"7. DISPLAY THE LIST \n";
		cout<<"Enter the choice\n";
		cin>>choice;
		switch(choice)
	{
		case 1: insertAtBegin(); break;
		case 2: insertAtPos();  break;
		case 3: insertAtEnd(); break;
		case 4: deleteAtBegin(); break;
		case 5: deleteAtPos(); break;
		case 6: deleteAtEnd(); break;
		case 7: display(); break;
	};
	cout<<"Enter 1 to continue ";
	cin>>con;
	}while(con==1);
	
}
