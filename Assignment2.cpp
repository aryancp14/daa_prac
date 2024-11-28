#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

int qsp(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] < pivot && i < high) i++;
        while (arr[j] > pivot && j > low) j--;
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[j], arr[low]);

    return j;
}

void qs(int arr[], int low, int high) {
    if (low < high) {
        int p = qsp(arr, low, high);
        qs(arr, low, p - 1);
        qs(arr, p + 1, high);
    }
}

void mst(int arr[], int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = 0; i < temp.size(); i++) {
        arr[low + i] = temp[i];
    }
}

void ms(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        ms(arr, low, mid);
        ms(arr, mid + 1, high);
        mst(arr, low, mid, high);
    }
}

int main() {
    int arr1[] = {5, 2, 1, 4, 3};
    int arr2[] = {5, 2, 1, 4, 3};
    int n = 5;

    auto start = high_resolution_clock::now();
    qs(arr1, 0, n - 1);
    auto end = high_resolution_clock::now();
    auto quickSortTime = duration_cast<microseconds>(end - start).count();

    start = high_resolution_clock::now();
    ms(arr2, 0, n - 1);
    end = high_resolution_clock::now();
    auto mergeSortTime = duration_cast<microseconds>(end - start).count();

    cout << "Sorted Array (Quick Sort): ";
    for (int i = 0; i < n; i++) cout << arr1[i] << " ";
    cout << endl;
    cout << "Time taken by Quick Sort: " << quickSortTime << " microseconds" << endl;

    cout << "Sorted Array (Merge Sort): ";
    for (int i = 0; i < n; i++) cout << arr2[i] << " ";
    cout << endl;
    cout << "Time taken by Merge Sort: " << mergeSortTime << " microseconds" << endl;

    return 0;
}
