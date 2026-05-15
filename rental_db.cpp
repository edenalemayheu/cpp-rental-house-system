CREATE DATABASE rental_db;
USE rental_db;

CREATE TABLE houses (
    propertyID INT PRIMARY KEY,
    title VARCHAR(100),
    location VARCHAR(100),
    type VARCHAR(50),
    bedrooms INT,
    price FLOAT,
    status VARCHAR(50),
    phone VARCHAR(15),
    ownerCode VARCHAR(20) UNIQUE 
);
