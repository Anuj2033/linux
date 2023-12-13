#include <iostream>
#include <graphics.h>
using namespace std;

class CohenSutherLandAlgo
{
private:
    double x1, y1, x2, y2;
    double x_max, y_max, x_min, y_min;
    const int INSIDE = 0; // 0000
    const int LEFT = 1;   // 0001
    const int RIGHT = 2;  // 0010
    const int BOTTOM = 4; // 0100
    const int TOP = 8;    // 1000

public:
    CohenSutherLandAlgo()
    {
        x1 = 0.0;
        x2 = 0.0;
        y1 = 0.0;
        y2 = 0.0;
    }
    void getCoordinates();
    void getClippingRectangle();
    int generateCode(double x, double y);
    void cohenSutherland();
    void drawRectangle();
    void drawLine(double x1, double y1, double x2, double y2, int color);
};

void CohenSutherLandAlgo::getCoordinates()
{
    cout << "\nEnter Co-ordinates of P1(X1,Y1) of Line Segment : ";
    cout << "\nEnter X1 Co-ordinate : ";
    cin >> x1;
    cout << "\nEnter Y1 Co-ordinate : ";
    cin >> y1;
    cout << "\nEnter Co-ordinates of P2(X2,Y2) of Line Segment : ";
    cout << "\nEnter X2 Co-ordinate : ";
    cin >> x2;
    cout << "\nEnter Y2 Co-ordinate : ";
    cin >> y2;
}

void CohenSutherLandAlgo::getClippingRectangle()
{
    cout << "\nEnter the Co-ordinates of Interested Rectangle.";
    cout << "\nEnter the X_MAX : ";
    cin >> x_max;
    cout << "\nEnter the Y_MAX : ";
    cin >> y_max;
    cout << "\nEnter the X_MIN : ";
    cin >> x_min;
    cout << "\nEnter the Y_MIN : ";
    cin >> y_min;
}

int CohenSutherLandAlgo::generateCode(double x, double y)
{
    int code = INSIDE; // intially initializing as being inside
    if (x < x_min)     // lies to the left of rectangle
        code |= LEFT;
    else if (x > x_max) // lies to the right of rectangle
        code |= RIGHT;
    if (y < y_min)      // lies below the rectangle
        code |= BOTTOM;
    else if (y > y_max) // lies above the rectangle
        code |= TOP;
    return code;
}

void CohenSutherLandAlgo::drawLine(double x1, double y1, double x2, double y2, int color)
{
    setcolor(color);
    line(x1, y1, x2, y2);
}

void CohenSutherLandAlgo::drawRectangle()
{
    setcolor(RED);
    rectangle(x_min, y_min, x_max, y_max);
}

void CohenSutherLandAlgo::cohenSutherland()
{
    int code1 = generateCode(x1, y1); // Compute region codes for P1.
    int code2 = generateCode(x2, y2); // Compute region codes for P2.
    bool accept = false;               // Initialize line as outside the rectangular window.
    while (true)
    {
        if ((code1 == 0) && (code2 == 0))
        {
            // If both endpoints lie within rectangle.
            accept = true;
            break;
        }
        else if (code1 & code2)
        {
            // If both endpoints are outside rectangle,in the same region.
            break;
        }
        else
        {
            // Some segment of the line lies within the rectangle.
            int code_out;
            double x, y;
            // At least one endpoint lies outside the rectangle, pick it.
            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;
            /*
            * Find intersection point by using formulae :
            y = y1 + slope * (x - x1)
            x = x1 + (1 / slope) * (y - y1)
            */
            if (code_out & TOP)
            {
                // point is above the clip rectangle
                x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                y = y_max;
            }
            else if (code_out & BOTTOM)
            {
                // point is below the rectangle
                x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                y = y_min;
            }
            else if (code_out & RIGHT)
            {
                // point is to the right of rectangle
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                x = x_max;
            }
            else if (code_out & LEFT)
            {
                // point is to the left of rectangle
                y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
                x = x_min;
            }
            // Intersection point x,y is found.
            // Replace point outside rectangle by intersection point.
            if (code_out == code1)
            {
                drawLine(x1, y1, x, y, WHITE);
                x1 = x;
                y1 = y;
                code1 = generateCode(x1, y1);
            }
            else
            {
                drawLine(x2, y2, x, y, WHITE);
                x2 = x;
                y2 = y;
                code2 = generateCode(x2, y2);
            }
        }
    }
    if (accept)
    {
        cout << "Line accepted from "
                  << "(" << x1 << ", " << y1 << ")"
                  << " to "
                  << "(" << x2 << ", " << y2 << ")"
                  << endl;
    }
    else
        cout << "Line rejected" << std::endl;

    // Draw the original line, clipped line, and clipping window
    drawLine(x1, y1, x2, y2, WHITE);    // Original line
    drawLine(x1, y1, x2, y2, RED);      // Clipped line
    drawRectangle();                    // Clipping window
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    CohenSutherLandAlgo c;
    c.getCoordinates();
    c.getClippingRectangle();
    c.cohenSutherland();

    delay(5000);
    closegraph();
    return 0;
}
