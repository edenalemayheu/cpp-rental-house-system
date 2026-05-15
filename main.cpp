void displayHouse(House h){
    cout<<"\nProperty ID: "<<h.propertyID<<endl;
    cout<<"Title: " <<h.title<<endl;
    cout<<"Location: "<<h.location<<endl;
    cout<<"Type: "<<h.type<<endl;
    cout<<"Bedrooms: "<<h.bedrooms<< endl;
    cout<<"Price: "<<h.price<<endl;
    cout<<"Status: "<<h.status<<endl;
    cout<<"Phone: +251 "<<h.phone<<endl;
    cout<<"\n\n";
}

void add(){
    House h;
    h.propertyID = generate_ID();
    h.ownerCode = generate_Code();
cin.ignore();
cout<<"Enter descriptive Title:";
getline(cin,h.title);
cout<<"Enter location:";
getline(cin,h.location);
cout<<"Enter type:";
getline(cin,h.type);
cout<<"Enter number of bedrooms:";

 while (!(cin >> h.bedrooms)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout<<"Invalid input.";
    }
cout<<"Enter Price per month:";
 while (!(cin >> h.price)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout<<"Invalid input. ";
    }
h.status="Available";
while (true) {
cout<<"Enter your contact information:+251 ";
cin>>h.phone;
if (h.phone.length() == 10) {
            break;
        } else {
            cout<<"phone number should be of length 10. Please try again.\n";
        }
    }

save(h);

cout<<"\nThank you for using our system.Your house is added Successfully. \n";
cout<<"Your property Id is "<<h.propertyID<<".And Your Owner Code is:"<<h.ownerCode <<". Keep it safe!!"<<endl;
}
void view(){
  ifstream file("houses.txt");
    if(!file){cout<<"File Could Not Open.\n";
        return;}
House h;
    cout<<"\n======= PROPERTY LIST =======\n";
    while(file>>h.propertyID){
        file.ignore();
        getline(file,h.title);
        getline(file, h.location);
        getline(file, h.type);
        file>>h.bedrooms;
        file>>h.price;
        file>>h.status;
        file>>h.phone;
        file.ignore();
        getline(file,h.ownerCode);
     displayHouse(h);
    }
file.close();
}
void search(){
     ifstream file("houses.txt");
      if(!file){
            cout<<"File Could Not Open.\n";
        return;}
string search_type;
int search_bedrooms;
float max_price;
cin.ignore();
cout<<"\nEnter the type of house you want: ";
getline(cin,search_type);
cout<<"Enter the number of bedrooms: ";

while (!(cin >> search_bedrooms)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input.";
    }
cout<<"Enter Maximum Price: ";

 while (!(cin >> max_price)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input.";
    }

House h;
bool found=false;
while(file>>h.propertyID){
        file.ignore();
        getline(file,h.title);
        getline(file,h.location);
        getline(file,h.type);
        file>>h.bedrooms;
        file>>h.price;
        file>>h.status;
        file>>h.phone;
        file.ignore();
        getline(file,h.ownerCode);
  if (search_type == h.type && h.bedrooms == search_bedrooms && h.price <= max_price) {
            found = true;
            displayHouse(h);
        }
    }
  if(!found){
      int ans;
      cout<<"Match not found for more house information you can view other properties.\nClick 1 to view properties , other key to continue\n";
      cin>>ans;
      if(ans==1)
        view();
      else
        return;
  }
  file.close();
}

void update(){
  ifstream file("houses.txt");
   if(!file){
        cout<<"File Could Not Open.\n";
      return;}
vector<House> temp;
House h;
int id;
string code;
cout<<"Enter Property ID: ";

while(!(cin >> id)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid entry.  Re-enter ID";
    }
cout<<"Enter Owner Code: ";
cin>>code;
bool found = false;
while(file>>h.propertyID){
        file.ignore();
        getline(file,h.title);
        getline(file,h.location);
        getline(file,h.type);
        file>>h.bedrooms;
        file>>h.price;
        file>>h.status;
        file>>h.phone;
        file.ignore();
        getline(file, h.ownerCode);
if(h.propertyID==id && h.ownerCode==code){
        found = true;
        cout<<"\n======= PROPERTY FOUND =======\n";
        displayHouse(h);
 int choice;
cout<<"What do u want to update?"<<endl;
cout<<"1)Price"<<endl;
cout<<"2)Status"<<endl;
cout<<"3)Phone number"<<endl;
cout<<"4)All"<<endl;
cin>>choice;
switch(choice){
   case 1:{
      cout<<"Enter New Price: ";
while(!(cin>>h.price)){
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout<<"Invalid.";
                }
      break;}
   case 2:{
       int statusChoice;
    cout<<"Enter New Status\n 1)Available  2)Rented: ";
     while(!(cin>>statusChoice)  (statusChoice != 1 && statusChoice != 2)) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout<<"Invalid selection. Choose 1 or 2: ";
                }
                if(statusChoice == 1) h.status = "Available";
                else h.status = "Rented";
    break;}
   case 3:{
    while(true){
                    cout<<"Enter New contact information:";
                    cin>>h.phone;
                    if(h.phone.length() == 10) break;
                    cout<<"Phone number should be of length 10.Please try again.\n";}
    break;}
   case 4:{
        cout<<"Enter New Price: ";
                while(!(cin>>h.price)) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout<<"Invalid input. Enter again: ";}

                int statusChoice;
                cout<<"Select New Status:\n1) Available  2) Rented\nEnter Choice: ";
                while(!(cin>>statusChoice)  (statusChoice != 1 && statusChoice != 2)) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout<<"Invalid selection.Choose 1 or 2: ";}
                if(statusChoice == 1) h.status ="Available";
                else h.status = "Rented";

                while(true) {
                    cout<<"Enter New contact information: ";
                    cin>>h.phone;
                    if(h.phone.length() == 10) break;
                    cout<<"Phone number should be of length 10. Please try again.\n";}
                break;
            }
   default:
    cout<<"Invalid Input!";
        }
        syncToMySQL(h);
        }
    temp.push_back(h);
}
file.close();

