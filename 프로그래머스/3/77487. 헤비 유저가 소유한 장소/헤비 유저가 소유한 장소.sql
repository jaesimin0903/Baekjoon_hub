-- 코드를 입력하세요

-- host 아이디 별로 카운트 저장한 select

select id, name, host_id from places
where host_id in (
    select host_id from places
    group by host_id
    having count(*) > 1
)
order by id;