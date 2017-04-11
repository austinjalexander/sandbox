-- to run: bpsimple=# \i create_tables-bpsimple.sql

CREATE TABLE customer
(
	customer_id		serial					,
	title					char(4)					,
	fname					varchar(32)				,
	lname					varchar(32)		NOT NULL,
	addressline		varchar(64)				,
	town					varchar(32)				,
	zipcode				char(10)		NOT NULL,
	phone					varchar(16)				,
	CONSTRAINT		customer_pk		PRIMARY KEY(customer_id)
);

CREATE TABLE item
(
	item_id				serial					,
	description		char(4)					,
	cost_price		varchar(32)				,
	sell_price		varchar(32)		NOT NULL,
	CONSTRAINT		item_pk			PRIMARY KEY(item_id)
);

CREATE TABLE orderinfo
(
	orderinfo_id	serial					,
	customer_id		integer					,
	date_placed		date					,
	date_shipped	date					,
	shipping			numeric(7,2)	NOT NULL,
	CONSTRAINT		orderinfo_pk	PRIMARY KEY(orderinfo_id)
);

CREATE TABLE stock
(
	item_id			integer			NOT NULL,
	quantity		integer			NOT NULL,
	CONSTRAINT		stock_pk		PRIMARY KEY(item_id)
);

CREATE TABLE orderline
(
	orderinfo_id	integer			NOT NULL,
	item_id			integer			NOT NULL,
	quantity		integer			NOT NULL,
	CONSTRAINT		stock_pk		PRIMARY KEY(orderinfo_id, item_id)
);

CREATE TABLE barcode
(
	barcode_ean		char(13)		NOT NULL,
	item_id			integer			NOT NULL,
	CONSTRAINT		barcode_pk		PRIMARY KEY(barcode_ean)
);







