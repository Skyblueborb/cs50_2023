 SELECT title, rating FROM movies JOIN ratings ON id = movie_id WHERE title IN (SELECT title FROM movies WHERE year = 2010) ORDER BY rating DESC, title ASC;
