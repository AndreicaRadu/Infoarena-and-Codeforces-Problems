#include <iostream>
#include <vector>
using namespace std;
int r , c;
vector <string> V(501);
bool sheep(int x , int  y)
{
    if(x>0 && V[x-1][y] == 'S')
        return true;
    if(y>0 && V[x][y-1] == 'S')
        return true;
    if(x<r-1 && V[x+1][y] == 'S')
        return true;
    if(y<c-1 && V[x][y+1] == 'S')
        return true;
    return false;
}
int main()
{
    cin >> r >> c;
    for(int i=0 ; i<r ; i++)
        cin >> V[i];
    for(int i=0 ; i<r ; i++)
        for(int j=0 ; j<c ; j++)
        {
            if(V[i][j] == 'W' && sheep(i , j))
            {
                cout << "No";
                return 0;
            }
            if(V[i][j] == '.' && sheep(i , j))
                V[i][j] = 'D';
        }
    cout << "Yes" << "\n";
    for(int i=0 ; i<r ; i++)
        cout << V[i] << "\n";
}
