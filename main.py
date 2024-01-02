version = "v0.2.0"

def waterFunction():
    swimWear = input("Will you need swim wear? (y/N)\n")
    if swimWear == "y" or swimWear == "Y":
        return 1
    elif swimWear == "n" or swimWear == "N":
        return 0
    else:
        print("Make sure to input a Y or an N")
        waterFunction()
def formalFunction():
    formalWear = input("Will you need swim wear? (y/N)\n")
    if formalWear == "y" or formalWear == "Y":
        return 1
    elif formalWear == "n" or formalWear == "N":
        return 0
    else:
        print("Make sure to input a Y or an N")
        formalFunction()

print("Trip Packing Calculator\n")
print("You are using", version)
print()
print()
days = int(input("How many days will you be away for?"))
nights = days - 1

waterVar = waterFunction()
formalVar = formalFunction()