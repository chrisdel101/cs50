#include <stdio.h>
#include <cs50.h>

void mario(void);

int main(void)
{
    mario();
}

// make outside function to recurse on input rather than loop
void mario(void)
{
    int input = get_int("Enter a number: ");
    if (input < 0 || input >= 24)
    {
        printf("Input value out of range");
        mario();
    }
    // input = input + 1;
    // printf("input: %i\n", input);
    for (int i = 1; i <= input; i++)
    {

        int spaces = input - i;
        int hashes = i + 1;
        if (i == input)
        {
            // on last line no spaces
            printf("%.*s\n", hashes, "##########################");
            exit(0);
        }
        // add spaces
        printf("%*c", spaces, ' ');
        // hack to print hashes easier than using another for loop
        // got it from here -
        // https://stackoverflow.com/questions/41434767/printing-a-character-multiple-times-in-a-for-loop
        printf("%.*s\n", hashes, "##########################");
    }
}