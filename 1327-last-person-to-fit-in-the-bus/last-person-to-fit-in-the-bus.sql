SELECT person_name
FROM (
  SELECT person_name, weight, turn, SUM(weight) OVER (ORDER BY turn) AS cum_wt
  FROM Queue
) AS sub
WHERE cum_wt <= 1000
ORDER BY cum_wt DESC
LIMIT 1