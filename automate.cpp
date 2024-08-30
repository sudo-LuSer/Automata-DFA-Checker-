#include <bits/stdc++.h>
using namespace std;
class automata_TYPEDFA{
	public: 
		char q0; 
		map<pair<char , char> , char> delta; 
		char F; 
		bool run(string word , char etat){
			if(word=="" && F== etat){
				return true; 
			}
			else if(word=="" && F != etat){
				return false;
			}
			char w = (word[0]);
			word = word.substr(1 , word.size());
			return run(word , delta[make_pair(etat , w)]);
		}
};
int main(){
	automata_TYPEDFA a; 
	a.q0 = 'a';
	a.F = 'b';
	a.delta[make_pair('a' , '1')] = 'a';
	a.delta[make_pair('a' , '3')] = 'a';
	a.delta[make_pair('a' , '5')] = 'a';
	a.delta[make_pair('a' , '7')] = 'a';
	a.delta[make_pair('a' , '9')] = 'a';
	a.delta[make_pair('a' , '0')] = 'b';
	a.delta[make_pair('a' , '2')] = 'b';
	a.delta[make_pair('a' , '4')] = 'b';
	a.delta[make_pair('a' , '6')] = 'b';
	a.delta[make_pair('a' , '8')] = 'b';
	a.delta[make_pair('b' , '1' )] = 'a';
	a.delta[make_pair('b' , '3' )] = 'a';
	a.delta[make_pair('b' , '5' )] = 'a';
	a.delta[make_pair('b' , '7' )] = 'a';
	a.delta[make_pair('b' , '9' )] = 'a';
	a.delta[make_pair('b' , '0')] = 'b';
	a.delta[make_pair('b' , '2')] = 'b';
	a.delta[make_pair('b' , '4')] = 'b';
	a.delta[make_pair('b' , '6')] = 'b';
	a.delta[make_pair('b' , '8')] = 'b';
	string w = "10100001010101010000001000100100001010000101010001010101010100101018210731973918378917398137918378100001010100101010101001000111975";
	cout<<a.run(w , a.q0)<<endl;
}