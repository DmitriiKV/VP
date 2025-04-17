#ifndef ENGINEER_H
#define ENGINEER_H

#include "../User/User.h"
#include <iostream>

class Engineer : public User {
private:
    wstring m_specialisation;

public:
    Engineer(const wstring& surname = L"", const wstring& name = L"", 
            int age = 0, const wstring& specialisation = L"");
    
    void setSpecialisation();
    wstring getSpecialisation() const;
    void PrintInfo() override;
    
    bool operator<(const User& other) const override;
    bool operator>(const User& other) const override;
    wostream& print(wostream& os) const override;
    wistream& read(wistream& is) override;

    friend wostream& operator<<(wostream& eout, const Engineer& engineer);
    friend wistream& operator>>(wistream& ein, Engineer& engineer);
};

#endif