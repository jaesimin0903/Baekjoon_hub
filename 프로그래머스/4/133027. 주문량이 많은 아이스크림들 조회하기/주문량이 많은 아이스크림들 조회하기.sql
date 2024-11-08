 select f.flavor from 
 (select h.flavor, (h.total_order + j.julySale) as sale from first_half h
join (select flavor, sum(total_order) as julySale, shipment_id from july group by flavor) as j on j.shipment_id = h.shipment_id
order by sale desc limit 3) f

