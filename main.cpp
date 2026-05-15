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
