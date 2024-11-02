fun maxSubArray(nums: IntArray): Int {
        var ans = Int.MIN_VALUE
        var sum = 0

        nums.forEach{ i-> 
            sum+=i
            ans = maxOf(ans, sum)
            if(sum<0) sum=0
        }

        return ans
    }
