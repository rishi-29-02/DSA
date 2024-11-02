fun productExceptSelf(nums: IntArray): IntArray {
        var pro = 1
        var cnt = 0
        nums.forEach{ i-> 
            if (i==0) cnt++
            else pro = pro * i
        }

        var ans = intArrayOf()

        if (cnt>1) {
            nums.forEach { i -> 
                ans+=0
            }
        } else if (cnt==1) {
            nums.forEach { i -> 
                if (i==0) {
                    ans+=pro
                } else {
                    ans+=0
                }
            }
        } else {
            nums.forEach{ i-> 
                ans+=(pro/i)
            }
        }

        return ans
    }
