SELECT car_id
FROM car_rental_company_rental_history
WHERE start_date <= '2022-10-16'
  AND end_date >= '2022-10-16'
GROUP BY car_id;

SELECT distinct(car_id),
       IF(car_id in (SELECT car_id
FROM car_rental_company_rental_history
WHERE start_date <= '2022-10-16'
  AND end_date >= '2022-10-16'
GROUP BY car_id) , '대여중', '대여 가능') AS rental_status
FROM car_rental_company_rental_history
order by car_id desc;
