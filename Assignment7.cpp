#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void helper(const vector<int>& nums, int target, int index, int current_sum, vector<int>& possible_ans, vector<vector<int>>& result) {
    if (current_sum == target) {
        result.push_back(possible_ans);
        return;
    }

    for (int i = index; i < nums.size(); i++) {
        // Skip duplicates: If the current number is the same as the previous number at the same recursive level
        if (i > index && nums[i] == nums[i - 1]) continue;

        if (nums[i] + current_sum > target) break;

        possible_ans.push_back(nums[i]);
        helper(nums, target, i + 1, current_sum + nums[i], possible_ans, result);
        possible_ans.pop_back();
    }
}

vector<vector<int>> find_subset(vector<int> nums, int target) {
    sort(nums.begin(), nums.end());
    vector<int> possible_ans;
    vector<vector<int>> result;
    helper(nums, target, 0, 0, possible_ans, result);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 5, 6, 8};
    int target = 9;

    vector<vector<int>> subsets = find_subset(nums, target);

    if (!subsets.empty()) {
        cout << "Subsets with the target sum:" << endl;
        for (const auto& subset : subsets) {
            for (int num : subset) {
                cout << num << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No valid subsets found." << endl;
    }

    return 0;
}
