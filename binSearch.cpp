# include <iostream>
# define maxi 100
using namespace std;
typedef int value;
value a[maxi];
value k;
int noItems;
void get()
{
	cout<<"Number of Items ?";
	cin>>noItems;
	int i;
	cout<<"\n Items ? \n";
	for (i=0;i<noItems;i++)
		cin>>a[i];
	cout<<"Search Key ?\n";
	cin>>k;
	
}
void nrbinSearch()
{
	int low=0,high=noItems-1;
	int m;
	while (low<=high)
	{
		m=(low+high)/2;
		if (a[m]==k)
		{
			cout<<"Element Found in Location "<<m<<endl;
			return;
		}
		if (k<a[m])
			high=m-1;
		else
			low=m+1;
	}
	cout<<"Element Not Found "<<endl;	
}

int recbinSearch(int low, int high)
{
	int m;
	if (low > high)
		return -1;
	else
	{
		m=(low+high)/2;
		if (a[m]==k)
			return m; 
		if (k<a[m])
			return recbinSearch(low, m-1);	
		else
			return recbinSearch(m+1, high);	
	}
}

int main()
{
	cout<<"Input numbers in ascending order ...\n";
	get();
	nrbinSearch();
	int Loc=recbinSearch(0,noItems);
	if (Loc!=-1)
		cout<<"Key Found in Location "<<Loc<<endl;
	else
		cout<<"Key not Found !";
	return 0;
}

