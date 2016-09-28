// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-informatica-concurs-mate-info-ubb-ro-2016.pdf

#include <iostream>

using namespace std;

// Virusi, recursiv
int vRec(int n, int k)
{
    if (n < k)
        return 0;
    if (n % 2 == 0)
        return 1 + vRec(n / 2, k);
    if (n % 2 != 0)
        return 1 + vRec(n + 1, k);
}

// Virusi
int nrOre(int n, int k)
{
    int nrOre = 0;
    while (n >= k)
    {
        if (n % 2 == 0)
        {
            n /= 2;
            ++nrOre;
        }
        if (n % 2 != 0)
        {
            ++n;
            ++nrOre;
        }
    }

    return nrOre;
}

void prodMax(int n, int v[], int &a, int &b, int &c)
{
    bool ch = false; // Change
    int tmp;
    do
    {
        ch = false;
        for (int i = 0; i < n - 1; ++i)
            if (v[i] < v[i + 1])
            {
                tmp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = tmp;
                ch = true;
            }
    } while (ch);

    a = v[0];
    b = v[1];
    c = v[2];
}

void triunghiulLuiPascal(int r, int linie[])
{
    int linieNoua[33];
    linie[0] = 1;
    linie[1] = 1;

    for (int ri = 2; ri <= r; ++ri)
    {
        linieNoua[0] = 1;
        linieNoua[ri] = 1;

        for (int i = 1; i < ri; ++i)
            linieNoua[i] = linie[i - 1] + linie[i];

        for (int i = 0; i <= ri; ++i)
            linie[i] = linieNoua[i];
    }
}

void citire(int &n, int a[])
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
}

void afisare(int n, int a[])
{
    for (int i = 0; i < n; ++i)
        cout << a[i] << ' ';
}

void afisare(int nrPerm)
{
    if (nrPerm != -1)
        cout << "Da! Nr permutari ciclice: " << nrPerm;
    else
        cout << "Nu!";
}

bool estePalindrom(int a[], int start, int _end)
{
	int i = start;
	int j = _end;
	//se verifica perechi de elemente (cu indici simetrici fata de mijlocul secventei)
	//cand se gaseste o pereche de elemente diferite se opreste cautarea
	while ((a[i] == a[j]) && (i < j))
    {
		i++;
		j--;
	}
	//daca s-au verificat toate perechile si toate au avut elemente egale
	if (i >= j)
		return true;
	else
		return false;
}

void determinaPalindroame(int n, int a[])
{
    for (int i = 0; i < n; ++i)
        a[n + i] = a[i];

    int nrPerm = -1;
    for (int i = 0; i < n; ++i)
    {
        if (estePalindrom(a, i, i + n - 1))
        {
            nrPerm = i;
            break;
        }
    }

    afisare(nrPerm);
    //afisare(n, a);
}

int main()
{
    //cout << nrOre(11, 3) << endl;
    //cout << vRec(11, 3) << endl;

    //int n, v[100];
    //cin >> n;
    //for (int i = 0; i < n; ++i)
    //    cin >> v[i];

    //int a, b, c;
    //prodMax(n, v, a, b, c);
    //cout << a << ' ' << b << ' ' << c << endl;

    //int linie[100], r;
    //cin >> r;
    //triunghiulLuiPascal(r, linie);

    //for (int i = 0; i < r + 1; ++i)
    //    cout << linie[i] << ' ';

    // Subiectul 3
    //int n, a[100];
    //citire(n, a);
    //determinaPalindroame(n, a);
}
