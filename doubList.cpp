# include <iostream>
using namespace std;
typedef int itemType;
struct node
{
	itemType value;
	struct node *prev, *next;
};
class DLL
{
public:
	struct node *head;
	int count;
	DLL();
	bool isempty();
	void insert();
	void del();
	void search();
	void display();
	void destroy();
	
};
DLL::DLL()
{
	count=0;
	head=NULL;
}
bool DLL::isempty()
{
	return (head==NULL)?true:false;
}
void DLL::insert()
{
	struct node *temp;
	itemType x;
	temp=new node;
	cout<<"Value ?"<<endl;
	cin>>x;
	temp->value=x;
	temp->next=NULL;
	temp->prev=NULL;
	if (isempty())
	{
		head=temp;
		++count;
		return;
	}
	if (head->value > x)
	{
		temp->next=head;
		head->prev=temp;
		head=temp;
		++count;
		return;
	} 
	struct node *t1,*t2;
	for (t1=head,t2=head; t2!=NULL && t2->value < x; t1=t2,t2=t2->next);
	
	temp->next=t2;
	t1->next=temp;
	temp->prev=t1;
	if (t2!=NULL)
		t2->prev=temp;
	++count;
}
void DLL::display()
{
if (!isempty())
	{
	struct node *temp,*t1;
	cout<<"Total number of element in the List : "<<count<<endl;
	cout<<"List elements(Forward order) are \n";
	for (temp=head;temp!=NULL;temp=temp->next)
		cout<<temp->value<<"-->";
	cout<<"NULL"<<endl;
	cout<<"List elements(Reverse order) are \n";
	for (t1=head;t1->next!=NULL;t1=t1->next);
	for (temp=t1;temp!=NULL;temp=temp->prev)
		cout<<temp->value<<"-->";
	cout<<"NULL"<<endl;
	}	
	else
		cout<<"Empty List!"<<endl;
}

void DLL::del()
{
	if (isempty())
		return;
	
	int x;
	struct node *temp;
	cout<<"Value to be deleted ?"<<endl;
	cin>>x;
	if (head->value==x)
	{
		temp=head;
		head=head->next;
		cout<<temp->value<<" deleted "<<endl;
		--count;
		if (head!=NULL)
			head->prev=NULL;
		delete temp;
		return;
	}
	struct node *t1, *t2;
	for (t1=head, t2=head; t2!=NULL&&t2->value!=x;t1=t2,t2=t2->next);
	if (t2==NULL)
		cout<<"Value not found "<<endl;
	else
	{
		t1->next=t2->next;
		if (t2->next!=NULL)
			t2->next->prev=t1;
		cout<<t2->value<<" deleted "<<endl;
		--count;
		delete t2;
	}
}

void DLL::search()
{
	if (!isempty())
	{
		struct node *temp;
		int c=0;
		int x;
		cout<<"Value to be searched ?"<<endl;
		cin>>x;
		for (temp= head,c=1;temp!=NULL&&temp->value<x; temp=temp->next,c++);
		if (temp==NULL)
			cout<<"Value not found \n";
		else
		{
			if (temp->value==x)
				cout<<temp->value<<" found in position "<<c<<endl;
			else
				cout<<"Value not found \n";
		}
	}
}

void DLL::destroy()
{
	struct node *t1, *t2;
	t2=head;
	while (t2!=NULL)
	{
		t1=t2->next;
		--count;
		cout<<t2->value<<" destroyed, Balance No. of nodes : "<<count<<endl;
		
		delete t2;
		t2=t1;
	}
	head=NULL;
}
int main()
{
	int c=1,ch;
	DLL s;
	cout<<"Singly Linked List\n";
	while (c)
	{
		cout<<"1.Insert \t 2.Delete \t 3. Search \t  4. Destroy List \n";
		cout<<"Choice? ";
		cin>>ch;
		switch(ch)
		{
			case 1:	s.insert(); 	break;
			case 2:	s.del(); break;
			case 3: s.search(); 	break;
			case 4: s.destroy(); break; 
			default: cout<<"Valid choice please.."<<endl;
			break;
		}
		s.display();
		cout<<"\n---------------\n";
		cout<<"Continue ? (0 to exit)"<<endl;
		cin>>c;
	}
	return 0;
}


