#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int string_loop(string str);
int main(){
    string_loop("#???");
}

int string_loop(string str){
    int len = strlen(str);
    char char_arr[len];
    int char_counter = 0;
    char non_char_arr[len];
    int non_char_counter = 0;
    char digit_arr[len];
    int digit_counter = 0;
    for(int i = 0; i < strlen(str); i++){
        if(isalpha(str[i])){
            char_arr[char_counter] = str[i];
            char_counter++;
        } else if(isdigit(str[i])){
            digit_arr[digit_counter] = str[i];
            digit_counter++;
        } else {
            non_char_arr[non_char_counter] = str[i];
            non_char_counter++;
        }
        // printf("%c\n", str[i]);
    }
    // printf("c: %s",char_arr);
    // printf("d: %s",digit_arr);
    printf("nc: %s",non_char_arr);
    return 0;
}

// char str[] = "The long and winding road";
// // int len = strlen(str);

// // for (int i = 0; i < len; i++) {
// for (int i = 0; i < len; i++){
//     printf("%c", str[i]);
// // }
// char *source = "This is an example.";
// int i;

// for (i = 0; i < strlen(source); i++){

//     printf("%c", source[i]);

// }



// int my_func(int i);
// int k = 1;

// int main() {
// my_func(k);
// //Where is the return value?

// printf("%d is the return value.\n", my_func(k));

// int double_func_value = (2 * my_func(k));

// printf("%d is the return value.\n", double_func_value);
// }

// int my_func(i){
// return i;
// }