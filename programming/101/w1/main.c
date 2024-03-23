#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "system.c"

int main(int argc, char const *argv[])
{
    number *binary = num(0, BINARY);           // 101011
    number *octal = num(0, OCTAL);             // 765
    number *decimal = num(0, DECIMAL);         // 275
    number *hexadecimal = num(0, HEXADECIMAL); // 0x9B4

    if (binary == NULL || octal == NULL || decimal == NULL || hexadecimal == NULL)
        return 1;

    setlocale(LC_CTYPE, "");

    binary->value = 1001101;
    convert_to_decimal(binary->value, binary->system, 1);

    binary->value = 1101;
    convert_to_decimal(binary->value, binary->system, 1);

    decimal->value = 15;
    convert_from_decimal(decimal->value, binary->system, 1);

    decimal->value = 20;
    convert_from_decimal(decimal->value, binary->system, 1);

    octal->value = 541;
    convert_to_decimal(octal->value, octal->system, 1);

    decimal->value = 128;
    convert_from_decimal(decimal->value, octal->system, 1);

    decimal->value = 415;
    convert_from_decimal(decimal->value, octal->system, 1);

    octal->value = 6251;
    convert_to_binary(octal->value, octal->system);

    binary->value = 10110011;
    convert_from_binary(binary->value, octal->system);

    hexadecimal->value = 0x3A18;
    convert_to_decimal(hexadecimal->value, hexadecimal->system, 1);

    decimal->value = 655;
    convert_from_decimal(decimal->value, octal->system, 1);

    hexadecimal->value = 0x3F51;
    convert_to_binary(hexadecimal->value, hexadecimal->system);

    binary->value = 1101001011;
    convert_from_binary(binary->value, hexadecimal->system);
    decimal->value = 415;
    convert_from_decimal(decimal->value, octal->system, 1);

    octal->value = 6251;
    convert_to_binary(octal->value, octal->system);

    binary->value = 10110011;
    convert_from_binary(binary->value, octal->system);

    hexadecimal->value = 0x3A18;
    convert_to_decimal(hexadecimal->value, hexadecimal->system, 1);

    decimal->value = 655;
    convert_from_decimal(decimal->value, hexadecimal->system, 1);

    hexadecimal->value = 0x3F51;
    convert_to_binary(hexadecimal->value, hexadecimal->system);

    binary->value = 1101001011;
    convert_from_binary(binary->value, hexadecimal->system);
    decimal->value = 415;
    convert_from_decimal(decimal->value, octal->system, 1);

    octal->value = 6251;
    convert_to_binary(octal->value, octal->system);

    binary->value = 10110011;
    convert_from_binary(binary->value, octal->system);

    hexadecimal->value = 0x3A18;
    convert_to_decimal(hexadecimal->value, hexadecimal->system, 1);

    decimal->value = 655;
    convert_from_decimal(decimal->value, hexadecimal->system, 1);

    hexadecimal->value = 0x3F51;
    convert_to_binary(hexadecimal->value, hexadecimal->system);

    binary->value = 1101001011;
    convert_from_binary(binary->value, hexadecimal->system);

    free(binary);
    free(octal);
    free(decimal);
    free(hexadecimal);

    return 0;
}
