/*
Lab 6 
Problem 2
CS 008 - Jason Li
*/

#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

int precedence(char op){
    if(op == '*' || op == '/'){
        return 2;
    }else if(op == '+' || op == '-'){
        return 1;
    }else{
        return 0;
    }
}

string infixToPostFix(const string& infixNotation){
    string postFix;
    stack<char> RPN;

    for(char c : infixNotation){
        //If theres parentheses
        if(c == '('){
            RPN.push(c);
        }else if(c == ')'){
            while(!RPN.empty() && RPN.top() != '('){
                postFix += RPN.top();
                RPN.pop();
            }
            if(!RPN.empty()){
                RPN.pop();
            } 
        }else if(precedence(c) > 0){
            while(!RPN.empty() && precedence(RPN.top()) >= precedence(c)){
                postFix += RPN.top();
                RPN.pop();
            }
            RPN.push(c);
        }else{
            postFix += c;
        }
    }

    while(!RPN.empty()){
        if(RPN.top() != '('){
            postFix += RPN.top();
        }
        RPN.pop();
    }

    return postFix;
}

double evaluatePostFix(const string& postFix){
    stack<double> values;

    for(char c : postFix){
        if(isdigit(c)){
            values.push(c - '0');
        } else {
            if(values.size() < 2)
                throw runtime_error("Malformed expression");

            int b = values.top(); values.pop();   // right operand
            int a = values.top(); values.pop();   // left operand

            switch(c){
                case '+': values.push(a + b); break;
                case '-': values.push(a - b); break;
                case '*': values.push(a * b); break;
                case '/':
                    if(b == 0){
                        cout << "Division by zero"; 
                        break;
                    }
                    values.push(a / b);
                    break;
                default:
                    cout << "Unknown operator";

            }
        }
    }

    return values.top();
}

int main(){
    string fileName;
    cout << "Enter filename: ";
    cin >> fileName; 
    ifstream file(fileName);

    if(!file.is_open()){
        cerr << "Could not open " << fileName << endl;
        return 1;
    }

    string line;
    while(getline(file, line)){
        if(line.empty()) continue;
        cout << "Infix   :  " << line << endl;
        cout << "Postfix :  " << infixToPostFix(line) << endl;
        cout << "Result  :  " << evaluatePostFix(infixToPostFix(line)) << endl;
        cout << endl;
    }

    file.close();
    return 0;
}