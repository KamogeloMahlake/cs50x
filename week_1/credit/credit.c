#include <cs50.h>
#include <stdio.h>

int length(long n);
int checknumber(long n, int size);
long power(int n);

int main(void)
{
    long number = get_long("Number: ");
    int numberlength = length(number);

    if (numberlength == 13 || numberlength == 15 || numberlength == 16)
    {
        int sum = checknumber(number, numberlength);
        if (sum % 10 != 0)
        {
            printf("INVALID\n");
            return 0;
        }

        int firstnumbers = number / power(numberlength);
        int first = firstnumbers / 10;
        int second = firstnumbers % 10;

        if (numberlength == 15 && (firstnumbers == 34 || firstnumbers == 37))
        {
            printf("AMEX\n");
        }
        else if ((numberlength == 13 || numberlength == 16) && first == 4)
        {
            printf("VISA\n");
        }
        else if (numberlength == 16 && first == 5 &&
                 (second == 1 || second == 2 || second == 3 || second == 4 || second == 5))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
        return 0;
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
}

int length(long n)
{
    if (n < 0)
        return 0;
    int x = 0;
    do
    {
        x = x + 1;
        n = n / 10;
    }
    while (n > 0);
    return x;
}

int checknumber(long n, int size)
{
    int sum = 0;
    int currentvalue = 0;
    for (int i = size; i > 0; i--)
    {
        if (i % 2 == size % 2)
        {
            sum += n % 10;
        }
        else
        {
            if (length((n % 10) * 2) == 2)
            {
                currentvalue = (n % 10) * 2;
                sum += currentvalue % 10;
                currentvalue = currentvalue / 10;
                sum += currentvalue % 10;
            }
            else
            {
                sum += (n % 10) * 2;
            }
        }
        n = n / 10;
    }
    return sum;
}
long power(int n)
{
    long number = 10;

    for (int i = 1; i < n - 2; i++)
    {
        number = number * 10;
    }
    return number;
}
