//  Julia Aiello
//  main.cpp
//  pa.3
//

#include <iostream>
#include <fstream> 
#include <string>
#include <cstring> 
#include "lexical.h"


using namespace std;

int value;
float valuer;
char ch;
string lexeme;
SYMBOL Token;
string Literal;
ofstream inputfile;

string reswords[3];

Lexical::Lexical()
{
}

Lexical::~Lexical()
{
    
    
}

void Lexical::GetNextToken()
{
    value = 0;
    valuer = 0.0;
    
    int i = 1;
    
    while (!(fin.eof()))
    {
        lexeme[1] = ch;
        fin.get(ch);
        
    }
    
    if (fin.peek() == '\n')
    {
        i++;
    }
    
    if (!fin.eof())
    {
        ProcessToken();
        
    }
    
    else
    {
        fin.close();
        Token = eofilet;
    }
    
}

void Lexical::displayToken()
{
    cout << "Token" << "   " << "Lexeme" << "   " << "value/valuer/Literal " << endl;
    cout << Token << "      " << lexeme << "        " << value;
}

void Lexical::InitResWords()
{
    reswords(begint).copy("BEGIN",5,0);
    reswords(fort).copy("FOR",3,0);
    reswords(endt).copy("END",3,0);
    
}

void Lexical::ProcessToken()
{
    lexeme.at(0) = ch;
    fin.get(ch);
    
    if((lexeme.at(0) >= 'a' && lexeme.at(0) <= 'z'))
    {
        int counter = 0;
        if (!isdigit(lexeme.at(0)) & !isalpha(lexeme.at(0)) && lexeme.at(0) != '_')
        {
            
            int j = 0;
            bool flag = false;
            while (j <endt)
            {
                if (lexeme.compare(reswords[j]) == 0)
                {
                    Token = (SYMBOL)j;
                    displayToken();
                    flag = true;
                }
            }
            
            Token = idt;
            displayToken();
            return;
            
        }
        
        lexeme.at(counter) = ch;
        fin.get(ch);
    }
    
    else if (lexeme.at(0) >= '0' && lexeme.at(0) <= '9')
    {
        ConstantToken();
    }
    
    else if (lexeme.at(0) == '\"')
             {
                 ProcessLiteralToken();
             }
    else if (lexeme.at(0) == '/')
    {
        if (ch == '/' || ch == '*')
        {
            if (ch == '/')
            {
                while(ch != '\n')
                    fin.get(ch);
            }
            
            else if (ch == '*')
            {
                while(true)
                {
                    fin.get(ch);
                    if (ch == '*')
                    {
                        char peek_value = fin.peek();
                        if (peek_value == '/')
                        {
                            fin.get(ch);
                            
                            return;
                        }
                        
                        else
                            continue;
                    }
                }
            }
            
            else
            {
                cout << "ERROR";
            }
            
            GetNextToken();
        }
        
        else
        {
            OpToken();
        }
    }
    
    else if ((lexeme.at(0) == '+') || (lexeme.at(0) == '-') || (lexeme.at(0) == '/') || (lexeme.at(0) == '*' ))
    {
        if (ch == '=')
        {
            lexeme.at(1) = ch;
            Token = relop;
            fin.get(ch);
        }
        
        else
            OpToken();
    }
    
}

void Lexical::OpToken()
{
    if (lexeme.at(0) == '+' || lexeme.at(0) == '-')
    {
        Token = addop;
        return;
        
    }
    else if (lexeme.at(0) == '*' || lexeme.at(0) == '/')
    {
        Token = relop;
        return;
    }
    else if (lexeme.at(0) == ';')
    {
        Token = semicolon;
        return;
    }
    
    else if (lexeme.at(0) == ',')
    {
        Token = comma;
        return;
    }
    
    //add more delimiters
    
    else
    {
        Token = unknownt;
        cout << "Error";
        exit(0);
    }
}

void Lexical::ConstantToken()
{
    int i = 0;
    while (isdigit(ch))
    {
        lexeme.at(i++) = ch;
        fin.get(ch);
    }
    
    if (ch == '.')
    {
        lexeme.at(i++) = ch;
        fin.get(ch);
        if (isdigit(ch))
        {
            while (isdigit(ch))
            {
                lexeme.at(i++) = ch;
                fin.get(ch);
            }
            Token = numt;
            valuer = atof(lexeme.c_str());
            return;
        }
        Token = unknownt;
        cout << "Error" << endl;
        exit(0);
    }
    else {
        Token = numt;
        value = atoi(lexeme.c_str());
        return;
    }
}

void Lexical::ProcessLiteralToken()
{
    int i = 0;
    while (ch != '\"')
    {
        if (ch == '\n')
        {
            Token = unknownt;
            cout << "Error" << endl;
            exit(0); 
        }
        Literal.at(i++) = ch;
        fin.get(ch);
      
    }
    
    Token = literalt;
    fin.get(ch);
    return;

}




    int main ()
    {
        cout << "Please input file: " << endl << endl;
        
        Lexical myLex;
        ifstream fin;
        
        fin.open("test.txt");
        
        while (Token != eofilet)
        {
            myLex.GetNextToken();
            myLex.displayToken();
        }
        
        cout << endl << "success" << endl;
        fin.close();
        
        return 0;
        
    }
    
        


    
        

    




    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    











