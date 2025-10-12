#include <bits/stdc++.h>
using namespace std;

class DFA {
public:
    char initial_state;
    map<pair<char, char>, char> transitions;
    char final_state;

    bool process(const string& input, char current_state) {
        if (input.empty()) {
            return current_state == final_state;
        }
        
        char symbol = input[0];
        char next_state = transitions[{current_state, symbol}];
        return process(input.substr(1), next_state);
    }
};

int main() {
    DFA automaton;
    automaton.initial_state = 'a';
    automaton.final_state = 'b';

    for (char state : {'a', 'b'}) {
        for (char odd : {'1', '3', '5', '7', '9'}) {
            automaton.transitions[{state, odd}] = 'a';
        }
        for (char even : {'0', '2', '4', '6', '8'}) {
            automaton.transitions[{state, even}] = 'b';
        }
    }

    string test_input = "10100001010101010000001000100100001010000101010001010101010100101018210731973918378917398137918378100001010100101010101001000111975";
    cout << automaton.process(test_input, automaton.initial_state) << endl;

    return 0;
}
