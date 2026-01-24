def compute_follow_sets(productions, first_sets, start_symbol):
    follow_sets = {start_symbol: {'$'}}  # Rule 3: Start symbol gets '$'

    changed = True
    while changed:
        changed = False
        for lhs, rules in productions:
            for rule in rules:
                for i in range(len(rule)):
                    current = rule[i]
                    if not current.isupper():  # Skip terminals
                        continue
                    follow_sets.setdefault(current, set())

                    # Rule 1: A → αBβ, add FIRST(β) - {ε} to FOLLOW(B)
                    can_derive_epsilon = True
                    for j in range(i + 1, len(rule)):
                        next_symbol = rule[j]

                        if next_symbol.islower() or next_symbol == '#':
                            if next_symbol not in follow_sets[current]:
                                follow_sets[current].add(next_symbol)
                                changed = True
                            can_derive_epsilon = False
                            break
                        else:
                            first_of_next = first_sets.get(next_symbol, set())
                            for terminal in first_of_next:
                                if terminal != '#' and terminal not in follow_sets[current]:
                                    follow_sets[current].add(terminal)
                                    changed = True
                            if '#' in first_of_next:
                                continue
                            else:
                                can_derive_epsilon = False
                                break

                    # Rule 2: A → αB or A → αBβ where β ⇒ ε, add FOLLOW(A) to FOLLOW(B)
                    if can_derive_epsilon:
                        follow_of_lhs = follow_sets.get(lhs, set())
                        for terminal in follow_of_lhs:
                            if terminal not in follow_sets[current]:
                                follow_sets[current].add(terminal)
                                changed = True
    return follow_sets

def main():
    productions = [
        ('S', ['aBDh']),
        ('B', ['cC']),
        ('C', ['bC', '#']),
        ('D', ['EF']),
        ('E', ['g', '#']),
        ('F', ['f', '#'])
    ]

    first_sets = {
        'S': {'a'},
        'B': {'c'},
        'C': {'b', '#'},
        'D': {'g', 'f', '#'},
        'E': {'g', '#'},
        'F': {'f', '#'}
    }

    start_symbol = 'S'
    follow_sets = compute_follow_sets(productions, first_sets, start_symbol)

    print("FOLLOW sets:")
    for nt in sorted(follow_sets):
        follow = sorted(follow_sets[nt])
        follow_str = [x if x != '#' else 'ε' for x in follow]
        print(f"{nt} : {{ {', '.join(follow_str)} }}")

if __name__ == "__main__":
    main()
