-- 코드를 입력하세요
SELECT DISTINCT(H.CAR_ID) FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY H
JOIN CAR_RENTAL_COMPANY_CAR R ON R.CAR_ID = H.CAR_ID
WHERE R.CAR_TYPE = '세단' AND MONTH(START_DATE) = 10
ORDER BY 1 DESC