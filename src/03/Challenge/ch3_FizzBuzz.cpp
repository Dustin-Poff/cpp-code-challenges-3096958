// C++ Code Challenges, LinkedIn Learning

// Challenge #3: FizzBuzz
// Write an application that plays FizzBuzz.
// Print an integer number sequence starting at 1, replacing multiples of 3 by "Fizz", multiples of 5 by "Buzz", and multiples of 3 and 5 by "FizzBuzz".
// The user enters the last number in the sequence.

#include <iostream>

void FizzBuzz(const int userNumber)
{
    for (size_t i = 0; i <= userNumber; i++)
    {
        if ((i % 3 == 0) && (i % 5 == 0))
        {
            std::cout << i << " is a " << "Fizz Buzz" << std::endl;
        }
        else if (i % 3 == 0)
        {
            std::cout << i << " is a "  << "Fizz" << std::endl;
        }
        else if (i % 5 == 0)
        {
            std::cout << i << " is a "  << "Buzz" << std::endl;
        }
    }
    
};

// FizzBuzz, main()
// Summary: This application runs on the main function.
int main(){
    int n; // How many numbers to include in the sequence.
    
    do
    {
        std::cout << "Enter a positive integer: " << std::flush;
        std::cin >> n;
    } while (isdigit(n) and n >= 0);
    

    // Write your code here
    FizzBuzz(n);
    
    std::cout << std::endl << std::flush;
    return 0;
}
