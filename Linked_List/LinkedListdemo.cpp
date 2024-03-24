#include "LinkedList.cpp"

int main() {
    LinkedList<int> list;
    int choice;
    int value, pos;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at a specified Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from a specified Position\n";
        cout << "7. Display\n";
        cout << "8. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                list.insert_at_beg(value);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                list.insert_at_end(value);
                break;
            case 3:
                cout << "Enter position to insert: ";
                cin >> pos;
                cout << "Enter value to insert: ";
                cin >> value;
                list.insert_at_position(pos, value);
                break;
            case 4:
                list.delete_from_beg();
                break;
            case 5:
                list.delete_from_end();
                break;
            case 6:
                cout << "Enter position to delete: ";
                cin >> pos;
                list.delete_from_position(pos);
                break;
            case 7:
                list.display();
                break;
            case 8:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice. Please enter again." << endl;
        }
    } while (choice != 8);

    return 0;
}
