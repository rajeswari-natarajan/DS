# include <iostream>
using namespace std;
void toh(int n, char s, char d, char a)
{
	static int c;
	if (n==1)
		cout<<"Move from "<<++c<<" "<<n<<"\t"<<s<<" "<<d<<endl;
	else
	{
		toh(n-1, s, a, d);
		cout<<"Move from "<<++c<<" "<<n<<"\t"<<s<<" "<<d<<endl;
		toh(n-1, a, d, s);
	}
}
int main()
{
	toh(2,'A','C','B');
	return 0;
}


