import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True


# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")

# UPDATE REQUIRED ON TOTAL INVESTMENT PER COMPANY
@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    total_investment = 0            # Added to find total valuation of cash + holdings
    total_holdings = []
    stocks = db.execute("SELECT symbol, name, price, SUM(shares) total_shares, SUM(total) subtotal FROM transactions WHERE user_id=:user_id GROUP BY symbol", user_id=session["user_id"])
    if stocks == None:
        return apology("No stocks found!")
    cash = float((db.execute("SELECT cash FROM users WHERE id = :user_id", user_id=session["user_id"]))[0]["cash"])
    for stock in stocks:
        total_investment += (stock["subtotal"])

    total = float(cash) + total_investment
    # current_holdings = float((db.execute("SELECT total FROM transactions WHERE user_id=:user_id AND symbol=:symbol GROUP BY symbol", user_id=session["user_id"], symbol=st_symbol))[0]["total"])
    # total = total_bought + current_holdings


    # Dictionary of all symbols
    # symbols = db.execute("SELECT symbol FROM transactions WHERE id=:user_id GROUP BY symbol", user_id=session["user_id"])

    # Dictionary of the net shares per symbol
    # shares = db.execute("SELECT SUM(shares) FROM transactions WHERE id=:user_id GROUP BY symbol", user_id=session["user_id"])

    # Dictionary of the prices for each share
    # prices = db.execute("SELECT price FROM transactions WHERE id=:user_id GROUP BY symbol", user_id=session["user_id"])
    # totals = db.execute("SELECT SUM(price) FROM transactions WHERE id=:user_id GROUP BY symbol", user_id=session["user_id"])
    return render_template("index.html", stocks=stocks, cash=cash, total_investment=total_investment, total=total)

@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        if lookup(request.form.get("symbol")) == None or request.form.get("symbol") == None:
            return apology("Invalid symbol or empty submission")
        elif request.form.get("shares") == '' or request.form.get("shares").find(".") != -1 or request.form.get("shares").isdigit() == False:
            return apology("Invalid share number")
        elif int(request.form.get("shares")) < 1:
            return apology("Invalid share number")
        symbol = request.form.get("symbol")         # Submitted symbol
        shares = int(request.form.get("shares"))
        name = lookup(symbol).get("name")
        st_symbol = lookup(symbol).get("symbol")    # Actual company symbol
        price = float(lookup(symbol).get("price"))
        user = db.execute("SELECT cash FROM users WHERE id = :user_id", user_id=session["user_id"])
        cash = user[0]["cash"]
        cost = float(price * shares)
        # total_bought = price * shares

        if cash < cost:
            return apology("Insufficient funds")

        cash = cash - cost
        # Update current cash count for user
        db.execute("UPDATE users SET cash = :cash WHERE id = :user_id", cash=cash, user_id=session["user_id"])
        # Update transaction records
        db.execute("CREATE TABLE IF NOT EXISTS transactions (id INTEGER, user_id INTEGER, symbol TEXT, name TEXT, shares INTEGER, price REAL, total REAL, transaction_time DATETIME, PRIMARY KEY(id))")
        db.execute("INSERT INTO transactions (user_id, symbol, name, shares, price, total) VALUES (?, ?, ?, ?, ?, ?)", session["user_id"], st_symbol, name, shares, price, cost)

        flash("Successfully purchased!")
        return redirect("/")
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    transactions = db.execute("SELECT symbol, name, shares, price, total, transaction_time FROM transactions WHERE user_id=:user_id", user_id=session["user_id"])
    print(transactions)
    return render_template("history.html", transactions=transactions)

@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        if lookup(request.form.get("symbol")) == None or request.form.get("symbol") == '':
            return apology("Invalid symbol entered")
        symbol = request.form.get("symbol")
        stock_name = lookup(symbol).get("name")
        stock_price = lookup(symbol).get("price")
        stock_symbol = lookup(symbol).get("symbol")
        return render_template("quoted.html", symbol=stock_symbol, name=stock_name, price=stock_price)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        confirm = request.form.get("confirmation")

        # If username blank
        if not username:
            return apology("Blank username")
        if not password or not confirm:
            return apology("Blank password")
        if password != confirm:
            return apology("Password mismatch")

        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))
        # If newly registered user already exists in database once
        if len(rows) == 1:
            return apology("User credentials taken")

        # Insert user into sql db
        pwhash = generate_password_hash(password)
        db.execute("INSERT INTO users (username, hash) VALUES (?, ?);", username, pwhash)

        # Remember user
        session["user_id"] = (db.execute("SELECT * FROM users WHERE username = :username", username=request.form.get("username")))[0]["id"]

        flash("Registered!")
        return redirect("/")

    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    stocks = []

    if request.method == "POST":
        if request.form.get("symbol") == None:
            return apology("No stock selected")

        share = request.form.get("symbol")
        name = lookup(share).get("name")
        price = float(lookup(share).get("price"))
        actual_number = (db.execute("SELECT SUM(shares) total_shares FROM transactions WHERE user_id=:user_id AND symbol=:share GROUP BY symbol", user_id=session["user_id"], share=share))[0]["total_shares"]
        req_number = int(request.form.get("shares"))

        if req_number > actual_number:
            return apology("Requested sell quantity exceeds actual quantity")

        # Update cash
        sp = price * req_number
        cash = (db.execute("SELECT cash FROM users WHERE id = :user_id", user_id=session["user_id"]))[0]["cash"]
        cash += sp
        db.execute("UPDATE users SET cash = :cash WHERE id = :user_id", cash=cash, user_id=session["user_id"])
        # Update transactions?
        db.execute("INSERT INTO transactions (user_id, symbol, name, shares, price, total) VALUES (?, ?, ?, ?, ?, ?)", session["user_id"], share, name, -abs(req_number), price, -abs(sp))

        flash("Sold successfully!")
        return redirect("/")

    else:
        all_symbols = db.execute("SELECT symbol, SUM(shares) total_shares FROM transactions WHERE user_id=:user_id GROUP BY symbol", user_id=session["user_id"])
        for symbol in all_symbols:
            if symbol["total_shares"] == 0:
                continue
            stocks.append(symbol["symbol"])
        return render_template("sell.html", stocks=stocks)


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
