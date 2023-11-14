#include<iostream>
#include<vector>
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
}

void polynomial :: addTerm(int c, int e) {
    struct terms newterm;
    newterm.coeff = c;
    newterm.exp = e;
    terms_vector.push_back(newterm);
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
                temp.addTerm(termA.coeff + termB.coeff, termA.exp);

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
            }
        }
    }
    return temp;
}


polynomial operator*(const polynomial a, const polynomial b) {
    polynomial temp;
        unordered_map<int, int> map1;
    for (const auto&termA : a.terms_vector) {
        for (const auto&termB : b.terms_vector) {
            int coeff_result = termA.coeff * termB.coeff;
            int exp_result = termA.exp * termB.exp;
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

int main() {
    polynomial p1;
    p1.addTerm(5, 3);
    p1.addTerm(2, 1);
    polynomial p2;
    p2.addTerm(6, 3);
    p2.addTerm(10, 1);
    p2.addTerm(1, 2);
    polynomial p3;
    p3 = p1 * p2;
    p3.displaypoly();

    return 0;
}