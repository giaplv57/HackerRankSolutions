#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person{
    public:
        int age;
        char name[100];
        int id;
        virtual void getdata(){};
        virtual void putdata(){};
};

class Professor : public Person{
    public:
        static int idCount;
        Professor(){
            this->id = idCount;
            idCount++;
        }
        int publications;
        void getdata(){
            cin >> this->name;
            cin >> this->age;
            cin >> this->publications;
        }
        void putdata(){
            cout << this->name << " " << this->age << " " << this->publications << " " << this->id << endl;
        }
};

class Student : public Person{
    public:
        static int idCount;
        Student(){
            this->id = idCount;
            idCount++;
        }
        int marks[6];
        void getdata(){
            cin >> this->name;
            cin >> this->age;
            for (int i=0; i<6; i++){
                cin >> marks[i];
            }
        }
        void putdata(){
            cout << this->name << " " << this->age << " ";
            int sum = 0;
            for (int i=0; i<6; i++){
                sum += this->marks[i];
            }
            cout << sum << " " << this->id << endl;
        }
};
int Student::idCount = 1;
int Professor::idCount = 1;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
