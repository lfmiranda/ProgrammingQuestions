#include <iostream>
#include <vector>

using namespace std;

/*
 * - Problem:
 * Max Sum Contiguous Subarray
 *
 * - Problem description:
 * Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 */

int maxSumContiguousSubarray(const vector<int>& A) {
    if (A.empty()) return 0;

    int maxSum = numeric_limits<int>::lowest();
    int currSum = 0;

    for (int currVal : A) {
        currSum += currVal;

        maxSum = max(maxSum, currSum);
        if (currSum < 0) currSum = 0;
    }

    return maxSum;
}

void MaxSumContiguousSubarrayTester() {
    vector<int> A = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSumContiguousSubarray(A);
}

int main() {
    MaxSumContiguousSubarrayTester();
}
