//
// Created by Maor Roizman Gheiler on 29/10/19.
//

#ifndef PROYECTO3_PARSER_H
#define PROYECTO3_PARSER_H

#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <cctype>
#include "Symbol.h"
using namespace std;



Token_value get_token()
{
    char ch = 0;
    do { if(!cin.get(ch)) return curr_tok = END; }		// skip whitespace except '\n'
    while (ch != '\n' && isspace(ch));
    switch (ch)
    {
        case 0 :
            return curr_tok=END;
        case ';' :
        case '\n' :
            return curr_tok = PRINT;
        case '*' :
        case '/' :
        case '+' :
        case '-' :
        case '(' :
        case ')' :
        case '=' :
            return curr_tok = Token_value(ch);

        case '0' :	case '1' :	case '2' :	case '3' : 	case '4' :
        case '5' :	case '6' :	case '7' :	case '8' :	case '9' :
        case '.' :
            cin.putback(ch);
            cin >> number_value;
            return curr_tok = NUMBER;
        default:				// NAME, NAME =, or error
            if (isalpha(ch))
            {
                string_value = ch;
                while (cin.get(ch) && isalnum(ch)) string_value.push_back(ch);
                cin.putback(ch);
                return curr_tok = NAME;
            }
            error("Bad Token");
            return curr_tok = PRINT;
    }
}



double error(const string& s)
{
    no_of_errors++;
    cerr << "error : " << s << '\n';
    return 1;
}

#endif //PROYECTO3_PARSER_H
