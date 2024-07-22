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
void insertionSort()
{
	int i,j;
	value m;
	for (i=2;i<=noItems;i++)
	{
		m=a[i];
		for (j=i-1;j>=1 && a[j] > m;j--)
			a[j+1]=a[j];
		a[j+1]=m;
		cout<<"Pass "<<i-1<<endl;
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
	insertionSort();
}


int main()
{
	get();
	return 0;
}
