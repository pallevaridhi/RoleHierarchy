#ifndef ROLEHIERARCHY_H
#define ROLEHIERARCHY_H

#include <string>
#include <vector>

class RoleHierarchy
{
public:
    RoleHierarchy(const bool root = false);
    void addSubRole();
    void dispRoles() const;

private:
    bool mIsRootRole = false;
    std::string mRoleName = "";
    std::string mReportingToRoleName = "";
    std::vector<RoleHierarchy> mSubRole;

    void addRootRole();
    RoleHierarchy& findRoleObject(std::vector<RoleHierarchy>& sub_role, const std::string& reporting_to_role_name);
    void dispRoles(const std::vector<RoleHierarchy>& sub_role) const;
};

#endif // ROLEHIERARCHY_H
