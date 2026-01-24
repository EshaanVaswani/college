def main():
    productions = get_productions()
    print("Original Productions:")
    display_productions(productions)

    new_productions = remove_left_recursion(productions)
    print("\nNew Productions (after removing left recursion):")
    display_productions(new_productions)

def get_productions():
    # Example with left recursion: A → Aa | b
    # Should be transformed to: A → bA', A' → aA' | ε
    return {
        'E': ['E+T', 'T'],
        'T': ['T*F', 'F'],
        'F': ['(E)', 'id']
    }

def remove_left_recursion(productions):
    new_productions = {}

    for nt in list(productions.keys()):
        prods = productions[nt]
        left_recursive = []
        non_left_recursive = []

        for prod in prods:
            if prod.startswith(nt):
                left_recursive.append(prod[len(nt):])  # remove the left-recursive part
            else:
                non_left_recursive.append(prod)

        if left_recursive:
            new_nt = nt + "'"
            new_productions[nt] = [p + new_nt for p in non_left_recursive]
            new_productions[new_nt] = [p + new_nt for p in left_recursive]
            new_productions[new_nt].append("#")  # # as epsilon
        else:
            new_productions[nt] = prods

    return new_productions

def display_productions(productions):
    for nt, prods in productions.items():
        print(f"{nt} -> {' | '.join(prods)}")

if __name__ == '__main__':
    main()
