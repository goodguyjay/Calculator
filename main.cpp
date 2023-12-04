#include <climits>
#include <iostream>

double get_number(double* num);
char get_operation(char* operation);
double get_result(double* num1, double* num2, char operation);

int main() {

    double num1 = 0, num2 = 0;
    char operation;

    std::cout << "Type in a number: " << std::endl;
    get_number(&num1);
    std::cout << "Operations available: \n[+]\n[-]\n[*]\n[/]\n";
    get_operation(&operation);
    std::cout << "Type in another number: " << std::endl;
    get_number(&num2);
    get_result(&num1, &num2, operation);
    std::cout << num1 << std::endl;

    return 0;
}

double get_number(double* num) {
    std::cin >> *num;
    return *num;
}

char get_operation(char* operation) {

    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    std::cin.get(*operation);

    switch(*operation) {
        //case 10: for a goddamn reason the + symbol was 10 and now its 43? TODO: test this on another compiler
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

double get_result(double* num1, double* num2, char operation) {

    switch (operation) {

        //case 10: // adição ??????
        case 43: {
            *num1 =  *num1 + *num2;
            return *num1;
        }

        case 45: { // subtração
            *num1 = *num1 - *num2;
            return *num1;
        }

        case 120: // multplicação e tecla x em ASCII
        case 42: {
            *num1 = *num1 * *num2;
            return *num1;
        }

        case 47: { // divisão
            *num1 = *num1 / *num2;
            return *num1;
        }

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
