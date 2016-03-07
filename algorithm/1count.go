package main

import (
	"fmt"
)

func count1(n int) int {
	pre := 0
	count := 0
	cur := 0
	next := 0
	i := 1
	for n/i > 0 {
		cur = (n / i) % 10
		pre = (n / i / 10)
		next = 0
		if i > 1 {
			next = n % i
		}

		if cur == 0 {
			count += pre * i
		} else if cur == 1 {
			count = pre*i + next + 1
		} else {
			count += (pre + 1) * i
		}

		i *= 10
	}

	return count
}

func count(i int) int {
	if i == 0 {
		return 0
	} else if i < 10 {
		return 1
	}

	power := 1
	for tmpI := i; tmpI > 9; tmpI = tmpI / 10 {
		power *= 10
	}

	longest := i / power

	if longest == 1 {
		return count(longest*power-1) + count(i-power*longest) + i - power*longest + 1
	}

	return longest*count(power-1) + count(i-power*longest) + power

}
func main() {
	fmt.Println(count(232))
	fmt.Println(count1(232))
}
