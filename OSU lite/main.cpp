#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>

using namespace std;

int main() {
    string message ="Choose the correct option!";
    string player_name, temp_name;
    int score, temp_num;
    string leaderboard_name[4] = {" - ", " - ", " - ", " - "};
    int top_score[4] = {0, 0, 0, 0};
    bool exit = true;
    double game_time;
    while (exit == true) {

        srand(time(NULL));
        int tiles_x = (rand() % 5) + 1;
        string game = "start";
        int tiles_y = 1;
        char key;
        int player_choose;

    cout << "Welcome to OSU Lite" << endl;
    cout << "1. Play" << endl;
    cout << "2. Highscore" << endl;
    cout << "3. Exit" << endl;
    cout << message << endl;
    cout << ">> ";
    cin >> player_choose;

        switch (player_choose) {

            case 1:
            score = 0;
            game_time = 500;
            cout << "Input Player Name: ";
            cin >> player_name;
            system("cls");
            while (game == "start") {
                cout << "   Player Name: " << player_name << endl;
                cout << "      Score: " << score << endl;
                cout << "Time Remaining: " << game_time / 50 << endl;
                for (int i = 0; i < 16; i++) {
                    for (int j = 0; j < 7; j++) {
                        if (i == 0 || j == 0 || j == 6) {
                            cout << " * ";
                        } else if (i == 15) {
                            cout << " _ ";
                        } else if (i == tiles_y && j == tiles_x) {
                            cout << " 0 ";
                        } else {
                            cout << "   ";
                        }
                    }
                    cout << endl;
                }
                cout << "    p  o  i  u  y" << endl;

                if ( kbhit() ) {
                    key = getch();
                    if (key == 'p') {
                        if (tiles_y == 15 && tiles_x == 1) {
                            score++;
                        }
                    } else if (key == 'o') {
                        if (tiles_y == 15 && tiles_x == 2) {
                            score++;
                        }
                    } else if (key == 'i') {
                        if (tiles_y == 15 && tiles_x == 3) {
                            score++;
                        }
                    } else if (key == 'u') {
                        if (tiles_y == 15 && tiles_x == 4) {
                            score++;
                        }
                    } else if (key == 'y') {
                        if (tiles_y == 15 && tiles_x == 5) {
                            score++;
                        }
                    } else if (int(key) == 27) {
                        game = "stop";
                    }
                }

                tiles_y += 1;
                if (tiles_y >= 16) {
                    tiles_y = 0;
                    tiles_x = (rand() % 5) + 1;
                }

                game_time--;

                if (game_time == 0) {
                    game = "stop";
                }

                Sleep(100);
                system("cls");
            }
            message ="Choose the correct option!";
            cout << "Thanks for playing" << endl;
            cout << "Your score is: " << score << endl;
            leaderboard_name[3] = player_name;
            top_score[3] = score;
            system("pause");
            break;

            case 2:
                system("cls");
                message ="Choose the correct option!";
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 4; j++) {
                        if (top_score[j] < top_score[j + 1]) {
                            temp_num = top_score[j];
                            temp_name = leaderboard_name[j];
                            top_score[j] = top_score[j + 1];
                            leaderboard_name[j] = leaderboard_name[j + 1];
                            top_score[j + 1] = temp_num;
                            leaderboard_name[j + 1] = temp_name;
                        }
                    }
                }

                cout << "Highscore: " << endl;
                cout << "1." << leaderboard_name[0] << " : " << top_score[0] << endl;
                cout << "2." << leaderboard_name[1] << " : " << top_score[1] << endl;
                cout << "3." << leaderboard_name[2] << " : " << top_score[2] << endl;
                system("pause");
            break;

            case 3:
                exit = false;
            break;

            default:
                message = "Bodo bisa baca gak ?";
            break;

        }
        system("cls");
    }
    return 0;
}
