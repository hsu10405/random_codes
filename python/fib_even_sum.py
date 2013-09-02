#writing fibonacci series out first
#fib1 = 1
#fib2 = 2 #starting condition

def fib_series():
	even_sum = 0
	fib1, fib2 = 0, 1
	while fib2 <= (4*pow(10, 6)):
		print(fib1)
		if fib2 % 2 == 0:
			even_sum += fib2
		fib1, fib2 = fib2, fib1+fib2
		
	return even_sum

#main
total_sum = fib_series()
print(total_sum)