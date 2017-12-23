

//#ifndef lexical_h
#define lexical_h

#include <iostream>
#include <fstream>

using namespace std;

enum SYMBOL
{
    begint, fort, endt, idt, addop, relop, semicolon, comma, unknownt, numt, literalt, eofilet
};

extern int value;
extern float valuer;
extern char ch;
extern string lexeme;
extern SYMBOL Token;
extern string Lteral;
extern string reswords[3];

class Lexical {
    
public:
    Lexical();
    ~Lexical();
    void GetNextToken();
    void displayToken();
    
private:
    void InitResWords();
    void ProcessToken();
    void OpToken();
    void ConstantToken();
    void ProcessLiteralToken();
    
    ifstream fin;
    
};

    
  
    
    
    











































