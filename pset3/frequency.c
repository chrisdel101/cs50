#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// bool is_rest(string s);
// int duration(string str);
int frequency(string note);

// attempt to use function
// int getter(string letter, bool sharp, bool flat, int initfreq, int semitone, int freq);
    // int getter(int letter bool sharp bool flat int initfreq int semitone){

int main() {

    string input = get_string("input: ");
    int f = frequency(input);
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
// // Calculates frequency (in Hz) of a note
int frequency(string note)
{
    int letter;
    int octave = 0;
    float semitone = 0;
    int initfreq = 440.0;
    float freq = 0;
    // bool double_sharp = false;
    // bool double_flat = false;
    bool sharp = false;
    bool flat = false;

    for(int i = 0;i < strlen(note); i++){
        if(note[i] == 'b'){
            flat = true;
        } else if((isalpha(note[i])) && (note[i] != 'b')){
            letter = note[i];
        } else if(note[i] == '#'){
            sharp = true;
        } else if(isdigit(note[i])){
            octave = note[i];
        } else {
            printf("%c is not valid", note[i]);
            return 1;
        }
    }

    printf("%c\n%c\n", letter, octave);
    // // printf("sharp: %s", sharp ? "true" : "false");
    // printf("flat: %s", flat ? "true" : "false");

// attempt to use function
    // getter(letter,sharp, flat,initfreq,semitone,freq);
        // int getter(int letter bool sharp bool flat int initfreq int semitone){


    switch(letter){
        case 'A':
            if(flat == true){
                semitone = -1.0;
            } else if(sharp){
                semitone = 1.0;
            } else {
                semitone = 0;
            }
        break;
        case 'B':
            if(flat == true){
                semitone = 1.0;
            } else if(sharp){
                semitone = 3.0;
            } else {
                semitone = 2.0;
            }
        break;
        case 'C':
            if(flat == true){
                semitone = -10.0;
            } else if(sharp){
                semitone = -8.0;
            } else {
                semitone = -9.0;
            }
        break;
        case 'D':
            if(flat == true){
                semitone = -8.0;
            } else if(sharp){
                semitone = -10.0;
            } else {
                semitone = -7.0;
            }
        break;
        case 'E':
            if(flat == true){
                semitone = -6.0;
            } else if(sharp){
                semitone = -4.0;
            } else {
                semitone = -5.0;
            }
        break;
        case 'F':
            if(flat == true){
                semitone = -5.0;
            } else if(sharp){
                semitone = -3.0;
            } else {
                semitone = -4.0;
            }
        break;
        case 'G':
            if(flat == true){
                semitone = -3.0;
            } else if(sharp){
                semitone = -1.0;
            } else {
                semitone = -2.0;
            }
        break;
    }
    // print semitone
    // printf("semitones: %f\n", semitone);
    // printf("octave: %c\n", octave);


    // get frequency
    // printf("no octave:%i\n", freq);

        // if(letter == 'A'){
        //       ///440
        //     if(sharp == true){
        //         freq = round(initfreq * pow(2.0, 1.0/12));
        //     } else if(flat == true){
        //         freq = round(initfreq / pow(2.0, 1.0/12));
        //     } else{
        //         freq = initfreq;
        //     }
        // } else if(letter != 'A') {
        //     // B
        // }
    freq = initfreq * pow(2.0, semitone/12.0);

    switch(octave){

        case '1':
            freq = ((freq / 2.0) / 2.0) / 2.0;
        break;
        case '2':
            freq = (freq / 2.0) / 2.0;
        break;
        case '3':
            freq = freq / 2.0;
        break;
        case '4':
            freq = freq * 1;
        break;
        case '5':
            freq = freq * 2.0;
        break;
        case '6':
            freq = (freq * 2.0) * 2.0;
        break;
        case '7':
            freq = ((freq * 2.0) * 2.0) * 2.0;
        break;
    }
    // printf("%i", freq);
    freq = round(freq);
    return freq;

}