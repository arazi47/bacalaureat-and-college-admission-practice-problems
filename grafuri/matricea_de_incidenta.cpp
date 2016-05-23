#include <iostream>
#include <fstream>

using namespace std;

int a[10][10]; // matricea de adiacenta
int n[100][100]; // matricea de incidenta
int noduri, muchii;

void read()
{
    ifstream in("data.in");
    int x, y;

    in >> noduri >> muchii;

    for (int i = 1; i <= muchii; i++)
    {
        in >> x >> y;
        a[x][y] = 1;
    }
}

void incidenta()
{
    int k = 1;

    for (int i = 1; i <= noduri; i++)
        for (int j = 1; j <= noduri; j++)
            if (a[i][j] == 1)
            {
                n[i][k] = 1;
                n[j][k] = -1;
                ++k;
            }
}

int main()
{
    read();
    incidenta();
    return 0;
}
