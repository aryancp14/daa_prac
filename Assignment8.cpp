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
