SELECT count(*) as COUNT
FROM ecoli_data
WHERE (bin(genotype) & 0b0010) != 0b0010 
and ((bin(genotype) & 0b0001 = 0b0001) or
     (bin(genotype) & 0b0100 = 0b0100));

