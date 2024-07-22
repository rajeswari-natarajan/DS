# include <iostream>
using namespace std;
int gcd(int a,int b)
{
	if (a==0)
		return b;
	if (b==0)
		return a;
	return gcd(b,a%b);
}
int main()
{
	cout<<gcd(50,24);
	return 0;
}
