#include <iostream>
#include <sstream>
#include "parser.h"
using namespace std;
using namespace Table;

Lexer::Token_stream ts {&cin};

void calculate(){
    while(true){
        ts.get();
        if (ts.current().kind == Lexer::Kind::END) break;
        if (ts.current().kind == Lexer::Kind::PRINT) continue;
        std::cout << expr(false) << '\n';
    }
}

int main(int argc, char* argv[]) { 
    istream* input;
    switch (argc) {
        case 1: // read from standard input
            input=&cin;
            break;
        case 2: // read from argument string
            ts.set_input(new istringstream{argv[1]});
            break;
        default:
            error("Muchos argumentos");
            return 1;
    }
    table["pi"] = 3.1415926535897932385;
    table["e"] = 2.7182818284590452354;
    calculate();


    return no_of_errors;
}