import csv
import sys

if len(sys.argv) != 3:
    print("Usage: python dna.py database.csv sequence.txt")
    sys.exit(1)

# Read database
with open(sys.argv[1]) as file:
    reader = csv.DictReader(file)
    people = list(reader)
    strs = reader.fieldnames[1:]

# Read DNA sequence
with open(sys.argv[2]) as file:
    dna = file.read()

# Count STRs
counts = {}

for s in strs:
    max_count = 0
    i = 0
    while i < len(dna):
        count = 0
        while dna[i:i+len(s)] == s:
            count += 1
            i += len(s)
        max_count = max(max_count, count)
        i += 1
    counts[s] = max_count

# Match with database
for person in people:
    match = True
    for s in strs:
        if int(person[s]) != counts[s]:
            match = False
    if match:
        print(person["name"])
        sys.exit(0)

print("No match")