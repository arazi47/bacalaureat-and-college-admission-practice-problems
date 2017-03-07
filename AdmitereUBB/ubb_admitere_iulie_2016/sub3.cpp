// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2016-iulie-informatica.pdf

#include <iostream>

using namespace std;

void citeste(int &n, int *a)
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
}

bool munte(int n, int *a, int st, int fin)
{
    while (a[st] < a[st + 1])
        ++st;

    bool munte = st < fin;

    if (munte)
    {
        while (st < fin && a[st] > a[st + 1])
            ++st;
    }

    munte = munte && (st == fin);

    return munte;
}

bool distincte(int n, int *a)
{
    int vdf[10000] = {};
    for (int i = 0; i < n; ++i)
    {
        ++vdf[a[i]];
        if (vdf[a[i]] > 1)
            return false;
    }

    return true;
}

void ceaMaiFrecventa(int n, int *a, int &altitudine, int &cnt)
{
    int vdf[10000] = {}, max = 1;
    for (int i = 0; i < n; ++i)
    {
        ++vdf[a[i]];
        if (vdf[a[i]] > vdf[max] && a[i] != 0)
            max = a[i];
    }

    altitudine = max;
    cnt = vdf[max];
}

void ceaMaiLungaInsula(int n, int *a, int &st, int &fin)
{
    int stMax = 0, finMax = 0, stCurr = 0, finCurr = 0;
    for (int i = 0; i < n; ++i)
    {
        while (a[i] == 0)
            ++i;

        stCurr = i;

        while (a[i] != 0)
            ++i;

        finCurr = i - 1;

        // daca la sfarsitul sirului nu avem 0...
        if (finCurr >= n)
            break;

        if (finCurr - stCurr > finMax - stMax)
        {
            finMax = finCurr;
            stMax = stCurr;
        }
    }

    st = stMax;
    fin = finMax;
}

// 15 10 2 1 0 7 0 1 2 13 5 0 0 8 5 2
// 10 1 2 0 1 2 13 0 0 1 2
int main()
{
    int n, a[100];
    citeste(n, a);

    int st = 0, fin = 0;
    ceaMaiLungaInsula(n, a, st, fin);

    // in exemple se incepe indexarea de la 1
    cout << st + 1 << ' ' << fin + 1 << endl;

    if (munte(n, a, st, fin))
        cout << "Este munte" << endl;
    else
        cout << "Nu este munte" << endl;

    if (distincte(n, a))
        cout << "Altitudinile sunt distincte" << endl;
    else
    {
        cout << "Altitudinile nu sunt distincte" << endl;
        int alt = 0, cnt = 0;
        ceaMaiFrecventa(n, a, alt, cnt);
        cout << "Cea mai frecventa altitudine este " << alt << " si apare de " << cnt << " ori" << endl;
    }

    return 0;
}
