# Write your MySQL query statement below
select
    DATE_FORMAT(trans_date,'%Y-%m') as month,
    country,count(*) as trans_count,
    Sum(amount) as trans_total_amount,
    Sum(state='approved') as approved_count,
    SUM(CASE WHEN state = 'approved' THEN amount ELSE 0 END) AS approved_total_amount
from Transactions
GROUP BY DATE_FORMAT(trans_date, '%Y-%m'), country