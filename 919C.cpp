#include <iostream>
#include <vector>
using namespace std;
int r , c , n;
vector <string> V;
 
int main()
{
    cin >> r >> c >> n;
    for(int i=0 ; i<r ; i++)
    {
        string a; cin >> a;
        V.push_back(a);
    }
    int k=0 , ans=0;
    for(int i=0 ; i<r ; i++)
        for(int j=0 ; j<c ; j++)
        {
            if(V[i][j] == '.')
                k++;
            if(V[i][j] == '*' || j==c-1)
            {
                ans += max(0 , k-n+1);
                k = 0;
            }
        }
    if(n > 1)
        for(int j=0 ; j<c ; j++)
            for(int i=0 ; i<r ; i++)
            {
                if(V[i][j] == '.')
                    k++;
                if(V[i][j] == '*' || i==r-1)
                {
                    ans += max(0 , k-n+1);
                    k = 0;
                }
            }
    cout << ans;
}
