/* write a SQL query to list the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred. */
SELECT title FROM stars JOIN movies on stars.movie_id = movies.id JOIN people on stars.person_id = people.id WHERE name IN ("Johnny Depp", "Helena Bonham Carter") GROUP BY title
HAVING COUNT(name) = 2