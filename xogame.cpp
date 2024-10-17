#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

char t[9] = {'1','2','3','4','5','6','7','8','9'};
int n;

void display_board();
void xo_read();
bool check_winner();
void ia_player();
bool check_draw();

int main() {
    bool b, c;
    printf("TTTTTTT IIIII  CCCCC     TTTTTTT   AAA    CCCCC     TTTTTTT  OOOOO  EEEEEEE    \n");
    printf("  TTT    III  CC    C      TTT    AAAAA  CC    C      TTT   OO   OO EE         \n");
    printf("  TTT    III  CC           TTT   AA   AA CC           TTT   OO   OO EEEEE      \n");
    printf("  TTT    III  CC    C      TTT   AAAAAAA CC    C      TTT   OO   OO EE         \n");
    printf("  TTT   IIIII  CCCCC       TTT   AA   AA  CCCCC       TTT    OOOO0  EEEEEEE    \n");

    cout << "XO_GAME_BY_RORYDEVELLA\n";
    display_board();
    do {
        xo_read();
        ia_player();
        display_board();
        b = check_draw();
        c = check_winner();
    } while(!b && !c);
    if (c) cout << "We have a winner!\n";
    else if (b) cout << "It's a draw!\n";
}

void display_board() {
    cout << " " << t[0] << " | " << t[1] << " | " << t[2] << " " << endl;
    cout << "-----------" << endl;
    cout << " " << t[3] << " | " << t[4] << " | " << t[5] << " " << endl;
    cout << "-----------" << endl;
    cout << " " << t[6] << " | " << t[7] << " | " << t[8] << " " << endl;
}

void xo_read() {
    do {
        cout << "Enter number 1~9: ";
        cin >> n;
    } while (t[n-1] == 'x' || t[n-1] == 'o');
    t[n-1] = 'x';
}

void ia_player() {
    srand(time(NULL));
    int n;
    bool found = false;
    while (!found) {
        n = rand() % 9;
        if (t[n] != 'x' && t[n] != 'o') {
            t[n] = 'o';
            found = true;
        }
    }
}

bool check_winner() {
    for (int i = 0; i < 9; i += 3) {
        if (t[i] == t[i+1] && t[i+1] == t[i+2]) return true;
    }
    for (int i = 0; i < 3; ++i) {
        if (t[i] == t[i+3] && t[i+3] == t[i+6]) return true;
    }
    if (t[0] == t[4] && t[4] == t[8]) return true;
    if (t[2] == t[4] && t[4] == t[6]) return true;
    return false;
}

bool check_draw() {
    for (int i = 0; i < 9; i++) {
        if (t[i] != 'x' && t[i] != 'o') return false;
    }
    return true;
}
