#include <iostream>
#include <vector>

using namespace std;

vector<int> tusharsBirthdayBombs(int A, vector<int>& B){
    // updatedB will keep the set of friends that could be at the final answer and their index at the original vector
    vector<pair<int, int>> candidates;

    /*
     * Go through the list of friends and every time a friend sets a new low level of strength, add it to a vector.
     * The result is a vector in decresing order, representing the friends that can be part of the answer.
     */
    int highestStrength = numeric_limits<int>::max();
    for (int i = 0; i < B.size(); i++) {
        if (B[i] < highestStrength) {
            candidates.push_back({i, B[i]});
            highestStrength = B[i];
        }
    }

    int numCandidates = (int) candidates.size();
    int smaStrength = candidates[numCandidates - 1].second;
    int remainingRes = A;
    vector<int> ans;

    int i = 0;
    while (i < numCandidates) {
        bool canHit = remainingRes >= candidates[i].second; // check if the current friend can hit

        // check if adding the current friend would keep the answer's size
        bool keepAnswerSize = ((remainingRes - candidates[i].second) / smaStrength + 1) == (remainingRes/smaStrength);

        if (canHit && keepAnswerSize) {
            ans.push_back(candidates[i].first);
            remainingRes -= candidates[i].second;
        } else {
            i++;
        }
    }

    return ans;
}

void tusharsBirthdayBombsTester() {
    vector<int> B = {6, 8, 5, 4, 7};
    tusharsBirthdayBombs(11, B);
}
