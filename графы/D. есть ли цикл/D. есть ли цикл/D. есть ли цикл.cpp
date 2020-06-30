#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[20][20];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
                arr[i][j] = -1;
            else
                arr[i][j] = 100;
        }
    for (int m = 0; m < n; m++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (arr[i][j] > arr[i][m] + arr[m][j] || arr[i][j] == 100)
                    arr[i][j] = arr[i][m] + arr[m][j];
            }
        }
    }
    bool TR = true;

    for (int i = 0; i < n; i++) {

        if (arr[i][i] < 0)
        {
            cout << "1";
            TR = false;
            break;
        }
    }

    if (TR)
        cout << "0";
}
