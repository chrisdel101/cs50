// Helper functions for music

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "helpers.h"

int duration(char *fraction)
{
    int nom;
    int denom;
    int eights;
    // get the numerator
    switch (fraction[0])
    {
        case '1':
            nom = 1;
            break;
        case '2':
            nom = 2;
            break;
        case '3':
            nom = 3;
            break;
        case '4':
            nom = 4;
            break;
        case '5':
            nom = 5;
            break;
        case '6':
            nom = 6;
            break;
        case '7':
            nom = 7;
            break;
        case '8':
            nom = 8;
            break;
    }
    // get the denominator
    switch (fraction[2])
    {
        case '1':
            denom = 1;
            break;
        case '2':
            denom = 2;
            break;
        case '4':
            denom = 4;
            break;
        case '8':
            denom = 8;
            break;

    }
    // convert to eighths
    switch (denom)
    {
        case 1:
            eights = 8;
            break;
        case 2:
            eights = nom * 4;
            break;
        case 4:
            eights = nom * 2;
            break;
        case 8:
            eights = nom * 1;
            break;
    }
    return eights;
}

// // Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // track octaves
    int octave = 0;
    // track semitones
    float semitone = 0;
    // set to A = 440 - must be float
    int initfreq = 440.0;
    // freq must be a float to get proper rounding
    float freq = 0;
    bool sharp = false;
    bool flat = false;
    int letter;

    // set flat of sharp to T/F - ordered to cover all cases
    for (int i = 0; i < strlen(note); i++)
    {
        if (note[i] == 'b')
        {
            flat = true;
        }
        else if ((isalpha(note[i])) && (note[i] != 'b'))
        {
            letter = note[i];
        }
        // if alpha and not flat, # can still be added here
        else if (note[i] == '#')
        {
            sharp = true;
        }
        else if (isdigit(note[i]))
        {
            octave = note[i];
        }
        else
        {
            printf("%c is not valid", note[i]);
            return 1;
        }
    }

    // set number of semitones away from A
    switch (letter)
    {
        case 'A':
            if (flat == true)
            {
                semitone = -1.0;
            }
            else if (sharp)
            {
                semitone = 1.0;
            }
            else
            {
                semitone = 0;
            }
            break;
        case 'B':
            if (flat == true)
            {
                semitone = 1.0;
            }
            else if (sharp)
            {
                semitone = 3.0;
            }
            else
            {
                semitone = 2.0;
            }
            break;
        case 'C':
            if (flat == true)
            {
                semitone = -10.0;
            }
            else if (sharp)
            {
                semitone = -8.0;
            }
            else
            {
                semitone = -9.0;
            }
            break;
        case 'D':
            if (flat == true)
            {
                semitone = -8.0;
            }
            else if (sharp)
            {
                semitone = -6.0;
            }
            else
            {
                semitone = -7.0;
            }
            break;
        case 'E':
            if (flat == true)
            {
                semitone = -6.0;
            }
            else if (sharp)
            {
                semitone = -4.0;
            }
            else
            {
                semitone = -5.0;
            }
            break;
        case 'F':
            if (flat == true)
            {
                semitone = -5.0;
            }
            else if (sharp)
            {
                semitone = -3.0;
            }
            else
            {
                semitone = -4.0;
            }
            break;
        case 'G':
            if (flat == true)
            {
                semitone = -3.0;
            }
            else if (sharp)
            {
                semitone = -1.0;
            }
            else
            {
                semitone = -2.0;
            }
            break;
    }

    // calculate frequency based on semitones
    freq = initfreq * pow(2.0, semitone / 12.0);

    // multiply or divide value based on octave, doubling each time
    switch (octave)
    {
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
    // round up frequency
    freq = round(freq);
    return freq;

}

// Determines whether a string represents a rest
// \0 is rest
bool is_rest(string s)
{
    // if not \0, it is not a rest, or false
    if (s[0] != '\0')
    {
        return false;
    }
    else
    {
        // a rest
        return true;
    }
}