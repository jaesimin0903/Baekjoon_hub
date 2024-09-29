-- 코드를 작성해주세요
select zero.id from ecoli_data zero 
join(select one.id from ecoli_data one
join (select three.id from ecoli_data three where three.parent_id is null) as two 
on two.id = one.parent_id) as onedata on onedata.id = zero.parent_id
order by id;


