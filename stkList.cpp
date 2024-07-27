# include <iostream>
using namespace std;
typedef int itemType;
struct node 
{
	itemType value;
	struct node *next;
};
struct node *top;
int count;
itemType defRet=-1;
//itemType defRet="null";
void push()
{
	struct node *temp;
	temp=new node;
	cout<<"Element ?"<<endl;
	cin>>temp->value;
	temp->next=NULL;
	if (top!=NULL)
		temp->next=top;
	top=temp;
	++count;
}
int isempty()
{
	return (top==NULL)?1:0;
}
itemType pop()
{
	struct node *temp;
	temp=top;
	itemType x;
	x=temp->value;
	top=top->next;
	delete temp;
	--count;
	return x;
}
itemType stkT()
{
	if (top!=NULL)
		return top->value;
	return defRet;
}
	
void print()
{
	if (top!=NULL)
	{
		struct node *temp;
		cout<<"Total number of element in the stack : "<<count<<endl;
		cout<<"Stack elements are \n";
		for (temp=top;temp!=NULL;temp=temp->next)
			cout<<temp->value<<"-->";
		cout<<"NULL"<<endl;
	}
	else
		cout<<"Empty Stack!"<<endl;
}

int main()
{
	int c=1,ch;

	cout<<"Stack using Linked Lists\n";
	while (c)
	{
	cout<<"1.Push \t 2.Pop \t 3. Stack Top \n";
	cout<<"Choice?";
	cin>>ch;
	switch(ch)
	{
		case 1:	push();
			break;
		case 2:	if (!isempty())
				cout<<pop()<<" deleted "<<endl;
			else
				cout<<"Stack empty"<<endl;
;			break;
		case 3: stkT();
			break;
		default: cout<<"Valid choice please.."<<endl;
			break;
	}
	print();
	cout<<"\n---------------\n";
	cout<<"Continue ? (0 to exit)"<<endl;
	cin>>c;
	}
	return 0;
}

	

	

		

