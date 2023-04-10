SELECT AVG(energy) FROM songs WHERE artist_id IS (SELECT id FROM artists WHERE name LIKE 'Drake');
