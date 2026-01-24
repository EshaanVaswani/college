def parse_rules(input_rules):
    productions = []
    for rule in input_rules:
        lhs,rhs = rule.split("->")
        rhs_opts = rhs.split("|")
        productions.append((lhs.strip(), [opt.strip() for opt in rhs_opts]))
    return productions

def insert_first(first_sets, non_terminal, symbol):
    if non_terminal not in first_sets:
        first_sets[non_terminal] = set()
    og_size = len(first_sets[non_terminal])
    first_sets[non_terminal].add(symbol)
    return len(first_sets[non_terminal]) > og_size

def compute_first_sets(rules):
    first_sets = {}
    updated = True

    while updated:   
        updated = False 
        for lhs, prods in rules:
            for p in prods:
                can_be_empty = True

                for s in p:
                    if s.islower() or s == '#':
                        if insert_first(first_sets, lhs, s):
                            updated = True
                        can_be_empty = (s == '#')
                        break

                    elif s.isupper():
                        first = first_sets.get(s, set())
                        
                        for t in first:
                            if t != '#' and insert_first(first_sets, lhs, t):
                                updated = True

                        if '#' in first:
                            continue
                        else:
                            can_be_empty = False
                            break

                if can_be_empty:
                    if insert_first(first_sets, lhs, '#'):
                        updated = True

    return first_sets

n = int(input("Enter no. of productions (in the form A->b|BC|#):"))
rules = [input().strip() for _ in range(n)]
prods = parse_rules(rules)
first = compute_first_sets(prods)
print("\nFIRST SETS:")
for nt in sorted(first):
    print(f"{nt} = {' '.join(sorted(first[nt]))}")