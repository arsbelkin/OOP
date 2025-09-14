#include <iostream>
#include <string>
#include <fstream>
#include "../header_files/menu.h"
#include "../header_files/utils.h"
#include "../header_files/group.h"

using namespace std;


void print_main_menu(){
    cout << endl << endl;
    cout << "---Main menu---" << endl;
    cout << "0 - stop prog" << endl;
    cout << "1 - add student to group" << endl;
    cout << "2 - show all students" << endl;
    cout << "3 - save students" << endl;
    cout << "4 - load students" << endl;
    cout << "5 - delete all students" << endl;
    cout << "----------------" << endl << endl;
}


void save_students(Group &group) {
    string file_name;
    
    cout << "file to save: ";
    getline(cin>>std::ws, file_name);
    
    ofstream file("./static/" + file_name);
    
    if (file.is_open()){
        group.saveStudents(file);
        file.close();
    } else {
        cout << "file not open!" << endl;
    }
}


void main_menu(){
    Group group("AS-23-05");
    
    cout << "Group " << group.get_title() << endl;
    
    string file_name;
    
    while(true){
        print_main_menu();
        
        int choice = valid_int(0, 5);
        
        switch (choice) {
            case 0:
                cout << endl;
                cout << "Goodbye!" << endl;
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
                cout << "You choose the number, that not exist!" << endl;
                break;
        }
    }
}

