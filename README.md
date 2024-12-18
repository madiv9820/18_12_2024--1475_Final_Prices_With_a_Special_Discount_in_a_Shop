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