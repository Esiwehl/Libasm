
#include <string.h>
#include <stdio.h>

int findNum(char c, char *base)
{
    int idx = 0;

    for (; base[idx]; idx++)
    {
        if (base[idx] == c)
            return idx;
    }
    return -1;
}

int validBase(char *base)
{
    int idx;
    int j;

    if (!base)
        return 0;

    for (idx = 0; base[idx]; idx++)
    {
        if (base[idx] == '+' || base[idx] == '-'
            || base[idx] == ' ' || (base[idx] >= 9 && base[idx] <= 13))
            return 0;

        for (j = idx + 1; base[j]; j++)
        {
            if (base[idx] == base[j])
                return 0;
        }
    }

    if (idx < 2)
        return 0;

    return 1;
}

int atoiBase(char *str, char *base)
{
    int num = 0;
    int result = 0;
    int len;
    int idx = 0;
    int sign = 1;

    if (!str || !validBase(base))
        return 0;

    len = strlen(base);

    while (str[idx] == ' '
        || (str[idx] >= 9 && str[idx] <= 13))
        idx++;

    if (str[idx] == '+' || str[idx] == '-')
    {
        if (str[idx] == '-')
            sign = -1;
        idx++;
    }

    for (; str[idx]; idx++)
    {
        num = findNum(str[idx], base);
        if (num == -1) break;
        result = result * len + num;
    }

    return result * sign;
}
