-- # Write your MySQL query statement below
-- select max(salary) as SecondHighestSalary from Employee
-- where Employee.salary < (select max(salary) from Employee)

-- limit 1 offset


select ifnull((select distinct salary as SecondHighestSalary from Employee 
order by salary desc limit 1 offset 1), null) as SecondHighestSalary
