-- 코드를 입력하세요
SELECT MCDP_CD 진료과코드, COUNT(*) AS 5월예약건수 FROM APPOINTMENT
WHERE MONTH(APNT_YMD) =5
GROUP BY MCDP_CD
ORDER BY 2 ASC, 1 ASC