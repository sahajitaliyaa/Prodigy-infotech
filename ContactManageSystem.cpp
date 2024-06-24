#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Contact {
    string name;
    string phone;
    string email;
};

vector<Contact> contacts;

void addContact() {
    Contact newContact;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, newContact.name);
    cout << "Enter phone number: ";
    getline(cin, newContact.phone);
    cout << "Enter email address: ";
    getline(cin, newContact.email);
    contacts.push_back(newContact);
    cout << "Contact added successfully!" << endl;
}

void viewContacts() {
    if (contacts.empty()) {
        cout << "No contacts available." << endl;
    } else {
        for (size_t i = 0; i < contacts.size(); ++i) {
            cout << "Contact " << i + 1 << ":" << endl;
            cout << "Name: " << contacts[i].name << endl;
            cout << "Phone: " << contacts[i].phone << endl;
            cout << "Email: " << contacts[i].email << endl;
            cout << "-----------------------" << endl;
        }
    }
}

void editContact() {
    int index;
    cout << "Enter the contact number to edit: ";
    cin >> index;
    cin.ignore();  // Consume the newline character left in the buffer

    if (index < 1 || index > contacts.size()) {
        cout << "Invalid contact number." << endl;
    } else {
        Contact &contact = contacts[index - 1];
        cout << "Editing contact " << index << ":" << endl;
        cout << "Enter new name (leave blank to keep current): ";
        string newName;
        getline(cin, newName);
        if (!newName.empty()) {
            contact.name = newName;
        }
        cout << "Enter new phone number (leave blank to keep current): ";
        string newPhone;
        getline(cin, newPhone);
        if (!newPhone.empty()) {
            contact.phone = newPhone;
        }
        cout << "Enter new email address (leave blank to keep current): ";
        string newEmail;
        getline(cin, newEmail);
        if (!newEmail.empty()) {
            contact.email = newEmail;
        }
        cout << "Contact updated successfully!" << endl;
    }
}

void deleteContact() {
    int index;
    cout << "Enter the contact number to delete: ";
    cin >> index;
    cin.ignore();  // Consume the newline character left in the buffer

    if (index < 1 || index > contacts.size()) {
        cout << "Invalid contact number." << endl;
    } else {
        contacts.erase(contacts.begin() + index - 1);
        cout << "Contact deleted successfully!" << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "Contact Management System" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. View Contacts" << endl;
        cout << "3. Edit Contact" << endl;
        cout << "4. Delete Contact" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Consume the newline character left in the buffer

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                editContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        cout << endl;
    } while (choice != 5);

    return 0;
}
