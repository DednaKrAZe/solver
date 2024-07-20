#include <cmath>
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

bool is_normal(string n)
{
    long long int count = n.size();
    int cdots = 0;
    for (int i = 0; i < n.size(); i++) {
        int code = (int)(n[i]);
        if (code <= 57 and code >= 48 or code == 45 and i == 0 or code == 46) {
            count -= 1;
            if (n[i] == '.') {
                cdots += 1;
            }
        }
    }
    if (count == 0 and cdots<=1) {
        return true;
    }
    else {
        return false;
    }
}

bool is_long(string n) {
    return (n.size() < 100);
}

class StandEq {
protected:
    long double a;
    long double b;
    long double c;
public:
    StandEq(long double _a, long double _b,long double _c) {
        a = _a;
        b = _b;
        c = _c;
    }
    double disc() {
        long double discriminant = b * b - a * c * 4;
        if (discriminant >= 0) {
            return discriminant;
        }
        else {
            return -1;
        }
    }
    void xstand() {
        cout << "solutions are: ";
        double discriminant = disc();
        if (discriminant >= 0) {
            long double x1 = (-b - sqrt(discriminant)) / (2 * a);
            long double x2 = (-b + sqrt(discriminant)) / (2 * a);
            if (x1 != x2) {
                cout << x1 << ' ' << x2 << endl << endl;
            }
            else {
                cout << x1 << endl << endl;
            }
        }
        else {
            cout << "discriminant is below zero" << endl << endl;
        }
    }
    void xstandc() {
        cout << "solutions are: ";
        double discriminant = disc();
        if (discriminant >= 0) {
            long double t1 = (-b - sqrt(disc())) / (2 * a);
            long double t2 = (-b + sqrt(disc())) /( 2 * a);
            long double x1, x2, x3, x4;
            if (t1 >= 0) {
                x1 = sqrt(t1);
                x2 = -sqrt(t1);
                if (x1 != x2) {
                    cout << x1 << ' ' << x2 << ' ';
                }
                else {
                    cout << x1 << ' ';
                }
            }
            if (t2 >= 0) {
                x3 = sqrt(t2);
                x4 = -sqrt(t2);
                if (t1 < 0) {
                    if (x3 != x4) {
                        cout << x3 << ' ' << x4 << ' ';
                    }
                    else {
                        cout << x3 << ' ';
                    }
                }
                else {
                    if (x3 != x1 and x3 != x2) {
                        cout << x3 << ' ';
                    }
                    if (x4 != x3 and x4 != x2 and x4 != x1) {
                        cout << x4 << ' ';
                    }
                }
            }
        }
        else {
            cout << "discriminant is below zero";
        }
        cout << endl << endl;
    }
    ~StandEq() {}
};

class EWOA {
protected:
    long double b;
    long double c;
public:
    EWOA(long double _b, long double _c) {
        b = _b;
        c = _c;
    }
    void xwoa() {
        cout << "solutions are: ";
        long double x = (-c) / b;
        cout << x << endl << endl;
    }
    void xwoaс() {
        cout << "solutions are: ";
        long double t = (-c) / b;
        if (t >= 0) {
            long double x1 = -(sqrt(t));
            long double x2 = (sqrt(t));
            if (x1 != x2) {
                cout << x1 << ' ' << x2 << endl << endl;
            }
            else {
                cout << x1 << endl << endl;
            }
        }
        else {
            cout << "There is no any non-complex solution" << endl << endl;
        }
    }
    ~EWOA() {}
};
class EWOC {
protected:
    long double a;
    long double b;
public:
    EWOC(long double _a, long double _b) {
        a = _a;
        b = _b;
    }
    void xwoc() {
        cout << "solutions are: ";
        long double x1 = 0;
        long double x2 = (-b) / a;
        cout << x1 << ' ' << x2 << endl << endl;
    }
    void xwocc() {
        cout << "solutions are: ";
        cout << 0 << ' ';
        long double t2 = (-b) / a;
        if (t2 >= 0) {
            long double x1 = -sqrt(t2);
            long double x2 = sqrt(t2);
            cout << x1 << ' ' << x2;
        }
        else {
            cout << "There is no any non-complex number";
        }
        cout << endl << endl;
    }
    ~EWOC() {}
};
class EWOB {
protected:
    long double a;
    long double c;
public:
    EWOB(long double _a, long double _c) {
        a = _a;
        c = _c;
    }
    void xwob() {
        cout << "solutions are: ";
        if (c * a < 0.0) {
            long double x1 = sqrt((-c) / a);
            long double x2 = -sqrt((-c) / a);
            if (x1 != x2) {
                cout << x1 << ' ' << x2 << endl;
            }
            else {
                cout << x1 << endl;
            }
        }
        else {
            cout << "There is no any non-complex answer" << endl << endl;
        }
    }
    void xwobc() {
        cout << "There is no any non-complex answer" << endl << endl;
    }
    ~EWOB() {}
};

class EWC {
protected:
    long double c;
public:
    EWC(long double _c) {
        c = _c;
    }
    void xwc() {
        cout << "solutions are: ";
        if (c != 0) {
            cout << "uncorrect equation" << endl << endl;
        }
        else {
            cout << "x is any number" << endl << endl;
        }
    }
    ~EWC() {}
};

class EWAoB {
protected:
    long double var;
public:
    EWAoB(long double _var) {
        var = _var;
    }
    void xwaob() {
        cout << "solutions are: 0" << endl << endl;
    }
    ~EWAoB() {}
};

void Set_EQ(long double a, long double b, long double c, int type) {
    if (a != 0 and b != 0 and c != 0) {
        StandEq obj(a, b, c);
        if (type == 1) {
            obj.xstand();
        }
        else {
            obj.xstandc();
        }
    }
    else if (a != 0 and b != 0 and c == 0) {
        EWOC obj(a, b);
        if (type == 1) {
            obj.xwoc();
        }
        else {
            obj.xwocc();
        }
    }
    else if (a == 0 and b != 0 and c != 0) {
        EWOA obj(b, c);
        if (type == 1) {
            obj.xwoa();
        }
        else {
            obj.xwoaс();
        }
    }
    else if (a == 0 and b == 0) {
        EWC obj(c);
        obj.xwc();
    }
    else if (a != 0 and b == 0 and c != 0) {
        EWOB obj(a, c);
        if (type == 1) {
            obj.xwob();
        }
        else {
            obj.xwobc();
        }
    }
    else if (b == 0 and c == 0 and a != 0 or b != 0 and a == 0 and c == 0) {
        if (a != 0) {
            EWAoB obj(a);
            obj.xwaob();
        }
        else {
            EWAoB obj(b);
            obj.xwaob();
        }
    }
}
void menu() {
    int command = 0;
    while (command != 5) {
        if (command == 0) {
            system("cls");
            cout << "This is app for solving quadratic equations. Press appropriate button to choose the command" << endl << "1 - Solve the equation" << endl << "2 - Notice about types of quadratic equations" << endl << "3 - Notice about solving equations" << endl << "4 - User's manual" << endl << "5 - stop" << endl;
            string com;
            cin >> com;
            bool flagcom = false;
            while (flagcom != true) {
                if (is_normal(com)) {
                    if (stod(com)>=0 and stod(com) <=5) {
                        flagcom = true;
                    }
                }
                if (flagcom == false) {
                    cout << "Enter number in range 1-5, please" << endl << endl;
                    cin >> com;
                }
            }
            command = stod(com);
        }
        else if (command == 1) {
            int secondcommand = 0;
            long double a;
            long double b;
            long double c;
            system("cls");
            cout << "If you want to solve standart quadratic equation press 1. If you want to solve the problem with changing variables press 2" << endl;
            string seccom;
            cin >> seccom;
            bool flagsc = false;
            while (flagsc != true) {
                if (is_normal(seccom)) {
                    if (stod(seccom) == 1 or stod(seccom) == 2) {
                        flagsc = true;
                    }
                }
                if (flagsc == false) {
                    cout << "Enter 1 or 2, please" << endl << endl;
                    cin >> seccom;
                }
            }
            secondcommand = stod(seccom);
            system("cls");
            cout << "Enter coefficient a (only nums, not any letters or special symbols):"<<endl;

            string astr;
            cin >> astr;
            bool flaga= is_normal(astr) and is_long(astr);
            if (flaga != true) {
                while (flaga != true) {
                    cout << "Enter a number with lenth under 100 signs, please" << endl << endl;
                    cin >> astr;
                    flaga = is_normal(astr) and is_long(astr);
                }
            }
            a = stod(astr);
            system("cls");
            if (secondcommand == 1) {
                cout << a << "x^2 + ";
            }
            else {
                cout << a << "x^4 + ";
            }
            string bstr;
            cin >> bstr;
            bool flagb = is_normal(bstr) and is_long(bstr);
            if (flagb != true) {
                while (flagb != true) {
                    cout << "Enter a number, please" << endl << endl;
                    cin >> bstr;
                    flagb = is_normal(bstr) and is_long(bstr);
                }
            }
            b = stod(bstr);
            system("cls");
            if (secondcommand == 1) {
                cout << a << "x^2 + (" << b << ")x + ";
            }
            else {
                cout << a << "x^4 + (" << b << ")x^2 + ";
            }
            string cstr;
            cin >> cstr;
            bool flagc = is_normal(cstr) and is_long(cstr);
            if (flagc != true) {
                while (flagc != true) {
                    cout << "Enter a number, please" << endl << endl;
                    cin >> cstr;
                    flagc = is_normal(cstr) and is_long(cstr);
                }
            }
            c = stod(cstr);
            system("cls");
            if (secondcommand == 1) {
                cout << a << "x^2+(" << b << ")x+(" << c << ")=0" << endl << endl;
            }
            else {
                cout << a << "x^4+(" << b << ")x^2+(" << c << ")=0" << endl << endl;
            }
            Set_EQ(a, b, c, secondcommand);
            cout << "press any button to return to the main menu" << endl;
            _getch();
            command = 0;
        }
        else if (command == 2) {
            system("cls");
            cout << "There are 8 types of equations:" << endl << "Standart equation ax^2 + bx + c = 0" << endl << "Equation without coefficient a : bx + c = 0" << endl << "Equation without coefficient b : ax^2 + c = 0" << endl << "Equation without coefficient c : ax^2 + bx = 0" << endl << "Equation with coefficient c : c = 0" << endl << "Equation with coefficient a : ax^2 = 0" << endl << "Equation with coefficient b : bx = 0" << endl << "Zero equation : 0=0" << endl << endl;
            cout << "press any button to return to the main menu" << endl;
            _getch();
            command = 0;
        }
        else if (command == 3) {
            system("cls");
            cout << "If you want to solve equation Ax^2+Bx+C=0, you should find discriminant with formula D=B^2-4AC. And then, if discriminat isn't below zero, your solutions can be find as (-B+sqrt(D))/2A and (-B-sqrt(D))/2A. If D equals 0, your solutions will be equal each other. If D is below zero, your solutions will be complex numbers." << endl<<"If your equation looks like Bx+C=0, you can find solutions with formula -C/B" << endl<<"If you have equation type C=0, you won't find any solutoin.it's just possible to say, is it true (if C equals 0) or false"<<endl<<"If you should to solve equation Ax^2+Bx=0, one of your solution will be 0. Other solution can be find with formula -B/A"<<endl<<"To solve equation Ax^2+C=0 use formulas sqrt(-C/A) and -sqrt(-C/A), but it's possible to solve only if A and C have different signs"<<endl<<"Equations Ax^2=0 and Bx=0 have only one solution. It's 0" << endl<<endl;
            cout << "press any button to return to the main menu" << endl;
            _getch();
            command = 0;
        }
        else if (command == 4) {
            system("cls");
            cout << "First of all, choose command, that you nead, in main menu. To do this, enter appropriate number from 1 to 5" << endl<<"If you choose 1, enter 1 for quadratic equation or 2 for biquadratic equation solving. Than you should to enter coefficients A, B and C. It can be ONLY NUMBERS OR SYMBOLS - AND . , NOT ANY LETTERS OR ANOTHER SYMBOLS" << endl<<"After fulfillment of any task, press any button to return to main menu"<<endl<<endl;
            cout << "press any button to return to the main menu" << endl;
            _getch();
            command = 0;
        }
        else if (command > 5 or command < 1) {
            command = 0;
        }
    }
}

int main() {

    menu();
}
