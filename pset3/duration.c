#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// bool is_rest(string s);
// int duration(string str);
int duration(string fraction);

// attempt to use function
// int getter(string letter, bool sharp, bool flat, int initfreq, int semitone, int freq);
    // int getter(int letter bool sharp bool flat int initfreq int semitone){

int main() {

    string input = get_string("input: ");
    int f = duration(input);
    printf("%i\n", f);
    // b
    // duration("1/2");
//     string str = "1/4";
//     int y = str[2];
//     // int x = atoi(y);
//     printf("%i", y );
//     // int x = atoi(str[2]);
//     // printf("%i", x);
//     // for(int i = 0;i < 3;i++){
//     //     int x = atoi(str[i]);
//     //     printf("%c", x);
//     // }
//     // int x = atof("1/4");
//     // printf("%i", x);

}

int duration(string fraction)
{
    int nom;
    int denom;
    int eights;
    switch(fraction[0]){
        case '1':
            nom = 1;
            // printf("non reassinged: %i\n", nom);
        break;
        case '2':
            nom = 2;
            // printf("non reassinged: %i\n", nom);
        break;
        case '3':
            nom = 3;
            // printf("non reassinged: %i\n", nom);
        break;
        case '4':
            nom = 4;
            // printf("non reassinged: %i\n", nom);
        break;
        case '5':
            nom = 5;
            // printf("non reassinged: %i\n", nom);
        break;
        case '6':
            nom = 6;
            // printf("non reassinged: %i\n", nom);
        break;
        case '7':
            nom = 7;
            // printf("non reassinged: %i\n", nom);
        break;
        case '8':
            nom = 8;
            // printf("non reassinged: %i\n", nom);
        break;

    }

    switch(fraction[2]){
        case '1':
            denom = 1;
            // printf("whole");
            // return 8;
        break;
        case '2':
            denom = 2;
        // printf("half");
            // return 4;
        break;
        case '4':
            denom = 4;
        // printf("denom quarter %i\n", denom);
            // return 2;
        break;
        case '8':
            denom = 8;
        // printf("denom eighth %i\n", denom);
            // return 1;
        break;

    }
    switch(denom){
        case 1:
            eights = 8;
            // printf("eights: %i\n", eights);
        break;
        case 2:
            eights = nom * 4;
            // printf("eights: %i\n", eights);
        break;
        case 4:
            eights = nom * 2;
            // printf("eights: %i\n", eights);
        break;
        case 8:
            eights = nom * 1;
            // printf("eights: %i\n", eights);
        break;
    }

    // printf("nom/denom %i\n ", (nom +denom) );
    return eights;
}