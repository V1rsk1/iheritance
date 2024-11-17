#include <iostream>
#include <string>

using namespace std;

class Student {
protected:
    string name, surname, specialty;
public:
    Student(string name, string surname, string specialty)
        : name(name), surname(surname), specialty(specialty) {}

    virtual void display() const {
        cout << "Name: " << 
          name << "\n" << "Surname: " << 
            surname << "\n" << "Specialty: " << 
            specialty << endl;
    }

    virtual string getType() const {
        return "Student";
    }


};

class Aspirant : public Student {
private:
    string theme;
public:
    Aspirant(string name, string surname, string specialty, string theme)
        : Student(name, surname, specialty), theme(theme) {}

    void display() const override {
        Student::display();
        cout << "Thesis Theme: " << theme << endl;
    }

    string getType() const override {
        return "Aspirant";
    }

};

int main() {
    Student student("John", "Doe", "Computer Science");
    student.display();
    cout << "Type: " << student.getType() << endl << endl;

    Aspirant aspirant("Alice", "Smith", "Physics", "Quantum Computing");
    aspirant.display();
    cout << "Type: " << aspirant.getType() << endl;

    return 0;
}
