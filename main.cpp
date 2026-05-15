#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <windows.h>
#include <mysql.h>

using namespace std;

struct House{
    int propertyID;
    string title;
    string location;
    string type;
    int bedrooms;
    float price;
    string status;
    string phone;
    string ownerCode;
};


MYSQL* conn;

void syncToMySQL(House h){
    if (!conn) return;
    string query = "INSERT INTO houses (propertyID, title, location, type, bedrooms, price, status, phone, ownerCode) VALUES ("
                   + to_string(h.propertyID) + ", '" + h.title + "', '" + h.location + "', '" + h.type + "', "
                   + to_string(h.bedrooms) + ", " + to_string(h.price) + ", '" + h.status + "', '" + h.phone + "', '" + h.ownerCode + "') "
                   "ON DUPLICATE KEY UPDATE title='" + h.title + "', location='" + h.location + "', type='" + h.type + "', "
                   "bedrooms=" + to_string(h.bedrooms) + ", price=" + to_string(h.price) + ", status='" + h.status + "', phone='" + h.phone + "';";
    mysql_query(conn, query.c_str());
}

void deleteFromMySQL(string code){
    if (!conn) return;
    string query ="DELETE FROM houses WHERE ownerCode = '" + code + "';";
    mysql_query(conn, query.c_str());
}

bool adminLogin(){
    string password;
    cout<<"Enter Admin Password: ";
    cin>>password;
    if (password=="aastu2026"){
        return true;}
        return false;
}

int generate_ID(){
    ifstream file("houses.txt");
    int maxID = 0;
    if (file) {
        House tmp;
        while(file>>tmp.propertyID) {
            file.ignore();
            getline(file, tmp.title);
            getline(file, tmp.location);
            getline(file, tmp.type);
            file>>tmp.bedrooms>>tmp.price>>tmp.status>>tmp.phone;
            file.ignore();
            getline(file, tmp.ownerCode);
            if (tmp.propertyID > maxID) {
                maxID = tmp.propertyID;
            }
        }
        file.close();
    }
    return maxID + 1;
}


string generate_Code(){
   ifstream file("houses.txt");
    int maxCodeNum = 99;
    if (file) {
        House tmp;
        while(file>>tmp.propertyID) {
            file.ignore();
            getline(file, tmp.title);
            getline(file, tmp.location);
            getline(file, tmp.type);
            file>>tmp.bedrooms>>tmp.price>>tmp.status>>tmp.phone;
            file.ignore();
            getline(file, tmp.ownerCode);
            if (tmp.ownerCode.length() > 1 && tmp.ownerCode[0] == 'H') {
                int currentNum = atoi(tmp.ownerCode.substr(1).c_str());
                if (currentNum > maxCodeNum) {
                    maxCodeNum = currentNum;
                }
            }
        }
        file.close();
    }
    return "H" + to_string(maxCodeNum + 1);
}

void save(House h){
    ofstream file("houses.txt",ios::app);
    file<<h.propertyID<<endl;
    file<<h.title<<endl;
    file<<h.location<<endl;
    file<<h.type<<endl;
    file<<h.bedrooms<<endl;
    file<<h.price<<endl;
    file<<h.status<<endl;
    file<<h.phone<<endl;
    file<<h.ownerCode<<endl;
    file.close();

    syncToMySQL(h);
}

