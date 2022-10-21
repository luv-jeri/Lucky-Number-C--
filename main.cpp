#include <iostream>
#include <time.h>

using namespace std;

int lucky_number = time(0) % 10 + 1;
int score = 5;

bool play_again()
{

    char answer;
    cout << "__________________________________" << endl;
    cout << "Do you want to play again? (y/n):  " << endl;
    cin >> answer;

    switch (answer)
    {
    case 'y':
    {
        cout << "__________________________________" << endl;
        cout << "Great! Let's play again!" << endl;
        cout << "__________________________________" << endl;
        return true;
    }
    case 'n':
    {
        cout << "__________________________________" << endl;
        cout << "Thanks for playing! Press any key to close." << endl;
        cout << "__________________________________" << endl;
        cin.get();
        return false;
    }
    default:
    {
        cout << "__________________________________" << endl;
        cout << "Invalid input! Please try again." << endl;
        cout << "__________________________________" << endl;
        play_again();
    }
    }
}

bool guessing()
{
    int guess;
    cout << "Guess the lucky number -> ";
    cin >> guess;

    if (guess > 10 || guess < 1)
    {
        cout << "** INVALID - Please enter a number between 1 - 10 only :/" << endl;
        guessing();
    }
    else
    {
        cout << "SO! YOUR GUESS IS -> " << guess << endl;
        cout << endl;

        if (guess == lucky_number)
        {
            cout << "****************************************" << endl;
            cout << "YOU ARE LUCKY! YOU GUESSED IT RIGHT! :D" << endl;
            cout << "****************************************" << endl;
            cout << endl;
            cout << "YOUR SCORE ON LUCKY S  ALE IS -> " << score << endl;
            cout << "****************************************" << endl;
            cout << endl;

            bool answer = play_again();
            return answer;
        }
        else
        {
            cout << "YOU ARE UNLUCKY! YOU GUESSED IT WRONG! :(" << endl;
            cout << "TRY AGAIN YOU UNLUCKY PERSON! :/" << endl;
            cout << endl;
            score = score - 1;
            cout << "Chances left -> " << score << endl;

            if (score <= 0)
            {
                cout << "........................" << endl;
                cout << "!!!   YOU LOST IT    !!!" << endl;
                cout << "........................" << endl;

                bool answer = play_again();
                return answer;
            }
            else
            {
                guessing();
            }
        }
    }
}

int main()
{
    cout << lucky_number << endl;
    cout << "---------------------" << endl;
    cout << "** WELCOME TO GAME **" << endl;
    cout << "---------------------" << endl;
    cout << endl;
    cout << "You have 5 chances to guess the lucky number!" << endl;
    cout << "Number will be between 1 and 10*" << endl;
    cout << " **** Good luck!  ****" << endl;
    cout << endl;
    cout << "______________________________________________________" << endl;

    bool user_choise = guessing();

    if (user_choise)
    {
        main();
    }
    else
    {
        cin.get();
        return 0;
    }
}