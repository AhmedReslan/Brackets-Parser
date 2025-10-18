# Bracket Parser

A simple **C++ console application** that checks whether parentheses, curly braces, and square brackets are balanced and properly nested within a given string.

## 🧩 Features
- Supports `()`, `{}`, and `[]`
- Ignores non-bracket characters  
- Provides real-time validation  
- Displays `true` or `false` for each input  

## ⚙️ How It Works
The program uses:
- A **stack** to track opening brackets  
- A **map** to match closing brackets with their corresponding opening ones  
- An **unordered set** to filter only bracket characters  

If every opening bracket has a properly ordered closing match, the function returns `true`; otherwise, `false`.

