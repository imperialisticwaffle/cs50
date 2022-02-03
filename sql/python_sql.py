from cs50 import SQL
import csv

open("shows.db", "w").close()       # Create empty file for us to interact with
db = SQL("sqlite:///shows.db")      # Open empty file shows.db as sqlite database

# Create table
db.execute("CREATE TABLE shows (id INTEGER, title TEXT, PRIMARY KEY(id)")

# Create table 2
db.execute("CREATE TABLE genres (show_id INTEGER, genre TEXT, FOREIGN KEY(show_id) REFERENCES shows(id)")

title = input("Title: ").strip().upper()        # Format uniformly to account for all cases

with open("Favorite TV shows - Form Responses 1.csv", "r") as file:
    reader = csv.dictReader(file)
    for row in reader:
        title = row["title"].strip().upper()
        id = db.execute("INSERT INTO shows (title) VALUES(?)", title)        # (?) is a placeholder value like %s in C or formatted strings in Python. .execute also returns an integer used for
        # the primary key.

# Provided you have the .csv file you can run this python file in the terminal, then run "sqlite3 shows.db" and then check .schema
# At this point the shows will be listed with id's autoincremented up to a certain number, but we haven't added genres yet
    for genre in row["genres"].split(", "):         # Allows us to identify the separator between the genres as the comma instead of iterating over each character in the comma separated list
        db.execute("INSERT INTO genres (show_id, genre) VALUES(?, ?)", id, genre)

# Now note that if you wanted to select all shows that were musicals, you can nest queries using sqlite language:
# SELECT title FROM shows WHERE id IN (SELECT show_id FROM genres WHERE genre = "Musical"); <-- the parentheses help us nest parameters