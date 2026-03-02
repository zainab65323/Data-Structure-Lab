#include <iostream>
using namespace std;

// Profile Class
class UserProfile
{
public:
    int userID;
    string userName;
    string gender;
    int age;
    string email;
    string hobby;
    string dob;

    UserProfile() {}

    UserProfile(int id, string name, string g, int a,
                string e, string h, string d)
    {
        userID = id;
        userName = name;
        gender = g;
        age = a;
        email = e;
        hobby = h;
        dob = d;
    }

    void showProfile()
    {
        cout << "\nID: " << userID;
        cout << "\nName: " << userName;
        cout << "\nGender: " << gender;
        cout << "\nAge: " << age;
        cout << "\nEmail: " << email;
        cout << "\nHobby: " << hobby;
        cout << "\nDOB: " << dob;
        cout << "\n---------------------------\n";
    }
};

// Node Class
class Node
{
public:
    UserProfile data;
    Node* next;

    Node(UserProfile p)
    {
        data = p;
        next = NULL;
    }
};

// Portal System Class
class SocialPortal
{
private:
    Node* head;

public:
    SocialPortal()
    {
        head = NULL;
    }

    // Create Profile
    void createProfile(UserProfile p)
    {
        Node* newNode = new Node(p);

        if(head == NULL)
        {
            head = newNode;
            return;
        }

        Node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    // Display Profiles
    void displayProfiles()
    {
        if(head == NULL)
        {
            cout << "No Profiles Found\n";
            return;
        }

        Node* temp = head;

        while(temp != NULL)
        {
            temp->data.showProfile();
            temp = temp->next;
        }
    }

    // Search Profile by Name
    void searchByName(string name)
    {
        Node* temp = head;

        while(temp != NULL)
        {
            if(temp->data.userName == name)
            {
                cout << "\nProfile Found\n";
                temp->data.showProfile();
                return;
            }
            temp = temp->next;
        }

        cout << "Profile Not Found\n";
    }

    // Update Profile by ID
    void updateProfile(int id)
    {
        Node* temp = head;

        while(temp != NULL)
        {
            if(temp->data.userID == id)
            {
                cout << "Enter New Name: ";
                cin >> temp->data.userName;

                cout << "Enter Gender: ";
                cin >> temp->data.gender;

                cout << "Enter Age: ";
                cin >> temp->data.age;

                cout << "Enter Email: ";
                cin >> temp->data.email;

                cout << "Enter Hobby: ";
                cin >> temp->data.hobby;

                cout << "Enter DOB: ";
                cin >> temp->data.dob;

                cout << "Profile Updated Successfully\n";
                return;
            }

            temp = temp->next;
        }

        cout << "Profile Not Found\n";
    }

    // Delete Profile by Name
    void deleteProfile(string name)
    {
        if(head == NULL)
        {
            cout << "List Empty\n";
            return;
        }

        if(head->data.userName == name)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Profile Deleted\n";
            return;
        }

        Node* temp = head;

        while(temp->next != NULL &&
              temp->next->data.userName != name)
        {
            temp = temp->next;
        }

        if(temp->next == NULL)
        {
            cout << "Profile Not Found\n";
            return;
        }

        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;

        cout << "Profile Deleted Successfully\n";
    }
};

// Main Function
int main()
{
    SocialPortal portal;

    int choice;

    do
    {
        cout << "\n===== SOCIAL MEDIA PORTAL =====\n";
        cout << "1. Create Profile\n";
        cout << "2. Update Profile\n";
        cout << "3. Delete Profile\n";
        cout << "4. Search Profile\n";
        cout << "5. Display All Profiles\n";
        cout << "6. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        if(choice == 1)
        {
            int id, age;
            string name, gender, email, hobby, dob;

            cout << "Enter ID: ";
            cin >> id;

            cout << "Enter Name: ";
            cin >> name;

            cout << "Enter Gender: ";
            cin >> gender;

            cout << "Enter Age: ";
            cin >> age;

            cout << "Enter Email: ";
            cin >> email;

            cout << "Enter Hobby: ";
            cin >> hobby;

            cout << "Enter DOB: ";
            cin >> dob;

            UserProfile p(id, name, gender, age, email, hobby, dob);
            portal.createProfile(p);
        }

        else if(choice == 2)
        {
            int id;
            cout << "Enter ID to Update: ";
            cin >> id;
            portal.updateProfile(id);
        }

        else if(choice == 3)
        {
            string name;
            cout << "Enter Name to Delete: ";
            cin >> name;
            portal.deleteProfile(name);
        }

        else if(choice == 4)
        {
            string name;
            cout << "Enter Name to Search: ";
            cin >> name;
            portal.searchByName(name);
        }

        else if(choice == 5)
        {
            portal.displayProfiles();
        }

    } while(choice != 6);

    cout << "Program Ended\n";

    return 0;
}
