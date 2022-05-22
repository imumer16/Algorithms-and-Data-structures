#include <iostream>
#include <string>
#include <cctype>

bool palindrome(std::string x)
{
    for (size_t i = 0, j = x.size() - 1; i < x.size() && j >= 0; i++, j--)
    {
        if (isupper(x[i]))
            x[i] = x[i] + 32;
        if (isupper(x[j]))
            x[j] = x[j] + 32;
        if (x[i] != x[j])
            return 0;
    }
    return 1;
}

int main()
{
    std::string str;

    std::cout << "Enter a word: ";
    std::cin >> str;

    if (palindrome(str))
        std::cout << str << " is a palindrome. " << std::endl;
    else
        std::cout << str << " is not a palindrome. " << std::endl;

    return 0;
}