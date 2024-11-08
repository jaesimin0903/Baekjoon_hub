-- 코드를 입력하세요
select p.product_code, sum(s.sales_amount) * p.price as sales from offline_sale s
join product p on p.product_id = s.product_id
group by s.product_id
order by sales desc, p.product_code