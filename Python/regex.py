import re

city_string = "Mumbai Kolkata Chennai Madurai Coimbatore Mysore Mangalore Pune Nashik Indore Bhopal Surat Udaipur"

cities_ending_with_ai = re.findall(r'\b\w*ai\b', city_string)
print("Cities ending with 'ai':", cities_ending_with_ai)

cities_starting_with_Mu_Ma = re.findall(r'\b(Mu\w*|Ma\w*)\b', city_string)
print("Cities starting with 'Mu' or 'Ma':", cities_starting_with_Mu_Ma)

cities_with_specific_letters = re.findall(r'\b\w*u\w{1}a\w\b', city_string)
print("Cities with 'u' as the second letter and 'a' as the second last letter:", cities_with_specific_letters)


