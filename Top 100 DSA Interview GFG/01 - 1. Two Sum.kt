fun twoSum(nums: IntArray, target: Int): IntArray {
        var map:HashMap<Int, Int> = hashMapOf()

        for(i in 0 until nums.size) {
            val rem = target - nums[i]
            if(map.contains(rem)) {
                return intArrayOf(i, map[rem]!!)
            } else {
                map[nums[i]] = i
            }
        }
        return intArrayOf()
    }
