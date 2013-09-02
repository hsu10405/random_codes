#include <iostream>
#include "myfunc.h"
using namespace std;
int main(){
	int num1, num2, ans = 0;

	cout << "Please enter the first integer: \n";
	cin >> num1;

	cout << "Please enter the second integer: \n";
	cin >> num2;

	ans = max(num1, num2);

	cout << "The biggest value is " << ans << endl;

	return 0;
}