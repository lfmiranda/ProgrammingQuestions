#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& A) {
    int N = (int)A.size();
    int q = 0; // index of the last distinct element found

    for (int p = 0; p < N; p++) {
        if (p == 0 || A[p - 1] != A[p]) { // if a distinct element was found
            A[q] = A[p];
            q++;
        }
    }

    // "cut" the end of the array in order to remove useless/repeated elements from it
    while (N > q) {
        A.pop_back();
        N--;
    }

    return q;
}

void removeDuplicatesTester() {
    vector<int> A = {1, 1, 1, 3, 5, 7, 7, 9, 9};
    removeDuplicates(A);
}
