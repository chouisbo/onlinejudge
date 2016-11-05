"""
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]


buy[i]  买进操作的最大利润。它需要考虑的是，第i天是否买进。（手上没有stock在第i天所能获得的最大利润）
sell[i] 卖出操作的最大利润。它需要考虑的是，第i天是否卖出。（手上有stock在第i天所能获得的最大利润）

所以，显然有状态转移方程:

buy[i]  = max(buy[i-1] , sell[i-2] – prices[i])  // 休息一天在买入，所以是sell[i-2]在状态转移
sell[i] = max(sell[i-1], buy[i-1] + prices[i])
最后显然有sell[n-1] > buy[n-1] 所以我们返回sell[n-1]
"""

class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if not prices or len(prices) < 2: return 0
        n = len(prices)
        buy, sell = [0] * n, [0] * n
        buy[0] = -prices[0]  # 第0天买进股票, 需要花费 prices[0](第0天的股价)
        buy[1] = max(-prices[0], -prices[1]) # 第0-1天买进股票，需要最少花费 prices[0]与prices[1]中的较小值
        sell[1] = max(0, prices[1] - prices[0]) # 第1天卖出的最大收益
        for i in xrange(2, n):
            buy[i] = max(sell[i - 2] - prices[i], buy[i - 1])
            sell[i] = max(buy[i - 1] + prices[i], sell[i - 1])
        return sell[n - 1]

