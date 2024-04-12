#include <iostream>
#include <clocale> // salida espa�ol
using namespace std;

//soluci�n iterativa
bool balance(char c[], int inic) {
    int cont = 0;

    for (int i = inic; c[i] != '\0'; i++) {
        if (c[i] == '(') {
            cont++;
        } else if (c[i] == ')') {
            cont--;
        }
        // Si el cont se vuelve negativo en algún punto, significa que hay más ')' que '('
        if (cont < 0) { 
            return false;
        }
    }

    // Si el cont es 0 al final, significa que hay la misma cantidad de '(' que de ')'
    return cont == 0;
}


//Soluci�n intermedia
bool balanceDelegada(char c[], int inic, int cont) {

   //identifica el caso base
    if (c[inic] == '\0') {
        return cont == 0; 
    } else {
        return balance(c, inic);
    }
}

bool balanceRec(char c[], int inic, int cont){
    //caso base
    if (c[inic] == '\0') {
        return cont == 0; 
    } else if (cont < 0) {
        return false; 
    } else if (c[inic] == '(') {
        return balanceRec(c, inic + 1, cont + 1);
    } else if (c[inic] == ')') {
        return balanceRec(c, inic + 1, cont - 1); 
    } else{
        return balanceRec(c, inic + 1, cont);
    }
    
}

int main() {
    setlocale (LC_CTYPE, "Spanish");
    char c[50];
    cout << "Ingrese una cadena: ";
    cin.getline(c, 50);

    if (balanceDelegada(c,0,0)) {
        cout << "Los par�ntesis est�n balanceados\n";
    } else {
        cout << "Los par�ntesis no est�n balanceados\n";
    }



    return 0;
}

