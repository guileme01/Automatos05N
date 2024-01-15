/*
Nome             TIA
Gabriel Ramos    32370229
Guilherme Leme   42136199
Mateus Reimberg  42105838
*/

#include <stdio.h>
#include <stdlib.h>

/*
E -> S$
S -> T K
K -> + T K
K -> - T K
K -> e
T -> F Z
Z -> * F Z
Z -> / F Z
Z -> e
F -> [S]
F -> X
X -> 0
X -> 1D|2D|3D|4D|5D|6D|7D|8D|9D
D -> 0D|1D|2D|3D|4D|5D|6D|7D|8D|9D
D -> e
*/

char lookahead;   /* Excepcionalmente variavel global */

int match(char t, char palavra[], int *pos){
	if (lookahead == t){
		lookahead = palavra[++(*pos)];
		return(1);
	}
	return(0);  
}

int E(char palavra[], int *pos);
int S(char palavra[], int *pos);
int K(char palavra[], int *pos);
int T(char palavra[], int *pos);
int Z(char palavra[], int *pos);
int F(char palavra[], int *pos);
int X(char palavra[], int *pos);
int D(char palavra[], int *pos);

int E(char palavra[], int *pos){
    if(S(palavra, pos) && match('$', palavra, pos)){
        return 1;
    }
    else{
        return 0;
    }
}

int S(char palavra[], int *pos){
    if(T(palavra, pos) && K(palavra, pos)){
        return 1;
    }
    else {
        return 0;
    }
}

int K(char palavra[], int *pos){
    if(match('+', palavra, pos)){
        if(T(palavra, pos) && K(palavra,pos)){
            return 1;
        }
        else {
            return 0;
        }
    }
    else if(match('-', palavra, pos)){
        if(T(palavra, pos) && K(palavra,pos)){
            return 1;
        }
        else {
            return 0;
        }
    }
    else{
        return 1;
    }
}

int T(char palavra[], int *pos){
    if(F(palavra, pos) && Z(palavra, pos)){
        return 1;
    }
    else{
        return 0;
    }
}

int Z(char palavra[], int *pos){
    if(match('*', palavra, pos)){
        if(F(palavra, pos) && Z(palavra,pos)){
            return 1;
        }
        else{
            return 0;
        }
    }
    else if(match('/', palavra, pos)){
        if(F(palavra, pos) && Z(palavra,pos)){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        return 1;
    }
}

int F(char palavra[], int *pos){
    if(match('[', palavra, pos) && S(palavra, pos) && match(']', palavra, pos)){
        return 1;
    }
    else if(X(palavra, pos)){
        return 1;
    }
    else{
        return 0;
    }
}

int X(char palavra[], int *pos){
    if(match('0', palavra, pos)){
        return 1;
    }
    else if(match('1', palavra, pos)){
        if(D(palavra, pos)){
            return 1;
        }
    }
    else if(match('2', palavra, pos)){
        if(D(palavra, pos)){
            return 1;
        }
    }
    else if(match('3', palavra, pos)){
        if(D(palavra, pos)){
            return 1;
        }
    }
    else if(match('4', palavra, pos)){
        if(D(palavra, pos)){
            return 1;
        }
    }
    else if(match('5', palavra, pos)){
        if(D(palavra, pos)){
            return 1;
        }
    }
    else if(match('6', palavra, pos)){
        if(D(palavra, pos)){
            return 1;
        }
    }
    else if(match('7', palavra, pos)){
        if(D(palavra, pos)){
            return 1;
        }
    }
    else if(match('8', palavra, pos)){
        if(D(palavra, pos)){
            return 1;
        }
    }
    else if(match('9', palavra, pos)){
        if(D(palavra, pos)){
            return 1;
        }
    }
    else{
        return 0;
    }
}

int D(char palavra[], int *pos){
    if(match('0', palavra, pos)){
        if(D(palavra, pos)){
            return 1;
        }
    }
    else if(match('1', palavra, pos)){
        if(D(palavra, pos)){
            return 1;
        }
    }
    else if(match('2', palavra, pos)){
        if(D(palavra, pos)){
            return 1;
        }
    }
    else if(match('3', palavra, pos)){
        if(D(palavra, pos)){
            return 1;
        }
    }
    else if(match('4', palavra, pos)){
        if(D(palavra, pos)){
            return 1;
        }
    }
    else if(match('5', palavra, pos)){
        if(D(palavra, pos)){
            return 1;
        }
    }
    else if(match('6', palavra, pos)){
        if(D(palavra, pos)){
            return 1;
        }
    }
    else if(match('7', palavra, pos)){
        if(D(palavra, pos)){
            return 1;
        }
    }
    else if(match('8', palavra, pos)){
        if(D(palavra, pos)){
            return 1;
        }
    }
    else if(match('9', palavra, pos)){
        if(D(palavra, pos)){
            return 1;
        }
    }
    else{
        return 1;
    }
}

void tratarErro(char palavra[], int *pos){
    if(*pos == 0){
        printf("\n\nA palavra nao pode iniciar com o caracter: %c\n\ns", palavra[*pos]);
    }
    else if(palavra[(*pos)] == '$'){
        printf("\n\nA palavra nao pode terminar com o caracter: %c\n\ns", palavra[(*pos)-1]);
    }
    else if( palavra[*pos] != '[' &&
        palavra[*pos] != ']' &&
        palavra[*pos] != '+' &&
        palavra[*pos] != '-' &&
        palavra[*pos] != '*' &&
        palavra[*pos] != '/' &&
        palavra[*pos] != '0' &&
        palavra[*pos] != '1' &&
        palavra[*pos] != '2' &&
        palavra[*pos] != '3' &&
        palavra[*pos] != '4' &&
        palavra[*pos] != '5' &&
        palavra[*pos] != '6' &&
        palavra[*pos] != '7' &&
        palavra[*pos] != '8' &&
        palavra[*pos] != '9' &&
        palavra[*pos] != '$'){
        printf("\n\nA palavra foi recusada por possuir um caracter que nao esta presente no alfabeto: %c\n\n", palavra[*pos]);
    }
    else{
        printf("\n\nA palavra foi recusada pois o caracter %c nao pode ser seguido do caracter %c\n\n", palavra[(*pos)-1], palavra[*pos]);
    }
}

int main(){
	char palavra[]= "[1+99]++1$";
	int pos=0;
	
	lookahead= palavra[pos];
	if (E(palavra, &pos))
	    printf("\nPalavra %s reconhecida\n\n", palavra);
    else
        tratarErro(palavra, &pos);
    system("PAUSE");
	return(0);
}