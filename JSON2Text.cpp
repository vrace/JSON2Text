#include <iostream>
#include <string>

int main(void)
{
    std::string line;
    
    std::cout << "var text =" << std::endl;
    
    while (std::getline(std::cin, line))
    {
        const char *str = line.c_str();
        
        std::cout << "\"";
        
        for (const char *p = str; *p; p++)
        {
            if (*p == '"')
            {
                std::cout << "\\\"";
            }
            else if (*p == '\\')
            {
                std::cout << "\\\\";
            }
            else if (*p == '\'')
            {
                std::cout << "\\'";
            }
            else if (*p == '\r' || *p == '\n')
            {
                
            }
            else
            {
                std::cout << *p;
            }
        }
        
        std::cout << "\" +" << std::endl;
    }
    
    std::cout << "\"\"" << std::endl;
    
    return 0;
}
