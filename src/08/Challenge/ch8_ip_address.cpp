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
std::vector<std::string> get_tokens(std::string ip)
{
    std::vector<std::string> parsedTokens;
    std::string parsingChar = ".";
    int position;
    do 
    {
        position = ip.find(parsingChar);
        parsedTokens.push_back(ip.substr(0, position));
        ip.erase(0, position + parsingChar.length());
        
    }while(position != ip.npos);
    return parsedTokens;
}

int ip_checks(std::vector<std::string> parsedTokens)
{
    size_t i = 0;
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
    return i;
}

bool is_valid_ip(std::string ip){
    std::vector<std::string> parsedTokens = get_tokens(ip);

    if (ip_checks(parsedTokens) == parsedTokens.size())
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
