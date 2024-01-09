#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void InputExtraction();
void Logic(string firstNum, string secondNum, string operato);
bool isValidNumber(const string& str);
void recurtion();

int main(){
    InputExtraction();
}

void InputExtraction(){
             #ifdef _WIN32
                system("cls");
            #else
                cout << "\033[2J\033[1;1H";  // ANSI escape codes to clear console on Unix-based systems
            #endif

    string equation;
    string first;
    string operat;
    string second;
    cout << "Please Enter An Equation: " << "\n";
    cin >> equation;
    int pos;
    for(int i = 0; i < equation.size();i++){
       if(equation[i] == '+' || equation[i] == '*' || equation[i] == '/' || equation[i] == '-'){
            operat = equation[i];
            pos = i;
        }
    }
    first = equation.substr(0,pos);
    operat = equation.substr(pos,1);
    second = equation.substr(pos+1);

 if (!isValidNumber(first) || !isValidNumber(second)) {
        cout << "Invalid input. Please enter valid numeric values." << "\n";
        InputExtraction();  // Retry input if it's invalid
        return;
    }

    Logic(first,second,operat);
}

bool isValidNumber(const string& str) {
    try {
        stod(str);  // Attempt to convert the string to a double
        return true; // Conversion succeeded, input is valid
    } catch (...) {
        return false; // Conversion failed, input is not a valid number
    }
}

void Logic(string firstNum, string secondNum, string operato){
    
    int numer = stod(firstNum);
    int numer2 = stod(secondNum);
    if(operato == "+"){
        cout << numer << " + " << numer2 <<" = "<< numer + numer2 << "\n";
    }
    else if(operato == "*"){
        cout << numer << " * " << numer2 <<" = "<< numer * numer2 << "\n";
    }
    else if(operato == "/"){
        cout << numer << " / " << numer2 <<" = "<< numer / numer2 << "\n";
    }
    else if(operato == "-"){
        cout << numer << " - " << numer2 <<" = "<< numer - numer2 << "\n";
    }
    else{
        cout << ">:(";
    }
    recurtion();
}

void recurtion(){

    char answer;
    do {
        cout << "Would you like to input a new equation? (y/n) ";
        cin >> answer;

        if (answer == 'y') {
            #ifdef _WIN32
                system("cls");
            #else
                cout << "\033[2J\033[1;1H";  // ANSI escape codes to clear console on Unix-based systems
            #endif
            InputExtraction();
        } else if (answer != 'n') {
            cout << "Invalid choice. Please enter 'y' or 'n'." << "\n";
        }
    } while (answer != 'n');

}





