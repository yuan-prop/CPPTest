#include <iostream>
#include <string>


using namespace std;

template<typename T>
class Animal
{
    typedef int int32;
public:
    Animal() = default;

    Animal(const Animal& Other)
    {
        name = new string(*Other.getName());
        age = Other.getAge();
    }
    ~Animal(){}

    const T* getName() const
    {
        return name;
    }
    void setName(T& n)
    {
        name = &n;
    }
    const int32& getAge() const
    {
        return age;
    }
    void print();

private:
    T* name;
    int32 age = 32;
};
template<typename T>
void Animal<T>::print()
{
    cout << "A print:" << *this->getName() << ", age:" << this->getAge() << endl;
}

int main()
{
    Animal<string> a;
    string name = "Tom";
    a.setName(name);
    a.print();
    Animal<string> b=a;
    string anme2 = "Sjs";
    b.setName(anme2);
    b.print();

    // cout << *a.getName() << ",b age:" << endl;
    // string s = "sdf";
    // string s2 = "abcdE";
    // string* a = &s2;
    // // *a = s;
    // cout << *a << endl;

}

