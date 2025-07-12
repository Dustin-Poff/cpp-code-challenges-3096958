// C++ Code Challenges, LinkedIn Learning

// Challenge #9: Fixing Faulty Code
// Fix the bugs in the provided code.
// The application is supposed to ask the user for a string, and print the number of vowels contained in the string.

// For example: 
// "I love my dog" has 4 vowels, "education" has 5 vowels, and "Sly spy by my crypt" has 0 vowels.

#include <string>
#include <iostream>
#include <algorithm>

// vowel_count()
// Summary: This function counts the number of vowels in an incoming string.
// Arguments:
//           str: The string to analyze.
// Returns: An integer with the vowel count.
int vowel_count(std::string str){
    int count = 0;
    std::transform(str.begin(), str.end(), str.begin(), tolower);
    for(int i = 0; i<str.length(); i++)
        switch(static_cast<char> (str[i])){
            case 'a':
                count++;
                break;
            case 'e':
                count++;
                break;
            case 'i':
                count++;
                break;
            case 'o':
                count++;
                break;
            case 'u':
                count++;
                break;
        }
    return count;
}

// Faulty code, main()
// Summary: This application ask the user for a string, and prints the number of vowels in it.
int main(){
    std::string input; 
    std::cout << "Enter some text: " << std::flush;
    getline(std::cin, input);
    std::cout << "\nThe text you entered contains " << vowel_count(input) << " vowels.\n\n";
    return 0;
}
 