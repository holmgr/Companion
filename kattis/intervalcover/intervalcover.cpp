#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;

struct Interval {
    double lower;
    double upper;

    Interval (double lower, double upper): lower {lower}, upper {upper} {};
};

struct IndexedInterval : public Interval {
    int index; 

    IndexedInterval (double lower, double upper, int index): Interval{lower, upper}, index{index} {};
};

unordered_set<int> interval_cover(Interval target, vector<IndexedInterval> availableIntervals) {

    sort(begin(availableIntervals), end(availableIntervals), [](Interval a, Interval b) {
        return a.upper > b.upper;
    });

    unordered_set<int> indices {};

    double current_end = target.lower;
    do {
        // Find first interval begining before current start not already used
        auto next_itr {find_if(begin(availableIntervals), end(availableIntervals), 
                [&current_end, &indices](IndexedInterval const & inter) {
            return inter.lower <= current_end && indices.find(inter.index) == end(indices);
        })};
        
        // No overlapping interval found
        if (next_itr == end(availableIntervals)) {
            return unordered_set<int>{};
        }

        indices.insert(next_itr->index);
        current_end = next_itr->upper;
    } while (current_end < target.upper);

    return indices;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Insert code here
    double A, B;
    while (cin >> A >> B) {
        Interval target = Interval { A, B };
        
        vector<IndexedInterval> ixs {};
        
        int N;
        cin >> N;
        for (int i = 0; i < N; ++i) {
           double a, b; 
           cin >> a >> b;
           IndexedInterval ix = IndexedInterval { a, b, i };
           ixs.push_back(ix);
        }

        unordered_set<int> cover { interval_cover(target, ixs) };
        if (cover.size() != 0) {
            cout << cover.size() << endl;
            copy(begin(cover), end(cover), ostream_iterator<int>{cout, " "});
            cout << endl;
        }
        else {
            cout << "impossible" << endl;
        }
    }

    return 0;
}
