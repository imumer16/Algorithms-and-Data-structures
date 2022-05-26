#include <iostream>

#define print(x)                \
	{                           \
		std::cout << "\t" << x; \
	}

int main()
{
	system("COLOR 0A");
	bool Leap = false;
	int Year = 0;

	print("Enter a Year = ");
	std::cin >> Year;

	if (Year % 4 == 0)
	{
		Leap = true;
		if (Year % 100 == 0)
		{
			Leap = false;
			if (Year % 400 == 0)
			{
				Leap = true;
			}
		}
	}

	if (!Leap)
	{
		print("Year is not a Leap Year");
	}
	else
	{
		print("Year is a Leap Year");
	}

	return 0;
}
