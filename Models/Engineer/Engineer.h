#include "../User/User.h"

using namespace std; 

class Engineer : public User {
    private:
    wstring m_specialisation{};
    
    public:
    void setSpecialisation();
    wstring getSpecialisation();
    void PrintInfo() override; 
};

