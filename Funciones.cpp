/*
Funciones en C++
- Fuentes: Actividad de clase, ProgramaciÃ³n Avanzada UP y
           C++ Programming Course - Beginner to Advanced - FreeCodeCamp, Daniel Gakwaya - https://youtu.be/8jLOx1hD3_o 
- Editado / modificado por: Eduardo RodrÃ­guez
- Fecha: 08/09/2023
*/

#include <bits/stdc++.h>

using namespace std;

// Declaracion de funciones (Prototipos, no incluyen return)
int max(size_t a, size_t b);

size_t min(size_t a, size_t b);

double mult(double a, double b);

// Sobrecarga de funciones
double max(double a, double b);

float max(float a, float b, float c);


int main(){

    // int a {8};
    // int b {10};

    // float a {8.5f};
    // int b {10};

    float a {8.5f};
    float b {10.0f};
    float c {1.0f};

    int result = max(a,b);
    cout << "Mayor entre " << a << " y " << b << ": " << result << endl;

    result = min(a,b);
    cout << "Menor entre " << a << " y " << b << ": " << result << endl;

    result = mult(a,b);
    cout << "Multiplicacion de " << a << " y " << b << ": " << result << endl;
    
    auto result2 = max(a,b,c);
    cout << "Mayor entre " << a << " y " << b << ": " << result2 << endl;
    
    return 0;
}

// Definicion de funciones
int max(size_t a, size_t b){
    if(a > b)
        return a;
    else
        return b;
}

size_t min(size_t a, size_t b){
    if(a < b)
        return a;
    else
        return b;
}

double mult(double a, double b){
    return a * b;
}

// Sobrecarga de funciones: La sobrecarga no se da por el tipo de retorno
// Si no por la cantidad de parametros, su tipo o su orden.
double max(double a, double b){
    cout << "Llamada a max (double)" << endl;
    return (a > b) ? a : b;
}

float max(float a, float b, float c){
    cout << "Llamada a max (float)" << endl;
    int mult = (a > b) ? a : b;
    return mult * c;
}