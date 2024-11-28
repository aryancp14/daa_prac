#include <bits/stdc++.h>
using namespace std ;

int binarySearch(const std::vector<int>& arr, int left, int right, int key) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) 
            return mid;
        if (arr[mid] > key) 
            return binarySearch(arr, left, mid - 1, key);
        return binarySearch(arr, mid + 1, right, key);
    }
    return -1;
}

int main() {
    std::vector<int> arr;
    int n = 5000, key;
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < n; i++) 
    {
        arr.push_back(rand() % 10000);
    }
    std::sort(arr.begin(), arr.end());
    std::cout << "Array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "\nEnter the key to search: ";
    std::cin >> key;
    int result = binarySearch(arr, 0, arr.size() - 1, key);
    if (result != -1) {
        std::cout << "Element found at index " << result << std::endl;
    } else {
        std::cout << "Element not found in the array" << std::endl;
    }
    return 0;
}
