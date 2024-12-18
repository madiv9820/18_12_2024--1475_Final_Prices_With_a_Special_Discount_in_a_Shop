- ## Approach 2:- Stack

    - ### Intuition
        The problem is to apply discounts to a list of prices where for each price, we check if there is a smaller or equal price that comes after it. If such a price exists, we subtract that price from the current price.

        The intuition behind the stack-based approach is to keep track of prices that haven't yet found a discount. As we traverse the list of prices, for each price, we look for a discount (a smaller or equal price) in the previous prices we've seen. We apply the discount as soon as we find it and then move on to the next price.

    - ### Approach
        1. **Stack for Indices**: Use a stack to store indices of the prices that haven't yet found a discount. The stack helps efficiently find the first smaller or equal price for each price.
        2. **Iterate Through Prices**: For each price:
            - While the stack is not empty and the current price is smaller than or equal to the price at the index stored at the top of the stack, apply the discount by subtracting the current price from the price at the index stored in the stack.
            - After applying the discount, pop the index from the stack.
        3. **Push Current Index**: After checking for discounts, push the current index onto the stack since we haven't found a discount for this price yet.
        4. **Return Result**: After processing all the prices, return the list with the final prices.

    - ### Steps:
        1. Initialize an empty stack.
        2. Iterate over the prices list by index.
        3. For each price, check if there is a smaller or equal price in the stack to apply the discount.
        4. If a discount is applied, update the price and pop the stack.
        5. Push the current index onto the stack.
        6. After the loop, return the modified prices list.

    - ### Code Implementation
        - **Python Solution**
            ```python3 []
            class Solution:
                def finalPrices(self, prices: List[int]) -> List[int]:
                    # Initialize an empty stack to store indices of the prices list
                    stack = []
                    
                    # Iterate through each price in the list by index
                    for index in range(len(prices)):
                        
                        # While the stack is not empty and the current price is smaller than or equal to
                        # the price at the index stored at the top of the stack, apply the discount
                        while len(stack) and prices[index] <= prices[stack[-1]]:
                            # Apply the discount by subtracting the current price from the price at the index in the stack
                            prices[stack[-1]] -= prices[index]
                            # Pop the index from the stack because the discount has been applied
                            stack.pop()
                        
                        # Push the current index onto the stack because we haven't found a discount for it yet
                        stack.append(index)
                    
                    # Return the modified prices list after applying the discounts
                    return prices
            ```
        - **C++ Solution**
            ```cpp []
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
            ```

    - ### Time Complexity
        - **$O(n)$**: Each index is pushed and popped from the stack exactly once. Therefore, the overall time complexity is linear, where **$n$** is the number of prices in the list.

    - ### Space Complexity
        - **$O(n)$**: The space complexity is linear because the stack can hold at most **$n$** indices in the worst case.