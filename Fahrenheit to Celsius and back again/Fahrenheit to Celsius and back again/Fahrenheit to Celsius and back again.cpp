/*
---- - Header Comments----------------------------------------------------------
Exercise:Fahrenheit to Celsius and Celsius to Fahrenheit
Coder: Daniel Nelson
Date : 1/24/21

Purpose : Fahreneit and Celsius Converter

TODO : 
*/

//----- Imports -----------------------------------------------------------------

#include <iostream>
using namespace std;

//----- Global Variables --------------------------------------------------------

//----- No-Touch Functions ------------------------------------------------------

//----- My Functions ------------------------------------------------------------

double fahrenheitToCelsius(double fahrenheit) {
    double celsius = (fahrenheit - 32) / 1.8;
    return celsius;
}
//Converts Fahrenheit to Celsius

double celsiusToFahrenheit(double celsius) {
    double fahrenheit = (celsius * 1.8) + 32;
    return fahrenheit;
}


//Converts Celsius to Fahrenheit

//----- Driver Code -------------------------------------------------------------

int main() {
    int answer;
    double inputTemp;
    cout << "Would You like to convert Fahrenheit to Celsius (1) Or Celsius to Fahrenheit (2)?\n";
    cin >> answer;
    while (true) {
        if (answer == 1) { //fahrenheit to celsius
            cout << "What is the temperature in Fahrenheit you would like to convert to Celsius?\n";
            cin >> inputTemp;
            double celsiusOut = fahrenheitToCelsius(inputTemp);
            cout << inputTemp << " degrees Fahrenheit is " << celsiusOut << " degrees Celsius.\n";
            break;//only breaks if 1 or 2 is answered
        }//end of if conditional
        else if (answer == 2) { //celsius to fahrenheit
            cout << "What is the temperature in Celsius you would like to convert to Fahrenheit?\n";
            cin >> inputTemp;
            double fahrenheitOut = celsiusToFahrenheit(inputTemp);
            cout << inputTemp << " degrees Celsius is " << fahrenheitOut << " degrees Fahrenheit.\n";
            break;//only breaks if 1 or 2 is answered
        }//end of else if conditional
        else { //making sure they answer 1 or 2
            cout << "Please answer with a 1 or 2\n";
            cin >> answer;
        }//end of else conditional
    }//end of while loop
    cout << "Thank you for using my program! BYE\n";
}