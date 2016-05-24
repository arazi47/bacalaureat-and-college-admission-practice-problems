#include <iostream>
#include <fstream>

using namespace std;

int a[10][10]; // matricea de adiacenta
int n[100][100]; // matricea drumurilor
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

void warshall()
{
    for (int k = 1; k <= noduri; k++)
        for (int i = 1; i <= noduri; i++)
            for (int j = 1; j <= noduri; j++)
            {
                if (a[i][j] == 0)
                {
                    a[i][j] = a[i][k] * a[k][j];
                }
            }
}

int main()
{
    read();
    warshall();
    return 0;
}
