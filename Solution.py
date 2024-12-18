from typing import List

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