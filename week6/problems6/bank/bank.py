string = input("Greeting: ")
if "hello" in string.lower():
    print("$0")
elif string.lower().startswith('h'):
    print("$20")
else:
    print("$100")
