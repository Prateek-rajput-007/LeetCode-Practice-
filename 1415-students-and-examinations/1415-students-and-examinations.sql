select 
student_id, student_name, subject_name, count(e.student_id) as attended_exams 
from (Students s1 join Subjects s2) 
left join Examinations e using(student_id, subject_name) 
group by student_id, subject_name 
order by student_id, subject_name;