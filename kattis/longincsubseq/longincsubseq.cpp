#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;

vector<int> longincsubseq(vector<int> vals) {

    // Stores predecessor index
    vector<int> predecessor = vector<int>(vals.size());

    // Stores k s.t vals[k] is the smallest ending value of a k 
    // long increasing subsequence
    vector<int> indices = vector<int>(vals.size() + 1);
    int max_len {};

    for (int i = 0; i < vals.size(); ++i) {
        // Binary search
        // Find the longest found subsequnce to which we can append the vals[i]
        int low {1};
        int high {max_len};
        while (low <= high) {
            int mid = ceil((low+high)/2);
            if (vals[indices[mid]] < vals[i]) {
                low = mid+1; 
            }
            else {
                high = mid-1;
            }
        }

        // Low-1 is length of longest prefix which we can extend with vals[i]
        int new_length {low};

        // Set predecessor to i
        predecessor[i] = indices[new_length - 1];
        indices[new_length] = i;

        // Rememeber if this was better solution
        if (new_length > max_len) {
            max_len = new_length;
        }
    }

    // Construct answer
    vector<int> res = vector<int>(max_len);
    int k = indices[max_len];

    for (int i {max_len-1}; i >= 0; --i) {
        res[i] = k;
        k = predecessor[k];
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Insert code here
    int N;
    while (cin >> N) {
       vector<int> vals {}; 
       for (int i = 0; i < N; ++i) {
          int elem; 
          cin >> elem;
          vals.push_back(elem);
       }

       vector<int> res {longincsubseq(vals)};
       cout << res.size() << endl;
       copy(begin(res), end(res), ostream_iterator<int>{cout, " "});
       cout << endl;
    }

    return 0;
}
