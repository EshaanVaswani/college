import re

result = {
   "keywords": set(),
   "identifiers": set(),
   "constants": set(),
   "operators": set(),
   "separators": set(),
   "errors": set()
}

patterns = {
   "keywords": r"\b(int|float|double|if|else|for|while|string|char|continue|return)\b",
   "identifiers": r"\b[a-zA-Z_][a-zA-Z0-9_]*\b",
   "constants": r"\b\d+(\.\d+)?\b|'(\\?.)'|\"(.*?)\"",
   "operators": r"(\+\+|--|>=|<=|==|\+=|-=|\*=|/=|[+\-*/><%!=])",
   "separators": r"[{}\[\]();:,]"
}

def tokenise(line):
    tokens = []

    while line:
        line = line.strip()
        if not line:
            break
        match = None
        for token_type, pattern in patterns.items():
            regex_match = re.match(pattern, line)
            if regex_match:
                match = (token_type, regex_match.group())
                break
            
        if match:
            token_type, token = match
            tokens.append((token_type, token))
            line = line[len(token):]
        else:
            invalid_token = line[0]
            result["errors"].add(invalid_token)
            line = line[1:]
    return tokens

n = int(input("Enter no. of lines: "))
print("Enter code line by line: ")
for _ in range(n):
    line = input()
    tokens = tokenise(line)
    for type, token in tokens:
        if type == "keywords":
            result["keywords"].add(token)
        elif type == "identifiers":
            result["identifiers"].add(token)
        elif type == "separators":
            result["separators"].add(token)
        elif type == "operators":
            result["operators"].add(token)
        elif type == "constants":
            if token.startswith('"') and token.endswith('"'):
                token = token[1:-1]
            elif token.startswith("'") and token.endswith("'"):
                token = token[1:-1]
            result["constants"].add(token)

for type, tokens in result.items():
    if tokens:
        print(f"{type} : {' '.join(tokens)}")