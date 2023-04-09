# TODO
from cs50 import get_int

def main():
    while True:
        height = get_int("Height: ")
        if height <= 8 and height >= 1:
            for i in range(height):
                print(" " * (height - i - 1), end="")
                print_hashes(i)
                print("  ", end='')

                print_hashes(i)
                print()

            break


def print_hashes(n):
    print("#" * (n + 1), end='')


main()
