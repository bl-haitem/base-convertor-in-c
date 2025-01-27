#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the input is a valid hexadecimal number
int is_valid_hex(char num[]) {
    for (int i = (num[0] == '-' ? 1 : 0); num[i] != '\0'; i++) {
        if (!((num[i] >= '0' && num[i] <= '9') ||
               (num[i] >= 'A' && num[i] <= 'F') ||
               (num[i] >= 'a' && num[i] <= 'f'))) {
            return 0;
        }
    }
    return 1;
}

// Function to check if the input is a valid octal number
int is_valid_octal(char num[]) {
    for (int i = (num[0] == '-' ? 1 : 0); num[i] != '\0'; i++) {
        if (num[i] < '0' || num[i] > '7') {
            return 0;
        }
    }
    return 1;
}

// Function to check if the input is a valid binary number
int is_valid_binary(char num[]) {
    for (int i = (num[0] == '-' ? 1 : 0); num[i] != '\0'; i++) {
        if (num[i] != '0' && num[i] != '1') {
            return 0;
        }
    }
    return 1;
}

// Function to check if the input is a valid decimal number
int is_valid_decimal(char num[]) {
    for (int i = (num[0] == '-' ? 1 : 0); num[i] != '\0'; i++) {
        if (num[i] < '0' || num[i] > '9') {
            return 0; // Invalid character
        }
    }
    return 1;
}

// Function to convert hexadecimal to decimal
long long hex_to_decimal(char num[]) {
    long long result = 0;
    long long base = 1; // 16^0
    int len = strlen(num);
    for (int i = len - 1; i >= (num[0] == '-' ? 1 : 0); i--) {
        char digit = num[i];
        int value;
        if (digit >= '0' && digit <= '9') {
            value = digit - '0';
        } else if (digit >= 'A' && digit <= 'F') {
            value = digit - 'A' + 10;
        } else if (digit >= 'a' && digit <= 'f') {
            value = digit - 'a' + 10;
        }
        result += value * base;
        base *= 16; // Move to the next power of 16
    }
    return result;
}

// Function to convert octal to decimal
long long octal_to_decimal(char num[]) {
    long long result = 0;
    long long base = 1; // 8^0
    int len = strlen(num);
    for (int i = len - 1; i >= (num[0] == '-' ? 1 : 0); i--) {
        char digit = num[i];
        int value = digit - '0'; // Convert char to int
        result += value * base;
        base *= 8; // Move to the next power of 8
    }
    return result;
}

// Function to convert binary to decimal
long long binary_to_decimal(char num[]) {
    long long result = 0;
    long long base = 1; // 2^0
    int len = strlen(num);
    for (int i = len - 1; i >= (num[0] == '-' ? 1 : 0); i--) {
        char digit = num[i];
        int value = digit - '0'; // Convert char to int
        result += value * base;
        base *= 2; // Move to the next power of 2
    }
    return result;
}

// Function to convert decimal to binary
void decimal_to_binary(long long num) {
    char binary[64] = {0};
    int index = 0;
    if (num == 0) {
        binary[index++] = '0'; // Handle zero case
    } else {
        while (num > 0) {
            binary[index++] = (num % 2) + '0';
            num /= 2;
        }
    }
    // Print binary representation
    if (num < 0) {
        printf("-");
    }
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", binary[i]);
    }
    printf("\n");
}

// Function to convert decimal to octal
void decimal_to_octal(long long num) {
    char octal[64] = {0};
    int index = 0;
    if (num == 0) {
        octal[index++] = '0'; // Handle zero case
    } else {
        while (num > 0) {
            octal[index++] = (num % 8) + '0';
            num /= 8;
        }
    }
    // Print octal representation
    if (num < 0) {
        printf("-");
    }
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", octal[i]);
    }
    printf("\n");
}

