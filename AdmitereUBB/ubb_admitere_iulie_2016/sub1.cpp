// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2016-iulie-informatica.pdf

#include <iostream>

using namespace std;

void determina(int p, int q, int n, int &k, int *x)
{
    bool magic;
    for (int i = 1; i < n; ++i)
    {
        magic = true;
        int vdf[10] = {};
        int nr = i;
        while (nr > 0)
        {
            vdf[nr % p] = 1;
            nr /= p;
        }
        nr = i;
        while (nr > 0)
        {
            ++vdf[nr % q];
            nr /= q;
        }

        for (int j = 0; j < 10; ++j)
            if (vdf[j] == 1)
            {
                magic = false;
                break;
            }

        if (magic)
            x[k++] = i;
    }
}

// n == 3: 1 2 1 3 1 2 1
void turnuri(int n)
{
    int s = 0, cnt = 0;
    for (int i = 1; i < n; ++i)
    {
        ++s;
        ++cnt;
    }
    for (int i = 2; i < n; ++i)
    {
        s += i;
        ++cnt;
    }

    cout << 2 * cnt + 1 << " turnuri si " << 2 * s + n << " monede";
}

void inserare(int &n, int *v)
{
    int nr;
    for (int i = n - 1; i >= 0; --i)
    {
        nr = 1;
        while (2 * nr < v[i])
            nr *= 2;

        v[2 * i] = v[i];
        v[2 * i + 1] = nr;
    }

    n *= 2;
}

int main()
{
    /*
    int n;
    cin >> n;
    turnuri(n);
    */

    /*
    int b1, b2, n, k = 0, x[100];
    cin >> b1 >> b2 >> n;
    determina(b1, b2, n, k, x);

    for (int i = 0; i < k; ++i)
        cout << x[i] << ' ';
    */

    int n, v[100];
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    inserare(n, v);

    for (int i = 0; i < n; ++i)
        cout << v[i] << ' ';

    return 0;
}
