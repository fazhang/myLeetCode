https://leetcode.com/problems/combine-two-tables/

# Write your MySQL query statement below
select a.FirstName as FirstName , a.LastName as LastName
,b.City  as City,  b.State as State
from Person a left join Address b
ON a.PersonId = b.PersonId;
