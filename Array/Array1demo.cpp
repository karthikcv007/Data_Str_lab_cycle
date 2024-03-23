#include "Array1.cpp"
int main() {
    Array1<int> arr;

    char choice;
    int a, pos;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insertion at Beginning\n";
        cout << "2. Insertion at End\n";
        cout << "3. Insertion at a specified positiion\n";
        cout << "4. Deletion from Beginning\n";
        cout << "5. Deletion from End\n";
        cout << "6. Deletion from a specified position\n";
        cout << "7. Find the index of a given element\n";
        cout << "8. Display\n";
        cout << "9. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "Enter element to insert at beginning: ";
                cin >> a;
                arr.insert_at_beg(a);
                break;
            case '2':
                cout << "Enter element to insert at end: ";
                cin >> a;
                arr.insert_at_end(a);
                break;
            case '3':
                cout << "Enter position to insert element: ";
                cin >> pos;
                cout << "Enter element to insert: ";
                cin >> a;
                arr.insert_at_position(pos, a);
                break;
            case '4':
                arr.delete_from_beg();
                break;
            case '5':
                arr.delete_from_end();
                break;
            case '6':
                cout << "Enter position to delete element: ";
                cin >> pos;
                arr.delete_from_position(pos);
                break;
            case '7':
                cout << "Enter element to find index: ";
                cin >> a;
                cout << "Index of element: " << arr.find_index(a) << endl;
                break;
            case '8':
                arr.display();
                break;
            case '9':
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice. Please enter again." << endl;
        }
    } while (choice != '9');

    return 0;
}