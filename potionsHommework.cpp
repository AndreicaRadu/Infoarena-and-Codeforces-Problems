#include <stdio.h>
#include <algorithm>
using namespace std;
int v[100001];
int main()
{
    int n,i,a=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&v[i]);
    sort(v+1,v+n+1);
    for(i=1;i<=n;i++) a=(a+(v[i]%10007)*(v[n+1-i]%10007))%10007;
    printf("%d",a);
}
