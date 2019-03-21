#include <iostream>
#include <algorithm>
using namespace std;
int n,m,v[1010],Max=0,Min=0,k=0,i,j,a[1010][1010];
int main()
{
	cin>>n>>m;
	for(i=1;i<=m;i++) cin>>v[i];
	sort(v+1,v+m+1,greater<int>());
	for(i=1;i<=v[1];i++) for(j=1;j<=m;j++)
	{
		if(i<=v[j]) a[i][j]=i;
	}
	for(i=v[1];i>=1;i--) for(j=1;j<=m;j++)
	{
		Max=Max+a[i][j];
		if(a[i][j]!=0) k++;
		if(k==n) {i=0;j=m+1;};
	}
	cout<<Max<<" ";
	k=0;
	for(j=m;j>=1;j--)for(i=v[1];i>=1;i--)
	{
		Min=Min+a[i][j];
		if(a[i][j]!=0) k++;
		if(k==n) {j=0;i=0;}
	}
	cout<<Min;
}
