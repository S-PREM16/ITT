#include <iostream>
#include <string>
#include <numeric>

using namespace std;

class Person {
public:
    string name;
    int age;
    virtual void getdata() = 0;
    virtual void putdata() = 0;
    virtual ~Person() {} 
};

class Professor : public Person {
    int publications;
    int cur_id;
    static int id_gen; 

public:
    Professor() {
        cur_id = ++id_gen;
    }

    void getdata() override {
        cin >> name >> age >> publications;
    }

    void putdata() override {
        cout << name << " " << age << " " << publications << " " << cur_id << endl;
    }
};

int Professor::id_gen = 0; 

class Student : public Person {
    int marks[6];
    int cur_id;
    static int id_gen;

public:
    Student() {
        cur_id = ++id_gen;
    }

    void getdata() override {
        cin >> name >> age;
        for (int i = 0; i < 6; i++) {
            cin >> marks[i];
        }
    }

    void putdata() override {
        int sum = 0;
        for (int i = 0; i < 6; i++) sum += marks[i];
        cout << name << " " << age << " " << sum << " " << cur_id << endl;
    }
};

int Student::id_gen = 0;

int main() {
    int n, val;
    cin >> n; 
    Person *per[n];

    for (int i = 0; i < n; i++) {
        cin >> val;
        if (val == 1) {
            per[i] = new Professor;
        } else {
            per[i] = new Student;
        }
        per[i]->getdata();
    }

    for (int i = 0; i < n; i++) {
        per[i]->putdata();
    }

    for (int i = 0; i < n; i++) {
        delete per[i];
    }

    return 0;
}

