// http://www.techiedelight.com/custom-sort-sort-elements-array-order-elements-defined-second-array/
// Extrem de ineficient e rezolvata

#include <iostream>

using namespace std;

// verifica daca el este diferit de
// toate elementele aflate in m
bool diferit(int el, int m, int a[])
{
    for (int i = 0; i < m; ++i)
        if (a[i] == el)
            return false;
    return true;
}

// 15  5 8 9 3 5 7 1 3 4 9 3 5 1 8 4
// 4  3 5 7 2
int main()
{
    int n, m, v[100], a[100];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    cin >> m;
    for (int i = 0; i < m; ++i)
        cin >> a[i];

    for (int k = 0; k < m; ++k)
    {
        for (int i = 0; i < n - 1; ++i)
            for (int j = i + 1; j < n; ++j)
            {
                // k + 1 pentru ca vrem sa verificam ca v[i] este diferit
                // doar de elementele din m pe care le-am parcurs deja
                if (diferit(v[i], k + 1, a) && v[j] == a[k])
                    swap(v[i], v[j]);
            }
    }

    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (diferit(v[i], m, a) && v[i] > v[j])
                swap(v[i], v[j]);

    for (int i = 0; i < n; ++i)
        cout << v[i] << ' ';


    return 0;
}
