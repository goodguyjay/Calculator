#include <iostream>

double operation_chooser(char operation, double num1, double num2);

double add(double num1, double num2);
double subtract(double num1, double num2);
double multiply(double num1, double num2);
double divide(double num1, double num2);

int main() {
    char operation;
    double result, num1, num2;

    std::cout << "Hey there! Type in a operation: " << std::endl;
    std::cin >> operation;
    std::cout << "Type in two numbers: (separated by a space or enter)" << std::endl;
    std::cin >> num1 && std::cin >> num2;
    result = operation_chooser(operation, num1, num2);
    std::cout << result << std::endl;
    /*
    do {
        value = operation_chooser(operation);
        std::cout << value << std::endl;
        std::cout << "Wanna do it again? (Type ? to stop) ;)" << std::endl;
    } while (operation != '?');*/

    return 0;
}

double operation_chooser(char operation, double num1, double num2) {
    double result = 0;

    if (operation == '?') {
        return operation;
    }

    switch (operation) {

        case '+': {
            result = add(num1, num2);
            break;
        };

        case '-': {
            result = subtract(num1, num2);
            break;
        };

        case '*' || 'x': {
            result = multiply(num1, num2);
            break;
        };

        case '/': {
            result = divide(num1, num2);
            break;
        }

        default: {
            std::cout << "Invalid operation. Please try again!" << std::endl;
            std::cin >> operation;
            main();
        }
    }
}
double add(double num1, double num2) {
    double result = num1 + num2;
    return result;
}

double subtract(double num1, double num2) {
    double result = num1 - num2;
    return result;
}

double multiply(double num1, double num2) {
    double result = num1 * num2;
    return result;
}

double divide(double num1, double num2) {
    double result = num1 / num2;
    return result;
}
