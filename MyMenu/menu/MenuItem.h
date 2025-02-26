#pragma once

#include <cstddef>
#include <string>

using namespace std;

class MyMenu {
    private:
        string m_title{};
        int m_item_count{};

    public:
        
        int last_item{};
        MyMenu *items{};

        void printMenu();
        void inputText();
        void print();

        MyMenu(const char* title, const int item_count) {
            m_title = new char[256] {};
            m_item_count = item_count;
        }

        ~MyMenu() {
            delete[] m_title;
        }


}