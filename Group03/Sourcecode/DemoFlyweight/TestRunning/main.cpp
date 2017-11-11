#include <boost\flyweight.hpp>
#include <iostream>
#include <string>

// Minh hoa su dung boost.flyweight

using namespace std;
using namespace ::boost;
using namespace ::boost::flyweights;

struct user_entry
{
    flyweight<string> first_name;
    flyweight<string> last_name;
    int age;
    user_entry(const string &f, const string &l, int a);
};

user_entry::user_entry(const string &f, const string &l, int a)
    : first_name(f), last_name(l), age(a)
{
}

bool same_name(const user_entry &user1, const user_entry &user2)
{
    return user1.first_name == user2.first_name &&
           user1.last_name == user2.last_name;
}

ostream &operator<<(ostream &os, const user_entry &user)
{
    return os << user.first_name << " " << user.last_name << " " << user.age;
}

istream &operator>>(istream &is, user_entry &user)
{
    return is >> user.first_name >> user.last_name >> user.age;
}

int main()
{
    user_entry a("hau", "nguyen", 12);
    cout << a << endl;
    user_entry b("thanh", "nguyen", 13);
    cout << b << endl;
    return 0;
}