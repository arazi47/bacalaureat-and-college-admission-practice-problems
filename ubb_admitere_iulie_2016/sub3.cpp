// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2016-iulie-informatica.pdf

#include <iostream>

using namespace std;

int a[100], n;

void citire()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
}

// Nu merge!
void verifica_munte(int start, int _end)
{
    int poz_switch = 0;
    for (int i = start; i < _end; ++i)
        if (i + 1 < i)
    {
        poz_switch = i;
        break;
    }

    if (poz_switch == 0)
        cout << "Nu este munte.\n";
}

void cea_mai_lunga_insula()
{
    int max_start = 0, max_end = 0, lungime_max = 0;
    int start, _end;

    for (int i = 1; i < n - 1; ++i) // Daca avem la capat 010
    {
        start = 0;
        _end = 0;

        if (a[i] == 0) // Incepe insula
        {
            //cout << "incepe insula la " << i + 1 << endl;
            start = i + 1;
            _end = i + 1;
            for (int j = start; j <= n; ++j)
                if (a[j] == 0)
                {
                    _end = j - 1;
                    i = _end + 1; // Se poate si fara. Dar ca sa sarim peste
                    break;
                }
        }

        if (start != _end) // Nu e insula daca sunt zerouri consecutive sau daca nu exista un zero pereche
            if (_end - start > lungime_max)
        {
            lungime_max = _end - start;
            max_start = start;
            max_end = _end;
        }
    }

    cout << max_start << ' ' << max_end << endl;
    //verifica_munte(max_start, max_end);
}

bool P_DIST = true; // Puncte distincte

void puncte_distincte()
{
    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (a[i] == a[j] && a[i] != 0) // 0 nu e altitudine
            {
                P_DIST = false;
                break;
            }

    if (!P_DIST)
        cout << "Altitudinile nu sunt distincte\n";
    else
        cout << "Altitudinile sunt distincte\n";
}

void altitudine_frecv()
{
    int vdf[10000] = {}; // Vectorul de frecventa al altitudinilor
    int aparitii = 0, index_;

    for (int i = 1; i <= n; ++i)
        if (a[i] != 0) // 0 nu e altitudine
            ++vdf[a[i]];

    for (int i = 1; i < 10000; ++i) // Incepem de la 1 pentru ca 0 nu e altitudine
        if (vdf[i] > aparitii)
        {
            aparitii = vdf[i];
            index_ = i;
        }

    cout << index_ << " apare de "  << aparitii << " ori.\n";
}

int main()
{
    citire();
    cea_mai_lunga_insula();
    puncte_distincte();
    if (!P_DIST)
        altitudine_frecv();

    return 0;
}
