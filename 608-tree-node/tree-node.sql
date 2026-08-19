select id,
      CASE
          When p_id is NULL then 'Root'
          when id in(select p_id from Tree) then 'Inner'
          else 'Leaf'
        END as type
from Tree;