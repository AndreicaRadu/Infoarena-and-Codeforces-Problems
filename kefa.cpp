#include <iostream>

using namespace std;
long long int v[2][100010],n,d,s=0;
void friendsum(int x, int y)
{
    int l;
    s=0;
    for(l=x;l<=y;l++)
        s=s+v[1][l];
}
int chose_pivot(int st,int dr){
    int r1,r2,r3;
    r1=rand()%(dr-st+1)+st;
    r2=rand()%(dr-st+1)+st;
    r3=rand()%(dr-st+1)+st;
    if(v[0][r1]<=v[0][r2] && v[0][r1]<=v[0][r3])
            return (v[0][r2]<=v[0][r3]?v[0][r2]:v[0][r3]);
    if(v[0][r2]<=v[0][r1] && v[0][r2]<=v[0][r3])
            return (v[0][r1]<=v[0][r3]?v[0][r1]:v[0][r3]);
    if(v[0][r3]<=v[0][r1] && v[0][r3]<=v[0][r2])
            return (v[0][r1]<=v[0][r2]?v[0][r1]:v[0][r2]);
}
void quicksort(int st,int dr){
    int pivot=chose_pivot(st,dr),i=st,j=dr;
    while(i<=j){
        while(v[0][i]<pivot) ++i;
        while(v[0][j]>pivot) --j;
        if(i<=j){
            swap(v[0][i],v[0][j]);
            swap(v[1][i],v[1][j]);
            ++i; --j;
        }
    }
    if(j>st)quicksort(st,j);
    if(i<dr)quicksort(i,dr);
}
int main()
{
    int i,j;
    long long k;
    cin>>n>>d;
    for(i=1;i<=n;i++) cin>>v[0][i]>>v[1][i];
    quicksort(1,n);
    k=0;j=0;
    for(i=1;i<=n&&j<n;i++)
    {
        while(v[0][j+1]-v[0][i]<d&&j<n) j++;
        friendsum(i,j);
        if(s>k) k=s;
    }
    cout<<k;
}
