-- 코드를 입력하세요
SELECT CATEGORY, SUM(SALES)AS TOTAL_SALES FROM BOOK_SALES S
JOIN BOOK B ON B.BOOK_ID = S.BOOK_ID
WHERE YEAR(SALES_DATE) = '2022' AND MONTH(SALES_DATE) = '01'
GROUP BY CATEGORY
ORDER BY 1;