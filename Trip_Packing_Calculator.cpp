/*
MIT License

Copyright (c) 2023 Tyler Davis

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <iostream>
#include <string>
#include <cmath>

bool waterFunction() //Asks the user if they want to pack swim wear
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

bool formalFunction() //Asks the user if they want to pack a formal outfit
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

bool gymFunction() //Asks the user if they want to pack gym clothes
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

bool washerFunction() //Asks the user if they will be able to wash clothes to minimize packing requirements
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
    std::cout << "Trip Packing Calculator" << std::endl;
    std::cout << "Created by Tyler Davis" << std::endl;
    std::cout << "Version 0.1.1" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Provided under the MIT license, found at https://gitea.tylerdavis.org/tyler/Trip_Packing_Calculator/src/branch/main/LICENSE" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;


    std::cout << "How many days will you be away for?" << std::endl;
    int days{};
    std::cin >> days;
    int nights{};
    nights = days - 1; //Usually the number of nights that you are gone for is the amount of "days - 1" due to travel time

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
    std::cout << "Toothbrush(s)" << std::endl;
    std::cout << "Toothpaste(s)" << std::endl;
    std::cout << "Dental floss(s)" << std::endl;
    std::cout << "Shaving cream(s)" << std::endl;
    std::cout << "Razor(s)" << std::endl;
    std::cout << "Deodorant(s)" << std::endl;
    std::cout << "Body soap(s)" << std::endl;
    std::cout << "Shampoo(s)" << std::endl;
    return 0;
}