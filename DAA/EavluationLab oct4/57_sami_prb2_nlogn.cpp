#include <bits/stdc++.h>
using namespace std;

int ceilIndex(vector<int>& input, vector<int>& T, int end, int s) {
    int start = 0;
    int middle;
    int len = end;
    while (start <= end) {
        middle = (start + end) / 2;
        if (middle < len && input[T[middle]] < s && s <= input[T[middle + 1]]) {
            return middle + 1;
        }
        else if (input[T[middle]] < s) {
            start = middle + 1;
        }
        else {
            end = middle - 1;
        }
    }
    return -1;
}

int longestIncreasingSubSequence(vector<int>& input,int k) {
    vector<int> T(input.size());
    vector<int> R(input.size(), -1);
    T[0] = 0;
    int len = 0;

    for (int i = 1; i < input.size(); i++) {
        if (input[T[0]] > input[i]  ) {
            T[0] = i;
        }
        else if (input[T[len]] < input[i]    &&  input[T[0]] - input[i]>=k) {
            len++;
            T[len] = i;
            R[T[len]] = T[len - 1];
        }
        else {
            int index = ceilIndex(input, T, len, input[i]);
            T[index] = i;
            R[T[index]] = T[index - 1];
        }
    }

   
    vector<int> lis;
    int index = T[len];
    while (index != -1) {
        lis.push_back(input[index]);
        index = R[index];
    }

    
    cout << "Longest increasing subsequence: ";
    for (int i = lis.size() - 1; i >= 0; i--) {
        cout << lis[i] << " ";
    }
    cout << endl;

    return len + 1;
}

int main() {
    int n;
    cin>>n;
    
    vector<int> input ;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        input.push_back(x);
        //cout<<b[i]<<endl;
    }
    int k;
    cin>>k;
    cout << "Maximum length: " << longestIncreasingSubSequence(input,k) << endl;
    return 0;
}
