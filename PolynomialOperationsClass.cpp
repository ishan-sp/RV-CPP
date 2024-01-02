#include<iostream>
#include<vector>
#include<cmath>
#include <unordered_map>
using namespace std;

class polynomial {
    private:
        struct terms {
            int coeff;
            int exp;
        };
        
    public:
        vector<terms> terms_vector;
        void addTerm(int c, int e);
        void displaypoly(void);
        void computeValue(int b);
        polynomial& operator=(const polynomial &other);
        friend polynomial operator+(const polynomial& a, const polynomial& b);
        friend polynomial operator-(const polynomial& a, const polynomial& b);
        friend polynomial operator*(const polynomial& a, const polynomial& b);
};

void polynomial :: displaypoly(void) {
    for(int i = 0; i < terms_vector.size(); i++) {
        if (i != (terms_vector.size() - 1))  {
            cout << terms_vector[i].coeff << "x^" << terms_vector[i].exp << "+";
        }
        else {
            cout << terms_vector[i].coeff << "x^" << terms_vector[i].exp;
        }
    }
    cout << endl;
}

void polynomial :: addTerm(int c, int e) {
    struct terms newterm;
    newterm.coeff = c;
    newterm.exp = e;
    terms_vector.push_back(newterm);
}

void polynomial :: computeValue(int b) {
    int sum = 0;
    for (const auto &term : terms_vector) {
        sum = sum + term.coeff * pow(b, term.exp);
    }
    cout << "The value is " << sum << endl;
}

polynomial operator+(const polynomial& a, const polynomial& b) {
    polynomial temp;

    // Iterate through terms of a
    //for(int i =0; i < a.terms_vector.size(); i++)
    //for j in l1: python counterpart
    for (const auto& termA : a.terms_vector) {
        bool foundMatch = false;

        // Iterate through terms of b to find a matching exponent
        for (const auto& termB : b.terms_vector) {
            if (termA.exp == termB.exp) {
                temp.addTerm(termA.coeff + termB.coeff, termA.exp);
                foundMatch = true;
                break;  // No need to check the rest of the terms in b for this exponent
            }
        }

        // If no match was found in b, add the term from a
        if (!foundMatch) {
            temp.addTerm(termA.coeff, termA.exp);
        }
    }

    // Iterate through terms of b to find terms with non-matching exponents
    for (const auto& termB : b.terms_vector) {
        bool foundMatch = false;

        // Check if the term with the same exponent is already added from a
        for (const auto& termA : a.terms_vector) {
            if (termA.exp == termB.exp) {
                temp.addTerm(termB.coeff, termB.exp);
                foundMatch = true;
                break;
            }
        }
        if (!foundMatch) {
            temp.addTerm(termB.coeff, termB.exp);
        }
    }
    return temp;
}

polynomial operator-(const polynomial&a, const polynomial&b) {
    polynomial temp;

    for (const auto& termA : a.terms_vector) {
        bool foundMatch = false; 

        for(const auto& termB : b.terms_vector) {
            if(termA.exp == termB.coeff)  {
                temp.addTerm(termA.coeff - termB.coeff, termA.exp);

                foundMatch = true;
                break;
            }
        }
        if (!foundMatch) {
            temp.addTerm(termA.coeff, termA.exp);
    }
    }
    for (const auto& termB : b.terms_vector) {
        bool foundMatch = false;
        for (const auto&termA : a.terms_vector) {
            if (termA.coeff == termB.coeff) {
                temp.addTerm(termA.coeff - termB.coeff, termB.exp);
                foundMatch = true;
                break;
            }
        }
    if (!foundMatch) {
        temp.addTerm(termB.coeff, termB.exp);
        }
    }
    return temp;
}


polynomial operator*(const polynomial& a, const polynomial& b) {
    polynomial temp;
    unordered_map<int, int> map1;
    for (const auto&termA : a.terms_vector) {
        for (const auto&termB : b.terms_vector) {
            int coeff_result = termA.coeff * termB.coeff;
            int exp_result = termA.exp + termB.exp;
            if (map1.find(exp_result) != map1.end()) {
                map1[exp_result] += coeff_result;
            }
            else {
                map1[exp_result] = coeff_result;
            }
            }
        }
        for(const auto& pair : map1) {
            temp.addTerm(pair.second, pair.first);
        }
        return temp;
    }
    
polynomial& polynomial::operator=(const polynomial& other) {
    if (this != &other) {
        // Clear current terms_vector to avoid memory leaks
        terms_vector.clear();

        // Copy terms from other polynomial
        terms_vector = other.terms_vector;
    }

    return *this;
}

istream& operator>>(istream& in, polynomial& poly) {
    int numTerms;
    cout << "Enter the number of terms: ";
    in >> numTerms;

    for (int i = 0; i < numTerms; i++) {
        int coeff, exp;
        cout << "Enter coefficient and exponent for term " << i + 1 << ": ";
        in >> coeff >> exp;
        poly.addTerm(coeff, exp);
    }
    return in;
}

ostream& operator<<(ostream& out, polynomial &poly) {
    poly.displaypoly();
    return out;
}

int main() {
    polynomial p1, p2, p3, p4, p5;
    p1.addTerm(5, 3);
    p1.addTerm(2, 1);
    p2.addTerm(6, 3);
    p2.addTerm(10, 1);
    p2.addTerm(1, 2);
    p1.computeValue(1);
    p3 = p1 * p2;
    cout << p3;
    p4 = p2-p1;
    cout << p4;
    cout << p1;
    cin >> p5;
    cout << p5;
    p5 = p1;
    cout << p5;

    return 0;
}