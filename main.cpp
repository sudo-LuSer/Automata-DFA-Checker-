#include "DFA.h"

using namespace std;

int main() {
    DFA automaton;
    

    automaton.initial_state = 'a';
    automaton.add_final_state('b');
    

    for (char state : {'a', 'b'}) {

        for (char odd : {'1', '3', '5', '7', '9'}) {
            automaton.add_transition(state, odd, 'a');
        }

        for (char even : {'0', '2', '4', '6', '8'}) {
            automaton.add_transition(state, even, 'b');
        }
    }

    automaton.display_info();
    
    vector<string> test_cases = {
        "10100001010101010000001000100100001010000101010001010101010100101018210731973918378917398137918378100001010100101010101001000111975",
        "123",
        "246",
        "13579",
        "02468",
        "1",
        "0",
        ""  
    };
    
    automaton.test_strings(test_cases);
    
    cout << "\nStep-by-step processing demonstration:\n";
    cout << "--------------------------------------\n";
    string demo_input = "123";
    automaton.reset();
    cout << "Processing: \"" << demo_input << "\"\n";
    cout << "Start state: " << automaton.get_current_state() << "\n";
    
    for (size_t i = 0; i < demo_input.length(); ++i) {
        char symbol = demo_input[i];
        bool valid = automaton.process_symbol(symbol);
        cout << "After symbol '" << symbol << "': state = " << automaton.get_current_state();
        cout << " (" << (valid ? "valid" : "invalid") << " transition)\n";
    }
    
    cout << "Final state: " << automaton.get_current_state() << "\n";
    cout << "String " << (automaton.is_accepting() ? "accepted" : "rejected") << "\n";
    
    return 0;
}