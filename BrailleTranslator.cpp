#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <cctype>
using namespace std;

//setting all the braille values to english characters
unordered_map<string, char> braille_translations = {
    {"0.....", 'a'}, {"0.0...", 'b'}, {"00....", 'c'}, {"00.0..", 'd'}, {"0..0..", 'e'}, 
    {"000...", 'f'}, {"0000..", 'g'}, {"0.00..", 'h'}, {".00...", 'i'}, {".000..", 'j'}, 
    {"0...0.", 'k'}, {"0.0.0.", 'l'}, {"00..0.", 'm'}, {"00.00.", 'n'}, {"0..00.", 'o'}, 
    {"000.0.", 'p'}, {"00000.", 'q'}, {"0.000.", 'r'}, {".00.0.", 's'}, {".0000.", 't'}, 
    {"0...00", 'u'}, {"0.0.00", 'v'}, {".000.0", 'w'}, {"00..00", 'x'}, {"00.000", 'y'}, 
    {"0..000", 'z'}, {"......", ' '}
};

//setting all the english characters to braille values
unordered_map<char, string> english_translations = {
    {'a', "0....."}, {'b', "0.0..."}, {'c', "00...."}, {'d', "00.0.."}, {'e', "0..0.."},
    {'f', "000..."}, {'g', "0000.."}, {'h', "0.00.."}, {'i', ".00..."}, {'j', ".000.."},
    {'k', "0...0."}, {'l', "0.0.0."}, {'m', "00..0."}, {'n', "00.00."}, {'o', "0..00."},
    {'p', "000.0."}, {'q', "00000."}, {'r', "0.000."}, {'s', ".00.0."}, {'t', ".0000."},
    {'u', "0...00"}, {'v', "0.0.00"}, {'w', ".000.0"}, {'x', "00..00"}, {'y', "00.000"},
    {'z', "0..000"}, {' ', "......"}    
};

//map contaning digits to braille
unordered_map<char, string> digit_to_braille = {
    {'1',"0....."}, {'2',"0.0..."}, {'3',"00...."}, {'4',"00.0.."}, {'5',"0..0.."},
    {'6',"000..."}, {'7',"0000.."}, {'8',"0.00.."}, {'9',".00..."}, {'0',".000.."}
};

//map containing braille to digits
unordered_map<string, char> braille_to_digits = {
    {"0.....",'1'}, {"0.0...",'2'}, {"00....",'3'}, {"00.0..",'4'}, {"0..0..",'5'},
    {"000...",'6'}, {"0000..",'7'}, {"0.00..",'8'}, {".00...",'9'}, {".000..",'0'}
};

//capitalization
const string capital_braille = ".....0";

//number
const string number_braille = ".0.000";

//checks if input braille or valid 
bool is_braille(const string& input){
    for(char x : input){
        if (x != '0' && x != '.' && x != ' '){
            return false;
        }
    }
    return true;

}

//english to braille conversion
string english_to_braille(const string& input){
    
    string output = "";
    bool isNumber = false;

    for (char x : input){
        if (isalpha(x)){
            if (isupper(x)){
                /*if upper case, upper case braille symbol will be outputted and then it will 
                be converted to lowercase so it can be found in the english to braille map*/
                output += capital_braille;
                x = tolower(x);
            }
            output += english_translations[x];
            isNumber = false;
        }
        else if (isdigit(x)){
            if (!isNumber){
                /*if number, number braille symbol will be outputted and then it will 
                so it can be found in the digit to braille map*/
                output += number_braille;
                isNumber = true;
            }
            output += digit_to_braille[x];
        }
        else if(x == ' '){
            output += english_translations[' '];
            isNumber = false;
        }
    }
    return output;
}

//braile to english conversion 
string braille_to_english(const string& input){
    string output = "";

//checks if the input is divisible by 6 so that it can translate
    if (input.length()% 6 !=0){
        cerr <<"Invalid number of characters. Should be multiples of 6." << endl;
        return "";
    }
    
    bool capital_next = false;
    bool isNumber = false;

    for (size_t i = 0; i < input.length(); i += 6) {
        string braille_character = input.substr(i, 6);

        cout << "Translating Braille: " << braille_character << endl;
        //if braille says capitalized, then capitalize it
        if (braille_character == capital_braille){
            capital_next = true;
        }
        else if (braille_character == number_braille){
            isNumber = true;
        }
        //use number map if isNumber is true
        else if (isNumber && braille_to_digits.find(braille_character) != braille_to_digits.end()){
            output += braille_to_digits[braille_character];
        }
        //If the Braille character is a valid letter, translate it
        else if (braille_translations.find(braille_character) != braille_translations.end()){
            char translated_character = braille_translations[braille_character];

            //capitalization
            if (capital_next){
                translated_character = toupper(translated_character);
                capital_next = false;
            }
           //add translated character to the output
           output += translated_character; //unknown
            }
        else{
            cerr << "Unknown Braille Character " << braille_character << endl;
            return "";        
        }
        }
         return output;
    }


int main(int argc, char* argv[]){
    //check if there are enough arguments
    if (argc<2){
        cerr << "Usage: " << argv[0] << "<text>" << endl;
        return 1;
    }
    //all arguments into one string from command line
    string input = "";
    for (int i = 1; i<argc; i++){
        if (i>1) input += " "; //space between each word
        input += argv[i]; //each argument gets put in the input string
    }

    /*determine which type of input it is either english 
    or braille and then convert it*/
    if(is_braille(input)){
        cout << braille_to_english(input) << endl;
    }
    else{
        cout << english_to_braille(input) << endl;
    }
return 0;
}