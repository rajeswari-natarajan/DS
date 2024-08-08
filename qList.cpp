# include <iostream>
using namespace std;
typedef int itemType;
struct node 
{
	itemType value;
	struct node *next;
};
struct node *f, *r;
int count;
itemType defRet=-1;
//itemType defRet="null";
int isempty()
{
	return (f== NULL &&r==NULL) ?1:0;
}
void enq()
{
	struct node *temp;
	temp=new node;
	cout<<"Element ?"<<endl;
	cin>>temp->value;
	temp->next=NULL;
	if (isempty())
		f=r=temp;
	else
	{
		r->next=temp;
		r=temp;
	}
	++count;
}
itemType deq()
{
	if (!isempty())
	{
		struct node *temp;
		temp=f;
		itemType x;
		x=f->value;
		f=f->next;
		if (f==NULL)
			r=NULL;
		delete temp;
		--count;
		return x;
	}
	return defRet;
}
itemType qf()
{
	if (!isempty())
		return f->value;
	return defRet;
}
itemType qr()
{
	if (!isempty())
		return r->value;
	return defRet;
}

void print()
{
	if (!isempty())
	{
		struct node *temp;
		cout<<"Total number of element in the Q : "<<count<<endl;
		cout<<"Q elements are \n";
		for (temp=f;temp!=NULL;temp=temp->next)
			cout<<temp->value<<"-->";
		cout<<"NULL"<<endl;
	}
	else
		cout<<"Empty Q!"<<endl;
}

int main()
{
	int c=1,ch;
	
	cout<<"Q using Linked Lists\n";
	while (c)
	{
		cout<<"1.Enq \t 2.DeQ \t 3. Front  \n 4. Rear \n";
		cout<<"Choice?";
		cin>>ch;
		switch(ch)
		{
			case 1:	enq();
					break;
			case 2:	{
					itemType t=deq();
					if (t!=defRet)
						cout<<t<<" deleted "<<endl;
					else
						cout<<"Q empty"<<endl;
					break;	
					}
			case 3: qf(); break;
			case 4: qr(); break;
			default:cout<<"Valid choice please.."<<endl;	break;
		}
		cout<<"Q contents \n";
		print();
		cout<<"\n---------------\n";
		cout<<"Continue ? (0 to exit)"<<endl;
		cin>>c;
	}
	return 0;
}







