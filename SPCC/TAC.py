def generate_tac(expr):
    temp_count = 1
    code = []
    operands = []
    operators = []
    i = 0
    while i < len(expr):
        char = expr[i]
        if char.isspace():
            i += 1
            continue
        elif char == '(':
            operators.append(char)
            i += 1
        elif char == ')':
            while operators and operators[-1] != '(':
                op = operators.pop()
                process_operator(op, operands, code, temp_count)
                temp_count += 1
            if operators and operators[-1] == '(':
                operators.pop()
            i += 1
        elif char == '=':
            operators.append(char)
            i += 1
        elif char.isalnum():
            operands.append(char)
            i += 1
        elif char in ['+', '-', '*', '/']:
            is_unary_minus = (char == '-' and (i == 0 or expr[i-1] in ['(', '=', '+', '-', '*', '/']))
            if is_unary_minus:
                i += 1
                if i < len(expr) and (expr[i].isalnum() or expr[i] == '('):
                    if expr[i] == '(':
                        operators.append('u-')
                        operators.append('(')
                        i += 1
                    else:
                        operand = expr[i]
                        temp = f"t{temp_count}"
                        temp_count += 1
                        code.append(f"{temp} = - {operand}")
                        operands.append(temp)
                        i += 1
            else:
                while (operators and operators[-1] != '(' and precedence(operators[-1]) >= precedence(char)):
                    op = operators.pop()
                    process_operator(op, operands, code, temp_count)
                    temp_count += 1
                operators.append(char)
                i += 1
        else:
            i += 1
    while operators:
        op = operators.pop()
        if op == '(':
            continue
        process_operator(op, operands, code, temp_count)
        temp_count += 1
    return code

def process_operator(op, operands, code, temp_count):
    if op == '=':
        right = operands.pop()
        left = operands.pop()
        code.append(f"{left} := {right}")
        operands.append(left)
    elif op == 'u-':
        operand = operands.pop()
        temp = f"t{temp_count}"
        code.append(f"{temp} = - {operand}")
        operands.append(temp)
    else:
        right = operands.pop()
        left = operands.pop()
        temp = f"t{temp_count}"
        code.append(f"{temp} = {left} {op} {right}")
        operands.append(temp)

def precedence(op):
    if op == '=':
        return 0
    elif op in ['+', '-']:
        return 1
    elif op in ['*', '/']:
        return 2
    elif op == 'u-':
        return 3
    return -1

def main():
    expr = input("Enter the expression: ")
    code = generate_tac(expr)
    print("\nThree Address Code:")
    for line in code:
        print(line)

if __name__ == "__main__":
    main()

