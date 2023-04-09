import csv
from os import name
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    # TODO: Read database file into a variable
    database = {}
    inner_key_names = set()
    with open(sys.argv[1], 'r') as f:
        reader = csv.DictReader(f)
        for row in reader:
            name = row['name']
            database[name] = {}
            for key, value in row.items():
                if key != 'name':
                    inner_key_names.add(key)
                    database[name][key] = value


    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2], 'r') as f:
        sequence = f.read()

    # TODO: Find longest match of each STR in DNA sequence
    longest = dict()
    for item in inner_key_names:
        longest[item] = longest_match(sequence, item)

    # TODO: Check database for matching profiles
    found = False
    for name, profile in database.items():
        matches = True
        for item, count in longest.items():
            if int(profile[item]) != count:
                matches = False
                break
        if matches:
            found = True
            break

    if found:
        print(name)
    else:
        print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
