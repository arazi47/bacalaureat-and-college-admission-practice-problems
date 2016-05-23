#include<iostream>

using namespace std;

int n, v[100], cnt;

void afisare()
{
    for(int i = 1; i <= n; i++)
        cout << v[i] << " ";

    cout << "\n";

    ++cnt;
}

bool valid(int k)
{
    for(int i = 1; i < k; i++)
        if(v[i] == v[k])
            return false;

    return true;
}

void back(int k)
{
    if(k > n)
        afisare();
    else
        for(int i = 1; i <= n; i++)
        {
            v[k] = i;

            if(valid(k))
                back(k + 1);
        }
}
int main()
{
    cout << "Permutari" << endl;
    cout << "n: ";
    cin >> n;

    back(1);

    cout << "In total sunt " << cnt << " permutari.";

    return 0;
}
