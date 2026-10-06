-- INSERT INTO users (name, email, age, city) VALUES
--   ('Ravi Kumar',     'ravi@example.com',     25, 'Mumbai'),
--   ('Sita Sharma',    'sita@example.com',     30, 'Delhi'),
--   ('Arjun Patel',    'arjun@example.com',    35, 'Mumbai'),
--   ('Priya Singh',    'priya@example.com',    28, 'Bangalore'),
--   ('Vikram Reddy',   'vikram@example.com',   42, 'Hyderabad'),
--   ('Ananya Iyer',    'ananya@example.com',   22, 'Chennai'),
--   ('Rahul Verma',    'rahul@example.com',    31, 'Delhi'),
--   ('Meera Nair',     'meera@example.com',    27, 'Kochi'),
--   ('Karan Joshi',    'karan@example.com',    45, 'Mumbai'),
--   ('Divya Menon',    'divya@example.com',    33, 'Bangalore'),
--   ('Rohan Das',      'rohan@example.com',    19, 'Kolkata'),
--   ('Nisha Gupta',    'nisha@example.com',    24, 'Delhi'),
--   ('Aditya Rao',     'aditya@example.com',   38, 'Pune'),
--   ('Sneha Kapoor',   'sneha@example.com',    29, NULL),
--   ('Manish Tiwari',  'manish@example.com',   41, 'Lucknow'),
--   ('Pooja Bhatt',    'pooja@example.com',    36, 'Mumbai'),
--   ('Siddharth Jain', 'sid@example.com',      23, 'Jaipur'),
--   ('Tanvi Desai',    'tanvi@example.com',    26, 'Ahmedabad'),
--   ('Nikhil Chauhan', 'nikhil@example.com',   50, NULL),
--   ('Isha Malhotra',  'isha@example.com',     21, 'Chandigarh')
-- RETURNING id, name;





INSERT INTO products (name, price, category, stock) VALUES
  ('Laptop',       55000.00, 'Electronics', 25),
  ('Smartphone',   25000.00, 'Electronics', 100),
  ('Headphones',    2500.00, 'Electronics', 200),
  ('Coffee Mug',     350.00, 'Kitchen',     500),
  ('Notebook',       120.00, 'Stationery',  1000),
  ('Pen Set',        250.00, 'Stationery',  800),
  ('Desk Lamp',     1200.00, 'Furniture',   75),
  ('Office Chair',  8500.00, 'Furniture',   30),
  ('Water Bottle',   500.00, 'Kitchen',     400),
  ('Backpack',      1800.00, 'Accessories', 150),
  ('Watch',         3500.00, 'Accessories', 80),
  ('Sneakers',      4500.00, 'Fashion',     60),
  ('T-Shirt',        800.00, 'Fashion',     300),
  ('Jacket',        2500.00, 'Fashion',     45),
  ('Sunglasses',    1500.00, 'Accessories', 0)
RETURNING id, name, stock;