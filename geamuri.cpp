#include <iostream>
#include <fstream>
using namespace std;
int B[1040][1040]={0},A[1040][1040]={0};
int v[50009]={0};
int main()
{
    ifstream fin("geamuri.in");
    ofstream fout("geamuri.out");
    int i,j,C,N,M,x1,x2,y1,y2;
    fin>>C;
    fin>>N;
    for(i=1; i<=N; i++)
    {
        fin>>x1>>y1>>x2>>y2;
        B[x1][y1]++;
        B[x2+1][y1]--;
        B[x1][y2+1]--;
        B[x2+1][y2+1]++;
    }
    for(i=1; i<=C; i++)
        for(j=1; j<=C; j++)
            {
                A[i][j]=A[i-1][j]+A[i][j-1]-A[i-1][j-1]+B[i][j];
                v[A[i][j]]++;
            }
    fin>>M;
    for(i=1; i<=M; i++)
    {
        fin>>j;
        fout<<v[j]<<endl;
    }

    return  0;
}
