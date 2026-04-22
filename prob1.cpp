#include "stack.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    Stack s;
    init(&s);

    string simbol;
    for (int i = 0; i < n; i++) {
        cin >> simbol;
        if (simbol == "+" || simbol == "-" || simbol == "*" || simbol == "/") {
            int bil2 = peek(&s); pop(&s);
            int bil1 = peek(&s); pop(&s);
            int hasil;
            if (simbol == "+") hasil = bil1 + bil2;
            else if (simbol == "-") hasil = bil1 - bil2;
            else if (simbol == "*") hasil = bil1 * bil2;
            else if (simbol == "/") {
                if (bil2 == 0) throw runtime_error("Division by zero");
                hasil = bil1 / bil2;
            }
            push(&s, hasil);
        } else {
            int angka = stoi(simbol);
            push(&s, angka);
        }
    }
    cout << peek(&s) << endl;

    return 0;
}