// Function to convert decimal to hexadecimal
void decimal_to_hex(long long num) {
    char hex[64] = {0};
    int index = 0;
    if (num == 0) {
        hex[index++] = '0'; // Handle zero case
    } else {
        while (num > 0) {
            int remainder = num % 16;
            if (remainder < 10) {
                hex[index++] = remainder + '0';
            } else {
                hex[index++] = (remainder - 10) + 'A'; // Convert to A-F
            }
            num /= 16;
        }
    }
    // Print hexadecimal representation
    if (num < 0) {
        printf("-");
    }
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", hex[i]);
    }
    printf("\n");
}

// Function to print the main menu
void print_menu() {
    printf("\033[1;32m _____    ____    ____  ____     ____  ____  __  _ __  __ ____ _____  _____  ____ _____ \n");
    printf("\033[1;32m | () )  / () \\  (_ (_`| ===|   / (__`/ () \\|  \\| |\\ \\/ /| ===|| () )|_   _|/ () \\| () )\n");
    printf("\033[1;32m |_()_) /__/\\__\\.__)__)|____|   \\____)\\____/|_|\\__| \\__/ |____||_|\\_\\  |_|  \\____/|_|\\_\\\n\n");
    printf("\t\033[1;36m===================================\n");
    printf("\t      Choose the main base:       \n");
    printf("\t===================================\n");
    printf("\033[1;32m-------------------------------------------------------------\n");
    printf("\033[1;32m                      1. Hexadecimal                          \n");
    printf("-------------------------------------------------------------\n");
    printf("-------------------------------------------------------------\n");
    printf("\033[1;32m                      2. Octal                                \n");
    printf("-------------------------------------------------------------\n");
    printf("-------------------------------------------------------------\n");
    printf("\033[1;32m                      3. Binary                               \n");
    printf("-------------------------------------------------------------\n");
    printf("-------------------------------------------------------------\n");
    printf("\033[1;32m                      4. Decimal                              \n");
    printf("-------------------------------------------------------------\n\n");
    printf("\033[0m Enter your choice (1 to 4): ");
}

// Function to print the conversion menu
void print_conversion_menu() {
    printf("\033[1;36m=============================================================\n");
    printf("            Choose the target base to convert to:            \n");
    printf("=============================================================\n");
    printf("-------------------------------------------------------------\n");
    printf("\033[1;32m                    1. Binary                                \n");
    printf("-------------------------------------------------------------\n");
    printf("-------------------------------------------------------------\n");
    printf("\033[1;32m                    2. Decimal                               \n");
    printf("-------------------------------------------------------------\n");
    printf("-------------------------------------------------------------\n");
    printf("\033[1;32m                    3. Octal                                 \n");
    printf("-------------------------------------------------------------\n");
    printf("-------------------------------------------------------------\n");
    printf("\033[1;32m                   4. Hexadecimal                           \n");
    printf("-------------------------------------------------------------\n\n");
    printf("\033[0m Enter your choice (1 to 4): ");
}

