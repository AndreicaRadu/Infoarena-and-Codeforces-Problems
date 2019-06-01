#include <iostream>
#include<fstream>
#include <queue>
#include <set>
using namespace std;

ifstream fin("alee.in");
ofstream fout("alee.out");

int N , M;
int p[177][177];

void BFS(int x , int y , int x0 , int y0)
{
    queue <pair<int , int>> q;
    q.push(make_pair(x,y));
    set<pair<int , int>> s;
    s.insert(make_pair(x,y));
    do
    {
        int a = q.front().first , b = q.front().second;
        q.pop();
        if(a>0 && p[a-1][b] != -1 && s.find(make_pair(a-1 , b)) == s.end())
        {
            q.push(make_pair(a-1 , b));
            p[a-1][b] = p[a][b] + 1;
            s.insert(make_pair(a-1,b));
        }
        if(b>0 && p[a][b-1] != -1 && s.find(make_pair(a , b-1)) == s.end())
        {
            q.push(make_pair(a , b-1));
            p[a][b-1] = p[a][b] + 1;
            s.insert(make_pair(a,b-1));
        }
        if(a<N-1 && p[a+1][b] != -1 && s.find(make_pair(a+1 , b)) == s.end())
        {
            q.push(make_pair(a+1 , b));
            p[a+1][b] = p[a][b] + 1;
            s.insert(make_pair(a+1,b));
        }
        if(b<N-1 && p[a][b+1] != -1 && s.find(make_pair(a , b+1)) == s.end())
        {
            q.push(make_pair(a , b+1));
            p[a][b+1] = p[a][b] + 1;
            s.insert(make_pair(a,b+1));
        }

    } while(s.find(make_pair(x0,y0)) == s.end());
}

int main()
{
    fin>>N>>M;
    for(int i=0 ; i<M ; i++)
    {
        int a,b;
        fin>>a>>b;
        p[a-1][b-1] = -1;
    }
    int x , y , x0 , y0;
    fin>>x>>y>>x0>>y0;
    p[x-1][y-1] = 1;
    BFS(x-1,y-1,x0-1,y0-1);

    fout<<p[x0-1][y0-1];
}