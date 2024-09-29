WITH recursive generation as(
    select id, parent_id, 1 as generation
    from ecoli_data
    where parent_id is null
    
    union all
    
    select e.id, e.parent_id, g.generation + 1 as generation
    from ecoli_data e
    join generation g on e.parent_id = g.id
)

select count(*) as COUNT, g.generation as GENERATION
from generation g
left join ecoli_data e on g.id = e.parent_id
where e.id is null
group by g.generation
order by g.generation;

# WITH RECURSIVE generation_tree AS (
#     -- 최초 세대 (PARENT_ID가 NULL인 개체)
#     SELECT 
#         ID, 
#         PARENT_ID, 
#         1 AS generation
#     FROM 
#         ecoli_data
#     WHERE 
#         PARENT_ID IS NULL
    
#     UNION ALL
    
#     -- 다음 세대를 재귀적으로 추적
#     SELECT 
#         e.ID, 
#         e.PARENT_ID, 
#         gt.generation + 1 AS generation
#     FROM 
#         ecoli_data e
#     JOIN 
#         generation_tree gt ON e.PARENT_ID = gt.ID
# )

-- 자식이 없는 개체와 세대별로 그룹화
# SELECT 
#     COUNT(*) AS COUNT,
#     generation_tree.generation AS GENERATION
    
# FROM 
#     generation_tree
# LEFT JOIN 
#     ecoli_data e ON generation_tree.ID = e.PARENT_ID
# WHERE 
#     e.ID IS NULL -- 자식이 없는 개체
# GROUP BY 
#     generation_tree.generation
# ORDER BY 
#     generation_tree.generation;

