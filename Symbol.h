//
// Created by Maor Roizman Gheiler on 29/10/19.
//

#ifndef PROYECTO3_DRIVER_H
#define PROYECTO3_DRIVER_H

#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <cctype>

using namespace std;


enum Token_value
{
    NAME,		NUMBER,		END,
    PLUS='+',	MINUS='-',		MUL='*',		DIV='/',
    PRINT=';',	ASSIGN='=',		LP='(',		RP=')', POW='^',
};

Token_value curr_tok = PRINT;
double number_value;
string string_value;
map<string,double> table;
int no_of_errors;
istream* input;			//pointer to input stream



double expr(bool get);
double term(bool get);
double prim(bool get);
Token_value get_token();
double error(const string& s);

#endif //PROYECTO3_DRIVER_H
