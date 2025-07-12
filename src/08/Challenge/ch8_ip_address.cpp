// C++ Code Challenges, LinkedIn Learning

// Challenge #8: IP Address Validation
// Write an application that reads a string from the terminal and responds with a message indicating whether the string is a valid IP address or not.
// Assume decimal IP addresses.
// 158.25.0.33
// All numbers between 0 and 255.

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

// is_valid_ip()
// Summary: This function validates an IP address.
// Arguments:
//           ip: The string to analyze with a potential ip address.
// Returns: A boolean value. True for valid ip addresses, false otherwise.
bool is_valid_ip(std::string ip){
    std::vector<std::string> parsedTokens;
    std::string ipTemp = ip;
    std::string parsingChar = ".";
    int position = ipTemp.find(parsingChar);
    size_t i = 0;

    while(position != ipTemp.npos)
    {
        parsedTokens.push_back(ipTemp.substr(0, position));
        ipTemp.erase(0, position + parsingChar.length());
        position = ipTemp.find(parsingChar);
        if (position == ipTemp.npos)
        {
            parsedTokens.push_back(ipTemp.substr(0, position));
        }
        
    }
    if (parsedTokens.size() == 4)
    {
        while (i < parsedTokens.size() && all_of(parsedTokens[i].begin(), parsedTokens[i].end(), ::isdigit))
        {
            if (std::stoul(parsedTokens[i]) > 255)
            {
                break;
            }
            i++;
        }
    }
    if (i == parsedTokens.size())
    {
        return true;
    }
    
    return false;
}

// Main function
int main(){
    std::string s;
    
    std::cout << std::endl << "Enter an IP address in decimal: " << std::flush;
    std::getline(std::cin,s);
    std::cout << " \n" << s << (is_valid_ip(s) ? " is" : " is not" ) << " a valid IP address.\n\n";
    return 0;
}
