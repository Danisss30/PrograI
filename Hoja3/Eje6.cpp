//Daniela Nohemy Divas Carrillo
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Ingrese un numero: ";
    cin >> n;

    int i = 1;

    while (i <= n) {
        int j = 1;

        while (j <= i) {
            cout << "*";
            j++;
        }

        cout << endl;
        i++;
    }

    return 0;
}
