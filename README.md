# Property Rental Management System 

This is a console-based Property Rental Management System developed using C++ and MySQL. 
The system allows administrators to manage rental properties and enables users to search and view available houses. Property information is stored locally in a text file and synchronized with a MySQL database.

--- 
## Features 

### Admin Functions 

- Add new houses
- Update property information
- Delete properties
- View all listed houses
- Search properties

### User Functions 

- View available houses
- Search houses based on:
  - House type
  - Number of bedrooms
  - Maximum price
  - 
### Additional Features 

- Admin password protection
- Automatic Property ID generation
- Automatic Owner Code generation
- Input validation
- MySQL database synchronization

--- 
## Technologies Used 

- C++
- MySQL
- File Handling
- MySQL C API

--- 

## Requirements 

Before running the project, make sure you have: 
1. A C++ compiler (GCC, MinGW, MSVC, or Clang)
2. MySQL Server installed and running
3. MySQL Connector/C libraries configured properly

 --- 
## Database Setup 

Run the following command to initialize the database:
```bash
mysql -u root -p < rental_db.sql
```

---

## Configure Database Connection

Open main.cpp and update your MySQL password inside:

```cpp
mysql_real_connect(conn, "localhost", "root", "YOUR_PASSWORD", "rental_db", 0, NULL, 0);
```

---

## Compilation

Compile the project using:

```bash
g++ main.cpp -o RentalSystem.exe -lmysql
```

For Windows users, make sure libmysql.dll is placed in the same folder as the generated .exe file.

---

## Default Admin Password

```text
aastu2026
```

---

## File Storage

The application automatically creates houses.txt during runtime if it does not already exist.

---

## Project Structure

```text
├── main.cpp
├── rental_db.sql
└── README.md
```
└── CONTRIBUTION.md

---
