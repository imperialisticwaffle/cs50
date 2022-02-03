-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Narrow down description of crime on Chamberlin St on Jul 28
SELECT description FROM crime_scene_reports WHERE year = 2020 AND month = 7 AND day = 28 AND street = "Chamberlin Street";
-- Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse. Interviews were conducted today with three witnesses who were present at the time — each of their interview
-- transcripts mentions the courthouse.

-- Let's look at the interviews.
SELECT transcript FROM interviews WHERE transcript LIKE "%courthouse%" AND year = 2020 AND month = 7 AND day = 28;
-- Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away. If you have security footage from the courthouse parking lot, you might
-- want to look for cars that left the parking lot in that time frame.

-- I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at the courthouse, I was walking by the ATM on Fifer Street and saw the thief there
-- withdrawing some money.

-- As the thief was leaving the courthouse, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest
-- flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.

-- We can narrow down the list of cars that were at the courthouse from 10:15 to 10:25, then attribute their license plates to people.
CREATE TABLE courthouse_info AS SELECT name, people.license_plate, activity FROM courthouse_security_logs JOIN people on courthouse_security_logs.license_plate = people.license_plate WHERE year = 2020 AND month = 7 AND day =
28 AND hour = 10 AND minute <= 25 AND minute > 15;
-- Patrick | 5P2BI95 | exit
-- Ernest | 94KL13X | exit
-- Amber | 6P58WS2 | exit
-- Danielle | 4328GD8 | exit
-- Roger | G412CB7 | exit
-- Elizabeth | L93JTIZ | exit
-- Russell | 322W7JE | exit
-- Evelyn | 0NTHK55 | exit

-- Now let's look into the atm records.
CREATE TABLE atm_info AS SELECT name, atm_transactions.account_number, amount FROM bank_accounts JOIN atm_transactions on bank_accounts.account_number = atm_transactions.account_number JOIN people on
bank_accounts.person_id = people.id WHERE year = 2020 AND month = 7 AND day = 28 AND transaction_type = "withdraw" AND atm_location = "Fifer Street";
-- Ernest | 49610011 | 50
-- Russell | 26013199 | 35
-- Roy | 16153065 | 80
-- Bobby | 28296815 | 20
-- Elizabeth | 25506511 | 20
-- Danielle | 28500762 | 48
-- Madison | 76054385 | 60
-- Victoria | 81061156 | 30

-- It may be difficult to find the accomplice; we need to check for phone records between 10:15 and 10:25 on the 28th as well as potentially a deposit of the thief's withdrawal about that time.
-- What was the destination of the flight?
SELECT airports.full_name, airports.city FROM airports JOIN flights on airports.id = flights.destination_airport_id WHERE year = 2020 AND flights.month = 7 AND
flights.day = 29 AND (flights.hour = (SELECT MIN(flights.hour) FROM flights WHERE month = 7 and day = 29));
-- Thief left for Heathrow Airport in London

-- Passengers on flight to Heathrow Airport
CREATE TABLE flight_info AS SELECT name, passengers.passport_number FROM passengers JOIN flights on passengers.flight_id = flights.id JOIN people on passengers.passport_number = people.passport_number WHERE flight_id =
(SELECT flights.id FROM airports JOIN flights on airports.id = flights.destination_airport_id WHERE year = 2020 AND flights.month = 7 AND flights.day = 29 AND (flights.hour =
(SELECT MIN(flights.hour) FROM flights WHERE month = 7 and day = 29)));
-- Doris | 7214083635
-- Roger | 1695452385
-- Ernest | 5773159633
-- Edward | 1540955065
-- Evelyn | 8294398571
-- Madison | 1988161715
-- Bobby | 9878712108
-- Danielle | 8496433585

-- Phone calls
CREATE TABLE phone_call_info AS SELECT name FROM phone_calls JOIN people on phone_calls.caller = people.phone_number WHERE year = 2020 AND month = 7 AND DAY = 28 AND duration < 60;
-- Roger
-- Evelyn
-- Ernest
-- Evelyn
-- Madison
-- Russell
-- Kimberly
-- Bobby
-- Victoria

-- Suspect list (doesn't work)
SELECT name WHERE name IN (phone_call_info AND flight_info AND atm_info AND courthouse_info);

-- Accomplice
SELECT name FROM phone_calls JOIN people on phone_calls.receiver = people.phone_number WHERE year = 2020 AND month = 7 AND DAY = 28 AND duration < 60 AND caller = "(367) 555-5533";
-- Berthold