ofstream outFile("houses.txt");

    for(int i = 0; i < temp.size(); i++){
        outFile<<temp[i].propertyID<<endl;
        outFile<<temp[i].title<<endl;
        outFile<< temp[i].location<<endl;
        outFile<<temp[i].type<<endl;
        outFile<<temp[i].bedrooms<<endl;
        outFile<<temp[i].price<<endl;
        outFile<<temp[i].status<<endl;
        outFile<<temp[i].phone<<endl;
        outFile<<temp[i].ownerCode<<endl;
    }
    outFile.close();
  if(found){
        cout<<"\nYour house is Updated Successfully.\n";}
    else{
        cout<<"\nYour house is not registered!!!\n";}
}
void deletee(){
      ifstream file("houses.txt");
        if(!file){cout << "File Could Not Open.\n";
           return;}
    string code;
    cout<<"\nEnter Owner Code to delete: ";
    cin>>code;
    House h;
   vector<House>tempStorage;
    bool found = false;
 while(file>>h.propertyID){
        file.ignore();
        getline(file,h.title);
        getline(file,h.location);
        getline(file,h.type);
        file>>h.bedrooms;
        file>>h.price;
        file>>h.status;
        file>>h.phone;
        file.ignore();
        getline(file,h.ownerCode);
        if(h.ownerCode == code){
            found = true;
            deleteFromMySQL(code);
            continue;
        }
        tempStorage.push_back(h);

    }
    file.close();
    ofstream outFile("houses.txt");
    for(int i = 0; i < tempStorage.size(); i++){
        outFile<<tempStorage[i].propertyID<<endl;
        outFile<<tempStorage[i].title<<endl;
        outFile<<tempStorage[i].location<<endl;
        outFile<<tempStorage[i].type<<endl;
        outFile<<tempStorage[i].bedrooms<<endl;
        outFile<<tempStorage[i].price<<endl;
        outFile<<tempStorage[i].status<<endl;
        outFile<<tempStorage[i].phone<<endl;
        outFile<<tempStorage[i].ownerCode<<endl;
    }
    outFile.close();
    if(found){
        cout<<"\nProperty Deleted Successfully.\n";
    }
    else{
        cout<<"\nInvalid Owner Code.\n";
    }
}
int main(){
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "root", "PASSWORD", "rental_db", 0, NULL, 0)) {
        cout << "Connection Error\n";}
         else {
        cout << "System Connected Successfully!\n";}
    int roleChoice;
do{
        cout<<"\n----- PROPERTY RENTAL SYSTEM -----\n";
        cout<<"1. Admin\n2. User\n3. Exit\n";
        cout<<"Enter Choice: ";
        cin>>roleChoice;
if(roleChoice==1){
            if (!adminLogin()) {
                cout<<"\nIncorrect Password! Access Denied.\n";
                 continue;
            }
   int adminChoice;
do {
                cout<<"\n--- ADMIN MENU ---\n";
                cout<<"1. Add House\n2. Update House\n3. Delete House\n4. View Houses\n5. Search House\n6. Logout\n";
                cout<<"Enter Choice: ";
                cin>>adminChoice;
switch(adminChoice){
    case 1:{
            add();
            break;}
    case 2:{
            update();
            break;}
    case 3:{
            deletee();
            break;}
    case 4:{
            view();
            break;}
    case 5:{
            search();
            break;}
    case 6:{
            cout<<"\nLogging out of admin portal...\n";
            break;}
    default:{
            cout<<"\nInvalid selection code.\n";}
}
}while(adminChoice!=6);
}else if (roleChoice == 2) {
            int userChoice;
do{
                cout<<"\n--- USER MENU ---\n";
                cout<<"1. View Houses\n2. Search House\n3. Back to Main Menu\n";
                cout<<"Enter Choice: ";
                cin>>userChoice;

switch(userChoice){
                    case 1: view(); break;
                    case 2: search(); break;
                    case 3: cout<<"\nReturning to home intercept...\n"; break;
                    default: cout<<"\nInvalid input.\n";
}
}while(userChoice!=3);
                                  }
}while(roleChoice!=3);
    if (conn) mysql_close(conn);
    cout<<"\nHave a wonderful time:) Thank you!\n";
    return 0;
}
