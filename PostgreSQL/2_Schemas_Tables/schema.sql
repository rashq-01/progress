---- schema.sql - Day 2 version (no foreign key yet)

DROP TABLE IF EXISTS order_items;
DROP TABLE IF EXISTS orders;
DROP TABLE IF EXISTS products;
DROP TABLE IF EXISTS users;

CREATE TABLE users(
    id SERIAL PRIMARY KEY,
    name TEXT,
    email TEXT,
    age INT
);

CREATE TABLE products(
    id SERIAL PRIMARY KEY,
    name TEXT,
    price NUMERIC(10,2),
    category TEXT,
    stock INT
);

CREATE TABLE orders(
    id SERIAL PRIMARY KEY,
    user_id INT,
    status TEXT,
    total NUMERIC(10,2),
    created_at TIMESTAMPTZ DEFAULT now()
);

CREATE TABLE orders_items(
    id SERIAL PRIMARY KEY,
    order_id INT,
    product_id INT,
    quantity INT,
    price NUMERIC(10,2)
);

