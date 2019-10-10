#include<iostream>
using namespace std;

struct node
	{
		int data;
		struct node *next;
	};
	
	struct node *head= NULL;
		struct node *temp,*newnode;
	int ch;
	int con;
	void insert();
	void display();	
	
	void insertAtBegin();
	void insertAtPos();
	void DeleteEle();
	void DeleteEleAtBegin();
	int main()
	{
		do{
			cout<<"1.insert\n";
			cout<<"2.display\n";
			cout<<"3.Insert At Begin\n";
			cout<<"4.Insert At Pos\n";
			cout<<"5.Delete Element\n";
			cout<<"6.Delete Element at beginning\n";
			
			cout<<"enter your choice\n";
			cin>>ch;
			switch(ch)
			{
				case 1: insert();
						break;
				case 2: display();
						break;
				case 3: insertAtBegin();
						break;
				case 4: insertAtPos();
						break;
				case 5: DeleteEle();
						break;
				case 6: DeleteEleAtBegin();
						break;
			 
				default:
				cout<<"invalid selection\n";
					
			}
			cout<<"enter 1 to continue and 0 to exit\n";
			cin>>con;
		}while(con==1);
		return 0;
	}
	
	void insert(){
		struct node *newnode;
		newnode=new node();
		cout<<"enter data element\n";
		cin>>newnode->data;
		newnode->next=NULL;
		
		if(head==NULL)
		{
			head=newnode; 
			temp=newnode;
		}
		else
		{
			 temp->next=newnode;
			 temp=newnode;
		}
		
	
	}
	
	void display()
	{
		struct node *p;
		p = head;
		if(p==NULL)
		{
			cout<<"currently list is empty\n";
			
		}
		else{
			

		while(p->next!=NULL)
		{
		cout<<p->data<<endl;
		p = p->next;	
		}
		cout<<p->data<<endl;
		}
	}
	void insertAtBegin()
	{
		newnode = new node();
		cout<<"enter the data element\n";
		cin>>newnode->data;
		newnode->next=NULL;
		
		if(head==NULL)
		{
			head = newnode;
		}
		else
		{
			newnode->next = head;
			 head = newnode;	
		}
			
	}	
	

void insertAtPos()
{
	int a;
	cout<<"enter position to insert an element"<<endl;
	cin>>a;
	int count=0;
	struct node *p=head;
	while(p->next!=NULL)
	{
		count++;
		p=p->next;
		
	}
	count++;
	cout<<"no of nodes = "<<count<<endl;
	if(a<=count+1)
	{
		struct node *p1=head,*p2=head;
		int i=1;
		while(i<a-1)  
		{
			p1=p1->next;
			p2=p2->next;
			i++;
		}
		if(a!=1)
		{
			p2=p2->next;
			
		}	
		newnode=new node();
		cout<<"enter new value"<<endl;
		cin>>newnode->data;
		newnode->next=NULL;
		newnode->next=p2;
		p1->next=newnode;
	}
	else
	{
		cout<<"plz insert less than"<<count<<endl;
		
	}
}
	void DeleteEle()
	{
	int a;
	int count=0;
	cout<<"enter the position of the element to delete\n";
	cin>>a;
	struct node *p=head;
	if(head==NULL)
	{
		cout<<"empty list";
	}
	
	else
	{
	
	while(p->next!=NULL)
	{
		count++;
		p= p->next;
	}
	count++;
	cout<<"no of nodes\n"<<count<<endl;
	
	
	if(a<=count)
	{
	struct node *p1 = head;
		struct node *p2 = head,*d;
		int i=1;
		while(i<a-1)
		{
			p1 = p1->next;
			p2 = p2->next;
			i++;
		}
		d=p1->next;
		 p2 = p2->next->next;
		 
	
		p1->next=p2;
		d->next=NULL;
		
			cout<<"node deleted with value of "<<d->data<<"\n";
			delete(d);
	}

	}
}
void DeleteEleAtBegin()
{
	temp = head;
	head = temp->next;
	delete(temp);
}

