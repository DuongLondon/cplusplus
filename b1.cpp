#include<iostream>

using namespace std;

class Tong {
    int a;
    int b;

public:
    int getSum() {
        int sum = a + b;
        return sum;
    }

    void setSum(int a, int b) {
        this->a = a;
        this->b = b;
    }

    void nhap() {
        cin>>a;
        cin>>b;
    }

    void in() {
        cout << "Tong: " << getSum() << endl;
    }
};

int main() {
    Tong t;
    t.nhap();
    t.in();

    return 0;
}
