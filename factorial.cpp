#include <iostream>

using namespace std;

long double factorial(long double n)
{
	long double fact = 1;
	for (double i = n; i >= 1; i--)
	{
		fact = fact + (fact * (n - i));
	}
	return fact;
}

int main()
{
	long double x = 0;
	cout << " (Enter a number) -> Find factorial of ";
	cin >> x;
	cout << "\tFactorial: " << factorial(x) << endl;

	return 0;
}
