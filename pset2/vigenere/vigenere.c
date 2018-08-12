// vigenere cipher

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]){
    // check for input errors
        if(argc != 2) {
                printf("Error on input");
                exit(1);
        }

        string key = argv[1];
        int len = strlen(key);
        // store key chars in array
        int keys[len];
        // set counter to track key state
        int counter = 0;
        // check that key is all alpha
        for (int i = 0; i < strlen(key); i++) {
                if(!isalpha(key[i])) {
                        printf("Non-alpha in key");
                        exit(1);
                } else {
                    // set key to 0-26 for both upper and lower
                        if(isupper(key[i])) {
                            // add to array
                                keys[i] = key[i] - 65;
                        } else {
                                keys[i] = key[i] - 97;
                        }
                }
        }
                // input and output
                string input = get_string("Input: ");
                printf("plaintext: %s\n", input);
                printf("ciphertext: ");


                for(int i = 0; i < strlen(input); i++) {
                        // reset counter when at key len
                        if(counter > len-1) {
                                counter = 0;
                        }
                        // make sure input is alpha
                        if(isalpha(input[i])) {
                                // if upper case then...
                                if(isupper(input[i])) {
                                        // get keys from array
                                        int convertKey = keys[counter % (strlen(key))];
                                        //subtracting 'A' minuses 65 to make each letter fit 0-26 mold
                                // magically returns a letter, but subracts numbers
                                        int convertInput = input[i] - 'A';
                                        int result =  (convertInput +  convertKey) % 26 + 'A';
                                        printf("%c", result);
                                        counter++;
                                // if lower...
                                }  else if(!isupper(input[i])) {
                                        int convertKey = keys[counter % (strlen(key))];
                                        int convertInput = input[i] - 'a';
                                        int result =  (convertInput +  convertKey) % 26 + 'a';
                                        printf("%c", result);
                                        counter++;

                                }
                                // if not alpha just print input, not key
                        } else if(!isalpha(input[i])) {
                                printf("%c", input[i]);
                        }
                }
        printf("\n");
        return 0;
}



