# TODO
from cs50 import get_float
from cs50.cs50 import print_function

def main():
    while True:
        cents = get_float("Change owed: ")
        if cents > 0:
            cents *= 100
            break

    coins = 0;

    for i in [25, 10, 5, 1]:
        temp = cents // i
        coins += temp
        cents -= temp * i

    print(f"{coins:.0f}")


main()
