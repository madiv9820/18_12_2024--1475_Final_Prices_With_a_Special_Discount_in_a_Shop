# [1475. Final Prices With a Special Discount in a Shop](https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop)

**Type:** Easy <br>
**Topics:** Array, Stack, Monotonic Stack <br>
**Companies:** Dream11, Google, Microsoft, Bloomberg 
<hr>

You are given an integer array `prices` where `prices[i]` is the price of the <code>i<sup>th</sup></code> item in a shop.

There is a special discount for items in the shop. If you buy the <code>i<sup>th</sup></code> item, then you will receive a discount equivalent to `prices[j]` where `j` is the minimum index such that `j > i` and `prices[j] <= prices[i]`. Otherwise, you will not receive any discount at all.

Return an integer `array` answer where `answer[i]` is the final price you will pay for the <code>i<sup>th</sup></code> item of the shop, considering the special discount.
<hr>

### Examples
- **Example 1:** <br>
**Input:** prices = [8,4,6,2,3] <br>
**Output:** [4,2,4,2,3] <br>
**Explanation:** <br>
For item 0 with price[0]=8 you will receive a discount equivalent to prices[1]=4, therefore, the final price you will pay is 8 - 4 = 4. <br>
For item 1 with price[1]=4 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 4 - 2 = 2. <br>
For item 2 with price[2]=6 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 6 - 2 = 4. <br>
For items 3 and 4 you will not receive any discount at all.

- **Example 2:** <br>
**Input:** prices = [1,2,3,4,5] <br>
**Output:** [1,2,3,4,5] <br>
**Explanation:** In this case, for all items, you will not receive any discount at all.

- **Example 3:** <br>
**Input:** prices = [10,1,1,6] <br>
**Output:** [9,0,1,6]
<hr>

### Constraints:
- `1 <= prices.length <= 500`
- `1 <= prices[i] <= 1000`

### Hints:
- Use brute force: For the ith item in the shop with a loop find the first position j satisfying the conditions and apply the discount, otherwise, the discount is 0.