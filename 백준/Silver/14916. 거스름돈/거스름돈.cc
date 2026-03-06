#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n2 = 0; // 2원 동전 개수
    int n5 = 0; // 5원 동전 개수

    int price = 0;
    cin >> price;

    int i = price / 5; 
    int possible = 0;
    int min = price / 2;
    if (price % 5 == 0 || price % 2 == 0) possible = 1;

    while (i) {
        int temp = price - 5 * i;
        if (!(temp % 2)) { // 2로 나누어 떨어지면
            if ((i + temp/2) < min) {
                n5 = i;
                n2 = temp / 2;
                min = n5 + n2;
            }
            possible = 1;
        }
        i--;
    }
    if (possible)
        cout << min << "";
    else
        cout << "-1\n";

    return 0;
}