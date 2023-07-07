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
    std::cout << "Will you go to the gym when you are away? (y/N)" << std::endl;
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

bool washerFunction()
{
    std::cout << "Will you have access to a washer when you are away? (y/N)" << std::endl;
    std::string washerString{};
    std::cin >> washerString;
    bool washer{};
    if (washerString == "Y")
    {
        washer = 1;
    }
    if (washerString == "y")
    {
        washer = 1;
    }
    if (washerString == "N")
    {
        washer = 0;
    }
    if (washerString == "n")
    {
        washer = 0;
    }
    else if (washerString != "y")
    {
        std::cout << "Please input either \"Y\" or \"N\"" << std::endl;
        washerFunction();
    }
    return washer;
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
    bool washerVar{ washerFunction() };

    std::cout << "\nYou should pack:" << std::endl;

    if (washerVar == true)
    {
        if (days >= 7)
        {
            std::cout << "7 normal outfits" << std::endl;
            std::cout << "1 set of PJ's" << std::endl;
        }
        else if (days < 7)
        {
            std::cout << days << " normal outfit(s)" << std::endl;
            std::cout << "1 set of PJ's" << std::endl;
        }
        if (waterVar == true)
        {
            if (nights >= 7)
            {
                std::cout << "7 sets of swim wear" << std::endl;
            }
            else if (nights < 7)
            {
                std::cout << nights << " set(s) of swim wear" << std::endl;
            }
        }
        if (formalVar == true)
        {
            std::cout << "1 suit" << std::endl;
            std::cout << "1 set of formal shoes" << std::endl;
            std::cout << "1 tie" << std::endl;
            std::cout << "1 formal belt" << std::endl;
        }
        if (gymVar == true)
        {
            if (nights >= 7)
            {
                std::cout << "1 set of gym wear" << std::endl;
            }
            if (nights < 7)
            {
                std::cout << nights << " set(s) of gym wear" << std::endl;
            }
        }
    }

    else if (washerVar == false)
    {
        std::cout << days << " normal outfit(s)" << std::endl;
        std::cout << std::ceil(nights / 7) << " set(s) of PJ's" << std::endl;
        if (waterVar == true)
        {
            std::cout << nights << " set(s) of swim wear" << std::endl;
        }
        if (formalVar == true)
        {
            std::cout << "1 suit" << std::endl;
            std::cout << "1 set of formal shoes" << std::endl;
            std::cout << "1 tie or bow tie" << std::endl;
            std::cout << "1 formal belt" << std::endl;
        }
        if (gymVar == true)
        {
                std::cout << nights << " set(s) of gym wear" << std::endl;
        }
    }
}