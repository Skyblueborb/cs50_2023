-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Find the crime report
SELECT * FROM crime_scene_reports WHERE (year = 2021 AND month = 7 AND day = 28) AND street LIKE 'Humphrey Street';

-- Inspect the 3 interview transcripts
SELECT * FROM interviews WHERE transcript LIKE '%bakery%';

-- Find the possible license plate of the thief
SELECT * FROM bakery_security_logs WHERE (year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25);

-- Find the possible bank account of the thief
SELECT * FROM atm_transactions WHERE atm_location LIKE 'Leggett Street' AND (year = 2021 AND month = 7 AND day = 28) AND transaction_type = 'withdraw';

-- Find the flight the thief took
SELECT * FROM flights WHERE (year = 2021 AND month = 7 AND day = 29) AND origin_airport_id = 8 ORDER BY hour ASC LIMIT 1;

-- Find possible phone number of thief and accomplice
SELECT * FROM phone_calls WHERE (year = 2021 AND month = 7 AND day = 28) AND duration < 60;

-- Get our first 8 suspects
SELECT name FROM people WHERE id IN (SELECT person_id FROM bank_accounts WHERE account_number In (SELECT account_number FROM atm_transactions WHERE atm_location LIKE 'Leggett Street' AND (year = 2021 AND month = 7 AND day = 28) AND transaction_type = 'withdraw'));

-- More suspects
SELECT name FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE (year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25));

-- 2 of the common suspects
SELECT name FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE (year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25))
INTERSECT
SELECT name FROM people WHERE id IN (SELECT person_id FROM bank_accounts
WHERE account_number In (SELECT account_number FROM atm_transactions WHERE atm_location LIKE 'Leggett Street' AND (year = 2021 AND month = 7 AND day = 28) AND transaction_type = 'withdraw'))
INTERSECT
SELECT name FROM people WHERE passport_number IN (SELECT passport_number FROM passengers WHERE flight_id IN (SELECT id FROM flights WHERE (year = 2021 AND month = 7 AND day = 29) AND origin_airport_id = 8 ORDER BY hour ASC LIMIT 1));

-- Our thief = Bruce
SELECT name FROM people WHERE phone_number IS (
SELECT phone_number FROM people WHERE name IN (SELECT name FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE (year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25))
INTERSECT
SELECT name FROM people WHERE id IN (SELECT person_id FROM bank_accounts
WHERE account_number In (SELECT account_number FROM atm_transactions WHERE atm_location LIKE 'Leggett Street' AND (year = 2021 AND month = 7 AND day = 28) AND transaction_type = 'withdraw'))
INTERSECT
SELECT name FROM people WHERE passport_number IN (SELECT passport_number FROM passengers WHERE flight_id IN (SELECT id FROM flights WHERE (year = 2021 AND month = 7 AND day = 29) AND origin_airport_id = 8 ORDER BY hour ASC LIMIT 1)))
INTERSECT
SELECT caller FROM phone_calls WHERE (year = 2021 AND month = 7 AND day = 28) AND duration < 60);

-- Accomplice = Robin
SELECT name from people WHERE phone_number IS (SELECT receiver FROM phone_calls WHERE (year = 2021 AND month = 7 AND day = 28) AND duration < 60 AND caller IS (SELECT phone_number FROM people WHERE name = 'Bruce'));

-- Bruce escaped to ... New York City
SELECT city FROM airports WHERE id IS (SELECT destination_airport_id FROM flights WHERE (year = 2021 AND month = 7 AND day = 29) AND origin_airport_id = 8 ORDER BY hour ASC LIMIT 1);
