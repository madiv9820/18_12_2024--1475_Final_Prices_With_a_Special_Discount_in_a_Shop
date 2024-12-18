from typing import List

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