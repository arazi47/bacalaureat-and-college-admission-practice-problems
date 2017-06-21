// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2015-iulie-informatica.pdf

#include <iostream>

using namespace std;

int elemente_sa(int n, int m, int a[100][100])
{
    bool minlin, maxlin, mincol, maxcol;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            minlin = maxlin = mincol = maxcol = true;

            for (int k = 0; k < n; ++k)
                if (a[i][j] > a[k][j] && i != k)
                   maxlin = false;

            for (int k = 0; k < n; ++k)
                if (a[i][j] < a[k][j] && i != k)
                    minlin = false;

                for (int k = 0; k < m; ++k)
                    if (a[i][j] < a[i][k] && j != k)
                        mincol = false;

                for (int k = 0; k < m; ++k)
                    if (a[i][j] > a[i][k] && j != k)
                        maxcol = false;

            if ((maxlin && mincol) ||
                (minlin && maxcol))
                    ++cnt;
        }

    return cnt;
}

int subI_A(int m, int n, int A[101][101])
{
    int cnt = 0, ml, mc; // max/min linie; max/min coloana

    for (int i = 1; i <= m; ++i)
    {
        ml = A[i][1];

        for (int j = 1; j <= n; ++j)
            if (A[i][j] > ml)
                ml = A[i][j];

        for (int j = 1; j <= n; ++j)
            if (A[i][j] == ml)
        {
            mc = A[1][j];

            for (int k = 1; k <= m; ++k)
                if (A[k][j] < mc)
                    mc = A[k][j];

            if (ml == mc)
                ++cnt;
        }
    }

    for (int i = 1; i <= m; ++i)
    {
        ml = A[i][1];

        for (int j = 1; j <= n; ++j)
            if (A[i][j] < ml)
                ml = A[i][j];

        for (int j = 1; j <= n; ++j)
            if (A[i][j] == ml)
        {
            mc = A[0][j];

            for (int k = 0; k <= m; ++k)
                if (A[k][j] > mc)
                    mc = A[k][j];

            if (ml == mc)
                ++cnt;
        }
    }

    return cnt;
}

int subI_B(int n)
{
    int n2 = n;
    int mult = 1;
    int cnt = 1; // cate cifre are numarul; incepem de la 1 pentru ca in while am scris n2 > 9
    int _max = 0;

    while (n2 > 9)
    {
        mult *= 10;
        ++cnt;
        n2 /= 10;
    }

    for (int i = 0; i < cnt; ++i)
    {
        n = (n % mult) * 10 + n / mult;

        if (n > _max)
            _max = n;
    }

    return _max;
}

// varianta nerecursiva
int subI_C_1(int n, int X[], int v)
{
    for (int i = 1; i <= n; ++i)
        if (X[i] == v)
            return i;

    return -1;
}

// varianta recursiva
int subI_C_2(int n, int X[], int v)
{
    if (n == 0)
        return -1;

    if (X[n] == v)
        return n;

    return subI_C_2(n - 1, X, v);
}

int main()
{
    return 0;
}
