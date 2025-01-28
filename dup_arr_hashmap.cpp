#include <bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(vector<int> &arr) {

    // Step 1: Create an empty unordered map to store
    // element frequencies
    int n = arr.size();
    unordered_map<int, int> freqMap;
    vector<int> result;

    // Step 2: Iterate through the array and count
    // element frequencies
    for (int i = 0; i < n; i++) {
        freqMap[arr[i]]++;
    }

    // Step 3: Iterate through the hashmap to find duplicates
    for (auto &entry : freqMap) {
        if (entry.second > 1) {
            result.push_back(entry.first);
        }
    }

    // Step 4: If no duplicates found, add -1 to the result
    if (result.empty()) {
        result.push_back(-1);
    }

    // Step 6: Return the result vector containing
    // duplicate elements or -1
    return result;
}

int main() {
    vector<int> arr;
    int n;
    cout << "Enter the number of elements in the array: ";
    cin>>n;
    cout << "Enter the elements of the array: ";
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    vector<int> duplicates = findDuplicates(arr);

    for (int element : duplicates) {
        cout << element << " ";
    }

    return 0;
}
