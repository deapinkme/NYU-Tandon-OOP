
#include <iostream>
#include <vector>

using namespace std;

void do_second(double& val) {
    val -= 4;
}

double* do_first() {
    double gamma = 5.5;
    do_second(gamma);
    gamma--;
    return &gamma;
}

int main() {
    double* result = do_first();
    cout << *result << endl;
}