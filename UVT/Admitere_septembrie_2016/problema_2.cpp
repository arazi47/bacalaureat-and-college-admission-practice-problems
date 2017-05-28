// https://drive.google.com/file/d/0B0NnkrRhUimbLW5DUTZtUTlvWVk/view
// Problema 2

#include <iostream>

using namespace std;

bool par(int n)
{
    return !(n % 2);
}

int cateNumerePare(int n, int v[])
{
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        if (par(v[i]))
            ++cnt;

    return cnt;
}

void interschimba(int &a, int &b)
{
    a += b;
    b = a - b;
    a -= b;
}

void sorteazaCrescator(int n, int v[])
{
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (par(v[i]) && par(v[j]) && v[i] > v[j])
                interschimba(v[i], v[j]);
}

void citire(int &n, int v[])
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
}

void afisare(int n, int v[])
{
    for (int i = 0; i < n; ++i)
        cout << v[i] << ' ';
}

// ex:
// n = 8
// v[] = 3 -1 6 5 8 4 7 -2
int main()
{
    int n, v[100];
    citire(n, v);
    afisare(n, v);
    cout << endl;
    sorteazaCrescator(n, v);
    afisare(n, v);

    return 0;
}
