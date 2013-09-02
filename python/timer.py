def countdown(number_input):
	seconds = 59
	while number_input is not 0:
		while seconds is not -1:
			print(str(number_input) + ":" + str(seconds))
			seconds = seconds - 1
		number_input = number_input - 1
		
