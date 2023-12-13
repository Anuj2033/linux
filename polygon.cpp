#include <graphics.h>
#include <iostream>
#include <vector>
#include<climits>
#include <algorithm>
using namespace std;

// Function to draw a line
void drawLine(int x1, int y1, int x2, int y2) {
    line(x1, y1, x2, y2);
}

// Function to draw the boundary of the polygon
void drawPolygon(const vector<pair<int, int>>& vertices) {
    int n = vertices.size();

    for (int i = 0; i < n; i++) {
        int x1 = vertices[i].first;
        int y1 = vertices[i].second;

        int x2 = vertices[(i + 1) % n].first;
        int y2 = vertices[(i + 1) % n].second;

        drawLine(x1, y1, x2, y2);
    }
}

// Function to implement the scan line polygon filling algorithm
void scanLineFill(const vector<pair<int, int>>& vertices) {
    int n = vertices.size();

    int yMin = INT_MAX;
    int yMax = INT_MIN;

    // Find the minimum and maximum y-coordinates of the polygon
    for (const auto& vertex : vertices) {
        yMin = min(yMin, vertex.second);
        yMax = max(yMax, vertex.second);
    }

    // Loop through scan lines
    for (int y = yMin + 1; y < yMax; y++) {
        vector<int> intersections;

        // Find intersections with each edge
        for (int i = 0; i < n; i++) {
            int x1 = vertices[i].first;
            int y1 = vertices[i].second;

            int x2 = vertices[(i + 1) % n].first;
            int y2 = vertices[(i + 1) % n].second;

            if ((y1 <= y && y2 > y) || (y2 <= y && y1 > y)) {
                // Edge intersects with the scan line
                int x = x1 + (y - y1) * (x2 - x1) / (y2 - y1);
                intersections.push_back(x);
            }
        }

        // Sort intersections and fill the pixels between pairs
        sort(intersections.begin(), intersections.end());

        for (int i = 0; i < intersections.size(); i += 2) {
            int x1 = intersections[i];
            int x2 = intersections[i + 1];

            for (int x = x1; x <= x2; x++) {
                putpixel(x, y, WHITE);
            }
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<pair<int, int>> vertices;
    cout << "Enter the coordinates of vertices:" << endl;

    for (int i = 0; i < n; ++i) {
        int x, y;
        cout << "Vertex " << i + 1 << ": ";
        cin >> x >> y;
        vertices.push_back({x, y});
    }

    drawPolygon(vertices);
    delay(1000);
    cleardevice();

    scanLineFill(vertices);

    delay(5000);
    closegraph();
    return 0;
}
