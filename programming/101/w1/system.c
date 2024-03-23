#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <string.h>

typedef enum PositionalSystem
{
    BINARY = 2,
    OCTAL = 8,
    DECIMAL = 10,
    HEXADECIMAL = 16
} positional_system;

const char *PositionalSystemName(positional_system *system)
{
    switch (*system)
    {
    case BINARY:
        return "BINARY";
    case OCTAL:
        return "OCTAL";
    case DECIMAL:
        return "DECIMAL";
    case HEXADECIMAL:
        return "HEXADECIMAL";

    default:
        return NULL;
    }
}

const wint_t SS[4][2] = {
    {0, 0x2082},
    {0, 0x2088},
    {0x2081, 0x2080},
    {0x2081, 0x2086}};

typedef struct Number
{
    unsigned long value;
    positional_system system;
} number;

number *num(unsigned long value, positional_system system)
{
    number *number = malloc(sizeof(number));
    if (number == NULL)
        return NULL;

    number->system = system;
    number->value = value;

    return number;
}

typedef struct toString
{
    int length;
    char *value;
} tostring;

tostring *convert_to_string(unsigned long *num, int is_hexa)
{
    char *fs = malloc(is_hexa ? 4 : 4 * sizeof(char));
    snprintf(fs, sizeof(fs), "%s", is_hexa ? "%lX" : "%lu");

    int length = snprintf(NULL, 0, fs, *num);
    size_t size = (length + 1) * sizeof(char);

    char *str = malloc(size);
    snprintf(str, size, fs, *num);

    free(fs);

    tostring *retval = malloc(sizeof(tostring));
    if (retval == NULL)
    {
        free(str);
        return NULL;
    }

    retval->length = length;
    retval->value = str;

    return retval;
}

unsigned long convert_from_decimal(unsigned long num, positional_system sys, int d)
{
    d &&printf("CONVERSION:\n  FROM: %lu (DECIMAL)\n  TO: %s\n\n", num, PositionalSystemName(&sys));
    char bb[(int)floor(log2(num))];
    int bbl = 0;

    d &&printf("CALCULATION: \n");
    do
    {
        unsigned long m = num % sys;
        bbl += sprintf(bb + bbl, "%lX", m);
        d &&printf("  %lu %% %d = %lu\n", num, sys, m);
        num /= sys;
    } while (num != 0);

    int length = snprintf(NULL, 0, "%s", bb);
    for (int i = 0; i < length / 2; i++)
    {
        int t = bb[i];
        bb[i] = bb[length - 1 - i];
        bb[length - 1 - i] = t;
    }

    unsigned long result;
    sscanf(bb, sys == HEXADECIMAL ? "%lX" : "%lu", &result);
    d &&printf("\nRESULT: %s\n", bb);

    return result;
}

unsigned long convert_to_decimal(unsigned long num, positional_system sys, int d)
{
    int is_hexa = sys == HEXADECIMAL;
    tostring *str = convert_to_string(&num, is_hexa);
    d &&printf("CONVERSION:\n  FROM: %s (%s)\n  TO: DECIMAL\n\n", str->value, PositionalSystemName(&sys));

    char *scb = malloc((str->length + 1) * (sizeof(char) + sizeof(unsigned long)));
    if (scb == NULL)
    {
        free(str->value);
        free(str);
        return 0;
    }
    int scl = 0;

    d &&printf("CALCULATION:\n  %s = ", str->value);

    unsigned long result = 0;
    for (int i = 0; i < str->length; i++)
    {
        char ch = str->value[i];
        int digit;
        sscanf(&ch, is_hexa ? "%X" : "%d", &digit);

        int pos = str->length - i;
        int power = pos - 1;
        int pdigit = digit * pow(sys, power);
        result += pdigit;

        int is_last = i == str->length - 1;
        d &&printf("%d.%d^%d%s", digit, sys, power, is_last ? "\0" : " + ");
        scl += sprintf(scb + scl, "%d %c ", pdigit, is_last ? '=' : '+');
    }

    char sa[str->length + 2];
    memset(sa, ' ', sizeof(sa));
    sa[sizeof(sa)] = '\0';

    d &&printf("\n%s = %s%lu\n", sa, scb, result);
    d &&printf("\nResult: %lu\n", result);

    free(scb);

    free(str->value);
    free(str);

    return result;
}

unsigned long convert_from_binary(unsigned long num, positional_system sys)
{
    if (sys == DECIMAL)
        return convert_to_decimal(num, sys, 1);

    printf("CONVERSION:\n  FROM: %lu (BINARY)\n  TO: %s\n\n", num, PositionalSystemName(&sys));

    int is_hexa = sys == HEXADECIMAL;
    tostring *str = convert_to_string(&num, 0);

    int base = (int)log2(sys);
    int p = str->length % base == 0 ? 0 : (base * ((str->length / base) + 1)) - str->length;

    int length = str->length + p;
    char tstr[length];
    tstr[sizeof(tstr)] = '\0';
    memset(tstr, '0', p);
    for (int i = p; i < length; i++)
    {
        tstr[i] = str->value[i - p];
    }

    printf("CALCULATION:\n");
    if (p)
        printf("  %s -> %s\n", str->value, tstr);

    char c[str->length];
    int b = 0;
    for (int i = 0; i < length; i += base)
    {
        char s[base + 1];
        s[base] = '\0';
        strncpy(s, &tstr[i], base);
        int d;
        sscanf(s, "%d", &d);
        unsigned long r = convert_to_decimal(d, BINARY, 0);
        char rs[str->length];
        sprintf(rs, is_hexa ? "%lX" : "%lu", r);
        b += sprintf(c + b, "%s", rs);
        printf("  (%s) = %s\n", s, rs);
    }

    char sa[base + 4];
    memset(sa, ' ', sizeof(sa));
    sa[sizeof(sa)] = '\0';
    printf("%s = %s\n\n", sa, c);

    printf("RESULT: %s\n", c);

    return 0;
}

unsigned long convert_to_binary(unsigned long num, positional_system sys)
{
    if (sys == DECIMAL)
        return convert_to_decimal(num, sys, 1);


    int is_hexa = sys == HEXADECIMAL;
    tostring *str = convert_to_string(&num, is_hexa);
    printf("CONVERSION:\n  FROM: %s (%s)\n  TO: BINARY\n\n", str->value, PositionalSystemName(&sys));

    printf("CALCULATION:\n");

    int base = log2(sys);
    char c[str->length];
    int b = 0;
    for (int i = 0; i < str->length; i++)
    {
        char ch = str->value[i];
        int d;
        sscanf(&ch, is_hexa ? "%X" : "%d", &d);
        unsigned long r = convert_from_decimal(d, BINARY, 0);
        tostring *rstr = convert_to_string(&r, 0);
        int p = rstr->length % base == 0 ? 0 : (base * ((rstr->length / base) + 1)) - rstr->length;
        char rs[base];
        memset(rs, '0', p);
        rs[sizeof(rs)] = '\0';
        sprintf(rs + p, "%lu", r);
        b += sprintf(c + b, "%s", rs);
        printf("  %c = %s\n", ch, rs);
    }

    char sa[4];
    memset(sa, ' ', sizeof(sa));
    sa[3] = '\0';
    printf("%s = %s\n\n", sa, c);

    printf("RESULT: %s\n", c);

    return 0;
}