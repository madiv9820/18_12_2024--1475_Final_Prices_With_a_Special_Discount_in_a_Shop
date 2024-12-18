#include <vector>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        // Initialize a stack to store the indices of prices that have not yet found a discount
        stack<int> st;

        // Iterate through each price in the list by index
        for(int index = 0; index < prices.size(); ++index) {
            
            // While the stack is not empty and the current price is smaller than or equal
            // to the price at the index stored at the top of the stack, apply the discount
            while(st.size() && prices[index] <= prices[st.top()]) {
                // Apply the discount: subtract the current price from the price at the index in the stack
                prices[st.top()] -= prices[index];
                // Pop the index from the stack because the discount has been applied
                st.pop();
            }

            // Push the current index onto the stack because we haven't found a discount for it yet
            st.push(index);
        }

        // Return the modified prices list after applying the discounts
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