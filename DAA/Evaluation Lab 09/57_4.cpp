CREATE DATABASE InvestmentDatabase;


//Create the Persons table

CREATE TABLE Person_57 (
    person_id INT(8) PRIMARY KEY,
    person_name VARCHAR(50),
    dob DATE,
    gender VARCHAR(8),
    father INT(8),
    mother INT(8),
    FOREIGN KEY (father) REFERENCES Person_57(person_id),
    FOREIGN KEY (mother) REFERENCES Person_57(person_id)
);

 Create the Companies table

CREATE TABLE Companie_57 (
    company_id INT(8) PRIMARY KEY,
    company_name VARCHAR(50),
    capital DECIMAL(20,2)
);

Create the Investments table

CREATE TABLE Investment_57 (
    investment_id INT(8) PRIMARY KEY ,
    company_id INT(8),
    person_id INT(8),
    share DECIMAL(20, 2),
    FOREIGN KEY (company_id) REFERENCES Companie_57(company_id),
    FOREIGN KEY (person_id) REFERENCES Person_57(person_id)
);




 Insert data into Person table
INSERT INTO Person_57 (person_id, person_name, dob, gender, father, mother)
VALUES(
    (1, 'Mahmud', '1967-03-01', 'Male', NULL, NULL),
    (2, 'Shahnaz', '1973-05-05', 'Female', NULL, NULL),
    (3, 'Nazrul', '1965-02-10', 'Male', NULL, NULL),
    (4, 'Momtaz', '1970-08-25', 'Female', NULL, NULL),
    (5, 'Sami', '2001-05-07', 'Male', 1, 2),
    (6, 'Shemu', '1995-12-12', 'Female', 1, 2),
    (7, 'Rakib', '2002-04-30', 'Male', 3, 4),
    (8, 'Habib', '2005-03-18', 'Male', 3,4),
    (9, 'Jessica ', '1992-11-05', 'Female', NULL, NULL),
    (10, 'Sukanto', '2001-07-28', 'Male', NULL, NULL));


 Insert data into Company table

INSERT INTO Companie_57 (company_id, company_name, capital)
VALUES
    (1, 'ABC Corporation', 1000000.00),
    (2, 'XYZ Enterprises', 800000.00),
    (3, 'Tech Innovators', 1500000.00);


 Insert data into Investment table

INSERT INTO Investment_57 (investment_id,company_id, person_id, share)
VALUES
    (1,1, 8, 6.75),
    (2,2, 9, 4.50),
    (3,3, 10, 10.00),
    (4,3, 5, 15.00),
    (5,2, 4, 8.50),
    (6,1, 3, 12.50);







