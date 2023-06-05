#include <iostream>
#include <string>
#include <cmath>

bool waterFunction()
{
    std::cout << "Will you need swim wear? (y/N)" << std::endl;
    std::string swimWearString{};
    std::cin >> swimWearString;
    bool swimWear{};
    if (swimWearString == "Y")
    {
        swimWear = 1;
    }
    if (swimWearString == "y")
    {
        swimWear = 1;
    }
    if (swimWearString == "N")
    {
        swimWear = 0;
    }
    if (swimWearString == "n")
    {
        swimWear = 0;
    }
    else if (swimWearString != "y")
    {
        std::cout << "Please input either \"Y\" or \"N\"" << std::endl;
        waterFunction();
    }
    return swimWear;
}

bool formalFunction()
{
    std::cout << "Will you need formal attire (eg. suit)? (y/N)" << std::endl;
    std::string formalString{};
    std::cin >> formalString;
    bool formal{};
    if (formalString == "Y")
    {
        formal = 1;
    }
    if (formalString == "y")
    {
        formal = 1;
    }
    if (formalString == "N")
    {
        formal = 0;
    }
    if (formalString == "n")
    {
        formal = 0;
    }
    else if (formalString != "y")
    {
        std::cout << "Please input either \"Y\" or \"N\"" << std::endl;
        formalFunction();
    }
    return formal;
}

bool gymFunction()
{
    std::cout << "Will go to the gym when you are away? (y/N)" << std::endl;
    std::string gymString{};
    std::cin >> gymString;
    bool gym{};
    if (gymString == "Y")
    {
        gym = 1;
    }
    if (gymString == "y")
    {
        gym = 1;
    }
    if (gymString == "N")
    {
        gym = 0;
    }
    if (gymString == "n")
    {
        gym = 0;
    }
    else if (gymString != "y")
    {
        std::cout << "Please input either \"Y\" or \"N\"" << std::endl;
        gymFunction();
    }
    return gym;
}


int main()
{
    std::cout << "How many days will you be away for?" << std::endl;
    double days{};
    std::cin >> days;
    double nights{};
    nights = days - 1;

    bool waterVar{ waterFunction() };
    bool formalVar{ formalFunction() };
    bool gymVar{ gymFunction() };

    std::cout << "\nYou should pack:" << std::endl;
    std:: cout << days << " normal outfits" << std::endl;
    if (nights > 7)
    {
        std::cout << std::ceil(nights / 7) << " sets of PJ's" << std::endl;
    }
    else if (nights <= 7)
    {
        std::cout << "1 set of PJ's" << std::endl;
    }
    if (waterVar == true)
    {
        if (nights > 1)
        {
            std::cout << nights << " sets of swim wear" << std::endl;
        }
        else if (nights == 1)
        {
            std::cout << "1 set of swim wear" << std::endl;
        }
    if (formalVar == true)
        std::cout << "1 suit" << std::endl;
        std::cout << "1 set of formal shoes" << std::endl;
        std::cout << "1 tie" << std::endl;
        std::cout << "1 formal belt" << std::endl;
    if (gymVar == true)
    {
        if (nights > 1)
        {
            std::cout << "1 set of gym wear" << std::endl;
        }
        if (nights >= 2)
        {
            std::cout << nights << " sets of gym wear" << std::endl;
        }
    }
    }
}