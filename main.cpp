#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<list>
using namespace std;
int randomId(){
    int value = rand();
    return value;
}
class task{
    protected:
        string task_name;
        string task_importance;
        int task_id;
    public:
        task(string tn,string tim,int tid){
            this->task_name = tn,
            this->task_importance = tim,
            this->task_id = tid;
        }
        void displayData(){
            cout<<"Dane zadania: "<<endl<<"Nazwa: "<<this->task_name<<endl<<"Waga: "<<this->task_importance<<endl<<"id: "<<this->task_id<<endl;
        }
        string getName(){
            return this->task_name;
        }
        string getImportance(){
            return this->task_importance;
        }
        int getId(){
            return this->task_id;
        }
};
class tasks{
    public:
        tasks(){
            this->taskList = {};
        };
        void addTask(string name, string importance, int id){
            this->taskList.push_front(task(name,importance,id));
        };
        void displayTasks(){
            for(task instance: this->taskList){
                cout<<"Id: "<<instance.getId()<<" Zadanie: "<<instance.getName()<<" Waga: "<<instance.getImportance()<<endl;
            }
        }
        void removeTask(int pos){
            auto it = taskList.begin();
            advance(it,pos);
            taskList.erase(it);
        }
        static void hello(){
            cout<<"hi";
        }
    protected:
        list<task> taskList;
};
class controler{
    public:
        void start(){
            cout<<"Witamy cie w naszej todoliscie, co chcesz zrobic?"<<endl<<endl;
            cout<<"1: Wyswietlic liste zadan"<<endl;
            cout<<"2: Dodac zadanie"<<endl;
            cout<<"3: Usunac zadanie"<<endl;
            cout<<"4: Wyjsc"<<endl;
            cin>>this->choice;
            switch (this->choice) {
                case 1:
                    this->wyswietl();
                    break;
                case 2:
                    this->addTask();
                    break;
                case 3:
                    this->removeTask();
                    break;
                case 4:
                    exit(0);
            }
        }
        void displayAfterOption(){
            int choiceInside;
            cout<<"Co chcesz teraz zrobic?"<<endl<<endl;
            cout<<"1. Wrocic do menu"<<endl;
            cout<<"2. Wyjsc z programu"<<endl;
            cin>>choiceInside;
            switch (choiceInside) {
                case 1:
                    this->start();
                    break;
                case 2:
                    exit(0);
                    break;
                default:
                    displayAfterOption();
            }
        }
        void wyswietl(){
            this->zadania.displayTasks();
            displayAfterOption();
        }
        void addTask(){
            string zadanie, waga;
            int id;
            cout<<"Podaj nazwe zadania, wage jego oraz id"<<endl;
            cin>>zadanie>>waga>>id;
            this->zadania.addTask(zadanie,waga,id);
            displayAfterOption();
        }
        void removeTask(){
            int zadanko;
            cout<<"Podaj ktore zadanie chcesz usunac? (od gory)"<<endl;
            cin>>zadanko;
            this->zadania.removeTask(zadanko);
            displayAfterOption();
        }
    private:
        int choice;
        tasks zadania;
};
int main(){
    controler kontroler;
    kontroler.start();
}