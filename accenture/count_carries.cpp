#include <iostream>
using namespace std;

int countCarries(int num1, int num2) {
    int carry = 0;      
    int carryCount = 0; 
    

    while (num1 > 0 || num2 > 0 || carry > 0) {
        
        
        int digit1 = num1 % 10;
        int digit2 = num2 % 10;
        
        
        int sum = digit1 + digit2 + carry;
        
    
        if (sum >= 10) {
            carry = 1;   
            carryCount++; 
        } else {
            carry = 0;   // No carry for this step
        }
        
        
        num1 /= 10;
        num2 /= 10;
    }
    
    return carryCount;
}

int main() {
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    
    int result = countCarries(num1, num2);
    cout << "Total number of carries: " << result << endl;
    
    return 0;
}