# include <iostream>
# define size 5
using namespace std;
typedef int value;
value stk[size];
int top=-1;
void print()
{
	cout<<"Contents of stack are .."<<endl;
	cout<<"Top : "<<top<<endl;
	for (int i=0;i<=top;i++)
		cout<<stk[i]<<"-->";
	cout<<endl;
}
int isfull()
{
	return (top==size-1)?1:0;
}
int isempty()
{
	return (top==-1)?1:0;
}
void push()
{
	if (!isfull())
	{
		value x;
		cout<<"Element to be pushed ?"<<endl;
		cin>>x;
		++top;
		stk[top]=x;
	}
	else
		cout<<"Stack Full "<<endl;
}
void pop()
{
	
	if (!isempty())
	{
		cout<<"Popped element : "<<stk[top]<<endl;
		--top;
	}
	else
		cout<<"Stack Empty "<<endl;
}
int main()
{
	cout<<"Stack using Array"<<endl;
	cout<<"1.Push \t 2. Pop \n";
	int c=1, ch;
	while (c)
	{
		cout<<"Choice"<<endl;
		cin>>ch;
		switch(ch)
		{
		case 1: push(); 	
				break;
		case 2: pop();	
				break;	
		default:	cout<<"Invalid choice"<<endl;
					break;
		}
		print();
		cout<<"Continue (0 to exit)?"<<endl;
		cin>>c;
	}
}
