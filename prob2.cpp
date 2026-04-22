#include "queue.h"
#include <iostream>

using namespace std;

int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (k <= 0 || k > n) return 0;

    Queue q;
    init(&q);

    long long current_sum = 0;

    for (int i = 0; i < k; i++) {
        enqueue(&q, arr[i]);
        current_sum += arr[i];
    }
    cout << current_sum;

    for (int i = k; i < n; i++) {
        int keluar = front(&q);
        dequeue(&q);

        enqueue(&q, arr[i]);

        current_sum = current_sum - keluar + arr[i];

        cout << " " << current_sum;
    }
    cout << endl;
    return 0;
}
