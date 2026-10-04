

create table books(
    id serial primary key,
    title text not null,
    author text not null,
    year integer check(year<2100 and year>1000),
    price NUMERIC(8,2) check(price>=0)
);

alter table books add column isbn type text unique not null;