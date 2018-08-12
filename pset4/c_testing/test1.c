// // to compile use make
// // to run use ./file


#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// int accidental(char note, bool status);
// char* concat(const char *s1, const char *s2);

// int main(void){
//         char* x = concat("hello", "there");
//         printf("%s", x);
// }

// concat string function
//    char* concat(const char *s1, const char *s2)
//     {
//         char *result = malloc(strlen(s1)+strlen(s2)+1);//+1 for the null-terminator
//         //in real code you would check for errors in malloc here
//         strcpy(result, s1);
//         strcat(result, s2);
//         return result;

//     }
//   int accidental(char note, bool status){
//           if((note == 'A') && (status == true)){
//                   printf("%s",'A'+'#');
//           } else if(note == 'A'){
//                   printf("%c",'A');
//           }
//           return 0;
//   }

// // int main(void){
// //     int j = 10;
// //     printf(j);
// // }

// int main(int argc, string argv[]){
//   if(argc == 2){
//     printf("hello, %s\n",  argv[1]);
//   } else {
//     printf("hello...\n");
//   }
// }

// int main(void){
//     string input = get_string("Input:");
//     int strSize = strlen(input);
//     string strings[strSize];
//      for(int i = 0; i < strlen(input); i++){
//       strings[i] = get_char(input[i]);
//   }
// //   printf("%s",strings);
// }
// main(int argc, char *argv)
// int x = malloc(sizeof(int) * N){
//     for(int i =0; i < N; i++){
//         x[i] = i * 2
//     }
// }


// size_t malloc_size = 100;

// for(int i = 0; i < 3; i++) {
//     word[i] = malloc(malloc_size * sizeof(char)); /* allocates 100 bytes */
//     printf("Enter word: ");
//     scanf("%99s", word[i]); /* Use %99s to avoid overflow */
//                             /* No need to include & address, since word[i] is already a char* pointer */
// }

// int main(void)
// {
//     string s = get_string("input: ");
//     printf("after:  ");
//     for (int i = 0, n = strlen(s); i < n; i++)
//     {
//         if (s[i] >= 'a' && s[i] <= 'z')
//         {
//             printf("first: %c", s[i] - ('a' - 'A'));
//         }
//         else
//         {
//             printf("second:%c", s[i]);
//         }
//     }
//     printf("\n");
// }

// loop through key and make sure it's all alpha
// check if key is upper or lower
// check if input is upper of lower


// loop through key and make sure it's all alpha
// check if key is upper or lower
// check if input is upper of lower

// int main(int argc, char *argv[]){
//         if(argc != 2) {
//                 printf("Error on input");
//                 exit(1);
//         }
//         string input = get_string("Input:");
//         string key = argv[1];
//         int len = strlen(key);
//         int keys[len];
//         for (int i = 0; i < strlen(key); i++) {
//                 if(isupper(key[i])) {
//                         keys[i] = key[i] - 65;
//                 } else {
//                         keys[i] = key[i] - 97;
//                 }
//         }

//         for(int i = 0; i < strlen(input); i++) {
//                 if(isalpha(input[i])) {
//                         // if upper case to this
//                         if(isupper(input[i])) {

//                                 int convertKey = keys[i % (strlen(key))];
//                                 // int convertInput = input[i] - 65;
//                                 // int result = ((convertInput +  convertKey) % 26) + 65;

//                                 printf("%i\n", convertKey);

//                         }  else if(!isupper(input[i])) {
//                                 int convertKey = keys[i % (strlen(key))];
//                                 // int convertInput = input[i] -97;
//                                 // int result = ((convertInput +  convertKey) % 26) + 97;


//                                 printf("%i\n", convertKey);

//                         }
//                 } else if(!isalpha(input[i])) {

//                         printf("%i", input[i]);
//                 }
//         }
// }

// //
// //     // print ciphertext string
// //     // loop over entire string length
// //     }
// // // printf("\n");
// // }
// POW
int main(void){
        int res = round(440 * pow(2.0, -9.0/12));
        printf("%i",res);
}