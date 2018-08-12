#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

bool is_rest(string s);

int main() {

    string input = get_string("input: ");
    int f = is_rest(input);
    printf("%c\n", f);


}
bool is_rest(string s)
{
    // s = get_string("Input: ");
    // not a rest
    if(s[0] != '\0'){
        // printf("false");
        return false;
    } else {
        // a rest
        // printf("true");
        return true;
    }
    return false;
}