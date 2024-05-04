import re

def find_contacts(filename):
    with open(filename, 'r') as file:
        contents = file.read()

    pattern = r'Rao\s([JK]\w*)\s(\d+)'
    matches = re.findall(pattern, contents)

    print("Entries with surname 'Rao' and first name starting with 'J' or 'K':")
    for match in matches:
        print(f"Surname: Rao, First Name: {match[0]}, Number: {match[1]}")

filename = 'phone_list.txt'
find_contacts(filename)


