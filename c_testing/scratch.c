
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// // SUBRACT letters
// char d = 'd';
// char b =  'b';
// int main(void){
//   // int diff = d - b;
//   // char ans = diff + 'a' - 1;
//   // printf("%c\n", ans);
//   int arr[16];
//   int num = get_int("put num: ");
//   // copy score
//   // int first = score;
//   int i = 0;
//     while(num)
//     {
//         arr[i] = num % 10;
//         printf("%d\n", num % 10);
//         num /= 10;
//         i++;
//     }
//     // int second;
//     // while(first >= 10)
//     // {
//     //     second = first;
//     //     first = first / 10;
//     // }
//     // printf("first %i\n", first);
//     // printf("second %i\n", second);
//     // size of arr
//     size_t n = sizeof(arr)/sizeof(arr[0]);
//     printf("size:%zu\n", n);
//     // for(int j = 0; j < n; j++ )
//     // {
//     //   printf("%i", num[j]);
//     // }
// }


int main(void)
{
    int num = 123;
    // int i = 0;
    while(num)
    {
        int digit = num % 10;
        num /= 10;
        // printf("num\n: %i", num);
        printf("digit: %i\n", digit);
    }
}

// int value = 123;
// while (value > 0) {
// int digit = value % 10;
// // do something with digit
// value /= 10;
// }
// // digit counter
//     long long num = get_long_long("enter number: ");
//     printf("%lli", num);
//     int digits = 0;
//     if(num < 10)
//     {
//       digits = 1;
//     }
//     else if(num < 100)
//     {
//       digits = 2;
//     }
//     else if(num < 1000)
//     {
//       digits = 3;
//     }
//     else if(num < 10000)
//     {
//       digits = 4;
//     }
//     else if(num < 100000)
//     {
//       digits = 5;
//     }
//     else if(num < 1000000)
//     {
//       digits = 6;
//     }
//     else if(num < 10000000)
//     {
//       digits = 7;
//     }
//     else if(num < 100000000)
//     {
//       digits = 8;
//     }
//     else if(num < 1000000000)
//     {
//       digits = 9;
//     }
//     else if(num < 10000000000)
//     {
//       digits = 10;
//     }
//     else if(num < 100000000000)
//     {
//       digits = 11;
//     }
//     else if(num < 1000000000000)
//     {
//       digits = 12;
//     }
//     else if(num < 10000000000000)
//     {
//       digits = 13;
//     }
//     else if(num < 100000000000000)
//     {
//       digits = 14;
//     }
//     else if(num < 1000000000000000)
//     {
//       digits = 15;
//     }
//     else if(num < 10000000000000000)
//     {
//       digits = 16;
//     }
//     else if(num >= 10000000000000000)
//     {
//       puts("Number has too many digits.");
//       exit(1);
//     }
//   printf("%i", digits);
