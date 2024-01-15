#include <stdio.h>

#define _INTEIRO_ 0
#define _PONTO_FLUTUANTE_ 1
#define _ERRO_ 2

/*
Consideramos o valor 0,0 como ponto flutuante e recusamos +0,0 e -0,0.
*/

int scanner(char *palavra){
    int i = 0;
    q0:
        if (palavra[i] == '0') goto q1;
        else if (palavra[i] == ',') goto q2;
        else if (palavra[i] == '+' || palavra[i] == '-') goto q3;
        else if (palavra[i] == '1'
        || palavra[i] == '2'
        || palavra[i] == '3'
        || palavra[i] == '4'
        || palavra[i] == '5'
        || palavra[i] == '6'
        || palavra[i] == '7'
        || palavra[i] == '8'
        || palavra[i] == '9') goto q4;
        else return(_ERRO_);
    q1:
        i++;
        if (palavra[i] == ',') goto q2;
        else if (palavra[i] == '1'
        || palavra[i] == '2'
        || palavra[i] == '3'
        || palavra[i] == '4'
        || palavra[i] == '5'
        || palavra[i] == '6'
        || palavra[i] == '7'
        || palavra[i] == '8'
        || palavra[i] == '9'
        || palavra[i] == '+' 
        || palavra[i] == '-') goto q8;
        else if (palavra[i] == '\0') return (_INTEIRO_);
        else return(_ERRO_);
    q2:
        i++;
        if (palavra[i] == '0'
        || palavra[i] == '1'
        || palavra[i] == '2'
        || palavra[i] == '3'
        || palavra[i] == '4'
        || palavra[i] == '5'
        || palavra[i] == '6'
        || palavra[i] == '7'
        || palavra[i] == '8'
        || palavra[i] == '9') goto q7;
        else if (palavra[i] == '+' 
        || palavra[i] == '-'
        || palavra[i] == ',') goto q8;
        else return(_ERRO_);
    q3:
        i++;
        if (palavra[i] == '1'
        || palavra[i] == '2'
        || palavra[i] == '3'
        || palavra[i] == '4'
        || palavra[i] == '5'
        || palavra[i] == '6'
        || palavra[i] == '7'
        || palavra[i] == '8'
        || palavra[i] == '9') goto q4;
        else if(palavra[i] == '+'
        || palavra[i] == '-'
        || palavra[i] == ',') goto q8;
        else if (palavra[i] == '0') goto q5;
        else return(_ERRO_);
    q4:
        i++;
        if (palavra[i] == '0'
        || palavra[i] == '1'
        || palavra[i] == '2'
        || palavra[i] == '3'
        || palavra[i] == '4'
        || palavra[i] == '5'
        || palavra[i] == '6'
        || palavra[i] == '7'
        || palavra[i] == '8'
        || palavra[i] == '9') goto q4;
        else if (palavra[i] == ',') goto q2;
        else if(palavra[i] == '+'
        || palavra[i] == '-') goto q8;
        else if (palavra[i] == '\0') return (_INTEIRO_);
        else return(_ERRO_);
    q5:
        i++;
        if (palavra[i] == '0'
        || palavra[i] == '1'
        || palavra[i] == '2'
        || palavra[i] == '3'
        || palavra[i] == '4'
        || palavra[i] == '5'
        || palavra[i] == '6'
        || palavra[i] == '7'
        || palavra[i] == '8'
        || palavra[i] == '9'
        || palavra[i] == '+'
        || palavra[i] == '-') goto q8;
        else if(palavra[i] == ',') goto q6;
        else return(_ERRO_);
    q6:
        i++;
        if (palavra[i] == '0') goto q6;
        else if(palavra[i] == '+'
        || palavra[i] == '-'
        || palavra[i] == ',') goto q8;
        else if (palavra[i] == '1'
        || palavra[i] == '2'
        || palavra[i] == '3'
        || palavra[i] == '4'
        || palavra[i] == '5'
        || palavra[i] == '6'
        || palavra[i] == '7'
        || palavra[i] == '8'
        || palavra[i] == '9') goto q7;
        else return(_ERRO_);
    q7:
        i++;
        if (palavra[i] == '0'
        || palavra[i] == '1'
        || palavra[i] == '2'
        || palavra[i] == '3'
        || palavra[i] == '4'
        || palavra[i] == '5'
        || palavra[i] == '6'
        || palavra[i] == '7'
        || palavra[i] == '8'
        || palavra[i] == '9') goto q7;
        else if (palavra[i] == '\0') return(_PONTO_FLUTUANTE_);
        else if(palavra[i] == '+'
        || palavra[i] == '-'
        || palavra[i] == ',') goto q2;
        else return(_ERRO_);
    q8:
        i++;
        if (palavra[i] == '0'
        || palavra[i] == '1'
        || palavra[i] == '2'
        || palavra[i] == '3'
        || palavra[i] == '4'
        || palavra[i] == '5'
        || palavra[i] == '6'
        || palavra[i] == '7'
        || palavra[i] == '8'
        || palavra[i] == '9'
        || palavra[i] == '+'
        || palavra[i] == '-'
        || palavra[i] == ',') goto q8;
        else if (palavra[i] == '\0') return(_ERRO_);
        else return(_ERRO_);
}

int main()
{
    char palavra[] = "+14,0";
    int a = scanner(palavra);
    printf("%i\n", a);
    return 0;
}