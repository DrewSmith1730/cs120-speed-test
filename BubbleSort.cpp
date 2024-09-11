#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    int size;
    // Get command line input
    if (argc > 1) {
        size = stoi(argv[1]);
    } else {
        size = 10000;
    }
    cout << "Looking for size: " << size << endl;
    
    // TODO: Declare a vector of longs to store the numbers
    vector<long> nums;
	
    // TODO: Read size numbers from numbers.txt
    ifstream fin;
	fin.open("../numbers.txt");
	long x;
	int i = 0;
	while(fin >> x && i < size){
		nums.push_back(x);
		i++;
	}
	
    // TODO: Print the vector size (to make sure it matches the size printed above)
    cout << nums.size() << endl;
	
    // TODO: Bubble Sort the vector
    bool haveSwapped = true;
    int numPasses = 0;
	while (haveSwapped) {
        haveSwapped = false;
        for (int i = 0; i+1 < nums.size() - numPasses; ++i) {
            if (nums[i] > nums[i+1]) { // 2 reads here
                // The two elements are out of order. Swap them.
                long temp = nums[i]; // write and read
                nums[i] = nums[i+1]; // write and a read
                nums[i+1] = temp; // write and a read
                // Update haveSwapped
                haveSwapped = true;
            }
        }
        ++numPasses;
    }
	
    // TODO: Print the first and last ten numbers from the vector to the console
	cout << "First 10 digits in nums" << endl;
	for(int i = 0; i < 10; i++){
		cout << nums[i] << endl;
	}
	cout << "Last 10 digits in nums" << endl;
	for(int i = nums.size() - 10; i < nums.size(); i++){
		cout << nums[i] << endl;
	}
	
    return 0;
}
