# TODO
from cs50 import get_int
import re
import sys

while True:
    card = get_int("Number: ")
    if card > 0 and re.fullmatch("[0-9]{13,16}", str(card)) != None:
        break
    else:
        print("INVALID")
        sys.exit(0)

temp = card
sum = 0
multiply = 0
# sum = false; multiple = true
operation = True
while(card > 0):
    digit = card % 10
    if operation:
        sum += digit
        operation = False
    else:
        if digit * 2 >= 10:
            multiply += digit * 2 - 9
        else:
            multiply += digit * 2
        operation = True;
    card //= 10

if (sum + multiply) % 10 == 0:
    if re.fullmatch("^4\d{12}(\d{3})?$", str(temp)) != None:
        print("VISA")
    elif re.fullmatch("5[1,5][0-9]{14}", str(temp)) != None:
        print("MASTERCARD")
    elif re.fullmatch("3[47][0-9]{13}", str(temp)) != None:
        print("AMEX")
    else:
        print("INVALID")
else:
    print("INVALID")
