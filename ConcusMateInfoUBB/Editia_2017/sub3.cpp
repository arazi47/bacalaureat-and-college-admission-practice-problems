// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-informatica-concurs-mate-info-ubb-ro-2017.pdf

#include <iostream>

using namespace std;

int sumaCifre(int n)
{
    int s = 0;
    while (n)
    {
        s += n % 10;
        n /= 10;
    }

    return s;
}

int cifraControl(int n)
{
    while (n > 9)
        n = sumaCifre(n);

    return n;
}

void citire(int &nr, int &m, int &n, int A[101][101])
{
    cin >> nr;
    cin >> m >> n;

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> A[i][j];
}

int revers(int n)
{
    int r = 0;
    while (n)
    {
        r = r * 10 + n % 10;
        n /= 10;
    }

    return r;
}

int DeterminaCelMaiLungPrefix(int nr, int m, int n, int A[101][101])
{
    // vectorul de frecventa al cifrelor de control
    // putem bool, si nu int pentru ca nu trebuie sa stim de cate ori apare cifra respectiva,
    // pentru ca o putem folosi de cate ori dorim
    bool cifreCtrl[10] = {};

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            cifreCtrl[cifraControl(A[i][j])] = true;

    int prefix = 0;
    // TODO:
    // ar trebui sa bagam cifrele intr-un vector
    // daca avem 0 la final se pierde
    nr = revers(nr);
    while (nr)
    {
        if (cifreCtrl[nr % 10])
            prefix = prefix * 10 + nr % 10;
        else
            break;

        nr /= 10;
    }

    if (prefix == 0)
        prefix = -1;

    return prefix;
}

void afiseazaPrefix(int pr)
{
    if (pr == -1)
        cout << "nu exista prefix";
    else
        cout << pr;
}

// 12319 3 4 182 12 274 22 22 1 98 56 5 301 51 94
int main()
{
   int A[101][101], m, n, nr;
   citire(nr, m, n, A);
   int prefix = DeterminaCelMaiLungPrefix(nr, m, n, A);
   afiseazaPrefix(prefix);

   return 0;
}
