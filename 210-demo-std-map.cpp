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
    villagerFRI["Audie"] = make_tuple(2, "mouse", "Tom");
    villagerFRI["Raymond"] = make_tuple(8, "Gray", "White");
    villagerFRI.insert({"Marshal", {"Blue", "White", "Black"}});

    // access the map using a range-based for loop
    cout << "Villagers and their favorite colors (range-based for loop):" << endl;
    for (auto pair : villagerFRI) {
        cout << pair.first << ": ";
        for (auto color : pair.second)
            cout << color << " ";
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, tuple<int, string, string>> villagerFRI::iterator it = villagerFRI.begin(); 
                                               it != villagerFRI.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->second) {
            cout << color << " ";
        }
        cout << endl;
    }

    // delete an element
    villagerFRI.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerFRI.find(searchKey);
    if (it != villagerFRI.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerFRI.size() << endl;
    villagerFRI.clear();
    cout << "Size after clear: " << villagerFRI.size() << endl;

    return 0;
}
