#pragma once

#include <locale>
#include <string>

using namespace std; 

class Rocket {
    private:
    wstring m_name{};
    wstring m_type{};
    double m_payloadCapacity{};
    wstring m_purpose{};
    
    public:
    // Rocket(wstring, wstring, int);
    void NewInfo();
    void PrintInfo();
    wstring getName();
    wstring getType();
    double getPayloadCapacity();
    wstring getPurpose();
    void setName();
    void setType();
    void setPayloadCapacity();
    void setPurpose();
    void PrintItem();       
};

