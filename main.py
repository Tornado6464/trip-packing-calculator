import math

version = "v0.2.0"

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

print("Trip Packing Calculator\n")
print("You are using", version)
print()
print()
days = daysFunction()

nights = days - 1

waterVar = waterFunction()
formalVar = formalFunction()
gymVar = gymFunction()
washerVar = washerFunction()

print("You should pack:")

if washerVar == True:
    if days >= 7:
        print("7 normal outfits")
        print("1 set of PJ's")
    elif days < 7:
        print(days, "normal outfit(s)")
        print("1 set of PJ's")
    if waterVar == True:
        if nights >= 7:
            print("7 sets of swim wear")
        elif nights < 7:
            print(nights, "sets of swim wear")
    if formalVar == True:
        print("1 suit")
        print("1 set of formal shoes")
        print("1 tie")
        print("1 formal belt")
    if gymVar == True:
        if nights >= 7:
            print("7 sets of gym wear")
        elif nights < 7:
            print(nights, "set(s) of gym wear")
elif washerVar == False:
    print(days, "normal outfit(s)")
    print(math.ceil(nights/7), "set(s) of PJ's")
    if waterVar == True:
        print(nights, "set's of swim wear")
    if formalVar == True:
        print("1 suit")
        print("1 set of formal shoes")
        print("1 tie")
        print("1 formal belt")
    if gymVar == True:
        print(nights, "set(s) of gym wear")
print("Toothbrush(s)")
print("Toothpaste(s)")
print("Dental floss(s)")
print("Shaving cream(s)")
print("Razor(s)")
print("Deodorant(s)")
print("Cologne")
print("Body soap(s)")
print("Shampoo(s)")