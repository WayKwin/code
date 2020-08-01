package main

import (
	"fmt"
	"strconv"
)
func numDecodings(s string) int {
	if len(s) == 0 || s[0] == '0' {
		return 0
	}
	dp := make([]int,len(s))
	dp[0] = 1
	for i := 1; i < len(s); i++{
		if s[i] == '0'{
			num := int(s[i-1] - '0')
			if num == 1 || num == 2{
				dp[i] = dp[i-1]
			}else{
				return 0
			}
		} else if s[i - 1] == '0' {
			dp[i] = dp[i-1]
		} else if i + 1 < len(s) && s[i+1] == '0'{
			if s[i] == '1' || s[i] == '2'{
				dp[i] = dp[i-1]
			}
		}else if  num,_ :=strconv.ParseInt(fmt.Sprintf("%c%c",s[i-1],s[i]),10,8); num <= 26{
			dp[i] = dp[i-1] + 1;
 		}else{
			 dp[i] = dp[i-1]
		 }
	}
	return dp[len(s)-1]
}
func main(){
	fmt.Println(numDecodings("1100"))
}