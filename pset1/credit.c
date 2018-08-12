#include <stdio.h>
#include <cs50.h>
#include <string.h>

int ccCheker(void);
int digitCheck(long long num);
bool lengthValidator(char *cardType, int size);
bool isValidNumber(int size, int numArr[]);


int main(void)
{
    ccCheker();
}

int ccCheker(void)
{

    char *cardType = "";
    int cardId = 0;
    long long num = get_long_long("Enter Number: ");
    // get num of digits
    // https://stackoverflow.com/questions/18691677/how-to-put-an-integer-to-an-array-of-digits
    int digits = digitCheck(num);
    // printf("di∂its: %i\n", digits);
    int numArr[digits];

    int i = 0;
    while (num)
    {
        // put num into array
        numArr[i] = num % 10;
        // printf("%lli", num % 10);
        num = num / 10;
        i++;
    }
    // get size of arr
    size_t size = sizeof(numArr) / sizeof(numArr[0]);
    // printf("size:%zu\n", size);
    int first_num = numArr[size - 1];
    // printf("firstNum %i\n", first_num);
    int second_num = numArr[size - 2];
    // printf("secondNum %i\n", second_num);


    // check first nums
    if (first_num != 4 && first_num != 3 && first_num != 5)
    {
        printf("INVALID\n");
        exit(0);
    }
    // check second numbers
    if (first_num == 5)
    {
        if (second_num != 1 && second_num != 2 && second_num != 3 && second_num != 4 && second_num != 5)
        {
            printf("INVALID\n");
            exit(0);
        }
    }
    if (first_num == 3)
    {
        if (second_num != 4 && second_num != 7)
        {
            printf("INVALID\n");
            exit(0);
        }
    }


    // get card type
    switch (first_num)
    {
        case 3:
            cardType = "AMEX";
            cardId = 1;
            break;
        case 4:
            cardType = "VISA";
            cardId = 2;
            break;
        case 5:
            cardType = "MASTERCARD";
            cardId = 3;
            break;
    }

    // printf("cardType: %s\n", cardType);

    bool lengthOkay = lengthValidator(cardType, size);
    if (lengthOkay != true)
    {
        printf("lenght func must be true. Error");
        exit(1);
    }

    bool result = isValidNumber(size, numArr);

    if (result)
    {
        printf("%s\n", cardType);
    }
    else
    {
        puts("INVALID\n");
    }

    return 0;
}

bool isValidNumber(int size, int numArr[])
{
    // if visa, 16 digits - start from first digit, every second
    // if visa 13, - start on second digit
    // arrays will be half the size of cc nums
    // if even
    int arrSize = 0;
    if (size % 2 == 0)
    {
        arrSize = size / 2;

    }
    // if odd
    else
    {
        arrSize = size / 2 + 1;

    }
    int everyFirstArr[arrSize];
    int everySecondArr[arrSize];
    int productsArr[arrSize];

    int firstSum = 0;

    for (int i = 1; i < size; i = i + 2)
    {
        // push every second one form numArr into new array
        everySecondArr[i / 2] = numArr[i];
    }
    for (int j = 0; j < size; j = j + 2)
    {
        // push every first one form numArr into new array
        everyFirstArr[j / 2] = numArr[j];
        // printf("num: %i\n", numArr[j]);
        // printf("first: %i\n", everyFirstArr[j/2]);
    }

    // this must add a number to size on odd num sizes
    if (size % 2 == 0)
    {
        for (int k = 0; k < size / 2; k++)
        {
            // get the of the first numbers
            firstSum = firstSum + everyFirstArr[k];

        }
    }
    else
    {
        for (int k = 0; k < size / 2 + 1; k++)
        {
            // printf("first: %i\n", everyFirstArr[k]);
            // printf("firstSum: %i\n", firstSum);
            firstSum = firstSum + everyFirstArr[k];

        }
    }


    // double everySecond and push into new arr
    for (int j = 0; j < size / 2; j++)
    {
        productsArr[j] = everySecondArr[j] * 2;
    }

    // split apart digits of second and get sum of all
    int secondSum = 0;
    for (int k = 0; k < size / 2; k++)
    {
        int num = productsArr[k];
        while (num)
        {
            // get second digit sum
            int digit = num % 10;
            num /= 10;
            secondSum += digit;

        }
    }
    // printf("secondSum: %i\n", secondSum);

    int result = firstSum + secondSum;
    // printf("%i\n", result);

    if (result % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}
bool lengthValidator(char *cardType, int size)
{
    int amex = strcmp(cardType, "AMEX");
    int visa = strcmp(cardType, "VISA");
    int mc = strcmp(cardType, "MASTERCARD");
    if (amex == 0)
    {
        if (size != 15)
        {
            // printf("The %s card must be 15 digits\n", cardType);
            // ccCheker();
            puts("INVALID");
            exit(0);
        }

    }
    else if (visa == 0)
    {
        if (size != 13 && size != 16)
        {
            // printf("The %s card must be 13 or 16 digits\n", cardType);
            // ccCheker();
            puts("INVALID");
            exit(0);
        }
    }
    else if (mc == 0)
    {
        if (size != 16)
        {
            // printf("The %s card must be 16 digits\n", cardType);
            // ccCheker();
            puts("INVALID");
            exit(0);
        }
    }
    else
    {
        puts("No card type was found. Re-enter the card number\n");
        ccCheker();

    }
    return true;
}
int digitCheck(long long num)
{
    int digits = 0;
    if (num < 10)
    {
        digits = 1;
    }
    else if (num < 100)
    {
        digits = 2;
    }
    else if (num < 1000)
    {
        digits = 3;
    }
    else if (num < 10000)
    {
        digits = 4;
    }
    else if (num < 100000)
    {
        digits = 5;
    }
    else if (num < 1000000)
    {
        digits = 6;
    }
    else if (num < 10000000)
    {
        digits = 7;
    }
    else if (num < 100000000)
    {
        digits = 8;
    }
    else if (num < 1000000000)
    {
        digits = 9;
    }
    else if (num < 10000000000)
    {
        digits = 10;
    }
    else if (num < 100000000000)
    {
        digits = 11;
    }
    else if (num < 1000000000000)
    {
        digits = 12;
    }
    else if (num < 10000000000000)
    {
        digits = 13;
    }
    else if (num < 100000000000000)
    {
        digits = 14;
    }
    else if (num < 1000000000000000)
    {
        digits = 15;
    }
    else if (num < 10000000000000000)
    {
        digits = 16;
    }
    else if (num >= 10000000000000000)
    {
        puts("Number has too many digits. Try again");
        ccCheker();
    }
    return digits;
}