// Main function
void base_converter() {
    int main_base, target_base;
    char number[100];
    char continue_choice;
    char input[10]; // Buffer for input
    do {
        // Main base selection with validation
        while (1) {
            system("cls");
            print_menu();
            scanf("%s", input);
            main_base = atoi(input); // Convert string to integer
            if (main_base < 1 || main_base > 4) {
                printf("\033[1;31m ------------------------------------------------------------------------------------------------------------\n");
                printf("\033[1;31m   Error: Invalid main base choice. Please select 1 (Hexadecimal), 2 (Octal), 3 (Binary), or 4 (Decimal).   \n");
                printf("------------------------------------------------------------------------------------------------------------\n");
            } else {
                break; // Valid input, exit loop
            }
        }
        system("cls");
        // Target base selection with validation
        while (1) {
            print_conversion_menu();
            scanf("%s", input);
            target_base = atoi(input); // Convert string to integer
            if (target_base < 1 || target_base > 4) {
                printf("------------------------------------------------------------------------------------------------------\n");
                printf("\033[1;31m  Error: Invalid target base choice. Please select between 1 (Binary) and 4 (Hexadecimal).  \n");
                printf("------------------------------------------------------------------------------------------------------\n");
            } else {
                break; // Valid input, exit loop
            }
        }
        system("cls");
        printf("\t\033[1;31m===========================\n \t\tIMPORTANT!!! \n\t===========================\n-------------------------------------------------------------\n\tTo stop the conversion, enter '*'.\n-------------------------------------------------------------\n");
        while (1) {
            printf("\n\033[0mEnter a number: ");
            scanf("%s", number);
            if (strcmp(number, "*") == 0) {
                printf("----------------------------------------------------------------------------------\n");
                printf("\033[1;31m                    Conversion stopped. Exiting the program.                      \n");
                printf("----------------------------------------------------------------------------------\n");
                break; // Exit the loop if user enters '*'
            }
            long long decimal_value;
            int is_negative = (number[0] == '-'); // Check if the number is negative

            if (main_base == 1) { // Hexadecimal
                if (!is_valid_hex(number)) {
                    printf("\033[1;31m-------------------------------------------------------------\n");
                    printf("\033[1;31m        Invalid hexadecimal number. Please try again.        \n");
                    printf("-------------------------------------------------------------\n");
                    continue; // Prompt for input again
                }
                decimal_value = hex_to_decimal(number);
            } else if (main_base == 2) { // Octal
                if (!is_valid_octal(number)) {
                    printf("\033[1;31m-------------------------------------------------------------\n");
                    printf("\033[1;31m            Invalid octal number. Please try again.          \n");
                    printf("-------------------------------------------------------------\n");
                    continue; // Prompt for input again
                }
                decimal_value = octal_to_decimal(number);
            } else if (main_base == 3) { // Binary
                if (!is_valid_binary(number)) {
                    printf("\033[1;31m-------------------------------------------------------------\n");
                    printf("\033[1;31m            Invalid binary number. Please try again.         \n");
                    printf("-------------------------------------------------------------\n");
                    continue; // Prompt for input again
                }
                decimal_value = binary_to_decimal(number);
            } else if (main_base == 4) { // Decimal
                if (!is_valid_decimal(number)) {
                    printf("\033[1;31m-------------------------------------------------------------\n");
                    printf("\033[1;31m            Invalid decimal number. Please try again.        \n");
                    printf("-------------------------------------------------------------\n");
                    continue; // Prompt for input again
                }
                decimal_value = atoll(number); // Convert string to long long
            } else {
                printf("\033[1;31m-------------------------------------------------------------\n");
                printf("\033[1;31m          Invalid main base choice. Please try again.        \n");
                printf("-------------------------------------------------------------\n");
                continue; // Prompt for input again
            }

            // Print the converted value
            if (is_negative) {
                printf("-");
            }
            switch (target_base) {
                case 1: // Convert to Binary
                    decimal_to_binary(decimal_value);
                    break;
                case 2: // Convert to Decimal
                    printf("%lld\n", decimal_value);
                    break;
                case 3: // Convert to Octal
                    decimal_to_octal(decimal_value);
                    break;
                case 4: // Convert to Hexadecimal
                    decimal_to_hex(decimal_value);
                    break;
                default:
                    printf("\033[1;31m-------------------------------------------------------------\n");
                    printf("\033[1;31m         Invalid target base choice. Please try again.      \n");
                    printf("-------------------------------------------------------------\n");
                    break;
            }
        }
        system("cls");
        printf("\033[1;36m=============================================================\n");
        printf("\033[1;36m       Do you want to perform another conversion? (y/n):      \n");
        printf("=============================================================\n\n");
        scanf(" %c", &continue_choice);
    } while ((continue_choice == 'y') || (continue_choice == 'Y'));
        printf("-------------------------------------------------------------\n");
        printf("\033[1;36m        Thank you for using the base converter!            \n");
        printf("\033[1;36m-------------------------------------------------------------\n");
        printf("\033[0m-------------------------------------------------------------\n");
    return 0;
}
