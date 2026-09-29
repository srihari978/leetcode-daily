 with rankas as (select d.name as Department,e.name as Employee ,e.Salary as salary,
    RANK() OVER(partition by d.id order by salary desc) as rnk
    from Employee e join Department d on e.departmentId=d.id )
select Department,Employee,Salary from rankas where rnk=1;
      