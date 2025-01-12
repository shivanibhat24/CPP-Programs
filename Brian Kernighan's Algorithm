// In this program, we count the total number of set bits in a number
//Using Brian Kernighan's Algorithm
#include <iostream>
using namespace std;

int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        n &= (n - 1); // Clear the rightmost set bit
        count++;
    }
    return count;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Number of set bits: " << countSetBits(num) << endl;
    return 0;
}
