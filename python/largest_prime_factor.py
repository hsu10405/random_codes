def largest_prime(number):
	for divisor in reversed(range(1, number)):
		if (number // divisor) == (number / divisor):
			largest_prime(divisor)
		else:
			return divisor
			
prime = largest_prime(600851475143)
print(prime)