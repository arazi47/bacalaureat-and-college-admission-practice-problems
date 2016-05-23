#include<iostream>

using namespace std;

int n, p, v[100], cnt;

void afisare()
{
    for(int i = 1; i <= p; i++)
        cout << v[i] << " ";

    cout << "\n";

    ++cnt;
}

bool solutie(int k)
{
    return k == p;
}

bool valid(int k)
{
    if (k > 1 && v[k] <= v[k - 1])
        return false;

    return true;
}

void back(int k)
{
    for(int i = 1; i <= n; i++)
    {
        v[k] = i;

        if(valid(k))
            if (solutie(k))
                afisare();
        else
            back(k + 1);
    }
}
int main()
{
    cout << "Combinari de: ";
    cin >> n;

    cout << "...luate cate: ";
    cin >> p;

    back(1);

    cout << "In total sunt " << cnt << " combinari.";

    return 0;
}
