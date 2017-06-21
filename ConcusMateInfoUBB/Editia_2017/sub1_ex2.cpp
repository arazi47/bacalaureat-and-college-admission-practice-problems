// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-informatica-concurs-mate-info-ubb-ro-2017.pdf

#include <iostream>

using namespace std;

#define MAX 100

struct grup
{
    int forta;
    int n;
    int v[100];
};

void citire(int &n, int x[MAX])
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> x[i];
}

void ordoneazaCrescatorGrupurile(int nrGr, grup grupuri[MAX])
{
    for (int i = 0; i < nrGr - 1; ++i)
        for (int j = i + 1; j < nrGr; ++j)
            if (grupuri[i].forta > grupuri[j].forta)
            {
                grup t = grupuri[i];
                grupuri[i] = grupuri[j];
                grupuri[j] = t;
            }
}

// Determinam numarul cifrelor de 1
// In scrierea numarului n in binar (baza 2)
int determinaGrupulDeFortaAlNumarului(int n)
{
    int cnt1 = 0;
    while (n)
    {
        if (n % 2 == 1)
            ++cnt1;
        n /= 2;
    }

    return cnt1;
}

void determinaGrupuriDeForta(int x[MAX], int n, int &nrGr, grup grupuri[MAX])
{
    int forta;
    // Grupul curent
    nrGr = 0;
    for (int i = 0; i < n; ++i)
    {
        // Am trecut peste acest element deja
        if (x[i] == -1)
            continue;

        forta = determinaGrupulDeFortaAlNumarului(x[i]);
        grupuri[nrGr].forta = forta;
        grupuri[nrGr].n = 0;
        for (int j = i; j < n; ++j)
        {
            if (determinaGrupulDeFortaAlNumarului(x[j]) == forta)
            {
                // Inseram elementul in grup
                grupuri[nrGr].v[grupuri[nrGr].n++] = x[j];

                // Anulam elementul
                x[j] = -1;
            }
        }
        ++nrGr;
    }
}

void afiseazaGrupuriDeForta(int nrGr, grup grupuri[MAX])
{
    for (int k = 0; k < nrGr; ++k)
    {
        cout << "Forta: " << grupuri[k].forta << ": ";
        for (int i = 0; i < grupuri[k].n; ++i)
            cout << grupuri[k].v[i] << ' ';
        cout << endl;
    }
}

// Date de intrare
// 6
// 12 3 24 16 15 32
int main()
{
    int n, x[MAX], nrGr = 0;
    grup grupuri[MAX];
    citire(n, x);
    determinaGrupuriDeForta(x, n, nrGr, grupuri);
    ordoneazaCrescatorGrupurile(nrGr, grupuri);
    afiseazaGrupuriDeForta(nrGr, grupuri);

    return 0;
}
