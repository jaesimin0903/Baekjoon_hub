-- 코드를 입력하세요
# SELECT mp.member_id, rr.review_text from rest_review rr join member_profile mp on mp.member_id = rr.member_id group by rr.rest_id
# order by ;

# select  mp.MEMBER_NAME, rest.REVIEW_TEXT, date_format(rest.review_date,"%Y-%m-%d") as REVIEW_DATE
# from (select member_id, review_text, review_date from rest_review  group by rest_id) as rest
# join member_profile mp on mp.member_id = rest.member_id
# group by rest.member_id
# order by review_date, rest.review_text;

SELECT mp.MEMBER_NAME, rr.REVIEW_TEXT,date_format(rr.review_date ,"%Y-%m-%d") as REVIEW_DATE
FROM rest_review rr
JOIN member_profile mp
ON mp.member_id = rr.member_id
WHERE rr.member_id = (
    SELECT member_id
    FROM rest_review
    GROUP BY member_id
    ORDER BY COUNT(*) DESC
    LIMIT 1
)
ORDER BY REVIEW_DATE, REVIEW_TEXT;
