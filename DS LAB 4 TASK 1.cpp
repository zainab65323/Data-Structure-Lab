#include<iostream>
#include<string>
using namespace std;

// Mobile Class
class Phone {
private:
    string companyName;
    int stockAvailable;
    double unitPrice;

public:
    // Constructor
    Phone(string c = "", int s = 0, double p = 0) {
        companyName = c;
        stockAvailable = s;
        unitPrice = p;
    }

    // Setters
    void setCompany(string c) {
        companyName = c;
    }

    void setStock(int s) {
        stockAvailable = s;
    }

    void setPrice(double p) {
        unitPrice = p;
    }

    // Getters
    string getCompany() {
        return companyName;
    }

    int getStock() {
        return stockAvailable;
    }

    double getPrice() {
        return unitPrice;
    }
};

// Node Class
class ListNode {
public:
    Phone info;
    ListNode* next;

    ListNode(Phone p) {
        info = p;
        next = NULL;
    }
};

// Inventory Linked List
class Inventory {
private:
    ListNode* head;

public:
    Inventory() {
        head = NULL;
    }

    // Add Phone at Beginning
    void addAtBeginning(Phone p) {
        ListNode* newNode = new ListNode(p);
        newNode->next = head;
        head = newNode;
    }

    // Add Phone at End
    void addAtEnd(Phone p) {
        ListNode* newNode = new ListNode(p);

        if(head == NULL) {
            head = newNode;
            return;
        }

        ListNode* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // Delete Phone from Beginning
    void removeFromBeginning() {
        if(head == NULL) {
            cout << "Inventory Empty\n";
            return;
        }

        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete Phone from End
    void removeFromEnd() {
        if(head == NULL) {
            cout << "Inventory Empty\n";
            return;
        }

        if(head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        ListNode* temp = head;
        while(temp->next->next != NULL) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    // Display Inventory
    void showInventory() {
        if(head == NULL) {
            cout << "No Phones Available\n";
            return;
        }

        ListNode* temp = head;
        while(temp != NULL) {
            cout << "Brand: " << temp->info.getCompany() << endl;
            cout << "Stock: " << temp->info.getStock() << endl;
            cout << "Price: " << temp->info.getPrice() << endl;
            cout << "------------------------\n";
            temp = temp->next;
        }
    }
};

// Main Function
int main() {
    Inventory shop;

    Phone p1("Samsung", 12, 90000);
    Phone p2("iPhone", 6, 250000);
    Phone p3("Realme", 20, 55000);
    Phone p4("Infinix", 10, 40000);

    cout << "Adding at Beginning\n";
    shop.addAtBeginning(p1);

    cout << "Adding at End\n";
    shop.addAtEnd(p2);

    cout << "Adding Another at End\n";
    shop.addAtEnd(p3);

    cout << "\nCurrent Inventory:\n";
    shop.showInventory();

    cout << "\nRemoving from Beginning\n";
    shop.removeFromBeginning();

    cout << "Removing from End\n";
    shop.removeFromEnd();

    cout << "Adding New Phone at End\n";
    shop.addAtEnd(p4);

    cout << "\nFinal Inventory:\n";
    shop.showInventory();

    return 0;
}
