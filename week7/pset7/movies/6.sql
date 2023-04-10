SELECT AVG(rating) FROM ratings WHERE movie_id IN (SELECT id FROM movies WHERE year IS 2012);
