SELECT 
    c.patient_id, 
    p.patient_name, 
    p.age, 
    DATEDIFF(MIN(c1.test_date), MIN(c.test_date)) AS recovery_time
FROM 
    covid_tests c 
INNER JOIN 
    covid_tests c1 
ON 
    c.patient_id = c1.patient_id AND c.test_date < c1.test_date AND c.result = 'Positive' AND c1.result = 'Negative'
INNER JOIN 
    patients p 
ON 
    c.patient_id = p.patient_id
GROUP BY 
    c.patient_id, 
    p.patient_name, 
    p.age
ORDER BY 
    recovery_time, 
    p.patient_name;