#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 9999999
using namespace std;
int C, n;

double calc (int degree, vector<double> & coeff, double x) {
    double res = 0;
    for (int i=0; i<=degree; i++) {
        res = res*x+coeff[i];
    }
    return res;
}
// find solution between l and r
double find (int degree, vector<double> & coeff, double l, double r) {
    double leftSol = calc(degree,coeff,l), rightSol = calc(degree,coeff,r);
    if ((leftSol < 0 && rightSol < 0) || (leftSol >=0 && rightSol >= 0)) {
        cout << "both negative(positive) error!" << endl;
        printf("deg:%d l:%.2lf lsol:%.2lf r:%.2lf rsol:%.2lf \n",degree, l, leftSol, r, rightSol);
        return 0;
    }
    // check if increasing
    bool incr = leftSol < rightSol;
    for (int i=0; i<100; i++) {
        double mid = (l+r)/2;
        if (incr ^ (calc(degree,coeff,mid) >= 0))
            l = mid;
        else
            r = mid;
    }
    return r;
}

void differentiate (int degree, vector<double> & coeff, vector<double> & diff) {
    for (int i=0; i<degree; i++) {
        diff.push_back(coeff[i]*(degree-i));
    }
}
void calcSol (int degree, vector<double> & coeff, vector<double> & sol) {
    if (degree == 1) {
        double x = find(degree, coeff, -1*MAX, MAX);
        sol.push_back(x);
        return;
    }
    vector<double> diffSol, diffCoeff;
    diffSol.push_back(-1*MAX);
    differentiate(degree, coeff, diffCoeff);
    calcSol(degree-1, diffCoeff, diffSol);
    diffSol.push_back(MAX);
    for (int i=0; i<degree; i++) {
        double x = find(degree, coeff, diffSol[i], diffSol[i+1]);
        sol.push_back(x);
    }
}


int main() {
    cin >> C;
    while (C--) {
        cin >> n;
        vector<double> coeff;
        double tmp;
        for (int i=0; i<=n; i++) {
            cin >> tmp;
            coeff.push_back(tmp);
        }
        vector<double> sol;
        calcSol(n, coeff, sol);
        for (int i=0; i<sol.size(); i++)
            printf("%.10lf ", sol[i]);
        cout << endl;
    }
}
