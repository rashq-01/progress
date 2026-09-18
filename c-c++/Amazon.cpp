#include<bits/stdc++.h>

using namespace std;



class Solution {
public:
    string bestSegment = "-1";
    int bestReplications = INT_MAX;

    vector<int> requiredFreq = vector<int>(26, 0);
    vector<int> candidateFreq = vector<int>(26, 0);

    void help(string& candidate, int segmentSize) {

        // Base case
        if (candidate.size() == segmentSize) {

            int repetitions = 0;
            bool valid = true;

            // Check ALL 26 characters
            for (int i = 0; i < 26; i++) {

                if (requiredFreq[i] > 0) {

                    // Required character is absent
                    if (candidateFreq[i] == 0) {
                        valid = false;
                        break;
                    }

                    // ceil(required / available)
                    int needed =
                        (requiredFreq[i] + candidateFreq[i] - 1)
                        / candidateFreq[i];

                    repetitions = max(repetitions, needed);
                }
            }

            if (valid) {

                if (repetitions < bestReplications) {
                    bestReplications = repetitions;
                    bestSegment = candidate;
                }
                else if (repetitions == bestReplications) {
                    if (candidate < bestSegment) {
                        bestSegment = candidate;
                    }
                }
            }

            return;
        }

        // Generate all possible strings
        for (int i = 0; i < 26; i++) {

            candidate.push_back('a' + i);
            candidateFreq[i]++;

            help(candidate, segmentSize);

            candidateFreq[i]--;
            candidate.pop_back();
        }
    }

    string getSmallestBaseSegment(int segmentSize,string missingData) {

        // Frequency of missingData
        for (char ch : missingData) {
            requiredFreq[ch - 'a']++;
        }

        string candidate = "";

        help(candidate, segmentSize);

        return bestSegment;
    }
};


int main(){
    Solution* sl = new Solution;

    cout<<sl->getSmallestBaseSegment(2,"aaa");

    return 0;
}