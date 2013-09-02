number = 1
total_sum = 0
while number < 1000:
	if ((number // 3) == (number / 3) or ((number // 5) == (number / 5))):
		total_sum += number
		print("number is " + str(number))
		print("sum is now " + str(total_sum))
	number += 1
	
print(total_sum)
print(number)