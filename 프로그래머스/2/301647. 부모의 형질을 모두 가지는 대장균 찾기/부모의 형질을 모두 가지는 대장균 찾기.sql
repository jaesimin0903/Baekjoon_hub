SELECT s.id as ID, s.genotype as GENOTYPE, p.genotype as PARENT_GENOTYPE
FROM ecoli_data s
JOIN ecoli_data p ON p.id = s.parent_id
WHERE (s.genotype & p.genotype) = p.genotype
ORDER BY s.id;
