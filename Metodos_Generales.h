//
// Created by Maor Roizman Gheiler on 29/10/19.
//

#ifndef PROYECTO3_METODOS_GENERALES_H
#define PROYECTO3_METODOS_GENERALES_H

#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <cctype>
#include "Symbol.h"
using namespace std;

void VarPredefinadas(){
    table["pi"] = 3.1415926535897932385;		// insert predefined names
    table["e"] = 2.7182818284590452354;
}


double expr(bool get)				// add and substract
{
    double left = term(get);

    for(;;)
        switch (curr_tok)
        {
            case PLUS :
                left += term(true);
                break;
            case MINUS :
                left -= term(true);
                break;
            default :
                return left;
        }
}



double term(bool get)				// multiply and divide
{
    double left = prim(get);

    for (;;)
        switch (curr_tok)
        {
            case MUL :
                left *= prim(true);
                break;
            case DIV :
                if (double d = prim(true))
                {
                    left /= d;
                    break;
                }
                return error("Dividido por 0");
            default :
                return left;
        }
}



double prim(bool get)				// handle primaries
{
    if (get) get_token();

    switch (curr_tok)
    {
        case NUMBER :			// floating point constant
        {
            double v = number_value;
            get_token();
            return v;
        }
        case NAME :
        {
            double& v = table[string_value];
            if (get_token() == ASSIGN) v = expr(true);
            return v;
        }
        case MINUS :			// unary minus
            return -prim(true);
        case LP :
        {
            double e = expr(true);
            if (curr_tok != RP) return error("')' expected");
            get_token();			//eat ')'
            return e;
        }
        default :
            return error("primary expected");
    }
}


// ------ INPUT FUNCTION -----

int Input(int argc, char* argv[]) {
    switch (argc) {
        case 1 :                // read from standard input
            input = &cin;
            break;
        case 2 :
            input = new istringstream(argv[1]);        // read argument string
            break;
        default :
            error("Too many arguments");
            return 1;
    }
}

void Verificar(){
    while (*input)
    {
        get_token();
        if (curr_tok == END) break;
        if (curr_tok == PRINT) continue;
        cout<< expr(false) <<endl;
    }

    if (input != &cin) delete input;
}

#endif //PROYECTO3_METODOS_GENERALES_H
