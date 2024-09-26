#include <iostream>
#include "BrailleTranslator.h"

using namespace std;

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