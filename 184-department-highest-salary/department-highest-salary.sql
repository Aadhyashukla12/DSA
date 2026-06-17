# Write your MySQL query statement bel
select
    d.name as Department,
    e.name as Employee,
    e.salary as Salary
from employee as e
join department as d
on e.departmentId=d.id
where e.salary=(
    select Max(salary)
    from Employee
    where departmentId=e.departmentId
);