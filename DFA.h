#ifndef DFA_H
#define DFA_H

#include <bits/stdc++.h>

class DFA {
private:
    char current_state;

public:
    char initial_state;
    std::map<std::pair<char, char>, char> transitions;
    std::set<char> final_states;
    std::set<char> alphabet;

    DFA() : current_state('a'), initial_state('a') {}
    
    void reset() {
        current_state = initial_state;
    }
    
    bool process_symbol(char symbol) {
        auto transition = transitions.find({current_state, symbol});
        if (transition != transitions.end()) {
            current_state = transition->second;
            return true;
        }
        return false; 
    }
    
    bool process(const std::string& input) {
        reset();
        for (char symbol : input) {
            if (!process_symbol(symbol)) {
                return false; // Invalid transition encountered
            }
        }
        return is_accepting();
    }
    
    bool process_recursive(const std::string& input, char state) {
        if (input.empty()) {
            return final_states.find(state) != final_states.end();
        }
        
        char symbol = input[0];
        auto transition = transitions.find({state, symbol});
        if (transition == transitions.end()) {
            return false;
        }
        return process_recursive(input.substr(1), transition->second);
    }
    
    bool is_accepting() const {
        return final_states.find(current_state) != final_states.end();
    }
    
    char get_current_state() const {
        return current_state;
    }
    
    void add_transition(char from, char symbol, char to) {
        transitions[{from, symbol}] = to;
        alphabet.insert(symbol);
    }
    
    void add_final_state(char state) {
        final_states.insert(state);
    }
    
    void display_info() const {
        std::cout << "DFA Information:\n";
        std::cout << "Initial state: " << initial_state << "\n";
        std::cout << "Final states: ";
        for (char state : final_states) {
            std::cout << state << " ";
        }
        std::cout << "\nAlphabet: ";
        for (char symbol : alphabet) {
            std::cout << symbol << " ";
        }
        std::cout << "\nTransitions:\n";
        for (const auto& transition : transitions) {
            std::cout << "δ(" << transition.first.first << ", " 
                      << transition.first.second << ") = " << transition.second << "\n";
        }
    }
    
    void test_strings(const std::vector<std::string>& test_cases) {
        std::cout << "\nTesting strings:\n";
        std::cout << "----------------\n";
        for (size_t i = 0; i < test_cases.size(); ++i) {
            bool result = process(test_cases[i]);
            std::cout << "Test " << (i + 1) << ": \"" << test_cases[i] 
                      << "\" -> " << (result ? "Accepted" : "Rejected") << "\n";
        }
    }
};

#endif