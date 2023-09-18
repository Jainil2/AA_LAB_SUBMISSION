#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

// Structure to represent a point in 2D space
struct Point
{
    int x, y;
};

// Function to calculate the Euclidean distance between two points
double distance(Point p1, Point p2)
{
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

// Brute-force algorithm to find the closest pair of points
pair<Point, Point> closestPairBruteForce(vector<Point> &points)
{
    int n = points.size();
    if (n < 2)
    {
        // Not enough points to form a pair
        return make_pair(Point{0, 0}, Point{0, 0});
    }

    pair<Point, Point> closestPair;
    double minDistance = INT_MAX;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double dist = distance(points[i], points[j]);
            if (dist < minDistance)
            {
                minDistance = dist;
                closestPair = make_pair(points[i], points[j]);
            }
        }
    }

    return closestPair;
}

int main()
{
    int n;
    cout << "Enter the number of points: ";
    cin >> n;

    vector<Point> points(n);

    cout << "Enter the coordinates of each point:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> points[i].x >> points[i].y;
    }

    pair<Point, Point> closestPair = closestPairBruteForce(points);

    cout << "Closest pair of points: (" << closestPair.first.x << ", " << closestPair.first.y << ") and ("
         << closestPair.second.x << ", " << closestPair.second.y << ")" << endl;

    double minDist = distance(closestPair.first, closestPair.second);
    cout << "Minimum distance: " << minDist << endl;

    return 0;
}
