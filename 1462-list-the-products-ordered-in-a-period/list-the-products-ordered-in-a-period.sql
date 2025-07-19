SELECT 
    p.product_name,
    sum(unit) AS unit FROM Products as p 
JOIN Orders As o 
ON p.product_id = o.product_id
WHERE o.order_date BETWEEN '2020-02-01' AND '2020-02-29'
GROUP BY p.product_name
HAVING unit>=100