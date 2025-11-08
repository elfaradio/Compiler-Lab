
import re
code = open("input.c").read()
keywords = {"int", "float", "if", "else", "return", "char",
            "double", "for", "while", "do", "void"}
pattern = {
    "Keyword": r"\b(?:int|float|if|else|return|char|double|for|while|do|void)\b",
    "Identifier": r"\b[A-Za-z_]\w*\b",
    "Number": r"\b\d+(\.\d+)?(e[+-]?\d+)?\b",
    "Char/String": r"\".*?\"|'.*?'",
    "Operator": r"[+\-*/%=<>!&|^~]+",
    "Symbol": r"[;{},()#\[\]]"
}
for typ, pat in pattern.items():
    tokens = re.findall(pat, code)
    if tokens:
        print(f"{typ}: {set(tokens)}")
