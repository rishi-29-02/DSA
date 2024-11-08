fun findDuplicates(nums: IntArray): List<Int> {
        var ans = mutableListOf<Int>()

        for (i in 0 until nums.size) {
            val pos = abs(nums[i]) - 1
            if(nums[pos] > 0) {
                nums[pos]*=-1
            } else {
                ans.add(abs(nums[i]))
            }
        }
        return ans
    }
