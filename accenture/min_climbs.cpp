
//1 se n steps......


#include <iostream>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    // Number of full M-step climbs
    long long fullMClimbs = N / M;

    // If there's a remainder (remaining steps), one more climb is needed
    long long remainder = N % M;
    long long totalClimbs = fullMClimbs + (remainder > 0 ? 1 : 0);

    cout << totalClimbs << endl;
    return 0;
}