#include <iostream>
#include <time.h>
#include <tchar.h>
using namespace std;
void vivod(int arr)
{
    cout << arr << "    ";
}

int _tmain(int argc, TCHAR* argv[]) 
{
    setlocale(LC_ALL, "Ukrainian");
    int a, b, n = 2, m = 22;
    cout << "Введіть a:";
    cin >> a;
    cout << "Введіть b:";
    cin >> b;
    int** arr = new int* [n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a < 0)
            {
                arr[i][j] = rand() % (b + abs(a) + 1) + a;
            }
            else
            {
                arr[i][j] = rand() % b + a;
            }
            vivod(arr[i][j]);
        }
        cout << endl;
    }
    int max = 0, k = 0;
    for (int j = 0; j < m - 1; j++)
    {
        int c = 0;
        for (int i = 1; i < n; i++)
        {
            c += arr[i][j] + arr[i][j + 1];
            if (j == 0 || c > max)
            {
                max = c;
                k = j;
            }
        }
    }
    cout << "Номера двух сусідніх рядків, сума елементів в якій максимальна: " << k << " " << k + 1 << endl;
    cout << endl;
    system("pause");
    return 0;
}