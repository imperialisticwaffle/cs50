/* write a SQL query to list the names of all people who have directed a movie that received a rating of at least 9.0. */
SELECT DISTINCT name FROM directors JOIN movies on directors.movie_id = movies.id JOIN ratings on movies.id = ratings.movie_id JOIN people on directors.person_id = people.id WHERE (rating = 9 OR
rating > 9)