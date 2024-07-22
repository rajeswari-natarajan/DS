# include <iostream>
using namespace std;
# define max 100
typedef int value;
int noItems;
value a[max];
void display()
{	
	int i;
	for (i=1;i<=noItems;i++)
		cout<<a[i]<<"\t";
	cout<<endl;
}
void selectionSort()
{
	int m,i,j;
	for (i=1;i<=noItems-1;i++)
	{
		m=i;
		for (j=i+1;j<=noItems;j++)
			if (a[j]<a[m])
				m=j;
		swap(a[i],a[m]);
		cout<<"Pass "<<i<<endl;
		display();
	}	
}

void get()
{
	cout<<"Number of Items ?";
	cin>>noItems;
	int i;
	cout<<"\n Items ? \n";
	for (i=1;i<=noItems;i++)
		cin>>a[i];
	selectionSort();
}


int main()
{
	get();
	return 0;
}
