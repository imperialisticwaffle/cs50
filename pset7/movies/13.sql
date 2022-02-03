/* write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred. */
SELECT DISTINCT name FROM stars JOIN people on stars.person_id = people.id JOIN movies on stars.movie_id = movies.id WHERE name IS NOT "Kevin Bacon" and title IN
(SELECT title FROM stars JOIN people on stars.person_id = people.id JOIN movies on stars.movie_id = movies.id WHERE name = "Kevin Bacon" AND birth = 1958) ORDER BY name
