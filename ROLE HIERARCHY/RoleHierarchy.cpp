#include "RoleHierarchy.h"

#include <iostream>

using namespace std;

RoleHierarchy::RoleHierarchy(const bool root)
{
    if(root)
    {
        addRootRole();
    }
}

void RoleHierarchy::addRootRole()
{
    mIsRootRole = true;
    cout << "Enter root role name : ";
    cin >> mRoleName;
}

void RoleHierarchy::addSubRole()
{
    cout << "Enter sub role name : ";

    RoleHierarchy sub_role_obj;

    cin >> sub_role_obj.mRoleName;

    cout << "Enter reporting to role name : ";

    cin >> sub_role_obj.mReportingToRoleName;

    findRoleObject(mSubRole, sub_role_obj.mReportingToRoleName).mSubRole.push_back(sub_role_obj);
}

void RoleHierarchy::dispRoles() const
{
    cout << mRoleName << ", ";

    dispRoles(mSubRole);
}

void RoleHierarchy::dispRoles(const std::vector<RoleHierarchy>& sub_role) const
{
    for(const auto& role : sub_role)
    {
        cout << role.mRoleName << ", ";
    }

    for(const auto& role : sub_role)
    {
        dispRoles(role.mSubRole);
    }
}

RoleHierarchy& RoleHierarchy::findRoleObject(std::vector<RoleHierarchy>& sub_role, const std::string& reporting_to_role_name)
{
    RoleHierarchy* match = this;

    if(mRoleName != reporting_to_role_name)
    {
        for(auto& role: sub_role)
        {
            if(role.mRoleName == reporting_to_role_name)
            {
                match = &role;
            }
            else
            {
                findRoleObject(role.mSubRole, reporting_to_role_name);
            }
        }
    }

    return *match;
}
