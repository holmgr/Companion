#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;
int max_height = INT_MAX;

pair<int, string> rec_spider(
        vector<unsigned int> const & stages, 
        size_t i, 
        int remaining_sum, 
        int highest_seen = 0, 
        int height = 0
        )
{
    if (i >= stages.size()) {
        if (height == 0) {
           max_height = min(highest_seen, max_height); 
        }
        return height == 0 ? make_pair(height, "") : make_pair(INT_MAX, "IMPOSSIBLE");
    }
    else if (height < 0 || height > remaining_sum || height > max_height || highest_seen > max_height) {
        return make_pair(INT_MAX, "IMPOSSIBLE"); }
    else {
        // INT_MAX
        unsigned int const stage = stages[i];
        auto down = rec_spider(stages, i+1, remaining_sum-stage, max(height, highest_seen), height-stage);
        auto up = rec_spider(stages, i+1, remaining_sum-stage, max(height, highest_seen), height+stage);

        if (up.first < down.first && up.second != "IMPOSSIBLE") {
            return make_pair(max(height, up.first), "U" + up.second);
        }
        else if (down.second != "IMPOSSIBLE") {
            return make_pair(max(height, down.first), "D" + down.second);
        }
        else {
            return make_pair(INT_MAX, "IMPOSSIBLE");
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Insert code here
    int test_cases;
    vector<unsigned int> stages;
    cin >> test_cases;
    for (int i = 0; i < test_cases; ++i) {
        max_height = INT_MAX;
        int num_stages;
        cin >> num_stages;
        stages.clear();
        stages.reserve(num_stages);
        for (int j = 0; j < num_stages; ++j) {
            unsigned int stage;
            cin >> stage;
            stages.push_back(stage);
        }
        int sum = accumulate(begin(stages), end(stages), 0);
        if (sum % 2 != 0) {
            cout << "IMPOSSIBLE" << endl;
        }
        else {
            cout << rec_spider(stages, 0, sum).second << endl;
        }
    }

    // TODO: Add 2 meters?
    return 0;
}
