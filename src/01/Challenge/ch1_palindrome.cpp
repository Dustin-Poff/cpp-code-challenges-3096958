// C++ Code Challenges, LinkedIn Learning

// Challenge #1: Checking for Palindromes
// Write a function to check if a string is a palindrome or not.
// Examples: civic, radar, level.

#include <iostream>
#include <algorithm>

// is_palindrome()
// Summary: This function receives a string and returns true if the string is a palindrome, false otherwise.
// Arguments:
//           str: The string to analyze.
// Returns: A boolean value. True for palindromes, false otherwise.
bool is_palindrome(std::string str){
    std::string reverse = str;
    int j = 0;
    for (size_t i = str.size() - 1; i > 0; i--)
    {
        reverse[j] = str[i]; 
        j++;
        if (i == 0) 
        {
            reverse[j] = '\0';
        }
    }
    

    // Write your code here
    if (str == reverse)
    {
        return true;
    }

    return false;
}

// Main function
int main(){
    std::string s;
    std::cout << "Enter a string: " << std::flush;
    std::getline(std::cin,s);
    std::cout << "\n\"" << s << (is_palindrome(s) ? "\" is" : "\" is not" ) << " a palindrome.\n\n";
    return 0;
}
