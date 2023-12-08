#include <climits>
#include <iostream>

double get_number(double *num);
char get_operation(char *operation);
double get_result(double *num1, double *num2, char operation);
bool get_continue(char *cont);

int main() {

    double num1 = 0, num2 = 0;
    char operation = '\n';
    char cont = '\n';

    // to better simulate a calculator, the main function will ask first for a number
    // then the operation, and then the other number
    // probable to change in the near future tho

    std::cout << "Type in a number: " << std::endl;
    get_number(&num1);

    std::cout << "Operations available: [+] [-] [*] [/] \n";
    get_operation(&operation);

    std::cout << "Type in another number: " << std::endl;
    get_number(&num2);
    get_result(&num1, &num2, operation);

    std::cout << "Result: " <<
        num1 << std::endl;

    std::cout << "Wanna continue? [y/n]" << std::endl;
    std::cin >> cont;

    while (get_continue(&cont)) {
        std::cout << "Operations available: \n[+]\n[-]\n[*]\n[/]\n" << std::endl;
        get_operation(&operation);

        std::cout << "Type in another number: " << std::endl;
        get_number(&num2);
        get_result(&num1, &num2, operation);

        std::cout << "Result: " <<
            num1 << std::endl;

        std::cout << "Wanna continue? [y/n]" << std::endl;
        std::cin >> cont;
    }

    std::cout << "Thank you for using this calculator!" << std::endl;
    return 0;
}

double get_number(double *num) {
    // ok i admit this is unecessary
    std::cin >> *num;
    return *num;
}

char get_operation(char *operation) {

    // to minimize code verbosity and portability, i made the operation reader a function
    // that way i can reuse it and add case exceptions without adding to the verbosity of the code itself

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
            return 1;
    }
}

double get_result(double *num1, double *num2, char operation) {


    /* you could say its lazy reusing the same variable to return the result
     *
     *
     *
     *
     * eh... you'd be right */
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
            *num1 = *num1 / *num2;
            return *num1;
        }

        // if the op is not within the defined parameters, it will go into the default and ask the user to change
        // until it is a valid operation
        default: {

            do {
                std::cout << "Invalid operation. Please type the operation again!" << std::endl;
                std::cout << "Operations available: \n[+]\n[-]\n[*]\n[/]\n";
                get_operation(&operation);
            } while (operation == 1);

            get_result(num1, num2, operation);
        }

    }

}

bool get_continue(char *cont) {

    *cont = std::tolower(*cont);
    short i = 0;

    switch(*cont) {

        case 'y':
            return true;

        case 'n':
            return false;

        default: {
                do {
                    std::cout << "Invalid option. Please type again!" << std::endl;
                    std::cin >> *cont;
                    *cont = std::tolower(*cont);

                    if (*cont == 'y' || *cont == 'n') {
                        get_continue(cont);
                    }

                    i++;
                } while (i < 5);
            }
        }

    std::cout << "I'll take that as a no." << std::endl;
    return false;
}
