#ifndef ASTRONAUT_H
#define ASTRONAUT_H

#include "../User/User.h"
#include <iostream>

class Astronaut : public User {
private:
    wstring m_mission;

public:
    Astronaut(const wstring& surname = L"", const wstring& name = L"", 
             int age = 0, const wstring& mission = L"");
    
    void setMission();
    wstring getMission() const;
    void PrintInfo() override;
    
    bool operator<(const User& other) const override;
    bool operator>(const User& other) const override;
    wostream& print(wostream& os) const override;
    wistream& read(wistream& is) override;

    friend wostream& operator<<(wostream& aout, const Astronaut& astronaut);
    friend wistream& operator>>(wistream& ain, Astronaut& astronaut);
};

#endif