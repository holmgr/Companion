#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;

bool is_tag(string word)
{
    return word.size() > 0 && word.substr(0, 1) == "<";
}

string solve_patterns(vector<string>& first, vector<string>& second)
{
    if (first.size() != second.size()) {
       return "-"; 
    }

    bool has_swapped = true;
    while (has_swapped) {
        has_swapped = false;

        unordered_map<string, string> tag_first;
        unordered_map<string, string> tag_second;

        // Build tags
        for (int i = 0; i < first.size(); ++i) {
            if (!is_tag(first[i]) && !is_tag(second[i]) && first[i] != second[i]) {
               return "-"; 
            }
            else if (is_tag(first[i]) && !is_tag(second[i])) {
               tag_first.insert({first[i], second[i]}); 
            }
            else if (!is_tag(first[i]) && is_tag(second[i])) {
               tag_second.insert({second[i], first[i]}); 
            }
        }

        for (int i = 0; i < first.size(); ++i) {
            if (is_tag(first[i]) && tag_first.find(first[i]) != tag_first.end()) {
                has_swapped = true;
                first[i] = tag_first.find(first[i])->second; 
            }
            if (is_tag(second[i]) && tag_second.find(second[i]) != tag_second.end()) {
                has_swapped = true;
                second[i] = tag_second.find(second[i])->second; 
            }
            
        }
    }

    string new_first, new_second;
    for (int i = 0; i < first.size(); ++i) {
        if (is_tag(first[i])) {
            new_first += "a ";
        }
        else {
            new_first += first[i] + " ";
        }
        if (is_tag(second[i])) {
            new_second += "a ";
        }
        else {
            new_second += second[i] + " ";
        }
    }
    if (new_first == new_second) {
       return new_first; 
    }
    return "-";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Insert code here
    int test_cases;
    cin >> test_cases;
    string dummy;
    getline(cin, dummy);

    vector<string> words_first;
    vector<string> words_second;
    for (int i = 0; i < test_cases; ++i) {
        words_first.clear();
        words_second.clear();
        string first_line, second_line;
        getline(cin, first_line);
        getline(cin, second_line);

        std::istringstream iss(first_line);
            std::copy(std::istream_iterator<std::string>(iss),
            std::istream_iterator<std::string>(),
            std::back_inserter(words_first));

        std::istringstream iss2(second_line);
            std::copy(std::istream_iterator<std::string>(iss2),
            std::istream_iterator<std::string>(),
            std::back_inserter(words_second));

        cout << solve_patterns(words_first, words_second) << endl;
    }

    return 0;
}

