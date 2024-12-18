#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        // Get the size of the prices vector
        int n = prices.size();
        
        // Iterate through each price in the list (outer loop)
        for(int i = 0; i < n; ++i) {
            // For each price[i], check subsequent prices[j] (inner loop)
            for(int j = i + 1; j < n; ++j) {
                // If a price[j] is less than or equal to price[i], apply the discount
                if(prices[i] >= prices[j]) {
                    // Subtract the discount price[j] from price[i]
                    prices[i] -= prices[j];
                    // After applying the discount, no need to check further prices for current i
                    break;
                }
            }
        }
        
        // Return the modified prices vector after discounts
        return prices;
    }
};

int main() {
    vector<vector<int>> inputs = {{8,4,6,2,3},{1,2,3,4,5},{10,1,1,6}};
    vector<vector<int>> outputs = {{4,2,4,2,3},{1,2,3,4,5},{9,0,1,6}};
    Solution sol;

    for(int i = 0; i < inputs.size(); ++i) {
        vector<int> result = sol.finalPrices(inputs[i]);
        bool match = true;
        for(int j = 0; j < result.size(); ++j)
            if(result[j] != outputs[i][j]) { match = false; break; }
        
        cout << (match ? "true":"false") << endl;
    }
}