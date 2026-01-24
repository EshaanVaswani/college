def macro_processor_pass1(lines):
    mnt = {}           # Macro Name Table: macro_name -> MDT index
    mdt = []           # Macro Definition Table: list of macro body lines
    ala_master = {}    # Argument List Array for each macro
    intermediate_code = []

    inside_macro = False
    current_macro = ""
    ala = {}
    mdt_ptr = 0

    for line in lines:
        line = line.strip()

        if line == "MACRO":
            inside_macro = True
            ala = {}
            continue

        elif line == "MEND":
            mdt.append("MEND")
            inside_macro = False
            ala_master[current_macro] = dict(ala)  # store a copy of ALA
            current_macro = ""
            continue

        if inside_macro:
            tokens = line.split()
            if current_macro == "":
                macro_name = tokens[0]
                current_macro = macro_name
                params = tokens[1].split(',') if len(tokens) > 1 else []
                for idx, param in enumerate(params):
                    ala[param.strip()] = f"#{idx}"
                mnt[macro_name] = mdt_ptr
            processed_line = line
            for param, idx in ala.items():
                processed_line = processed_line.replace(param, idx)
            mdt.append(processed_line)
            mdt_ptr += 1
        else:
            tokens = line.split()
            if tokens and tokens[0] in mnt:
                macro_name = tokens[0]
                args = tokens[1].split(',') if len(tokens) > 1 else []
                intermediate_code.append((macro_name, args))
            else:
                intermediate_code.append(line)

    return intermediate_code, mnt, mdt, ala_master

# Example usage
if __name__ == "__main__":
    input_lines = [
        "PRGM START",
        "MACRO",
        "INCR &ARG1,&ARG2",
        "ADD &ARG1,&ARG2",
        "MEND",
        "MOV A,B",
        "INCR X,Y",
        "SUB A,B"
    ]

    ic, mnt, mdt, ala = macro_processor_pass1(input_lines)

    print("Intermediate Code:")
    for line in ic:
        print(line)

    print("\nMNT (Macro Name Table):")
    for macro, ptr in mnt.items():
        print(f"{macro} -> MDT index {ptr}")

    print("\nMDT (Macro Definition Table):")
    for i, line in enumerate(mdt):
        print(f"{i}: {line}")

    print("\nALA (Argument List Array) per Macro:")
    for macro, table in ala.items():
        print(f"{macro}: {table}")
