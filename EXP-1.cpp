#include <iostream>

using namespace std;

int j(int n, int k) {
    return n == 1 ? 0 : (j(n - 1, k) + k) % n;
}

int w(int n, int k) {
    return j(n, k) + 1;
}

int main() {
    cout << "The winner is: " << w(5, 2) << endl;
    return 0;
}
