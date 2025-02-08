#include <iostream>
#include <queue>
using namespace std;

int josephus(int n, int k) {
    // Create a queue and populate it with people numbered from 1 to n
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    // Simulate the elimination process
    while (q.size() > 1) {
        // Move the first (k-1) people to the back of the queue
        for (int i = 1; i < k; i++) {
            int front = q.front();
            q.pop();
            q.push(front);
        }
        // Eliminate the k-th person
        q.pop();
    }

    // The last remaining person is the survivor
    return q.front();
}

int main() {
    int n, k;
    cout << "Enter the number of people (n): ";
    cin >> n;
    cout << "Enter the elimination step (k): ";
    cin >> k;

    int survivor = josephus(n, k);
    cout << "The survivor is: " << survivor << endl;

    return 0;
}
