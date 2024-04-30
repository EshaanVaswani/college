#include <iostream>
#include <vector>

using namespace std;

int totalCalls = 0; // Global variable to count the number of recursive function calls

// Function to print the current subset
void printSubset(const vector<int>& subset) {
    cout << "{ ";
    for (int num : subset) {
        cout << num << " ";
    }
    cout << "}" << endl;
}

// Recursive function to find all subsets that sum up to the target
void findSubsets(const vector<int>& nums, int index, vector<int>& current, int sum, int target) {
    totalCalls++; // Increment the call count

    // Check if the current sum equals the target sum
    if (sum == target) {
        printSubset(current); // Print the valid subset
        return; // Return to explore other possibilities
    }

    // If the sum exceeds the target or if we reach the end of the list, return
    if (sum > target || index == nums.size()) {
        return;
    }

    // Include the current element in the subset
    current.push_back(nums[index]);
    findSubsets(nums, index + 1, current, sum + nums[index], target);

    // Exclude the current element from the subset
    current.pop_back();
    findSubsets(nums, index + 1, current, sum, target);
}

int main() {
    vector<int> nums = {10, 7, 5, 18, 12, 20, 15}; // Set of numbers
    int target = 35; // The target sum to find

    cout << "Subsets that sum to " << target << ":\n";
    vector<int> current; // Current subset being processed
    findSubsets(nums, 0, current, 0, target); // Start the recursive search

    cout << "Total recursive calls: " << totalCalls << endl;

    return 0;
}
