#include <iostream>
#include <fstream>
using namespace std;
long long a,b,n;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    inputFile >> n;
    while(n--){
        inputFile >> a;
        inputFile >> b;

        long long resa=0,resb=0;
        for(long long i=1; i<=a; i*=2){
            resa+=(a/i);
        }
        for(long long i=1; i<=b; i*=2){
            resb+=(b/i);
        }
        outputFile << resb-resa << endl;
    }
}

