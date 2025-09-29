#include <iostream>
#include <string>
#include <fstream>
#include "../header_files/menu.h"
#include "../header_files/utils.h"
#include "../header_files/group.h"

using namespace std;


BOOST_CLASS_EXPORT_IMPLEMENT(Student)
BOOST_CLASS_EXPORT_IMPLEMENT(GroupLeader)


void print_main_menu(){
    cout << endl << endl;
    cout << "---МЕНЮ---" << endl;
    cout << "0 - завершить программу" << endl;
    cout << "1 - добавить студента" << endl;
    cout << "2 - добавить старосту" << endl;
    cout << "3 - посмотреть всех обучающихся" << endl;
    cout << "4 - сохранить обучающихся в файл" << endl;
    cout << "5 - загрузить обучающийхся из файла" << endl;
    cout << "6 - удалить всех обучающихся" << endl;
    cout << "----------------" << endl << endl;
}


void save_students(Group &group) {
    string file_name;
    
    cout << "файл для сохранения: ";
    getline(cin>>std::ws, file_name);
    
    ofstream file("./static/" + file_name);
    
    if (file.is_open()){
        group.saveStudents(file);
        file.close();
    } else {
        cout << "не удалось открыть файл!" << endl;
    }
}


void main_menu(){
    Group group("АС-23-05");
    
    cout << "Группа: " << group.get_title() << endl;
    
    string file_name;
    
    while(true){
        print_main_menu();
        
        int choice = valid_int(0, 6);
        
        switch (choice) {
            case 0:
                cout << endl;
                cout << "До свидания!" << endl;
                return;
                break;
                
            case 1:
                group.addStudent<Student>();
                break;
                
            case 2:
                group.addStudent<GroupLeader>();
                break;
            
            case 3:
                group.showAllStudents();
                break;
                
            case 4:
                save_students(group);
                break;
                
            case 5:
                group.loadStudents();
                break;
            
            case 6:
                group.deleteAllStudents();
                break;
                
            default:
                cout << endl;
                cout << "надо выбрать существующий пункт меню!" << endl;
                break;
        }
    }
}
