//
// Created by Maor Roizman Gheiler on 29/10/19.
//

#ifndef PROYECTO3_DRIVER_H
#define PROYECTO3_DRIVER_H

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

#endif //PROYECTO3_DRIVER_H
