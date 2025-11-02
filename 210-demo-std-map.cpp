#include <iostream>
#include <map>
#include <tuple>
#include <vector>
using namespace std;

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagerFRI;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerFRI["Tom"] = make_tuple(2, "mouse", "I HAVE TO RUN");
    villagerFRI["Jerry"] = make_tuple(8, "cat", "COME HERE TOM");
    villagerFRI.insert({"Doopy", make_tuple(6, "fish", "Look at those two")});
    auto it = villagerFRI.end();

    int choice;
    cout << "Menu:" << endl;
    cout<< "1. Increase Friendship" << endl;
    cout<< "2. Decrease Friendship" << endl;
    cout<< "3. Search for Villager" << endl;
    cout<< "4. Exit" << endl;
    cout<< "Enter choice: ";
    cin >> choice;

    switch (choice){
        case 1: 
            cout << "Enter villager name to increase friendship: ";
            string name;
            cin >> name;
            it = villagers.find(name);
            if (it != villagers.end()) {
                get<0>(it->second) += 1;
                cout << name << "'s friendship increased to " << get<0>(it->second) << endl;
            } 
            else {
                cout << name << " not found.\n";
            }
            cout << "Villagers and their informations:" << endl;
            for (auto pair : villagerFRI) {
            cout << pair.first << ": [" << get<0>(pair.second) << ", " << get<1>(pair.second)<< ", " << get<2>(pair.second)<< "]" << endl;
            }
    }
    // access the map using a range-based for loop
    cout << "Villagers and their informations:" << endl;
    for (auto pair : villagerFRI) {
        cout << pair.first << ": [" << get<0>(pair.second) << ", " << get<1>(pair.second)<< ", " << get<2>(pair.second)<< "]" << endl;
    }
 
    // access the map using iterators
    cout << "\nVillagers and their information (iterators):" << endl;
    for (map<string, tuple<int, string, string>>::iterator it = villagerFRI.begin(); 
                                               it != villagerFRI.end(); ++it) {
        cout << it->first << ": ["<< get<0>(it->second) << ", " << get<1>(it->second) << ", " << get<2>(it->second) << "]" << endl;
    }

    // delete an element
    villagerFRI.erase("Jerry");

    // search for an element using .find() to avoid errors
    string searchKey = "Doopy";
    auto it = villagerFRI.find(searchKey);
    if (it != villagerFRI.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << ": [" << get<0>(it->second) << ", " << get<1>(it->second) << ", "<< get<2>(it->second) << "]" << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerFRI.size() << endl;
    villagerFRI.clear();
    cout << "Size after clear: " << villagerFRI.size() << endl;

    return 0;
}
