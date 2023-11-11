#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

double distance(pair<double, double> p1, pair<double, double> p2) {
    double dx = p1.first - p2.first;
    double dy = p1.second - p2.second;
    return sqrt(dx * dx + dy * dy);
}

bool compareX(pair<double, double> p1, pair<double, double> p2) {
    return p1.first < p2.first;
}

double closestPair(vector<pair<double, double>>& points, int left, int right) {
    if (right - left <= 3) {
        double minDist = DBL_MAX;
        for (int i = left; i < right; i++) {
            for (int j = i + 1; j < right; j++) {
                minDist = min(minDist, distance(points[i], points[j]));
            }
        }
        return minDist;
    }

    int mid = (left + right) / 2;
    double leftMinDist = closestPair(points, left, mid);
    double rightMinDist = closestPair(points, mid, right);
    double minDist = min(leftMinDist, rightMinDist);

    vector<pair<double, double>> strip;
    for (int i = left; i < right; i++) {
        if (fabs(points[i].first - points[mid].first) < minDist) {
            strip.push_back(points[i]);
        }
    }

    sort(strip.begin(), strip.end(), [](pair<double, double> p1, pair<double, double> p2) {
        return p1.second < p2.second;
    });

    for (size_t i = 0; i < strip.size(); i++) {
        for (size_t j = i + 1; j < strip.size() && (strip[j].second - strip[i].second) < minDist; j++) {
            minDist = min(minDist, distance(strip[i], strip[j]));
        }
    }

    return minDist;
}

double findClosestPair(vector<pair<double, double>>& points) {
    sort(points.begin(), points.end(), compareX);
    return closestPair(points, 0, points.size());
}

int main() {
    int n;
    cin >> n;

    vector<pair<double, double>> points;
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        points.push_back(make_pair(x, y));
    }

    double closestDistance = findClosestPair(points);
    cout << "Closest pair distance: " << closestDistance << endl;
    return 0;
}
