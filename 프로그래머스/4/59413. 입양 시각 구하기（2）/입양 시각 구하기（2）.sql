WITH RECURSIVE hours AS (
  SELECT 0 AS hour
  UNION ALL
  SELECT hour + 1
  FROM hours
  WHERE hour < 23
)
SELECT h.hour, COUNT(a.DATETIME) AS COUNT
FROM hours h
LEFT JOIN ANIMAL_OUTS a ON h.hour = HOUR(a.DATETIME)
GROUP BY h.hour
ORDER BY h.hour;