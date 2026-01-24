def eliminate_common_subexpressions(statements):
    temp = {}
    removed = {}
    for stmt in statements:
        var, expr = map(str.strip, stmt.split('='))
        for old_var, existing_expr in removed.items():
            if old_var in expr:
                expr = expr.replace(old_var, existing_expr)
        if expr not in temp.values():
            temp[var] = expr
        else:
            existing_var = next(v for v, e in temp.items() if e == expr)
            removed[var] = existing_var
    return temp

def normalize_temp_names(exprs):
    sorted_vars = sorted(exprs.keys(), key=lambda x: int(x[1:]))
    mapping = {old: f"t{i+1}" for i, old in enumerate(sorted_vars)}
    final = {}
    for old_var, expr in exprs.items():
        for old, new in mapping.items():
            expr = expr.replace(old, new)
        final[mapping[old_var]] = expr
    return final

def main():
    statements = [
        "t1 = a + b",
        "t2 = a + b",
        "t3 = c + d",
        "t4 = t1 + t3",
        "t5 = a + b"
    ]

    remaining = eliminate_common_subexpressions(statements)
    optimized = normalize_temp_names(remaining)

    print("Optimized Code:")
    for var in sorted(optimized, key=lambda x: int(x[1:])):
        print(f"{var} = {optimized[var]}")

if __name__ == "__main__":
    main()
