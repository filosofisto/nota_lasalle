/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: eduardo
 *
 * Created on May 20, 2017, 11:25 AM
 */

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

using namespace std;

const float E_VALUE  = (9+10)/2.0;
const float O_VALUE  = (8+8.9)/2.0;
const float S_VALUE  = (6+7.9)/2.0;
const float P_VALUE  = (3+5.9)/2.0;
const float I_VALUE  = (0.1+2.9)/2.0;
const float SR_VALUE = 0;

float value(char *);
void usage();
char *media_final(float);

/*
 * 
 */
int main(int argc, char** argv) {
    cout << "****************************" << endl;
    cout << "Calculadora de Notas LaSalle" << endl;
    cout << "****************************" << endl;
    
    /*printf("Quantidade de Parametros: %d\n", argc-1);
    for (int k = 1; k < argc; k++) {
        printf("Nota %s\n", argv[k]);
    }*/
    
    if (argc < 2) {
        usage();
        return EXIT_FAILURE;
    }
    
    float tot = 0;
    
    for (int k = 1; k < argc; k++) {
        printf("Totalizando Nota %s (valor: %.2f)\n", argv[k], value(argv[k]));
        tot = tot + value(argv[k]);
    }
    
    float media = tot / (argc-1);
    
    cout << "Total: " << tot << endl;
    cout << "Quantidade de Notas: " << argc-1 << endl;
    printf("Media Numerica: %.2f\n", media);
    cout << "Media Final --> " << media_final(media) << " <--" << endl;
    
    return 0;
}

float value(char *letra) {
    if (strcmp("E", letra) == 0)
        return E_VALUE;
    if (strcmp("O", letra) == 0)
        return O_VALUE;
    if (strcmp("S", letra) == 0)
        return S_VALUE;
    if (strcmp("P", letra) == 0)
        return P_VALUE;
    if (strcmp("I", letra) == 0)
        return I_VALUE;
    if (strcmp("SR", letra) == 0)
        return SR_VALUE;
    
    _exit(-1);
}

void usage() 
{
    cout << "Entre com as notas (letras) separadas por espaço" << endl;
}

char *media_final(float media)
{
    if (media < 0.1) 
        return (char*) "SR";
    
    if (media < 3.0)
        return (char*) "I";
    
    if (media < 6.0)
        return (char*) "P";
    
    if (media < 8.0)
        return (char*) "S";
    
    if (media < 9.0)
        return (char*) "O";
    
    return (char*) "E";
}