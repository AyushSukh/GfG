//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for
class Solution{
public:
    int firstOccurrence(int arr[], int n, int x) {
        int low = 0, high = n - 1;
        int first = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == x) {
                first = mid;
                high = mid - 1; // look for smaller index on the left
            } else if (arr[mid] < x) {
                low = mid + 1; // look on the right
            } else {
                high = mid - 1; // look on the left
            }
        }
        return first;
    }

    int lastOccurrence(int arr[], int n, int x) {
        int low = 0, high = n - 1;
        int last = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == x) {
                last = mid;
                low = mid + 1; // look for larger index on the right
            } else if (arr[mid] < x) {
                low = mid + 1; // look on the right
            } else {
                high = mid - 1; // look on the left
            }
        }
        return last;
    }

    int count(int arr[], int n, int x) {
        int first = firstOccurrence(arr, n, x);
        if (first == -1) return 0; // x is not present in the array

        int last = lastOccurrence(arr, n, x);
        return last - first + 1; // count of occurrences of x
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends