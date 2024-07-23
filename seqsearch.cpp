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
void nrSeqSearch()
{
	int i;
	for (i=0;i<noItems && k!=a[i];i++);
	if (i==noItems)
		cout<<"Key not Found !";
	else
		cout<<"Key Found in Location "<<i<<endl;
}
int recSeqSearch(int i)
{
	if (i<0)
		return -1;
	if (a[i]==k)
		return i;
	return recSeqSearch(i-1);
}

int main()
{
	get();
	nrSeqSearch(); // Non-Recursive Sequential Search
	int Loc=recSeqSearch(noItems-1); //Recursive Sequential Search
	if (Loc!=-1)
		cout<<"Key Found in Location "<<Loc<<endl;
	else
		cout<<"Key not Found !";
	return 0;
}

