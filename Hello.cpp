#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Teacher;
class Student;


class Teacher {

public:
    Teacher() : age(16) {cout << "Teacher 创建！"<< this << endl;}

    Teacher(Teacher& Other) : age(Other.age)
    {
        cout << "Teacher拷贝构造函数" << this->age <<endl;
    }

    Teacher& operator=(const Teacher& Other){
        cout << "Teacher拷贝赋值运算符"<< endl;
        return *this;
    }

    // void SetAge(int a){
    //     age = a;
    // }

    const int* getAge() const {return &age;}

private:
    const int age;
};

class Student{

public:
    // Student()=delete;/

    // Student(Student&){};

    ~Student(){};
    const Teacher* getTea(){
        return &t;
    }

private:

     Teacher t;

};

void dd(){
    // char i;
    // cout<< "i的值:" << i << "结束"<<endl;
    const int constant = 26;
    const int* const_p = &constant;
    int* modifier = const_cast<int*>(const_p);
    *modifier = 3;
    cout<< "constant:  "<<constant<<"  adderss:  "<< &constant <<endl;
    cout<<"*modifier:  "<<*modifier<<"  adderss:  " << modifier<<endl;

    system("pause");
}

int main()
{
    vector<string> msg = {"hello","c++","world"};

    for(string& s : msg){
        cout << s << " ";
    }
    cout << endl;
    // Student s;
    // Teacher* t = const_cast<Teacher*>(s.getTea());
    // cout << "TMD:" << t->getAge() << endl;
    // t->SetAge(32);
    // cout << "TMD1:" << t->getAge() << endl;
    // dd();
    Teacher t;
    Teacher d;
    Teacher b = t;
    b = d;
    int * v = const_cast<int*>(t.getAge());
    *v = 3;
    cout << "v:"<< *v <<", age:" << *(t.getAge()) << endl;
    
}