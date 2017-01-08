-- The answer SELECT statement is below.

DROP TABLE 'Item';
DROP TABLE 'Category';
DROP TABLE 'ItemOrderMembership';

CREATE TABLE  'Item' (
  'itemID'       INTEGER       PRIMARY KEY AUTOINCREMENT,
  'name'         CHAR(64),
  'description'  CHAR(128),
  'categoryID'   INTEGER
);

INSERT INTO 'item' ('name', 'description', 'categoryID')
VALUES ('Towel', 'Super Dry', 1), ('Tea', 'Tastes Great', NULL),  ('Surfboard', 'THe best ever', NULL), ('Car', 'It works', 2);

CREATE TABLE  'Category' (
  'categoryID'       INTEGER       PRIMARY KEY AUTOINCREMENT,
  'name'   CHAR(64)
);

INSERT INTO 'category' ('name')
VALUES ('bath'), ('vehicle');

CREATE TABLE  'ItemOrderMembership' (
  'orderID'       INTEGER,
  'itemID'   INTEGER
);

INSERT INTO 'ItemOrderMembership' ('orderID', 'itemID')
VALUES (33, 1), (12345, 1), (12345, 3);

SELECT ''; -- line separation
SELECT * FROM Item;
SELECT ''; -- line separation
SELECT * FROM Category;
SELECT ''; -- line separation
SELECT * FROM ItemOrderMembership;
SELECT ''; -- line separation

--- BEGIN ANSWER
SELECT Item.name, Category.name
FROM Item 
LEFT OUTER JOIN Category ON Item.categoryID = Category.categoryID
INNER JOIN ItemOrderMembership ON Item.itemID = ItemOrderMembership.itemID
WHERE ItemOrderMembership.orderID = 12345;
--- END ANSWER

SELECT ''; -- line separation
