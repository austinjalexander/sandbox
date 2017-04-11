-- to run: bpsimple=# \i drop_tables.sql

DROP TABLE barcode;
DROP TABLE orderline;
DROP TABLE stock;
DROP TABLE orderinfo;
DROP TABLE item;
DROP TABLE customer;
DROP SEQUENCE customer_customer_id_seq;
DROP SEQUENCE item_item_id_seq;
DROP SEQUENCE orderinfo_orderinfo_id_seq;

/*
 * sequences are used to maintain the auto-increment
 * serial columns; in psql 8+, these sequences will
 * be auto-dropped when the relevant tables are dropped
 */
