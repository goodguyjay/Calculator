#include <climits>
#include <iostream>
#include <limits>

double get_number(double *num);
char get_operation(char *operation);
double get_result(double *num1, double *num2, char operation);
bool get_continue(char *cont);
inline void clear_screen() { std::cout << "\x1B[2J\x1B[H"; }

int main() {

    double num1 = 0, num2 = 0, num_temp;
    char operation = '\0';
    char cont = '\0';

    // to better simulate a calculator, the main function will ask first for a number
    // then the operation, and then the other number
    // probable to change in the near future tho

    std::cout << "Type in a number: ";
    get_number(&num1);
    num_temp = num1;
    clear_screen();

    std::cout << num1 << " (operations available: [+] [-] [*] [/]) ";

    do {
        get_operation(&operation);
    } while (operation == 'e');

    clear_screen();

    std::cout << num1 << " " << operation << " (type in another number) ";

    get_number(&num2);
    get_result(&num1, &num2, operation);

    clear_screen();

    std::cout << num_temp << " " << operation << " " << num2 << " = " << num1 << std::endl;

    std::cout << "Wanna continue? [y/n]" << std::endl;
    std::cin >> cont;

    clear_screen();

    while (get_continue(&cont)) {
        std::cout << num1 << " (operations available: [+] [-] [*] [/])" << std::endl;
        get_operation(&operation);

        std::cout << num1 << " " << operation << " (type in another number): ";
        get_number(&num2);
        num_temp = num1;
        get_result(&num1, &num2, operation);
        std::cout << num_temp << " " << operation << " " << num2 << " = " << num1 << std::endl;

        std::cout << "Do you want to continue? [y/n]" << std::endl;
        std::cin >> cont;
        clear_screen();
    }

    std::cout << "Thank you for using this calculator!" << std::endl;
    return 0;
}

double get_number(double *num) {

    std::cin >> *num;

    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits < std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please type in a number!" << std::endl;
        std::cin >> *num;
    }

    return *num;
}

char get_operation(char *operation) {
    // to minimize code verbosity and portability, i made the operation reader a function
    // that way i can reuse it and add case exceptions without adding to the verbosity of the code itself

    do {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cin.get(*operation);

        switch(*operation) {
            // these numbers are the equivalent to the ASCII code of the operation
            case 43:
            case 45:
            case 120:
            case 42:
            case 47:
                return *operation;
            default:
                *operation = 'e';
                std::cout << "Invalid operation. Please type the operation again!" << std::endl;
                std::cout << "Operations available: [+] [-] [*] [/]" << std::endl;
        }
    } while (true);

}

double get_result(double *num1, double *num2, char operation) {


    // i'm reusing the num1 as the result to avoid creating another unecessary variable
    switch (operation) {

        // 43 equals to '+'
        case 43: {
            *num1 =  *num1 + *num2;
            return *num1;
        }

        // 45 equals to '-'
        case 45: {
            *num1 = *num1 - *num2;
            return *num1;
        }

        // 120 and 42 equals to 'x' and '*'
        case 120:
        case 42: {
            *num1 = *num1 * *num2;
            return *num1;
        }

        // 47 equals to '/'
        case 47: {

            /*while (*num1 == 0 || *num2 == 0) {
                std::cout << "You can't divide by zero!" << std::endl;
                std::cout << "Please type in the first number again: ";
                get_number(num1);
                std::cout << "Please type in the second number again: ";
                get_number(num2);
            }*/


            // if the user tries to divide 0 by anything, it will be always 0
            if (*num1 == 0) {
                return 0;
            }

            // if the user tries to divide anything by 0, it will ask for the second number again
            do {
                std::cout << "You cant divide by zero!" << std::endl;
                std::cout << "Please type in the second number again: ";
                get_number(num2);
            } while (*num2 == 0);

            *num1 = *num1 / *num2;
            return *num1;
        }

        // if the op is not within the defined parameters, it will go into the default and ask the user to change
        // until it is a valid operation
        default: {
            // TODO: CHANGE THIS
            do {
                std::cout << "Invalid operation. Please type the operation again!" << std::endl;
                std::cout << "Operations available: [+] [-] [*] [/]" << std::endl;
                get_operation(&operation);
            } while (operation == 1);
        }

    }

    return *num1;

}

bool get_continue(char *cont) {

    *cont = std::tolower(static_cast<unsigned char>(*cont));

    switch(*cont) {

        case 'y':
            return true;

        case 'n':
            return false;

        default: {
            short i = 0;
            do {
                    std::cout << "Invalid option. Please try again! [y/n]" << std::endl;

                    std::cin.clear();
                    std::cin.ignore(INT_MAX, '\n');
                    std::cin.get(*cont);

                    *cont = std::tolower(static_cast<unsigned char>(*cont));

                    if (*cont == 'y' || *cont == 'n') {
                        return true;
                    }

                    i++;
                } while (i < 5);
            }
        }

    std::cout << "I'll take that as a no." << std::endl;
    return false;
}
