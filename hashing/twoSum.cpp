#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(const vector<int>& A, int target) {
    vector<int> ans;

    int N = (int) A.size();
    if (N < 2) return ans;

    unordered_map<int, int> map; // mapping from numbers in the array to their index

    for (int i = 0; i < N; i++) {
        int wanted = target - A[i];

        if (map.find(wanted) != map.end()) {
            ans.push_back(map[wanted] + 1);
            ans.push_back(i + 1);
            break;
        }

        if (map.find(A[i]) == map.end()) map[A[i]] = i;
    }

    return ans;
}

void twoSumTester() {
    vector<int> A = {2, 7, 11, 15, 9, 3, 1};

    twoSum(A, 10);
}
