-- 코드를 입력하세요
SELECT 
HISTORY_ID,
CAR_ID,
DATE_FORMAT(START_DATE,"%Y-%m-%d")AS START_DATE,
DATE_FORMAT(END_DATE,"%Y-%m-%d")AS END_DATE,
case when datediff(end_date, start_date) >= 29 then '장기 대여'
else '단기 대여'
end as RENT_TYPE
from car_rental_company_rental_history
WHERE YEAR(START_DATE) = 2022 AND MONTH(START_DATE) = 9
ORDER BY HISTORY_ID DESC;