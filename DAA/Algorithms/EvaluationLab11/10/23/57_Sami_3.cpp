#include <bits/stdc++.h>
using namespace std;


double calculateDistance(pair<int, int> p1, pair<int, int> p2) {
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}

pair<pair<int, int>, pair<int, int>> findClosestPair(const vector<pair<int, int>>& allPairs) {
    int n = allPairs.size();
    pair<pair<int, int>, pair<int, int>> closestPair;
    double minDistance = numeric_limits<double>::infinity();

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double distance = calculateDistance(allPairs[i], allPairs[j]);
            if (distance < minDistance) {
                minDistance = distance;
                closestPair = {allPairs[i], allPairs[j]};
            }
        }
    }

    return closestPair;
}

int main() {
      freopen("input3.txt","r",stdin);
     freopen("output3.txt","w",stdout);

        int t;
        cin>>t;
        while(t--){
            int n;
    cin >> n;

    vector<pair<int, int>> allPairs(n);

    for (int i = 0; i < n; ++i) {
        cin >> allPairs[i].first >> allPairs[i].second;
    }

    pair<pair<int, int>, pair<int, int>> closestPair = findClosestPair(allPairs);

    cout  << setprecision(17) << calculateDistance(closestPair.first, closestPair.second) << endl;
   
    cout  << closestPair.first.first << "," << closestPair.first.second  << endl;
    cout << closestPair.second.first << "," << closestPair.second.second  << endl;
    cout<<endl;

        }



    

    return 0;
}
