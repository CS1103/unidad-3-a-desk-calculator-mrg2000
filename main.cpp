#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <cctype>

#include "Parser.h"
#include "Metodos_Generales.h"
#include "Symbol.h"
using namespace std;


int main(int argc, char* argv[]) {

    Input(argc,argv);

    VarPredefinadas();

    Verificar();

    return no_of_errors;
}


