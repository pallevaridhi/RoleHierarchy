#include <iostream>

#include "RoleHierarchy.h"

using namespace std;

int main()
{
    RoleHierarchy role_hierarchy_obj(true);

    int option = 0;

    do
    {
        cout << "Operations :" << endl;
        cout << "\t" << "1. Add Sub Role." << endl;
        cout << "\t" << "2. Display Roles." << endl;

        cin >> option;

        switch (option)
        {
            case 1: role_hierarchy_obj.addSubRole();
            break;
            case 2: role_hierarchy_obj.dispRoles();
            break;
        }
    }
    while ((option > 0) && (option < 3));

    return 0;
}
