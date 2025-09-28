#include <iostream>
#include <string>
#include <fstream>
#include "../header_files/menu.h"
#include "../header_files/utils.h"
#include "../header_files/group.h"

using namespace std;


void print_main_menu(){
    cout << endl << endl;
    cout << "---МЕНЮ---" << endl;
    cout << "0 - завершить программу" << endl;
    cout << "1 - добавить студента" << endl;
    cout << "2 - посмотреть всех студентов" << endl;
    cout << "3 - сохранить студентов в файл" << endl;
    cout << "4 - загрузить студентов из файла" << endl;
    cout << "5 - удалить всех студентов" << endl;
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
        
        int choice = valid_int(0, 5);
        
        switch (choice) {
            case 0:
                cout << endl;
                cout << "До свидания!" << endl;
                return;
                break;
                
            case 1:
                group.addStudent();
                break;
            
            case 2:
                group.showAllStudents();
                break;
                
            case 3:
                save_students(group);
                break;
                
            case 4:
                group.loadStudents();
                break;
            
            case 5:
                group.deleteAllStudents();
                break;
                
            default:
                cout << endl;
                cout << "надо выбрать существующий пункт меню!" << endl;
                break;
        }
    }
}
