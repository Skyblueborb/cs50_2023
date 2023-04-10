SELECT COUNT(*) FROM movies WHERE id IN (SELECT movie_id FROM ratings WHERE rating IS 10.0);
