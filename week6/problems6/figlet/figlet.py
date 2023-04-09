from pyfiglet import Figlet, print_figlet
import sys

figlet = Figlet()

if len(sys.argv) == 3:
    if sys.argv[1] != "-f" and sys.argv[1] != "--font":
        print("Invalid usage")
        sys.exit(1)
    if sys.argv[2] not in figlet.getFonts():
        print("Invalid usage")
        sys.exit(1)
    figlet.setFont(font=sys.argv[2])
if len(sys.argv) == 2:
    print("Invalid usage")
    sys.exit(1)


s = input("Input: ")
print(f"Output:\n {figlet.renderText(s)}")

