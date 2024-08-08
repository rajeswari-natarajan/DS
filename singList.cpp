# include <iostream>
using namespace std;
typedef int itemType;
struct node
{
	itemType value;
	struct node *next;
};
class SLL
{
public:
	struct node *head;
	int count;
	SLL();
	bool isempty();
	void insert();
	void del();
	void search();
	void display();
	void destroy();
	
};
SLL::SLL()
{
	count=0;
	head=NULL;
}
bool SLL::isempty()
{
	return (head==NULL)?true:false;
}
void SLL::insert()
{
	struct node *temp;
	itemType x;
	temp=new node;
	cout<<"Value ?"<<endl;
	cin>>x;
	temp->value=x;
	temp->next=NULL;
	if (isempty())
	{
		head=temp;
		++count;
		return;
	}
	if (head->value > x)
	{
		temp->next=head;
		head=temp;
		++count;
		return;
	} 
	struct node *prev,*curr;
	for (prev=head,curr=head; curr!=NULL && curr->value < x; prev=curr,curr=curr->next);
	
	if (curr==NULL)
	{
		prev->next=temp;
	}
	else
	{
		temp->next=prev->next;
		prev->next=temp;
	}
	++count;
}
void SLL::display()
{
if (!isempty())
	{
	struct node *temp;
	cout<<"Total number of element in the List : "<<count<<endl;
	cout<<"List elements are \n";
	for (temp=head;temp!=NULL;temp=temp->next)
		cout<<temp->value<<"-->";
	cout<<"NULL"<<endl;
	}	
	else
		cout<<"Empty List!"<<endl;
}

void SLL::del()
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
		delete temp;
		return;
	}
	struct node *prev, *curr;
	for (prev=head, curr=head; curr!=NULL&&curr->value!=x;prev=curr,curr=curr->next);
	if (curr==NULL)
		cout<<"Value not found "<<endl;
	else
	{
		prev->next=curr->next;
		cout<<curr->value<<" deleted "<<endl;
		--count;
		delete curr;
	}
}

void SLL::search()
{
	if (!isempty())
	{
		struct node *temp;
		int c=0;
		int x;
		cout<<"Value to be searched ?"<<endl;
		cin>>x;
		for (temp= head,c=1;temp!=NULL&&temp->value!=x; temp=temp->next,c++);
		if (temp==NULL)
			cout<<"Value not found \n";
		else
			cout<<temp->value<<" found in position "<<c<<endl;
	}
}

void SLL::destroy()
{
	struct node *t1, *t2;
	t2=head;
	while (t2!=NULL)
	{
		t1=t2->next;
		cout<<t2->value<<" destroyed \n";
		delete t2;
		t2=t1;	
	}
	head=NULL;
}
int main()
{
	int c=1,ch;
	SLL s;
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


