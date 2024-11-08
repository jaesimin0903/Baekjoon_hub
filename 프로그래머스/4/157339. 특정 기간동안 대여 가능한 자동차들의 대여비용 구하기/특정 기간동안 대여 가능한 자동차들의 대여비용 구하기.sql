# CAR_RENTAL_COMPANY_CAR 테이블과 CAR_RENTAL_COMPANY_RENTAL_HISTORY 테이블과 CAR_RENTAL_COMPANY_DISCOUNT_PLAN 테이블에서 자동차 종류가 '세단' 또는 'SUV' 인 자동차 중 2022년 11월 1일부터 2022년 11월 30일까지 대여 가능하고 30일간의 대여 금액이 50만원 이상 200만원 미만인 자동차에 대해서 자동차 ID, 자동차 종류, 대여 금액(컬럼명: FEE) 리스트를 출력하는 SQL문을 작성해주세요. 결과는 대여 금액을 기준으로 내림차순 정렬하고, 대여 금액이 같은 경우 자동차 종류를 기준으로 오름차순 정렬, 자동차 종류까지 같은 경우 자동차 ID를 기준으로 내림차순 정렬해주세요.

SELECT c.car_id, c.car_type,
    CASE
        WHEN c.car_type = 'SUV' THEN FLOOR(30 * c.daily_fee * (1 - p.discount_rate / 100))
        WHEN c.car_type = '세단' THEN FLOOR(30 * c.daily_fee * (1 - p.discount_rate / 100))
    END AS fee
FROM car_rental_company_car c
JOIN car_rental_company_discount_plan p 
    ON c.car_type = p.car_type AND p.duration_type = '30일 이상'
WHERE c.car_type IN ('SUV', '세단')
    AND c.car_id NOT IN (
        SELECT car_id
        FROM car_rental_company_rental_history
        WHERE start_date <= '2022-11-30' AND end_date >= '2022-11-01'
    )
    AND (
        (c.car_type = 'SUV' AND FLOOR(30 * c.daily_fee * (1 - p.discount_rate / 100)) BETWEEN 500000 AND 2000000)
        OR (c.car_type = '세단' AND FLOOR(30 * c.daily_fee * (1 - p.discount_rate / 100)) BETWEEN 500000 AND 2000000)
    )
ORDER BY fee DESC, c.car_type ASC, c.car_id DESC;
