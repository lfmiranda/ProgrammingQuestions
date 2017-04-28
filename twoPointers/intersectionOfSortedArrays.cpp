#include <iostream>
#include <vector>

using namespace std;

vector<int> intersect(const vector<int>& A, const vector<int>& B) {
    vector<int> intersection;

    int N1 = A.size();
    int N2 = B.size();

    int i = 0, j = 0;

    while (i < N1 && j < N2) {
        if (A[i] < B[j]) {
            i++;
        } else if (A[i] > B[j]) {
            j++;
        } else {
            intersection.push_back(A[i]);
            i++;
            j++;
        }
    }

    return intersection;
}
