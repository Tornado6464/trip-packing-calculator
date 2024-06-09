import math
import os.path
from win32 import win32print
import win32api

version = "v0.2.0"

outputFileName = "./trip-packing-calculator/output.txt"

def daysFunction():
    while True:
        try:
            days = int(input("How many days will you be away for?\n"))
            return days
        except ValueError:
            print("Please enter an integer.")
def waterFunction():
    swimWear = input("Will you need swim wear? (y/N)\n")
    if swimWear == "y" or swimWear == "Y":
        return 1
    elif swimWear == "n" or swimWear == "N" or swimWear == "":
        return 0
    else:
        print("Make sure to input a Y or an N")
        waterFunction()
def formalFunction():
    formalWear = input("Will you need formal attire (eg. a suit)? (y/N)\n")
    if formalWear == "y" or formalWear == "Y":
        return 1
    elif formalWear == "n" or formalWear == "N" or formalWear == "":
        return 0
    else:
        print("Make sure to input a Y or an N")
        formalFunction()
def gymFunction():
    gymWear = input("Will you go to the gym when you are away? (y/N)\n")
    if gymWear == "y" or gymWear == "Y":
        return 1
    elif gymWear == "n" or gymWear == "N" or gymWear == "":
        return 0
    else:
        print("Make sure to input a Y or an N")
        gymFunction()
def washerFunction():
    washerString = input("Will you have access to a washer when you are away? (y/N)\n")
    if washerString == "y" or washerString == "Y":
        return 1
    elif washerString == "n" or washerString == "N" or washerString == "":
        return 0
    else:
        print("Make sure to input a Y or an N")
        washerFunction()
def printFunction():
    printResults = input('\nDo you want to print these results? (y/N):\n')
    if printResults == "y" or printResults == "Y":
        printer_name = win32print.GetDefaultPrinter()
        hPrinter = win32print.OpenPrinter(printer_name)
        filename = "output.txt"
        try:
            hJob = win32print.StartDocPrinter(hPrinter, 1, ('PrintJobName', None, 'TEXT'))
            try:
                win32api.ShellExecute(0, "print", filename, None, "./trip-packing-calculator", 0)
            finally:
                win32print.EndDocPrinter(hPrinter)
        finally:
            win32print.ClosePrinter(hPrinter)
    elif printResults == "n" or printResults == "N" or printResults == "":
        print()
    else:
        print()

print("Trip Packing Calculator")
print("You are using", version)
print()
print()
days = daysFunction()

nights = days - 1

waterVar = waterFunction()
formalVar = formalFunction()
gymVar = gymFunction()
washerVar = washerFunction()

file_exists = os.path.exists('./trip-packing-calculator/output.txt')
if not file_exists:
    path = './trip-packing-calculator'
    os.mkdir(path)

with open(outputFileName, "w+") as f:
    print()
    print("You should pack:", file=f)
    if washerVar == True:
        if days >= 7:
            print("7 normal outfits", file=f)
            print("1 set of PJ's", file=f)
        elif days < 7:
            print(days, "normal outfit(s)", file=f)
            print("1 set of PJ's", file=f)
        if waterVar == True:
            if nights >= 7:
                print("7 sets of swim wear", file=f)
            elif nights < 7:
                print(nights, "sets of swim wear", file=f)
        if formalVar == True:
            print("1 suit", file=f)
            print("1 set of formal shoes", file=f)
            print("1 tie", file=f)
            print("1 formal belt", file=f)
        if gymVar == True:
            if nights >= 7:
                print("7 sets of gym wear", file=f)
            elif nights < 7:
                print(nights, "set(s) of gym wear", file=f)
    elif washerVar == False:
        print(days, "normal outfit(s)", file=f)
        print(math.ceil(nights/7), "set(s) of PJ's", file=f)
        if waterVar == True:
            print(nights, "set(s) of swim wear", file=f)
        if formalVar == True:
            print("1 suit", file=f)
            print("1 set of formal shoes", file=f)
            print("1 tie", file=f)
            print("1 formal belt", file=f)
        if gymVar == True:
            print(nights, "set(s) of gym wear", file=f)
    print("Toothbrush(s)", file=f)
    print("Toothpaste(s)", file=f)
    print("Dental floss(s)", file=f)
    print("Shaving cream(s)", file=f)
    print("Razor(s)", file=f)
    print("Deodorant(s)", file=f)
    print("Cologne", file=f)
    print("Body soap(s)", file=f)
    print("Shampoo(s)", file=f)
    print("Sunglasses", file=f)
    f.close
with open(outputFileName, "r") as f:
    print(f.read())
    f.close

printFunction()
