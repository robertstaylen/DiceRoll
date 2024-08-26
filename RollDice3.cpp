#include <iostream>
#include <iomanip>
#include <cstdlib> //for rand()
#include <ctime>   

using namespace std;

int main() {
    const int rolls = 36000;
    const int sides = 6;
    const int combinations = 11;  // 2 through 12
    
    int dice1, dice2, sum;
    int frequency[combinations] = {0};  // Initialize array elements to 0

    //random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Roll the dice 36,000 times
    for (int i = 0; i < rolls; ++i) {
        dice1 = 1 + rand() % sides;  // Random number between 1 and 6
        dice2 = 1 + rand() % sides;  // Random number between 1 and 6
        sum = dice1 + dice2;
        ++frequency[sum - 2];  // Increment the corresponding array element
    }

    //results in a tabular format
    cout << setw(10) << "Sum" << setw(15) << "Frequency" << setw(15) << "Relative Frequency" << endl;

    for (int i = 2; i <= 12; ++i) {
        double relativeFrequency = static_cast<double>(frequency[i - 2]) / rolls;
        cout << setw(10) << i << setw(15) << frequency[i - 2] << setw(15) << relativeFrequency << endl;
    }

    return 0;
}
