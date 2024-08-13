#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    string crackSafe(int n, int k) {
        unordered_set<string> seen;
        string ans;


        dfs(string(n - 1, '0'), k, seen, ans, n);


        return ans + string(n - 1, '0');
    }

private:
    void dfs(const string& node, int k, unordered_set<string>& seen, string& ans, int n) {
        for (int x = 0; x < k; ++x) {
            string nei = node + to_string(x);
            if (!seen.count(nei)) {
                seen.insert(nei);
                dfs(nei.substr(1), k, seen, ans, n);
                ans += to_string(x);
            }
        }
    }
};

int main() {
    int n = 2; 
    int k = 2; 

    Solution solution;
    string result = solution.crackSafe(n, k);
    cout << "The minimum length sequence to crack the safe: " << result << endl;

    return 0;
}
