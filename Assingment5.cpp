// DAA Assn 05
// Write a program for analysis of quick sort by using deterministic and randomized variant


#include <bits/stdc++.h>
using namespace std;


int partition(vector<int> &a, int l, int r) {
    int p = a[r];
    int i = l - 1;

    for (int j = l; j < r; j++) {
        if (a[j] <= p) {
            i = i + 1;
            swap(a[i], a[j]);
        }
    }
    
    swap(a[i + 1], a[r]);
    return i + 1;
}


int partition_rand(int l, int r, vector<int> &a) {
    int pivot = l + rand() % (r - l);
    swap(a[r], a[pivot]);
    return partition(a, l, r);
}


void qsort(int l, int r, vector<int> &a) {
    if (l < r) {
        int pi = partition_rand(l, r, a);
        qsort(l, pi - 1, a);
        qsort(pi + 1, r, a);
    }
    cout << "qsort ";
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}


int randomized_partition(vector<int> &arr, int low, int high) {
    srand(time(0));
    int random_index = low + rand() % (high - low + 1);
    swap(arr[random_index], arr[high]);
    return partition(arr, low, high);
}


void randomized_quicksort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivot_index = randomized_partition(arr, low, high);
        randomized_quicksort(arr, low, pivot_index - 1);
        randomized_quicksort(arr, pivot_index + 1, high);
    }
    cout << "randomized_quicksort ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        arr.push_back(rand() % 1000 + 1);
    }
    cout << "Generated Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Analyze deterministic Quick Sort
    clock_t start_time = clock();
    qsort(0, n - 1, arr);
    clock_t end_time = clock();
    double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;
    cout << "Deterministic Quick Sort took " << fixed << time_taken << " seconds" << endl;

    // Analyze randomized Quick Sort
    clock_t start_time2 = clock();
    randomized_quicksort(arr, 0, n - 1);
    clock_t end_time2 = clock();
    double time_taken2 = double(end_time2 - start_time2) / CLOCKS_PER_SEC;
    cout << "Randomized Quick Sort took " << fixed << time_taken2 << " seconds" << endl;

    return 0;
}