select d.dept_id, d.dept_name_en, round(avg(sal))as avg_sal from hr_employees as h
join hr_department as d on h.dept_id = d.dept_id
group by dept_id
order by avg(sal) desc;