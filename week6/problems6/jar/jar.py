class Jar:
    def __init__(self, capacity=12):
        if capacity < 0: raise ValueError
        self.jarCapacity = capacity
        self.cookieAmount = 0

    def __str__(self):
        return "🍪" * self.cookieAmount;

    def deposit(self, n):
        if self.cookieAmount + n > self.capacity: raise ValueError
        self.cookieAmount += n;

    def withdraw(self, n):
        if self.cookieAmount - n < 0: raise ValueError
        self.cookieAmount -= n

    @property
    def capacity(self):
        return self.jarCapacity;

    @property
    def size(self):
        return self.cookieAmount;


def main():
    jar = Jar()
    jar.deposit(2)
    print(str(jar))
    jar.withdraw(1)
    print(str(jar))


main()
