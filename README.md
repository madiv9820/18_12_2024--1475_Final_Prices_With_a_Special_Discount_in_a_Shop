# [1475. Final Prices With a Special Discount in a Shop](https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop) (All Approaches)

- ## Approach 1:- Brute Force

    - ### Intuition
        The task is to modify a list of prices where for each price, we check subsequent prices in the list to see if any of them are smaller or equal. If such a price exists, we apply the discount by subtracting that price from the current price.

        The intuition is that for each price at index `i`, we need to find the first price at index `j` (where `j > i`) that is smaller or equal to the price at `i`. Once we find such a price, we subtract it from the price at `i`. This can be thought of as finding the "next smaller or equal element" in a sublist and applying the discount.

    - ### Approach
        1. **Iterate over each price in the list**: For each price at index `i`, we will check all subsequent prices.
        2. **Find the first smaller or equal price**: For each price at index `i`, iterate through subsequent prices at index `j > i` and check if `prices[j]` is smaller or equal to `prices[i]`.
        3. **Apply the discount**: If we find such a price, subtract it from the current price `prices[i]`.
        4. **Return the modified list**: After all iterations, return the updated list of prices.

    - ### Steps:
        1. **Outer Loop (i)**: Traverse through each price starting from the first price.
        2. **Inner Loop (j)**: For each price `i`, look at the prices after it and find the first smaller or equal price.
        3. **Apply Discount**: Once we find a valid price `j`, apply the discount by subtracting `prices[j]` from `prices[i]` and break out of the inner loop.
        4. **Return Result**: After processing all prices, return the final list.

    - ### Code Implementation
        - **Python Solution**
            ```python3 []
            class Solution:
                def finalPrices(self, prices: List[int]) -> List[int]:
                    # Get the length of the prices list
                    n = len(prices)
                    
                    # Iterate through each price in the list
                    for i in range(n):
                        # For each price, look at the prices after it to find the first one that's less than or equal to the current price
                        for j in range(i + 1, n):
                            # If a price[j] is less than or equal to price[i], apply the discount
                            if prices[i] >= prices[j]:
                                # Subtract the discount (price[j]) from price[i]
                                prices[i] -= prices[j]
                                # After applying the discount, no need to check further prices
                                break
                    
                    # Return the modified list of prices after discounts
                    return prices
            ```
        - **C++ Solution**
            ```cpp []
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
            ```

    - ### Time Complexity
        - **Outer Loop**: The outer loop runs **$n$** times, where **$n$** is the number of prices in the list.
        - **Inner Loop**: For each price `i`, the inner loop checks subsequent prices (i.e., the number of checks decreases as `i` increases). In the worst case, each price might require checking every other price that comes after it.
        - Thus, the time complexity is **$O(n^2)$**, where **$n$** is the number of elements in the list.

    - ### Space Complexity
        - The space complexity is **$O(1)$** because we are modifying the input list in place and not using any additional data structures that scale with the input size. We are only using a constant amount of extra space for the loop variables.

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