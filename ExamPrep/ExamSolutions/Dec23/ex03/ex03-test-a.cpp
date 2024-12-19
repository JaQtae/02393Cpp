#include <iostream>
#include "ex03-library.h"
using namespace std;

int main() {
    ParkingArea area = ParkingArea();

    cout << "Initial parking space occupancy:" << endl;
    area.display();

    // This should always succeed
    area.park("LYNGBY04", "RT456DS", "Eric", CAR);
    cout << endl << "After trying to park Eric's car inside parking space LYNGBY04:" << endl;
    area.display();

    area.park("LYNGBY01", "KL394PO", "Fie", MOTORBIKE);
    cout << endl << "After trying to park Fie's motorbike inside parking space LYNGBY01:" << endl;
    area.display();

    area.park("LYNGBY03", "BN254DD", "Gerard", CAR);
    cout << endl << "After trying to park Gerard's car inside parking space LYNGBY03:" << endl;
    area.display();

    area.park("LYNGBY04", "IU093NN", "Henriette", CAR);
    cout << endl << "After trying to park Henriette's car inside parking space LYNGBY04:" << endl;
    area.display();

    area.park("LYNGBY06", "GY183WE", "Irina", MOTORBIKE);
    cout << endl << "After trying to park Irina's motorbike inside parking space LYNGBY06:" << endl;
    area.display();


    return 0;
}
