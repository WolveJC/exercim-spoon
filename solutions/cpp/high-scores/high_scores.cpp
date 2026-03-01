#include "high_scores.h"

using namespace std;

namespace arcade {

    vector<int> HighScores::list_scores() const {
        return scores_;
    }

    int HighScores::latest_score() const {
        return scores_.back();
    }

    int HighScores::personal_best() const {
        if (scores_.empty()) return 0;
        return *max_element(scores_.begin(), scores_.end());
    }

    vector<int> HighScores::top_three() const {
        vector<int> sorted_scores = scores_;
        sort(sorted_scores.begin(), sorted_scores.end(), greater<int>());
        
        int count = min((int)sorted_scores.size(), 3);
        return vector<int>(sorted_scores.begin(), sorted_scores.begin() + count);
    }

}