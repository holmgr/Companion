#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;


unsigned long long calc_anger(vector<unsigned long long>& wishes, long total_candy)
{
    sort(begin(wishes), end(wishes));
    //copy(begin(wishes), end(wishes), ostream_iterator<long>{cout, ", "});

    // Only one index
    if (wishes.size() < 2) {
        return pow(wishes[0]-total_candy, 2);
    }

    // Split
    int i = 0;
    unsigned long long result = 0;
    bool all_equal = true;

    // Start second to last index
    for (i = wishes.size() -2; i >= 0; --i) {
        unsigned long long curr { wishes[i] };
        unsigned long long right { wishes[i+1] };
        size_t num_to_right { wishes.size() - i - 1 };

        // Can not lower to current
        if (total_candy <= (right - curr)*(num_to_right)) {
            unsigned long long lowered_to = right - (total_candy / num_to_right);
            result +=
                (lowered_to*lowered_to) * ((num_to_right) - (total_candy % (num_to_right)))
                + (lowered_to -1)*(lowered_to -1) * (total_candy % (num_to_right));
            all_equal = false;
            break;
        }
        total_candy -= (right - curr)*(num_to_right);
    }

    if (total_candy != 0 && all_equal) {
        // TODO: Handle all values equal
        unsigned long long elem { wishes[0] };
        unsigned long long lowered_to = elem - (total_candy / wishes.size());
        result = (lowered_to*lowered_to) * (wishes.size() - (total_candy % wishes.size()))
                + (lowered_to -1)*(lowered_to-1) * (total_candy % wishes.size());
        return result;
    }

    for (int j = 0; j <= i; ++j ) {
        result += wishes[j]*wishes[j];
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Insert code here
    unsigned long long M, N;

    cin >> M >> N;

    vector<unsigned long long> wishes;
    long long wish;
    for (int i = 0; i < N; ++i) {
        cin >> wish;
        wishes.push_back(wish);
    }
    cout << calc_anger(wishes, M) << endl;
    return 0;
}
