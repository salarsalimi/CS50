#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card = get_long("Number: ");
    int length = 0;
    int n1 = 0;
    int n2 = 0;
    int sum1 = 0;
    int sum2 = 0;
    int flag = 0;
    int last = 0;
    while (card / 10 > 0 || last == 0)
    {
        length++;
        n2 = n1;
        n1 = card % 10;
        if (flag == 0)
        {
            sum1 += n1;
            flag = 1;
        }
        else
        {
            int x = n1 * 2;
            if (x / 10 > 0)
            {
                sum2 += (x % 10) + ((x / 10) % 10);
                flag = 0;
            }
            else
            {
                sum2 += x;
                flag = 0;
            }
        }

        if (card / 10 <= 0)
        {
            last = 1;
        }
        else
        {
            card = card / 10;
        }
    }

    if (length < 13 || length > 16 || (sum1 + sum2) % 10 != 0)
    {
        printf("INVALID\n");
    }
    else if ((sum1 + sum2) % 10 == 0 && length == 15 && (n1 * 10 + n2 == 34 || n1 * 10 + n2 == 37))
    {
        printf("AMEX\n");
    }
    else if ((sum1 + sum2) % 10 == 0 && length == 16 && (n1 * 10 + n2 <= 55 && n1 * 10 + n2 >= 51))
    {
        printf("MASTERCARD\n");
    }
    else if ((sum1 + sum2) % 10 == 0 && (length == 13 || length == 16) && (n1 == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
