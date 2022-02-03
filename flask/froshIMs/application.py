import os
from cs50 import SQL
from flask import Flask, redirect, render_template, request
# from flask_mail import Mail, Message

app = Flask(__name__)       # turns current file into webapp listening for browser requests

# app.config["MAIL_DEFAULT_SENDER"] = os.getenv("MAIL_DEFAULT_SENDER")        # DO NOT EVER TYPE IN ANYTHING PRIVATE OR SECURE INTO YOUR CODE. GRAB THOSE ITEMS FROM ENVIRONMENT
# app.config["MAIL_PASSWORD"] = os.getenv("MAIL_PASSWORD")
# app.config["MAIL_PORT"] = 587                                               # Gmail sends emails on TCP port 587
# app.config["MAIL_SERVER"] = "smtp.gmail.com"
# app.config["MAIL_USE_TLS"] = True                                           # Encryption
# app.config["MAIL_USERNAME"] = os.getenv("MAIL_USERNAME")
# mail = Mail(app)

SPORTS = [
    "Dodgeball",
    "Flag Football",
    "Soccer",
    "Volleyball",
    "Ultimate Frisbee"
]

# Allow data storage of registrants
# REGISTRANTS = {}

db = SQL("sqlite:///froshIMs.db")

# Now have to tell flask what the routes are
@app.route("/")
def index():
    # return render_template("index.html")
    return render_template("index.html", sports=SPORTS)

@app.route("/register", methods=["POST"])
def register():
    # We have to be careful about doing some thorough error checking
    # if not request.form.get("name") or request.form.get("sport")not in SPORTS:
        # return render_template("failure.html")
    # return render_template("success.html")
    # name = request.form.get("name")

    name = request.form.get("name")
    if not name:
        return render_template("error.html", message="Missing name")
    sport = request.form.get("sport")
    if not sport:
        return render_template("error.html", message="Missing sport")
    if sport not in SPORTS:
        return render_template("error.html", message="Invalid sport")

    # REGISTRANTS[name] = sport
    # print(REGISTRANTS)

    # return render_template("success.html")
    # return render_template("registrants.html",  registrants=REGISTRANTS)

    db.execute("INSERT INTO registrants (name, sport) VALUES(?, ?)", name, sport)
    # db.execute("INSERT INTO registrants (email, sport) VALUES(?, ?)", email, sport)
    # message = Message("You are registered!", recipients=[email])
    # mail.send(message)

    return redirect("/registrants")

# There still exists a major problem. What if the user modifies the contents of the form submission (i.e. dropdown menu via inspect element) and submits the form to the server with the locally
# altered parameters? We have to make sure that the server will not accept any answers besides the ones given in the form. We can solve this by defining an array of sports.

@app.route("/registrants")
def registrants():
    rows = db.execute("SELECT * FROM registrants")
    print(rows)
    return render_template("registrants.html",  rows=rows)