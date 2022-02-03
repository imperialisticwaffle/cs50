/* write a SQL query to list the titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated. */
SELECT title FROM stars JOIN movies on stars.movie_id = movies.id JOIN people on stars.person_id = people.id JOIN ratings on ratings.movie_id = movies.id WHERE name = "Chadwick Boseman" ORDER BY
rating DESC LIMIT 5