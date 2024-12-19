#include <iostream>
#include <vector>
#include <cmath>
#include "shapes.h"

using namespace std;

int main(void){

    vector<Shape *> shapes;

    Rectangle u(2,5);
    shapes.push_back(&u);
    Square v(3);
    shapes.push_back(&v);
    Circle w(2);
    shapes.push_back(&w);
 // Enumerating all areas
    cout << "Areas..." << endl;
    double area = 0;
    for(int i=0; i<shapes.size(); i++){
        cout << round(shapes[i]->area()) << " ";
        area += shapes[i]->area();
    }
    cout << endl << "Total area is " << round(area) << endl;

    // Enumerating all areas
    cout << "Perimeters..." << endl;
    double perimeter = 0;
    for(int i=0; i<shapes.size(); i++){
        cout << round(shapes[i]->perimeter()) << " ";
        perimeter += shapes[i]->perimeter();
    }
    cout << endl << "Total area is " << round(perimeter) << endl;

    // I want to put them side-by-side
    // And see how much space they use (width and height)
    cout << "Placing side-by-side..." << endl;
    double width = 0;
    double height = 0;
    for(int i=0; i<shapes.size(); i++){
        width += shapes[i]->width();
        if(height < shapes[i]->height()){
            height = shapes[i]->height();
        }
    }
    cout << "Total width is " << round(width) << endl;
    cout << "Total height is " << round(height) << endl;

    // I now try to do the same, but minimizing width
    // First, I rotate those shapes that need it
    for(int i=0; i<shapes.size(); i++){
        if(shapes[i]->width() > shapes[i]->height()) {
            shapes[i]->rotate();
        }
    }
    // Then I proceed as before
    // Then I proceed as before
    cout << "Placing side-by-side..." << endl;
    width = 0;
    height = 0;
    for(int i=0; i<shapes.size(); i++){
        width += shapes[i]->width();
        if(height < shapes[i]->height()){
            height = shapes[i]->height();
        }
    }


    cout << "Total width is " << round(width) << endl;
    cout << "Total height is " << round(height) << endl;

    return 0;

}
