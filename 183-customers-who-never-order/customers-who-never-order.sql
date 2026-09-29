select name as Customers from Customers c 
     where not exists(
    select 1 from Orders o where c.id=o.customerId
);