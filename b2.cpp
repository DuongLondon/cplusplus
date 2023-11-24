#include <iostream>
#include <stack>
#include <cmath>
#include <cctype>

class ExpressionEvaluator {
private:
    std::stack<int> values;
    std::stack<char> operators;

    void applyOperator() {
        int b = values.top(); values.pop();
        int a = values.top(); values.pop();
        char op = operators.top(); operators.pop();

        if (op == '+') values.push(a + b);
        else if (op == '-') values.push(a - b);
        else if (op == '*') values.push(a * b);
    }

public:
    int evaluate(const std::string& expression) {
        for (char ch : expression) {
            if (std::isdigit(ch)) {
                values.push(ch - '0');
            } else if (ch == ' ') {
                continue;  // Bỏ qua khoảng trắng
            } else if (ch == '(') {
                operators.push(ch);
            } else if (ch == ')') {
                while (!operators.empty() && operators.top() != '(') {
                    applyOperator();
                }
                operators.pop();  // Loại bỏ '('
            } else {
                while (!operators.empty() && operators.top() != '(' &&
                       ((ch == '+' || ch == '-') && (operators.top() == '+' || operators.top() == '-' || operators.top() == '*' || operators.top() == '/')) ||
                       ((ch == '*' || ch == '/') && (operators.top() == '*' || operators.top() == '/'))) {
                    applyOperator();
                }
                operators.push(ch);
            }
        }

        while (!operators.empty()) {
            applyOperator();
        }

        return values.top();
    }
};

int main() {
    ExpressionEvaluator evaluator;
    std::string expression;

    std::cout << "Nhap bieu thuc: ";
    std::getline(std::cin, expression);

    int result = evaluator.evaluate(expression);
    std::cout << "Gia tri cua bieu thuc la: " << result << std::endl;

    return 0;
}
