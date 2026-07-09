class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        best_buy = prices[0]
        best_profit = 0
        for i in range(1, len(prices)):
            
            this_price = prices[i]
            this_profit = max(this_price - best_buy, 0)
            best_profit = max(best_profit, this_profit)
            
            best_buy = min(best_buy, this_price)

        return best_profit