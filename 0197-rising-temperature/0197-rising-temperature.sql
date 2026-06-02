SELECT w.id
FROM Weather as w
INNER JOIN Weather as t
ON w.recordDate = DATE_ADD(t.recordDate, INTERVAL 1 DAY)
WHERE w.temperature > t.temperature