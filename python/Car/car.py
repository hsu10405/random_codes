class Car(object):
	"Car barebone structure"
	
	def __init__(self, brand):
		print("you just made a car")
		self.brand = brand
		self.gas_tank = 0
		self.car_key = 1
		
	def __str__(self):
		return "Car is a " + self.brand + "\n"

class Maintainance():
	def start(key):
		if key == 1:
			print("Your car is now running.\n")
			return 0 #Means you don't have the key with you any more.
		elif car_key == 0:
			print("Where is your key?\n")
		else:
			print("You dont have the proper key and you are trying to start this car.\n")
	def shutdown(key):
		if key == 0:
			print("you turned off your car.")
			return 1
	def gas(tank):
		if tank == 0:
			print("Your tank is empty. You should get some gas.\n")
			print("Want to get some gas?")
			if input("Y/N") is "Y":
				amount_gas = input("How much gas you want")
				tank += get_gas(amount_gas)
			else:
				print("you ran out of gas")
				return shutdown()
				
				
				
	def get_gas(amount_gas):
		if amount_gas < 0:
			print("Invalid input")
			new_amount_gas = input("Enter new amount")
			get_gas(new_amount_gas)
		else:
			return amount_gas
				
		