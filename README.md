## 🎓 Project Context

This project was developed for the **Formal Languages, Automata, and Compilers (LFAC)** course at the Faculty of Computer Science, "Alexandru Ioan Cuza" University of Iași.

The goal was to build a functional compiler for a custom language using:
* **Flex:** For lexical analysis and tokenization.
* **Bison:** For syntax and semantic analysis (LALR grammar).
* **C++:** For managing the Symbol Table, scope control, and internal data structures.


# 🚀 C-LFA (C for Formal Automata) Compiler

C-LFA is a C-style imperative language designed for educational purposes. It features a strict modular structure, object-oriented capabilities, and support for recursive algorithms and type inference.


---

## 🏗️ Language Architecture

The compiler enforces a strict sequence of code blocks. A valid program must follow this exact order:

1. **`class_section`**: Definitions of classes, attributes, and methods.
2. **`global_var_section`**: Variables accessible throughout the entire program.
3. **`global_fun_section`**: Standalone functions and complex algorithms.
4. **`main` ... `end_main`**: The mandatory entry point for execution.

---

## 🛠️ Feature Set

### 1. Object-Oriented Programming
Define blueprints with specific sections for data and behavior:
* **`class_var_section`**: Define class attributes (e.g., `int sir[5]`).
* **`class_methods_section`**: Functions that manipulate class data.
* **Instantiating**: Create objects using the `new` keyword: `MathToolbox tool = new MathToolbox();`.

### 2. Variable Scoping & Data Types
The compiler manages a Symbol Table to handle different scopes and supports the following types:

| Type | Description |
| :--- | :--- |
| **`int`** | Standard 32-bit integers. |
| **`float`** | Floating-point numbers. |
| **`bool`** | Boolean logic (`true`/`false`). |
| **`char` / `string`** | Character and text storage. |
| **`auto`** | **Type Inference:** Deduces type from the local assignment. |
| **Arrays** | Fixed-size collections (e.g., `int v[10]`). |

### 3. Built-in Keywords & Logic
* **`Print()`**: Function to output variables or strings.
* **`newline`**: Specialized constant for line breaks.
* **Control Flow**: Supports standard `if-else`, `while`, and `for` loops.
* **Operators**: Arithmetic (`+`, `-`, `*`, `/`, `%`) and Logical (`==`, `>`, `<`, `&&`, `||`).

---

## 🚀 How to Compile and Run

To build and use the **C-LFA** compiler, follow these steps. Ensure you have `flex`, `bison`, and `g++` installed on your system.

A `compile.sh` script is provided to automate the Flex and Bison build process.
Grant execution permissions to the script:
   ```bash
   chmod +x ./compile.sh
   ```

Secondly, you must run it:
```bash
./compile.sh
```

A file named `compiler` should've been created. To now compile a custom C-LFA file you created, run:
```bash
./compiler <relative path to file>
```

Upon successful execution, the compiler automatically generates two diagnostic files:

* **`tables.txt`**: This file contains the **Symbol Table** for each identified scope (Global, Class, and Local), detailing identifiers, data types, and function signatures.
* **`ast.txt`**: This file provides the **Abstract Syntax Tree (AST)** of the source code, representing its hierarchical structure and execution logic.

For code snippets, you can check the `examples` folder.
For the mathBox.txt file, you'll get an output of:
```bash
1. OOP Section - Class Vector: 10 50 20 40 30 
Sum of class elements:  150 
2. Recursion Section - Factorial of 5: 120 
3. Algorithm Section - Bubble Sort: Before: 56 2 38 12 91 8 72 5 23 16 
After: 2 5 8 12 16 23 38 56 72 91 

4. Searching Section - Binary Search for 23: Found at index:  5 
```