# include <iostream>
# include <string.h>
# define m 80
using namespace std;
int top = -1;
char infix[m], postfix[m], stk[m];

int isempty()
{
	return (top ==-1)? 1:0;
}
void push(char c)
{
	if (top!=m-1)
	{
		++top;
		stk[top]=c;
	}
}
char pop()
{
	if (!isempty())
	{
		char p=stk[top];
		--top;
		return p;
	}
	return '$';
}

int isopr(char s)
{
	switch(s)
	{
		case '+':
		case '*':
		case '-':
		case '/':
		case '^': return 1;
		default: return 0;
	}
}

int priority(char s)
{
	switch(s)
	{
		case '^': return 3;
		case '/':
		case '*': return 2;
		case '+':
		case '-': return 1;
		case '(': return 0;
		default: return -1;
	}

}
char stktop()
{
	if (!isempty())
		return stk[top];
	return '$';
}
void convert(char inf[])
{
	int i,j=0,p1,p2;
	char t;
	for (i=0;i<strlen(inf);i++)
	{
		t=inf[i];
		if (t=='(') 
			push(t);
		else if (isalpha(t) || isdigit(t))			
		{
			postfix[j]=t;
			++j;
		}
		else if (isopr(t))
		{
			p1=priority(t);
			p2=priority(stktop());	
			char t1;
			while (!isempty() && (stktop()!='(') && (p2>=p1) )
			{
				t1=pop();
				postfix[j]=t1;
				++j;
				//cout<<"t1"<<t1<<endl;

			}
			push(t);
		}
		else if (t==')')
		{
			char t2;
			while (!isempty() && (stktop()!='('))
			{
				t2=pop();			
				postfix[j]=t2;
				++j;
				//cout<<"t2"<<t2<<endl;

			}
			t2=pop();
		}

		
		for (int k=0; k<j;k++)
			cout<<postfix[k];
		cout<<endl;
	}
	while (!isempty())
	{
		char t3=pop();			
		postfix[j]=t3;
		++j;	
	}
	postfix[j]='\0';
	cout<<"Postfix expression \n"<<postfix<<endl;

}

int main()
{
	cout<<"Infix expression \n";
	cin>>infix;
	convert(infix);
	
	return 0;
}

		
				
		
	
	


