-- 코드를 입력하세요
SELECT HISTORY_ID, 
CASE
WHEN DATEDIFF(END_DATE, START_DATE)+1 BETWEEN 7 AND 29 THEN ROUND(DAILY_FEE * (DATEDIFF(END_DATE,START_DATE)+1)*(SELECT (100-DISCOUNT_RATE)/100 FROM CAR_RENTAL_COMPANY_DISCOUNT_PLAN WHERE CAR_TYPE = '트럭' AND DURATION_TYPE ='7일 이상'),0)
WHEN DATEDIFF(END_DATE, START_DATE)+1 BETWEEN 30 AND 89
THEN ROUND(DAILY_FEE * (DATEDIFF(END_DATE,START_DATE)+1)*(SELECT (100-DISCOUNT_RATE)/100 FROM CAR_RENTAL_COMPANY_DISCOUNT_PLAN WHERE CAR_TYPE = '트럭' AND DURATION_TYPE ='30일 이상'),0)
WHEN DATEDIFF(END_DATE, START_DATE)+1 >=90
THEN ROUND(DAILY_FEE * (DATEDIFF(END_DATE,START_DATE)+1)*(SELECT (100-DISCOUNT_RATE)/100 FROM CAR_RENTAL_COMPANY_DISCOUNT_PLAN WHERE CAR_TYPE = '트럭' AND DURATION_TYPE ='90일 이상'),0)
ELSE ROUND(DAILY_FEE * (DATEDIFF(END_DATE,START_DATE)+1),0)
END AS FEE FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY A
JOIN CAR_RENTAL_COMPANY_CAR B
ON B.CAR_ID = A.CAR_ID
JOIN CAR_RENTAL_COMPANY_DISCOUNT_PLAN C
ON C.CAR_TYPE = B.CAR_TYPE
WHERE B.CAR_TYPE = '트럭'
GROUP BY HISTORY_ID
ORDER BY FEE DESC, HISTORY_ID DESC

# -- 코드를 입력하세요
# select distinct(history_id),
# case when datediff(end_date, start_date)+1 between 7 and 29 then round(daily_fee*(datediff(end_date, start_date)+1)*(select (100-DISCOUNT_RATE)/100 from CAR_RENTAL_COMPANY_DISCOUNT_PLAN where car_type = '트럭' and duration_type = '7일 이상'),0)
# when datediff(end_date, start_date)+1 between 30 and 89 then round(daily_fee*(datediff(end_date, start_date)+1)*(select (100-DISCOUNT_RATE)/100 from CAR_RENTAL_COMPANY_DISCOUNT_PLAN where car_type = '트럭' and duration_type = '30일 이상'),0)
# when datediff(end_date, start_date)+1 >=90 then round(daily_fee*(datediff(end_date, start_date)+1)*(select (100-DISCOUNT_RATE)/100 from CAR_RENTAL_COMPANY_DISCOUNT_PLAN where car_type = '트럭' and duration_type = '90일 이상'),0)
# else round(daily_fee*(datediff(end_date, start_date)+1),0)
# end as fee
# from CAR_RENTAL_COMPANY_RENTAL_HISTORY a
# join CAR_RENTAL_COMPANY_CAR b
# on a.CAR_ID = b.CAR_ID
# join CAR_RENTAL_COMPANY_DISCOUNT_PLAN c
# on b.CAR_TYPE = c.CAR_TYPE
# where b.CAR_TYPE = '트럭'
# order by 2 desc, 1 desc