#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void helper(vector<int> &nums, vector<vector<int>> &res, vector<int> &com, vector<bool> flag) {
    if (find(flag.begin(), flag.end(), false) == flag.end()) {
        res.push_back(com);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (flag[i] == false) {
            com.push_back(nums[i]);
            flag[i] = true;
            helper(nums, res, com, flag);
            flag[i] = false;
            com.pop_back();
        }
    }
}

int main(int argc, char**argv) {
    vector<int> nums{1, 2, 3, 4, 5, 6, 7};
    vector<vector<int>> res;
    vector<int> com;
    vector<bool> flag(nums.size(), false);
    helper(nums, res, com, flag);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
