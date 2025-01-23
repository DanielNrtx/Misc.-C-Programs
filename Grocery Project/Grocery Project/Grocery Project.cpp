/*
CONSOLE OUTPUT/TESTING RESULTS:
What would you like to buy?
1. Bread
2. Milk
3. Soap
Please enter your choice: 1
Please enter the price: $2.85
Please enter your age: 22
        Invoice
Price:          $2.85
Tax:            $0.00
Total:          $2.85
--------------------------------------------------------
What would you like to buy?
1. Bread
2. Milk
3. Soap
Please enter your choice: 3
Please enter the price: $1.65
Please enter your age: 45
        Invoice
Price:          $1.65
Tax:            $0.14
Total:          $1.79
---------------------------------------------------------
What would you like to buy?
1. Bread
2. Milk
3. Soap
Please enter your choice: 2
Please enter the price: $3.25
Please enter your age: 60
        Invoice
Price:          $3.25
Tax:            $0.00
Total:          $3.25
---------------------------------------------------------
What would you like to buy?
1. Bread
2. Milk
3. Soap
Please enter your choice: 3
Please enter the price: $1.65
Please enter your age: 81
        Invoice
Price:          $1.65
Tax:            $0.14
Discount:       $-0.08
Total:          $1.71
----------------------------------------------------------
What would you like to buy?
1. Bread
2. Milk
3. Soap
Please enter your choice: 5
You're input was invalid, goodbye
*/

/*
----- Header Comments ----------------------------------------------------------
Exercise:
Coder: Daniel Nelson
Date:
Period: 6

Purpose:

TODO:

*/

//----- Imports -----------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

//----- Global Variables --------------------------------------------------------

double const elderlyDiscount = -.05;
double const taxRate = .08;


//----- No-Touch Functions ------------------------------------------------------

//----- My Functions ------------------------------------------------------------

double money(double number) {
    double checkingNumber = (int(number*100)-int(number*100))*10;
    if (checkingNumber <= 5) {
        number = ceil(number * 100) / 100;
    }
    else {
        number = floor(number * 100) / 100;
    }
    return number;
}//makes number end with 2 decimals

int askForProduct() {
    int product;
    cout << "What would you like to buy? \n1. Bread \n2. Milk\n3. Soap\nPlease enter your choice: ";
    cin >> product;
    return product;
}

double askForPrice() {
    double price;
    cout << "Please enter the price: $";
    cin >> price;
    return price;
}

int askForAge() {
    int age;
    cout << "Please enter your age: ";
    cin >> age;
    return age;
}

int printInvoice(int product, double price, int age) {
    bool food = true;
    bool elderly = true;
    double discount = money(price * elderlyDiscount);
    double tax = money(price * taxRate);
    double newPrice = price;
    //non grocery tax
    if (product == 3) {
        newPrice = money(newPrice + (newPrice * taxRate));
        food = false;
    }
    else {food = true;}
    //elderly discount
    if (age >= 80) {
        newPrice = money(newPrice + (newPrice * elderlyDiscount));
        elderly = true;
    }
    else {elderly = false;}
    //printing invoice
    if (food == true && elderly == true) {
        cout << "\tInvoice\nPrice:\t\t$" << price << "\nTax:\t\t$0.00\nDiscount:\t$" << discount << "\nTotal:\t\t$" << newPrice;
    }
    else if (food == false && elderly == true) {
        cout << "\tInvoice\nPrice:\t\t$" << price << "\nTax:\t\t$" << tax << "\nDiscount:\t$" << discount << "\nTotal:\t\t$" << newPrice;
    }
    else if (food == true && elderly == false) {
        cout << "\tInvoice\nPrice:\t\t$" << price << "\nTax:\t\t$0.00\nTotal:\t\t$" << newPrice;
    }
    else if (food == false && elderly == false) {
        cout << "\tInvoice\nPrice:\t\t$" << price << "\nTax:\t\t$" << tax << "\nTotal:\t\t$" << newPrice;
    }



    return 0;
}


//----- Driver Code -------------------------------------------------------------

int main() {
    int inputProduct = askForProduct();
    if (inputProduct < 1 || inputProduct > 3) {
        cout << "You're input was invalid, goodbye";
        return 0;
    }//end if block
    double inputPrice = askForPrice();
    int inputAge = askForAge();
    printInvoice(inputProduct, inputPrice, inputAge);
}