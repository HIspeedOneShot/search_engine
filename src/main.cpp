#include <iostream>
#include <vector>
#include <ConverterJSON.h>

#include "nlohmann/json.hpp"

int main(int, char **)
{
    

    ConverterJSON converter;
    converter.readRequests();
    converter.readConfig();
    converter.writeAnswer();
    try
    {
        /* // добавить вывод полученного имени в ConverteJSON
        std::cout << "Starting " << name << std::endl;
        std::cout << "responses = " << responses << std::endl;
        for (auto &i : GetTextFile)
        {
            std::cout << i << std::endl;
        } */
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
}
