#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// loop through key and make sure it's all alpha
// change key into alpha index

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// loop through key and make sure it's all alpha
// change key into alpha index

int main(int argc, char *argv[]){
    if(argc != 2) {
        printf("Error on input");
        exit(1);
    } else if(argc == 2) {
        // get string key
        string key = argv[1];
        // loop through check if alpha
        for(int j = 0;j < strlen(key);j++ ){

            // printf("%c ,", key[j]);
            // if not alpha, break
            if(!isalpha(key[j])){
                printf("Key must be all alpha");
                exit(1);
            } else {
                // get user input
                string input = get_string("Input: ");
    //     // print plaintext
                printf("plaintext: %s\n", input);

                for(int i = 0; i < strlen(input); i++) {
                // if alpha do this
                    if(isalpha(input[i])) {
                    // if upper case to this
                        if(isupper(input[i])) {
            //                     // convert to alpha index -65
                            int convertInput = input[i] - 65;
                            // int convertKey = key[j] - 65;
                                // perform cipher shift
                            // int result = ((convertInput +  arg1) % 26) + 65;

                            printf("%c", convertInput);
                                // if not upper do this
                        }
                        // else if(!isupper(input[i])) {
                        //     // covert to alpha index - 97
                        //     int convert = input[i] - 97;
                        //     // cipher
                        //     int result = ((convert +  arg1) % 26) + 97;
                        //     printf("%c", result);
                        // }
            //             // if not alpha, just print
        //         } else {
        //                 printf("%c", input[i]);
        //         }
                    }
                }
            }
    //
    //     // print ciphertext string
    //     // loop over entire string length
        }
    // printf("\n");
    }
}
