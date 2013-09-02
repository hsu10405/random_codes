#include <iostream>
using namespace std;

template <class T>
T compare(T x, T y){
    if(x > y){
        return x;
    }
    else{
        return y;
    }
}
int main(){
    int int_a, int_b = 0;
    double double_a, double_b = 0;

    int largest_int;
    double largest_double;
    cout << "enter 2 integers:\n" ;
    cin >> int_a >> int_b;

    cout << "enter 2 decimals:\n";
    cin >> double_a >> double_b;

    largest_int = compare(int_a, int_b);
    largest_double = compare(double_a, double_b);

    cout << "the largest integer is " << largest_int << "\n";
    cout << "the largest decimal is " << largest_double << "\n";

	return 0;
}
