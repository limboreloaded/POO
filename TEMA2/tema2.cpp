#include <iostream>
#include <cstring>

using namespace std;

class MyString
{
public:
    MyString(char *_str, int len)
    {

        this->str = new char[len];
        strcpy(this->str, _str);

        this->len = len;
    }

    MyString(const MyString &s)
    {
        this->len = s.len;
        this->str = new char[s.len];
        strcpy(this->str, s.str);
    }

    MyString operator=(const MyString &s) {
        this->len = s.len;
        this->str = new char[s.len];
        strcpy(this->str, s.str);

    }

    ~MyString()
    {
        delete[] this->str;
    }

    int getLength()
    {
        return this->len;
    }

    char *getString()
    {
        return this->str;
    }

    void showString()
    {
        for (int i = 0; i < len; i++)
        {
            cout << this->str[i];
        }
        cout << endl;
    }

    void setString(char *_str, int len)
    {
        this->len = len;
        delete[] this->str;

        this->str = new char[len];
        strcpy(this->str, _str);
    }



private:
    char *str;
    int len;
};

int main()
{
    MyString my_string = MyString("Abraham", 7);

    my_string.showString();

    MyString my_string2 = MyString(my_string);

    my_string2.showString();

    MyString my_string3 = my_string;

    my_string3.showString();

    return 0;
}