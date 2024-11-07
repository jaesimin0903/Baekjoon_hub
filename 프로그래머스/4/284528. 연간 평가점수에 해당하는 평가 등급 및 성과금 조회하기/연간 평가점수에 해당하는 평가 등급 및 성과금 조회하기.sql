-- 코드를 작성해주세요
-- hr-grade 에서 평균 점수 내기
select g.emp_no, emp_name,
case
    when avg(score) >= 96 then 'S'
    when avg(score) >= 90 then 'A'
    when avg(score) >= 80 then 'B'
    else 'C'
end as grade,
case
    when avg(score) >= 96 then e.sal * 0.2
    when avg(score) >= 90 then e.sal * 0.15
    when avg(score) >= 80 then e.sal * 0.1
    else 0
end as bonus
from hr_grade as g
join hr_employees as e on g.emp_no = e.emp_no
group by emp_no;