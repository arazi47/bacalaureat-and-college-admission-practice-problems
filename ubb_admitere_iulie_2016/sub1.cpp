// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2016-iulie-informatica.pdf

#include <iostream>

using namespace std;

void SubI_1(int n)
{
    int v[100];
    int marime = 1;
    int n2 = n - 1;
    v[0] = 1;
    int s = 1;
    while (n2 > 1)
    {
        v[marime++] = n2;
        v[marime++] = 1;

        s += 1 + n2;
        --n2;
    }

        cout << 2 * marime + 1 << " turnuri; " << 2 * s + n << " monede";
}

// ultima cifra a lui a^n
int F(int a, int b)
{
    int c = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
            c = (c * a) % 10;

        a = (a * a) % 10;
        b /= 2;
    }

    return c;
}

int F_REC(int a, int b)
{
    if (b == 0)
        return a;

    if (b % 2 == 1)
        return F_REC(a % 10, b / 2); // nu e corecta linia
    else
        return F_REC((a * a) % 10, b / 2);

}

void SubI_3(int a[], int &n)
{
    int i = 1;
    int nr_de_pus;

    while (i <= n)
    {
        nr_de_pus = 0;

        if (a[i] == 1 || a[i] == 2)
            nr_de_pus = 1;
        else
            for (int k = 2; k < a[i]; k *= 2)
                if (k > nr_de_pus)
                    nr_de_pus = k;

        for (int p = n; p > i; --p)
            a[p + 1] = a[p];

        a[i + 1] = nr_de_pus;
        ++n;
        i += 2;
    }
}

void SubI_2(int p, int q, int x[], int &k)
{

}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << F(a, b) << endl << F_REC(a, b);
    /*
    int x[100] = {}, k = 0, p, q;
    cin >> p >> q;

    int n, n1, b, aux, nr;
    bool ok;

    aux = nr = 0;
    int nr2;

    //cin >> n;
    int limita;
    cin >> limita;

    for (int i = 1; i <= limita; ++i)
    {
        ok = true;
        n = i;
        b = p;
        n1 = n;

    do
    {
        aux = aux * 10 + n1 % b;
        n1 /= b;
    } while (n1);

    do
    {
        nr = nr * 10 + aux % 10;
        aux /= 10;
    } while (aux);

    nr2 = nr;
    //cout << nr << endl;

    b = q;
    n1 = n;

    do
    {
        aux = aux * 10 + n1 % b;
        n1 /= b;
    } while (n1);

    do
    {
        nr = nr * 10 + aux % 10;
        aux /= 10;
    } while (aux);

    //cout << nr << endl;

        int vdf1[10] = {}, vdf2[10] = {};

        //cout << nr << ' ' << nr2 << endl;
        while (nr)
        {
            vdf1[nr % 10] = 1;
            nr /= 10;
        }

        while (nr2)
        {
            vdf2[nr2 % 10] = 1;
            nr2 /= 10;
        }

        for (int k = 0; k < 10; ++k)
            if (vdf1[k] != vdf2[k])
            {
                ok = false;
                break;
            }

        if (ok)
            cout << i << " ESTE\n";
    }*/
}
