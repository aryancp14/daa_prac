
#include <bits/stdc++.h>
using namespace std;

// Function to solve the unbounded knapsack problem
int knapsackUtil(vector<int>& wt, vector<int>& val, int ind, int W, vector<vector<int>>& dp) {
    if (ind == 0) {
        return (W / wt[0]) * val[0];
    }
    
    if (dp[ind][W] != -1)
        return dp[ind][W];
        
    int notTaken = 0 + knapsackUtil(wt, val, ind - 1, W, dp);
    
    int taken = INT_MIN;
    if (wt[ind] <= W)
        taken = val[ind] + knapsackUtil(wt, val, ind, W - wt[ind], dp);
        
    return dp[ind][W] = max(notTaken, taken);
}

int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
    vector<vector<int>> dp(n, vector<int>(W + 1, -1)); // Create a DP table
    
    return knapsackUtil(wt, val, n - 1, W, dp);
}

int main() {
    vector<int> wt = {2, 4, 6}; // Weight of items
    vector<int> val = {5, 11, 13}; // Value of items
    int W = 10; // Weight capacity of the knapsack
    int n = wt.size(); // Number of items
    
    // Call the function to calculate and output the maximum value the thief can steal
    cout << "The Maximum value of items the thief can steal is " << unboundedKnapsack(n, W, val, wt) << endl;

    return 0; // Return 0 to indicate successful program execution
}