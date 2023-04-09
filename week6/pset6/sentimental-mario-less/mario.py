# TODO
from cs50 import get_int

while True:
    height = get_int("Height: ")
    if height <= 8 and height >= 1:
        for i in range(height):
            print(" " * (height - i - 1), end="")
            print("#" * (i + 1))
        break

