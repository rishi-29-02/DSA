fun maxProfit(prices: IntArray): Int {
        var ans = 0
        var min = prices[0]

        for (i in 1 until prices.size) {
            if (prices[i]>min) {
                ans = maxOf(ans, prices[i]-min)
            } else {
                min = minOf(min, prices[i])
            }
        }
        return ans
    }
