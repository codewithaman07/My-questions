# Write your MySQL query statement below
SELECT max(num) AS num
FROM (
    SELECT num
    FROM MYNumbers
    GROUP BY num
    HAVING COUNT(num) = 1
) as unique_nums