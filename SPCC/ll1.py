def generate_parse_table(grammar, first, follow):
    non_terminals = list(grammar.keys())  # Non-terminals on Y-axis
    terminals = get_terminals(grammar, non_terminals)  # Terminals on X-axis

    # Create an empty parse table: { non-terminal : { terminal : None } }
    table = {nt: {t: None for t in terminals} for nt in non_terminals}

    for nt in grammar:
        for rule in grammar[nt]:
            rule_first = get_first(rule, first, non_terminals)  # Get FIRST set for the rule

            # Fill table for each terminal in FIRST of the rule
            for symbol in rule_first:
                if symbol != 'ε':  # We don't care about epsilon for now
                    if table[nt][symbol] is not None:
                        print(f"Conflict at [{nt}][{symbol}]: {table[nt][symbol]} vs {rule}")
                        return None
                    table[nt][symbol] = rule

            # If the rule can derive ε, we check the FOLLOW set for the non-terminal
            if 'ε' in rule_first:
                for symbol in follow[nt]:
                    if table[nt][symbol] is not None:
                        print(f"Conflict at [{nt}][{symbol}]: {table[nt][symbol]} vs {rule}")
                        return None
                    table[nt][symbol] = rule

    return table

def get_terminals(grammar, non_terminals):
    terminals = set()
    for rules in grammar.values():
        for rule in rules:
            for symbol in rule:
                if symbol not in non_terminals and symbol != 'ε':
                    terminals.add(symbol)
    return sorted(terminals) + ['$']  # Add $ as end of input symbol

def get_first(rule, first_sets, non_terminals):
    result = set()
    for symbol in rule:
        if symbol in non_terminals:
            result.update(first_sets[symbol] - {'ε'})
            if 'ε' not in first_sets[symbol]:
                return result
        else:
            result.add(symbol)
            return result
    result.add('ε')
    return result

def display_table(table, terminals):
    print("\nLL(1) Parse Table:")
    print(f"{'Non-Terminal':<15}", end="")
    for t in terminals:
        print(f"{t:<10}", end="")
    print()
    print("-" * (15 + len(terminals) * 10))
    
    for nt in table:
        print(f"{nt:<15}", end="")
        for t in terminals:
            rule = table[nt][t]
            production = 'None' if rule is None else ' '.join(rule) if rule != ['ε'] else 'ε'
            print(f"{production:<10}", end="")
        print()

# --- Main driver code with hardcoded FIRST and FOLLOW sets ---
if __name__ == "__main__":
    grammar = {
        'E': [['T', "E'"]],
        "E'": [['+', 'T', "E'"], ['ε']],
        'T': [['F', "T'"]],
        "T'": [['*', 'F', "T'"], ['ε']],
        'F': [['(', 'E', ')'], ['id']]
    }

    # Hardcoded FIRST sets
    first = {
        'E': {'(', 'id'},
        "E'": {'+', 'ε'},
        'T': {'(', 'id'},
        "T'": {'*', 'ε'},
        'F': {'(', 'id'}
    }

    # Hardcoded FOLLOW sets
    follow = {
        'E': {')', '$'},
        "E'": {')', '$'},
        'T': {'+', ')', '$'},
        "T'": {'+', ')', '$'},
        'F': {'*', '+', ')', '$'}
    }

    parse_table = generate_parse_table(grammar, first, follow)
    if parse_table:
        display_table(parse_table, get_terminals(grammar, list(grammar.keys())))
