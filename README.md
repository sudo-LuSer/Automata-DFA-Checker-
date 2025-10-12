# DFA Automata Checker

A C++ implementation of a **Deterministic Finite Automaton (DFA)** with enhanced features for both educational and practical use.

---

## 🚀 Features

- **Multiple Final States** — Supports multiple accepting states  
- **Flexible Transitions** — Simple interface for adding transitions  
- **Two Processing Modes** —  
  - *Iterative*: safe for long input strings  
  - *Recursive*: for comparison and visualization  
- **Step-by-step Processing** — Trace automaton execution in detail  
- **Validation** — Detects invalid transitions or undefined states  
- **Comprehensive Testing** — Built-in testing utility  
- **Informative Display** — Shows configuration and structure of the automaton

---

## 🧩 Class Overview

### Key Methods

| Method | Description |
|--------|--------------|
| `process(string)` | Processes a complete input string (iterative) |
| `process_recursive(string, state)` | Processes recursively for visualization |
| `process_symbol(char)` | Processes a single symbol |
| `reset()` | Resets the automaton to its initial state |
| `is_accepting()` | Checks if the current state is accepting |
| `add_transition(from, symbol, to)` | Adds a new transition |
| `add_final_state(state)` | Adds an accepting state |
| `display_info()` | Displays the automaton’s configuration |
| `test_strings(test_cases)` | Tests multiple input strings automatically |

---

## 💡 Example Usage

```cpp
#include <iostream>
#include "dfa.hpp" // Example header (if applicable)
using namespace std;

int main() {
    DFA automaton;
    automaton.initial_state = 'a';
    automaton.add_final_state('b');

    // Add transitions
    automaton.add_transition('a', '0', 'b');
    automaton.add_transition('a', '1', 'a');
    automaton.add_transition('b', '0', 'b');
    automaton.add_transition('b', '1', 'a');

    // Test a string
    bool result = automaton.process("1010");
    cout << "Result: " << (result ? "Accepted" : "Rejected") << endl;

    return 0;
}
```

---

## ⚙️ Building and Running

### 🔧 Compilation
```bash
g++ -std=c++11 -Wall -Wextra -o dfa main.cpp
```

### ▶️ Execution
```bash
./dfa
```

---

## 🧠 Example Automaton Description

The provided example implements a DFA that:

- **Accepts** strings where the **last digit is even**  
- **States**: `'a'` (last digit odd), `'b'` (last digit even)  
- **Alphabet**: Digits `0–9`  
- **Final state**: `'b'`

---

## 🎯 Applications

- Formal language recognition  
- Lexical analysis (compiler front-ends)  
- Pattern recognition and validation  
- Educational visualization for automata theory  

---

## 🧰 Optional: Makefile

```makefile
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGET = dfa
SOURCES = main.cpp

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: clean run
```
