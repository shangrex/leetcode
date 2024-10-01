# Write your MySQL query statement below
SELECT user_id, count(user_id) as followers_count from Followers GROUP BY user_id  ORDER BY user_id ASC