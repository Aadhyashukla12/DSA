# Write your MySQL query statement below
update salary
set sex=
CASE
   WHEN SEX='m' then 'f'
   else 'm'
end;