#include <iostream>

using namespace std;

int main()
{
    char operation;
    double num1,num2,Result;

    cout<<"-----------------"<<endl;
    cout<<"SIMPLE CALCULATOR"<<endl;
    cout<<"-----------------"<<endl;

    //getting the input from the use
    cout<<"choose the operator (+,-,/,*):"<<endl;
    cin >> operation;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    cout<<"-----------------"<<endl;

    switch(operation){
    case '+':
     Result=num1+num2;
     cout<<"Result:"<<Result<<endl;
     break;

    case '-':
     Result=num1-num2;
     cout<<"Result:"<<Result<<endl;
     break;

    case '*':
     Result=num1*num2;
     cout<<"Result:"<<Result<<endl;
     break;

     case '/':
      if(num2!=0){
        Result=num1/num2;
        cout<<"Result:"<<Result<<endl;
      }else {
      cout<<"Error:cannot divide by zero"<<endl;
      }
      break;

      default:
      cout<<"Error: Operation is invalid"<<endl;
      break;
    }
    return 0;
}
