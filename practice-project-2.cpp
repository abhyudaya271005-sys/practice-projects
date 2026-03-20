#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <thread>
#include <chrono>
#include <limits>
using namespace std;

void basicTimer();
void simpleCalculator();
void miniHabitTracker();
void dailyQuoteGenerator();

int main() {
    int choose;

    do {
        cout << "\n\n========== MULTI UTILITY APP ==========\n";
        cout << "Choose the program you would like to use:\n";
        cout << " 1) Basic Timer\n";
        cout << " 2) Simple Calculator\n";
        cout << " 3) Mini Habit Tracker\n";
        cout << " 4) Daily Quote Generator\n";
        cout << " 5) EXIT\n";
        cout << "Enter your choice: ";
        cin >> choose;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 5.\n";
            continue;
        }

        switch (choose) {
            case 1: basicTimer(); break;
            case 2: simpleCalculator(); break;
            case 3: miniHabitTracker(); break;
            case 4: dailyQuoteGenerator(); break;
            case 5: cout << "\nExiting interface...\n"; break;
            default: cout << "Invalid choice, try again.\n";
        }

    } while (choose != 5);

    return 0;
}
void simpleCalculator() {
    double a, b;
    char op;

    cout << "\n=== Simple Calculator ===\n";
    cout << "Enter the first number: ";
    cin >> a;

    cout << "Choose an operation (+, -, *, /, %, s for sqrt): ";
    cin >> op;

    if (op == 's' || op == 'S') {
        if (a < 0) {
            cout << "Cannot take square root of a negative number.\n";
        } else {
            cout << "The square root of " << a << " is " << sqrt(a) << "\n";
        }
        return;
    }

    cout << "Enter the second number: ";
    cin >> b;

    switch (op) {
        case '+':
            cout << "The answer is: " << a + b << "\n";
            break;
        case '-':
            cout << "The answer is: " << a - b << "\n";
            break;
        case '*':
            cout << "The answer is: " << a * b << "\n";
            break;
        case '/':
            if (b != 0)
                cout << "The answer is: " << a / b << "\n";
            else
                cout << "Division by zero is not allowed.\n";
            break;
        case '%':
            if (static_cast<int>(b) != 0)
                cout << "The answer is: " << static_cast<int>(a) % static_cast<int>(b) << "\n";
            else
                cout << "Modulus by zero is not allowed.\n";
            break;
        default:
            cout << "Invalid operator.\n";
    }
}
void basicTimer() {
    int seconds;

    cout << "\n=== Basic Timer ===\n";
    cout << "Enter countdown in seconds: ";
    cin >> seconds;

    if (cin.fail() || seconds <= 0) {
        cout << "Invalid input. Timer must be a positive number.\n";
        return;
    }

    cout << "Starting Timer in 3... 2... 1...\n";

    for (int i = seconds; i > 0; --i) {
        cout << "\rTime left: " << i << " seconds" << flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    cout << "\nTIME'S UP !!!\n";
}
void miniHabitTracker() {
    vector<string> habits = { "Drink Water", "Eat Food", "Study", "Exercise" };
    vector<string> status;
    string input;

    ofstream file("habits.txt", ios::app);
    if (!file) {
        cout << "Error opening file for writing.\n";
        return;
    }

    time_t now = time(0);
    tm* ltm = localtime(&now);
    file << "Date: " << 1900 + ltm->tm_year << "/"
         << 1 + ltm->tm_mon << "/"
         << ltm->tm_mday << endl;

    cout << "\n=== Mini Habit Tracker ===\n";
    for (string habit : habits) {
        cout << "Did you complete \"" << habit << "\" today? (y/n): ";
        cin >> input;
        status.push_back((input == "y" || input == "Y") ? "Yes" : "No");
    }

    for (int i = 0; i < habits.size(); ++i) {
        file << habits[i] << ": " << status[i] << endl;
    }

    file << "-------------------------\n";
    file.close();

    cout << "Progress saved to 'habits.txt'!\n";
}
void dailyQuoteGenerator() {
    vector<string> quotes = {
        "You can become knowledgable from others knwoledge but you can't become wise from others wisdom.",
        "I'm selfish, impatient and a little insecure...",
        "So many books, so little time.",
        "Two things are infinite: the universe and human stupidity...",
        "A room without books is like a body without a soul.",
        "Be the change that you wish to see in the world.",
        "You only live once, but if you do it right, once is enough.",
        "In three words I can sum up everything I've learned about life: it goes on.",
        "If you tell the truth, you don't have to remember anything.",
        "A friend is someone who knows all about you and still loves you.",
        "To live is the rarest thing in the world. Most people exist, that is all."
    };

    srand(time(0));
    int index = rand() % quotes.size();

    cout << "\n Quote of the Day:\n\n\"" << quotes[index] << "\"\n" << endl;
}
