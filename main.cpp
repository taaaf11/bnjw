#include "show.h"
#include <conio.h>
#include <iostream>
using namespace std;


int main() {
    int choice;
    while (true) {
        system("cls");

        cout << "1. Show P1 - 1" << endl;
        cout << "2. Show P1 - 2" << endl;
        cout << "3. Show P1 - 3" << endl;
        cout << "4. Show P1 - 4" << endl;
        cout << "5. Show P1 - 5" << endl;
        cout << "6. Show P1 - 6" << endl;
        cout << "7. Show P1 - 7" << endl;
        cout << "8. Show P1 - 8" << endl;
        cout << "9. Show P1 - 9" << endl;
        cout << "10. Show P1 - 10" << endl;
        cout << "11. Show P2 - 11" << endl;
        cout << "12. Show P2 - 12" << endl;
        cout << "13. Show P2 - 13" << endl;
        cout << "14. Show P2 - 14" << endl;
        cout << "15. Show P2 - 15" << endl;
        cout << "16. Show P3 - 16" << endl;
        cout << "17. Show P3 - 17" << endl;
        cout << "18. Show P3 - 18" << endl;
        cout << "19. Show P3 - 19" << endl;
        cout << "20. Show P3 - 20" << endl;
        cout << "00. Quit" << endl;
        cout << ">>> ";
        cin >> choice;

        switch (choice) {
            case 1:
                showP1();
                break;
            case 2:
                showP2();
                break;
            case 3:
                showP3();
                break;
            case 4:
                showP4();
                break;
            case 5:
                showP5();
                break;
            case 6:
                showP6();
                break;
            case 7:
                showP7();
                break;
            case 8:
                showP8();
                break;
            case 9:
                showP9();
                break;
            case 10:
                showP10();
                break;
            case 11:
                showP11();
                break;
            case 12:
                showP12();
                break;
            case 13:
                showP13();
                break;
            case 14:
                showP14();
                break;
            case 15:
                showP15();
                break;
            case 16:
                showP16();
                break;
            case 17:
                showP17();
                break;
            case 18:
                showP18();
                break;
            case 19:
                showP19();
                break;
            case 20:
                showP20();
                break;
            case 0:
                return 0;
            default:
                cout << "Not implemented." << endl;
        }

        cout << endl << endl << "Press any key to continue...";
        getch();
    }
    return 0;
}