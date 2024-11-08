#include <iostream>
#include <cmath>
using namespace std;

class Calculator {
public:

    float add(float a, float b){
        return a + b;
    }

    float subtract(float a, float b){
        return a - b;
    }

    float multiply(float a, float b){
        return a * b;
    }

    float divide(float a, float b){
        if(b != 0){
            return a / b;
        }
        else{
            cout << "Cannot divide by zero. Please try again.";
            return 0;
        }
    }

    int sum_m_n(int m, int n){
        // Sum of all numbers between M and N such that M<N.
        int sum = 0;

        if(n>m){
        
        for(int i=m; i<=n; i++){
            sum = sum + i;
        }
        return sum;
        }
        else{
            cout<< m << " should not be greater than " << n;
            return 0;
        }
    }

    int fibonacci(int n){
        // Fibonacci for 0 is 0 and 1 is 1.
        if(n <= 1){
            return n;
        }

        return fibonacci(n - 1) + fibonacci(n - 2);
    }
    bool palindrome(int num){
        int original = num; 
        int reverse = 0;
        
        while(num>0){
            int last_digit;
            last_digit = num % 10; 
            reverse = reverse * 10 + last_digit; 
            num /= 10;
        }

        if(reverse == original){
            return true;
        }
        else{
            return false;   
        }
    }

    bool prime_or_not(int num){
        if(num < 2){
            return false;
        }
        else{
            for(int i=2; i<num; i++){
                if(num % i == 0){
                    return false;
                }
                else{
                    return true;
                }
            }
        }
    }

    int gcd(int num1, int num2){

        int small_number, gcd;

        if(num1> num2){
            small_number = num2;
        }

        else {
            small_number = num1;
        }

        //Finding the Greatest Common Divisor using this loop:
        for(int i = 1; i <= small_number; i++) {
            if(num1 % i == 0 && num2 % i == 0){
                gcd = i; 
            }
        }
        return gcd;
    }

    bool armstrong(int n){
        string num;
        num = to_string(n);

        int power = num.length();

        int a;
        int sum = 0;

        for(int i = 0; i<power; i++){
            
            a = num[i]-'0';
            sum += pow(a, power);
            
        }

        if (sum == n){
            cout << n << " is an Armstrong number.";
        }
        else {
            cout << n << " is not an Armstrong number.";
        }
    }

    void quadEqn(float a, float b, float c) {
        float delta = (b * b) - (4 * a * c);
        if (delta >= 0) {
            float x1 = (-b + sqrt(delta)) / (2 * a);
            float x2 = (-b - sqrt(delta)) / (2 * a);
            if (delta == 0) {
                cout << "The roots are " << x1 << " and are real and equal.";
            } else {
                cout << "The roots are " << x1 << " and " << x2 << " and are real and unequal.";
            }
        } else {
            cout << "The roots are complex and not real.";
        }
    }

    int factorial(int n){
        if(n < 2){
            return 1;
        }

        return n * factorial(n-1); //Recursion is used
    }
};

int main(){
    Calculator calc;
    int choice;

    while(true){
        cout << endl << "Select an operation to perform: " << endl;
        cout << "1. Add" << endl;
        cout << "2. Subtract" << endl;
        cout << "3. Multiply" << endl;
        cout << "4. Divide" << endl;
        cout << "5. Find factorial" << endl;
        cout << "6. Check for palindrome" << endl;
        cout << "7. Check for Armstrong number" << endl;
        cout << "8. Check for prime number" << endl;
        cout << "9. Find GCD" << endl;
        cout << "10. Find LCM" << endl;
        cout << "11. Find sum between M and N" << endl;
        cout << "12. Solve quadratic equation" << endl;
        cout << "13. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        if(choice == 13){
            break;
        }

        switch(choice) {
            case 1:{
                float a, b;
                cout << "Adding two numbers: " << endl;
                cout << endl << "Number a: ";
                cin >> a;
                cout << "Number b: ";
                cin >> b;
                cout << "Result: " << calc.add(a, b) << endl;
                break;
            }
            case 2:{
                float a, b;
                cout << "Subtracting two numbers: " << endl;
                cout << endl << "Number a: ";
                cin >> a;
                cout << "Number b: ";
                cin >> b;
                cout << "Result: " << calc.subtract(a, b) << endl;
                break;
            }
            case 3:{
                float a, b;
                cout << "Multiplying two numbers: " << endl;
                cout << endl << "Number a: ";
                cin >> a;
                cout << "Number b: ";
                cin >> b;
                cout << "Result: " << calc.multiply(a, b) << endl;
                break;
            }
            case 4:{
                float a, b;
                cout << "Dividing two numbers: " << endl ;
                cout << endl << "Number a: ";
                cin >> a;
                cout << "Number b: ";
                cin >> b;
                cout << "Result: " << calc.divide(a, b) << endl;
                break;
            }
            case 5:{
                int n;
                cout << "Enter a number: ";
                cin >> n;
                cout << "Factorial of  " << n << " is: " << calc.factorial(n) << endl;
                break;
            }
            case 6:{
                int num;
                cout << "Enter a number: ";
                cin >> num;
                if(calc.palindrome(num)){
                    cout << "The number " << num << " is a palindrome." << endl;
                }
                else{
                    cout << "The number " << num << " is not a palindrome." << endl;
                }
                break;
            }
            case 7:{
                int n;
                cout << "Enter a number: ";
                cin >> n;
                if(calc.armstrong(n)){
                    cout << "The number " << n << " is an Armstrong number." << endl;
                }
                else{
                    cout << "The number " << n << " is not an Armstrong number." << endl;
                }
                break;
            }
            case 8:{
                int num;
                cout << "Enter a number: ";
                cin >> num;
                if(calc.prime_or_not(num)){
                    cout << "The number " << num << " is a Prime number." << endl;
                }
                else{
                    cout << "The number " << num << " is not a Prime number." << endl;
                }
                break;
            }
            case 9:{
                int num1, num2;
                cout << "Finding GCD: ";
                cout << endl << "Number a: ";
                cin >> num1;
                cout << "Number b: ";
                cin >> num2;
                cout << "GCD: " << calc.gcd(num1, num2) << endl;
                break;
            }
            case 10:{
                int num1, num2;
                cout << "Finding LCM: ";
                cout << endl << "Number a: ";
                cin >> num1;
                cout << endl << "Number b: ";
                cin >> num2;
                int g = calc.gcd(num1, num2);
                cout << "LCM: " << ((num1*num2)/g);
                break;
            }
            case 11:{
                int m, n;
                cout << "Enter two numbers M and N (M < N): ";
                cin >> m >> n;
                cout << "Sum: " << calc.sum_m_n(m, n) << endl;
                break;
            }
            case 12:{
                float a, b, c;
                cout << "Enter coefficients a, b, and c: ";
                cin >> a >> b >> c;
                calc.quadEqn(a, b, c);
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    
    cout << "Exiting program." << endl;
    return 0;
}
