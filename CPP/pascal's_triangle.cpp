#include <iostream>
using namespace std;

// Function to calculate nCr (combinations)
int nCr(int n, int r) {
    int res = 1;
    // Since nCr = n! / (r! * (n - r)!)
    if (r > n - r)
        r = n - r; 
    for (int i = 0; i < r; i++) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

void printPascal(int rows) {
    for (int n = 0; n < rows; n++) {
        for (int space = 0; space < rows - n - 1; space++)
            cout << "  ";

        // printing each element 
        for (int r = 0; r <= n; r++)
            cout << nCr(n, r) << "   ";

        cout << endl;
    }
}

int main() {
    int rows;
    cout << "Enter number of rows: "; // No of rows for Pascal's Triangle
    cin >> rows;
    
    cout << "\nPascal's Triangle:\n";
    printPascal(rows);

    return 0;
}
