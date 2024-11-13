#include <iostream>
#include <vector>
using namespace std;

int averageOfEvenDivisibleBy3(const vector<int>& nums, int N) {
    int sum = 0, count = 0;

    for (int i = 0; i < N; i++) {
        if (nums[i] % 3 == 0 && nums[i] % 2 == 0) {
            sum += nums[i];
            count++;
        }
    }

    if (count == 0) {
        return 0; // If no such number exists, return 0
    }

    return sum / count; //avaerage nikalna un sub numbers ka..(to sum/count)..
}

int main() {
    int N;
    cout << "Enter the size of the array: ";
    cin >> N;

    vector<int> nums(N);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    int result = averageOfEvenDivisibleBy3(nums, N);
    cout << "The average of numbers divisible by 3 and even is: " << result << endl;

    return 0;
}