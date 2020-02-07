#include <bits/stdc++.h>
using namespace std;
 
 
int main()
{
    int n , m;
    cin >> n >> m;
    unsigned int ingredients[513] = {0};
    for(int i=0 ; i<n ; i++)
    {
        int a , client=0;
        cin >> a;
        for(int j=0 ; j<a ; j++)
        {
            unsigned int b;
            cin >> b;
            client = client | 1LL << (b-1);
        }
        ingredients[client]++;
    }
    vector <pair<pair<unsigned int , unsigned int> , pair<unsigned long long , unsigned long long>>> pizza(513); //STOP
    for(int i=0 ; i<m ; i++)
    {
        unsigned long long pret , nri , idpizza=0;
        cin >> pret >> nri;
        for(int j=0 ; j<nri ; j++)
        {
            int aux; cin >> aux;
            idpizza = idpizza | 1LL<<(aux-1);
        }
        if(!pizza[idpizza].second.first)
        {
            pizza[idpizza].second.first = pret;
            pizza[idpizza].first.first = i+1;
        }
        else if(!pizza[idpizza].second.second)
        {
            int mm = min(pret , pizza[idpizza].second.first) , mM = max(pret , pizza[idpizza].second.first);
            pizza[idpizza].first.second = i+1;
            if(mM == pizza[idpizza].second.first)
                swap(pizza[idpizza].first.second , pizza[idpizza].first.first);
            pizza[idpizza].second.first = mm;
            pizza[idpizza].second.second = mM;
        }
        else
        {
            if(pret < pizza[idpizza].second.first)
            {
                pizza[idpizza].second.second = pizza[idpizza].second.first;
                pizza[idpizza].second.first = pret;
                pizza[idpizza].first.second = pizza[idpizza].first.first;
                pizza[idpizza].first.first = i+1;
            }
            else if(pret < pizza[idpizza].second.second)
            {
                pizza[idpizza].second.second = pret;
                pizza[idpizza].first.second = i+1;
            }
        }
    }
    unsigned long long p1=0 , p2=0 , bestpret = 1000000000002;
    long long satis=-1;
    for(unsigned int i=511 ; i>1 ; i--)
        if(pizza[i].first.first)
            for(unsigned int j=i-1 ; j>0 ; j--)
                if(pizza[j].first.first)
                {
                    unsigned int nrs=0;
                    for(unsigned int l=0 ; l<512 ; l++)
                        if(((i | j) & l) == l)
                            nrs += ingredients[l];
                    if(nrs > satis)
                    {
                        satis = nrs;
                        p1 = pizza[i].first.first;
                        p2 = pizza[j].first.first;
                        bestpret = pizza[i].second.first + pizza[j].second.first;
                    }
                    else if(nrs == satis)
                    {
                        satis = nrs;
                        if (pizza[i].second.first + pizza[j].second.first < bestpret)
                        {
                            p1 = pizza[i].first.first;
                            p2 = pizza[j].first.first;
                            bestpret = pizza[i].second.first + pizza[j].second.first;
                        }
                    }
                }
    for(unsigned int i=511 ; i>=1 ; i--)
        if(pizza[i].second.second)
        {
            unsigned int nrs=0;
            for(unsigned int l=0 ; l<512 ; l++)
                if((i & l) == l)
                    nrs += ingredients[l];
            if(nrs > satis)
            {
                satis = nrs;
                p1 = pizza[i].first.first;
                p2 = pizza[i].first.second;
                bestpret = pizza[i].second.first + pizza[i].second.second;
            }
            else if(nrs == satis)
            {
                satis = nrs;
                if (pizza[i].second.first + pizza[i].second.second < bestpret)
                {
                    p1 = pizza[i].first.first;
                    p2 = pizza[i].first.second;
                    bestpret = pizza[i].second.first + pizza[i].second.second;
                }
            }
        }
    cout << p1 << " " << p2;
    return 0;
}
