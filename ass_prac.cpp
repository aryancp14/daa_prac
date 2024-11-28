// Fractional
#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int weight, value;
    double valueDensity;
};

bool compare(Item a, Item b) {
    return a.valueDensity > b.valueDensity;
}

int main() {
    int W = 20;
    Item items[] = {
        {3, 10}, {5, 20}, {5, 21}, {8, 30}, {4, 16}
    };

    int n = sizeof(items) / sizeof(items[0]);

    for (int i = 0; i < n; i++) {
        items[i].valueDensity = (double)items[i].value / items[i].weight;
    }

    sort(items, items + n, compare);


    double maxValue = 0;
    int currentWeight = 0;

    cout << "\nSelected items:\n";

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= W) {
            currentWeight += items[i].weight;
            maxValue += items[i].value;
           
        } else {
            int remainingWeight = W - currentWeight;
            maxValue += items[i].valueDensity * remainingWeight;
            break;
        }
    }

    cout << "\nTotal value in the knapsack = " << maxValue << endl;

    return 0;
}




// N

#include <iostream>
#include <vector>
using namespace std;

void printSolution(const vector<vector<int>>& board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl; 
}

bool isSafe(const vector<vector<int>>& board, int row, int col) {
    for (int i = 0; i < col; i++) {
        if (board[row][i])      return false;
        
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])     return false;
        
    }

    for (int i = row, j = col; i < board.size() && j >= 0; i++, j--) {
        if (board[i][j])     return false;
        
    }

    return true;
}

bool solveNQUtil(vector<vector<int>>& board, int col) {
    if (col >= board.size()) {
        printSolution(board);
        return true;
    }

    bool res = false;
     
    for (int i = 0; i < board.size(); i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1; 
           
            res = solveNQUtil(board, col + 1) || res;

            board[i][col] = 0;
        }
    }

    return res;
}

void solveNQ(int N) {
    vector<vector<int>> board(N, vector<int>(N, 0));
   
    if (!solveNQUtil(board, 0)) {
        cout << "Solution does not exist" << endl; 
    }
}

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;
    solveNQ(N);
    return 0;
}


// SS
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


// TSP

#include <bits/stdc++.h>
using namespace std;

int tsp(const vector<vector<int>>& graph, vector<bool>& visited, int n, int current_pos, int cost, int count, int ans, vector<int>& path, vector<int>& best_path) {
    if (count == n && graph[current_pos][0] > 0) {
        int total_cost = cost + graph[current_pos][0];
        if (total_cost < ans) {
            ans = total_cost;
            best_path = path;
            best_path.push_back(0);
        }
        return ans;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[current_pos][i] > 0) {
            visited[i] = true;
            path.push_back(i);
            ans = tsp(graph, visited, n, i, cost + graph[current_pos][i], count + 1, ans, path, best_path);
            visited[i] = false;
            path.pop_back();
        }
    }

    return ans;
}

int main() {
    int n = 4;
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    vector<bool> visited(n, false);
    int ans = INT_MAX;
    vector<int> path = {0};
    vector<int> best_path;
    visited[0] = true;

    ans = tsp(graph, visited, n, 0, 0, 1, ans, path, best_path);

    cout << "The minimum traveling cost is: " << ans << endl;
    cout << "The optimal route is: ";
    for (int city : best_path) {
        cout << city << " -> ";
    }
    cout << "0" << endl;

    return 0;
}
