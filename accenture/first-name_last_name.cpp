
//firstanme poora captitaal h,,,lastname poora small ulta krna..

#include <iostream>
#include <cctype>  // For tolower() and toupper()
#include <string>
using namespace std;

int main() {
    string firstname, lastname;
    
    // Take input for first name and last name
    cout << "Enter first name and last name: ";
    cin >> firstname >> lastname;




    // Convert first name to lowercase
    for (int i = 0; i < firstname.length(); i++) {
        firstname[i] = tolower(firstname[i]);
    }

    // Convert last name to uppercase
    for (int i = 0; i < lastname.length(); i++) {
        lastname[i] = toupper(lastname[i]);
    }

    // Print the result
    cout << "Output: " << firstname << " " << lastname << endl;

    return 0;
}
