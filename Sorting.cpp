#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>

using namespace std;

struct Contact {
    string name;
    string mobile;
    string home;
};

void displayContacts(const vector<Contact>& contacts) {
    cout << "\nСписок користувачів:" << endl;
    for (const auto& contact : contacts) {
        cout << "Ім'я: " << contact.name << ", Мобільний: " << contact.mobile << ", Домашній: " << contact.home << endl;
    }
}

void sortByMobile(vector<Contact>& contacts) {
    sort(contacts.begin(), contacts.end(), [](const Contact& a, const Contact& b) {
        return a.mobile < b.mobile;
    });
    cout << "\nВідсортовано за номерами мобільних телефонів." << endl;
}

void sortByHome(vector<Contact>& contacts) {
    sort(contacts.begin(), contacts.end(), [](const Contact& a, const Contact& b) {
        return a.home < b.home;
    });
    cout << "\nВідсортовано за домашніми номерами телефонів." << endl;
}

 
int main() { 
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251); 
    vector<Contact> contacts = {
        {"Олександр", "0987654321", "0441234567"},
        {"Настя", "0931234567", "0447654321"},
        {"Діма", "0505678901", "0449876543"},
        {"Анна", "0672345678", "0441112233"}
    };

    int choice;
    do {
        cout << "\nМеню:" << endl;
        cout << "1. Відсортувати за номерами мобільних" << endl;
        cout << "2. Відсортувати за домашніми номерами" << endl;
        cout << "3. Вивести список користувачів" << endl;
        cout << "4. Вихід" << endl;
        cout << "Виберіть опцію: ";
        cin >> choice;

        switch (choice) {
        case 1:
            sortByMobile(contacts);
            break;
        case 2:
            sortByHome(contacts);
            break;
        case 3:
            displayContacts(contacts);
            break;
        case 4:
            cout << "\nВихід з програми..." << endl;
            break;
        default:
            cout << "\nНевірний вибір, спробуйте ще раз." << endl;
        }
    } while (choice != 4);

    
    return 0; 
}
